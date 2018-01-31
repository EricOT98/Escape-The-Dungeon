/// <summary>
/// Author: Eric O' Toole
/// Description: A class to control and process all widgets
/// tlabels
/// Time Taken: 2 hours
/// Dates:
/// 
/// Known Errors: No known errors
/// </summary>
#ifndef LABEL_H
#define LABEL_H

#include <iostream>
#include "Widget.h"
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

class Label : public Widget
{
public:
	Label(Widget * parent = nullptr);
	~Label();

	void update() override;
	void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void setSize(int size);
	void setPosition(sf::Vector2f pos) override;
	void setColour(sf::Color c);
	void setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor) override;
	void setString(sf::String s);
	std::string getString();
	sf::FloatRect getSize();

protected:
	sf::Text m_text;
	sf::Font m_font;
};
#endif // !LABEL_H