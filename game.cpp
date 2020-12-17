//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#include <fstream>
#include "board.cpp"
using namespace std;

board *b = new board();
int temp = 0;
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void GameDisplay() {
	glClearColor(0, 0, 0.0, 0);
	glClear (GL_COLOR_BUFFER_BIT);
	
	if (b->getState() == 0)
		b->displayMenu();
	else if (b->getState() == -1)
		b->displayGameTypeMenu();
	else if (b->getState() == 1) {
		b->display();
		if (!b->isTimeTrial())
			if (b->getTime() > 0)
				DrawString(30,560,to_string(b->getTime()),colors[WHITE]);
	}
	else
		b->displayInstructions();
	
	glutPostRedisplay();
	glutSwapBuffers(); // do not modify this line..

}

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {

	}
	else if (key == GLUT_KEY_RIGHT) {

	}
	else if (key == GLUT_KEY_UP) {

	}
	else if (key == GLUT_KEY_DOWN) {

	}

	glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27) {
		exit(1);
	}

	if (key == 'p' || key == 'P') {
		if (b->getState() == 1)
			b->pauseGame();
	}

	if (key == 's' || key == 'S') {
		if (b->getState() == 1)
			b->saveGame();
	}

	glutPostRedisplay();
}

void Timer(int m) {
	if (b->isPaused() == false  && b->getState() == 1)
		b->setTime(b->getTime() - 1);

	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y) {
	if ((b->getTime() > 0 && b->targetReached() == false && b->isPaused() == false) || (!b->isPaused() && b->isTimeTrial())) {
		if (abs(b->getMouseX() - x) > abs(b->getMouseY() - y)) {
			if (b->getMouseX() - x < 0)
				b->swapShapes(3);
			else
				b->swapShapes(1);
		}
		else {
			if (b->getMouseY() - y < 0)
				b->swapShapes(4);
			else
				b->swapShapes(2);
		}
	}
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) {
		temp = !temp;
		if (temp == 1) {
			if (b->getState() == 1) {
				b->setMouseX(x); b->setMouseY(y);
			}
			else if (b->getState() == 2) {
				b->setMouseX(x); b->setMouseY(y);
				b->goBack();
			}
			else {
				b->setMouseX(x); b->setMouseY(y);
				if (b->getState() != -1)
					b->setState();
				else
					b->gameMode();
			}
		}

	}
	else if (button == GLUT_RIGHT_BUTTON) {

	}

	glutPostRedisplay();
}

int main(int argc, char*argv[]) {

	int width = 600, height = 600;

	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("Candy Crush (OOP)"); 
	SetCanvasSize(width, height);

	b->initialiseBoard();
	b->setName();

	glutDisplayFunc(GameDisplay);
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutMotionFunc(MousePressedAndMoved);

	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
