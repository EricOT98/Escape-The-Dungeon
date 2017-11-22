#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML/Graphics.hpp>

/// <summary>
/// @author John O' Meara
/// @date Feb 2017
/// @version 1,0
/// </summary>

/// <summary>
/// data to store the current state of the controller
/// </summary>
struct GamePadState
{
	// Coloured Buttons
	bool buttonA;
	bool buttonB;
	bool buttonX;
	bool buttonY;

	bool buttonCross;
	bool buttonSquare;
	bool buttonTriangle;
	bool buttonCircle;

	// Bumpers
	bool bumperLeft;
	bool bumperRight;

	// Start/Back
	bool Back;
	bool Start;

	// Thumbsticks
	bool thumbstickLeftClick;
	bool thumbstickRightClick;

	sf::Vector2f thumbstickLeft;
	sf::Vector2f thumbstickRight;

	float leftAngleRAD;
	float rightAngleRAD;

	float leftAngleDEG;
	float rightAngleDEG;

	// D-Pad
	bool dpadUp;
	bool dpadDown;
	bool dpadLeft;
	bool dpadRight;

	// Triggers
	float triggerLeft;
	float triggerRight;
};

// Easy list to assign names to buttons
const std::string m_buttonNames[] =
{
	"A",
	"B",
	"X",
	"Y",

	"LB",
	"RB",

	"Back",
	"Start",

	"L",
	"R"
};

/// <summary>
/// Xbox controller class to query current state of controller
/// to mimic the controller states like XNA
/// </summary>
class Xbox360Controller
{
private:
	// Deadzone for the dpad
	const int dpadThreshold = 50;

	// index of last pressed button
	int m_lastPressed = -1;

public:
	// index count for multiple controllers if connected
	int sf_Joystick_index;
	// The current state of all the buttons
	GamePadState m_currentState;
	// The previous state to use th echeck for the moment a button is pressed
	GamePadState m_previousState;

	Xbox360Controller();
	~Xbox360Controller();

	void Xbox360Controller::update();

	//returns true/false
	bool isConnected();

	//goes through index and returns true if it finds available one
	bool connect();

	//finds out which button was pressed
	void checkButtons();

	//Gets information about thumbsticks
	void checkThumbsticks();

	//Gets information about D-Pad
	void checkDPad();

	//Gets information about triggers
	void checkTriggers();
};


#endif // !XBOX360CONTROLLER