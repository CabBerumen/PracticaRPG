//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../Character/Character.h"
#include "../Player/Player.h"
#include <vector>
#include "../Utils.h"
#include "Enemy.h"
#pragma once

class Enemy: public Character{
private:
    int experience;
    int attackDamage;
    int trueDamage;
public:
    Enemy(string _name, int _health, int _attack, int _defense, int _speed, int _experience);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    int getExperience();
    int getAttackDamage();

    Character* selectTarget(vector<Player*> possibleTargets);

    int getTrueDamage();
};


#endif //RPG_ENEMY_H
