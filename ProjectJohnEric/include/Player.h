/// <summary>
/// @author: John O' Meara
/// date: 30/10/2017
/// </summary>

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML\Audio.hpp>

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
	
	void processInput(Xbox360Controller & controller);
	bool getViewForward() {
		return m_viewForward;
	}
	void move() override;
	float m_visionRange;
	float m_fieldOfVision;
	float m_viewPercent;// no greater than 1
	float m_viewStep; // 0-1

	float m_rangeMin, m_rangeMax;
	float m_fovMin, m_fovMax;

	float lerp(float start, float end, float percentage);
protected:
	bool m_usingMouse;
	bool m_viewForward;

private:
	KeyboardHandler * m_keyHandler;

	
	
	Xbox360Controller controller;
	Light *  m_light;
	sf::Sound m_walking;
	bool m_soundsLoaded;
};

#endif !PLAYER_H