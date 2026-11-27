from conan import ConanFile


class NanoforceConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("spdlog/1.16.0")
        self.requires("glfw/3.4")
