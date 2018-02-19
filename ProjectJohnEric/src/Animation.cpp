#include "Animation.h"

//Animation::Animation()
//{
//	m_startFrame.x = 0;
//	m_startFrame.y = 0;
//	m_currentFrame.x = 0; 
//	m_currentFrame.y = 0;
//
//	m_playing = false;
//	m_paused = false;
//	m_looping = false;
//}

Animation::Animation(std::string name, sf::Sprite & sprite) :
	m_name(name),
	m_sprite(sprite)
{
	m_startFrame.x = 0;
	m_startFrame.y = 0;
	m_currentFrame.x = 0;
	m_currentFrame.y = 0;
	m_timePerFrame = 0.1f;
	m_playing = false;
	m_paused = false;
	m_looping = false;
}

void Animation::update(float dt)
{
	if (m_playing) {
		m_currentTime += dt;
		if (m_currentTime >= m_timePerFrame)
		{
			m_currentFrame.x++;
			if(m_currentFrame.x >= m_frameCount.x)
			{
				m_currentFrame.x = m_startFrame.x;
				if (!m_looping)
					m_playing = false;
			}
			m_currentTime = 0;
		}
		m_sprite.setTextureRect(m_frames.at(m_currentFrame.x));
	}
}

void Animation::render(sf::RenderTarget & targ)
{
	targ.draw(m_sprite);
}

void Animation::addFrame(sf::IntRect frame, int row, int col)
{
	m_frames.push_back(frame);
}

void Animation::segmentTexture(unsigned int rows, unsigned int cols)
{
	m_frameWidth = m_sprite.getTexture()->getSize().x / cols;
	m_frameHeight = m_sprite.getTexture()->getSize().x / rows;
	for ( int row = 0; row < rows; row++)
	{
		for ( int col = 0; col < cols; col++)
		{
			addFrame(sf::IntRect(col * m_frameWidth, row * m_frameHeight, m_frameWidth, m_frameHeight));
		}
	}
	m_frameCount.x = cols;
	m_frameCount.y = rows;
}

sf::IntRect Animation::getCurrentFrame()
{
	return m_frames.at(m_frameCount.x);
}

void Animation::setStartFrame()
{
}

void Animation::loop(bool loop)
{
	m_looping = true;
}

bool Animation::getLooping()
{
	return m_looping;
}

void Animation::play()
{
	m_playing = true;
}

void Animation::pause()
{
	m_paused = true;
	m_playing = false;
}

void Animation::stop()
{
	m_playing = false;
	m_paused = false;
}
