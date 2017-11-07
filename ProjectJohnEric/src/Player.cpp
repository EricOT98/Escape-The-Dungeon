#include "Player.h"

/// <summary>
/// Default player constructor
/// </summary>
Player::Player()
	: Character()
{
}

/// <summary>
/// Player constructor that sets a name
/// </summary>
/// <param name="name">Name of the character for testing</param>
Player::Player(string name)
	: Character(name)
{

}

void Player::update(sf::RenderWindow &window, Xbox360Controller & controller)
{
	if (KeyboardHandler::GetInstance()->KeyPressed(sf::Keyboard::Space))
	{
		if (m_usingMouse)
		{
			m_usingMouse = false;
			m_rect.setFillColor(sf::Color::Red);
		}
		else
		{
			m_usingMouse = true;
			m_rect.setFillColor(sf::Color::Green);
		}
	}


#pragma region MOVEMENT_LOGIC
	m_direction = sf::Vector2f(0, 0);

	// The moving bool won't work 100%. If two opposite keys (eg, up and down) are
	// being held at the same time, the player won't move but his speed will be
	// accelerating. Worth fixing?
	m_moving = false;

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::A))
	{
		m_direction.x += -1;
		m_moving = true;
	}
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::D))
	{
		m_direction.x += 1;
		m_moving = true;
	}
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::W))
	{
		m_direction.y += -1;
		m_moving = true;
	}
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::S))
	{
		m_direction.y += 1;
		m_moving = true;
	}

	if (controller.m_currentState.thumbstickLeft.x >= 20) {
		m_direction.x -= -1;
		m_moving = true;
	}
	else if (controller.m_currentState.thumbstickLeft.x <= -20) {
		m_direction.x += -1;
		m_moving = true;
	}

	if (controller.m_currentState.thumbstickLeft.y >= 20) {
		
		m_direction.y -= -1;
		m_moving = true;
	}
	else if (controller.m_currentState.thumbstickLeft.y <= -20) {
		m_direction.y += -1;
		m_moving = true;
	}

	move();

#pragma endregion

#pragma region ROTATION_LOGIC

	if (m_usingMouse)
	{
		sf::Vector2f mouse = sf::Vector2f(sf::Mouse::getPosition(window));
		//m_direction = sf::Vector2f(sf::Mouse::getPosition());
		//m_rotation = std::atan2((sf::Mouse::getPosition(window).x - m_position.x), (sf::Mouse::getPosition(window).y - m_position.y)) * ((180 / acos(-1)) - 90);

		//double n1 = sqrt(m_position.x*m_position.x + m_position.y*m_position.y);
		//double n2 = sqrt(mouse.x*mouse.x + mouse.y*mouse.y);
		//m_rotation = acos((m_position.x*mouse.x + m_position.y*mouse.y / (n1*n2)) * (180 / acos(-1)) - 90);

		float dot = m_position.x*mouse.x + m_position.y*mouse.y;
		float det = m_position.x*mouse.y - m_position.y*mouse.x;
		m_rotation = atan2(det, dot) * (180 / acos(-1)) - 90;
	}
	
	else
	{
		if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Left))
		{
			m_rotation += m_spinSpeed;
			if (m_rotation >= 360)
				m_rotation -= 360;
		}
		if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::Right))
		{
			m_rotation -= m_spinSpeed;
			if (m_rotation < 0)
				m_rotation += 360;
		}

		m_rotation =controller.m_currentState.rightAngleDEG;
		//cout << m_rotation << endl;
		//cout << controller.m_currentState.thumbstickRight.x << ", " << controller.m_currentState.thumbstickRight.y << endl;
	}
	

#pragma endregion


#pragma region UPDATE_DEBUG
	//cout << "(" << m_position.x << "," << m_position.y << ")" << endl;
	//cout << "(" << sf::Mouse::getPosition(window).x << "," << sf::Mouse::getPosition(window).y << ")" << endl;
	//cout << m_moveSpeed << endl;
	//cout << m_rotation << endl;
#pragma endregion

}
