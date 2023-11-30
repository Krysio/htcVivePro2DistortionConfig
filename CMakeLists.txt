set(CMAKE_GENERATOR_PLATFORM "x64" CACHE STRING "" FORCE)
PROJECT(LibLensDistortion)
ENABLE_LANGUAGE(C CXX ASM_MASM)
ADD_LIBRARY(LibLensDistortion SHARED LibLensDistortion_asm.asm LibLensDistortion.cpp LibLensDistortion.def empty.h hook_macro.h)