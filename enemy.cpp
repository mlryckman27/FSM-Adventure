#include "enemy.h"

using namespace std;

/**
 * @brief set_stats allows for the setting of specific stats for an enemy.
 * @param enemyName is the name of the enemy.
 * @param enemyMaxHealth is the maximum health an enemy may have.
 * @param enemyHealth is the current health of an enemy.
 * @param enemyAttack is the attack power of an enemy.
 */
void Enemy::set_stats(string enemyName, int enemyMaxHealth, int enemyHealth, int enemyAttack){
    name = enemyName;

    maxHealth = enemyMaxHealth;
    health = enemyHealth;
    attack = enemyAttack;
}

/**
 * @brief decrease_health decreases an enemy's health in battle.
 * @param heroAttack is the attack power of the user.
 */
void Enemy::decrease_health(int heroAttack){
    //The new health an enemy will have after taking damage.
    int newHealth;

    //The current health of an enemy.
    int currentHealth = health;

    newHealth = health - (heroAttack + (rand()%5 + 1));

    if(newHealth >= health){
        health = currentHealth;
    }

    else if(newHealth < health){
        health = newHealth;
    }

    if(health >= maxHealth){
        health = maxHealth;
    }
}
