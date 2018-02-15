#include "ResourceManager.h"
#include <fstream>

ResourceManager g_resourceManager;

/// <summary>
/// Loads all required assets in game
/// </summary>
void ResourceManager::loadAssets()
{
	try
	{
		std::ifstream fileIDSImages("ASSETS/Resources.txt");

		std::string id, filepath;

		while (fileIDSImages >> id >> filepath) {
			textureHolder.acquire(id, thor::Resources::fromFile<sf::Texture>(filepath));
		}

		fontHolder.acquire("GameFont", thor::Resources::fromFile<sf::Font>("ASSETS/FONTS/FarenheightPers.ttf"));
		soundHolder.acquire("Walking", thor::Resources::fromFile<sf::SoundBuffer>("ASSETS/SOUNDS/footstepsFadeFast.wav"));
	}
	catch (thor::ResourceLoadingException& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//void ResourceManager::loadLevels(std::vector<Level>& levels)
//{
//	for (auto & level : levels) {
//
//	}
//}
