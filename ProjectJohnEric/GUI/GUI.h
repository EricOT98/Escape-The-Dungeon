/// <summary>
/// Author: Eric O' Toole
/// Description: A class to control and process all widgets
/// that are to be used by menus and other displays in the game.
/// Time Taken: 4 hours
/// Dates:
/// 28/02/17 Gui order added and add buttons and labels
/// 
/// Known Errors: No known errors
/// Refactoring: Order method needs to be refactored to handle
/// the objects only once;
/// </summary>
#ifndef GUI_H
#define GUI_H

#include "Widget.h"
#include "Button.h"
#include "Slider.h"
#include "Checkbox.h"
#include <iostream>

using namespace std;

class GUI : public Widget
{
public:
	GUI(Widget * parent = nullptr);
	~GUI();

	void add(Widget * widget);
	void update() override;
	void processInput(Xbox360Controller & controller) override;

	void setColorScheme(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor);
	void addButton(Button * button, std::string label, sf::Vector2f pos, sf::Vector2i size, sf::Color fillColor);
	void addLabel(Label * label, std::string text, sf::Vector2f pos, int, sf::Color textColor);
	void addSlider(Slider * slider, std::string label, sf::Vector2f pos, sf::Vector2i size, sf::Color fillColor);
	void addCheckbox(Checkbox * checkbox, std::string label, sf::Vector2f pos, sf::Vector2i size, sf::Color fillColor);
	std::vector<Widget*> m_widgets;
	//Strings used to check base type of widget in the order methods
	std::string labelIdCheck;
	std::string buttonIdCheck;
	std::string sliderIdCheck;
private:
	void order();
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	
	bool startWidgetFound = false;
};
#endif