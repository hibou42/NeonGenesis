#include "SceneMenuSettings.hpp"
#include "SceneGame.hpp"
#include "SceneMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


SceneMenu::SceneMenu() : sfmlManager(nullptr){}

SceneMenu::SceneMenu(SFMLManager* manager) : sfmlManager(manager){

    this->_text = sf::Text("Scene Menu", sf::Font(), 50);
    this->_circle = sf::CircleShape(50);
    this->_rect = sf::RectangleShape(sf::Vector2f(100, 100));
}

SceneMenu::~SceneMenu() {}

void SceneMenu::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {

		std::cout << "E pressed" << std::endl;
		if (sfmlManager != nullptr){

        	sfmlManager->pushScene(std::make_unique<SceneGame>(sfmlManager));
		}
		else
			std::cout << "sfmlManager is null" << std::endl;
    }
}

void SceneMenu::onUpdate(float deltaTime) {
    // Logique de mise à jour de la scène ici
	// std::cout << "deltaTime 1: " << deltaTime << std::endl;
}

void SceneMenu::onDraw(sf::RenderWindow& window) {
    window.clear();

    sf::Font font;
    if (!font.loadFromFile("font/digital-7.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return;
    }

    std::string str = "Scene Menu";

    this->_text.setFont(font);
    this->_text.setString(str);
    this->_text.setCharacterSize(50);
    this->_text.setPosition(100, 100);
    this->_text.setFillColor(sf::Color::Red);

    // Crée un cercle
    this->_circle.setFillColor(sf::Color::Green);
    this->_circle.setPosition(200, 200);
    this->_circle.setRadius(50);

    // Crée un rectangle
    this->_rect.setFillColor(sf::Color::Blue);
    this->_rect.setPosition(400, 300);
    this->_rect.setSize(sf::Vector2f(100, 100));

    // Dessiner les formes et le texte ici
    window.draw(_circle);
    window.draw(_rect);
    window.draw(_text);
    window.display();
}