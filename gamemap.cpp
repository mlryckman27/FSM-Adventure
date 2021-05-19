#include "gamemap.h"

using namespace std;

/**
 * @brief clear_screen clears the console screen by printing several blank new lines.
 */
void GameMap::clear_screen(){
    //Loops over an index number, i, printing out blanks new lines each time to clear the screen.
    for (unsigned int i = 0; i < 100; i++){
        cout << "\n\n\n";
    }
}

/**
 * @brief start controls the start state.
 */
void GameMap::start(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "START" << endl;
    cout << " " << endl;
    cout << "0: Display backpack's contents." << endl;
    cout << "1: FOREST" << endl;
    cout << "2: RIVER" << endl;

    //Holds user input.
    int input = 0;

    cin >> input;

    clear_screen();

    switch(input){
        case 0:{
            hero.print_backpack();
            start();
        }

        case 1:{
            forest();
            break;
        }

        case 2:{
            river();
            break;
        }

        default:{
            cout << "Invalid selection..." << endl;
            start();
        }
    }
}

/**
 * @brief forest controls the forest state.
 */
void GameMap::forest(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "FOREST" << endl;
    cout << "You notice some strange bushes in an open area of the forest." << endl;
    cout << "Off in the distance you see an opening in the trees leading out of the forest." << endl;
    cout << " " << endl;
    cout << "1: START" << endl;
    cout << "2: PLAINS" << endl;
    cout << "3: Investigate around the bushes." << endl;

    int input = 0;

    //Holds user input.
    cin >> input;

    clear_screen();

    switch(input){
        case 1:{
            start();
            break;
        }

        case 2:{
            plains();
            break;
        }

        case 3:{
            cout << "You found a treasure chest!" << endl;
            cout << "Enter the name of the item you would like to add to your backpack:" << endl;

            if(chest1.size() > 0){
                chest1.print_chest();

                string chestInput;

                cin >> chestInput;

                hero.add_item(chestInput);

                chest1.empty_chest();
            }else{
                cout << "The treasure chest is empty..." << endl;
            }

            forest();
        }

        default:{
            cout << "Invalid selection..." << endl;
            forest();
        }
    }
}

/**
 * @brief river controls the river state.
 */
void GameMap::river(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "RIVER" << endl;
    cout << "It looks like you could cross this river if you had to right materials." << endl;
    cout << "Near the river bank, you spy what appears to be an empty box" << endl;
    cout << " " << endl;
    cout << "1: START" << endl;
    cout << "2: LAKE" << endl;
    cout << "3: Cross the RIVER" << endl;
    cout << "4: Search the empty box." << endl;

    //Holds user input.
    int input = 0;

    cin >> input;

    clear_screen();

    switch(input){
        case 1:{
            start();
            break;
        }

        case 2:{
            lake();
            break;
        }

        case 3:{
            if ((hero.check_backpack("Wood") == true or hero.check_backpack("Rock") == true) and (hero.check_backpack("Rope") == true or hero.check_backpack("Knife"))){
                trollBattle();
                break;
            }else{
                cout << "You lack the proper materials to cross the river." << endl;
                cout << "You need any TWO of the following items: Rock, Wood, Rope, or Knife." << endl;

                river();
            }
        }

        case 4:{
            cout << "You found a treasure chest!" << endl;
            cout << "Enter the name of the item you would like to add to your backpack:" << endl;

            if(chest2.size() > 0){
                chest2.print_chest();

                //Holds the user's input regarding which item they want from the chest.
                string chestInput;

                cin >> chestInput;

                clear_screen();

                hero.add_item(chestInput);

                chest2.empty_chest();
            }else{
                cout << "The treasure chest is empty..." << endl;
            }

            river();
        }

        default:{
            cout << "Invalid selection..." << endl;
            river();
        }
    }
}

/**
 * @brief plains controls the plains state.
 */
void GameMap::plains(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "PLAINS" << endl;
    cout << "The plains are flat and coverd in tall grass." << endl;
    cout << "Be sure to watch your step." << endl;
    cout << " " << endl;
    cout << "1: FOREST" << endl;
    cout << "2: MOUNTAIN" << endl;
    cout << "3: Investigate the oddly-placed rocks." << endl;

    //Holds user input.
    int input = 0;

    cin >> input;

    clear_screen();

    switch(input){
        case 1:{
            forest();
            break;
        }

        case 2:{
            mountain();
            break;
        }

        case 3:{
            cout << "You found a potion.  It's used for restoring HEALTH in battle." << endl;

            hero.add_item("Potion");

            plains();
        }

        default:{
            cout << "Invalid selection..." << endl;
            plains();
        }
    }
}

/**
 * @brief mountain controls the mountain state.
 */
void GameMap::mountain(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "MOUNTAIN" << endl;
    cout << "The mountain extends into the clouds." << endl;
    cout << "Maybe you could climb it if you had just the right combination of materials." << endl;
    cout << " " << endl;
    cout << "1: PLAINS" << endl;
    cout << "2: Climb the MOUNTAIN" << endl;
    cout << "3: Investigate the cave near the base of the mountain." << endl;

    //Holds user input.
    int input = 0;

    cin >> input;

    clear_screen();

    switch(input){
        case 1:{
            plains();
            break;
        }

        case 2:{
            if(hero.check_backpack("Knife") == true and hero.check_backpack("Rock") == true){
                dragonBattle();
                break;
            }else{
                cout << "You do not have the proper materials for climbing the mountain." << endl;
                mountain();
            }
        }

        case 3:{
            cout << "You get bit by a snake and lose 10 HEALTH." << endl;

            hero.health = hero.health - 10;

            mountain();
        }

        default:{
            cout << "Invalid selection..." << endl;
            mountain();
        }
    }
}

