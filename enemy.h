#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include "time.h"

using namespace std;

/**
 * @brief The Enemy class is derived from the Character class and contains member fields and methods related to an enemy.
 */
class Enemy: public Character{
public:

    //Creates an enemy character with generic stats that can be modified.
    Enemy(){
        name = " ";

        maxHealth = 50;
        health = 50;
        attack = 5;
    }

    /**
     * @brief set_stats allows for the setting of specific stats for an enemy.
     * @param enemyName is the name of the enemy.
     * @param enemyMaxHealth is the maximum health an enemy may have.
     * @param enemyHealth is the current health of an enemy.
     * @param enemyAttack is the attack power of an enemy.
     */
    void set_stats(string enemyName, int enemyMaxHealth, int enemyHealth, int enemyAttack);

    /**
     * @brief decrease_health decreases an enemy's health in battle.
     * @param heroAttack is the attack power of the user.
     */
    void decrease_health(int heroAttack);
};

#endif // ENEMY_H
