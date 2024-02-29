#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"

int main() {
    Player *player = new Player("Bocchi", 100, 8, 4, 10);
    Enemy *enemy = new Enemy("Noel", 100, 6,4 , 5, 10);
    Enemy *enemy2 = new Enemy("Orc", 15, 6, 2, 5, 10);

    int round = 1;
    int doneDamage;
    int TrueDamage;

    cout << player->toString() << endl;
    cout << "---------------" << endl;
    cout << enemy->toString() << endl;

    cout << "=====================" << endl;

    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();


    while (player -> getHealth() > 0 && enemy -> getHealth() > 0){
        cout << "Round: " << round << ": " << endl;

        player->doAttack(enemy);
        //doneDamage = player->getAttackDamage();
        TrueDamage = enemy -> getTrueDamage(); // Obtiene el verdadero daño obtenido
        cout << player->getName() << " ataco con: " << TrueDamage << " de dano a: " << enemy->getName() << " || Salud de " << enemy->getName() << ": " << enemy->getHealth() << endl;

        if (enemy-> getHealth() > 0){
            enemy ->doAttack(player);
            //doneDamage = enemy->getAttackDamage();
            TrueDamage = player -> getTrueDamage();
            cout << enemy->getName() << " ataco con: " << TrueDamage << " de dano a: " << player->getName() << " || Salud de " << player->getName() << ": " << player->getHealth() << endl;

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
    delete combat;
    return 0;
}
