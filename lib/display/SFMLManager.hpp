#ifndef SFMLMANAGER_HPP
# define SFMLMANAGER_HPP

#include "SceneBase.hpp"
#include <SFML/Graphics.hpp>
#include <stack>
#include <memory>

class SceneBase;

class SFMLManager
{
private:
	// SceneBase* currentScene = nullptr;
	std::stack<std::unique_ptr<SceneBase>> scenes;
public:
	SFMLManager() {}

	static SFMLManager& getInstance() {
		static SFMLManager instance;
		return instance;
	}

	void pushScene(std::unique_ptr<SceneBase> scene);
	void popScene();
	// SceneBase* getCurrentScene();
	void handleEvent(const sf::Event& event);
	void onUpdate(float deltaTime);
	void onDraw(sf::RenderWindow& window);

};

#endif