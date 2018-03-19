#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI M_PI

static void resize(int width, int height){
	const float ar = (float) width / (float) height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity() ;
}
void spawn_normal(float ax,float ay,float az, float bx,float by,float bz,float cx,float cy,float cz){
	float arrayA[3]={bx-ax,by-ay,bz-az};
	float arrayB[3]={cx-ax,cy-ay,cz-az};
	float x_direct=arrayA[1]*arrayB[2]-arrayA[2]*arrayB[1];
	float y_direct=arrayA[2]*arrayB[0]-arrayA[0]*arrayB[2];
	float z_direct=arrayA[0]*arrayB[1]-arrayA[1]*arrayB[0];
	float length=sqrt(pow(x_direct,2)+pow(y_direct,2)+pow(z_direct,2));
	float temp_divide=1/length;
	x_direct*=temp_divide;
	y_direct*=temp_divide;
	z_direct*=temp_divide;
	glNormal3f(x_direct,y_direct,z_direct);
}
void draw_star(float r,float g,float b){
	float step=M_PI/5.0;  //  pi*36/180
	float table[20][3][3]={
		{{0,0,0.3},{0.8*cos(PI/2-step),0.8*sin(PI/2-step),0},{0,2,0}},
		{{0,0,0.3},{2*cos(PI/2.0-2*step),2*sin(PI/2-2*step),0},{0.8*cos(PI/2-step),0.8*sin(PI/2-step),0}},
		{{0,0,0.3},{0.8*cos(PI/2.0-3*step),0.8*sin(PI/2-3*step),0},{2*cos(PI/2-2*step),2*sin(PI/2-2*step),0}},
		{{0,0,0.3},{2*cos(PI/2.0-4*step),2*sin(PI/2-4*step),0},{0.8*cos(PI/2-3*step),0.8*sin(PI/2-3*step),0}},
		{{0,0,0.3},{0.8*cos(PI/2.0-5*step),0.8*sin(PI/2-5*step),0},{2*cos(PI/2-4*step),2*sin(PI/2-4*step),0}},
		{{0,0,0.3},{2*cos(PI/2.0-6*step),2*sin(PI/2-6*step),0},{0.8*cos(PI/2-5*step),0.8*sin(PI/2-5*step),0}},
		{{0,0,0.3},{0.8*cos(PI/2.0-7*step),0.8*sin(PI/2-7*step),0},{2*cos(PI/2-6*step),2*sin(PI/2-6*step),0}},
		{{0,0,0.3},{2*cos(PI/2.0-8*step),2*sin(PI/2-8*step),0},{0.8*cos(PI/2-7*step),0.8*sin(PI/2-7*step),0}},
		{{0,0,0.3},{0.8*cos(PI/2.0-9*step),0.8*sin(PI/2-9*step),0},{2*cos(PI/2-8*step),2*sin(PI/2-8*step),0}},
		{{0,0,0.3},{0,2,0},{0.8*cos(PI/2-9*step),0.8*sin(PI/2-9*step),0}},

		{{0,0,-0.3},{0,2,0},{0.8*cos(PI/2-step),0.8*sin(PI/2-step),0}},
		{{0,0,-0.3},{0.8*cos(PI/2-step),0.8*sin(PI/2-step),0},{2*cos(PI/2.0-2*step),2*sin(PI/2-2*step),0}},
		{{0,0,-0.3},{2*cos(PI/2-2*step),2*sin(PI/2-2*step),0},{0.8*cos(PI/2.0-3*step),0.8*sin(PI/2-3*step),0}},
		{{0,0,-0.3},{0.8*cos(PI/2-3*step),0.8*sin(PI/2-3*step),0},{2*cos(PI/2.0-4*step),2*sin(PI/2-4*step),0}},
		{{0,0,-0.3},{2*cos(PI/2-4*step),2*sin(PI/2-4*step),0},{0.8*cos(PI/2.0-5*step),0.8*sin(PI/2-5*step),0}},
		{{0,0,-0.3},{0.8*cos(PI/2-5*step),0.8*sin(PI/2-5*step),0},{2*cos(PI/2.0-6*step),2*sin(PI/2-6*step),0}},
		{{0,0,-0.3},{2*cos(PI/2-6*step),2*sin(PI/2-6*step),0},{0.8*cos(PI/2.0-7*step),0.8*sin(PI/2-7*step),0}},
		{{0,0,-0.3},{0.8*cos(PI/2-7*step),0.8*sin(PI/2-7*step),0},{2*cos(PI/2.0-8*step),2*sin(PI/2-8*step),0}},
		{{0,0,-0.3},{2*cos(PI/2-8*step),2*sin(PI/2-8*step),0},{0.8*cos(PI/2.0-9*step),0.8*sin(PI/2-9*step),0}},
		{{0,0,-0.3},{0.8*cos(PI/2-9*step),0.8*sin(PI/2-9*step),0},{0,2,0}}
	};
	glBegin(GL_TRIANGLES);
	int i;
	for(i=0;i<20;i++){
		if(i<10) glColor3f(r,g,b);
		else glColor3f(r/3,g/3,b/3);
		spawn_normal(table[i][0][0],table[i][0][1],table[i][0][2],table[i][1][0],table[i][1][1],table[i][1][2],table[i][2][0],table[i][2][1],table[i][2][2]);
		glVertex3f(table[i][0][0],table[i][0][1],table[i][0][2]);
		glVertex3f(table[i][1][0],table[i][1][1],table[i][1][2]);
		glVertex3f(table[i][2][0],table[i][2][1],table[i][2][2]);
	}
	glEnd();
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
static void display(void){
	const double t = glutGet(GLUT_ELAPSED_TIME) / 10000.0;
	const double a = t*90.0;
	const double b = t*600.0;
	double L=3;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(1,0,0);
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	glPushMatrix();
	gluLookAt(0,0,4+4*sin(3*t),0,0,0,0,1,0);
	glTranslated(0,0,-10);
	glRotated(b/2,0,-1,0);
	glRotated(b,0,0,1);
	double R=4;
		//yellow
		glPushMatrix();
		glTranslated(R*sin(2*M_PI*5/5),R*cos(2*M_PI*5/5),0.0);
		glRotated(b,0,0,-1);
		draw_star(1,1,0);
		glPopMatrix();
		//green
		int flash=(((int)b/2)%200)<3?1:0;
		glPushMatrix();
		glTranslated(R*sin(2*M_PI*4/5),R*cos(2*M_PI*4/5),0.0);
		glRotated(b,0,0,-1);
		draw_star(flash,1,flash);
		glPopMatrix();
		//red
		glPushMatrix();
		glTranslated(R*sin(2*M_PI*3/5),R*cos(2*M_PI*3/5),0.0);
		glRotated(b,0,0,1);
		draw_star(1,0,0);
		glPopMatrix();
		//black
		glPushMatrix();
		glTranslated(R*sin(2*M_PI*2/5),R*cos(2*M_PI*2/5),0.0);
		glRotated(b,0,0,-1);
		glRotated(2*b,0,-1,0);
		draw_star(0,0,0);
		glPopMatrix();
		//blue
		glPushMatrix();
		glTranslated(R*sin(2*M_PI*1/5),R*cos(2*M_PI*1/5),0.0);
		glRotated(b,0,0,-1);
		glRotated(2*b,1,0,0);
		draw_star(0,0,1);
		glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

static void idle(void){
	glutPostRedisplay();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(10,10);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("FreeGLUT Shapes");

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	glClearColor(1,1,1,1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();

	return EXIT_SUCCESS;
}
