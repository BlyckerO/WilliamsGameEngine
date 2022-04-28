  
#include "GameScene.h" 


#include "Background.h"
const float SPEED = 0.5f;



Background::Background()
{
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(0,0);
	assignTag("Background"); 

	sprite2_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite2_.setPosition(sprite2_.getGlobalBounds().width, 0);
	assignTag("Background");
	
}

void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_);

}

void Background::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x <= sprite_.getGlobalBounds().width * -1)
	{
		
		sprite_.setPosition(sprite_.getGlobalBounds().width, 0);


	} 
	if (pos.x <= sprite2_.getGlobalBounds().width * -1)
	{

		sprite_.setPosition(sprite2_.getGlobalBounds().width, 0);


	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}
