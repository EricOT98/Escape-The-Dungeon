#include "GUI.h"
#include "ResourceManager.h"

/// <summary>
/// Default constructor
/// Takes pointer to a widget
/// as a parameter
/// </summary>
/// <param name="parent"></param>
GUI::GUI(Widget * parent)
{
	labelIdCheck = typeid(Label).name();
	buttonIdCheck = typeid(Button).name();
	sliderIdCheck = typeid(Slider).name();
	//std::cout << labelIdCheck << std::endl;
	//std::cout << buttonIdCheck << std::endl;
	//std::cout << sliderIdCheck << std::endl;
}

/// <summary>
/// Deconstructor
/// </summary>
GUI::~GUI()
{
	for (Widget * widget : m_widgets)
	{
		if (widget->m_parent == this)
		{
			delete widget;
		}
	}
}

/// <summary>
/// This method adds a passed in Widget to the array of 
/// Widget pointers and pushs the vector of pointers back
/// to allow the widget to be added
/// </summary>
/// <param name="widget"></param>
void GUI::add(Widget * widget)
{
	//Slightly hackw way but reduces code duplication
	widget->setSwitchSound(g_resourceManager.soundHolder["Switch"]);
	widget->setErrorSound(g_resourceManager.soundHolder["Error"]);


	widget->m_parent = this;
	m_widgets.emplace_back(widget);
	updateShape();
}

/// <summary>
/// Calls the update method of every Widget object contained in
/// the Gui object.
/// </summary>
void GUI::update()
{
	for (Widget * widget : m_widgets)
	{
		widget->update();
	}
}

/// <summary>
/// This method is used to process input for all the wodgets in the gui object
/// The processed boolean is used to control the input for each widget so only one input
/// can be registered at a time. This is necessary due to the controller update not 
/// updating at the correct time and thus registering mutliple inputs for every
/// widget.
/// </summary>
/// <param name="controller"></param>
void GUI::processInput(Xbox360Controller & controller)
{
	controller.update();
	bool processed = false;
	for (Widget * widget : m_widgets)
	{
		if (widget->m_hasFocus && !processed)
		{
			widget->processInput(controller);
			processed = true;
		}
	}
}

/// <summary>
/// This method is used to order all the widets in the m_widgets vector
/// The widget position at the current index is checked and if
/// the widget is first it assigns its next widget only,
/// last its previous widget only,
/// only widget do nothing
/// any other widget assign its next and previous widget
/// </summary>
void GUI::order()
{
	int index = 0;
	int numElements = m_widgets.size();
	for (Widget * widget : m_widgets)
	{
		std::string name = typeid(*widget).name();
		if (index == 0 && numElements > 1)						//First element
		{
			widget->m_next = m_widgets.at(index + 1);
		}
		else if (index == numElements - 1 && numElements > 1)   //last element
		{
			widget->m_previous = m_widgets.at(index - 1);
		}
		else if (index == 0 && numElements <= 1)				//Only element
		{
			int i = 0;
		}
		else                                                    //Every other element
		{
			widget->m_next = m_widgets.at(index + 1);
			widget->m_previous = m_widgets.at(index - 1);
		}
		//This is to set the first focused widget to not be a label
		if (name != labelIdCheck && !startWidgetFound)
		{
			widget->getFocus();
			startWidgetFound = true;
			//std::cout << "Start widget is : " << typeid(*widget).name() << std::endl;
		}

		index++;
	}
}

void GUI::setColorScheme(sf::Color selectedColor, sf::Color unselectedColor, sf::Color fillColor, sf::Color outlineColor)
{
	for (Widget* widget : m_widgets)
	{
		widget->setColors(selectedColor, unselectedColor, fillColor, outlineColor);
	}
}

/// <summary>
/// This method creates a pointer to a button object and adds it to the
/// vector of m_widgets
/// </summary>
/// <param name="button"></param>
/// <param name="label"></param>
/// <param name="pos"></param>
/// <param name="size"></param>
/// <param name="fillColor"></param>
void GUI::addButton(Button * button, std::string label, sf::Vector2f pos, sf::Vector2i size, sf::Color fillColor)
{
	button->setLabel(label);
	button->setPosition(pos);
	button->setSize(size.x, size.y);
	button->setColour(fillColor);
	button->updateShape();
	button->setClickSound(g_resourceManager.soundHolder["ButtonClick"]);
	add(button);
	order();
}

/// <summary>
/// This method creates a pointer to a label object and adds it to the
/// vector of m_widgets
/// </summary>
/// <param name="label"></param>
/// <param name="text"></param>
/// <param name="pos"></param>
/// <param name="size"></param>
/// <param name="textColor"></param>
void GUI::addLabel(Label * label, std::string text, sf::Vector2f pos, int size, sf::Color textColor)
{
	label->setString(text);
	label->setPosition(pos);
	label->setSize(size);
	label->setColour(textColor);
	add(label);
	order();
}

/// <summary>
/// This method adds a pointer to a slider object and adds it
/// to the vector of m_widgets
/// </summary>
/// <param name="slider"></param>
/// <param name="label"></param>
/// <param name="pos"></param>
/// <param name="size"></param>
/// <param name="fillColor"></param>
void GUI::addSlider(Slider * slider, std::string label, sf::Vector2f pos, sf::Vector2i size, sf::Color fillColor)
{
	slider->setLabel(label);
	slider->setPosition(pos);
	slider->setSize(size.x, size.y);
	slider->setLength(size.x - 2);
	slider->setColour(fillColor);
	slider->updateShape();
	slider->setToggleSound(g_resourceManager.soundHolder["SliderToggle"]);
	add(slider);
	order();
}

/// <summary>
/// Adds a pointer to checkbox objects and adds it
/// to the vector of m_widgets
/// </summary>
/// <param name="checkbox"></param>
/// <param name="label"></param>
/// <param name="pos"></param>
/// <param name="size"></param>
/// <param name="fillColor"></param>
void GUI::addCheckbox(Checkbox * checkbox, std::string label, sf::Vector2f pos, sf::Vector2i size, sf::Color fillColor)
{
	checkbox->setLabel(label);
	checkbox->setSize(size.x, size.y);
	checkbox->setPosition(pos);
	checkbox->setColour(fillColor);
	checkbox->updateShape();
	checkbox->setClickSound(g_resourceManager.soundHolder["ButtonClick"]);
	add(checkbox);
	order();
}

/// <summary>
/// Calls the draw method for every Widget contained in the gui
/// object.
/// </summary>
/// <param name="target"></param>
/// <param name="states"></param>
void GUI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (Widget * widget : m_widgets)
	{
		target.draw(*widget, states);
	}
}
