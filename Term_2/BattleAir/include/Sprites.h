#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
sf::Sprite RenderBackground();
sf::Sprite RenderPlayer(const float width,const float height);
class Ammo : public sf::Sprite{//ºÃ≥–Sprite¿‡
    public:
        static void Init();
        static inline std::string entity_type = "enemy";
        static inline sf::FloatRect ammoHitBox;

        Ammo(sf::Vector2f position,const std::string& entity_type);
        void Update(const std::string& entity_type,float speed);
    private: 
        static sf::Texture playerTexture;
        static sf::Texture enemyTexture;
};

class Enemy : public sf::Sprite{
    public:
        static void Init();
        sf::Clock enemyShootClock;
        float enemyShootTime = 0.5f;

        Enemy(sf::Vector2f position,const std::string& entity_type = "enemy");
        void Update(const std::string& entity_type = "enemy",float speed = 5.5f);
        void Shoot(std::vector<Ammo>& ammos,sf::Vector2f position);
    private:
        static sf::Texture enemyPlaneTex;
};