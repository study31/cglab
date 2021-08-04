#include <stdlib.h>
#include <stdio.h>
#include<GL/glut.h>
using namespace std;
GLvoid scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4);
GLint k=0,m,n;

typedef struct 
{
GLfloat x,y;
}point;
point p[250000];


void edgedetect(float x1,float y1,float x2,float y2)
{
GLfloat mx,my,temp,a,b;
GLint i;
	if((y2-y1)<0)
	{
		temp=y1;y1=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	my=y2-y1;       
        printf("the change in  delta x is  %f and delta y  are %f   \n",mx,my);
	for(i=0;i<=my;i++)
	{      
                a=x1+i*mx;
                b=y1+i;
		p[k].x=(x1+i*mx);
                p[k].y=y1+i;
                k++;
        }
}
void scanfill()
{
GLfloat x1=200,y1=10,x2=100,y2=250,x4=200,y4=150,x3=300,y3=400;
bool flag;
GLfloat sx[500][500] ;
GLint  count[500]={0};
GLint c;
       
        printf("k value is %d",k);
 

   
	edgedetect(x1,y1,x2,y2);
	edgedetect(x2,y2,x3,y3);
	edgedetect(x3,y3,x4,y4);
	edgedetect(x4,y4,x1,y1);
 

	for(int m=0;m<500;m++)
	{ 
          c=0;
           printf("\nforscanline %d   x intercepts are::",m);
              for(int n=0;n<k;n++)
          {
		if(p[n].y==m)
                {
                 sx[c][m]=p[n].x;
                 count[m]=c;
               printf("%f\t",sx[c][m]);
                  c++;
                }                 
         
	  }
				
	         // printf("scan line is %d",m);
	}
	   
           for(int m=0;m<500;m++)
        {
          if(count[m]>0)
          {
          for(int j=0;j<=count[m];j=j+2)
          {   
                   for(int z=sx[j][m];z<=sx[j+1][m];z++)
                   {
                        printf("(\t%d,%d \n)",z,m);;
                        glBegin(GL_POINTS);  glVertex2f(z,m);  glEnd();
                       
                    }
                    
            } 
           }    
        printf("scanline %d has finished\n",m);
    }
}

void display(void)
 {
 glClear (GL_COLOR_BUFFER_BIT);
 glColor3f (1.0, 0.0, 0.0);
 scanfill();
 glFlush();
 }

void myinit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	gluOrtho2D(0.0,500,0.0,500.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Filling a Polygon using Scan-line Algorithm");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
