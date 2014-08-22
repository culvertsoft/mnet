#!/usr/bin/python
from buildutil import *

###########
# TARGETS #
###########

def clean():
    rmFolders(".", "src_generated")
    rmFolder("mnet-cppclient/target")
    sbt_clean(".")

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
    cmake("mnet-cppclient/target", "../src", "Debug")

def publish_impl():
    sbt(".",   ('"project mnet_api" publish-signed '
                '"project mnet_backend" publish-signed '
                '"project mnet_javaclient" publish-signed '))
