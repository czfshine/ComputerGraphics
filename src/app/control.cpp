// 控制一个cube
// Created by czfshine on 19-11-16.

#include <GL/glew.h>
#include <GL/glut.h>
#include <cstring>
#include <cstdio>
#include <cmath>
#define reg(d) (d/180.0)*3.1415926535
int width = 512;
int height = 512;

//动作变量
float rotateY = 135;
float rotateX = 325;
float rotateZ = 90;
float posX = 0.0f;
float posY = 0.0f;
float posZ = -7.0f;
float sphereX=0;
float sphereY=0;
float sphereZ=0;

//初始化信息
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    //这些让图像效果更好
    glShadeModel(GL_SMOOTH);
//    glEnable(GL_DEPTH_TEST);
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);
    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluPerspective(90.0, (GLfloat)width/height, 1.0, 30.0);
    glOrtho(-5, 5, -5, 5, 0, 15);
}

void drawSphere(float x, float y, float z, float r) {
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    float j = 0;
    for (j = 0; j <= 360; j += 0.1) {
        glVertex3f(x + r * sin(reg(j)), y + r * cos(reg(j)), z);
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    for (j = 0; j <= 360; j += 0.1) {
        glVertex3f(x, y + r * cos(j / 180 * 3.1415), z + r * sin(j / 180 * 3.1415));
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    for (j = 0; j <= 360; j += 0.1) {
        glVertex3f(x + r * cos(j / 180 * 3.1415), y, z + r * sin(j / 180 * 3.1415));
    }
    glEnd();
    glLineWidth(0.5);
}

void draw_weidu(float x, float y, float z, float r){
    for(float d = 80 ;d>=-80;d-=10){
        glBegin(GL_LINE_LOOP);
        float newR= r * cos(d/180*3.1415);
        float newZ= z+r*sin(d/180*3.1415);
        float j = 0;
        for (j = 0; j <= 360; j += 0.1) {
            glVertex3f(x + newR * sin(j / 180 * 3.1415), y + newR * cos(j / 180 * 3.1415), newZ);
        }
        glEnd();
    }
}

void draw_jingdu(float x, float y, float z, float r){
    for(float d = 0 ;d<=180;d+=10){
        glBegin(GL_LINE_LOOP);
        for(float j=0;j<=360;j+=0.1){
            float newZ=cos(j/180*3.1415)*r+z;
            float sinz=sin(j/180*3.1415)*r;
            float newY=cos(d/180*3.1415)*sinz+y;
            float newX=sin(d/180*3.1415)*sinz+x;
            glVertex3f(newX,newY,newZ);
        }
        glEnd();
    }
}

/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(posX, posY, posZ);
    glRotatef(rotateX, 1, 0, 0.0f);
    glRotatef(rotateY, 0, 1, 0.0f);
    glRotatef(rotateZ, 0, 0, 1);

    //接下来和普通画线没区别，注意坐标是三维的
    glColor3f(0.0f, 1.0f, 1.0f);
    GLfloat points[8 * 3] = {2, -2, 2,
                             2, -2, -2,
                             2, 2, -2,
                             2, 2, 2,
                             -2, -2, 2,
                             -2, 2, 2,
                             -2, 2, -2,
                             -2, -2, -2};
    GLubyte index[] = {0, 1, 2, 3,
                       4, 5, 6, 7,
                       0, 3, 5, 4,
                       1, 2, 6, 7
    };
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, points);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index);
    glColor3f(0.0f, 0.5f, 1.0f);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index + 4);
    glColor3f(0.5f, 1.0f, 1.0f);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index + 8);
    glColor3f(0.0f, 1.0f, 0.5f);
    glDrawElements(GL_LINE_LOOP, 4, GL_UNSIGNED_BYTE, index + 12);
    glDisableClientState(GL_VERTEX_ARRAY);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawSphere(sphereX, sphereY, sphereZ, 3);
    glColor3f(0.0f, 1.0f, 0.5f);
    draw_weidu(sphereX, sphereY, sphereZ, 3);
    draw_jingdu(sphereX,sphereY,sphereZ,3);
    glPopMatrix();
    // 交换显示缓冲区
    glutSwapBuffers();
}
bool inZoom= false;
void listenKey(unsigned char key, int x, int y) {
    switch (key) {
//        case 'W':
        case 'w': {
            posZ -= 0.1f;
            break;
        }
        case 's': {
            posZ += 0.1f;
            break;
        }
        case 'a': {
            posX -= 0.1f;
            break;
        }
        case 'd': {
            posX += 0.1f;
            break;
        }
        case 'q': {
            posY += 0.1f;
            break;
        }
        case 'e': {
            posY -= 0.1f;
            break;
        }
        case 'h': {
            rotateX -= 1.1f;
            break;
        }
        case 'k': {
            rotateX += 1.1f;
            break;
        }
        case 'u': {
            rotateZ -= 1.1f;
            break;
        }
        case 'i': {
            rotateZ += 1.1f;
            break;
        }
        case 'n': {
            rotateY -= 1.1f;
            break;
        }
        case 'm': {
            rotateY += 1.1f;
            break;
        }
        case'r':{
            sphereX+=0.1;
            break;
        }
        case 't':{

            sphereX-=0.1;
            break;
        }
        case 'f':{

            sphereY+=0.1;
            break;
        }
        case 'g':{

            sphereY-=0.1;
            break;
        }
        case 'v':{

            sphereZ+=0.1;
            break;
        }
        case'b':{

            sphereZ-=0.1;
            break;
        }
        case ' ':{
            if(!inZoom){
                inZoom=!inZoom;
                glOrtho(-15, 15, -15, 15, -100, 150);
            }
            break;
        }

    }
    printf("(%5.2f,%5.2f,%5.2f):<%7.2f,%7.2f,%7.2af>\n",posX,posY,posZ,rotateX,rotateY,rotateZ);
    glutPostRedisplay();
}
void upKey(unsigned char key,int x,int y){
    if(key==' '){
        if(inZoom){
            inZoom=!inZoom;
            glLoadIdentity()
            glOrtho(-5, 5, -5, 5, 0, 15);
            glutPostRedisplay();
        }
    }
}

int main(int argc, char *argv[]) {
    //一些初始化窗口和opengl的函数
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glewInit();
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(width, height);
    glutCreateWindow("3D control");
    init();
    glutDisplayFunc(&Display);
    glutKeyboardFunc(&listenKey);
    glutKeyboardUpFunc(&upKey);

    glutMainLoop();
    return 0;
}