#include "Character.h"

using namespace std;

void battle(Character&, Character&);

int main() {
    Character c1(120, 10, 30, "Jack the Ripper", "A serial killer");
    Character c2(100, 15, 30, "Joe Rogan", "Ex-MMA Fighter/Podcaster");
    battle(c1, c2);
    return 0;
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