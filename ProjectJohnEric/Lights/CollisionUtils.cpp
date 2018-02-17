#include "CollisionUtils.h"
#include <iostream>

bool col_utils::lineLineCollision(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	//Calculate the distance between 2 lines point of intersection
	float ua1 = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3));
	float ua2 = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));
	
	float uA =  0;
	if (ua1 != 0 && ua2 != 0) {
		uA = ua1 / ua2;
	}

	float ub1 = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3));
	float ub2 = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y2));
	float uB = 0;

	if (ub1 != 0 && ub2 != 0) {
		uB = ub1 / ub2;
	}
	//if uA and uB withtin range (0, 1) collision
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1)
		return true;
	return false;
}

sf::Vector2f col_utils::lineLineIntersectionPoints(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	//Calculate the distance between 2 lines point of intersection
	float ua1 = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3));
	float ua2 = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y1));

	float uA = 0;
	if (ua1 != 0 && ua2 != 0) {
		uA = ua1 / ua2;
	}

	float ub1 = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3));
	float ub2 = ((y4 - y3) * (x2 - x1) - (x4 - x3) * (y2 - y2));
	float uB = 0;

	if (ub1 != 0 && ub2 != 0) {
		uB = ub1 / ub2;
	}
	//if uA and uB withtin range (0, 1) collision
	if (uA >= 0 && uA <= 1 && uB >= 0 && uB <= 1) {
		float iX = x1 + (uA * (x2 - x1));
		float iY = y1 + (uA * (y2 - y1));
		return sf::Vector2f(iX, iY);
	}	
	return sf::Vector2f();
}

bool col_utils::pointInAABB(float px, float py, float bx, float by, float bw, float bh)
{
	return !(px < bx || px > bx + bw ||
		py < by || py > by + bh);
}

bool col_utils::pointInSector(float px, float py, float centerX, float centerY, float startAngle, float endAngle, float radius)
{
	float angle = atan2( py - centerY, px - centerX ) * (180 / acos(-1));
	float distSqr = (((px - centerX) * (px - centerX)) + ((py - centerY) * (py - centerY)));
	
	return (distSqr < radius * radius && distSqr > 0 &&  angle > startAngle && angle < endAngle);
}
