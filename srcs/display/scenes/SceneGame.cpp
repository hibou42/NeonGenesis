#include "SceneStart.hpp"
#include "SceneGame.hpp"
#include <iostream>

SceneGame::SceneGame() : sfmlManager(nullptr), _gameplay(*new Easy()) {}

SceneGame::SceneGame(SFMLManager* manager) : sfmlManager(manager), _gameplay(*new Easy()) {
	// Initialisation des formes et du texte ici
	this->_text = sf::Text();
	this->_woodSprite = sf::Sprite();
	this->_waterSprite = sf::Sprite();
	this->_leatherSprite = sf::Sprite();
	this->_metalSprite = sf::Sprite();

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
		if(_gameplay.goWood(_gameplay.getP1(), _gameplay.getWood()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getWood().getCooldown(),"p1backwood"));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W) {
		if(_gameplay.goWater(_gameplay.getP1(), _gameplay.getWater()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getWater().getCooldown(),"p1backwater"));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {
		if(_gameplay.goLeather(_gameplay.getP1(), _gameplay.getLeather()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getLeather().getCooldown(),"p1backleather"));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
		if(_gameplay.goMetal(_gameplay.getP1(), _gameplay.getMetal()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getMetal().getCooldown(),"p1backmetal"));
	}

	//event p2
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::U) {
		if(_gameplay.goWood(_gameplay.getP2(), _gameplay.getWood()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getWood().getCooldown(),"p2backwood"));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I) {
		if(_gameplay.goWater(_gameplay.getP2(), _gameplay.getWater()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getWater().getCooldown(),"p2backwater"));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::O) {
		if(_gameplay.goLeather(_gameplay.getP2(), _gameplay.getLeather()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getLeather().getCooldown(),"p2backleather"));
	}
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
		if(_gameplay.goMetal(_gameplay.getP2(), _gameplay.getMetal()) == true)
			_autoReturnMap.insert(std::make_pair(_timeNow + _gameplay.getMetal().getCooldown(),"p2backmetal"));
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
		_gameplay.getP1().setBackPack("wood", _gameplay.getP1().getItemQuantiy("wood") + 1);
	}
	else if (str == "p2backwood") {
		_gameplay.backWood(_gameplay.getP2(), _gameplay.getWood());
		_gameplay.getP2().setBackPack("wood", _gameplay.getP2().getItemQuantiy("wood") + 1);
	}
	else if (str == "p1backwater") {
		_gameplay.backWater(_gameplay.getP1(), _gameplay.getWater());
		_gameplay.getP1().setBackPack("water", _gameplay.getP1().getItemQuantiy("water") + 1);
	}
	else if (str == "p2backwater") {
		_gameplay.backWater(_gameplay.getP2(), _gameplay.getWater());
		_gameplay.getP2().setBackPack("water", _gameplay.getP2().getItemQuantiy("water") + 1);
	}
	else if (str == "p1backleather") {
		_gameplay.backLeather(_gameplay.getP1(), _gameplay.getLeather());
		_gameplay.getP1().setBackPack("leather", _gameplay.getP1().getItemQuantiy("leather") + 1);
	}
	else if (str == "p2backleather") {
		_gameplay.backLeather(_gameplay.getP2(), _gameplay.getLeather());
		_gameplay.getP2().setBackPack("leather", _gameplay.getP2().getItemQuantiy("leather") + 1);
	}
	else if (str == "p1backmetal") {
		_gameplay.backMetal(_gameplay.getP1(), _gameplay.getMetal());
		_gameplay.getP1().setBackPack("metal", _gameplay.getP1().getItemQuantiy("metal") + 1);
	}
	else if (str == "p2backmetal") {
		_gameplay.backMetal(_gameplay.getP2(), _gameplay.getMetal());
		_gameplay.getP2().setBackPack("metal", _gameplay.getP2().getItemQuantiy("metal") + 1);
	}
}