/**
 * @brief lake controls the lake state.
 */
void GameMap::lake(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "LAKE" << endl;
    cout << "The lake water is clear despite its depth." << endl;
    cout << "You notice something at the bottom" << endl;
    cout << " " << endl;
    cout << "1: RIVER" << endl;
    cout << "2: CAMP" << endl;
    cout << "3: Investigate the clear water." << endl;

    //Holds user input.
    int input = 0;

    cin >> input;

    clear_screen();

    switch(input){
        case 1:{
            river();
            break;
        }

        case 2:{
            camp();
            break;
        }

        case 3:{
            cout << "A snake jumps out of the water and bites you.  You lose 10 HEALTH." << endl;

            //User's health is decremented by 10.
            hero.health = hero.health - 10;

            lake();
        }

        default:{
            cout << "Invalid selection..." << endl;
            lake();
        }
    }
}

/**
 * @brief camp controls the camp state.
 */
void GameMap::camp(){
    cout << "HEALTH: " << hero.health << endl;
    cout << "Weapon: " << hero.weaponName << endl;
    cout << "Armor: " << hero.armorName << endl;
    cout << " " << endl;
    cout << "CAMP" << endl;
    cout << "It appears to be a camp, abandoned long ago." << endl;
    cout << " " << endl;
    cout << "1: LAKE" << endl;
    cout << "2: Investigate the empty camp." << endl;

    //Holds user input.
    int input = 0;

    cin >> input;

    clear_screen();

    switch(input){
        case 1:{
            lake();
            break;
        }

        case 2:{
            cout << "You found a new set of weapons and armor!" << endl;

            //Old weapon and armor set is swapped for a new, better set.
            hero.change_weapon("Steel Sword", 20);
            hero.change_armor("Steel Plate Armor", 15);

            camp();
        }

        default:{
            cout << "Invalid selection..." << endl;
            camp();
        }
    }
}

/**
 * @brief trollBattle controls the trollBattle state, which is a combat loop.
 */
void GameMap::trollBattle(){
    while(hero.health > 0 and troll.health > 0){
        cout << "Battle!" << endl;
        cout << " " << endl;
        cout << hero.name << "'s " << "HEALTH: " << hero.health << endl;
        cout << troll.name << "'s " << "HEALTH: " << troll.health << endl;
        cout << " " << endl;
        cout << "Attack or dodge?" << endl;
        cout << "1: Use an item" << endl;
        cout << "2: Attack" << endl;
        cout << "3: Dodge" << endl;

        //Holds user input.
        int input = 0;

        cin >> input;

        clear_screen();

        if(input == 1){
            hero.use_item();
        }

        if(input == 2){
            cout << "You clash with the enemy!" << endl;

            hero.decrease_health(troll.attack);
            troll.decrease_health(hero.attack);
        }

        else if(input == 3){
            hero.dodge_attack(troll.attack);
        }else{
            cout << "Invalid input..." << endl;
        }
    }

    if(hero.health <= 0){
        cout << "You lost... GAME OVER!" << endl;
        cout << "Enter any key to exit." << endl;

        //Holds user input.
        int input;

        cin >> input;

        //Regardless of what the user inputs, the program closes.
        exit(0);
    }

    if(troll.health <= 0){
        cout << "You WON!" << endl;
        cout << "Enter any key to exit." << endl;

        //Holds user input.
        int input;

        cin >> input;

        //Regardless of what the user inputs, the program closes.
        exit(0);
    }
}

/**
 * @brief dragonBattle controls the dragonBattle state, which is a combat loop.
 */
void GameMap::dragonBattle(){
    while(hero.health > 0 and dragon.health > 0){
        cout << "Battle!" << endl;
        cout << " " << endl;
        cout << hero.name << "'s " << "HEALTH: " << hero.health << endl;
        cout << dragon.name << "'s " << "HEALTH: " << dragon.health << endl;
        cout << " " << endl;
        cout << "Attack or dodge?" << endl;
        cout << "1: Use an item" << endl;
        cout << "2: Attack" << endl;
        cout << "3: Dodge" << endl;

        //Holds user input.
        int input = 0;

        cin >> input;

        clear_screen();

        if(input == 1){
            hero.use_item();
        }

        if(input == 2){
            cout << "You clash with the enemy!" << endl;

            hero.decrease_health(troll.attack);
            dragon.decrease_health(hero.attack);
        }

        else if(input == 3){
            hero.dodge_attack(dragon.attack);
        }else{
            cout << "Invalid input..." << endl;
        }
    }

    if(hero.health <= 0){
        cout << "You lost... GAME OVER!" << endl;
        cout << "Enter any key to continue." << endl;

        //Holds user input.
        int input;

        cin >> input;

        //Regardless of what the user inputs, the program closes.
        exit(0);
    }

    if(dragon.health <= 0){
        cout << "You WON!";
        cout << "Enter any key to continue." << endl;

        //Holds user input.
        int input;

        cin >> input;

        //Regardless of what the user inputs, the program closes.
        exit(0);
    }
}
