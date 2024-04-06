#include "SceneMenuSettings.hpp"

SceneMenuSettings::SceneMenuSettings() : sfmlManager(nullptr) {}

SceneMenuSettings::SceneMenuSettings(SFMLManager* manager) : sfmlManager(manager)
	, _position({100, 100}), _options({"Option 1", "Option 2", "Option 3"}), _showMenu(false), _selectedOption(-1) {
		std::cout << "SceneMenuSettings constructor" << std::endl;
	}



// SceneMenuSettings::SceneMenuSettings(const sf::Vector2f& position, const std::vector<std::string>& options) 
// 	: _position(position), _options(options), _showMenu(false), _selectedOption(-1) {}

SceneMenuSettings::~SceneMenuSettings() {}

void SceneMenuSettings::handleEvent(const sf::Event& event) {
	std::cout << "E pressed" << std::endl;
	//  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            // sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
        //     sf::FloatRect buttonBounds(_position.x, _position.y, 100, 40);

        //     if (buttonBounds.contains(mousePos)) {
        //         _showMenu = !_showMenu;
        //     } else if (_showMenu) {
        //         for (size_t i = 0; i < _options.size(); ++i) {
        //             sf::FloatRect optionBounds(_position.x, _position.y + 40 + i * 20, 100, 20);
        //             if (optionBounds.contains(mousePos)) {
        //                 _selectedOption = i;
        //                 _showMenu = false;
        //                 std::cout << "Option selected: " << _options[i] << std::endl;
        //                 break;
        //             }
        //         }
        //     }
        // }
}

void SceneMenuSettings::onUpdate(float deltaTime) {}

void SceneMenuSettings::onDraw(sf::RenderWindow& window) {
		window.clear();
		
	    sf::RectangleShape button(sf::Vector2f(100, 40));
        button.setFillColor(sf::Color::White);
        button.setOutlineColor(sf::Color::Black);
        button.setOutlineThickness(1);
        button.setPosition(_position);

        sf::Font font;
        if (!font.loadFromFile("font/digital-7.ttf")) {
            std::cerr << "Error loading font!" << std::endl;
            return;
        }

        sf::Text buttonText("Options", font, 16);
        buttonText.setPosition(_position.x + 10, _position.y + 10);

        window.draw(button);
        window.draw(buttonText);

        if (_showMenu) {
            sf::RectangleShape menu(sf::Vector2f(100, _options.size() * 20));
            menu.setFillColor(sf::Color::White);
            menu.setOutlineColor(sf::Color::Black);
            menu.setOutlineThickness(1);
            menu.setPosition(_position.x, _position.y + 40);

            for (size_t i = 0; i < _options.size(); ++i) {
                sf::Text optionText(_options[i], font, 16);
                optionText.setPosition(_position.x + 10, _position.y + 40 + i * 20);
                window.draw(optionText);
            }

            window.draw(menu);
        }
}