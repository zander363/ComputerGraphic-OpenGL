#include <windows.h>
#include <string.h>
#include <GL/glut.h> 
#include<math.h>

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,300.0,0.0,300.0);
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
void circle(float x,float y,float R){
	glBegin(GL_POLYGON);			
	int i;
	int n=40;
	for(i=0;i<n;i++){
		glVertex3f(x+R*sin(i*2*M_PI/n),y+R*cos(i*2*M_PI/n),0.0);
	}
	glEnd();
}
void ecllipse(float x,float y,float a,float b){
	glBegin(GL_POLYGON);			
	int i;
	int n=40;
	for(i=0;i<n;i++){
		glVertex3f(x+a*sin(i*2*M_PI/n),y+b*cos(i*2*M_PI/n),0.0);
	}
	glEnd();
}

void ball(float x,float y,float r){
	glColor3f(0,0,1);
	circle(x,y,0.2*5*r);
	glColor3f(1,1,1);
	ecllipse(x,y,0.18*5*r,0.15*5*r);
	glColor3f(1,1,0.3);
	ecllipse(x,y,0.19*5*r,0.09*5*r);
}
void autoRectangle(float upperMid_x,float upperMid_y,float lowerMid_x,float lowerMid_y,float width){
	float L=pow(pow((upperMid_x-lowerMid_x),2)+pow((upperMid_y-lowerMid_y),2),0.5);
	float theta = atan((lowerMid_y-upperMid_y)/(lowerMid_x-upperMid_x));
	float adjust=(lowerMid_x-upperMid_x)<0?180:0;

	glPushMatrix();	

	glTranslated(upperMid_x,upperMid_y,0);
	glRotated(theta*360/2/M_PI+adjust,0,0,1);

	glBegin(GL_POLYGON);			
	glVertex3f(0,width/2,0);
	glVertex3f(0,-width/2,0);
	glVertex3f(L,-width/2,0);
	glVertex3f(L,width/2,0);
	glEnd();

	glRotated(theta*360/2/M_PI+adjust,0,0,-1);
	glTranslated(-upperMid_x,-upperMid_y,0);

	glPopMatrix();
}
void arcRectangle(float upperMid_x,float upperMid_y,float lowerMid_x,float lowerMid_y,float width){
	float L=pow(pow((upperMid_x-lowerMid_x),2)+pow((upperMid_y-lowerMid_y),2),0.5);
	float theta = atan((lowerMid_y-upperMid_y)/(lowerMid_x-upperMid_x));
	float adjust=(lowerMid_x-upperMid_x)<0?180:0;

	glPushMatrix();	

	glTranslated(upperMid_x,upperMid_y,0);
	glRotated(theta*360/2/M_PI+adjust,0,0,1);

	glBegin(GL_POLYGON);			
	glVertex3f(0,width/2,0);
	glVertex3f(0,-width/2,0);
	glVertex3f(L,-width/2,0);
	glVertex3f(L,width/2,0);
	glEnd();

	circle(0,0,width/2);
	circle(L,0,width/2);

	glRotated(theta*360/2/M_PI+adjust,0,0,-1);
	glTranslated(-upperMid_x,-upperMid_y,0);

	glPopMatrix();
}
void shock(float x,float y,float r){
	glColor3f(1,0,0);
	autoRectangle(0,r,0,-0.5*r,0.2*r);
	autoRectangle(0,-0.8*r,0,-r,0.2*r);

}

