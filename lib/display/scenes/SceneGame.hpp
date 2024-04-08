#ifndef SCENEGAME_HPP
# define SCENEGAME_HPP

#include "SceneBase.hpp"
#include "SFMLManager.hpp"
#include <chrono>
#include <map>
#include <functional>

#include "../gameplay/Easy.hpp"

class SceneGame : public SceneBase {
	private:
		SFMLManager* sfmlManager;
		Easy &_gameplay;
		std::chrono::system_clock::time_point _timeNow;

		sf::Text			_text;
		sf::CircleShape		_circle;
		sf::RectangleShape	_rect;
		sf::Sprite			_woodSprite;

	public:
		SceneGame();
		SceneGame(SFMLManager* manager);
		~SceneGame();
		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;

};

#endif