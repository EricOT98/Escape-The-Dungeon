/// <summary>
/// 
/// </summary>

#ifndef LIGHT_ENGINE//don't allow this header to be included more than once
#define LIGHT_ENGINE

#include "Light.h"
#include "Block.h"
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp> //Place to draw on
#include <SFML/Graphics/Shape.hpp> //SFML programmable Shapes

class LightEngine

{

public:

	void Step(sf::RenderTarget &rt);



	std::vector <Light*> Lights; //Container for Lights



	std::vector <Block*> Blocks; //Container for Blocks

private:



	void ShineLight(Light *lig, sf::RenderTarget &rt);



	static const float Distance(const sf::Vector2f &p1, const sf::Vector2f &p2);

	static const sf::Vector2f GetCenter(const sf::FloatRect &fr); //Get the center of a rectangle





	struct FindDistance //if a light's radius manages to intersect multiple blocks, we need to find the sortest distance to shorten the light

	{

		FindDistance();

		float shortest;

		bool LightHitsBlock(Light &l, Block &b, const float cur_ang, float &reflength);

		bool start; //to get the first distance to refer off of

	};



	FindDistance findDis;
};
#endif