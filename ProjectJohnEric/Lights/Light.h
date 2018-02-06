#ifndef LIGHT
#define LIGHT


#include <SFML/Graphics.hpp>
class Light

{

public:
	Light()

		: color(255, 255, 255),endColor(255,255,255,0), radius(0), angleSpread(0), position(0, 0), angle(0), dynamic(true)
	{
	}

	sf::Vector2f position; //position of the light

	sf::Color color; //light color
	sf::Color endColor; //The endColor for the light to match

	float radius; //how far the light will shine to

	float angleSpread; //spread of the light, creating an arc

	float angle; //where the light's pointing at

	bool dynamic; //can this change?

};
#endif LIGHT