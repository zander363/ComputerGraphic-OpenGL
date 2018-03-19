#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <string.h>
#include <GL/glut.h> 
#include<math.h>

void init(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,300.0,0.0,300.0);
}

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
//color3f colorscheme[]={{0,0,1},{1,0,1},{1,0,0},{1,1,0},{0,1,0}};
char message1[] = "B  e  a  c  h";
char message2[] = "V  o  l  l  e  y  b  a  l  l";
char *messageptr1 = message1;
char *messageptr2 = message2;

void output(float x, float y, char *string)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}
void star(float x,float y,float R,float theta){
	glBegin(GL_TRIANGLES);			
	int i;
	glLineWidth(5);
	for(i=0;i<5;i++){
		glVertex3f(x+R*sin((theta+i*72)*2*M_PI/360),y+R*cos((theta+i*72)*2*M_PI/360),0.0);
		glVertex3f(x+0.4*R*sin((theta+36+i*72)*2*M_PI/360),y+0.4*R*cos((theta+36+i*72)*2*M_PI/360), 0.0);
		glVertex3f(x+0.4*R*sin((theta-36+i*72)*2*M_PI/360),y+0.4*R*cos((theta-36+i*72)*2*M_PI/360), 0.0);
	}
    glEnd();
    glBegin(GL_POLYGON);
    	for(i=0;i<5;i++){		
		glVertex3f(x+0.4*R*sin((theta+36+i*72)*2*M_PI/360),y+0.4*R*cos((theta+36+i*72)*2*M_PI/360), 0.0);
	}
	glEnd();
    
}
void circle(float x,float y,float R){
	glBegin(GL_POLYGON);			
	int i;
	for(i=0;i<20;i++){
		glVertex3f(x+R*sin(i*18*2*M_PI/360),y+R*cos(i*18*2*M_PI/360),0.0);
	}
    glEnd();
}
void halfCircle(float x,float y,float R,float theta){
	glBegin(GL_LINE_STRIP);	
	int i;
	glLineWidth(10);
	for(i=0;i<11;i++){
		glVertex3f(x+R*sin((theta+i*18)*2*M_PI/360),y+R*cos((theta+i*18)*2*M_PI/360),0.0);
	}
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);			//flag
    	glColor3f(1,1,1);
        glVertex3f(-0.8, 0.1, 0.0);
        glVertex3f(0.8, 0.1, 0.0);
		glVertex3f(0.8, 0.9, 0.0);
        glVertex3f(-0.8, 0.9, 0.0);
    glEnd();
    glBegin(GL_QUADS);			//left
    	glColor3f(0,0,1);
		glVertex3f(-0.03, -0.36, 0.0);
    	glVertex3f(0.02, -0.41, 0.0);
        glVertex3f(0.2,-0.25, 0.0);
        glVertex3f(0.15, -0.2, 0.0);
    glEnd();
	glBegin(GL_QUADS);			//body
    	glColor3f(0,1,1);
    	glVertex3f(0.1, -0.68, 0.0);
        glVertex3f(0,-0.7, 0.0);
		glVertex3f(-0.1, -0.4, 0.0);
        glVertex3f(0, -0.38, 0.0);
    glEnd();   
    glColor3f(1,0,0);
    circle(-0.08,-0.28,0.1);	//head
	glBegin(GL_QUADS);			//right_upper
    	glColor3f(0,0,1);
		glVertex3f(-0.23, -0.33, 0.0);
    	glVertex3f(-0.18, -0.38, 0.0);
        glVertex3f(-0.15,-0.22, 0.0);
        glVertex3f(-0.2, -0.17, 0.0);
    glEnd();
	glBegin(GL_QUADS);			//right_lower
    	glColor3f(0,0,1);
		glVertex3f(-0.2, -0.3, 0.0);
    	glVertex3f(-0.25, -0.35, 0.0);
        glVertex3f(-0.1,-0.48, 0.0);
        glVertex3f(-0.05, -0.43, 0.0);
    glEnd();
    glBegin(GL_QUADS);			//left_leg
    	glColor3f(0,0,1);
    	glVertex3f(0.2, -0.83, 0.0);
        glVertex3f(0.1,-0.85, 0.0);
		glVertex3f(0, -0.7, 0.0);
        glVertex3f(0.1, -0.68, 0.0);
    glEnd();   
    glBegin(GL_QUADS);			//right_leg
    	glColor3f(0,0,1);
    	glVertex3f(0.14, -0.88, 0.0);
        glVertex3f(0.04,-0.9, 0.0);
		glVertex3f(0, -0.7, 0.0);
        glVertex3f(0.1, -0.68, 0.0);
    glEnd();   
        glBegin(GL_QUADS);			//lower_left_leg
    	glColor3f(0,0,1);
		glVertex3f(-0.13, -0.93, 0.0);
    	glVertex3f(-0.08, -0.98, 0.0);
        glVertex3f(0.15,-0.83, 0.0);
        glVertex3f(0.1,-0.78, 0.0);
    glEnd();
        glBegin(GL_QUADS);			//lower_right_leg
    	glColor3f(0,0,1);
    glEnd();

    //stars
    glColor3f(0,0,1);
    star(-0.5,0.5,0.1,-60);
    glColor3f(1,1,0);
    star(-0.3,0.3,0.1,-30);
    glColor3f(0,0,0);
    star(0,0.2,0.1,0);
    glColor3f(0,1,0);
    star(0.3,0.3,0.1,30);
    glColor3f(1,0,0);
    star(0.5,0.5,0.1,60);
    //U
    glColor3f(0,0,0);
    halfCircle(0,0.6,0.2,90);
    halfCircle(0,0.6,0.1,90);

    glBegin(GL_LINE_STRIP);	
		glLineWidth(10);
    	glVertex3f(0.2,0.6,0);
    	glVertex3f(0.2, 0.8, 0.0);
    glEnd();
	glBegin(GL_LINE_STRIP);	
		glLineWidth(10);
		glVertex3f(0.1,0.6,0);
    	glVertex3f(0.1, 0.8, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);	
		glLineWidth(10);
    	glVertex3f(-0.2,0.6,0);
    	glVertex3f(-0.2, 0.8, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);	
		glLineWidth(10);
    	glVertex3f(-0.1,0.6,0);
    	glVertex3f(-0.1, 0.8, 0.0);
    glEnd();
    glBegin(GL_LINE_STRIP);	
    	glLineWidth(10);
    	glVertex3f(0.2,0.8,0);
    	glVertex3f(0.1, 0.8, 0.0);
    glEnd();    
    glBegin(GL_LINE_STRIP);	
		glLineWidth(10);
		glVertex3f(-0.2,0.8,0);
    	glVertex3f(-0.1, 0.8, 0.0);
    glEnd();
	glColor3f(1,1,0);
	circle(0.3,-0.18,0.1);	//ball
    glColor3f(1,0,0);
    /*
    glColor3f(0,0,1);		
    glRasterPos2f(-0.6, 0); 
    glutBitmapCharacter(font, 'C');
    glColor3f(1,0,1);
    glRasterPos2f(-0.3, 0); 
    glutBitmapCharacter(font, 'A');
    glColor3f(1,0,0);
    glRasterPos2f(0, 0); 
    glutBitmapCharacter(font, 'N');
    glColor3f(1,1,0);
    glRasterPos2f(0.3, 0); 

    glutBitmapCharacter(font, 'O');
    glColor3f(0,1,0);
    glRasterPos2f(0.6, 0); 

    glutBitmapCharacter(font, 'E');
	*/
	//font
	glColor3f(1,1,0);
	output(-0.5,0,messageptr1);
	glColor3f(0,1,1);
	output(0,0,messageptr2);

	glFlush();
}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(300,300);
	glutInitWindowSize(900,900);
    glutCreateWindow("Computer Graphics\n"); 
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
