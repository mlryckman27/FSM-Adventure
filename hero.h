#ifndef HERO_H
#define HERO_H

#include "character.h"
#include <vector>
#include "time.h"

using namespace std;

/**
 * @brief The Hero class creates a hero for the user to play as.
 */
class Hero: public Character{
public:
    /**
     * @brief backpack is a vector that the player can add items to.
     */
    vector<string> backpack;

    /**
     * @brief weapon has an integer value that will add to the user's attack power.
     */
    int weapon;

    /**
     * @brief armor has an integer value that will add to the user's block power.
     */
    int armor;

    /**
     * @brief weaponName is the name of the user's current weapon.
     */
    string weaponName;

    /**
     * @brief armorName is the name of the user's current armor.
     */
    string armorName;

    /**
     * @brief Hero is the default construct that initializes the hero.
     */
    Hero(){
        init_hero();
    }

    /**
     * @brief init_hero initisalizes a hero with stats and asks for the user to input a name.
     */
    void init_hero();

    /**
     * @brief print_backpack displays the items in the hero's backpack.
     */
    void print_backpack();

    /**
     * @brief compare_strings returns true if the strings match, false otherwise.
     * @param item1 is an item to be compared.
     * @param item2 is an item to be compared
     * @return returns true or false.
     */
    bool compare_strings(string item1, string item2);

    /**
     * @brief check_backpack returns true if the backpack contains the item
     * @param item is any item that is to be searched for in the backpack.
     * @return returns true if the item is in the backpack.
     */
    bool check_backpack(string item);

    /**
     * @brief add_item adds an item to the backpack.
     * @param item is any item that is to be added to the backpack.
     */
    void add_item(string item);

    /**
     * @brief decrease_health decrements the hero's health.
     * @param enemyAttack is the attack power of the enemy.
     */
    void decrease_health(int enemyAttack);

    /**
     * @brief dodge_attack gives the user a chance to dodge an enemy attack.
     * @param enemyAttack is the attack power of the enemy.
     */
    void dodge_attack(int enemyAttack);

    /**
     * @brief change_weapon changes the weapon the hero has equipped.
     * @param newWeaponName is the name of the new weapon.
     * @param newWeapon is the attack power of the new weapon.
     */
    void change_weapon(string newWeaponName, int newWeapon);

    /**
     * @brief change_armor changes the armor the hero has equipped.
     * @param newArmorName is the name of the new armor.
     * @param newArmor is the block power of the new armor.
     */
    void change_armor(string newArmorName, int newArmor);

    /**
     * @brief use_item uses an item from the backpack to restore health.
     */
    void use_item();
};

#endif // HERO_H
