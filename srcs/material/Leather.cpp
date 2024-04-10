#include "../../lib/material/Leather.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters & Setters
// ============================================================================|

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Leather::Leather() {
	this->_difficulty = this->_settings.leatherDifficulty;
	this->_cooldown = this->_settings.leatherCooldown;

	this->_type = "Leather";
	this->_gens_p1 = 0;
	this->_gens_p2 = 0;
	this->_upgrade_type = "scissors";
	this->_upgrade_p1 = 0;
	this->_upgrade_p2 = 0;
}

Leather::~Leather() {}
