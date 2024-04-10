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
		std::multimap<std::chrono::system_clock::time_point, std::string> _autoReturnMap;

		std::chrono::system_clock::time_point	_timeNow;
		std::chrono::system_clock::time_point	_timeNext;

		sf::Font _font_digital;
		sf::Font _font_lemon;

		sf::Text			_text;
		sf::Sprite			_woodSprite;
		sf::Texture			_woodTexture;
		sf::Sprite			_waterSprite;
		sf::Texture			_waterTexture;
		sf::Sprite			_leatherSprite;
		sf::Texture			_leatherTexture;
		sf::Sprite			_metalSprite;
		sf::Texture			_metalTexture;

	public:
		SceneGame();
		SceneGame(SFMLManager* manager);
		~SceneGame();
		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
		void autoReturn(std::string str);

};

#endif