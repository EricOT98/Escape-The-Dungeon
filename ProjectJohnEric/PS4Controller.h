#ifndef PS4CONTROLLER
#define PS4CONTROLLER

#include <SFML/Graphics.hpp>

/// <summary>
/// @author John O' Meara
/// @date NOV 2017
/// </summary>

/// <summary>
/// data to store the current state of the controller
/// </summary>
struct GamePadState
{
	// Face Buttons
	bool buttonSquare;		// 0
	bool buttonCross;		// 1
	bool buttonCircle;		// 2
	bool buttonTriangle;	// 3

	// Bumpers
	bool bumperLeft;	// 4
	bool bumperRight;	// 5

	// Share/Options
	bool share;		// 8
	bool options;	// 9

	// Thumbsticks
	bool thumbstickLeftClick;	// 10
	bool thumbstickRightClick;	// 11

	// PlayStation Specific
	bool playStationButton;	//12
	bool touchPad;			// 13

	sf::Vector2f thumbstickLeft;	// (X, Y)
	sf::Vector2f thumbstickRight;	// (Z, R)

	float leftAngleRAD;
	float rightAngleRAD;

	float leftAngleDEG;
	float rightAngleDEG;

	// D-Pad
	bool dpadUp;	// -100 <= PovX < 0
	bool dpadDown;	// -100 <= PovY < 0
	bool dpadLeft;	// 0 < PovX <= +100
	bool dpadRight;	// 0 < PovY <= +100

	// Triggers
	bool triggerLeftPressed;	// 6
	bool triggerRightPressed;	// 7
	float triggerLeft;			// V-axis
	float triggerRight;			// U-axis
};

// Easy list to assign names to buttons
const std::string m_buttonNames[] =
{
	"SQUARE",	// 0
	"CROSS",	// 1
	"CIRCLE",	// 2
	"TRIANGLE",	// 3
	"L1",		// 4
	"R1",		// 5
	"L2",		// 6 
	"R2",		// 7
	"SHARE",	// 8
	"OPTIONS",	// 9
	"L3",		// 10
	"R3",		// 11
	"PSBUTTON", // 12
	"TOUCHPAD"  // 13
};

/// <summary>
/// Xbox controller class to query current state of controller
/// to mimic the controller states like XNA
/// </summary>
class PS4Controller
{
private:
	// Deadzone for the dpad
	const int dpadThreshold = 50;

	// Controller image
	sf::Texture m_ControllerImage;

	// index of last pressed button
	int m_lastPressed = -1;

public:
	// index count for multiple controllers if connected
	int sf_Joystick_index;
	// The current state of all the buttons
	GamePadState m_currentState;
	// The previous state to use th echeck for the moment a button is pressed
	GamePadState m_previousState;

	PS4Controller();
	~PS4Controller();

	void PS4Controller::update();

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


#endif // !PS4CONTROLLER