void SceneGame::onDraw(sf::RenderWindow& window) {
	window.clear();

	sf::Texture texture;
	if (!texture.loadFromFile("sprite/tree.png"))
		std::cout << "Error loading image!" << std::endl;
	this->_woodSprite.setTexture(texture);
	this->_woodSprite.setPosition(100,275);
	this->_woodSprite.setScale(0.4f, 0.4f);
	window.draw(_woodSprite);

	if (!texture.loadFromFile("sprite/water.png"))
		std::cout << "Error loading image!" << std::endl;
	this->_waterSprite.setTexture(texture);
	this->_waterSprite.setPosition(450, 275);
	this->_waterSprite.setScale(0.4f, 0.4f);
	window.draw(_waterSprite);

	if (!texture.loadFromFile("sprite/leather.png"))
		std::cout << "Error loading image!" << std::endl;
	this->_leatherSprite.setTexture(texture);
	this->_leatherSprite.setPosition(100, 100);
	this->_leatherSprite.setScale(0.4f, 0.4f);
	window.draw(_leatherSprite);

	if (!texture.loadFromFile("sprite/metal.png"))
		std::cout << "Error loading image!" << std::endl;
	this->_metalSprite.setTexture(texture);
	this->_metalSprite.setPosition(450,100);
	this->_metalSprite.setScale(0.4f, 0.4f);
	window.draw(_metalSprite);

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

	str = "Q wood, W water, E leater, R metal for P1 || U wood, I water, O leater, P metal for P2";
	this->_text.setCharacterSize(15);
	this->_text.setString(str);
	this->_text.setPosition(40, 40);
	window.draw(_text);

	str = "bp1 metal = " + std::to_string(_gameplay.getP1().getItemQuantiy("metal"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(5, 475);
	window.draw(_text);

	str = "bp2 metal = " + std::to_string(_gameplay.getP2().getItemQuantiy("metal"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(500, 475);
	window.draw(_text);

	str = "bp1 leather = " + std::to_string(_gameplay.getP1().getItemQuantiy("leather"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(5, 500);
	window.draw(_text);

	str = "bp2 leather = " + std::to_string(_gameplay.getP2().getItemQuantiy("leather"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(500, 500);
	window.draw(_text);

	str = "bp1 water = " + std::to_string(_gameplay.getP1().getItemQuantiy("water"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(5, 525);
	window.draw(_text);

	str = "bp2 water = " + std::to_string(_gameplay.getP2().getItemQuantiy("water"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(500, 525);
	window.draw(_text);

	str = "bp1 wood = " + std::to_string(_gameplay.getP1().getItemQuantiy("wood"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(5, 550);
	window.draw(_text);

	str = "bp2 wood = " + std::to_string(_gameplay.getP2().getItemQuantiy("wood"));
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(500, 550);
	window.draw(_text);

	str = "nb gens p1 = " + std::to_string(_gameplay.getP1().getGens());
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(5, 575);
	window.draw(_text);

	str = "nb gens p2 = " + std::to_string(_gameplay.getP2().getGens());
	this->_text.setCharacterSize(25);
	this->_text.setString(str);
	this->_text.setPosition(500, 575);
	window.draw(_text);

	str = std::to_string(_gameplay.getMetal().getGensP1());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(450, 130);
	window.draw(_text);

	str = std::to_string(_gameplay.getMetal().getGensP2());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(680, 130);
	window.draw(_text);

	str = std::to_string(_gameplay.getLeather().getGensP1());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(130, 200);
	window.draw(_text);

	str = std::to_string(_gameplay.getLeather().getGensP2());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(270, 200);
	window.draw(_text);

	str = std::to_string(_gameplay.getWater().getGensP1());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(450, 330);
	window.draw(_text);

	str = std::to_string(_gameplay.getWater().getGensP2());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(680, 330);
	window.draw(_text);

	str = std::to_string(_gameplay.getWood().getGensP1());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(130, 400);
	window.draw(_text);

	str = std::to_string(_gameplay.getWood().getGensP2());
	this->_text.setCharacterSize(30);
	this->_text.setString(str);
	this->_text.setPosition(230, 400);
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
