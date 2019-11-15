// 鼠标 点击事件
// Created by czfshine on 19-11-14.
//
#include <GL/glut.h>
int size=320/2;
void callback(int button, int state, int x, int y) {

    //glClear(GL_COLOR_BUFFER_BIT);
    switch (button){
        case GLUT_RIGHT_BUTTON:{
            glColor3b(127,0,0);
            break;
        }
        case GLUT_LEFT_BUTTON:{
            glColor3b(0,127,0);
            break;
        }
        case GLUT_MIDDLE_BUTTON:{
            glColor3b(0,0,127);
            break;
        }
        default:{

        }
    }
    switch (state){
        case GLUT_UP:{
            glColor3i(64,64,64);
            glPointSize(10.0f); //大小
            break;
        }
        case GLUT_DOWN:{
            glPointSize(20.0f); //大小
            break;
        }
        default:{

        }
    }
    glBegin(GL_POINTS); //表明开始画点
    glVertex2f((float) (x-size)/size,(float )-(y-size)/size);
    glEnd(); //表明结束绘画点，也就是可以画别的东西了
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(size*2,size*2);
    glutCreateWindow("mouse click");
    glutMouseFunc(callback);
    glutMainLoop();
    return 1;
}