import glob
import os
import shutil
import subprocess
import sys

ROOT_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def run(command):
    result = subprocess.run(command, cwd=ROOT_DIR)
    if result.returncode != 0:
        sys.exit(result.returncode)


def build(config):
    run(["conan", "install", "Automation/conanfile.py", "--output-folder=Build", "--build=missing",
         "-s", f"build_type={config}", "-s", "compiler.cppstd=23"])
    run(["cmake", "-S", ".", "-B", "Build", "-DCMAKE_TOOLCHAIN_FILE=Build/conan_toolchain.cmake"])
    run(["cmake", "--build", "Build", "--config", config])


def clean():
    shutil.rmtree(os.path.join(ROOT_DIR, "Build"), ignore_errors=True)


def format_all_files():
    files = glob.glob("Engine/**/*.h", root_dir=ROOT_DIR, recursive=True)
    files += glob.glob("Engine/**/*.cpp", root_dir=ROOT_DIR, recursive=True)
    files += glob.glob("Sandbox/**/*.h", root_dir=ROOT_DIR, recursive=True)
    files += glob.glob("Sandbox/**/*.cpp", root_dir=ROOT_DIR, recursive=True)
    run(["clang-format", "-i", "--style=file:Automation/.clang-format", *files])


command = sys.argv[1]
if command == "build":
    build(sys.argv[2])
elif command == "clean":
    clean()
elif command == "format":
    format_all_files()
