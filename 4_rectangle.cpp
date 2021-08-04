#include<GL/glut.h>
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POLYGON);
   glVertex2f(-0.5,-0.5);
   glVertex2f(-0.5,0.5);
   glVertex2f(0.5,0.5);
   glVertex2f(0.5,-0.5);
   glEnd();
   glFlush();
}
void init()
{
   glClearColor(0.5,0.5,0.5,0.0);
   glColor3f(1.0,0.0,1.0);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
}
int main(int argc,char **argv)
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
   glutInitWindowPosition(0,0);
   glutInitWindowSize(800,500);
   glutCreateWindow("rectangle");
   init();
   glutDisplayFunc(display);
   glutMainLoop();
}
