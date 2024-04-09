#include "../../lib/gameplay/Easy.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

bool Easy::goWood(Player &player, Wood &wood) {
	if (&player == &_p1 && player.getGens() >= wood.getDifficulty()) {
		player.setGens(player.getGens() - wood.getDifficulty());
		wood.setGensP1(wood.getGensP1() + wood.getDifficulty());
		return true;
	}
	else if (&player == &_p2 && player.getGens() >= wood.getDifficulty()) {
		player.setGens(player.getGens() - wood.getDifficulty());
		wood.setGensP2(wood.getGensP2() + wood.getDifficulty());
		return true;
	}
	return false;
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

Player	&Easy::getP1() {
	return _p1;
}

Player	&Easy::getP2() {
	return _p2;
}

Wood	&Easy::getWood() {
	return _wood;
}

Water	&Easy::getWater() {
	return _water;
}

Leather	&Easy::getLeather() {
	return _leather;
}

Metal	&Easy::getMetal() {
	return _metal;
}

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