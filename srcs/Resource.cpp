#include "../lib/Resource.hpp"

// ============================================================================|
// Interaction fonctions
// ============================================================================|

// ============================================================================|
// Getters & Setters
// ============================================================================|

int	Resource::getResDiff(const string &str) const {
	return (this->_mapResDiff.at(str));
}

const void Resource::setResDiff(const string str, int i) {
	this->_mapResDiff[str] = i;
}

map<string, int> Resource::getMapResDiff() const {
	return (this->_mapResDiff);
}

// ============================================================================|
// Construction, destruction & overload
// ============================================================================|

Resource::Resource() {
	this->_mapResDiff["wood"] = 1;
	this->_mapResDiff["water"] = 2;
	this->_mapResDiff["leather"] = 3;
	this->_mapResDiff["iron"] = 5;
}

Resource::~Resource() {

}