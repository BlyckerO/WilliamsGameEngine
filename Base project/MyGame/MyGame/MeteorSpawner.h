#pragma once 


#include "Engine/GameEngine.h" 
#include "Meteor.h"                                                                    
#include "GameScene.h"
class MeteorSpawner : public GameObject
{
public: 
	void update(sf::Time& elapsed); 
private: 
	int timer_ = 0; 
	int SPAWN_DELAY = 2000;
}; 
    
typedef std::shared_ptr<MeteorSpawner> MeteorSpawnerPtr;

