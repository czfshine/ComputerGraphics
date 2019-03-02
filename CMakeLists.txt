cmake_minimum_required(VERSION 3.0)
project(cg)
set(CMAKE_CXX_STANDARD 17)

if(MSVC)
    #window 下配置环境
    set(BUILD_USE_64BITS on) #64w位咯

    set(FREEPATH "freeglut 的路径" CACHE STRING INTERNAL)
    set(GLEWPATH "GLEW的路径" CACHE STRING INTERNAL)
    INCLUDE_DIRECTORIES(${FREEPATH}/include/)
    LINK_DIRECTORIES(${FREEPATH}/lib/Debug/)
    message(${FREEPATH}/include/Release/)
    INCLUDE_DIRECTORIES(${GLEWPATH}/include/)
    LINK_DIRECTORIES(${GLEWPATH}/lib/Release/X64)
    message(${GLEWPATH}/include/Release/)
    set(ALLLIB GLU32 OpenGL32 freeglutd glew32)
else()
    set(ALLLIB GLU GL glut GLEW)
endif()

ADD_SUBDIRECTORY(src)