#include "hero.h"

using namespace std;

/**
 * @brief init_hero initisalizes a hero with stats and asks for the user to input a name.
 */
void Hero::init_hero(){
    cout << "Name: " << endl;;

    cin >> name;

    maxHealth = 50;
    health = 50;
    weapon = 5;
    armor = 5;
    attack = 5 + weapon;
    block = 5 + armor;

    weaponName = "Wooden Sword";
    armorName = "Ripped Tunic";

    backpack = {"Water"};
}

/**
 * @brief print_backpack displays the items in the hero's backpack.
 */
void Hero::print_backpack(){
    cout << "Backpack:" << endl;

    for (unsigned int i = 0; i < backpack.size(); i++){
        cout << backpack.at(i) << endl;
    }
}

/**
 * @brief compare_strings returns true if the strings match, false otherwise.
 * @param item1 is an item to be compared.
 * @param item2 is an item to be compared
 * @return returns true or false.
 */
bool Hero::compare_strings(string item1, string item2){
    if (item1 == item2){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief check_backpack returns true if the backpack contains the item
 * @param item is any item that is to be searched for in the backpack.
 * @return returns true if the item is in the backpack.
 */
bool Hero::check_backpack(string item){
    for (unsigned int i = 0; i < backpack.size(); i++){
        if(compare_strings(backpack.at(i), item) == true){
            return true;
        }
    }

    return false;
}

/**
 * @brief add_item adds an item to the backpack.
 * @param item is any item that is to be added to the backpack.
 */
void Hero::add_item(string item){
    for (unsigned int i = 0; i < backpack.size(); i++){
        if(check_backpack(item) == false){
            backpack.push_back(item);
        }else{
            cout << "The item is already in your backpack." << endl;
        }
    }
}

/**
 * @brief decrease_health decrements the hero's health.
 * @param enemyAttack is the attack power of the enemy.
 */
void Hero::decrease_health(int enemyAttack){
    int newHealth;
    int currentHealth = health;

    newHealth = health - ((enemyAttack +  (rand()%10 + 5)) - block);

    if(newHealth >= health){
        health = currentHealth;
    }

    else if(newHealth < health){
        health = newHealth;
    }

    if (health >= maxHealth){
        health = maxHealth;
    }
}

/**
 * @brief dodge_attack gives the user a chance to dodge an enemy attack.
 * @param enemyAttack is the attack power of the enemy.
 */
void Hero::dodge_attack(int enemyAttack){
    int dodge = rand()%5;

    if (dodge <= 1){
        cout << "You failed to dodge." << endl;
        health = health - (enemyAttack + (rand()%10 + 5));

        if (health > maxHealth){
            health = maxHealth;
        }
    }else{
        cout << "You dodged the attack and gained 5 HEALTH!" << endl;

        health = health + 5;

        if(health >= maxHealth){
            health = maxHealth;
        }
    }
}

/**
 * @brief change_weapon changes the weapon the hero has equipped.
 * @param newWeaponName is the name of the new weapon.
 * @param newWeapon is the attack power of the new weapon.
 */
void Hero::change_weapon(string newWeaponName, int newWeapon){
    weaponName = newWeaponName;
    weapon = newWeapon;
}

/**
 * @brief change_armor changes the armor the hero has equipped.
 * @param newArmorName is the name of the new armor.
 * @param newArmor is the block power of the new armor.
 */
void Hero::change_armor(string newArmorName, int newArmor){
    armorName = newArmorName;
    armor = newArmor;
}

/**
 * @brief use_item uses an item from the backpack to restore health.
 */
void Hero::use_item(){
    print_backpack();

    cout << "Enter the name of the item you want to use: ";

    string item;

    cin >> item;

    if(compare_strings(item, "Water") and (check_backpack(item) == true)){
        cout << "You gained gained 10 HEALTH." << endl;

        health = health + 10;

        if(health > maxHealth){
            health = maxHealth;
        }

        int i = 0;

        for(i = 0; i < backpack.size(); i++){
            if(compare_strings("Water", backpack.at(i)) == true){
                backpack.erase(backpack.begin() + i);
            }
        }
    }

    if(compare_strings(item, "Potion") and (check_backpack(item) == true)){
        cout << "Your HEALTH has been restored." << endl;
        health = maxHealth;

        int i = 0;

        for(i = 0; i < backpack.size(); i++){
            if(compare_strings("Water", backpack.at(i)) == true){
                backpack.erase(backpack.begin() + i);
            }
        }
    }
}
