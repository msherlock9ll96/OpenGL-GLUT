#include <iostream>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "Portrait.hpp"



Portrait::Portrait(float theXy[])
{
	// Setting the center coordinated to the specified location
	xy[0] = theXy[0];
	xy[1] = theXy[1];
}

// Main draw method
void Portrait::draw(void) const
{
	// Push object drawing onto stack
	glPushMatrix();

	// Set any parameters
	glTranslatef(xy[0],xy[1],0.f);
	glScalef(scale[0], scale[1], 1.f);
	glRotatef(rotation, 0.f, 0.f, 1.f);


	// Begin drawing
	drawHead();
	drawHair();
	drawFace();
	drawAccessories();


	glPopMatrix();
}


/*
	Setter Methods
*/

void Portrait::setScale(float xScale, float yScale)
{
	scale[0] = xScale;
	scale[1] = yScale;
}

void Portrait::setRotation(float degrees)
{
	rotation = degrees;
}

void Portrait::setHairColor(float R, float G, float B)
{
	this->hairColor[0] = R/255.f;
	this->hairColor[1] = G/255.f;
	this->hairColor[2] = B/255.f;
}

void Portrait::setSkinColor(float R, float G, float B)
{
	this->skinColor[0] = R/255.f;
	this->skinColor[1] = G/255.f;
	this->skinColor[2] = B/255.f;
}

void Portrait::setEyeColor(float R, float G, float B)
{
	this->eyeColor[0] = R/255.f;
	this->eyeColor[1] = G/255.f;
	this->eyeColor[2] = B/255.f;
}

void Portrait::setGlassesColor(float R, float G, float B)
{
	this->glassesColor[0] = R/255.f;
	this->glassesColor[1] = G/255.f;
	this->glassesColor[2] = B/255.f;
}

void Portrait::drawHead(void) const
{
	// Set Color
	glColor3fv(skinColor);


	// Neck and length of head
	glBegin(GL_POLYGON);
		glVertex2f(-1.f, -3.0f);
		glVertex2f(1.f, -3.0f);
		glVertex2f(1.f, 2.f);
		glVertex2f(-1.f, 2.f);
	glEnd();

	// Facial Structure
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-1.f, -1.5f);
		glVertex2f(-1.8f, -1.f);
		glVertex2f(-1.f, -0.6f);
		glVertex2f(-2.f, 0.f);
		glVertex2f(-1.f, 0.4f);
		glVertex2f(-1.7f, 0.6f);
		glVertex2f(-1.f, 0.85f);
		glVertex2f(-1.85f, 1.f);
		glVertex2f(-1.f, 1.4f);
		glVertex2f(-1.6f, 1.8f);
		glVertex2f(-1.f, 2.f);
	glEnd();

	// Ear
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(1.f, -0.3f);
		glVertex2f(1.35f, 0.f);
		glVertex2f(1.f, 0.4f);
		glVertex2f(1.5f, 0.7f);
		glVertex2f(1.f, 0.8f);
	glEnd();
}

void Portrait::drawHair(void) const
{
	// Set Color
	glColor3fv(hairColor);

	// Top of hair
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-1.85f, 1.f);
		glVertex2f(-1.9f, 2.f);
		glVertex2f(-1.5f, 1.75f);
		glVertex2f(-1.7f, 2.4f);
		glVertex2f(-1.f, 2.f);
		glVertex2f(-1.7f, 2.4f);
		glVertex2f(-0.8f, 2.f);
		glVertex2f(-1.5f, 2.6f);
		glVertex2f(-0.6f, 2.f);
		glVertex2f(-1.f, 2.8f);
		glVertex2f(-0.3f, 2.f);
		glVertex2f(-0.45f, 2.7f);
		glVertex2f(0.2f, 2.f);
		glVertex2f(0.2f, 2.65f);
		glVertex2f(0.6f, 2.f);
		glVertex2f(0.7f, 2.55f);
		glVertex2f(1.3f, 2.f);
	glEnd();

	// Back of hair
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(0.4f, 2.f);
		glVertex2f(1.4f, 2.f);
		glVertex2f(0.4f, 1.3f);
		glVertex2f(1.5f, 1.4f);
		glVertex2f(0.65f, 1.0f);
		glVertex2f(1.45f, 0.8f);
		glVertex2f(1.f, 0.6f);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(1.f, -0.3f);
		glVertex2f(1.3f, 0.f);
		glVertex2f(1.f, -0.8f);
	glEnd();

	// Eyebrows

	glBegin(GL_QUAD_STRIP);
		glVertex2f(0.f, 1.f);
		glVertex2f(0.f, 1.05f);
		glVertex2f(-0.4f, 0.95f);
		glVertex2f(-0.4f, 1.10f);
		glVertex2f(-0.75f, 0.80);
		glVertex2f(-0.80f, 0.95f);
	glEnd();

	glBegin(GL_QUAD_STRIP);
		glVertex2f(-1.65f, 0.95f);
		glVertex2f(-1.65f, 1.1f);
		glVertex2f(-1.35f, 0.95f);
		glVertex2f(-1.25f, 1.10f);
		glVertex2f(-1.15f, 0.95f);
		glVertex2f(-1.10f, 1.05f);

	glEnd();


	// Facial Hair
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(1.f, 0.6f);
		glVertex2f(0.85f, -0.4f);
		glVertex2f(0.45f, -0.2f);
		glVertex2f(0.4f, -1.15f);
		glVertex2f(0.f, -0.5f);
		glVertex2f(-0.3f, -1.4f);
		glVertex2f(-0.5f, -1.f);
		glVertex2f(-0.8f, -1.6f);
		glVertex2f(-1.f, -1.15f);
		glVertex2f(-1.2f, -1.65f);
		glVertex2f(-1.3f, -1.1f);
		glVertex2f(-1.5f, -1.55f);
		glVertex2f(-1.55f, -0.75f);
		glVertex2f(-1.85f, -1.10f);
		glVertex2f(-1.75f, -0.45f);
		glVertex2f(-2.f, -0.15f);
		glVertex2f(-1.9f, 0.05f);

	glEnd();

	// Mustache
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(0.f,-0.5f);
		glVertex2f(-0.25f, -0.25f);
		glVertex2f(-1.f, -0.5f);
		glVertex2f(-1.f, -0.25f);
		glVertex2f(-1.65f, -0.45f);
		glVertex2f(-1.75f, -0.20f);
		glVertex2f(-1.85f, -0.45f);
		glVertex2f(-1.9f, -0.20f);
	glEnd();
}

