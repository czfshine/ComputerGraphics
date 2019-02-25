# ComputerGraphics
一些计算机图形学相关的代码，主要内容是在学<计算机图形学>这门课和opengl的过程中的一些代码片段和程序。



## Index

> 代码在src文件夹下，各个代码的简要说明在下面

* basic 基础
  * `point.cpp` 一个点

## Build

整个项目使用**cmake**构建，按照传统的cmake编译流程编译就行，需要用到的外部库有`opengl`，`glew`，`freeglut`.

在Ubuntu 1804和Windows 10 下都测试通过。

下面是具体的编译流程

### Linux

```bash
cmake ./
make
```

完事



### Window

先配置外部库，再生成Visual Studio 2017 的解决方案文件：

```bash
cmake -G "Visual Studio 15"
```

然后在VS2017打开生成的解决方案文件，构建就行. 



## Screenshot

![image](./screenshot/Screenshot%20from%202019-02-25%2016-54-53.png?raw=true)
