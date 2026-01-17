add_library(${PROJECT_NAME} STATIC
        matrix.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_SOURCE_DIR}")
