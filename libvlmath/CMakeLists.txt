add_library(libvlmath)
add_library(VolcanusLucis::libvlmath ALIAS libvlmath)

target_compile_definitions(libvlmath PUBLIC 
    LIBVLMATH_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    LIBVLMATH_VERSION_MINOR=${PROJECT_VERSION_MINOR}
    LIBVLMATH_VERSION_PATCH=${PROJECT_VERSION_PATCH}
)

# May remain unused.
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(libvlmath_ARCH_SUFFIX 64)
else ()
    set(libvlmath_ARCH_SUFFIX "")
endif ()

# Project is already pre-pended with lib
set_target_properties(libvlmath PROPERTIES 
    PREFIX ""
    IMPORT_PREFIX ""
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

target_sources(libvlmath
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
    FILES
        matrix.hpp
        matrix.ipp
)

target_sources(libvlmath PRIVATE
    matrix.cpp
)

target_compile_features(libvlmath PUBLIC cxx_std_23)
target_include_directories(libvlmath PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    if (NOT CMAKE_CROSSCOMPILING)
        if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
            set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "${PROJECT_SOURCE_DIR}/install/${PROJECT_NAME}")
        else ()
            set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "/usr/local")
        endif ()
    else ()
        set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "${PROJECT_SOURCE_DIR}/install/${PROJECT_NAME}")
    endif ()
endif ()