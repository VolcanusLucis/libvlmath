add_library(${PROJECT_NAME}
        matrix.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}")


