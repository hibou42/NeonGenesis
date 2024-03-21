#include <SFML/Graphics.hpp>
#include "./lib/Player.hpp"
#include <string>

int main() {
    Player *p1 = new Player();
    p1->setBackPack("pouet", 28);
	int quant = p1->getItemQuantiy("pouet");
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dessiner des Formes");

    sf::Font font;
    if (!font.loadFromFile("./font/digital-7.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return EXIT_FAILURE;
    }

    string str= "Hello SFML = " + std::to_string(quant);
    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(50);
    text.setPosition(100, 100);
    text.setFillColor(sf::Color::Red);
    // Crée un cercle
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(200, 200);

    // Crée un rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120, 60));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(400, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(text);
        window.display();
    }

    return 0;
}
/*
int main (void)
{
	Player *p1 = new Player();
	//Player *p2 = new Player();

	cout << "test" << endl;

	p1->setBackPack("pouet", 28);
	int quant = p1->getItemQuantiy("pouet");
	cout << " pouet = " << quant << endl;

	return 0;
}
*/