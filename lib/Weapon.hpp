#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <map>
#include <string>

using namespace std;

class Weapon
{
private:
	map<string, int> _mapWeaponDamage;

public:
	Weapon();				// Constructeur
	~Weapon();				// Destructeur

	int			getWeaponDamage(const string &str) const;
	const void	setWeaponDamage(const string str, int i);

	map<string, int> getMapWeaponDamage() const;

};

#endif
