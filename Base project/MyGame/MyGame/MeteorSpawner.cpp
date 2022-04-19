#include "MeteorSpawner.h" 
//Numver of milliseconds between meteor spawns 
const int SPAWN_DELAY = 1000; 

void MeteorSpawner::update(sf::Time& elapsed)
{
	//determin how much time has passed and adjust out timer 
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;



	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();  

		float meteorX = (float)(size.x + 100); 

		float meteorY = (float)(rand() % size.y); 

		MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY)); 
		GAME.getCurrentScene().addGameObject(meteor);

	}
}