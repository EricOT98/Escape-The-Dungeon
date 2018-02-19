#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Widget.h"
#include "Label.h"
#include <functional>
#include "ResourceManager.h"

class Button : public Widget
{
public:
	Button(sf::Font & font, Widget * parent);
	~Button();

	void update();
	void updateShape();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void setSize(int width, int height);
	void setPosition(sf::Vector2f pos) override;
	void setColour(sf::Color c);
	void setLabel(sf::String s);
	void processInput(Xbox360Controller & controller) override;

	void setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor) override;
	void setClickSound(sf::SoundBuffer & buffer);
	void resetPressed();
	bool getPressed();
	typedef std::function<void()> Callback;
	Callback select;
protected:
	sf::Sound m_clickSound;
private:
	sf::RectangleShape rect;
	bool isPressed;
	Label * m_label;
	
};

#endif // !BUTTON_H
