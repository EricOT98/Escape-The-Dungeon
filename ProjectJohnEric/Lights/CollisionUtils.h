#ifndef COLLISION_UTILS
#define COLLISION_UTILS

#include <SFML\System\Vector2.hpp>

namespace col_utils {
	bool lineLineCollision(float x1 , float y1, float x2,float y2, float x3, float y3, float x4, float y4 );
	sf::Vector2f lineLineIntersectionPoints(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
	bool pointInAABB(float px, float py, float bx, float by, float bw, float bh);
	bool pointInSector(float px, float py, float centerX, float centerY, float startAngle, float endAngle, float radius);
	bool pointInCircle(float px, float py, float cx, float cy, float radius);
}

#endif //!COLLISION_UTILS
