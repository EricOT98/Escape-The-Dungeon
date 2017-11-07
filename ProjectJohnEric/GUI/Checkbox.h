#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "Button.h"

class Checkbox : public Button
{
public:
	Checkbox(Widget * parent = nullptr);
	~Checkbox();

	void update();
	void updateShape();
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void setSize(int width, int height);
	void setPosition(sf::Vector2f pos) override;
	void setColour(sf::Color c);
	void setLabel(sf::String s);

	void processInput(Xbox360Controller & controller) override;
	void setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor) override;
private:
	sf::RectangleShape m_boxRect;
	sf::RectangleShape m_tickRect;
	bool isSelected;
	Label * m_label;
	bool m_on;
};

#endif // !CHECKBOX_H
