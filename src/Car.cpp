#include "Car.h"
#include "World.h"
#include "ofMain.h"

Car::Car(Color _color, const Vector2D& initialPosition, float orientation, float _mass, float _maxForce, float _maxSpeed) 
	: color(_color), 
	  position(initialPosition), 
	  direction(Vector2D::newBySizeAngle(1.0f, math::toRadians(orientation))),
	  velocity(),
	  mass(_mass),
	  maxForce(_maxForce),
	  maxSpeed(_maxSpeed)
{
}

const Vector2D& Car::getPosition() const
{
	return position;
}

const Vector2D& Car::getVelocity() const
{
	return velocity;
}

const Vector2D& Car::getDirection() const
{
	return direction;
}

float Car::getMass() const
{
	return mass;
}

float Car::getMaxSpeed() const
{
	return maxSpeed;
}

float Car::getMaxForce() const
{
	return maxForce;
}

void Car::processLogics(const World& world)
{	
	//Modelo super simplificado de fisica do Reynolds, modificado para levar em conta a velocidade
	Vector2D steering_force = truncate(calculateSteering(world), maxForce) * world.getSecs();
	Vector2D acceleration = (steering_force / mass);
    velocity = truncate(velocity + acceleration, maxSpeed);
    position = position + velocity * world.getSecs();

	//Calcula a nova direction
	if (!velocity.isZero()) 
		direction = normalize(velocity);

	//Circula pela tela
	float w = ofGetWidth() / 2.0f;
	float h = ofGetHeight() / 2.0f;
	if (position.x < -(w+20)) position.x = w;
	if (position.x > w+20) position.x = -w;
	if (position.y < -(h+20)) position.y = h;
	if (position.y > h+20) position. y = -h;
}

void Car::draw() const
{
    ofPushMatrix();
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofTranslate(position.x, position.y);
        ofRotateZ(math::toDegrees(direction.angle()));
        ofSetColor(color);
    
        ofDrawBox(0, 0, 0, 40, 20, 0);
        ofSetColor(255, 255, 0);
        ofDrawBox(16, -5, 0, 2, 4, 0);
        ofDrawBox(16,  4, 0, 2, 4, 0);
    ofPopMatrix();
    
}


Car::~Car()
{
}
