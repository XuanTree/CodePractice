#include <iostream>
#include <SFML/Graphics.hpp>
int main(){
    //Set the window
    float width = 600.0f;
    float height = 1000.0f;
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(width,height)), "Battle Air");
    window.setFramerateLimit(60);
    
    //Texture
    sf:: Texture PlayerTexture;
    if(!PlayerTexture.loadFromFile("D:\\C_C++\\Term_1\\Winter\\PlayerPlane.png")){
        std:: cerr << "The file can not be loaded" << std:: endl;
    }
    sf:: Sprite PlayerSprite(PlayerTexture);
    sf:: IntRect dir[1];
    dir[0] = sf:: IntRect({0,0},{32,32});
    PlayerSprite.setTextureRect(dir[0]);
    PlayerSprite.setOrigin({16,16});
    PlayerSprite.scale(sf::Vector2f(1.2f,1.2f));
    PlayerSprite.setPosition({width/2.0f,height/2.0f});
    //Set Speed
    const float moveSpeed = 8.6f;
 
    while (window.isOpen()){
        while (auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            PlayerSprite.move(sf::Vector2f(0.f,-moveSpeed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            PlayerSprite.move(sf::Vector2f(0.f,moveSpeed));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            PlayerSprite.move(sf::Vector2f(-moveSpeed,0.f));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            PlayerSprite.move(sf::Vector2f(moveSpeed,0.f));
        }
        //Render
        window.clear(sf::Color::Black);
        
        //Draw
        window.draw(PlayerSprite);
        window.display();
    }
    return 0;
}