#include "../headers/entity.hpp"

/* Base Class */
void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

/* Derived Classes */

NPC::NPC(Type type): mType(type)
{

}

MOB::MOB(Type type): mType(type)
{

}

Player::Player(Type type): mType(type)
{
	
}