/// <summary>
/// @author: John O' Meara
/// date: 30/10/2017
/// </summary>

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "KeyboardHandler.h"
#include "../Input/Xbox360Controller.h"
#include "../Lights/Light.h"
#include "../Lights/LightEngine.h"

using namespace std;

class Player : public Character
{
public:
	Player();
	Player(string name);
	void init(LightEngine & engine);
	void update(sf::RenderWindow &window, Xbox360Controller & controller);

	//sf::RectangleShape m_TESTPOINTER;

protected:
	bool m_usingMouse;

private:
	KeyboardHandler * m_keyHandler;
	float m_visionRange;
	

	Xbox360Controller controller;
	Light *  m_light;
};

#endif !PLAYER_H