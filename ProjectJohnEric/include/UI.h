#ifndef UI_H
#define UI_H

#include <SFML\Graphics.hpp>
#include "ResourceManager.h"

using namespace std;

class UI
{
public:
	UI();
	~UI();

	void init();
	void update(float dt);
	void render(sf::RenderTarget & targ);
	void reset();


	float m_time;
protected:
	sf::Text m_timeText;
};

#endif !UI_H