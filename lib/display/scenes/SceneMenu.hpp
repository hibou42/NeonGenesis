#ifndef SCENEMENU_HPP
# define SCENEMENU_HPP

#include "SceneBase.hpp"
#include "SFMLManager.hpp"

class SceneMenu : public SceneBase {
	private:
		 SFMLManager* sfmlManager;

		sf::Text _text;
		sf::CircleShape _circle;
		sf::RectangleShape _rect;

	public:
		SceneMenu();
		SceneMenu(SFMLManager* manager);
		virtual ~SceneMenu();
		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
};

#endif