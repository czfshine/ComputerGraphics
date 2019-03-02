这个项目需要用到`opengl` `glew` `freeglut` `glu` 四个外部库，

* `opengl` `glu`   在window的开发工具包（Window kits）自带，安装visual studio时选就行
* freeglut  用来创建窗口和获取鼠标键盘事件的，安装教程在下面
* glew  它将各平台的不同的实现统一起来，只要包括一个glew，就可以调用不同的扩展功能，安装教程在下面

## freeglut

* [官网下载](http://freeglut.sourceforge.net/index.php#download) 推荐下载3.0.0版本的

* 解压到某个目录

* 使用cmake构建，按`README.cmake` 文件内的说明进行生成

* `readme.cmake` 文件内容摘抄如下：

  ```
  How to build freeglut with CMake on Windows (MS Visual Studio)
  --------------------------------------------------------------
  1~3	步说明怎么下载cmake的，已经有的可以不看
  1.  Download CMake (http://www.cmake.org/cmake/resources/software.html).
      Get one of the releases from the binary distribution section.
  2.  Run the CMake installer, install wherever you like. 
  3.  Launch CMake via Start > Program Files > CMake 2.8 > CMake (GUI)
      (note that the shortcut put by the installer on your desktop does NOT
      point to the CMake GUI program!)
  配置原目录和目标目录，不要选错
  4.  In the "Where is the source code" box, type or browse to the root
      directory of your freeglut source (so that's /freeglut, not
      /freeglut/src).
  5.  In the "Where to build the binaries" box, type or browse to any
      folder you like - this will be where the Visual Studio solution will be
      generated. This folder does not have to exist yet.
   配置生成目标
  6.  Hit the Configure button near the bottom of the window. 
  这里选visual studio 2017/2015 的就行（todo：X64的看情况）
  7.  Pick your target compiler, make sure that its installed on your
      system of course!
  8.  Answer Ok when asked if you want to create the build directory. 
  9.  Wait for the configure process to finish. 
  屏幕会有选项给你选
  10. The screen will now have some configuration options on it, for
      instance specifying whether you want to build static and/or shared
      libraries (see below for a complete list). When you've selected your
      options, click the Configure button again.
  选项列表如下：

  Breakdown of CMake configuration options
  ----------------------------------------
  CMAKE_BUILD_TYPE            [Empty, Debug, Release] Can be overriden by
                              passing it as a make variable during build.
  CMAKE_INSTALL_PREFIX	    Installation prefix (e.g. /usr/local on UNIX)
  FREEGLUT_BUILD_DEMOS	    [ON, OFF] Controls whether the demos are
                              built or not. freeglut的示例，看个人情况，这里不需要
  FREEGLUT_BUILD_SHARED_LIBS  [ON, OFF] Build freeglut as a shared library 要点
  FREEGLUT_BUILD_STATIC_LIBS  [ON, OFF] Build freeglut as a static library 要点
  FREEGLUT_GLES               [ON, OFF] Link with GLEs libraries instead
                              of OpenGL 不用咯
  FREEGLUT_PRINT_ERRORS       [ON, OFF] Controls whether errors are
                              default handled or not when user does not
                              provide an error callback 
                              要不要把（freeglut的）错误信息打出来，
                              推荐点，要发布再重新编译一次去掉
  FREEGLUT_PRINT_WARNINGS     [ON, OFF] Controls whether warnings are
                              default handled or not when user does not
                              provide an warning callback
                              同上，不过是警告信息（可能有点多）
  FREEGLUT_REPLACE_GLUT       [ON, OFF] For non-Windows platforms,
                              freeglut is by default built as -lglut. if
                              off, built as -lfreeglut. On Windows,
                              libraries are always built as freeglut.
                              自己改下名就行hhh
  INSTALL_PDB                 [ON, OFF] MSVC only: controls whether debug
                              information files are included with the
                              install or not
                              没啥用
  点击生成 (Generate)按钮生成，因为freeglut没有外部依赖项，所以应该会成功的，
  如果不成功，可能是你visual studio版本选错
  11. The Generate button at the bottom will now be enabled. Click Generate.
  在你刚才选的目标目录下就有个freeglut.sln,双击打开完事
  12. The build files will now be generated in the location you picked. 

  You can now navigate to the build directory you specified in step 5.
  Open the freeglut.sln file that was generated in your build directory,
  and compile as usual
  ```


 

* 用Visual studio 打开解决方案后，默认是生成debug版本的，改下选Release，然后生成解决方案.在lib\Release目录下会生`freeglut.lib` 这就是我们需要的静态库了，不动它：）记住所在的目录就行



## glew

* [官网](http://glew.sourceforge.net/)  下载最新的2.1.0版本 ，直接下载`Binaries Windows 32-bit and 64-bit` 预编译好的就行
* 直接解压就行，在lib/Release 下就行直接找到我们要的`glew32.lib` ，它有32位和64位的，看情况使用

