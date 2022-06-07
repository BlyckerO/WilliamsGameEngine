#include "MeteorSpawner.h" 
//Numver of milliseconds between meteor spawns 


void MeteorSpawner::update(sf::Time& elapsed)
{
	//determin how much time has passed and adjust out timer 
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;

	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	int incscore = 10;
	
	if (scene.getScore() % 10 == 0 && SPAWN_DELAY != 1500)
	{
		

		SPAWN_DELAY = SPAWN_DELAY - 10;
	}

	if (timer_ <= 0)
	{
		int randPos;
		for (int i = 0; i < 3; i++) {
			randPos = rand() % 4 + 1;

			timer_ = SPAWN_DELAY;
			sf::Vector2u size = GAME.getRenderWindow().getSize();

			float meteorY = (float)(size.y - 600);

			float meteorX = (randPos * 200) - 100;

			MeteorPtr meteor = std::make_shared<Meteor>(sf::Vector2f(meteorX, meteorY));
			GAME.getCurrentScene().addGameObject(meteor);
		}
	}
}