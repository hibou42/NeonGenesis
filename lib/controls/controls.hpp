#ifndef ACONTROLS_HPP
# define ACONTROLS_HPP

#include <string>

class AControls {
	private:
		std::string _controls_p1;
		std::string _controls_p2;



	public:
		virtual ~AControls() = default;
		std::string defaultControls();

};

#endif
