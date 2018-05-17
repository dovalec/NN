cmake_minimum_required(VERSION 3.0.0)
project(NN VERSION 0.1.0)

find_package( OpenCV REQUIRED COMPONENTS core imgproc highgui )

include(CTest)
enable_testing()

include_directories( ./include )

add_executable(NN.out
    src/Main.cpp 
    src/Net.cpp
    src/Layer.cpp
    src/Node.cpp
    src/TransformFunc
    
)

target_link_libraries(NN.out ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_BUILD_TYPE Release)
include(CPack)
