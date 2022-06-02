#include "Meteor.h"  
#include "GameScene.h" 
#include "Explosion.h" 
#include "Score.h"
const float SPEED = 0.25f; 
Meteor::Meteor(sf::Vector2f pos)
{
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png")); 
	sprite_.setPosition(pos); 
	assignTag("meteor"); 
	setCollisionCheckEnabled(true);
} 

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_); 

} 

void Meteor::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds(); 
	sf::Vector2f pos = sprite_.getPosition(); 

	
	
		sprite_.setPosition(sf::Vector2f(pos.x, pos.y + SPEED * msElapsed));
	
} 
sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
} 
void Meteor::handleCollision(GameObject& otherGameObject)
{  
	GameScene& scene = (GameScene&)GAME.getCurrentScene();
	if (otherGameObject.hasTag("ship"))
	{
		ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
		scene.addGameObject(explosion);

		scene.decreaseLives();
	}
	if (otherGameObject.hasTag("lazar"))
	{
		otherGameObject.makeDead(); 
		 
		
		ExplosionPtr explosion = std::make_shared<Explosion>(sprite_.getPosition());
		scene.addGameObject(explosion); 

		scene.increaseScore();
	} 
	makeDead();
}