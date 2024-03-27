#include <SFML/Graphics.hpp>
#include "lib/display/SFMLManager.hpp"
#include "lib/display/SceneStart.hpp"
// #include "lib/display/SceneBase.hpp"
// #include "SceneGame.hpp"

int main() {

	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();


    sf::RenderWindow window(sf::VideoMode(desktopMode.width, desktopMode.height), "SFML Game", sf::Style::Fullscreen | sf::Style::None);
    window.setFramerateLimit(60);

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

        sceneManager.onUpdate(0.016f); // deltaTime fixe pour 60 FPS

        window.clear();
        sceneManager.onDraw(window);
        window.display();
    }

    return 0;
}