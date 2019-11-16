// 基础3d
// Created by czfshine on 19-11-15.
//
// 这个程序显示了最基本的如何画三维图形。
// 先解释一些基础概念：
// 矩阵（Matrix）： 众所周知，在计算机图形学里所有变换都相当于乘以一个矩阵
// 在opengl的状态机里面也有一些矩阵，下面用到的一些可以操作这些矩阵的函数如下：
// (这一篇的目标是显示一个三维图像，后面会专门讲这些的）
// glMatrixMode:设置当前要操作什么矩阵（投影，视图，纹理）
// glLoadIdentity:设置当前矩阵为单位矩阵
// gluPerspective:设置透视效果(传递的参数会根据某种算法影响矩阵）
// glTranslatef:叠加到矩阵的位置分量，产生平移效果
// glRotatef:同上，产生旋转效果
// glPushMatrix,glPopMatrix: 将矩阵弹入弹出栈，保存现场
// 注：改变矩阵的函数大部分都不是幂等的
//
// 画三维图形与之前的二维图像基本一致，需要做的额外步骤是：
// 1. 设置显示效果，即投影
// 2. 让物体加入视界，移动位置
// 剩下的话和二维图一样，不过坐标要是三维的（二维的话z会补0）

#include <GL/glew.h>
#include <GL/glut.h>
#include <cstring>

int width = 512;
int height = 512;

//动画变量
float rotate = 0.0f;        // 绕Y轴旋转变量
//初始化信息
void init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    //这些让图像效果更好
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat)width/height, 1.0, 30.0);
}

//动画
void idle()
{
    rotate += 0.2f;
    glutPostRedisplay();
}

/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display()
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        // 把整个物体往前推一些，不然我们的视点在内部，看不见图像（还以为出bug了，bug--）
        glTranslatef(0, 0.0f, -7.0f);
        //动画，旋转一下下
        glRotatef(rotate, 0.0f, 1.0f, 0.0f);

        //接下来和普通画线没区别，注意坐标是三维的
        glColor3f (0.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
            glVertex3f (2.0f, -1.5f, 2.0f);
            glVertex3f (-2.0f, -1.5f, 2.0);
            glVertex3f (-2.0f, -1.5f, -2.0);
            glVertex3f (2.0f, -1.50f, -2.0);
        glEnd();
    glPopMatrix();

    // 交换显示缓冲区
    glutSwapBuffers() ;
}

int main(int argc,char* argv[])
{
    //一些初始化窗口和opengl的函数
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glewInit();
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow("3D");
    init() ;
    glutDisplayFunc(&Display);
    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}