#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
using namespace std;
void draw_pixel(GLint cx,GLint cy)
{
   glColor3f(1.0,0.0,0.0);
   glBegin(GL_POINTS);
   glVertex2i(cx,cy);
   glEnd();
}
void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
   draw_pixel(x+h,y+k);
   draw_pixel(-x+h,y+k);
   draw_pixel(x+h,-y+k);
   draw_pixel(-x+h,-y+k);
   draw_pixel(y+h,x+k);
   draw_pixel(y+h,-x+k);
   draw_pixel(-y+h,x+k);
   draw_pixel(-y+h,-x+k);
}
void circle_draw(GLint h,GLint k,GLint r)
{
   GLint d=1-r,x=0,y=r;
   while(y>x)
   {
     plotpixels(h,k,x,y);
     if(d<0)
        d+=2*x+3;
     else
     {
        d+=2*(x-y)+5;
        y--;
     }
      x++;
    }
   plotpixels(h,k,x,y);
}
void Init()
{
  glClearColor(0.0,0.0,1.0,0.0);
  gluOrtho2D(0.0,400.0,0.0,300.0);
}
void display()
{
   GLint xc=100,yc=100,r=50;
   GLint xlc=100,ylc=50;
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0,1.0,0.0);
   glPointSize(2.0);
   circle_draw(xc,yc,r);
   circle_draw(xlc,ylc,r);
   glFlush();
}
int main(int argc,char **argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
   glutInitWindowPosition(50,50);
   glutInitWindowSize(400,300);
   glutCreateWindow("circle creation");
   Init();
   glutDisplayFunc(display);
   glutMainLoop();
}
