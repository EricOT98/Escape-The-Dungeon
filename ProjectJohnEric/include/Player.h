/// <summary>
/// @author: John O' Meara
/// date: 30/10/2017
/// </summary>

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "KeyboardHandler.h"
#include "../Input/Xbox360Controller.h"

using namespace std;

class Player : public Character
{
public:
	Player();
	Player(string name);

	void update(sf::RenderWindow &window, Xbox360Controller & controller);

	bool getViewForward() {
		return m_viewForward;
	}

protected:
	bool m_usingMouse;
	bool m_viewForward;

private:
	KeyboardHandler * m_keyHandler;

	float m_visionRange;
	float m_fieldOfVision;
	

	Xbox360Controller controller;
};

#endif !PLAYER_H