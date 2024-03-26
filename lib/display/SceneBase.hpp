#ifndef SCENEBASE_HPP
# define SCENEBASE_HPP

#include <SFML/Graphics.hpp>
// #include "SceneStart.hpp"

class SceneBase{
	protected:
		// SFMLManager* sfmlManager;
	public:

		SceneBase();
		virtual ~SceneBase();
		virtual void handleEvent(const sf::Event& event) = 0;
		virtual void onUpdate(float deltaTime) = 0;
		virtual void onDraw(sf::RenderWindow& window) = 0;

};

// #include "SceneStart.hpp"

#endif
