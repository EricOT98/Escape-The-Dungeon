#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>

class Animation
{
public:
	//Animation();
	Animation(std::string name, sf::Sprite & sprite);

	void update(float dt);
	void render(sf::RenderTarget & targ);

	void addFrame(sf::IntRect frame, int row = 0, int col = 0);
	void segmentTexture(unsigned int rows, unsigned int cols);

	sf::IntRect getCurrentFrame();
	void setStartFrame();
	void loop(bool loop);
	bool getLooping();

	void play();
	void pause();
	void stop();

	int m_frameWidth;
	int m_frameHeight;
	float m_timePerFrame;
	sf::Vector2i m_frameCount;
	sf::Sprite & m_sprite;
	std::string m_name;
protected:
	std::vector<sf::IntRect> m_frames;

	sf::Vector2i m_currentFrame;
	sf::Vector2i m_startFrame;
	bool m_looping;
	bool m_playing;
	bool m_paused;
	float m_currentTime;
};

//class AnimationFunctor
//{
//	sf::Vector2i m_frame;
//
//public:
//	bool operator<(sf::Vector2i f) {
//		return (m_frame.x < f.x && m_frame.y < f.y);
//	}
//};

#endif !ANIMATION_H
