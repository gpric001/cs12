#include <iostream>
#include <string>

class Character {
    public:
    Character(int, unsigned, unsigned,
              std::string, std::string);
    void showInfo() const;
    bool advance();
    bool isDead() const;
    void modHealth(int);
    void fight(Character&);
    
    private:
    int health;
    unsigned speed;
    unsigned power;
    unsigned action;
    std::string name;
    std::string description;
};