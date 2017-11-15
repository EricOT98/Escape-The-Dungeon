#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <SFML\Graphics.hpp>
class Object {
public:
	Object(sf::Vector2f pos, sf::FloatRect rec, bool visible, bool trigger);

	void update();
	void render(sf::RenderWindow & window);

	sf::Vector2f getSize();
	sf::Vector2f getPosition();

protected:
	sf::Vector2f m_position;
	sf::FloatRect m_aabb;
	sf::RectangleShape m_rect;
	bool m_isTrigger;
	bool m_isVisible;
	enum class ObjectType {
		STATIC,
		DYNAMIC,
		TRIGGER
	};
};
#endif //!OBJECT_H