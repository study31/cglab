#include<GL/glut.h>
using namespace std;
void house()
{
   glColor3f(1.0,1.0,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(10,10);
   glVertex2f(50,10);
   glVertex2f(50,50);
   glVertex2f(10,50);
   glEnd();
   glColor3f(1.0,1.0,1.0);
   glBegin(GL_POLYGON);
   glVertex2f(30,10);
   glVertex2f(40,10);
   glVertex2f(40,20);
   glVertex2f(30,20);
   glEnd();
   glColor3f(0.0,0.0,0.0);
   glBegin(GL_POLYGON);
   glVertex2f(10,50);
   glVertex2f(50,50);
   glVertex2f(30,70);
   glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    house();
    glFlush();
    glutSwapBuffers();
}
void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        glutDisplayFunc(display);
        glTranslatef(35,35,0);
        glRotatef(-45,0.0,0.0,1.0);
        glTranslatef(-35,-35,0);
        glutPostRedisplay();
    }
}
void myinit()
{
    glClearColor(1.0,0.0,0.0,1.0);
    gluOrtho2D(-100,100,-100,100);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("house");
    myinit();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
