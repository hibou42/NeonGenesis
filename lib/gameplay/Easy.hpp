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

	bool goWood(Player &player, Wood &wood);
	void backWood(Player &player, Wood &wood);
	bool goWater(Player &player, Water &water);
	void backWater(Player &player, Water &water);
	bool goLeather(Player &player, Leather &leather);
	void backLeather(Player &player,Leather &leather);
	bool goMetal(Player &player, Metal &metal);
	void backMetal(Player &player, Metal &metal);

	Player	&getP1();
	Player	&getP2();
	Wood	&getWood();
	Water	&getWater();
	Leather	&getLeather();
	Metal	&getMetal();
};

#endif