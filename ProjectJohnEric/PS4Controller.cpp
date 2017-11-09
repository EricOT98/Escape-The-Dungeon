#include "PS4Controller.h"
#include <iostream>

/// <summary>
/// @author John O' Meara
/// @date Feb 2017
/// @version 1,0
/// </summary>

/// <summary>
/// Default constructor
/// </summary>
PS4Controller::PS4Controller()
{

}

/// <summary>
/// Destructer
/// </summary>
PS4Controller::~PS4Controller()
{

}

/// <summary>
/// Updates the state of the controller
/// </summary>
void PS4Controller::update()
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
bool PS4Controller::isConnected()
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
bool PS4Controller::connect()
{
	return false;
}

/// <summary>
/// Takes the input and assigns it to a button
/// </summary>
/// <param name="button"></param>
void PS4Controller::checkButtons()
{
	m_currentState.buttonSquare = sf::Joystick::isButtonPressed(0, 0);
	m_currentState.buttonCross = sf::Joystick::isButtonPressed(0, 1);
	m_currentState.buttonCircle = sf::Joystick::isButtonPressed(0, 2);
	m_currentState.buttonTriangle = sf::Joystick::isButtonPressed(0, 3);

	m_currentState.bumperLeft = sf::Joystick::isButtonPressed(0, 4);
	m_currentState.bumperRight = sf::Joystick::isButtonPressed(0, 5);

	m_currentState.share = sf::Joystick::isButtonPressed(0, 8);
	m_currentState.options = sf::Joystick::isButtonPressed(0, 9);

	m_currentState.thumbstickLeftClick = sf::Joystick::isButtonPressed(0, 10);
	m_currentState.thumbstickRightClick = sf::Joystick::isButtonPressed(0, 11);

	m_currentState.playStationButton = sf::Joystick::isButtonPressed(0, 12);
	m_currentState.touchPad = sf::Joystick::isButtonPressed(0, 13);
}

/// <summary>
/// Assigns values for the thumbsticks
/// </summary>
void PS4Controller::checkThumbsticks()
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
void PS4Controller::checkDPad()
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
void PS4Controller::checkTriggers()
{
	m_currentState.triggerLeftPressed = sf::Joystick::isButtonPressed(0, 6);
	m_currentState.triggerRightPressed = sf::Joystick::isButtonPressed(0, 7);

	m_currentState.triggerLeft = sf::Joystick::Axis::V;
	m_currentState.triggerRight = sf::Joystick::Axis::U;
}