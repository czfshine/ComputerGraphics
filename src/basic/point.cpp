//基础:利用opengl绘制一个点
// Created by czfshine on 19-2-25.
//

#include <GL/glut.h>

/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5.0f); //大小

    glBegin(GL_POINTS); //表明开始画点
    glVertex2f(0.5f,0.8f);//屏幕分为x（-1,1）y（-1,1）的矩形
    glEnd(); //表明结束绘画点，也就是可以画别的东西了

    glFlush(); //注意，和写文件一样有缓冲区的，要更新才能真正的显示
}

int main(int argc,char* argv[])
{
    //一些初始化窗口和opengl的函数
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(800,800);
    glutCreateWindow("The First Point");
    glutDisplayFunc(&Display);
    glutMainLoop();
    return 0;
}