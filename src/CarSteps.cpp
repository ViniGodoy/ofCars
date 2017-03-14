#include "CarSteps.h"
#include <cstdio>

#include "AlunoSetup.h"
#include "World.h"

using namespace std;

CarSteps::CarSteps() : cars(createCars()), clicked(false), finished(false), mouseScreenClick(-5000,0)
{
}

void CarSteps::setup()
{
    ofSetWindowTitle("Steering behaviors - Cars");
	//Cor do fundo
    
    ofBackground(230, 230, 230);
}

void CarSteps::update()
{	
	clicked = ofGetMousePressed();
	mousePos = Vector2D(
		ofGetMouseX() - ofGetWidth() / 2.0f,
		ofGetMouseY() - ofGetHeight() / 2.0f);

	if (clicked) {
        mouseScreenClick.set(ofGetMouseX(), ofGetMouseY());
		mouseClick = mousePos;
    }

	for (unsigned i = 0; i < cars.size(); ++i)
	{
		World world(cars[i], cars, mousePos, clicked, mouseClick);
		cars[i]->processLogics(world);
	}
	clicked = false;
}

void CarSteps::draw() const
{	
    if (mouseScreenClick.x > -5000) {
        ofSetColor(200, 200, 200);
        ofDrawCircle(mouseScreenClick.x, mouseScreenClick.y, 5);
    }
    
    for (unsigned i = 0; i < cars.size(); ++i)
		cars[i]->draw();
}

bool CarSteps::ended()
{
	return finished;
}

void CarSteps::teardown()
{
	for (vector<Car*>::iterator it = cars.begin(); it != cars.end(); ++it)
		delete (*it);
}

CarSteps::~CarSteps(void)
{
}
