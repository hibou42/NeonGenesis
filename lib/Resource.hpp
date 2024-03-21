#ifndef RESOURCE_HPP
# define RESOURCE_HPP

#include <map>
#include <string>

using namespace std;

class Resource
{
private:
	map<string, int> _mapResDiff;

public:
	Resource();				// Constructeur
	~Resource();			// Destructeur

	int			getResDiff(const string &str) const;
	const void	setResDiff(const string str, int i);

	map<string, int> getMapResDiff() const;

};

#endif
