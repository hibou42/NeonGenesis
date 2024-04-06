#include "SceneStart.hpp"
#include "SceneGame.hpp"
#include <iostream>

SceneGame::SceneGame() : sfmlManager(nullptr) {}

SceneGame::SceneGame(SFMLManager* manager) : sfmlManager(manager) {
    // Initialisation des formes et du texte ici

    this->_text = sf::Text();
    this->_circle = sf::CircleShape();
    this->_rect = sf::RectangleShape();
}

SceneGame::~SceneGame() {}

void SceneGame::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
        // Transition vers la prochaine scène (exemple: SceneGame)
        // sfmlManager->pushScene(std::make_unique<SceneGame>());
    }
}

void SceneGame::onUpdate(float deltaTime) {
    // Logique de mise à jour de la scène ici
}

void SceneGame::onDraw(sf::RenderWindow& window) {
    window.clear();

	sf::Font font;
	if (!font.loadFromFile("font/digital-7.ttf")) {
		std::cout << "Error loading font!" << std::endl;
		return;
	}

	std::string str = "TEST GAME";

	this->_text.setFont(font);
    this->_text.setString(str);
    this->_text.setCharacterSize(50);
    this->_text.setPosition(100, 100);
    this->_text.setFillColor(sf::Color::Green);
    // Crée un cercle

    this->_circle.setFillColor(sf::Color::Red);
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