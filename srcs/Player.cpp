#include "../lib/Player.hpp"

using namespace std;

// ============================================================================|
// Fonctions d'interaction
// ============================================================================|

// ============================================================================|
// Construction, destruction et overload
// ============================================================================|

Player::Player() : _gens(10) {
	this->_mapbackpack["food"] = 20;
	cout << "Constructor Player / food = " << this->_mapbackpack.at("food") << endl;
}

Player::~Player() {
}

// ============================================================================|
// Getters & Setters
// ============================================================================|

int	Player::getGens() const {
	return (this->_gens);
}

const void Player::setGens(const int gens) {
	this->_gens = gens;
}

int Player::getItemQuantiy(const string item_name) const {
	return this->_mapbackpack.at(item_name);
}

map<string, int> Player::getBackPack() {
	return this->_mapbackpack;
}

const void Player::setBackPack(const string str, int quantity) {
	this->_mapbackpack[str] = quantity;
}
