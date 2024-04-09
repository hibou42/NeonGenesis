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

	this->_timeNow = std::chrono::system_clock::now();
	this->_timeNext = _timeNow + std::chrono::seconds(1);
}

SceneGame::~SceneGame() {
	std::cout << "SceneGame destroyed" << std::endl;
	delete &_gameplay;
}

void SceneGame::handleEvent(const sf::Event& event) {
	//event p1
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q) {
		_gameplay.goWood(_gameplay.getP1(), _gameplay.getWood());
		_autoReturnMap.insert(std::make_pair(_timeNow + std::chrono::seconds(3),"p1backwood"));
	}

	//event p2
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
		_gameplay.goWood(_gameplay.getP2(), _gameplay.getWood());
		_autoReturnMap.insert(std::make_pair(_timeNow + std::chrono::seconds(3),"p2backwood"));
	}
}

void SceneGame::onUpdate(float deltaTime) {
	// Logique de mise à jour de la scène ici
	this->_timeNow = std::chrono::system_clock::now();
	if (this->_timeNext <= this->_timeNow) {
		this->_timeNext = this->_timeNow + std::chrono::seconds(1);

		for (auto node = _autoReturnMap.begin(); node != _autoReturnMap.end();) {
			if (node->first < _timeNow) {
				autoReturn(node->second);
				node = _autoReturnMap.erase(node);
			} else {
				node++;
			}
		}
	}
}

void SceneGame::autoReturn(std::string str) {
	if (str == "p1backwood") {
		_gameplay.backWood(_gameplay.getP1(), _gameplay.getWood());
	}
	else if (str == "p2backwood") {
		_gameplay.backWood(_gameplay.getP2(), _gameplay.getWood());
	}
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

	str = "Q = goWood for P1 / P = goWood for P2";
	this->_text.setCharacterSize(20);
	this->_text.setString(str);
	this->_text.setPosition(175, 60);
	window.draw(_text);

	str = "nb gens p1 = " + std::to_string(_gameplay.getP1().getGens());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(5, 500);
	window.draw(_text);

	str = "nb gens p2 = " + std::to_string(_gameplay.getP2().getGens());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(500, 500);
	window.draw(_text);

	str = std::to_string(_gameplay.getWood().getGensP1());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(300, 400);
	window.draw(_text);

	str = std::to_string(_gameplay.getWood().getGensP2());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(475, 400);
	window.draw(_text);

	time_t tempsActuel = std::chrono::system_clock::to_time_t(_timeNow);
	str = std::ctime(&tempsActuel);
	this->_text.setFont(font_digital);
	this->_text.setCharacterSize(20);
	this->_text.setString(str);
	this->_text.setPosition(5, 5);
	window.draw(_text);

	window.display();
}
