/// <summary>
///
/// </summary>

#ifndef LIGHT_ENGINE
#define LIGHT_ENGINE

#include "Light.h"
#include "Block.h"
#include <vector>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

class LightEngine

{

public:
	void init();
	void Step(sf::RenderTarget &rt);

	std::vector <Light*> Lights; //Container for Lights



	std::vector <Block*> Blocks; //Container for Blocks
	sf::ConvexShape lightShape;
	sf::Texture m_tex;
private:

	void ShineLight(Light *lig, sf::RenderTarget &rt);



	static const float DistanceSqr(const sf::Vector2f &p1, const sf::Vector2f &p2);
	static const float Distance(const sf::Vector2f &p1, const sf::Vector2f &p2);

	static const sf::Vector2f GetCenter(const sf::FloatRect &fr); //Get the center of a rectangle





	struct FindDistance //Check for multiple intersections

	{

		FindDistance();

		float shortest;

		bool LightHitsBlock(Light &l, Block &b, const float cur_ang, float &reflength);

		bool start; //to get the first distance to refer off of

	};



	FindDistance findDis;
};
#endif
