/// <summary>
/// @author: Eric O' Toole
/// @desc: Pause menu for the game
/// </summary>

#ifndef PAUSE_H
#define PAUSE_H

#include "Menu.h";

class Pause : public Menu
{
public:
	Pause();
	~Pause();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;

	void continueCallback();
	void optionsCallback();
	void quitToMenuCallback();

	bool m_continuePressed;
	bool m_optionsPressed;
	bool m_quitPressed;

protected:
	void initialise() override;
	void initGUIObjects() override;

	void reset();

	Label * m_title;
	Button * m_continue;
	Button * m_options;
	Button * m_back;
};

#endif //!PAUSE
