#include "ResourceManager.hpp"

sf::Font& ResourceManager::getFont() {
	static sf::Font font;
	static bool loaded = false;
	if (!loaded) {
		if (!font.loadFromFile("font/digital-7.ttf")) {
			std::cerr << "Error loading font!" << std::endl;
		}
		loaded = true;
	}
	return font;
}