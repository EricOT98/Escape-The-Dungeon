/// <summary>
/// @author: Eric O' Toole
/// @desc A sound options controller menu
/// </summary>

#ifndef SOUNDOPTIONS_H
#define SOUDNOPTIONS_H

#include "Menu.h"

class SoundOptions : public Menu
{
public:
	SoundOptions(sf::Font & font);
	~SoundOptions();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;

	void back();
	void volume();

protected:
	void initialise() override;
	void initGUIObjects() override;

	void reset();

	bool m_backPressed;
	bool m_volumePressed;

	Label * m_title;
	Button * m_back;
	Slider * m_volume;
};
#endif //!SOUNDOPTIONS
