#include "UI.h"

#include <iomanip> // setprecision
#include <sstream> // stringstream
UI::UI()
{
	
}

UI::~UI()
{
}

void UI::init()
{
	m_timeText.setFont(g_resourceManager.fontHolder["UIFont"]);
	m_timeText.setPosition(sf::Vector2f(0, 0));
	m_timeText.setFillColor(sf::Color(77, 132, 60));
	
	m_timeText.setCharacterSize(30);
}

void UI::update(float dt)
{
	m_time += dt;
	stringstream stream;
	stream << fixed << setprecision(2) << m_time;
	string s = stream.str();
	m_timeText.setString("Time: " + s);
}

void UI::render(sf::RenderTarget & targ)
{
	targ.draw(m_timeText);
}

void UI::reset()
{
	m_time = 0;
}
