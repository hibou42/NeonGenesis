#include "../../lib/material/Metal.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters & Setters
// ============================================================================|

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Metal::Metal() {
	this->_difficulty = this->_settings.metalDifficulty;
	this->_cooldown = this->_settings.metalCooldown;

	this->_type = "metal";
	this->_gens_p1 = 0;
	this->_gens_p2 = 0;
	this->_upgrade_type = "pickaxe";
	this->_upgrade_p1 = 0;
	this->_upgrade_p2 = 0;
}

Metal::~Metal() {}
