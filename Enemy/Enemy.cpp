//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"


using namespace std;
using namespace combat_utils;

Enemy::Enemy(string _name, int _health, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed) {
    experience = _experience;
}

void Enemy::doAttack(Character *target) {
    attackDamage = getRolledAttack(attack);
    target->takeDamage(attackDamage);
}
int Enemy::getAttackDamage() {
    return attackDamage;
}

void Enemy::takeDamage(int damage) {
    trueDamage = damage - defense;

    health-= trueDamage;
}
int Enemy::getTrueDamage(){
    return trueDamage;
}

int Enemy::getExperience() {
    return experience;
}