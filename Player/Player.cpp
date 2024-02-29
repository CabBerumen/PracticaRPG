//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include "../Enemy/Enemy.h"
#include "../Combat/Combat.h"

using namespace std;

Player::Player(string _name, int _health, int _attack, int _defense, int _speed) : Character(_name, _health, _attack, _defense, _speed,
                                                                                             true) {
    level = 1;
    experience = 0;
}

void Player::doAttack(Character *target) {
    attackDamage = attack;
    target->takeDamage(attackDamage);
}
int Player::getAttackDamage() {
    return attackDamage;
}

void Player::takeDamage(int damage) {
    trueDamage = damage - defense;

    health-= trueDamage;
    cout << name << " took " << trueDamage << " damage!" << endl;
}
int Player::getTrueDamage() {
    return trueDamage;
}

void Player::levelUp() {
    level++;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }
}
Character* Player::selectTarget(vector<Enemy*> possibleTargets) {
    int selectedTarget = 0;
    cout << "Select a target: " << endl;
    for (int i = 0; i < possibleTargets.size(); i++) {
        cout << i << ". " << possibleTargets[i]->getName() << endl;
    }

    //TODO: Add input validation
    cin >> selectedTarget;
    return possibleTargets[selectedTarget];
}