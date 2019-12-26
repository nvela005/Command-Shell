


CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rshell
	src/execom.cpp src/main.cpp
)
ADD_EXECUTABLE(test
     src/execom.cpp src/test_main.cpp 
)

TARGET_LINK_LIBRARIES(test gtest)
