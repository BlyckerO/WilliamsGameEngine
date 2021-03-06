  
#include "GameScene.h" 


#include "Background.h"
const float SPEED = 0.25f;



Background::Background()
{
	sprite_.setTexture(GAME.getTexture("Resources/background2.png"));
	sprite_.setPosition(0,0);
	assignTag("Background1"); 

	sprite2_.setTexture(GAME.getTexture("Resources/background2.png"));
	sprite2_.setPosition(0, -sprite_.getGlobalBounds().height);
	assignTag("Background2");
	
}

void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_); 

	GAME.getRenderWindow().draw(sprite2_);

}

void Background::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();  	 
	sf::Vector2f pos2 = sprite2_.getPosition();
	float fudge = 17;

	if (pos.y >= sprite_.getGlobalBounds().height * 1)
	{
		sprite_.setPosition(0, pos2.y -sprite_.getGlobalBounds().height + fudge);
		//sprite_.setPosition(0,- sprite_.getGlobalBounds().height);
	}  
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x, pos.y + SPEED * msElapsed));
	}
	if (pos2.y >= sprite2_.getGlobalBounds().height)
	{
		sprite2_.setPosition(0,pos.y -sprite2_.getGlobalBounds().height + fudge); 
		//sprite2_.setPosition(0, - sprite2_.getGlobalBounds().height * 1);
	}
	else
	{
		sprite2_.setPosition(sf::Vector2f(pos2.x, pos2.y + SPEED * msElapsed));
	}
}
