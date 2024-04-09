#include "../../lib/material/AMaterial.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters
// ============================================================================|

int		AMaterial::getDifficulty() const {
	return (this->_difficulty);
}

string	AMaterial::getType() const {
	return (this->_type);
}

int		AMaterial::getGensP1() const {
	return (this->_gens_p1);
}

int		AMaterial::getGensP2() const {
	return (this->_gens_p2);
}

string	AMaterial::getUpgradeType() const {
	return (this->_upgrade_type);
}

int		AMaterial::getUpgradeP1() const {
	return (this->_upgrade_p1);
}

int		AMaterial::getUpgradeP2() const {
	return (this->_upgrade_p2);
}

// ============================================================================|
// Setters
// ============================================================================|

void AMaterial::setGensP1(int i) {
	this->_gens_p1 = i;
}

void AMaterial::setGensP2(int i) {
	this->_gens_p2 = i;
}

void AMaterial::setUpgradeP1(int i) {
	this->_upgrade_p1 = i;
}

void AMaterial::setUpgradeP2(int i) {
	this->_upgrade_p2 = i;
}

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

AMaterial::AMaterial() {
	_settings = ZsettingsMaterial::loadSettingsFromJson("json/material.json");
}

AMaterial::~AMaterial() {}