#include "../lib/Weapon.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters & Setters
// ============================================================================|

int	Weapon::getWeaponDamage(const string &str) const {
	return (this->_mapWeaponDamage.at(str));
}

const void Weapon::setWeaponDamage(const string str, int i) {
	this->_mapWeaponDamage[str] = i;
}

map<string, int> Weapon::getMapWeaponDamage() const {
	return (this->_mapWeaponDamage);
}

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Weapon::Weapon() {
	this->_mapWeaponDamage["staff"] = 1;
	this->_mapWeaponDamage["axe"] = 3;
	this->_mapWeaponDamage["sword"] = 5;
	this->_mapWeaponDamage["halberd"] = 10;
}

Weapon::~Weapon() {

}