#ifndef SCENEMENUSETTINGS_HPP
# define SCENEMENUSETTINGS_HPP

#include "SceneBase.hpp"
#include "SFMLManager.hpp"
#include <iostream>

class SceneMenuSettings : public SceneBase {
	private:
		SFMLManager* sfmlManager;

		sf::Vector2f _position;
    	std::vector<std::string> _options;
    	bool _showMenu;
    	int _selectedOption;

	public:
		SceneMenuSettings();
		SceneMenuSettings(SFMLManager* manager);
		SceneMenuSettings(const sf::Vector2f& position, const std::vector<std::string>& options);
		virtual ~SceneMenuSettings();
		void handleEvent(const sf::Event& event) override;
		void onUpdate(float deltaTime) override;
		void onDraw(sf::RenderWindow& window) override;
};



#endif