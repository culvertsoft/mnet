#!/usr/bin/python
from buildutil import *

###########
# TARGETS #
###########

def clean():
    sbt_clean(".")
    #TODO: clean cppclient
    
def build():
    generate_network_model()
    build_java_and_scala()

def test():
    print("test() not yet implemented!")

def eclipse():
    sbt_eclipse(".")

def publish():
    print("publish() not yet implemented!")
    
###########
# HELPERS #
###########

default_cpp_build_cfg = "NEEDS_TO_BE_SET"

def compile3(workingDir, project, outPath):
    check_call(mgen + project + pluginPaths + ' output_path="' + outPath + '"', cwd=workingDir, shell=True)

def compile(workingDir, project):
    compile3(workingDir, project, ".")

def generate_network_model():
    check_call("mgen src/main/model/project.xml", cwd="mnet-api", shell=True)
    
def build_java_and_scala():
    sbt(".",   ('"project mnet_api" publish-local '
                '"project mnet_backend" publish-local '
                '"project mnet_javaclient" publish-local '))

def build_cpp():
    print("build_cpp() not yet implemented!")
               
