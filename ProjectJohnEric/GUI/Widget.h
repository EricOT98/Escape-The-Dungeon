/// <summary>
/// Author : eric and james
/// Known issues none
/// </summary>
#ifndef WIDGET_H
#define WIDGET_H

#include <iostream>
#include <SFML\Graphics.hpp>
#include "../Input/Xbox360Controller.h"

using namespace std;

class Widget : public sf::Drawable
{
public:
	Widget(Widget* parent = nullptr);
	~Widget();

	virtual void update();
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	virtual void getFocus();
	virtual void looseFocus();

	virtual void setPosition(sf::Vector2f pos);
	virtual const sf::Vector2f getPosition() const;
	virtual void processInput(Xbox360Controller & controller);
	Widget * m_parent;
	Widget * m_next;
	Widget * m_previous;
	bool m_hasFocus;				//Used to get the current selected widget
	virtual std::string getType();
	virtual void setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor);
protected:
	virtual void updateShape();
	
	sf::Vector2f m_pos;
	sf::Color m_selectedColor;		//The widgets selected color
	sf::Color m_unselectedColor;	//The widgets unselected color
	sf::Color m_fillColor;			//The widgets fill color
	sf::Color m_outlineColor;		//The widgets outline color
	sf::Color m_translucent;
	std::string m_type;				//the type of widget it is

	virtual void goToNext();
	virtual void goToPrevious();
};

#endif
