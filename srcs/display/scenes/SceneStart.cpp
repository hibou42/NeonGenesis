#include "SceneStart.hpp"



SceneStart::SceneStart() : sfmlManager(nullptr){}

SceneStart::SceneStart(SFMLManager* manager) : sfmlManager(manager){

    // this->_text = sf::Text();
	// this->_text.setFont(ResourceManager::getFont());
    this->_circle = sf::CircleShape(50);
    this->_rect = sf::RectangleShape(sf::Vector2f(100, 100));
}

SceneStart::~SceneStart() {

	std::cout << "SceneStart destroyed" << std::endl;
}

void SceneStart::handleEvent(const sf::Event& event) {
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
    // window.clear();



    // std::string str = "Scene Start";

    // this->_text.setString(str);
    // this->_text.setCharacterSize(50);
    // this->_text.setPosition(100, 100);
    // this->_text.setFillColor(sf::Color::Red);

    // Crée un cercle
    this->_circle.setFillColor(sf::Color::Green);
    this->_circle.setPosition(200, 200);
    this->_circle.setRadius(50);

    // // Crée un rectangle
    this->_rect.setFillColor(sf::Color::Blue);
    this->_rect.setPosition(400, 300);
    this->_rect.setSize(sf::Vector2f(100, 100));

    // // Dessiner les formes et le texte ici
    window.draw(this->_circle);
    window.draw(this->_rect);
    // window.draw(this->_text);
    // window.display();
}