#include "OptionsMenu.h"

/// <summary>
/// Default consrtuctor
/// </summary>
OptionsMenu::OptionsMenu() :
	Menu(MenuStates::OPTIONS)
{
	initialise();
}

/// <summary>
/// Default Destructor
/// </summary>
OptionsMenu::~OptionsMenu()
{
}

/// <summary>
/// Update the options menu
/// </summary>
/// <param name="controller">The current connected controller</param>
void OptionsMenu::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	//Menu functionality for a button press
	if (m_backPressed)
	{
		goToMenu(MenuStates::MAIN_MENU);
		reset();
	}
	if (m_soundPressed)
	{
		goToMenu(MenuStates::SOUNDOPTIONS);
		reset();
	}
	if (m_displayPressed)
	{
		//TODO: Eric - implement display options menu State
		goToMenu(MenuStates::DISPLAYOPTIONS);
		reset();
	}

	m_gui.update();
}

/// <summary>
/// Draw the current menu
/// </summary>
/// <param name="window">The current render window</param>
void OptionsMenu::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

/// <summary>
/// Sound options button callback
/// </summary>
void OptionsMenu::sound()
{
	m_soundPressed = true;
}

/// <summary>
/// Display menu callback
/// </summary>
void OptionsMenu::display()
{
	m_displayPressed = true;
}

/// <summary>
/// Back button callback
/// </summary>
void OptionsMenu::back()
{
	m_backPressed = true;
}

/// <summary>
/// Initialise the options menu
/// </summary>
void OptionsMenu::initialise()
{
	initGUIObjects();
	m_sound->select = std::bind(&OptionsMenu::sound, this);
	m_back->select = std::bind(&OptionsMenu::back, this);
	m_display->select = std::bind(&OptionsMenu::display, this);
}

/// <summary>
/// Initialise all gui objects in the menu
/// </summary>
void OptionsMenu::initGUIObjects()
{
	m_title = new Label(nullptr);
	m_sound = new Button(nullptr);
	m_display = new Button(nullptr);
	m_back = new Button(nullptr);
	m_gui.addLabel(m_title, "Options", sf::Vector2f(100, 0), 80, sf::Color::Green);
	m_gui.addButton(m_sound, "Sound Options", sf::Vector2f(100, 200), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_display, "Display Options", sf::Vector2f(100, 300), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addButton(m_back, "<- Back", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);

	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Black);
}

/// <summary>
/// Reset the menu to be used again
/// </summary>
void OptionsMenu::reset()
{
	m_backPressed = false;
	m_soundPressed = false;
	m_displayPressed = false;
}
