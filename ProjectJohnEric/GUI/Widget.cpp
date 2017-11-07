#include "Widget.h"

Widget::Widget(Widget * parent) :
	m_parent(parent)
{
	m_next = nullptr;
	m_previous = nullptr;
	m_type = typeid(Widget).name();
}

/// <summary>
/// Delete all references to widgets tht the
/// widget has
/// </summary>
Widget::~Widget()
{
	m_next = nullptr;
	m_previous = nullptr;
	m_parent = nullptr;
	std::cout << "Widget Destroyed" << std::endl;
}

/// <summary>
/// Update all the widget objects in the gui
/// </summary>
void Widget::update()
{
}

/// <summary>
/// Draw all widgets in the gui
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void Widget::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
}

/// <summary>
/// Set this widget to be focused
/// </summary>
void Widget::getFocus()
{
	m_hasFocus = true;
}

/// <summary>
/// Set this widget to be unfocused
/// </summary>
void Widget::looseFocus()
{
	m_hasFocus = false;
}

/// <summary>
/// This method processes all input for the widget objects
/// The method sets the next active widget based on the 
/// input from the controller.
/// </summary>
/// <param name="controller"></param>
void Widget::processInput(Xbox360Controller & controller)
{
	GamePadState currentState = controller.m_currentState;
	GamePadState previousState = controller.m_previousState;
	if (currentState.dpadUp && !previousState.dpadUp)
	{
		goToPrevious();
	}
	else if (currentState.dpadDown && !previousState.dpadDown)
	{
		goToNext();
	}

	if (currentState.thumbstickLeft.y > 20 && previousState.thumbstickLeft.y < 20)
	{
		goToNext();
	}
	else if (currentState.thumbstickLeft.y < -20 && previousState.thumbstickLeft.y > -20)
	{
		goToPrevious();
	}
}

/// <summary>
/// Set the position of the widget
/// </summary>
/// <param name="pos"></param>
void Widget::setPosition(sf::Vector2f pos)
{
	m_pos = pos;
}

/// <summary>
/// Get the position of the widget
/// </summary>
/// <returns></returns>
const sf::Vector2f Widget::getPosition() const
{
	return m_pos;
}

/// <summary>
/// Return the type of the widget
/// </summary>
/// <returns></returns>
std::string Widget::getType()
{
	return m_type;
}

void Widget::setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor)
{
	m_selectedColor = selectedColor;
	m_unselectedColor = unselectedColor;
	m_fillColor = fillColor;
	m_outlineColor = outlineColor;
}

/// <summary>
/// Updates the shape of every widget object in the
/// gui.
/// </summary>
void Widget::updateShape()
{
	if (m_parent)
	{
		m_parent->updateShape();
	}
}

/// <summary>
/// This method sets the focus to be the next focusable widget
/// </summary>
void Widget::goToNext()
{
	if (m_next != nullptr)
	{
		looseFocus();
		m_next->getFocus();
	}
	else
	{
		//Produce error sound
	}
}

/// <summary>
/// his method sets the focus to be the previous focusable widget
/// </summary>
void Widget::goToPrevious()
{
	if (m_previous != nullptr)
	{
		looseFocus();
		m_previous->getFocus();
	}
	else
	{
		//Produce error sound
	}
}
