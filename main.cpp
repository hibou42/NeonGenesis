#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dessiner des Formes");

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