/// <summary>
/// @author: Eric O' Toole
/// @desc: Display Options menu class for toggling shaders + camera shake
/// </summary>

#ifndef DISPLAYOPTIONS_H
#define OPTIONSMENU_H

#include "Menu.h"

class DisplayOptions : public Menu
{
public:
	DisplayOptions(sf::Font & font);
	~DisplayOptions();

	void update(Xbox360Controller & controller) override;
	void render(sf::RenderWindow & window) override;

	void shader();
	void cameraShake();
	void back();
	
	bool m_shaderPressed;
	bool m_shakePressed;
	bool m_backPressed;
	
protected:
	void initialise() override;
	void initGUIObjects() override;

	void reset();

	Label * m_title;
	Checkbox * m_shader;
	Checkbox * m_shake;
	Button * m_back;
};

#endif //!OPTIONSMENU_H