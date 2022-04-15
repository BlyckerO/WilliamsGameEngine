#pragma once

#include "Engine/GameEngine.h"

class Laser : public GameObject
{
public:
	// Creates laser 
	Laser(sf::Vector2f pos);

	// Functjions overrijdden from game object 
	void draw();
	void update(sf::Time& elapsed);

private:
	sf::Sprite sprite_;

};

typedef std::shared_ptr<Laser> LaserPtr;
