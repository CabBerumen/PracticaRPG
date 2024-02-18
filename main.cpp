#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    Player *player = new Player("Rhaenyra", 100, 8, 4, 10);
    Enemy *enemy = new Enemy("Aegon II", 100, 8,4 , 5, 10);
    int round = 1;
    int doneDamage;

    cout << player->toString() << endl;
    cout << "---------------" << endl;
    cout << enemy->toString() << endl;

    cout << "=====================" << endl;

    while (player -> getHealth() > 0 && enemy -> getHealth() > 0){
        cout << "Round: " << round << ": " << endl;

        player->doAttack(enemy);
        doneDamage = player->getAttackDamage();
        cout << player->getName() << " ataco con: " << doneDamage << " de dano a: " << enemy->getName() << " || Salud de " << enemy->getName() << ": " << enemy->getHealth() << endl;

        if (enemy-> getHealth() > 0){
            enemy ->doAttack(player);
            doneDamage = enemy->getAttackDamage();
            cout << enemy->getName() << " ataco con: " << doneDamage << " de dano a: " << player->getName() << " || Salud de " << player->getName() << ": " << player->getHealth() << endl;

        }
        round ++;
    }

    if (player->getHealth() > 0 && enemy -> getHealth() <= 0){
        cout << player->getName() << " gano " << endl;
    } else if (enemy->getHealth() > 0 && player -> getHealth() <= 0){
        cout << enemy->getName() << " gano " << endl;
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
