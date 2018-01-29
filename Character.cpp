#include "Character.h"

Character::Character(int health, unsigned speed, unsigned power,
                     std::string name, std::string description) {
    this->health = health;
    this->speed = speed;
    this->power = power;
    this->action = 0;
    this->name = name;
    this->description = description;
}

void Character::showInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Health: " << health << std::endl;
    std::cout << "Speed:  " << speed << std::endl;
    std::cout << "Power:  " << power << std::endl;
    std::cout << "Action: " << action << std::endl;
}

bool Character::advance() {
    action += speed;
    if (action >= 100) {
        action = 0;
        return true;
    }
    return false;
}

bool Character::isDead() const {
    return health <= 0;
}

void Character::modHealth(int healthMod) {
    health += healthMod;
}

void Character::fight(Character& character) {
    character.modHealth(-(this->power / 10));
}