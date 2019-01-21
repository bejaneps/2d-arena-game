#ifndef MAIN_HEADER_HPP
#define MAIN_HEADER_HPP

#include "res_holder.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <exception>
#include <utility>
#include <thread>
#include <cstdlib>
#include <X11/Xlib.h>

class Game
{
public:
							Game(std::pair<short, short> size);
	void 					run();

private:
	sf::RenderWindow 		mWindow;
	sf::Sprite				mPlayer;
	bool 					mIsMovingUp, mIsMovingDown, mIsMovingLeft, mIsMovingRight;
	const sf::Time 			mTimePerFrame;
	const float 			mPlayerSpeed;
	ResHolder<sf::Texture, enum Type> res;

private:
	void 					processEvents();
	void 					update(sf::Time deltaTime);
	void 					render();
	void 					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

public:
	static std::pair<short, short> screenSize();	// just 1 copy of this function is enough
};

#endif
