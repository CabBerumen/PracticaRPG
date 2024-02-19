//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"

Player::Player(string _name, int _health, int _attack, int _defense, int _speed) : Character(_name, _health, _attack, _defense, _speed) {
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