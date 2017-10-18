#ifndef KEYBOARD_HANDLER
#define KEYBOARD_HANDLER

#include <SFML\Window\Keyboard.hpp>

using namespace std;

class KeyboardHandler
{
private:
	KeyboardHandler();//used to make it singleton

public:

	bool m_keysDown[sf::Keyboard::KeyCount];
	bool m_keysUp[sf::Keyboard::KeyCount];

	static KeyboardHandler *GetInstance();
	bool KeyPressed(int key);
	bool KeyDown(int key);
};
#endif //!KEYBOARD_HANDLER