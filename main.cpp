#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include "glPlatform.h"
#include "Portrait.hpp"

/****************************
	Function Declaration
*****************************/
void myDisplayFunc(void);
void myInit(void);
void myKeyboardHandler(unsigned char c, int x, int y);
void myMouseHandler(int button, int state, int x, int y);
void myResizeFunc(int width, int height);


/************************
	GLOBAL VARIABLES
*************************/
// Portrait Object
Portrait* myPortrait1;
Portrait* myPortrait2;
Portrait* myPortrait3;
Portrait* myPortrait4;
Portrait* myPortrait5;
Portrait* myPortrait6;

// Initial Window Position
const int 	INIT_WIN_X = 100,
			INIT_WIN_Y = 40;		

// Window Size Variables
int g_windowWidth = 1600;
int g_windowHeight = 1600;

// Main Menu Items
const int MAIN_MENU[] = { };

const int NUM_MAIN_ITEMS = sizeof(MAIN_MENU)/sizeof(int);

// Init Check
bool initDone = false;


/*******************************
	Function Implementations
*******************************/

void myMouseHandler(int button, int state, int x, int y) 
{
	switch(button) 
	{
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN) 
			{
				exit(0);
			}
			else if (state == GLUT_UP)
			{
				exit(0);
			}
			break;

		default:
			break;
	}
}

void myKeyboardHandler(unsigned char c, int x, int y) 
{
	switch (c)
	{	
		// ASCII code for esc
		case 27:
			exit(0);
			break;

		default:
			break;
	}
}

void myDisplayFunc(void)
{
	// Set background color
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	// Clear the buffer to write to
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use model view for writing
	glMatrixMode(GL_MODELVIEW);

	// This makes us start at the lower corner of the screen
	glLoadIdentity();

	/************************
		Drawing Code
	*************************/
	if (initDone)
	{

		myPortrait1->draw();
		myPortrait2->draw();
		myPortrait3->draw();
		myPortrait4->draw();
		myPortrait5->draw();
		myPortrait6->draw();
	}


	// Bring our newly drawn buffer to the front
	glutSwapBuffers();
}

// Handles resizing window and adjusting scale
void myResizeFunc(int width, int height) 
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	// Adjusting scale for non-square display
	float widthScale = 1.f;
	if (width != height)
	{
		std::cout << "adjusting dimentions to\nwidth: " << width << "\nheight: " << height << "\n";
		widthScale = float(width) / float(height);
	}

	glOrtho(-10.f*widthScale, 10.f*widthScale, -10.f, 10.f, -1.f, 1.f);
	glutPostRedisplay();
}

/************************
	Application Setup
*************************/
void myInit(void) 
{
	// Create Menus
	int myMenu, mySubmenu;



	initDone = true;
	myDisplayFunc();
}


int main(int argc, char** argv) 
{

	// Initializing glut and creating a window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);


	glutInitWindowSize(g_windowWidth, g_windowHeight);
	glutInitWindowPosition(INIT_WIN_X, INIT_WIN_Y);
	glutCreateWindow("Portrait Window");

	// callback functions
	glutDisplayFunc(myDisplayFunc);
	glutMouseFunc(myMouseHandler);
	glutKeyboardFunc(myKeyboardHandler);
	glutReshapeFunc(myResizeFunc);


	// Values for portrait objects
	float xy[2] = {0.f,0.f};
	myPortrait1 = new Portrait(xy);
	xy[0] = 5.f;
	xy[1] = 5.f;
	myPortrait2 = new Portrait(xy);
	xy[0] = -5.f;
	xy[1] = 5.f;
	myPortrait3 = new Portrait(xy);
	xy[0] = -5.f;
	xy[1] = -5.f;
	myPortrait4 = new Portrait(xy);
	xy[0] = 5.f;
	xy[1] = -5.f;
	myPortrait5 = new Portrait(xy);
	xy[0] = 0.f;
	xy[1] = -6.f;
	myPortrait6 = new Portrait(xy);
	


	// Application level 
	myInit();

	// Main loop
	glutMainLoop();

	return 0;
}
