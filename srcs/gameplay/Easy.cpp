#include "../../lib/gameplay/Easy.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

void Easy::goWood(Player &player, Wood &wood) {
	if (&player == &_p1 && player.getGens() >= wood.getDifficulty()) {
		player.setGens(player.getGens() - wood.getDifficulty());
		wood.setGensP1(wood.getGensP1() + wood.getDifficulty());
	}
	else if (&player == &_p2 && player.getGens() >= wood.getDifficulty()) {
		player.setGens(player.getGens() - wood.getDifficulty());
		wood.setGensP2(wood.getGensP2() + wood.getDifficulty());
	}
}

void Easy::backWood(Player &player, Wood &wood) {
		if (&player == &_p1 && wood.getGensP1() > 0) {
			player.setGens(player.getGens() + wood.getDifficulty());
			wood.setGensP1(wood.getGensP1() - wood.getDifficulty());
		}
		else if (&player == &_p2 && wood.getGensP2() > 0) {
			player.setGens(player.getGens() + wood.getDifficulty());
			wood.setGensP2(wood.getGensP2() - wood.getDifficulty());
		}
}

// ============================================================================|
// Getters
// ============================================================================|


// ============================================================================|
// Setters
// ============================================================================|


// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Easy::Easy() :
	_p1(*new Player()), 
	_p2(*new Player()), 
	_wood(*new Wood()), 
	_water(*new Water()), 
	_leather(*new Leather()), 
	_metal(*new Metal()) {}

Easy::~Easy() {
	delete &_p1;
	delete &_p2;
	delete &_wood;
	delete &_water;
	delete &_leather;
	delete &_metal;
}