//基础:利用opengl绘制线和形状
// Created by czfshine on 19-2-25.
//
// 屏幕分为x（-1,1）y（-1,1）的矩形
#include <GL/glut.h>

// note:这个文件使用opengl提供的API画线和图形
// 就目前而言要绘制一块图形,
// 先告诉opengl说你要画什么类型的图形,
// 然后提供一些点(和其他一些东西)作为参照,
// 最后跟opengl说你画完了:)
// 代码格式如下:
// ```c++
//    glBegin(XXX);
//      LALALA...
//    glEnd();
// ```
// 其中 XXX 可以是下面常量中的一个:
// GL_POINTS
// GL_LINES
// GL_LINE_LOOP
// GL_LINE_STRIP
// GL_TRIANGLES
// GL_TRIANGLE_STRIP
// GL_TRIANGLE_FAN
// GL_QUADS
// GL_QUAD_STRIP
// GL_POLYGON
// 具体意思看下面的代码
// LALALA部分可以是多条语句,
// 主要有:
// * glVertex* 增加坐标点
// * glColor*改变(以后图形的)颜色
// 现在先用到这些API,基本上可以画很多东西了.
/**
 * 线
 */
void line() {
    glLineWidth(10.0f);//宽度
    glColor3f(0.5f, 0.5f, 0.0f);

    //1.连续线段
    glBegin(GL_LINE_STRIP);
    //3个点两条线段
    glVertex2f(-0.8f, 0.75f);//A
    glVertex2f(-0.6f, 0.85f);//B
    glVertex2f(-0.4f, 0.75f);//C

    //A--B--C
    glEnd();

    //2.两个点中间只有一条线
    glBegin(GL_LINES);
    //A--B   C--D  E--F G--H
    //第一条线段
    glVertex2f(-0.8f, 0.65f);//A
    glVertex2f(-0.6f, 0.75f);//B
    //第二条线段,注意下面的点和上面的点中间没有线段
    glVertex2f(-0.4f, 0.65f);//C
    glVertex2f(-0.6f, 0.75f);//D
    //三
    glVertex2f(-0.8f, 0.55f);//E
    glVertex2f(-0.6f, 0.65f);//F
    //四
    glVertex2f(-0.4f, 0.55f);//G
    glVertex2f(-0.6f, 0.65f);//H
    glEnd();

    //3自动闭合,第一个点和最后一个点会自动加线
    glBegin(GL_LINE_LOOP);
    //三个点一共三条线段
    glVertex2f(-0.8f, 0.45f);//A
    glVertex2f(-0.6f, 0.55f);//B
    glVertex2f(-0.4f, 0.45f);//C

    //A--B--C--A
    glEnd();
}

float margin = 0.1;
int row = 3;
int col = 3;

/**
 * 绘制格子3*3的绿色格子
 */
void grid() {

    glLineWidth(4.0f); //线宽
    glColor3f(0.f, 0.5f, 0.0f); //画笔颜色
    glBegin(GL_LINES); //画线
    for (int i = 0; i <= row; i++) {
        glVertex2f(margin - 1, (1.0 - margin) - i * ((2.0 - 2.0 * margin) / row));//起点
        glVertex2f(1 - margin, (1.0 - margin) - i * ((2.0 - 2.0 * margin) / row));//终点
    }
    for (int i = 0; i <= col; i++) {
        glVertex2f((1.0 - margin) - i * ((2.0 - 2.0 * margin) / col), margin - 1);
        glVertex2f((1.0 - margin) - i * ((2.0 - 2.0 * margin) / col), 1 - margin);
    }
    glEnd();
}

/**
 * 三角形
 */
void triangles() {
    glLineWidth(4.0f); //线宽

    //1.三个点一个三角形
    glBegin(GL_TRIANGLES);
    glColor3f(0.f, 0.5f, 0.5f); //画笔颜色

    glVertex2f(-0.2f, 0.85f);//A
    glVertex2f(-0.1f, 0.75f);//B
    glVertex2f(-0.0f, 0.85f);//C
    //ABC
    glVertex2f(-0.2f, 0.65f);//D
    glVertex2f(-0.1f, 0.75f);//E
    glVertex2f(-0.0f, 0.65f);//F
    //DEF
    glEnd();

    //2.连续三个点一个三角形
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 0.5f, 0.0f); //画笔颜色
    glVertex2f(0.0f, 0.65f);//A
    glVertex2f(0.0f, 0.85f);//B
    glVertex2f(0.1f, 0.65f);//C
    //ABC
    glVertex2f(0.15f, 0.80f);//D
    //BCD
    glVertex2f(0.2f, 0.80f);//E
    //CDE
    glEnd();

    //3.以第一个点为中心,剩下连续两个点为一个三角形
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.2f, 0.0f); //画笔颜色
    glVertex2f(0.0f, 0.45f);//中心 A

    glVertex2f(-0.1f, 0.6f);//B
    glVertex2f(0.1f, 0.6f);//C
    //ABC一个三角形
    glVertex2f(0.2f, 0.45f);//D
    //ACD一个三角形
    glVertex2f(0.1f, 0.3f);//E
    //ADE一个三角形
    glVertex2f(-0.1f, 0.3f);//F
    //AEF一个三角形
    glEnd();


}

/**
 * 四边形
 */
void quads() {
    //1.一个四边形显然要四个点
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.0f, 0.0f); //画笔颜色
    glVertex2f(0.5f, 0.8f);//A
    glVertex2f(0.5f, 0.7f);//B
    glVertex2f(0.6f, 0.7f);//C
    glVertex2f(0.6f, 0.8f);//D
    //ABCD
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(0.7f, 0.6f);//E
    glVertex2f(0.7f, 0.5f);//F
    glVertex2f(0.6f, 0.5f);//G
    glVertex2f(0.6f, 0.6f);//H
    //EFGH
    glEnd();

    //2.连续画,每四个点确定一个四边形,每两个点确定一次
    glBegin(GL_QUAD_STRIP);
    glVertex2f(-0.9f, -0.1f);//A
    glVertex2f(-0.9f, 0.1f);//B
    glVertex2f(-0.7f, -0.1f);//C
    glVertex2f(-0.7f, 0.1f);//D
    //ABDC 注意顺序!!
    glVertex2f(-0.6f, 0.0f);//E
    glVertex2f(-0.6f, 0.2f);//F
    //CDFE 注意顺序!!
    glVertex2f(-0.4f, 0.0f);//G
    glVertex2f(-0.4f, 0.2f);//H
    //EFHG 注意顺序!!
    glEnd();
}

/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    grid();
    line();
    triangles();
    quads();
    glFlush();//注意，和写文件一样有缓冲区的，要更新才能真正的显示
}

int main(int argc, char *argv[]) {
    //一些初始化窗口和opengl的函数
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(800, 800);
    glutCreateWindow("The Second Shapes");
    glutDisplayFunc(&Display);
    glutMainLoop();
    return 0;
}