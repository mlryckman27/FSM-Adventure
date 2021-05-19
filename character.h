#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using namespace std;

/**
 * @brief The Character class contains member fields that will be be used in other derived classes.
 */
class Character{
public:
    //The name of an enemy or user.
    string name;

    //The maximum health an enemy or user can have.
    int maxHealth;
    //The health of an enemy or user.
    int health;
    //The attack power of an enemy or user.
    int attack;
    //The amount of damage an enemy or hero can block.
    int block;

    //Setting up a generic character and setting all the stats to zero values.
    Character(){
        name = " ";
        maxHealth = 0;
        health = 0;
        attack = 0;
        block = 0;
    }
};

#endif // CHARACTER_H
