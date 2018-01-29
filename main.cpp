#include <iostream>
#include <string>

using namespace std;

class Character {
    public:
    Character(int, unsigned, unsigned,
              string, string);
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
    string name;
    string description;
};

void battle(Character&, Character&);

int main() {
    Character c1(120, 10, 30, "Jack the Ripper", "A serial killer");
    Character c2(100, 15, 30, "Joe Rogan", "Ex-MMA Fighter/Podcaster");
    battle(c1, c2);
    return 0;
}

Character::Character(int health, unsigned speed, unsigned power,
                     string name, string description) {
    this->health = health;
    this->speed = speed;
    this->power = power;
    this->action = 0;
    this->name = name;
    this->description = description;
}

void Character::showInfo() const {
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Health: " << health << endl;
    cout << "Speed:  " << speed << endl;
    cout << "Power:  " << power << endl;
    cout << "Action: " << action << endl;
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

void battle(Character& char1, Character& char2) {
    while (!char1.isDead() && !char2.isDead()) {
        if (char1.advance()) {
            char1.fight(char2);
        }
        if (char2.advance()) {
            char2.fight(char1);
        }
    }
    if (char1.isDead() && char2.isDead()) {
        cout << "It's a tie!" << endl;
        return;
    }
    else if (char1.isDead()) {
        char2.showInfo();
    }
    else {
        char1.showInfo();
    }
    cout << "Is the winner!" << endl;
}