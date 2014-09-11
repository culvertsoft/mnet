#!/usr/bin/python
from buildutil import *

###########
# TARGETS #
###########

def clean():
    sbt_clean(".")
    rmFolders(".", "src_generated")
    rmFolder("mnet-cppclient/target")
    rmFolder("target/install_zip")


def build():
    generate_models()
    #build_cpp()#Currently not building cpp from python until jenkins has qt installed
    build_java_and_scala()    


def test():
    sbt_test(".")
    #TODO: test cppclient


def eclipse():
    sbt_eclipse(".")


def publish():
    publish_impl()


def deploy(folder):
    mkFolder(folder)
    for jarFile in findFiles(".", '*assembly*.jar*'):
        trgFilePath = folder + "/" + os.path.basename(jarFile)
        shutil.copyfile(jarFile, trgFilePath)


###########
# HELPERS #
###########

default_cpp_build_cfg = "NEEDS_TO_BE_SET"
mnet_version = "NEEDS_TO_BE_SET"


def getCommitDateString():
    return os.popen("git show -s --format=%ci").read().rstrip()


def copySubProjectJarFilesToZipDir(folderName, subprojectName, version, includeAssembly):
    srcFileBase = folderName + "/target/" + subprojectName + "-" + version
    destFileBase = "target/install_zip/jars/" + subprojectName
    copyFile(srcFileBase + ".jar", destFileBase + ".jar")
    copyFile(srcFileBase + "-sources.jar", destFileBase + "-sources.jar")
    copyFile(srcFileBase + "-javadoc.jar", destFileBase + "-javadoc.jar")
    if (includeAssembly):
        assemblySrc = folderName + "/target/" + subprojectName + "-assembly-" + version + ".jar"
        copyFile(assemblySrc, destFileBase + "-assembly.jar")


def copyJarFilesToZipDir():
    copySubProjectJarFilesToZipDir("mnet-api", "mnet-api", mnet_version, False)
    copySubProjectJarFilesToZipDir("mnet-backend","mnet-backend", mnet_version, False)
    copySubProjectJarFilesToZipDir("mnet-javaclient", "mnet-client", mnet_version, False)


def getInstallZipName():
    return "target/mnet-" + mnet_version + ".zip"


def create_install_zip():
    rmFolder("target/install_zip")
    mkFolder("target/install_zip")
    mkFolder("target/install_zip/jars")
    mkFolder("target/install_zip/bin")
    mkFolder("target/install_zip/include")
    mkFolder("target/install_zip/javascript")
    
    copyJarFilesToZipDir()

    copyTree("mnet-cppclient/src/main/cpp/mnet", "target/install_zip/include/mnet")
    copyTree("mnet-cppclient/src/main/cpp_generated/se", "target/install_zip/include/se")
        
    copyFile("LICENSE", "target/install_zip/LICENSE.TXT")
  
    versionFile = open("target/install_zip/BUILD.TXT", "w")
    versionFile.write("Release version: " + mnet_version + "\n")
    versionFile.write("Git commit date: " + getCommitDateString() + "\n")
    versionFile.close()
    
    zipdir("target/install_zip", getInstallZipName())


def install():

    # name of the file to store on disk
    zipFile = getInstallZipName()

    if not os.path.exists(zipFile):
        create_install_zip()
    
    #Check that we have an install path
    installPath = os.environ.get('MNET_INSTALL_PATH')
    if installPath == None:
        raise Exception("Environmental variable MNET_INSTALL_PATH not set")

    print("Installing MNET to " + installPath)
    
    #prepare install folder
    rmFolderContents(installPath)
    mkFolder(installPath)
    
    #unzipping
    fh = open(zipFile, 'rb')
    z = zipfile.ZipFile(fh)
    for name in z.namelist():
        z.extract(name, installPath + "/")
    fh.close()


def compile3(workingDir, project, outPath):
    check_call(mgen + project + pluginPaths + ' output_path="' + outPath + '"', cwd=workingDir, shell=True)


def compile(workingDir, project):
    compile3(workingDir, project, ".")


def generate_models():
    check_call("mgen src/main/model/project.xml", cwd="mnet-api", shell=True)
    check_call("mgen src/main/model/project.xml", cwd="mnet-backend", shell=True)
    check_call("mgen src/main/model/project.xml", cwd="mnet-cppclient", shell=True)


def build_java_and_scala():
    sbt(".",   ('"project mnet_api" publish-local '
                '"project mnet_backend" publish-local '
                '"project mnet_javaclient" assembly publish-local '))


def build_cpp():
    mkFolder("mnet-cppclient/target")
    cmake("mnet-cppclient/target", "../src/test/cpp", "Debug")


def publish_impl():
    sbt(".",   ('"project mnet_api" publish-signed '
                '"project mnet_backend" publish-signed '
                '"project mnet_javaclient" publish-signed '))
