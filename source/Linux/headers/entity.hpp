#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Entity
{
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
private:
	sf::Vector2f mVelocity;
};

class NPC: public Entity
{
public:
	enum Type
	{
		Interactive, NonInteractive
	};

public:
	explicit NPC(Type type);

private:
	Type mType;
};

class MOB: public Entity
{
public:
	enum Type
	{
		Skeleton, Bat, Zombie
	};

public:
	explicit MOB(Type type);

private:
	Type mType;
};

class Player: public Entity
{
public:
	enum Type
	{
		Archer, Warrior, Mage, Warlock
	};

public:
	explicit Player(Type type);

private:
	Type mType;
};

#endif