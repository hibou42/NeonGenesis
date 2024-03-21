Bien sûr, je peux vous montrer quelques exemples supplémentaires d'utilisation de SFML en C++. SFML est une bibliothèque très versatile, vous permettant de gérer les fenêtres, les graphismes, le son et plus encore. Voici quelques exemples illustrant différents aspects de la SFML.
Exemple 1: Dessiner des formes

cpp

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

Dans cet exemple, un cercle vert et un rectangle bleu sont dessinés sur la fenêtre.
Exemple 2: Charger et afficher une image

cpp

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Afficher une Image");
    sf::Texture texture;

    if (!texture.loadFromFile("image.png")) {
        return -1; // Erreur lors du chargement de l'image
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

Ce code charge une image à partir d'un fichier et l'affiche à l'écran. Assurez-vous que le fichier "image.png" se trouve dans le même dossier que votre exécutable ou spécifiez le chemin complet vers le fichier.
Exemple 3: Gestion des entrées clavier

cpp

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gestion des Entrées Clavier");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            shape.move(-1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            shape.move(1.0f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            shape.move(0.0f, -1.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            shape.move(0.0f, 1.0f);
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}

Ici, un cercle vert peut être déplacé en utilisant les touches fléchées du clavier. Ces exemples montrent comment utiliser les fonctionnalités de base de SFML pour créer des fenêtres, dessiner des formes simples, charger et afficher des images, et gérer les entrées clavier. Vous pouvez combiner ces éléments pour créer des jeux ou des applications graphiques plus complexes.