#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <map>
#include <string>
#include <iostream>
#include <ostream>

using namespace std;

class Player
{
	private:
		int _gens;
		map<string, int> _mapbackpack;

	public:
		Player();
		~Player();

		int			getGens() const;
		const void	setGens(const int gens);

		int	getItemQuantiy(const string item_name) const;

		map<string, int>	getBackPack();
		const void			setBackPack(const string, int quantity);
		

};

#endif