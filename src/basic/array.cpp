// 使用opengl的数组功能画图
// Created by czfshine on 19-2-26.
//
// 在之前画图形都是一个一个点画的,在有大量图形时函数调用带来的开销太大了
// opengl提供了一些功能,可以批量的把一系列点的坐标一次性传递给服务端
// 以画两个四边形的绘图函数为例
// 原来的代码如下:
// ```c++
//    glBegin(GL_QUADS);
//    glVertex2f(0.5f, 0.8f);//A
//    glVertex2f(0.5f, 0.7f);//B
//    glVertex2f(0.6f, 0.7f);//C
//    glVertex2f(0.6f, 0.8f);//D
//    //ABCD
//    glVertex2f(0.7f, 0.6f);//E
//    glVertex2f(0.7f, 0.5f);//F
//    glVertex2f(0.6f, 0.5f);//G
//    glVertex2f(0.6f, 0.6f);//H
//    //EFGH
//    glEnd();
// ```

// 使用数组功能:
// 首先将坐标提取成数组
// GLfloat points [8*2] ={0.5,0.8,0.5,0.7,0.6,0.7,0.6,0.8,0.7,0.6,0.7,0.5,0.6,0.5,0.6,0.6};
// 然后告诉opengl要使用数组模式
// glEnableClientState(GL_VERTEX_ARRAY);
// 把数组传给它
// glVertexPointer(2,GL_FLOAT,0,points); //2代表一个点由两个坐标组成
// 然后使用这些点绘图
// GLubyte index[]= {0,1,2,3,4,5,6,7} ;
// glDrawElements(GL_QUADS,8,GL_UNSIGNED_BYTE,index); //GL_QUADS 说明要使用GL_QUADS 方法画图,8表示要8个点
// 注意到有个index数组,它表示我们要以什么顺序取点,这里是0~7,说明按顺序取点
// 假如我们的图案有好多个点重叠,就不用一个一个传递,改变index就行
// 比如画 ABCD 和CDHG 两个矩形,我们使用的index数组为{0,1,2,3,2,3,7,6}
#include <GL/glut.h>

void array() {
    glColor3f(0.5, 0.5, 0.5);
    GLfloat points[8 * 2] = {0.4, 0.8,
                             0.4, 0.7,
                             0.5, 0.7,
                             0.5, 0.8,
                             0.7, 0.8,
                             0.7, 0.7,
                             0.6, 0.7,
                             0.6, 0.8};
    GLubyte index[] = {0, 1, 2, 3, 4, 5, 6, 7};
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, points); //2代表一个点由两个坐标组成
    glDrawElements(GL_QUADS, 8, GL_UNSIGNED_BYTE, index);


    //手动平移hhh 不然和上面的重叠了
    for (int i = 0; i < 8 * 2; ++i) {
        points[i] -= 0.25;
    }

    glColor3f(0.5, 0.5, 0.0);
    GLubyte index2[] = {0, 1, 2, 3, 2, 3, 7, 6}; //ABCDCDHG
    glDrawElements(GL_QUADS, 8, GL_UNSIGNED_BYTE, index2);

    glDisableClientState(GL_VERTEX_ARRAY); //记得停止数组模式!!

}

//注意到上面的函数每一次调用draw画出来的两个图形颜色要一样,下面使用混合数组(顶点和颜色)创建图形
//所需的颜色
#define white 0.9,0.9,0.9
#define black 0,0,0
#define glay  0.5,0.5,0.5

//所需的点
#define s 0.05
#define x 0
#define y 0
#define p1 x+0,1*s+y,0.0f
#define p2 x+0,4*s+y,0.0f
#define p3 x+3*s,0+y,0.0f
#define p4 x+3*s,3*s+y,0.0f
#define p5 x+5*s,4*s+y,0.0f
#define p6 x+5*s,1*s+y,0.0f
#define p7 x+2*s,5*s+y,0.0f
#define p8 x+2*s,2*s+y,0.0f
#define p(pp) glVertex3f(pp);

void colorarray() {


    glBegin(GL_QUADS);
    glColor3f(black);
    p(p1);
    p(p3);
    p(p4);
    glColor3f(white);
    p(p2);
    p(p2);
    p(p4);
    glColor3f(glay);
    p(p5);
    p(p7);
    p(p4);
    p(p3);
    glColor3f(black);
    p(p6);
    p(p5);
    glEnd();

#define  x -0.5
#define y -0.5
    GLfloat ps[] = {
            black, p1,
            white, p2,
            black, p3,
            glay, p4,
            black, p5,
            black, p6,
            glay, p7,
            black, p8};

    glInterleavedArrays(GL_C3F_V3F, 0, ps);
    GLubyte psindex[] = {0, 2, 3, 1, 1, 3, 4, 6, 3, 2, 5, 4};
    glDrawElements(GL_QUADS, 12, GL_UNSIGNED_BYTE, psindex);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display(void) {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    array();
    colorarray();
    glFlush(); //注意，和写文件一样有缓冲区的，要更新才能真正的显示
}

int main(int argc, char *argv[]) {
    //一些初始化窗口和opengl的函数
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(900, 900);
    glutCreateWindow("The First Point");
    glutDisplayFunc(&Display);
    glutMainLoop();
    return 0;
}