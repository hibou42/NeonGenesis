#ifndef SCENESTART_HPP
# define SCENESTART_HPP

#include "SceneBase.hpp"
#include <SFML/Graphics.hpp>
// #include <iostream>

class SceneStart : public SceneBase {
	private:
		sf::Text _text;
		sf::CircleShape _circle;
		sf::RectangleShape _rect;

	public:
		SceneStart();
		virtual ~SceneStart();

		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
};

#endif