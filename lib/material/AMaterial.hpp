#ifndef AMATERIAL_HPP
# define AMATERIAL_HPP

#include <string>
#include "ZsettingsMaterial.hpp"

using namespace std;

class AMaterial
{
private:

protected :
	ZsettingsMaterial _settings;

	int		_difficulty;
	string	_type;
	int		_gens_p1;
	int		_gens_p2;
	string	_upgrade_type;
	int		_upgrade_p1;
	int		_upgrade_p2;

public:
	AMaterial();				// Constructeur
	virtual ~AMaterial();		// Destructeur

	int			getDifficulty() const;
	string		getType() const;
	int			getGensP1() const;
	int			getGensP2() const;
	string		getUpgradeType() const;
	int			getUpgradeP1() const;
	int			getUpgradeP2() const;

	void		setGensP1(int i);
	void		setGensP2(int i);
	void		setUpgradeP1(int i);
	void		setUpgradeP2(int i);
};

#endif
