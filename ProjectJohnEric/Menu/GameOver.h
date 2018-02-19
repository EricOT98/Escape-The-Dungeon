#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "Menu.h"
#include "ResourceManager.h"

class GameOver : public Menu
{
public:
	GameOver(sf::Font & font, bool & gameOutcome, float & time);
	~GameOver();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;

	void mainmenu();
	void retry();
	typedef std::function<void()> Callback;
	Callback retryGame;
	void setEndTime(float time);
	void setFail();
protected:
	void initialise() override;
	void initGUIObjects() override;

	void reset();

	bool m_backPressed;
	bool m_volumePressed;

	Label * m_title;
	sf::Text m_message;
	Button * m_mainmenu;
	Button * m_retry;

	bool m_mainmenuPressed;
	bool m_retryPressed;
	bool & m_gameOutcome;
	float & m_time;
};
#endif //!GAMEOVER
