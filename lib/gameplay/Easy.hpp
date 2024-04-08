#ifndef EASY_HPP
# define EASY_HPP

#include <string>

#include "AGameplay.hpp"
#include "../Player.hpp"
#include "../material/Wood.hpp"
#include "../material/Water.hpp"
#include "../material/Leather.hpp"
#include "../material/Metal.hpp"

using namespace std;
// class SceneGame;

class Easy : public AGameplay
{
	private:
		Player	&_p1;
		Player	&_p2;

		Wood	&_wood;
		Water	&_water;
		Leather	&_leather;
		Metal	&_metal;

	public:
		Easy();
		~Easy();

	void goWood(Player &player, Wood &wood);
	void backWood(Player &player, Wood &wood);

	Player	&getP1();
	Player	&getP2();
	Wood	&getWood();
	Water	&getWater();
	Leather	&getLeather();
	Metal	&getMetal();
};

#endif