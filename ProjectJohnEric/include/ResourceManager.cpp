#include "ResourceManager.h"
#include <iostream>

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::addTexture(std::string id, std::string filepath)
{
	try {
		m_textureHolder.acquire(id, thor::Resources::fromFile<sf::Texture>(filepath));
	}
	catch(thor::ResourceLoadingException& e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (...) {
		std::cout << "Error: Unknown Exception occured" << std::endl;
	}
}

sf::Texture & ResourceManager::getTexture(std::string id)
{
	return m_textureHolder[id];
}
