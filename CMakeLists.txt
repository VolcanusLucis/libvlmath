cmake_minimum_required(VERSION 3.24)
project(libvlmath)

# Project is already pre-pended with lib
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.hpp"
        PATTERN "*.tpp"
)