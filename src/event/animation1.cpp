// 一个会动的三角形
// Created by czfshine on 19-2-28.
//

// 展示最基本的动画怎么写,整体的框架怎么搭
// 主要是 glut的glutIdleFunc 函数
// 它的声明是`void glutIdleFunc( void (* callback)( void ) );`
// 大概就是在整个程序进入空闲状态(idle)时会调用callback函数.
// 注意:1. 它在空闲也仅仅是空闲时才会调用,所以在别的事件函数做大量计算时,不会保持callback的调用
//     2. 显然调用的时机的不固定的,而且会一直调用,所以不是占满显卡的计算力就是占满cpu,所以慎用:)
//     3. 可以在使用多线程,或者自定义事件的时候用

// 怎么写:
// 写个callback函数改变数据就行
#include <GL/glut.h>

float x=-0.2;
float v=0.00001;//自己调节速度
void callback(void) {
    x+=v;
    if(x>0.2)
        x=-0.2;
    glClear(GL_COLOR_BUFFER_BIT );
    glBegin(GL_TRIANGLES);
    glVertex3f(-0.8f+x,-0.8f, 0.0f);
    glVertex3f( 0.8f+x, 0.0f, 0.0);
    glVertex3f( 0.0f+x, 0.8f, 0.0f);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("animation1");

    glutDisplayFunc(callback);
    glutIdleFunc(callback);//!!!

    glutMainLoop();
    return 1;
}