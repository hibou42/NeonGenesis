#ifndef ZSETTINGSMATERIAL_HPP
# define ZSETTINGSMATERIAL_HPP

#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include <../../nlohmann/json.hpp>


namespace fs = std::experimental::filesystem;
using json = nlohmann::json;

class ZsettingsMaterial {
public:
	// add more here !!!
	int	woodDifficulty;
	std::chrono::seconds	woodCooldown;
	int	waterDifficulty;
	std::chrono::seconds	waterCooldown;
	int	leatherDifficulty;
	std::chrono::seconds	leatherCooldown;
	int	metalDifficulty;
	std::chrono::seconds	metalCooldown;
	int	last;

	ZsettingsMaterial() {};
	~ZsettingsMaterial() {};

	static ZsettingsMaterial loadSettingsFromJson(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Erreur: Impossible to open file: " << filename << std::endl;
			return ZsettingsMaterial();
		}
		json jason;
		file >> jason;

		// add more here !!!
		ZsettingsMaterial settings;
		settings.woodDifficulty = jason.value("woodDifficulty", 1);
		settings.woodCooldown = std::chrono::seconds(jason.value("woodCooldown", 1));
		settings.waterDifficulty = jason.value("waterDifficulty", 1);
		settings.waterCooldown = std::chrono::seconds(jason.value("waterCooldown", 1));
		settings.leatherDifficulty = jason.value("leatherDifficulty", 1);
		settings.leatherCooldown = std::chrono::seconds(jason.value("leatherCooldown", 1));
		settings.metalDifficulty = jason.value("metalDifficulty", 1);
		settings.metalCooldown = std::chrono::seconds(jason.value("metalCooldown", 1));
		settings.last = jason.value("last", 0);

		return settings;
	}
};

#endif