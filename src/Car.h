#ifndef __CAR_H__
#define __CAR_H__

#include "Vector2D.h"
#include "Color.h"

using math::Vector2D;

class World;

class Car
{
private:	
	Color color;
	Vector2D position;
	Vector2D direction;
	Vector2D velocity;	

	float mass;
	float maxForce;
	float maxSpeed;

public:
	Car(Color _color, 
		const Vector2D& initialPosition, 
		float orientation, 
		float _mass = 1.0f,
		float _maxForce = 350.0f,
		float _maxSpeed = 500.0f);

	const Vector2D& getPosition() const;
	const Vector2D& getVelocity() const;
	const Vector2D& getDirection() const;

	float getMass() const;
	float getMaxSpeed() const;
	float getMaxForce() const;

	virtual Vector2D calculateSteering(const World& world) = 0;
	void draw() const;

	void processLogics(const World& world);
	virtual ~Car();
};

#endif //__CAR_H__
