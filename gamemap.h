#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "hero.h"
#include "treasurechest.h"
#include "enemy.h"

using namespace std;

/**
 * @brief The GameMap class controls all of the various game states the user can be in.
 */
class GameMap{
public:

    //Creates a hero character that the user will play as.
    Hero hero;

    //Creates two enemy characters that the user will battle at the end of the game.
    Enemy troll;
    Enemy dragon;

    //Creates two treasure chests that the user can find and take items from.
    TreasureChest chest1;
    TreasureChest chest2;

    GameMap(){
        //Seeding the random number generator.
        srand(time(NULL));

        //Setting the stats for the two enemies.
        troll.set_stats("Troll", 75, 75, 5);
        dragon.set_stats("Dragon", 150, 150, 20);

        //Filling the chests with items that the player can add to their backpack.
        chest1.fill_chest("Rock", "Wood");
        chest2.fill_chest("Rope", "Knife");

        start();
    }

    /**
     * @brief clear_screen clears the console screen by printing several blank new lines.
     */
    void clear_screen();

    /**
     * @brief start controls the start state.
     */
    void start();

    /**
     * @brief forest controls the forest state.
     */
    void forest();

    /**
     * @brief river controls the river state.
     */
    void river();

    /**
     * @brief plains controls the plains state.
     */
    void plains();

    /**
     * @brief mountain controls the mountain state.
     */
    void mountain();

    /**
     * @brief lake controls the lake state.
     */
    void lake();

    /**
     * @brief camp controls the camp state.
     */
    void camp();

    /**
     * @brief trollBattle controls the trollBattle state, which is a combat loop.
     */
    void trollBattle();

    /**
     * @brief dragonBattle controls the dragonBattle state, which is a combat loop.
     */
    void dragonBattle();
};

#endif // GAMEMAP_H
