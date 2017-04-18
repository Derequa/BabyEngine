#include <stdlib.h>
#include "Engine.h"
#include <pthread.h>


using namespace std;


/**
    This is the main function. Its starts things and stuff.
    @param argc The number of arguments given
    @param argv The argument vector (where dey is)
    @return This function never returns directly, all control is handed over to glutMainLoop
*/
int main(int argc, char** argv)
{
    baby::Engine::setup(argc, argv);
    
    // For you my dear compiler
    return EXIT_SUCCESS;
}

/*
	Initialize the 3D rendering.
*-/
void initRendering()
{
	// Dark unkown magic to make 3D drawing work
	glEnable(GL_DEPTH_TEST);
}

/*
	This function is called to update object in the game world and acts as our
	main game loop.
	@param value I have no idea.
 *-/
void update(int value)
{
	// Redraw and wait again
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

/*
	Draw the 3D scene
*-/
void drawScene()
{
	glEnable(GL_LIGHTING);
	// Clear information from the last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Switch to the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	// Reset the perspective
	glLoadIdentity();

	glFlush();
	//Send the 3D scene to the window
	glutSwapBuffers();
}

/*
	This is a simple function for drawing text to the window.
	@param x The x co-ordinate for where we should start drawing.
	@param y The y co-ordinate for where we should start drawing.
	@param z The z depth co-ordinate for where we should draw.
	@param string The string to draw.
 *-/
void drawText(float x, float y, float z, char* string)
{
	glRasterPos3f(x, y, z);
	for (char* p = string; *p != '\0'; p++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p);
}

/*
	This function handles interaction with a right click menu.
	@param ID Menu entry ID.
 *-/
void handle_menu(int ID)
{
	switch (ID) {
	case 0:
		// Leave if the Quit entry is clicked
		exit(0);
	case 1:
		// Restart the game
		restartGame();
		break;
	}
}

/*
	Called when the window is resized.
	@param w The new screen width.
	@param h The new screen height.
 *-/
void handleResize(int w, int h)
{
	// Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	// Switch to setting camera perspective
	glMatrixMode(GL_PROJECTION);
	// Set the camera perspective
	glLoadIdentity();
	// Pass in camera angle, width-to-height ratio, the near z clipping coordinate, and the far z clipping coordinate
	gluPerspective(45.0, (double) w /(double) h, 1.0, 200.0);

}

/*
	Called when a key is pressed.
	@param key The key that was pressed.
	@param x The mouse's x coordinate.
	@param y The mouse's y coordinate.
*-/
void handleKeypress(unsigned char key, int x, int y)
{
}

/*
	Called when a key is released.
	@param key The key that was pressed.
	@param x The mouse's x coordinate.
	@param y The mouse's y coordinate.
*-/
void handleKeyRelease(unsigned char key, int x, int y)
{
}

/*
	Called when a special key is pressed.
	@param key The special that was pressed.
	@param x The mouse's x coordinate.
	@param y The mouse's y coordinate.
*-/
void handleSpecialPress(int key, int x, int y)
{
}

/*
	Called whenever a special key is released.
	@param key The key that was released.
	@param x The mouse's x coordinate.
	@param y The mouse's y coordinate.
*-/
void handleSpecialRelease(int key, int x, int y)
{
}

/*
	This initializes lighting magic.
	Its pretty much all stuff from the demo program.
*-/
void initLighting()
{
	// Ambient material property
	float  amb[] = { 0, 0, 0, 1 };
	// Ambient light property
	float  lt_amb[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	// Ambient light property
	float  lt_dif[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	// Light position
	float  lt_pos[] = { 0, .39392, .91914, 0 };
	// Specular light property
	float  lt_spc[] = { 0, 0, 0, 1 };

	// Set default ambient light in scene
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	// Set Light 0 position, ambient, diffuse, specular intensities
	glLightfv(GL_LIGHT0, GL_POSITION, lt_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lt_amb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lt_dif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lt_spc);

	// Enable Light 0 and GL lighting
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	// Flat shading
	glShadeModel(GL_FLAT);
	// Normalize normals
	glEnable(GL_NORMALIZE);

	// Setup background colour
	glClearDepth(1.0);
	glClearColor(0, 0, 0, 0);
}*/

