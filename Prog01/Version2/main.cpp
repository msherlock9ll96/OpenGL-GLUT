#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/gl.h>
#include <GL/glut.h>
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

// Initial Window Position
const int 	INIT_WIN_X = 100,
			INIT_WIN_Y = 40;		

// Window Size Variables
int g_windowWidth = 1920;
int g_windowHeight = 1080;

// Main Menu Items
const int MAIN_MENU[] = { };

const int NUM_MAIN_ITEMS = sizeof(MAIN_MENU)/sizeof(int);

// Init Check
bool initDone = false;


/*******************************
	Function Implementations
*******************************/

// Handles mouse buttons
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

// Handles keypresses
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

// Code to write to buffers
void myDisplayFunc(void)
{
	// Set background color
	// 114, 137, 218
	glClearColor(44.f/255.f, 47.f/255.f, 51.f/255.f, 1.0f);
	// Clear the buffer to write to
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Use model view for writing
	glMatrixMode(GL_MODELVIEW);

	// This makes us start at the lower corner of the screen
	glLoadIdentity();

	/************************
		Drawing Code - with some funky examples
	*************************/
	if (initDone)
	{
		myPortrait1->setScale(0.5f, 0.5f);
		for (int i = 0 ; i < 25 ; i++)
		{
			myPortrait1->draw();
		}
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

// Main loop
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


	// Values for portrait object
	myPortrait1 = new Portrait();
	


	// Application level 
	myInit();

	// Main loop
	glutMainLoop();

	return 0;
}
