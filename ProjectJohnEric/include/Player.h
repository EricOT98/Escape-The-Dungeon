/// <summary>
/// @author: John O' Meara
/// date: 30/10/2017
/// </summary>

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "KeyboardHandler.h"
#include "Xbox360Controller.h"

using namespace std;

class Player : public Character
{
public:
	Player();
	Player(string name);

	void update(sf::RenderWindow &window, Xbox360Controller & controller);

protected:
	bool m_usingMouse;

private:
	KeyboardHandler * m_keyHandler;
};

#endif !PLAYER_H