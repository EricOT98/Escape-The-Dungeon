#include "SoundOptions.h"

/// <summary>
/// Default constructor
/// </summary>
SoundOptions::SoundOptions(sf::Font & font) :
	Menu(MenuStates::SOUNDOPTIONS, font)
{
	initialise();
}

/// <summary>
/// Default destructor
/// </summary>
SoundOptions::~SoundOptions()
{
}

/// <summary>
/// Update the sound options menu
/// </summary>
/// <param name="controller">The current connected controller</param>
void SoundOptions::update(Xbox360Controller & controller)
{
	m_gui.processInput(controller);
	//Menu functionality for a button press
	if (m_backPressed)
	{
		goToMenu(MenuStates::OPTIONS);
		reset();
	}
	m_gui.update();
}

/// <summary>
/// Render the current menu
/// </summary>
/// <param name="window">The current render window</param>
void SoundOptions::render(sf::RenderWindow & window)
{
	window.draw(m_gui); //Draw gui components
}

/// <summary>
/// back button callback
/// </summary>
void SoundOptions::back()
{
	m_backPressed = true;
}

/// <summary>
/// volume button callback
/// </summary>
void SoundOptions::volume()
{
	
}

/// <summary>
/// 
/// </summary>
void SoundOptions::initialise()
{
	initGUIObjects();
	//m_sound->select = std::bind(&OptionsMenu::sound, this);
	m_back->select = std::bind(&SoundOptions::back, this);
}

/// <summary>
/// 
/// </summary>
void SoundOptions::initGUIObjects()
{
	m_title = new Label( m_font, nullptr);
	m_back = new Button( m_font, nullptr);
	m_volume = new Slider(m_font, nullptr);
	m_gui.addLabel(m_title, "Sound Options", sf::Vector2f(100, 0), 80, sf::Color::Green);
	m_gui.addButton(m_back, "<- Back", sf::Vector2f(100, 600), sf::Vector2i(200, 50), sf::Color::Green);
	m_gui.addSlider(m_volume, "Volume", sf::Vector2f(100, 300), sf::Vector2i(200, 50), sf::Color::Green);
	//selected, unselected, fill ,outline
	m_gui.setColorScheme(sf::Color::Blue, sf::Color::White, sf::Color::Green, sf::Color::Black);
	m_title->setColour(sf::Color::White);
}

/// <summary>
/// Rest all button pressed variables
/// </summary>
void SoundOptions::reset()
{
	m_backPressed = false;
}
