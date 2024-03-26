#include "../../lib/display/SFMLManager.hpp"

void SFMLManager::pushScene(std::unique_ptr<SceneBase> scene) {
    scenes.push(std::move(scene));
}

void SFMLManager::popScene() {
    if (!scenes.empty()) {
        scenes.pop();
    }
}

void SFMLManager::handleEvent(const sf::Event& event) {
    if (!scenes.empty()) {
        scenes.top()->handleEvent(event);
    }
}

void SFMLManager::onUpdate(float deltaTime) {
    if (!scenes.empty()) {
        scenes.top()->onUpdate(deltaTime);
    }
}

void SFMLManager::onDraw(sf::RenderWindow& window) {
    if (!scenes.empty()) {
        scenes.top()->onDraw(window);
    }
}