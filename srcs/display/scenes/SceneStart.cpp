#include "SceneStart.hpp"



SceneStart::SceneStart() : sfmlManager(nullptr){}

SceneStart::SceneStart(SFMLManager* manager) : sfmlManager(manager){

	this->_text = sf::Text("Push E", ResourceManager::getFont(), 50);
    this->_circle = sf::CircleShape(50);
    this->_rect = sf::RectangleShape(sf::Vector2f(100, 100));
}

SceneStart::~SceneStart() {

	std::cout << "SceneStart destroyed" << std::endl;
}

void SceneStart::handleEvent(const sf::Event& event) {
	if (sf::Joystick::isConnected(0)) {
		std::cout << "Joystick connected" << std::endl;
	}

	// std::cout << event.key.code << std::endl;
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E) {

		std::cout << "E pressed" << std::endl;
		if (sfmlManager != nullptr){

        	sfmlManager->pushScene(std::make_unique<SceneMenu>(sfmlManager));

		}
		else
			std::cout << "sfmlManager is null" << std::endl;
    }
}

void SceneStart::onUpdate(float deltaTime) {

    // Logique de mise à jour de la scène ici
	// std::cout << "deltaTime 0 : " << deltaTime << std::endl;
}

void SceneStart::onDraw(sf::RenderWindow& window) {
    window.clear();

	
	// this->_text.setFont(ResourceManager::getFont());
	// this->_text.setString("Push E");
    // this->_text.setCharacterSize(50);
    this->_text.setPosition(window.getSize().x / 2 - this->_text.getGlobalBounds().width / 2, window.getSize().y / 2);
    this->_text.setFillColor(sf::Color::Red);

	window.draw(_text);
	window.display();

}