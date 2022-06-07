#include "Ship.h"  
#include "Laser.h"

const float SPEED = 0.4f;  
const int FIRE_DELAY = 200;

Ship::Ship()
{
	sprite_.setTexture(GAME.getTexture("Resources/ship.png")); 
	sprite_.setPosition(sf::Vector2f(400, 400)); 
	assignTag("ship");
} 
void Ship::draw()
{
	GAME.getRenderWindow().draw(sprite_);
} 

void Ship::update(sf::Time& elapsed)
	{
		sf::Vector2f pos = sprite_.getPosition(); 
		float x = pos.x; 
		float y = pos.y; 
		
		int msElapsed = elapsed.asMilliseconds(); 

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sprite_.getPosition().x >=0) x -= SPEED * msElapsed;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sprite_.getPosition().x < GAME.getRenderWindow().getSize().x - 81) x += SPEED * msElapsed;
		
		sprite_.setPosition(sf::Vector2f(x, y)); 

		if (fireTimer_ > 0)
		{
			fireTimer_ -= msElapsed; 
			
		} 

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireTimer_ <= 0)
		{
			fireTimer_ = FIRE_DELAY; 
			sf::FloatRect bounds = sprite_.getGlobalBounds(); 

			float laserX = x + bounds.width; 
			float laserY = y + (bounds.height / 2.0f); 

			LaserPtr laser = std::make_shared<Laser>(sf::Vector2f(laserX, laserY)); 
			GAME.getCurrentScene().addGameObject(laser);
		} 
		
		
	}  
sf::FloatRect Ship::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

