
#pragma once
#include "Engine/GameEngine.h" 

class Background : public GameObject
{
public:
	//Creates Meteor 
	Background();

	// Functions overridn from GameObject 
	void draw();
	void update(sf::Time& elapsed);

	
	
private:
	sf::Sprite sprite_; 

	sf::Sprite sprite2_;

};

typedef std::shared_ptr<Background> BackgroundPtr;