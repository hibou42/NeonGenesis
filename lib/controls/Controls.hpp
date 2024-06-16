#ifndef CONTROLS_HPP
# define CONTROLS_HPP

#include <string>
#include <nlohmann/json.hpp>

class Controls {
	private:
		nlohmann::json _defaultControls;
		nlohmann::json _controls;
		std::string _controls_p1;
		std::string _controls_p2;



	public:
		Controls();
		~Controls() = default;
		defaultControls();


};

#endif
