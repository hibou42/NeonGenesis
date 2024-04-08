#include "SceneStart.hpp"
#include "SceneGame.hpp"
#include <iostream>

SceneGame::SceneGame() : sfmlManager(nullptr), _gameplay(*new Easy()) {}

SceneGame::SceneGame(SFMLManager* manager) : sfmlManager(manager), _gameplay(*new Easy()) {
	// Initialisation des formes et du texte ici
	this->_text = sf::Text();
	this->_circle = sf::CircleShape();
	this->_rect = sf::RectangleShape();
	this->_woodSprite = sf::Sprite();
}

SceneGame::~SceneGame() {
	std::cout << "SceneGame destroyed" << std::endl;
	delete &_gameplay;
}

void SceneGame::handleEvent(const sf::Event& event) {
	//event p1
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
		_gameplay.goWood(_gameplay._p1, _gameplay._wood);
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
		_gameplay.backWood(_gameplay._p1, _gameplay._wood);
	}

	//event p2
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
		_gameplay.goWood(_gameplay._p2, _gameplay._wood);
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
		_gameplay.backWood(_gameplay._p2, _gameplay._wood);
	}
}

void SceneGame::onUpdate(float deltaTime) {
	// Logique de mise à jour de la scène ici
}

void SceneGame::onDraw(sf::RenderWindow& window) {
	window.clear();

	sf::Texture texture;
	if (!texture.loadFromFile("sprite/tree.png")) {
		std::cout << "Error loading image!" << std::endl;
		return;
	}
	this->_woodSprite.setTexture(texture);
	this->_woodSprite.setPosition(220, 100);
	this->_woodSprite.setScale(0.8f, 0.8f);
	window.draw(_woodSprite);

	sf::Font font_digital;
	if (!font_digital.loadFromFile("font/digital-7.ttf")) {
		std::cout << "Error loading font!" << std::endl;
		return;
	}

	sf::Font font_lemon;
	if (!font_lemon.loadFromFile("font/LEMONMILK-Light.otf")) {
		std::cout << "Error loading font!" << std::endl;
		return;
	}
	this->_text.setFont(font_lemon);
	this->_text.setFillColor(sf::Color::White);

	std::string str = "TEST GAME";
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(325, 5);
	window.draw(_text);

	str = "Q = goWood, E = bkWood for P1 / I = goWood, P = bkWood for P2";
	this->_text.setCharacterSize(20);
	this->_text.setString(str);
	this->_text.setPosition(20, 60);
	window.draw(_text);

	str = "nb gens p1 = " + std::to_string(_gameplay._p1.getGens());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(5, 500);
	window.draw(_text);

	str = "nb gens p2 = " + std::to_string(_gameplay._p2.getGens());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(500, 500);
	window.draw(_text);

	str = std::to_string(_gameplay._wood.getGensP1());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(300, 400);
	window.draw(_text);

	str = std::to_string(_gameplay._wood.getGensP2());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(475, 400);
	window.draw(_text);

	window.display();
}
