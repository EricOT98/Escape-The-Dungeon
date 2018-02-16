#include "DisplayOptions.h"

/// <summary>
/// Default constructor
/// </summary>
DisplayOptions::DisplayOptions(sf::Font & font) :
	Menu(MenuStates::DISPLAYOPTIONS, font)
{
	initialise();
}

DisplayOptions::~DisplayOptions()
{
}

/// <summary>
/// Update the display options menu
/// </summary>
/// <param name="controller">The current connected controller</param>
void DisplayOptions::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);

	if (m_backPressed)
	{
		goToMenu(m_previousMenu);
		reset();
	}

	if (KeyboardHandler::GetInstance()->KeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Widgets:" << std::endl;
		for (auto widget : m_gui.m_widgets)
		{
			std::cout << "Widget: " << widget->getType() << std::endl;
		}
	}
	m_gui.update();
}

/// <summary>
/// Draw all gui components to the screen
/// </summary>
/// <param name="window">The current render window</param>
void DisplayOptions::render(sf::RenderWindow & window)
{
	window.draw(m_gui);
}

/// <summary>
/// Shader toggle callback function
/// </summary>
void DisplayOptions::shader()
{
	m_shaderPressed = !m_shaderPressed;
}

/// <summary>
///	Camera shake toggle function
/// </summary>
void DisplayOptions::cameraShake()
{
	m_shaderPressed = !m_shakePressed;
}

void DisplayOptions::back()
{
	m_backPressed = true;
}

void DisplayOptions::initialise()
{
	initGUIObjects();
	m_shader->select = std::bind(&DisplayOptions::shader, this);
	m_shake->select = std::bind(&DisplayOptions::cameraShake, this);
	m_back->select = std::bind(&DisplayOptions::back, this);
}
/// <summary>
/// Initialise all gui objects
/// </summary>
void DisplayOptions::initGUIObjects()
{
	m_title = new Label( m_font, nullptr);
	m_shader = new Checkbox( m_font, nullptr);
	m_shake = new Checkbox( m_font, nullptr);
	m_back = new Button( m_font, nullptr);

	m_gui.addLabel(m_title, "Display options", sf::Vector2f(100, 0), 80, sf::Color::Green);
	m_gui.addCheckbox(m_shader, "Shaders On", sf::Vector2f(100, 200), sf::Vector2i(40, 40), sf::Color::Green);
	m_gui.addCheckbox(m_shake, "Camera Shake On", sf::Vector2f(100, 400), sf::Vector2i(40, 40), sf::Color::Green);
	m_gui.addButton(m_back, "<- Back", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);
	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Black);
}

/// <summary>
/// Reset the menu to be used again
/// </summary>
void DisplayOptions::reset()
{
	m_backPressed = false;
}
