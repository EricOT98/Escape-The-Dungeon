/// <summary>
/// Author: Eric O' Toole
/// Description: a brief options menu class for the game
/// to process the sound and outher options in the game
/// 
/// Time Taken: 1 hour
/// Known Errors: Stack overflow on destruction
/// </summary>
#ifndef SLIDER_H
#define SLIDER_H

#include "Widget.h"
#include "Label.h"

class Slider : public Widget
{
public:
	Slider(sf::Font & font, Widget * parent);
	~Slider();

	void update();
	void updateShape();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void setSize(int width, int height);
	void setPosition(sf::Vector2f pos) override;
	void setColour(sf::Color c);
	void setLabel(sf::String s);
	void setLength(int length);
	void processInput(Xbox360Controller & controller) override;

	void setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor) override;
	float getValue();
	void setValue(float val);

private:
	sf::RectangleShape bar;
	sf::RectangleShape tab;
	bool isSelected;
	float m_length;
	float m_increment;
	float m_value;
	float tabPosition;
	Label * m_label;

	void increase();
	void decrease();
};

#endif // ! SLIDER_H