void littlePeople(float x,float y,float r){
	glColor3f(0.9,0.7,0.6);
	circle(x,y,r);
	autoRectangle(x,y,x,y-r*2,r/1.8);
}
void FrontPerson(float head_x,float head_y,float upperBody_x,float upperBody_y,float lowerBody_x,float lowerBody_y,
		float width,float rightArm_x,float rightArm_y,float rightFisk_x,float rightFisk_y,
		float leftArm_x,float leftArm_y,float leftFisk_x,float leftFisk_y,float rightLeg_x,float rightLeg_y,
		float rightFoot_x,float rightFoot_y,float leftLeg_x,float leftLeg_y,float leftFoot_x,float leftFoot_y,float r,float g,float b){
	glColor3f(0.9,0.7,0.6); //skinColor
	glColor3f(r,g,b); //pantsColor
	//rightLeg
	float dis_x=lowerBody_x-rightLeg_x;
	float dis_y=lowerBody_y-rightLeg_y;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(rightLeg_x,rightLeg_y,rightFoot_x,rightFoot_y,width/2);
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,rightLeg_x,rightLeg_y,width/2);
	glColor3f(r,g,b); //pantsColor
	autoRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,rightLeg_x-dis_x/4,rightLeg_y-dis_y/4,width/1.25);
	//leftLeg
	dis_x=lowerBody_x-leftLeg_x;
	dis_y=lowerBody_y-leftLeg_y;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(leftLeg_x,leftLeg_y,leftFoot_x,leftFoot_y,width/2);
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,leftLeg_x,leftLeg_y,width/2);
	glColor3f(r,g,b); //pantsColor
	autoRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,leftLeg_x-dis_x/4,leftLeg_y-dis_y/4,width/1.25);
	//Body
	dis_y=upperBody_y-lowerBody_y;
	glColor3f(0.9,0.7,0.6); //skinColor
	autoRectangle(head_x,head_y,head_x,upperBody_y,width/3);
	autoRectangle(upperBody_x,upperBody_y+dis_y/15,lowerBody_x,lowerBody_y-dis_y/5,width);
	//arm
	float shoulder_x = upperBody_x+width/2.25;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(shoulder_x,upperBody_y,leftArm_x,leftArm_y,width/2.6);
	shoulder_x = upperBody_x-width/2.25;
	arcRectangle(shoulder_x,upperBody_y,rightArm_x,rightArm_y,width/2.6);
	//head
	glColor3f(1,0.8,0.7); //skinColor
	circle(head_x,head_y,width/1.6);
	//lefthand
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(leftArm_x,leftArm_y,leftFisk_x,leftFisk_y,width/2.6);
	circle(leftFisk_x,leftFisk_y,width/2.4);
	//righthand
	arcRectangle(rightArm_x,rightArm_y,rightFisk_x,rightFisk_y,width/2.6);
	circle(rightFisk_x,rightFisk_y,width/2.4);
}

void SidePerson(float head_x,float head_y,float upperBody_x,float upperBody_y,float lowerBody_x,float lowerBody_y,
		float width,float rightArm_x,float rightArm_y,float rightFisk_x,float rightFisk_y,
		float leftArm_x,float leftArm_y,float leftFisk_x,float leftFisk_y,float rightLeg_x,float rightLeg_y,
		float rightFoot_x,float rightFoot_y,float leftLeg_x,float leftLeg_y,float leftFoot_x,float leftFoot_y){
	glColor3f(0.9,0.7,0.6); //skinColor
	glColor3f(0.3,0.8,1); //pantsColor
	//rightLeg
	float dis_x=lowerBody_x-rightLeg_x;
	float dis_y=lowerBody_y-rightLeg_y;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(rightLeg_x,rightLeg_y,rightFoot_x,rightFoot_y,width/2);
	autoRectangle(rightFoot_x,rightFoot_y-dis_y/8,rightFoot_x+width/2,rightFoot_y-dis_y/8,width/4);
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,rightLeg_x,rightLeg_y,width/2);
	glColor3f(0.3,0.8,1); //pantsColor
	autoRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,rightLeg_x-dis_x/4,rightLeg_y-dis_y/4,width/1.25);
	//leftLeg
	dis_x=lowerBody_x-leftLeg_x;
	dis_y=lowerBody_y-leftLeg_y;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(leftLeg_x,leftLeg_y,leftFoot_x,leftFoot_y,width/2);
	autoRectangle(leftFoot_x,leftFoot_y-dis_y/8,leftFoot_x+width/2,leftFoot_y-dis_y/8,width/4);
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,leftLeg_x,leftLeg_y,width/2);
	glColor3f(0.3,0.8,1); //pantsColor
	autoRectangle(lowerBody_x+dis_x/4,lowerBody_y+dis_y/4,leftLeg_x-dis_x/4,leftLeg_y-dis_y/4,width/1.25);
	//leftArm*3
	float shoulder_x = upperBody_x+width/2.25;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(shoulder_x,upperBody_y,leftArm_x,leftArm_y,width/2.6);
	arcRectangle(leftArm_x,leftArm_y,leftFisk_x,leftFisk_y,width/2.6);
	circle(leftFisk_x,leftFisk_y,width/2.4);
	//Body
	dis_y=upperBody_y-lowerBody_y;
	glColor3f(0.9,0.7,0.6); //skinColor
	autoRectangle(head_x,head_y,head_x,upperBody_y,width/3);
	autoRectangle(upperBody_x,upperBody_y+dis_y/15,lowerBody_x,lowerBody_y-dis_y/5,width);
	//head
	glColor3f(1,0.8,0.7); //skinColor
	circle(head_x,head_y,width/1.6);
	//rightArm*3
	shoulder_x = upperBody_x-width/2.25;
	glColor3f(0.9,0.7,0.6); //skinColor
	arcRectangle(shoulder_x,upperBody_y,rightArm_x,rightArm_y,width/2.6);
	arcRectangle(rightArm_x,rightArm_y,rightFisk_x,rightFisk_y,width/2.6);
	circle(rightFisk_x,rightFisk_y,width/2.4);
}

