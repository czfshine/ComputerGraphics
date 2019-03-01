// 画像素点
// Created by czfshine on 19-2-26.
//

// 在之前的程序里都是用坐标表示图形,或者说都是矢量的
// 下面就来画像素,不够个人并不推荐直接绘制屏幕的像素点,
// 考虑到不同执行环境,可能效果并没有在开发机上的好
// 除非必要,否则不要使用
// 先不涉及复杂的坐标系统,和缓存,全都以默认状态
// 窗口左下角为0,0,使用RGB色彩每个像素需要3个数据,
// 所以要画(W,H)大小的像素区域需要一个W*H*3的数组
//
// 我们要用到的API的声明如下:
// ```
// void glDrawPixels( GLsizei width, GLsizei height,
//                                    GLenum format, GLenum type,
//                                    const GLvoid *pixels );
// width和height是宽度和高度,format是色彩模式,也是数据的模式,
// type和其他api一样指代pixels数组的类型,pixels就是我们准备好要画像素的数据了
// 示例如下:
#include <GL/glut.h>
#include <cstdio>

#define H 800
#define W 800

/**
 * 生成(x,y)位置对应的颜色
 * @param x
 * @param y
 * @param r 输出参数
 * @param g 输出参数
 * @param b 输出参数
 */
void getcolor(int x,int y, float *r, float*g, float*b){
    *r=0.0;
    *g=1.0*x/W;
    *b=1.0*y/H;
}

//下面给出其他一些颜色函数,可忽略
/*

//计算迭代次数
#define maxr 9999
#define minr 0.00001
#define maxn 1024
// Z_0 =X+Yi
// for i =0...maxn do
//  n=i
//  Z_{n+1} =Z_{N}^{2}
//  if(abs(Zn+1)>maxr)
//     return +i
//  else if(abs(Zn+1)<minr)
//    return -i
//  else
//    continue
// return maxn+1;
int getiter(double x, double y){

    double r=x;
    double i=y;

    for (int j = 0; j <= maxn; ++j) {
        double len=r*r+i*i;
        if(len > maxr*maxr){
            return j;
        }else{
            if(len<minr*minr){
                return -j;
            }
        }

        double nr=r*r-i*i;
        double ni=2*r*i;
        r=nr+x;
        i=ni+y;
    }
    return  maxn+1;
}
#define size 1.5848931924611143e-8
#define sox  -1.749763331236
#define soy  2.745433083104e-05
void getcolor2(int x,int y, float *r, float*g, float*b) {

    double sx=sox+2.0*size*((1.0*x-(W/2)))/W;
    double sy=soy+2.0*size*((1.0*y-(H/2)))/H;

    int iter=getiter(sx,sy);
    if(iter>0){
        *b= static_cast<float>((iter /1024.0));
    }else{
        *r= static_cast<float>((iter /1024.0));
        *g= static_cast<float>((iter /1024.0));
    }
}
*/
/**
 * 主要的绘制函数
 * 因为这个程序是静态而且没有交互，所以只要这一个函数就行
 * @return
 */
void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //我们的数组
    float data[H][W][3]={0};
    auto * p= reinterpret_cast<float *>(data);
    for (int i = 0; i < H*W * 3; i+=3) {
        int x=i%(W*3)/3;
        int y=i/(W*3);
        //设置数据
        getcolor(x,y,p+i,p+i+1,p+i+2);
    }
    //画
    glDrawPixels(W,H,GL_RGB,GL_FLOAT,p);
    //glutSwapBuffers();
    glFlush(); //注意，和写文件一样有缓冲区的，要更新才能真正的显示
}

int main(int argc,char* argv[])
{
    //一些初始化窗口和opengl的函数
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(800,800);
    glutCreateWindow("Pixels");
    glutDisplayFunc(&Display);
    glutMainLoop();
    return 0;
}