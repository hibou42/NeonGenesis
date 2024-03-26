#ifndef SCENEGAME_HPP
# define SCENEGAME_HPP

#include "SceneBase.hpp"
// #include "SFMLManager.hpp"

class SceneGame : public SceneBase {
	private:
		sf::Text _text;
		sf::CircleShape _circle;
		sf::RectangleShape _rect;
		// sf::RenderWindow* _window;

	public:

		SceneGame();
		virtual ~SceneGame();
		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
};

#endif