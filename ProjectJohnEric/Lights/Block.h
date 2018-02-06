//Block.h

#ifndef BLOCK//don't allow this header to be included more than once
#define BLOCK
#include <SFML/Graphics.hpp>

class Block
{

public:
	Block();
	void setAllowed(bool allowed);
	void render(sf::RenderWindow & window);
	void setSize(sf::Vector2f size);
	void setPosition(sf::Vector2f pos);
	sf::FloatRect fRect; //Area that will be blocking light
	sf::RectangleShape m_rectShape;
	sf::Color col;
	bool allowBlock; //Sometimes we want to keep a block, but don't want it to actually block until a certain point

};
#endif //!BLOCK