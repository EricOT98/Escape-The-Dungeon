/// <summary>
/// @author: John O' Meara
/// date: 30/10/2017
/// </summary>

#ifndef PLAYER_H
#define PLAYER_H

//#include <iostream>
//#include <SFML/Graphics.hpp>

#include "Character.h"
#include "KeyboardHandler.h"

using namespace std;

class Player : public Character
{
public:
	Player();
	Player(string name);

	void update(sf::RenderWindow &window);

protected:
	bool m_usingMouse;

private:
	KeyboardHandler * m_keyHandler;
};

#endif !PLAYER_H