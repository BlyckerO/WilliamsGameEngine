#include "GameScene.h" 
#include "Ship.h"
#include "MEteorSpawner.h"
GameScene::GameScene() 
{
	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship); 

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>(); 
	addGameObject(meteorSpawner);
}
