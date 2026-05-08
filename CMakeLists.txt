cmake_minimum_required(VERSION 3.30)
project(libvlmath 
    VERSION 0.0.1
    HOMEPAGE_URL "https://github.com/VolcanusLucis/libvlmath"
)

# VARIABLES

option(libvlmath_INCLUDE_PACKAGING "Include packaging rules for libvlmath" "${PROJECT_IS_TOP_LEVEL}")

# PROJECT

if (DEFINED libvlmath_SHARED_LIBS)
    set(BUILD_SHARED_LIBS ${libvlmath_SHARED_LIBS})
endif ()

add_subdirectory(libvlmath)

# PACKAGING

if (libvlmath_INCLUDE_PACKAGING)
    add_subdirectory(packaging)
endif ()