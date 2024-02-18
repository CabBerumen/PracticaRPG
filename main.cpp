#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    Player *player = new Player("Bocchi", 100, 8, 4, 10);
    Enemy *enemy = new Enemy("Daemon", 100, 5,4 , 5, 10);
    int round = 1;

    cout << player->toString() << endl;
    cout << "---------------" << endl;
    cout << enemy->toString() << endl;

    cout << "=====================" << endl;

    while (player -> getHealth() > 0 && enemy -> getHealth() > 0){
        cout << "Round: " << round << ": " << endl;

        player->doAttack(enemy);
        cout << player->getName() << " ataco a: " << enemy->getName() << " || Salud restante de " << enemy->getName() << ": " << enemy->getHealth() << endl;

        if (enemy-> getHealth() > 0){
            enemy ->doAttack(player);
            cout << enemy->getName() << " ataco a: " << player->getName() << " || Salud restante de " << player->getName() << ": " << player->getHealth() << endl;

        }
        round ++;
    }

    if (player->getHealth() > 0 && enemy -> getHealth() <= 0){
        cout << player->getName() << " ha ganado " << endl;
    } else if (enemy->getHealth() > 0 && player -> getHealth() <= 0){
        cout << enemy->getName() << " ha ganado " << endl;
    }


    //player->doAttack(enemy);
    //enemy->doAttack(player);
    cout << "=====================" << endl;

    cout << player->toString() << endl;
    cout << "---------------" << endl;
    cout << enemy->toString() << endl;

    delete player;
    delete enemy;
    return 0;
}
