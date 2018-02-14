#include "Button.h"

/// <summary>
/// Button constructor
/// </summary>
Button::Button(sf::Font & font, Widget * parent = nullptr)
{
	//std::cout << "Button created" << std::endl; //Debug msg
	m_label = new Label(font, this); //Initialise label with pointer to widget(button)
	m_label->setColour(m_unselectedColor); //Set colour of label text
	m_label->setSize(30); //Set character size of label text	
	m_type = typeid(Button).name();	//Set the type of the button
	//rect.setFillColor(m_fillColor);
	rect.setOutlineColor(m_outlineColor);
}

/// <summary>
/// Button deconstructor
/// </summary>
Button::~Button()
{
	//std::cout << "Button destroyed" << std::endl; //Debug msg
}

/// <summary>
/// Takes width and height as a parameter
/// and scales the button
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void Button::setSize(int width, int height)
{
	//Sets width/height of rectangle for button
	rect.setSize(sf::Vector2f(width, height));
}

/// <summary>
/// Takes x and y parameters and sets the
/// position of the button
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Button::setPosition(sf::Vector2f pos)
{
	rect.setPosition(pos); //Set x/y position of rectangle
	m_label->setPosition(sf::Vector2f(pos.x, pos.y)); //Sets label position to rectangle position
}

/// <summary>
/// Sets the string to each label
/// </summary>
/// <param name="s"></param>
void Button::setLabel(sf::String s)
{
	//Sets label to text to string passed in
	m_label->setString(s);
}

/// <summary>
/// Takes an sf::Color parameter
/// and sets the fillColor of the 
/// rectangle
/// </summary>
/// <param name="c"></param>
void Button::setColour(sf::Color c)
{
	//Sets fill colour of button rectangle
	rect.setFillColor(c);
}

/// <summary>
/// Processes key input for button class
/// </summary>
/// <param name="event"></param>
void Button::processInput(Xbox360Controller & controller)
{
	GamePadState currentState = controller.m_currentState;
	GamePadState previousState = controller.m_previousState;
	Widget::processInput(controller);
	if ((currentState.buttonCross && !previousState.buttonCross) || KeyboardHandler::GetInstance()->KeyPressed(sf::Keyboard::Return))
	{
		isPressed = true;
		select();
	}
}

/// <summary>
/// Sets the color of the buttons to  match the color scheme
/// </summary>
/// <param name="selectedColor"></param>
/// <param name="unselectedColor"></param>
/// <param name="fillColor"></param>
/// <param name="outlineColor"></param>
void Button::setColors(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor)
{
	m_selectedColor = selectedColor;
	m_unselectedColor = unselectedColor;
	m_fillColor = fillColor;
	m_outlineColor = outlineColor;

	rect.setFillColor(m_fillColor);
	rect.setOutlineColor(m_outlineColor);
	m_label->setColors(m_selectedColor, m_unselectedColor, m_fillColor, m_outlineColor);
}

void Button::resetPressed()
{
	isPressed = false;
}

bool Button::getPressed()
{
	return isPressed;
}

/// <summary>
/// Update button here, check key presses
/// </summary>
void Button::update()
{
	//Mouse position changed for xbox controller implementation
	if (m_hasFocus)
	{
		rect.setOutlineThickness(5);
		rect.setOutlineColor(m_selectedColor);
		m_label->setColour(m_selectedColor);
	}
	else
	{
		rect.setOutlineThickness(0);
		rect.setOutlineColor(m_unselectedColor);
		m_label->setColour(m_unselectedColor);
		//std::cout << "Button: " << m_label->getString() << ":" << m_unselectedColor << std::endl;


	}
}

void Button::updateShape()
{
	sf::FloatRect labelSize = m_label->getSize();
	int width = 0, height = 0;
	if (labelSize.width > rect.getLocalBounds().width)
	{
		width = labelSize.width + 40;
	}
	if (labelSize.height > rect.getLocalBounds().height)
	{
		height = labelSize.height + 40;
	}
	if (width != 0 && height != 0)
	{
		setSize(width, height);
	}
	else if (width != 0)
	{
		setSize(width, rect.getLocalBounds().height);
	}
	else if (height != 0)
	{
		setSize(rect.getLocalBounds().width, height);
	}
}

/// <summary>
/// Draw button objects here
/// </summary>
/// <param name="window"></param>
void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect, states); //Draws button rectangles
	m_label->draw(target, states); //Calls label draw function
}