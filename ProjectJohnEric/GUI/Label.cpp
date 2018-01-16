#include "Label.h"

/// <summary>
/// Default constructor
/// </summary>
/// <param name="parent"></param>
Label::Label(Widget * parent)
{
	//std::cout << "Label created" << std::endl;

	if (!m_font.loadFromFile("ASSETS/FONTS/ariblk.TTF"))
	{
		std::string s("Error loading font <ariblk.TTF>");
		//throw std::exception(s.c_str());
	}

	m_text.setFont(m_font);
	m_text.setFillColor(m_unselectedColor);
	m_type = typeid(Label).name();
}

/// <summary>
/// Deconstructor
/// </summary>
Label::~Label()
{
	std::cout << "Label deconstructed" << std::endl;
}

/// <summary>
/// Update label objects
/// </summary>
void Label::update()
{
	//This code prevets the Label from having focus and therefore
	//can be processed by the gui without the gui needing to check if it is label
	if (m_hasFocus)
	{
		if (m_next != nullptr && m_next->getType() != m_type)
		{
			looseFocus();
			m_next->getFocus();
		}
		else
		{
			looseFocus();
			m_previous->getFocus();
		}
	}
}

/// <summary>
/// Draw labels here
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void Label::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_text, states);
}

/// <summary>
/// Sets the label text colour
/// </summary>
void Label::setColour(sf::Color c)
{
	m_text.setFillColor(c);
}

/// <summary>
/// Sets position of label on screen
/// </summary>
/// <param name="pos"></param>
void Label::setPosition(sf::Vector2f pos)
{
	m_text.setPosition(pos);
}

void Label::setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor)
{
	m_selectedColor = selectedColor;
	m_unselectedColor = unselectedColor;
	m_text.setFillColor(unselectedColor);
}

/// <summary>
/// Sets character size of label
/// </summary>
/// <param name="size"></param>
void Label::setSize(int size)
{
	m_text.setCharacterSize(size);
}

/// <summary>
/// Sets the string of each label
/// </summary>
/// <param name="s"></param>
void Label::setString(sf::String s)
{
	m_text.setString(s);
}

sf::FloatRect Label::getSize()
{
	return m_text.getGlobalBounds();
}
