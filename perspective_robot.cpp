#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

int Width, Height;
float angle = 0.0f;
float angle2 = 0.0f;
void Init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-35.0, 35.0, -35.0, 35.0, -35.0, 35.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




void mytimer(int value)
{
	angle = angle + 0.3f;     
	angle2 = angle2 + 0.3f;   // increase our rotation angle counter
	if (angle >= 100.0f)               // if we've gone in a circle, reset counter
		angle = -20.0f;
	if (angle2 >= 100)
		angle2 = -50;
	glutPostRedisplay();
}




////// Robot variables
float legAngle[2] = { 0.0f, 0.0f };		// each leg's current angle
float armAngle[2] = { 0.0f, 0.0f };
float lowlegAngle[2] = { -7.0f, -7.0f };
// DrawCube
// desc: since each component of the robot is made up of
//       cubes, we will use a single function that will
//		 draw a cube at a specified location.
void DrawCube(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glTranslatef(xPos, yPos, zPos);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);	// top face
	glVertex3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);	// front face
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f); // right face
	glVertex3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, 0.0f, -1.0f);

	glVertex3f(-1.0f, 0.0f, 0.0f);	// left face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f);	// bottom face
	glVertex3f(0.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glVertex3f(0.0f, 0.0f, 0.0f); // back face
	glVertex3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(0.0f, -1.0f, -1.0f);

	glEnd();
	glPopMatrix();
}

// DrawArm
// desc: draws one arm
void DrawArm(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.0f, 0.0f);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawArm2
// desc: draws one arm
void DrawArm2(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);	// red
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.0f, 1.0f);		// arm is a 1x4x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawHead
// desc: draws the robot head
void DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.7f, 0.6f);	// white
	glTranslatef(xPos, yPos, zPos);
	glScalef(2.0f, 2.0f, 2.0f);		// head is a 2x2x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawTorso
