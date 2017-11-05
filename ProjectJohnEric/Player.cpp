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

void Player::update()
{
	// TODO: REFACTOR ALL THIS INTO CLASSES WHEN WORKED OUT FULLY

#pragma region MOVEMENT_LOGIC
	m_direction = sf::Vector2f(0, 0);

	// The moving bool won't work 100%. If two opposite keys (eg, up and down) are
	// being held at the same time, the player won't move but his speed will be
	// accelerating. Worth fixing?
	bool moving = false;

	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::A))
	{
		m_direction.x += -1;
		moving = true;
	}
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::D))
	{
		m_direction.x += 1;
		moving = true;
	}
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::W))
	{
		m_direction.y += -1;
		moving = true;
	}
	if (KeyboardHandler::GetInstance()->KeyDown(sf::Keyboard::S))
	{
		m_direction.y += 1;
		moving = true;
	}

	// should this be a method in the parent class?
	if (moving && m_moveSpeed < m_maxSpeed)
	{
		m_moveSpeed += m_acceleration;
		if (m_moveSpeed > m_maxSpeed)
			m_moveSpeed = m_maxSpeed;
	}
	else if (!moving && m_moveSpeed > 0)
	{
		m_moveSpeed -= m_acceleration;
		if (m_moveSpeed < 0)
			m_moveSpeed = 0;
	}
	
	m_position += m_direction * m_moveSpeed;

#pragma endregion

#pragma region ROTATION_LOGIC

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

#pragma endregion

#pragma region UPDATE_DEBUG
	cout << "(" << m_position.x << "," << m_position.y << ")" << endl;
	cout << m_moveSpeed << endl;
	cout << m_rotation << endl;
#pragma endregion
}
