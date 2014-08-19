#!/usr/bin/python
import buildimpl
from buildimpl import *

# Parse arguments
parser = argparse.ArgumentParser()
parser.add_argument("-b", "--build", action='store_true')
parser.add_argument("-p", "--publish", action='store_true')
parser.add_argument("-c", "--clean", action='store_true')
parser.add_argument("-e", "--eclipse", action='store_true')
parser.add_argument("-t", "--test", action='store_true')
parser.add_argument("-a", "--all", help='all except publish (=cbt)', action='store_true')
parser.add_argument("-g", "--generate", action='store_true')
parser.add_argument("-d", "--deploy", action='store_true')
parser.add_argument("-f", "--deploy_folder", default='X:/johan/deploy/mnet')
parser.add_argument("-v", "--version", default="SNAPSHOT")
args = parser.parse_args()

# Buildimpl requires these to be set
os.environ['MNEN_BUILD_VERSION'] = args.version
buildimpl.default_cpp_build_cfg = "RelwithDebInfo" # Because VS is epicly slow in debug

# Targets 
if args.clean or args.all: clean() 
if args.generate: generate_models()
if args.build or args.all or len(sys.argv) == 1: build()
if args.test or args.all: test()
if args.eclipse or args.all: eclipse()
if args.deploy: deploy(args.deploy_folder)
if args.publish: publish()
