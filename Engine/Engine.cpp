#include "Engine.h"
#include "GameObject.h"
#include "DebugObject.h"
#include <string>
#include <stdlib.h>
#include <ctime>
#include <GL/freeglut.h>

namespace baby {

    HashMap<long, EngineObject> Engine::objects;
    long Engine::guidCounter = 0;
    float Engine::deltaT = 0;
    std::chrono::time_point<std::chrono::system_clock> Engine::lastTime = std::chrono::system_clock::now();
    
    Engine* Engine::instance = NULL;

    Engine::Engine(){}
    
    Engine::~Engine(){}
    
    void Engine::run(int thing)
    {
        using namespace std::chrono;
        microseconds dif = duration_cast<microseconds>(system_clock::now() - lastTime);
        deltaT = (float)dif.count() / 1000.0f;
        // Redraw and wait again
        for (long i = 0 ; i < Engine::guidCounter ; i++) {
            if (!Engine::objects.containsKey(&i))
                continue;
            EngineObject* o = Engine::objects.get(&i);
            o->update();
        }
        lastTime = std::chrono::system_clock::now();
	glutPostRedisplay();
	glutTimerFunc(25,Engine::run, 0);
    }
    
    void Engine::setup(int argc, char** argv)
    {
        // Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 800);

	// Create a window
	glutCreateWindow("Baby Engine");
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
	// Dark unkown magic to make 3D drawing work
	glEnable(GL_DEPTH_TEST);

	// Set handler functions for drawing, keypress, and window resize
	glutDisplayFunc(Engine::draw);
	//glutKeyboardFunc(handleKeypress);
	//glutKeyboardUpFunc(handleKeyRelease);
	//glutSpecialFunc(handleSpecialPress);
	//glutSpecialUpFunc(handleSpecialRelease);
	//glutReshapeFunc(handleResize);

	// Make the menu
	//glutCreateMenu(handle_menu);
	//glutAddMenuEntry("Quit", 0);
	//glutAddMenuEntry("Restart Game", 1);
	//glutAttachMenu(GLUT_RIGHT_BUTTON);
        DebugObject* o = new DebugObject(Engine::getNewGUID());
        
        for (long i = 0 ; i < Engine::guidCounter ; i++) {
            if (!Engine::objects.containsKey(&i))
                continue;
            EngineObject* o = Engine::objects.get(&i);
            o->setup();
        }
	// Set the update function (main game loop)
	glutTimerFunc(25, Engine::run, 0);

	// Enable backface stuff
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
        lastTime = std::chrono::system_clock::now();
	// Start the glut main loop. glutMainLoop does not return :(
	glutMainLoop();
    }
    
    void Engine::draw()
    {
        glEnable(GL_LIGHTING);
	// Clear information from the last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Switch to the drawing perspective
	glMatrixMode(GL_MODELVIEW);
	// Reset the perspective
	glLoadIdentity();
        
        for (long i = 0 ; i < Engine::guidCounter ; i++) {
            if (!Engine::objects.containsKey(&i))
                continue;
            EngineObject* o = Engine::objects.get(&i);
            if (GameObject* g = dynamic_cast<GameObject*>(o)) {
                glPushMatrix();
                    g->draw();
                glPopMatrix();
            }
        }

	glFlush();
	//Send the 3D scene to the window
	glutSwapBuffers();
    }
    
    void Engine::removeObject(long guid)
    {
        if (!Engine::objects.containsKey(&guid))
            return;
        EngineObject* obj = Engine::objects.remove(&guid);
        delete obj;
    }
    
    long Engine::getNewGUID() { return Engine::guidCounter++; }
    
    EngineObject* Engine::getObject(long guid)
    {
        if (!Engine::objects.containsKey(&guid))
            return NULL;
        return Engine::objects.get(&guid);
    }
    
    void Engine::addObject(EngineObject* object) 
    {
        Engine::objects.put(&object->guid, object);
    }
    
    float Engine::getDeltaT() {return Engine::deltaT;}
}