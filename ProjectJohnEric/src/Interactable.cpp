#include "Interactable.h"

#include <iostream>

//Interactable::Interactable(sf::Texture * tex, int x, int y, int tx, int ty, int w, int h, int gid, int layer)
//	: Tile(tex,x,y,tx,ty,w,h,gid,layer),
//	m_active(true)
//{
//	
//
//}
//
//void Interactable::interact()
//{
//	if (m_active) {
//		m_active = false;
//		std::cout << "PICKUP";
//	}
//}
//
//void Interactable::setActive(bool active)
//{
//	m_active = active;
//}
//
//
//Door::Door(sf::Texture * tex, int x, int y, int tx, int ty, int w, int h, int gid, int layer)
//	: Interactable(tex, x, y, tx, ty, w, h, gid, layer)
//{
//
//}
//
//bool Door::enter()
//{
//	return false;
//}