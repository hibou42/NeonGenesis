#include "../../lib/material/Wood.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters & Setters
// ============================================================================|

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Wood::Wood() {
	this->_difficulty = 1;
	this->_type = "wood";
	this->_gens_p1 = 0;
	this->_gens_p2 = 0;
	this->_upgrade_type = "axe";
	this->_upgrade_p1 = 0;
	this->_upgrade_p2 = 0;
}

Wood::~Wood() {}
