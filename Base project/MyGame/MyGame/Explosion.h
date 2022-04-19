#pragma once



#include "Engine/GameEngine.h" 

class Explosion : public AnimatedSprite
{
public: 
	//creates explosion 
	Explosion(sf::Vector2f pos); 

	//Functions overrridden from jGameobject 
	void update(sf::Time& elapsed); 

private: 
	void SetUpExplosionAnimation(); 

	sf::Sound boom_;
}; 
typedef std::shared_ptr<Explosion> ExplosionPtr;