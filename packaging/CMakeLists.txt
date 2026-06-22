include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# SETUP

if (NOT DEFINED libvlmath_INSTALL_CMAKEDIR)
    set(libvlmath_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/libvlmath" 
        CACHE STRING "Path to libvlmath CMake files"
    )
endif ()

# INSTALL TARGETS

install(TARGETS libvlmath EXPORT libvlmathTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} COMPONENT libvlmath_Runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libvlmath_Runtime
    NAMELINK_COMPONENT libvlmath_Development
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT libvlmath_Development
    FILE_SET HEADERS DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libvlmath COMPONENT libvlmath_Development
)

# INSTALL EXPORT TARGETS

install(EXPORT libvlmathTargets
    DESTINATION ${libvlmath_INSTALL_CMAKEDIR}
    NAMESPACE VolcanusLucis::
    FILE libvlmathConfig.cmake
    COMPONENT libvlmath_Development
)

write_basic_package_version_file(
    libvlmathConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/libvlmathConfigVersion.cmake
    DESTINATION ${libvlmath_INSTALL_CMAKEDIR}
    COMPONENT libvlmath_Development
)

# INSTALL DOCS

set(CMAKE_INSTALL_DOCDIR ${CMAKE_INSTALL_DATAROOTDIR}/doc/libvlmath)
install(FILES
    ${PROJECT_SOURCE_DIR}/README.md
    ${PROJECT_SOURCE_DIR}/LICENSE
    DESTINATION ${CMAKE_INSTALL_DOCDIR}
    COMPONENT libvlmath_Documentation
)

# EXPORTS

export(EXPORT libvlmathTargets
    NAMESPACE VolcanusLucis::
)

export(PACKAGE libvlmath)

# PACKAGING

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A linear maths library for use in or with 3D applications.")
# set(CPACK_PACKAGE_DESCRIPTION_FILE path/to/file)
set(CPACK_PACKAGE_VENDOR "Volcanus Lucis")
set(CPACK_PROJECT_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PROJECT_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PROJECT_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_PACKAGE_INSTALL_DIRECTORY ${CPACK_PACKAGE_NAME})
set(CPACK_VERBATIM_VARIABLES ON)
# set(CPACK_RESOURCE_FILE_WELCOME path/to/file)
set(CPACK_RESOURCE_FILE_LICENSE ${PROJECT_SOURCE_DIR}/LICENSE)
set(CPACK_RESOURCE_FILE_README ${PROJECT_SOURCE_DIR}/README.md)
set(CPACK_TOPLEVEL_TAG ${PROJECT_NAME})

if (NOT DEFINED CPACK_GENERATOR)
    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
        # TODO: Support Package Manager Packaging [DEB, RPM]
        set(CPACK_GENERATOR TGZ TXZ)
    elseif (CMAKE_SYSTEM_NAME STREQUAL "Windows")
        if (CMAKE_VERSION VERSION_GREATER_EQUAL 4.3)
            set(CPACK_GENERATOR ZIP_LZMA2)
        else ()
            set(CPACK_GENERATOR ZIP)
        endif ()
    endif ()
endif ()

if (DEFINED libvlmath_RUNTIME_BUILD AND libvlmath_RUNTIME_BUILD)
    set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
    set(CPACK_COMPONENTS_GROUPING ALL_COMPONENTS_IN_ONE)
    set(CPACK_COMPONENTS_ALL libvlmath_Runtime libvlmath_Documentation)
endif ()

include(CPack)