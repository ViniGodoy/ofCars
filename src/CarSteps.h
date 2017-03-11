#ifndef __CARSTEPS_H__
#define __CARSTEPS_H__

#include <vector>

#include "ofMain.h"
#include "gamesteps.h"
#include "Car.h"

using std::vector;

class CarSteps : public GameSteps
{
private:
	vector<Car*> cars;
	Vector2D mouseClick;
	Vector2D mousePos;
    Vector2D mouseScreenClick;

	bool clicked;
	bool finished;
public:
	CarSteps();	
    virtual void setup();
    
    virtual void update();
    virtual void draw() const;

    virtual bool ended();

    virtual void teardown();

	virtual ~CarSteps();
};

#endif //__CARSTEPS_H__
