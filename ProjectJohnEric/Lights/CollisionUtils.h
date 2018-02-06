#ifndef COLLISION_UTILS
#define COLLISION_UTILS

#include <SFML\System\Vector2.hpp>

namespace col_utils {
	bool lineLineCollision(float x1 , float y1, float x2,float y2, float x3, float y3, float x4, float y4 );
	sf::Vector2f lineLineIntersectionPoints(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
}

#endif //!COLLISION_UTILS
