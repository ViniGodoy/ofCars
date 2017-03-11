#ifndef __WORLD_H__
#define __WORLD_H__

#include "Car.h"

#include <vector>

using std::vector;

class World
{
private:		
	Car* current;
	vector<Car*> cars;
	Vector2D mousePos;
	Vector2D clickPos;
	bool clicked;

public:
	World(Car* current, const vector<Car*>& _cars, const Vector2D& _mousePos, bool _clicked, const Vector2D& _clickPos);
	float getSecs() const;
	Vector2D getMousePos() const;
	Vector2D getClickPos() const;

	bool isClicked() const;
	bool isKeyPressed(int key) const;
	
	const vector<Car const*> getNeighbors(int radius = 0) const;
};

#endif //__WORLD_H__
