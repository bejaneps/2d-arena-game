#include "../headers/main_header.hpp"

Game::Game(std::pair<short, short> size)
:	mWindow(sf::VideoMode(size.first, size.second), "Arena Game", sf::Style::Default), 
	mTimePerFrame(sf::seconds(1.f / 60.f)), mPlayerSpeed(200.f)
{
	res.load(Type::Player, "../../../Assets/Players/Viking Sample.png");
	res.load(Type::NPC, "../../../Assets/Players/NPC/NPC BLUE.png");

	mPlayer.setTexture(res.get(Type::Player));
	mPlayer.setPosition(200.f, 200.f);

	mWindow.setVerticalSyncEnabled(true);
	mWindow.setFramerateLimit(60);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

void Game::processEvents()
{
	sf::Event event;
	while(mWindow.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
			
			default:
				break;
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);

	if (mIsMovingUp)
		movement.y -= mPlayerSpeed;
	if (mIsMovingDown)
		movement.y += mPlayerSpeed;
	if (mIsMovingLeft)
		movement.x -= mPlayerSpeed;
	if (mIsMovingRight)
		movement.x += mPlayerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear(sf::Color(40, 105, 195));		// default water color
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while(timeSinceLastUpdate > mTimePerFrame)
		{
			timeSinceLastUpdate -= mTimePerFrame;
			processEvents();
			update(mTimePerFrame);
		}
		render();
	}
}

std::pair<short, short> Game::screenSize()
{
	Screen *s = DefaultScreenOfDisplay(XOpenDisplay(NULL));

	return std::make_pair(std::move(s->width), std::move(s->height));
}