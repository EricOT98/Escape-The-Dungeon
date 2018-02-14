#include "LightEngine.h"
#include "CollisionUtils.h"
#include <iostream>
LightEngine::FindDistance::FindDistance()

{
	start = false;
	shortest = 0;
}



const sf::Vector2f LightEngine::GetCenter(const sf::FloatRect &fr)

{
	return sf::Vector2f(fr.left + (fr.width / 2), fr.top + (fr.height / 2));
}



const float LightEngine::Distance(const sf::Vector2f &p1, const sf::Vector2f &p2)

{
	float a = p2.x - p1.x;  //width length

	float b = p2.y - p1.y; //height length

	float c = sqrt((a * a) + (b * b)); //Pythagorean Theorem. (c� = a� + b�). c = squareroot(a� + b�)

	return c;
}



void LightEngine::init()
{
	lightShape.setTexture(&g_resourceManager.textureHolder["Light"]);
}

void LightEngine::Step(sf::RenderTarget &rt)

{
	for (unsigned i = 0; i < Lights.size(); i++)
	{
		ShineLight(Lights[i], rt); //Shine all lights
	}

}
void LightEngine::ShineLight(Light *l, sf::RenderTarget &rt)

{
	float current_angle = l->angle - (l->angleSpread / 2); //This will rotate the angle back far enough to get a desired arc /* Lights Angle (if it was at 0):-------------Current_Angle: ///(slanted)*/

	float dyn_len = l->radius; //dynamic length of the light. This will be changed in the function LightHitsBlock()

	float addto = 1.f / l->radius;

	//TODO: ERIC better version of this maybe using triangels??
	
	uint16_t points = 1;
	std::vector<sf::Vector2f> shapePoints;
	shapePoints.push_back(l->position);
	int count = 0;
	for (current_angle; current_angle < l->angle + (l->angleSpread / 2); current_angle += addto * (180.f / 3.14f)) //we need to add to the current angle, until it reaches the end of the arc. we divide 1.f by radius for a more solid shape. Otherwize you could see lines seperating

	{
		dyn_len = l->radius; //Reset the length

		findDis.start = true; //Start of finding a light, we need to reset

		findDis.shortest = 0; //Reset the shortest.

		if (l->dynamic) //can this change?

		{
			for (unsigned i = 0; i < Blocks.size(); i++)
			{
				findDis.LightHitsBlock(*l, *Blocks[i], current_angle, dyn_len);
			}

		}
		float radians = current_angle * (3.14f / 180); //Convert to radians for trig functions



		sf::Vector2f end = l->position;

		end.x += cos(radians) * dyn_len;

		end.y += sin(radians) * dyn_len;
		/*if (count == 0) {
			std::cout << "Line o end point: " << end.x << ", " << end.y << std::endl;
		}*/
		sf::Vertex line[] =
		{
			sf::Vertex(l->position, l->color),
			sf::Vertex(end, l->endColor)
		};

		/*rt.draw(line, 2, sf::Lines);*/
		count++;
		//TODO: ERIC better version of this maybe using triangels??
		shapePoints.push_back(end);
		points++;
	}
	//TODO: ERIC better version of this maybe using triangels??
	lightShape.setPointCount(points);
	for (int i = 0; i < points; i++) {
		lightShape.setPoint(i, shapePoints.at(i));
	}
	lightShape.setFillColor(sf::Color(174, 146, 9, 128));
	
	rt.draw(lightShape);
}

bool LightEngine::FindDistance::LightHitsBlock(Light &l, Block &b, float cur_ang, float &refleng)

{

	if (b.allowBlock) //can this even block?

	{
		//sf::Vector2f wallCorners[4];
		////TL
		//wallCorners[0] = sf::Vector2f(b.fRect.left, b.fRect.top);
		////TR
		//wallCorners[1] = sf::Vector2f(b.fRect.left + b.fRect.width, b.fRect.top);
		////BL
		//wallCorners[2] = sf::Vector2f(b.fRect.left, b.fRect.top + b.fRect.top);
		////BR
		//wallCorners[3] = sf::Vector2f(b.fRect.left + b.fRect.width, b.fRect.top + b.fRect.top);
		//
		//
		////Get shortest distance to wall
		//for (int i = 0; i < 4; i++) {
		//	float currDist = Distance(l.position, wallCorners[i]);
		//	if (currDist < distance) {
		//		distance = currDist;
		//	}
		//}

		float distance = Distance(l.position, GetCenter(b.fRect));

		if (l.radius >= distance) //check if it's radius is even long enough to hit a block
		{

			float radians = cur_ang * (3.14f / 180); //convert cur_ang to radians for trig functions
			sf::Vector2f pointpos = l.position;

			pointpos.x += cos(radians) * distance;

			pointpos.y += sin(radians) * distance;

			//By doing this, we check if the angle is in the direciton of the block.

			sf::FloatRect tempRect = sf::FloatRect(b.fRect.left, b.fRect.top, b.fRect.width, b.fRect.height);

			if (col_utils::pointInAABB(pointpos.x, pointpos.y, b.fRect.left, b.fRect.top, b.fRect.width, b.fRect.height)) //If it was, than the point would be intersecting the rectangle of the block
			{
				std::cout << "Point in rect" << std::endl;
				sf::Vector2f walls[4];
				bool collided = false;
				//TL Vect TR Vect - TOP
				walls[0] = col_utils::lineLineIntersectionPoints(
					b.fRect.left, b.fRect.top, b.fRect.left + b.fRect.width, b.fRect.top, l.position.x, l.position.y, pointpos.x, pointpos.y);

				//TL Vect // BL vect - LEFT
				walls[1] = col_utils::lineLineIntersectionPoints(
					b.fRect.left, b.fRect.top, b.fRect.left, b.fRect.top + b.fRect.height, l.position.x, l.position.y, pointpos.x, pointpos.y);

				//TR vect BR vect - RIGHT
				walls[2] = col_utils::lineLineIntersectionPoints(
					b.fRect.left + b.fRect.width, b.fRect.top, b.fRect.left + b.fRect.width, b.fRect.top + b.fRect.height, l.position.x, l.position.y, pointpos.x, pointpos.y);

				//BL vect BR vect - BOTTOM
				walls[3] = col_utils::lineLineIntersectionPoints(
					b.fRect.left, b.fRect.top + b.fRect.height, b.fRect.left + b.fRect.width, b.fRect.top + b.fRect.height, l.position.x, l.position.y, pointpos.x, pointpos.y);

				float shortestDistance = Distance(l.position, walls[0]);
				sf::Vector2f currentPos;
				for (int i = 1; i < 4; i++) {
					//Temp check to stop all points going back to origin
					if (walls[i].x != 0 && walls[i].y != 0) {
						float currDistance = Distance(l.position, walls[i]);
						if (currDistance < shortestDistance) {
							shortestDistance = currDistance;
						}
					}
				}
				distance = shortestDistance;
				//std::cout << "Point in square" << std::endl;
				if (start || distance < shortest) //If this is the first block, or it has a shorter distance
				{
					start = false; //definately not the start so other blocks can't automatically set the distance
					shortest = distance; //shortest is set to this
					refleng = shortest; //This is where the dynamic comes in, it changes the length of the reference towhere it's going to stop after it hits the distance from the point to the block
				}
				return true;
			}
		}
	}
	return false;
}
