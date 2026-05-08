cmake_minimum_required(VERSION 3.30)

set(libvlmathBuildTypes Static Shared)
set(libvlmathBuildStatic NO)
set(libvlmathBuildShared NO)

foreach (libvlmathBuildType IN LISTS ${CMAKE_FIND_PACKAGE_NAME}_FIND_COMPONENTS)
    if (libvlmathBuildType IN_LIST libvlmathBuildTypes)
        set(libvlmathBuild${libvlmathBuildType} YES)
    else ()
        set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "libvlmath does not recognise component `${libvlmathBuildType}`.")
        set(${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
        return()
    endif ()
endforeach ()

if (libvlmathBuildStatic AND libvlmathBuildShared)
    set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
        "libvlmath `Static` and `Shared` components are mutually exclusive.")
    set(${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
    return()
endif ()

set(libvlmathStaticTargets "${CMAKE_CURRENT_LIST_DIR}/libvlmathStaticTargets.cmake")
set(libvlmathSharedTargets "${CMAKE_CURRENT_LIST_DIR}/libvlmathSharedTargets.cmake")

macro(libvlmathLoadTargets type)
    if (NOT EXISTS "${libvlmath${type}Targets}")
        set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
            "libvlmath ${type} targets not found.")
        set(${CMAKE_FIND_PACKAGE_NAME}_FOUND FALSE)
        return()
    endif ()
    include("${libvlmath${type}Targets}")
endmacro()

if (libvlmathBuildShared
    OR (DEFINED libvlmath_SHARED_LIBS AND libvlmath_SHARED_LIBS)
    OR (BUILD_SHARED_LIBS AND EXISTS ${libvlmathSharedTargets})
    OR (NOT BUILD_SHARED_LIBS AND NOT EXISTS ${libvlmathStaticTargets})
)
    libvlmathLoadTargets(Shared)
elseif (libvlmathBuildStatic 
    OR (DEFINED libvlmath_SHARED_LIBS AND NOT libvlmath_SHARED_LIBS)
    OR (BUILD_SHARED_LIBS AND NOT EXISTS ${libvlmathSharedTargets})
    OR (NOT BUILD_SHARED_LIBS AND EXISTS ${libvlmathStaticTargets})
)
    libvlmathLoadTargets(Static)
endif ()