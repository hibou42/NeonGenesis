#ifndef SCENEGAME_HPP
# define SCENEGAME_HPP

#include "SceneBase.hpp"
#include "SFMLManager.hpp"

#include "../gameplay/Easy.hpp"

class SceneGame : public SceneBase {
	private:
		SFMLManager* sfmlManager;
		Easy &_gameplay;

		sf::Text _text;
		sf::CircleShape _circle;
		sf::RectangleShape _rect;

	public:
		SceneGame();
		SceneGame(SFMLManager* manager);
		~SceneGame();
		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
};

#endif