// desc: draws the robot torso
void DrawTorso(float xPos, float yPos, float zPos,float r,float g, float b)
{
	glPushMatrix();
	glColor3f(r,g,b);	// blue
	glTranslatef(xPos, yPos, zPos);
	glScalef(3.0f, 5.0f, 2.0f);		// torso is a 3x5x2 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawLeg
// desc: draws a single leg
void DrawLeg(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// DrawLeg
// desc: draws a single leg
void DrawLeg2(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.7f, 0.6f, 1.0f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 2.5f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}
// Drawfoot
// desc: draws a single foot
void Drawfoot(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 0.0f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 1.0f, 2.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}

// Drawhand
// desc: draws a single foot
void Drawhand(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	glColor3f(1.0f, 0.7f, 0.7f);	// yellow
	glTranslatef(xPos, yPos, zPos);
	glScalef(1.0f, 1.0f, 1.0f);		// leg is a 1x5x1 cube
	DrawCube(0.0f, 0.0f, 0.0f);
	glPopMatrix();
}


// DrawRobot
// desc: draws the robot located at (xpos,ypos,zpos)
void DrawRobot(float xPos, float yPos, float zPos, float r, float g, float b)
{
	static bool leg1 = true;		// robot's leg states
	static bool leg2 = false;		// true = forward, false = back

	static bool leg3 = true;		// robot's leg states
	static bool leg4 = false;		// true = forward, false = back

	static bool arm1 = true;
	static bool arm2 = false;

	glPushMatrix();

	glTranslatef(xPos, yPos, zPos);	// draw robot at desired coordinates

// draw components
	DrawHead(1.0f, 2.0f, 0.0f);
	DrawTorso(1.5f, 0.0f, 0.0f,r,g,b);
	glPushMatrix();
	// if leg is moving forward, increase angle, else decrease angle
	if (arm1)
		armAngle[0] = armAngle[0] + 0.3f;
	else
		armAngle[0] = armAngle[0] - 0.3f;

	// once leg has reached its maximum angle in a direction,
	// reverse it
	if (armAngle[0] >= 15.0f)
		arm1 = false;
	if (armAngle[0] <= -15.0f)
		arm1 = true;

	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);
	DrawArm(2.5f, 0.0f, -0.5f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	DrawArm2(2.5f, -0.5f, 3.0f);
	Drawhand(2.5f, -2.5f, 3.0f);
	glPopMatrix();

	glPushMatrix();
	// if leg is moving forward, increase angle, else decrease angle
	if (arm2)
		armAngle[1] = armAngle[1] + 0.3f;
	else
		armAngle[1] = armAngle[1] - 0.3f;

	// once leg has reached its maximum angle in a direction,
	// reverse it
	if (armAngle[1] >= 15.0f)
		arm2 = false;
	if (armAngle[1] <= -15.0f)
		arm2 = true;

	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);
	DrawArm(-1.5f, 0.0f, -0.5f);
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	DrawArm2(-1.5f, -0.5f, 3.0f);
	Drawhand(-1.5f, -2.5f, 3.0f);
	glPopMatrix();


	// we want to rotate the legs relative to the robot's position in the world
	// this is leg 1, the robot's right leg
	glPushMatrix();

	// if leg is moving forward, increase angle, else decrease angle
	if (leg1)
		legAngle[0] = legAngle[0] + 0.3f;
	else
		legAngle[0] = legAngle[0] - 0.3f;



	// once leg has reached its maximum angle in a direction,
	// reverse it
	if (legAngle[0] >= 15.0f)
		leg1 = false;
	if (legAngle[0] <= -15.0f)
		leg1 = true;



	// move the leg away from the torso and rotate it to give "walking" effect
	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngle[0], 1.0f, 0.0f, 0.0f);

	// draw the leg
	DrawLeg(-0.5f, -4.6f, -0.5f);

	glPushMatrix();
	if (leg3)
		lowlegAngle[0] = lowlegAngle[0] + 0.3f;
	else
		lowlegAngle[0] = lowlegAngle[0] - 0.3f;

	if (lowlegAngle[0] >= 7.0f)
		leg3 = false;
	if (lowlegAngle[0] <= -23.0f)
		leg3 = true;
	glTranslatef(-0.5f, -6.9f, -0.5f);
	glRotatef(lowlegAngle[0], 1.0f, 0.0f, 0.0f);
	DrawLeg2(0.0f, -0.0f, 0.0f);
	Drawfoot(0.0f, -2.5f, 0.0f);
	glPopMatrix();



	glPopMatrix();



	// do the same as above with leg 2, the robot's left leg
	glPushMatrix();

	if (leg2)
		legAngle[1] = legAngle[1] + 0.3f;
	else
		legAngle[1] = legAngle[1] - 0.3f;

	if (legAngle[1] >= 15.0f)
		leg2 = false;
	if (legAngle[1] <= -15.0f)
		leg2 = true;

	glTranslatef(0.0f, -0.5f, 0.0f);
	glRotatef(legAngle[1], 1.0f, 0.0f, 0.0f);
	DrawLeg(1.5f, -4.6f, -0.5f);

	glPushMatrix();
	if (leg4)
		lowlegAngle[1] = lowlegAngle[1] + 0.3f;
	else
		lowlegAngle[1] = lowlegAngle[1] - 0.3f;

	if (lowlegAngle[1] >= 7.0f)
		leg4 = false;
	if (lowlegAngle[1] <= -23.0f)
		leg4 = true;
	glTranslatef(1.5f, -6.9f, -0.5f);
	glRotatef(lowlegAngle[1], 1.0f, 0.0f, 0.0f);
	DrawLeg2(0.0f, -0.0f, 0.0f);
	Drawfoot(0.0f, -2.5f, 0.0f);
	glPopMatrix();



	//DrawLeg2(1.5f, -7.5f, -0.5f);
	//Drawfoot(1.5f, -10.0f, -0.5f);
	glPopMatrix();
	glPopMatrix();




}
void drawtile(float a, float b)
{
	glColor3f(0.3, 0.7, 1.0);
	glPushMatrix();
	glTranslatef(0.0, -b, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(a, 0.0, a);
	glVertex3f(a, 0.0, -a);
	glVertex3f(-a, 0.0, -a);
	glVertex3f(-a, 0.0, a);
	glEnd();
	glPopMatrix();
}

void Render()
{
	glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    
    // put current matrix on stack
                   // reset matrix
    //glTranslatef(angle, 0.0f, -30.0f);   // move to (0, 0, -30)      
	glutTimerFunc(10, mytimer, 3);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluPerspective(120, 1.0, 5.0, 500.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
			gluLookAt(0.0, 0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0,0.0);
			DrawRobot(0.0f, 0.0f, 0.0f - angle,0,0,1);
			
			gluLookAt(15.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawRobot(0.0f, 0.0f, 0.0f - angle,1,1,1);

			gluLookAt(15.0, 0.0, -15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			DrawRobot(0.0f, 0.0f, 0.0f - angle,0,1,0);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	//Drawline();
    glFlush();     // bring backbuffer to foreground

}

/*void Render()
{
	glEnable(GL_DEPTH_TEST);            // enable depth testing
	// do rendering here
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);               // clear to black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      // clear screen and depth buffer
	glLoadIdentity();                              // reset modelview matrix


	angle = angle + 0.5f;               // increase our rotation angle counter
	if (angle >= 25.0f)               // if we've gone in a circle, reset counter
		angle = -20.0f;

	glViewport(0, Height / 2, Width / 2, Height / 2); //좌상
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
	DrawRobot(0.0f, 0.0f, -angle);
	glPopMatrix();



	glViewport(0, 0, Width / 2, Height / 2); //좌하
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(0.0, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawRobot(0.0f, 0.0f, 0.0f);
	glPopMatrix();

	glViewport(Width / 2, 0, Width / 2, Height / 2); //우하
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(-1.0, 0.0, 0.0f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawRobot(0.0f, 0.0f, -angle);
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2); //우상
	glPushMatrix();
	glLoadIdentity();
	gluLookAt(-1.0, 1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawRobot(0.0f, 0.0f, -angle);
	glPopMatrix();

	glFlush();
}


*/
void MyReshape(int w, int h) {
    Width = w;
    Height = h;
}



int main(int argc, char** argv) {
    Width = 1000;
    Height = 1000;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2017305053 이규진");
    Init();
    glutDisplayFunc(Render);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}
