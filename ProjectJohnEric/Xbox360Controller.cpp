#include "Xbox360Controller.h"
#include <iostream>

/// <summary>
/// @author John O' Meara
/// @date Feb 2017
/// @version 1,0
/// </summary>

/// <summary>
/// Default constructor
/// </summary>
Xbox360Controller::Xbox360Controller()
{

}

/// <summary>
/// Destructer
/// </summary>
Xbox360Controller::~Xbox360Controller()
{

}

/// <summary>
/// Updates the state of the controller
/// </summary>
void Xbox360Controller::update()
{
	m_previousState = m_currentState;

	sf::Joystick::update();

	checkButtons();
	checkThumbsticks();
	checkDPad();
	checkTriggers();
}


/// <summary>
/// Checks if a controller is connected
/// </summary>
/// <returns></returns>
bool Xbox360Controller::isConnected()
{
	if (sf::Joystick::isConnected(0))
	{
		return true;
	}
	return false;
}

/// <summary>
/// Finds next available connected controller
/// </summary>
/// <returns></returns>
bool Xbox360Controller::connect()
{
	return false;
}

/// <summary>
/// Takes the input and assigns it to a button
/// </summary>
/// <param name="button"></param>
void Xbox360Controller::checkButtons()
{
	if (sf::Joystick::isButtonPressed(0, 0))
	{
		m_currentState.buttonA = true;
	}
	else
	{
		m_currentState.buttonA = false;
	}

	if (sf::Joystick::isButtonPressed(0, 1))
	{
		m_currentState.buttonB = true;
	}
	else
	{
		m_currentState.buttonB = false;
	}

	if (sf::Joystick::isButtonPressed(0, 2))
	{
		m_currentState.buttonX = true;
	}
	else
	{
		m_currentState.buttonX = false;
	}

	if (sf::Joystick::isButtonPressed(0, 3))
	{
		m_currentState.buttonY = true;
	}
	else
	{
		m_currentState.buttonY = false;
	}

	if (sf::Joystick::isButtonPressed(0, 4))
	{
		m_currentState.bumperLeft = true;
	}
	else
	{
		m_currentState.bumperLeft = false;
	}

	if (sf::Joystick::isButtonPressed(0, 5))
	{
		m_currentState.bumperRight = true;
	}
	else
	{
		m_currentState.bumperRight = false;
	}

	if (sf::Joystick::isButtonPressed(0, 6))
	{
		m_currentState.Back = true;
	}
	else
	{
		m_currentState.Back = false;
	}

	if (sf::Joystick::isButtonPressed(0, 7))
	{
		m_currentState.Start = true;
	}
	else
	{
		m_currentState.Start = false;
	}

	if (sf::Joystick::isButtonPressed(0, 8))
	{
		m_currentState.thumbstickLeftClick = true;
	}
	else
	{
		m_currentState.thumbstickLeftClick = false;
	}

	if (sf::Joystick::isButtonPressed(0, 9))
	{
		m_currentState.thumbstickRightClick = true;
	}
	else
	{
		m_currentState.thumbstickRightClick = false;
	}
}

/// <summary>
/// Assigns values for the thumbsticks
/// </summary>
void Xbox360Controller::checkThumbsticks()
{
	//LEFT
	m_currentState.thumbstickLeft.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X);
	m_currentState.thumbstickLeft.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y);

	//RIGHT
	m_currentState.thumbstickRight.x = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
	m_currentState.thumbstickRight.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R);

	//ANGLE
	m_currentState.leftAngleRAD = std::atan2(m_currentState.thumbstickLeft.y, m_currentState.thumbstickLeft.x);
	m_currentState.rightAngleRAD = std::atan2(m_currentState.thumbstickRight.y, m_currentState.thumbstickRight.x);
	m_currentState.leftAngleDEG = (m_currentState.leftAngleRAD * (180 / acos(-1)) - 90);
	m_currentState.rightAngleDEG = (m_currentState.rightAngleRAD * (180 / acos(-1)) - 90);
}

/// <summary>
/// Assigns values for the D-Pad
/// </summary>
void Xbox360Controller::checkDPad()
{
	// UP
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) >= dpadThreshold)
	{
		m_currentState.dpadUp = true;
	}
	else
	{
		m_currentState.dpadUp = false;
	}

	// DOWN
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) <= -dpadThreshold)
	{
		m_currentState.dpadDown = true;
	}
	else
	{
		m_currentState.dpadDown = false;
	}

	// RIGHT
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) >= dpadThreshold)
	{
		m_currentState.dpadRight = true;
	}
	else
	{
		m_currentState.dpadRight = false;
	}

	// LEFT
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) <= -dpadThreshold)
	{
		m_currentState.dpadLeft = true;
	}
	else
	{
		m_currentState.dpadLeft = false;
	}
}

/// <summary>
/// Assigns values for the Triggers
/// </summary>
void Xbox360Controller::checkTriggers()
{
	// LEFT
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) >= 0.1)
	{
		m_currentState.triggerLeft = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	}
	else
	{
		m_currentState.triggerLeft = 0;
	}

	// RIGHT
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) <= -0.1)
	{
		m_currentState.triggerRight = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	}
	else
	{
		m_currentState.triggerRight = 0;
	}
}