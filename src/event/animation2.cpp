// 最简单的定时器的使用定时器
// Created by czfshine on 19-2-28.
//

// 还是一个glut的api:
// `void glutTimerFunc( unsigned int time, void (* callback)( int ), int value );`
// 大概的意思是说,在time(毫秒)之后调用callback函数,并把value传递给callback函数

// 知道这个api,写代码就很简单了:)

//下面画一个时钟
#include <GL/glut.h>
#include <cmath>
#include <cstdio>
//大小咯
#define size 0.8f

void showpane();

/**
 * 显示秒针
 * @param s 当前秒数
 */
void showsecond(char s){
    glLineWidth(2);
    double a=2*3.1415*s/60;
    glBegin(GL_LINES);
    glVertex2f(0.0f,0.0f);
    glVertex2f((size-0.05)*sin(a),(size-0.05)*cos(a));
    glEnd();
}
/**
 * 显示分针
 * @param m 当前分钟数
 * @param s 当前秒数
 */
void showminute(char m,char s){
    glLineWidth(4);
    double a=2*3.1415*m/60;
    a+= 2*3.1415*s/3600;
    glBegin(GL_LINES);
    glVertex2f(0.0f,0.0f);
    glVertex2f((size-0.15)*sin(a),(size-0.15)*cos(a));
    glEnd();
}
//时针就不用了:)

void callback(int value){
    glClear(GL_COLOR_BUFFER_BIT );
    showpane();
    showsecond(value%60);
    showminute(value/60,value%60);
    //glFlush();
    glutSwapBuffers();
    glutTimerFunc(1000,callback,value+1);
}

void showpane() {
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    for(float a=0.0f;a<=3.1415926*2+0.1;a+=0.05)
        glVertex2f(size*sin(a),size*cos(a));
    glEnd();
}

void voidfn(){
    //抗锯齿
    glEnable (GL_LINE_SMOOTH);
    glHint (GL_LINE_SMOOTH, GL_NICEST);
    glEnable(GL_MULTISAMPLE);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_MULTISAMPLE);//多重采样
    glutInitWindowPosition(100,100);
    glutInitWindowSize(800,800);
    glutCreateWindow("animation2");
    glutDisplayFunc(voidfn);
    glutTimerFunc(1000,callback,0);
    glutMainLoop();
    return 1;
}