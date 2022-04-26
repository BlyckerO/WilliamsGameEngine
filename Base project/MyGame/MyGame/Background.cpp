/*#include "Meteor.h"  
#include "GameScene.h" 
#include "Explosion.h" 
#include "Score.h"
const float SPEED = 0.5f;

Background::Background(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/background.png"));
	sprite_.setPosition(pos);
	assignTag("background");
	
}

void Background::draw()
{
	GAME.getRenderWindow().draw(sprite_);

}

void Backgound::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();

	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
		makeDead();

	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}
sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}
*/