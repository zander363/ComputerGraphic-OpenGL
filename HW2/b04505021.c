#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

static void 
resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
char message[] = "ROTATING BOX!";
char *messageptr = message;

void output(float x, float y, char *string)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}

void circle(float x,float y,float R){
	glBegin(GL_POLYGON);			
	int i;
	for(i=0;i<40;i++){
		glVertex3f(x+R*sin(i*9*2*M_PI/360),y+R*cos(i*9*2*M_PI/360),0.0);
	}
    glEnd();
}
void square(float x,float y,float R,double theta){
    glPushMatrix();	
	    glRotated(theta,0,0,1);
		glBegin(GL_POLYGON);
		
		glVertex3f(x+0.5*R,y+0.5*R,0.0);
		glVertex3f(x-0.5*R,y+0.5*R,0.0);
		glVertex3f(x-0.5*R,y-0.5*R,0.0);
		glVertex3f(x+0.5*R,y-0.5*R,0.0);
	    glEnd();
    glPopMatrix();
}
static void 
display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 10000.0;
    const double b = -t*360.0;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    


    glPushMatrix();
        glRotated(b,0,0,1);
        
    	glColor3f(0.5+0.5*sin((-60+b)*M_PI/180),0.5+0.5*sin((-60+b)*M_PI/180),1);
        square(0,0.7,0.23,0.0);
    	glColor3f(0.5+0.5*sin((b)*M_PI/180),0.5+0.5*sin((b)*M_PI/180),1);
        square(0,0.7,0.23,60.0);
    	glColor3f(0.5+0.5*sin((60+b)*M_PI/180),0.5+0.5*sin((60+b)*M_PI/180),1);
        square(0,0.7,0.23,120.0);
    	glColor3f(0.5+0.5*sin((120+b)*M_PI/180),0.5+0.5*sin((120+b)*M_PI/180),1);
        square(0,0.7,0.23,180.0);
    	glColor3f(0.5+0.5*sin((180+b)*M_PI/180),0.5+0.5*sin((180+b)*M_PI/180),1);
        square(0,0.7,0.23,240.0);
     	glColor3f(0.5+0.5*sin((240+b)*M_PI/180),0.5+0.5*sin((240+b)*M_PI/180),1);
        square(0,0.7,0.23,300.0);
        glColor3f(0,1,0.5+0.5*cos(b*M_PI/180));
        circle(0,0,0.6);
        glColor3f(0,0,0);
        circle(0,0,0.4);
    	glColor3f(0,1,1);
    glPopMatrix();
    glColor3f(1,0.3+0.5*cos(b*M_PI/180),0.3+0.5*cos(b*M_PI/180));
    output(-0.4-0.6*cos(b*M_PI/180),0.9,messageptr);

    glutSwapBuffers();
}

static void 
idle(void)
{
    glutPostRedisplay();
}

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);

    glutCreateWindow("Moving Square");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();
}

