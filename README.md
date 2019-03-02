[![Build Status](https://travis-ci.org/czfshine/ComputerGraphics.svg?branch=master)](https://travis-ci.org/czfshine/ComputerGraphics)

# ComputerGraphics

一些计算机图形学相关的代码，主要内容是在学<计算机图形学>这门课和opengl的过程中的一些代码片段和程序。



## Index

> 代码在src文件夹下，各个代码的简要说明在下面

* basic 基础,这一部分只涉及opengl,glut,glew的各类API的使用和简单示例,不包括各种算法和事件,动画等.复杂度依次递增,而且没有覆盖所有的API
  * `point.cpp` 一个点
  * `lineandshape.cpp` 利用**opengl的API**画线和三角形,四边形等
  * `array.cpp` 使用数组绘制
  * `simpleshader.cpp` 简单着色器示例 
* event 事件,opengl规范只提供了显示相关的API,事件使用freeglut实现,[文档在这](http://freeglut.sourceforge.net/docs/api.php)
  * 动画/时间定时器
    * `animation1.cpp` 一个最最简单的动画示例了
    * `animation2.cpp` 最简单的定时器做的时针
  * 鼠标键盘
    * todo
  * 窗口回调
    * todo

## Building

整个项目使用**cmake**构建，按照传统的cmake编译流程编译就行，需要用到的外部库有`opengl`，`freeglut`.

在Ubuntu 18.04和Windows 10 下都测试通过。

我的环境为
```
OpenGL实现厂商的名字：NVIDIA Corporation
渲染器标识符：GeForce 940M/PCIe/SSE2
OOpenGL实现的版本号：4.6.0 NVIDIA 390.48
OGLU工具库版本：1.3
glutGet(GLUT_VERSION) == 30000
```

下面是具体的编译流程

### Linux

先安装外部库,ubuntu 下运行:

```
sudo apt-get install -y libglew-dev freeglut3-dev libgl1-mesa-dev
```

注意Ubuntu版本要高于或等于16.04

测试环境,先手动编译point.cpp测试下库是否安装正确

```
g++ ./src/basic/point.cpp -lGL -lglut -lGLU -o point
```

没报错说明正常,然后执行:

```bash
cmake ./
make
```

完事

### Window

* 先配置外部库，参考[这个文档](./doc/Window平台下配置必需的库.md) .

* 然后安装cmake（最新版的），然后在开始菜单内点`cmake  gui` 打开cmake的图形界面

* 配置如下：

  ​

```bash
cmake -G "Visual Studio 15"
```

然后在VS2017打开生成的解决方案文件，构建就行. 

## 开发

现在主流的C/C++的IDE都支持直接打开和解析cmake项目,这个仓库使用Clion ~~(学生免费:)~~进行开发的,直接`File -> Import Project`  选择这个库的根目录即可.

## 资料

教材<计算机图形学(第四版)>,直接从3.5开始看.

opengl官网wiki和<OpenGl编程指南>.

<计算机视觉中的数学方法> 补数学基础的.质量还行，主要是学校图书馆关于计算机图形学的书不多，而且混杂在一堆讲Photoshop的书里面。

## Screenshot

![image](./screenshot/Screenshot%20from%202019-02-25%2016-54-53.png?raw=true)
画点(point.cpp)
![image](./screenshot/Screenshot%20from%202019-02-25%2021-30-31.png?raw=true)
画图形(lineandshape.cpp)
