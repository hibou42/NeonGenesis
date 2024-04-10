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

bool Easy::goWater(Player &player, Water &water) {
	if (&player == &_p1 && player.getGens() >= water.getDifficulty()) {
		player.setGens(player.getGens() - water.getDifficulty());
		water.setGensP1(water.getGensP1() + water.getDifficulty());
		return true;
	}
	else if (&player == &_p2 && player.getGens() >= water.getDifficulty()) {
		player.setGens(player.getGens() - water.getDifficulty());
		water.setGensP2(water.getGensP2() + water.getDifficulty());
		return true;
	}
	return false;
}

void Easy::backWater(Player &player, Water &water) {
		if (&player == &_p1 && water.getGensP1() > 0) {
			player.setGens(player.getGens() + water.getDifficulty());
			water.setGensP1(water.getGensP1() - water.getDifficulty());
		}
		else if (&player == &_p2 && water.getGensP2() > 0) {
			player.setGens(player.getGens() + water.getDifficulty());
			water.setGensP2(water.getGensP2() - water.getDifficulty());
		}
}

bool Easy::goLeather(Player &player, Leather &leather) {
	if (&player == &_p1 && player.getGens() >= leather.getDifficulty()) {
		player.setGens(player.getGens() - leather.getDifficulty());
		leather.setGensP1(leather.getGensP1() + leather.getDifficulty());
		return true;
	}
	else if (&player == &_p2 && player.getGens() >= leather.getDifficulty()) {
		player.setGens(player.getGens() - leather.getDifficulty());
		leather.setGensP2(leather.getGensP2() + leather.getDifficulty());
		return true;
	}
	return false;
}

void Easy::backLeather(Player &player, Leather &leather) {
		if (&player == &_p1 && leather.getGensP1() > 0) {
			player.setGens(player.getGens() + leather.getDifficulty());
			leather.setGensP1(leather.getGensP1() - leather.getDifficulty());
		}
		else if (&player == &_p2 && leather.getGensP2() > 0) {
			player.setGens(player.getGens() + leather.getDifficulty());
			leather.setGensP2(leather.getGensP2() - leather.getDifficulty());
		}
}

bool Easy::goMetal(Player &player, Metal &metal) {
	if (&player == &_p1 && player.getGens() >= metal.getDifficulty()) {
		player.setGens(player.getGens() - metal.getDifficulty());
		metal.setGensP1(metal.getGensP1() + metal.getDifficulty());
		return true;
	}
	else if (&player == &_p2 && player.getGens() >= metal.getDifficulty()) {
		player.setGens(player.getGens() - metal.getDifficulty());
		metal.setGensP2(metal.getGensP2() + metal.getDifficulty());
		return true;
	}
	return false;
}

void Easy::backMetal(Player &player, Metal &metal) {
		if (&player == &_p1 && metal.getGensP1() > 0) {
			player.setGens(player.getGens() + metal.getDifficulty());
			metal.setGensP1(metal.getGensP1() - metal.getDifficulty());
		}
		else if (&player == &_p2 && metal.getGensP2() > 0) {
			player.setGens(player.getGens() + metal.getDifficulty());
			metal.setGensP2(metal.getGensP2() - metal.getDifficulty());
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