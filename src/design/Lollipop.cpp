// 给你糖糖
// Created by czfshine on 2019/3/4.
// https://en.wikipedia.org/wiki/Lollipop

#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>

#define pi 3.14159265358
/**
 * 画扇形
 * 如果要取反的话将角度调换就行
 * @param x 圆心坐标
 * @param y 圆心坐标
 * @param r 半径
 * @param start 开始角度
 * @param end   结束角度
 */
void sector(float x,float y, float r, float start, float end){

    if(end<start)
        end+=2*pi;
#define getx(t) x+r*cos(t)
#define gety(t) y+r*sin(t)
    glBegin(GL_POLYGON);

    glVertex2f(getx(end), gety(end));//A
    glVertex2f(x, y);//A
    glVertex2f(getx(start),gety(start));

    for(float i=start;i<=end;i+=0.01 ){
        glVertex2f(getx(i), gety(i));
    }
    glVertex2f(getx(end), gety(end));//A
    glEnd();
}
/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display(void)
{
    glEnable (GL_LINE_SMOOTH);
    glHint (GL_LINE_SMOOTH, GL_NICEST);
    glEnable(GL_MULTISAMPLE);
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(200);
    glColor3f(1, 214.0/255, 138.0/255);
    float delta=0.0375/1.41;
    sector(-0.4,-0.4,0.0375,3.0/4.0*pi,7.0/4.0*pi);
    glBegin(GL_POLYGON);
    glVertex2f(0.0+ delta,0.0-delta);
    glVertex2f(0.0- delta,0.0+delta);
    glVertex2f(-0.40- delta,-0.40+ delta);
    glVertex2f(-0.40+ delta,-0.40- delta);
    glEnd();
    glColor3f(1,100.0/255,100.0/255);
    sector(0,0,0.2,3.0/4.0*pi,7.0/4.0*pi);
    glColor3f(244.0/255,67.0/255,133.0/255);
    sector(0,0,0.2,7.0/4.0*pi,3.0/4.0*pi);
    glutSwapBuffers();
}

int main(int argc,char* argv[])
{
    //一些初始化窗口和opengl的函数
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_MULTISAMPLE);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(800,800);
    glutCreateWindow("The First Point");
    glutDisplayFunc(&Display);
    glutMainLoop();
    return 0;
}

