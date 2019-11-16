function(singlefile type filename)
    add_executable(${filename} ${type}/${filename}.cpp)
    target_link_libraries(${filename} ${ALLLIB})

    if(MSVC)
        #在window下要复制freeglut.dll到目标目录
        #也就是从 ${FREEPATH}/bin/Debug/ 里面复制freeglut.dll到 目标生成的exe对应的目录下
        add_custom_command(TARGET ${filename} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${FREEPATH}/bin/Debug/ $<TARGET_FILE_DIR:${filename}>)
    endif()
endfunction()

singlefile(basic point)
singlefile(basic lineandshape)
singlefile(basic array)
singlefile(basic 3d)
#singlefile(basic simpleshaper)
singlefile(event animation1)
singlefile(event animation2)
singlefile(event mouseclick)
singlefile(basic pixels)
#singlefile(textture)

singlefile(design Lollipop)
#target_link_libraries(textture X11)