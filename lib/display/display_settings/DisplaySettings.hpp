#ifndef DISPLAYSETTINGS_HPP
# define DISPLAYSETTINGS_HPP

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;
using json = nlohmann::json;

class DisplaySettings {
public:
	int width;
	int height;
	bool fullscreen;
	bool borderless;

	DisplaySettings() : width(800), height(600), fullscreen(false), borderless(false) {}

	static DisplaySettings loadSettingsFromJson(const std::string& filename) {
		std::ifstream file(filename);
		if (!file.is_open()) {
			std::cerr << "Erreur: Impossible to open file: " << filename << std::endl;


			DisplaySettings defaultSettings;
            defaultSettings.saveSettingsToJson(filename);
			return defaultSettings;
		}

		json j;
		file >> j;

		DisplaySettings settings;
		settings.width = j.value("width", 800);
		settings.height = j.value("height", 600);
		settings.fullscreen = j.value("fullscreen", false);
		settings.borderless = j.value("borderless", false);

		return settings;
	}


	void saveSettingsToJson(const std::string& filename) const {

		json j;
		j["width"] = width;
		j["height"] = height;
		j["fullscreen"] = fullscreen;
		j["borderless"] = borderless;

		std::ofstream file(filename);
		if (file.is_open()) {
			file << std::setw(4) << j;
			std::cout << "Paramèters saved in " << filename << std::endl;
		} else {
			std::cerr << "Erreur: Impossible to open file: " << filename << std::endl;
		}
	}
};

#endif