void Portrait::drawFace(void) const
{
	// Adding eyes
	glPushMatrix();
	glColor3fv(eyeColor);
	glTranslatef(-0.4f, 0.6f, 0.f);
	glScalef(2.f, 1.f, 1.f);
	drawEllipse(0.15f, 0.15f);
	glColor3fv(glassesColor);
	glScalef(0.5f, 1.f, 1.f);
	drawEllipse(0.1f, 0.1f);

	glColor3fv(eyeColor);
	glTranslatef(-1.f, 0.10f, 0.f);
	glScalef(2.f, 1.f, 1.f);
	drawEllipse(0.15f, 0.15f);
	glColor3fv(glassesColor);
	glScalef(0.5f, 1.f, 1.f);
	drawEllipse(0.1f, 0.1f);
	glPopMatrix();

	// Adding mouth
	glColor3fv(eyeColor);
	glBegin(GL_TRIANGLE_STRIP);
		glVertex2f(-1.45f, -0.6f);
		glVertex2f(-1.2f, -0.75f);
		glVertex2f(-1.f, -0.63f);
		glVertex2f(-0.75f, -0.80f);
		glVertex2f(-0.35f, -0.65f);
	glEnd();

	// Adding nose and detailing
	glLineWidth(3.f);
	glColor3fv(glassesColor);
	glBegin(GL_LINES);
		glVertex2f(-1.f, 0.45f);
		glVertex2f(-1.2f, 0.15f);
		glVertex2f(-1.2f, 0.15f);
		glVertex2f(-1.3f, 0.05f);
		glVertex2f(-1.3f, 0.05f);
		glVertex2f(-1.f, -0.15f);
		glVertex2f(-1.f, -0.15f);
		glVertex2f(-0.75f, 0.0f);
		glVertex2f(1.15f, 0.35f);
		glVertex2f(1.2f, 0.25f);
	glEnd();



}

void Portrait::drawAccessories(void) const
{

	// Drawing glasses
	glLineWidth(6.f);
	glColor3fv(glassesColor);
	glBegin(GL_LINES);
		glVertex2f(0.1f, 0.85f);
		glVertex2f(0.9f, 0.75f);
	glEnd();
	glLineWidth(4.f);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.1f, 0.85f);
		glVertex2f(-0.8f, 0.85f);
		glVertex2f(-0.8f, 0.35f);
		glVertex2f(0.1f, 0.35f);
		glVertex2f(0.1f, 0.85f);
	glEnd();
	glLineWidth(6.f);
	glBegin(GL_LINES);
		glVertex2f(-0.8f, 0.85f);
		glVertex2f(-1.f, 0.85f);
	glEnd();
	glLineWidth(4.f);
	glBegin(GL_LINE_STRIP);
		glVertex2f(-1.f, 0.85f);
		glVertex2f(-2.f, 0.9f);
		glVertex2f(-2.0f, 0.4f);
		glVertex2f(-1.f, 0.35f);
		glVertex2f(-1.f, 0.85f);
	glEnd();


	// Drawing Clothes
	glColor3fv(eyeColor);
	glBegin(GL_TRIANGLES);
		glVertex2f(-2.f,-3.f);
		glVertex2f(1.f, -3.f);
		glVertex2f(1.f, -1.f);
		glVertex2f(-2.f, -3.f);
		glVertex2f(-1.f, -2.5f);
		glVertex2f(-1.f, -1.75f);
	glEnd();
	glColor3fv(glassesColor);
	glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -3.f);
		glVertex2f(2.7f, -3.f);
		glVertex2f(1.05f, -1.15f);
		glVertex2f(-2.f,-3.f);
		glVertex2f(-1.f,-1.75f);
		glVertex2f(-2.f, -2.f);
	glEnd();

}

void Portrait::drawEllipse(float x, float y) const
{
	glBegin(GL_POLYGON);
	for (int i = 0 ; i < 180 ; i++)
	{
		float rad = i*3.14159/180.0;
		glVertex2f(cos(rad)*x, sin(rad)*x);
	}
	for (int i = 0 ; i < 180 ; i++)
	{
		float rad = i*3.14159/180.0;
		glVertex2f(cos(rad)*x*-1, sin(rad)*x*-1);
	}
	glEnd();
}

