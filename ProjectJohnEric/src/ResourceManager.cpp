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
		fontHolder.acquire("UIFont", thor::Resources::fromFile<sf::Font>("ASSETS/FONTS/unispace bd.ttf"));

		textureHolder.acquire("Player", thor::Resources::fromFile<sf::Texture>("ASSETS/IMAGES/player.png"));
		textureHolder.acquire("MainMenu", thor::Resources::fromFile<sf::Texture>("ASSETS/IMAGES/MainMenu.jpg"));
		textureHolder.acquire("Button", thor::Resources::fromFile<sf::Texture>("ASSETS/IMAGES/button.jpg"));
		textureHolder.acquire("Sliderbar", thor::Resources::fromFile<sf::Texture>("ASSETS/IMAGES/sliderbar.png"));
		textureHolder.acquire("Slidertab", thor::Resources::fromFile<sf::Texture>("ASSETS/IMAGES/slidertab.png"));

		soundHolder.acquire("Walking", thor::Resources::fromFile<sf::SoundBuffer>("ASSETS/SOUNDS/footstepsFadeFast.wav"));
		soundHolder.acquire("ButtonClick", thor::Resources::fromFile<sf::SoundBuffer>("ASSETS/SOUNDS/UI/switch7.wav"));
		soundHolder.acquire("SliderToggle", thor::Resources::fromFile<sf::SoundBuffer>("ASSETS/SOUNDS/UI/switch13.wav"));
		soundHolder.acquire("Switch", thor::Resources::fromFile<sf::SoundBuffer>("ASSETS/SOUNDS/UI/switch9.wav"));
		soundHolder.acquire("Error", thor::Resources::fromFile<sf::SoundBuffer>("ASSETS/SOUNDS/UI/error.wav"));
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
