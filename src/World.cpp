#include "World.h"
#include "MathUtil.h"
#include "ofMain.h"

World::World(Car* _current, const vector<Car*>& _cars, const Vector2D& _mousePos, bool _clicked, const Vector2D& _clickPos)
	:  current(_current), cars(_cars), mousePos(_mousePos), clicked(_clicked), clickPos(_clickPos)
{	
}

float World::getSecs() const
{
    return static_cast<float>(ofGetLastFrameTime());
}

Vector2D World::getMousePos() const
{
	return mousePos;
}

bool World::isClicked() const
{
	return clicked;
}

Vector2D World::getClickPos() const
{
	return clickPos;
}

bool World::isKeyPressed(int key) const
{	
	return ofGetKeyPressed(key);
}
const vector<Car const*> World::getNeighbors(int radius) const
{
		vector<Car const*> others;
		for (unsigned i = 0; i < cars.size(); i++) 
			if  (current != cars[i] &&
				(radius <= 0 || distanceSqr(current->getPosition(), cars[i]->getPosition()) <= radius*radius))
					others.push_back(cars[i]);

		return others;
}
