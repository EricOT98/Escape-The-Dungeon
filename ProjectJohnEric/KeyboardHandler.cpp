#include "KeyboardHandler.h"

/// <summary>
/// Default all key presses to false.
/// </summary>
KeyboardHandler::KeyboardHandler()
{
	for (bool &keyDown : m_keysDown)
		keyDown = false;

	for (bool &keyUp : m_keysUp)
		keyUp = false;
}

/// <summary>
/// Return a pointer to a new keyboard object
/// </summary>
/// <returns>a pointer to a static keyboard object</returns>
KeyboardHandler *KeyboardHandler::GetInstance()
{
	static KeyboardHandler *instance = new KeyboardHandler();
	return instance;
}

/// <summary>
/// returns if the key is down and not up
/// </summary>
/// <param name="key"></param>
/// <returns>boolean for key pressed</returns>
bool KeyboardHandler::KeyPressed(int key)
{
	if (m_keysDown[key] && !m_keysUp[key])
	{
		m_keysUp[key] = true;
		return true;
	}

	return false;
}

/// <summary>
/// Returns if the key is being held down
/// </summary>
/// <param name="key"></param>
/// <returns>boolean for key held</returns>
bool KeyboardHandler::KeyDown(int key)
{
	if (m_keysDown[key])
	{
		return true;
	}

	return false;
}