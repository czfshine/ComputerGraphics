// 控制一个cube
// Created by czfshine on 19-11-16.


#include <GL/glew.h>
#include <GL/glut.h>
#include <cstring>
#include <cstdio>

int width = 512;
int height = 512;

//动作变量
float rotateY = 0.0f;
float rotateX= 0.0f;
float rotateZ= 0.0f;
float posX=0.0f;
float posY=0.0f;
float posZ=-7.0f;

//初始化信息
void init()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    //这些让图像效果更好
    glShadeModel(GL_SMOOTH);
//    glEnable(GL_DEPTH_TEST);
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable (GL_LINE_SMOOTH);
    glHint (GL_LINE_SMOOTH, GL_NICEST);
    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (GLfloat)width/height, 1.0, 30.0);
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
    glTranslatef(posX, posY, posZ);
    glRotatef(rotateX,1,0,0.0f);
    glRotatef(rotateY,0,1,0.0f);
    glRotatef(rotateZ,0,0,1);

    //接下来和普通画线没区别，注意坐标是三维的
    glColor3f (0.0f, 1.0f, 1.0f);
    GLfloat points[8 * 3] = {2,-2,2,
                             2,-2,-2,
                             2,2,-2,
                             2,2,2,
                             -2,-2,2,
                             -2,2,2,
                             -2,2,-2,
                             -2,-2,-2};
    GLubyte index[] = {0,1,2,3,
                       4,5,6,7,
                       0,3,5,4,
                       1,2,6,7
        };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, points);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index);
    glColor3f (0.0f, 0.5f, 1.0f);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index+4);
    glColor3f (0.5f, 1.0f, 1.0f);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index+8);
    glColor3f (0.0f, 1.0f, 0.5f);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index+12);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();

    // 交换显示缓冲区
    glutSwapBuffers() ;
}

void listenKey(unsigned char key,int x,int y){
    switch (key){
//        case 'W':
        case 'w':
        {
            posZ-=0.1f;
            break;
        }
        case 's':
        {
            posZ+=0.1f;
            break;
        }
        case 'a':{
            posX-=0.1f;
            break;
        }
        case 'd':{
            posX+=0.1f;
            break;
        }
        case 'q':{
            posY+=0.1f;
            break;
        }
        case 'e':{
            posY-=0.1f;
            break;
        }
        case 'h':{
            rotateX-=1.1f;
            break;
        }
        case 'k':{
            rotateX+=1.1f;
            break;
        }
        case 'u':{
            rotateZ-=1.1f;
            break;
        }
        case 'i':{
            rotateZ+=1.1f;
            break;
        }
        case 'n':{
            rotateY-=1.1f;
            break;
        }
        case 'm':{
            rotateY+=1.1f;
            break;
        }

    }
    glutPostRedisplay();
}
int main(int argc,char* argv[])
{
    //一些初始化窗口和opengl的函数
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH|GLUT_MULTISAMPLE);
    glewInit();
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow("3D");
    init() ;
    glutDisplayFunc(&Display);
    glutKeyboardFunc(&listenKey);

    glutMainLoop();
    return 0;
}