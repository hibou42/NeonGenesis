#include <SFML/Graphics.hpp>
#include "SFMLManager.hpp"
#include "SceneStart.hpp"
#include <nlohmann/json.hpp>
#include "DisplaySettings.hpp"
#include <iostream>


int main() {
	std::cout << "Let's start !" << std::endl;
	DisplaySettings settings = DisplaySettings::loadSettingsFromJson("display_settings.json");
	std::cout << "Width: " << settings.width << std::endl;
	std::cout << "Height: " << settings.height << std::endl;
	std::cout << "Fullscreen: " << std::boolalpha << settings.fullscreen << std::endl;
	std::cout << "Borderless: " << std::boolalpha << settings.borderless << std::endl;
	// sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

	sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
    std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl;
    sf::String controller("Joystick Use: " + id.name);
	std::cout << "Controller: " << controller.toAnsiString() << std::endl;

	sf::RenderWindow window(sf::VideoMode(settings.width, settings.height), "SFML Game", sf::Style::Default | sf::Style::None);
	window.setFramerateLimit(120);

	SFMLManager sceneManager;
	sceneManager.pushScene(std::make_unique<SceneStart>(&sceneManager));
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			sceneManager.handleEvent(event);
		}

		sceneManager.handleEvent(event);
		sceneManager.onUpdate(0.016f); 
		window.clear();
		sceneManager.onDraw(window);
		window.display();
	}

	std::cout << "Bye!" << std::endl;
	return 0;
}
