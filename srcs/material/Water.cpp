#include "../../lib/material/Water.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters & Setters
// ============================================================================|

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Water::Water() {
	this->_difficulty = this->_settings.waterDifficulty;
	this->_cooldown = this->_settings.waterCooldown;

	this->_type = "water";
	this->_gens_p1 = 0;
	this->_gens_p2 = 0;
	this->_upgrade_type = "bucket";
	this->_upgrade_p1 = 0;
	this->_upgrade_p2 = 0;
}

Water::~Water() {}
