#include "Slider.h"

/// <summary>
/// Default constructor
/// </summary>
/// <param name="parent"></param>
Slider::Slider( sf::Font & font, Widget * parent = nullptr)
{
	//std::cout << "Slider created" << std::endl; //Debug msg
	m_label = new Label(font, this); //Initialise new label with pointer to widget(Slider)
	m_label->setColour(m_unselectedColor); //Set colour of label text
	m_label->setSize(30); //Set character size of label text
	bar.setOutlineThickness(5);
	bar.setOutlineColor(m_outlineColor);
	bar.setFillColor(m_fillColor);
	tab.setFillColor(m_outlineColor);
	m_length = 0;
	m_increment = 0;
	m_type = typeid(Slider).name();
}

/// <summary>
/// Deconstructor
/// </summary>
Slider::~Slider()
{
	//std::cout << "Slider destroyed" << std::endl;
}

/// <summary>
/// Update slider here
/// </summary>
void Slider::update()
{
	if (m_hasFocus)
	{
		bar.setOutlineColor(m_selectedColor);
		tab.setFillColor(m_selectedColor);
		m_label->setColour(m_selectedColor);
	}
	else
	{
		bar.setOutlineColor(m_unselectedColor);
		tab.setFillColor(m_unselectedColor);
		m_label->setColour(m_unselectedColor);
	}
	tab.setPosition(bar.getPosition().x + tabPosition, bar.getPosition().y );
}

/// <summary>
/// Does things
/// </summary>
void Slider::updateShape()
{
	sf::FloatRect labelSize = m_label->getSize();
	int width = 0, height = 0;
	if (labelSize.width > bar.getLocalBounds().width)
	{
		width = labelSize.width + 40;
	}
	if (labelSize.height > bar.getLocalBounds().height)
	{
		height = labelSize.height + 40;
	}
	if (width != 0 && height != 0)
	{
		setSize(width, height);
		setLength(width);
	}
	else if (width != 0)
	{
		setSize(width, bar.getLocalBounds().height);
		setLength(width);
	}
	else if (height != 0)
	{
		setSize(bar.getLocalBounds().width, height);
	}
}

/// <summary>
/// Draws slider objects
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void Slider::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(bar, states); //Draws slider bar rectangle
	target.draw(tab, states); //Draws slider tab rectangle
	m_label->draw(target, states);
}

/// <summary>
/// Sets size of slider
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Slider::setSize(int width, int height)
{
	bar.setSize(sf::Vector2f(width, height));
	setLength(width);

	tab.setSize(sf::Vector2f(10, height));
}

/// <summary>
/// Sets position of slider
/// </summary>
/// <param name="pos"></param>
void Slider::setPosition(sf::Vector2f pos)
{
	bar.setPosition(pos);
	m_label->setPosition(sf::Vector2f(pos.x, pos.y - (m_label->getSize().height +20)));
}

/// <summary>
/// Sets total length of the slider
/// </summary>
/// <param name="length"></param>
void Slider::setLength(int length)
{
	m_length = length;
	m_increment = (m_length - tab.getSize().x) / 100.0f;	//+2 is to avoid gaps in the end of the slider
}

void Slider::setLabel(sf::String s)
{
	m_label->setString(s);
}

/// <summary>
/// Sets fill colour of slider bar
/// </summary>
/// <param name="c"></param>
void Slider::setColour(sf::Color c)
{
	bar.setFillColor(c);
}

/// <summary>
/// Processes Xbox 360 controller input
/// </summary>
/// <param name="controller"></param>
void Slider::processInput(Xbox360Controller & controller)
{
	Widget::processInput(controller);
	GamePadState currentState = controller.m_currentState;
	GamePadState previousState = controller.m_previousState;
	if (currentState.dpadLeft || KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::A))
	{
		decrease();
	}
	else if (currentState.dpadRight || KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::D))
	{
		increase();
	}

	if (currentState.thumbstickLeft.x > 20)
	{
		increase();
	}
	else if (currentState.thumbstickRight.x < -20)
	{
		decrease();
	}
	//std::cout << m_value << std::endl;
}

void Slider::setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor)
{
	m_selectedColor = selectedColor;
	m_unselectedColor = unselectedColor;
	m_outlineColor = outlineColor;
	m_fillColor = fillColor;

	bar.setFillColor(m_fillColor);
	bar.setOutlineColor(m_outlineColor);
	tab.setFillColor(m_outlineColor);
	tab.setOutlineThickness(4);
	tab.setOutlineColor(m_outlineColor);

	m_label->setColors(m_selectedColor, m_unselectedColor, m_fillColor, m_outlineColor);
}

float Slider::getValue()
{
	return m_value;
}

void Slider::setValue(float val)
{
	m_value = val;
}

void Slider::setToggleSound(sf::SoundBuffer & buffer)
{
	m_toggleSound.setBuffer(buffer);
	m_soundsActive = true;
}

void Slider::increase()
{
	if (m_value < 100)
	{
		tabPosition += m_increment;
		//std::cout << "pos" << tabPosition << std::endl;
		m_value++;
		if (m_soundsActive && m_toggleSound.getStatus() != sf::Sound::Playing)
			m_toggleSound.play();
	}
}

void Slider::decrease()
{
	if (m_value >0)
	{
		tabPosition -= m_increment;
		m_value--;
		if(m_soundsActive && m_toggleSound.getStatus() != sf::Sound::Playing)
			m_toggleSound.play();
	}
}