void background(double y){
	glColor3f(0,0.5,1);
	glBegin(GL_POLYGON);			
	glVertex3f(-1,1,0);
	glVertex3f(-1,-1,0);
	glVertex3f(1,-1,0);
	glVertex3f(1,1,0);
	glEnd();

	glColor3f(0,0.4,0.6);
	glBegin(GL_POLYGON);			
	glVertex3f(-1,1.1*y,0);
	glVertex3f(-1,-1,0);
	glVertex3f(1,-1,0);
	glVertex3f(1,1.1*y,0);
	glEnd();

	glColor3f(0.9,0.8,0.5);
	glBegin(GL_POLYGON);			
	glVertex3f(-1,y,0);
	glVertex3f(-1,-1,0);
	glVertex3f(1,-1,0);
	glVertex3f(1,y,0);
	glEnd();
}
void net(double x1,double upper_y1,double lower_y1,double x2,double upper_y2,double lower_y2){
	double width=x2-x1;
	double height=upper_y1-lower_y1;
	double height2=upper_y2-lower_y2;
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);			
	glVertex3f(x1-0.05*width,upper_y1,0);
	glVertex3f(x1,upper_y1,0);
	glVertex3f(x1,lower_y1,0);
	glVertex3f(x1-0.05*width,lower_y1,0);
	glEnd();

	glBegin(GL_POLYGON);			
	glVertex3f(x2-0.05*width,upper_y2,0);
	glVertex3f(x2,upper_y2,0);
	glVertex3f(x2,lower_y2,0);
	glVertex3f(x2-0.05*width,lower_y2,0);
	glEnd();

	glBegin(GL_POLYGON);			
	glVertex3f(x1,upper_y1,0);
	glVertex3f(x1,upper_y1-0.05*height,0);
	glVertex3f(x2,upper_y2-0.05*height,0);
	glVertex3f(x2,upper_y2,0);
	glEnd();

	glBegin(GL_POLYGON);			
	glVertex3f(x1,upper_y1-0.45*height,0);
	glVertex3f(x1,upper_y1-0.5*height,0);
	glVertex3f(x2,upper_y2-0.5*height2,0);
	glVertex3f(x2,upper_y2-0.45*height2,0);
	glEnd();
	
	int i=0	, nx;

	nx=4;
	for(i=0;i<nx;i++){
		glBegin(GL_POLYGON);			
		glVertex3f(x1,upper_y1-i*height/nx/2,0);
		glVertex3f(x1,upper_y1-i*height/nx/2-0.01*height,0);
		glVertex3f(x2,upper_y2-i*height2/nx/2-0.01*height2,0);
		glVertex3f(x2,upper_y2-i*height2/nx/2,0);
		glEnd();
	}
	nx=10;
	for(i=0;i<nx;i++){
		glBegin(GL_POLYGON);			
		glVertex3f(x1+i*width/nx-0.01*width,upper_y1+(upper_y2-upper_y1)*i/nx,0);
		glVertex3f(x1+i*width/nx-0.01*width,upper_y1-height/2+(upper_y2+lower_y2-upper_y1-lower_y1)/2*i/nx,0);
		glVertex3f(x1+i*width/nx,upper_y1-height/2+(upper_y2+lower_y2-upper_y1-lower_y1)/2*i/nx,0);
		glVertex3f(x1+i*width/nx,upper_y1+(upper_y2-upper_y1)*i/nx,0);
		glEnd();
	}
}
void timeShift(double t,double *start,double *end){
	*start=*end;
	*end+=t;
}
void frame1(double t,double start,double end){
	double duration=end-start;
	const double omega = -t*-72.0;
	if(t>=start&&t<end){
		background(0.8);
		if(t<start+duration/3){
			SidePerson(-0.5,0.42,-0.45,0.2,-0.45,-0.2,
			0.3,-0.75,0.2,-0.7,0.6,0,0,-0.1,0.2+(t-start-duration/3)/5,
			-0.55,-0.5,-0.58,-0.9,-0.35,-0.5,-0.38,-0.9);
		}else{
			float change=fabs(t-start-duration*2/3)-duration/3;
			SidePerson(-0.5,0.42,-0.45,0.2,-0.45,-0.2,
			0.3,-0.75-change/9,0.2,-0.7-change/6,0.6,0,0,-0.1,0.2,
			-0.55,-0.5,-0.58,-0.9,-0.35,-0.5,-0.38,-0.9);
		}
		if(t<start+duration*2/3){
			ball(-0.1,0.6+(t-start-duration*2/3)/5,0.2);
		}else{
			ball(-0.1+(t-start-duration*2/3)/3,0.6+(t-start-duration*2/3)/5,0.2);
		}
	}
}
void frame8(double t,double start,double end){
	double duration=end-start;
	const double omega = -t*360.0;
	if(t>=start&&t<end){
		background(0.2);
		glPushMatrix();
		glTranslatef((t-start)/25,(t-start)/25,0);
		if(t<start+duration/3){
			SidePerson(-0.15,0.4,-0.1,0.15,-0.1,-0.2,
			0.35,-0.4,0.2,-0.35,0.6,0.2,0,0.1,-0.2,
			-0.25,-0.5,-0.5,-0.6,0,-0.6,-0.25,-0.6);
		}else{
			SidePerson(-0.15,0.4,-0.1,0.15,-0.1,-0.2,
			0.35,-0.4+(t-start-duration/3)/12,0.2-(t-start-duration/3)/12,-0.35+(t-start-duration/3)/6,0.6-(t-start-duration/3)/6,0.2,0,0.1,-0.2,
			-0.25,-0.5,-0.5,-0.6,0,-0.6,-0.25,-0.6);
		}	
		glTranslatef((t-start)/25,(t-start)/25,0);
		glPopMatrix();
		net(-1.2,-2,1.3,1.2,-1,1.5);
		ball(-0.02+fabs(t-start-duration/2)/7,0.75-pow(((t-start)/7),2),0.22);
	}
}
void frame2(double t,double start,double end){
	double duration=end-start;
	const double omega = -72*t;
	if(t>=start&&t<end){
		background(0.4);
		net(-0.15,0.2,-0.6,0.15,-0.2,-1);
		littlePeople((t-start)/12-0.7,-0.5,0.1);
		littlePeople((t-start)/7+0.2,-0.5,0.1);

		glPushMatrix();	
		glTranslatef((t-start-duration/2)/3,0.2-0.5*pow(((t-start-duration/2)/3),2),0);
		glRotated(10*omega,0,0,1);
		ball(0,0,0.1);
		glRotated(10*omega,0,0,-1);
		glTranslatef(-(t-start-duration/2)/3,-(0.2-0.5*pow(((t-start-duration/2)/3),2)),0);
		glPopMatrix();
	
		glutSwapBuffers();
	}
}
void frame4(double t,double start,double end){
	double duration=end-start;
	const double omega = -72*t;
	if(t>=start&&t<end){
		background(0.4);
		net(-0.15,0.2,-0.6,0.15,-0.2,-1);
		littlePeople(-0.2-(t-start)/7,-0.5,0.1);
		littlePeople(0.9-(t-start)/12,-0.5,0.1);

		glPushMatrix();	
		glTranslatef(-(t-start-duration/2)/3,0.2-0.5*pow(((t-start-duration/2)/3),2),0);
		glRotated(10*omega,0,0,1);
		ball(0,0,0.1);
		glRotated(10*omega,0,0,-1);
		glTranslatef((t-start-duration/2)/3,-(0.2-0.5*pow(((t-start-duration/2)/3),2)),0);
		glPopMatrix();
	
		glutSwapBuffers();
	}
}
void frame6(double t,double start,double end){
	double duration=end-start;
	const double omega = -72*t;
	if(t>=start&&t<end){
		background(0.4);
		double breakpoint=start+0.7*duration;
		net(-0.15,0.2,-0.6,0.15,-0.2,-1);
		littlePeople((t-start)/12-0.7,-0.5,0.1);
		if(t<breakpoint){
			littlePeople((t-breakpoint)/9+0.8,-(t-breakpoint)/24-0.8,0.1);
		}else{
			littlePeople(0.8,-0.8,0.1);
			shock(0.5,0.3,0.2);
		}

		glPushMatrix();	
		glTranslatef(-0.2+(t-start-duration/2)/3,0.2-0.5*pow(((t-start-duration/2)/3),2),0);
		glRotated(10*omega,0,0,1);
		ball(0,0,0.1);
		glRotated(10*omega,0,0,-1);
		glTranslatef(0.2-(t-start-duration/2)/3,-(0.2-0.5*pow(((t-start-duration/2)/3),2)),0);
		glPopMatrix();
	
		glutSwapBuffers();
	}
}
void frame7(double t,double start,double end){
	double duration=end-start;
	const double omega = -72*t;
	if(t>=start&&t<end){
		glClear(GL_COLOR_BUFFER_BIT);
		background(1);
		double breakpoint=start+0.6*duration;
		glPushMatrix();	
		glTranslatef(0.5-(t-start)/5,0.3-(t-start)/5,0);
		FrontPerson(0.1,0.2,0.15,0.15,0.45,0,0.3,
			-0.1,0,-0.25,-0.35,0.3,0,0.1,-0.35,
			0.4,-0.25,0.6,-0.1,0.7,0.1,0.8,0.45,0.3,0.8,1);
		glTranslatef((t-start)/5-0.5,(t-start)/5-0.3,0);
		glPopMatrix();
		glPushMatrix();	
		glTranslatef(-0.3-fabs(t-breakpoint)/5,-0.5+fabs(t-breakpoint)*0.8/duration,0);
		glRotated(10*omega,0,0,1);

		ball(0,0,0.2);

		glRotated(10*omega,0,0,-1);
		glTranslatef(-(-0.2-fabs(t-breakpoint)/5),-(-0.3+fabs(t-breakpoint)*0.8/duration),0);
		glPopMatrix();

		glutSwapBuffers();
	}

}
void frame9(double t,double start,double end){
	double duration=end-start;
	const double omega = -72*t;
	if(t>=start&&t<end){
		glClear(GL_COLOR_BUFFER_BIT);
		background(1);
		
		double breakpoint=start+0.6*duration;
		glPushMatrix();	
		glTranslatef(-0.8+(t-start)*1.4/duration,-0.2+fabs(t-breakpoint)*0.8/duration,0);
		glRotated(10*omega,0,0,1);

		ball(0,0,0.25);

		glRotated(10*omega,0,0,-1);
		glTranslatef(-(-0.8+(t-start)*1.4/duration),-(-0.2+fabs(t-breakpoint)*0.8/duration),0);
		glPopMatrix();

		glColor3f(0.9,0.8,0.5);
	 	glBegin(GL_POLYGON);
			glVertex3f(-1,-1,0);
			glVertex3f(1,-1,0);
			glVertex3f(1,-0.42,0);
			glVertex3f(-1,-0.42,0);
		glEnd();

		glutSwapBuffers();
	}
}
void frame3(double t,double start,double end){
	double duration=end-start;
	const double omega = -t*-72.0;
	if(t>start&&t<end){
		background(0.7);
		double breakpoint=start+0.6*duration;

		FrontPerson(-0.08,0.3,-0.1,0.1,-0.05,-0.3,0.3,
		-0.3,0,-0.5+fabs(t-breakpoint)/18,-0.2-fabs(t-breakpoint)/18,-0.2,-0.25,-0.45+fabs(t-breakpoint)/18,-0.2-fabs(t-breakpoint)/18,
		-0.3,-0.5,-0.25,-0.9,-0.1,-0.5,0,-0.9,0,1,0);

		glTranslatef(-0.6-fabs(t-breakpoint)/5,fabs(t-breakpoint)*0.8/duration,0);
		glRotated(10*omega,0,0,1);

		ball(0,0,0.2);

		glRotated(10*omega,0,0,-1);
		glTranslatef(-(-0.6-fabs(t-breakpoint)/5),-(fabs(t-breakpoint)*0.8/duration),0);

	}
}
void frame5(double t,double start,double end){
	double duration=end-start;
	const double omega = -t*-72.0;
	if(t>start&&t<end){
		background(0.7);
		double breakpoint=start+0.6*duration;
		FrontPerson(-0.22,0.3,-0.2,0.1,-0.25,-0.3,0.3,
		-0.1,-0.25,0.05-fabs(t-breakpoint)/18,-0.2-fabs(t-breakpoint)/18,0,0,0.1-fabs(t-breakpoint)/18,-0.2-fabs(t-breakpoint)/18,
		-0.2,-0.5,-0.3,-0.9,0,-0.5,-0.05,-0.9,0.3,0.8,1);
		glTranslatef(0.2+fabs(t-breakpoint)/5,fabs(t-breakpoint)*0.8/duration,0);
		glRotated(10*omega,0,0,1);

		ball(0,0,0.2);

		glRotated(10*omega,0,0,-1);
		glTranslatef(-(0.2+fabs(t-breakpoint)/5),-(fabs(t-breakpoint)*0.8/duration),0);

	}
}
void smile(double t,double start,double end){
	double duration=end-start;
	const double omega = -t*-72.0;
	if(t>start&&t<end){
		glColor3f(0,0,0);
		autoRectangle(0,1,0,-1,2);
		glColor3f(0.9,0.7,0.6); //skinColor
		circle(-0.8,0.8,1.5);
		glColor3f(1,1,1);
	 	glBegin(GL_POLYGON);
			glVertex3f(0.1,0,0);
			glVertex3f(-0.2,-0.2,0);
			glVertex3f(-0.5-(t-start)/5,0.2+(t-start)/7,0);
		glEnd();
	}
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
void cover(double t){
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

	//font
	glColor3f(cos(t),cos(t),0);
	output(-0.5,0,messageptr1);
	glColor3f(0,cos(t),cos(t));
	output(0,0,messageptr2);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
	double start=10,end=10;
	cover(t);
	timeShift(5,&start,&end);
	frame1(t,start,end);
	timeShift(5,&start,&end);
	frame2(t,start,end);
	timeShift(6,&start,&end);
	frame3(t,start,end);
	timeShift(5,&start,&end);
	frame4(t,start,end);
	timeShift(6,&start,&end);
	frame5(t,start,end);
	timeShift(5,&start,&end);
	frame6(t,start,end);
	timeShift(6,&start,&end);
	frame7(t,start,end);
	timeShift(5,&start,&end);
	smile(t,start,end);
	timeShift(6,&start,&end);
	frame8(t,start,end);
	timeShift(8,&start,&end);
	frame9(t,start,end);

	glFlush();
}
static void idle(void){
	glutPostRedisplay();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
	glutInitWindowPosition(100,0);
	glutInitWindowSize(800,800);
	glutCreateWindow("Computer Graphics\n"); 
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
