#ifndef SCENESTART_HPP
# define SCENESTART_HPP

#include "SceneBase.hpp"
#include "SFMLManager.hpp"
#include "SceneMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ResourceManager.hpp"

class SceneStart : public SceneBase {
	private:
		 SFMLManager* sfmlManager;

		sf::Text _text;
		sf::CircleShape _circle;
		sf::RectangleShape _rect;

	public:
		SceneStart();
		SceneStart(SFMLManager* manager);
		virtual ~SceneStart();

		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
};

#endif