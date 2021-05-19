#ifndef TREASURECHEST_H
#define TREASURECHEST_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief The TreasureChest class creates treasure chests that contain items for the user to add to their backpack.
 */
class TreasureChest{
public:
    //A vector called 'chest' that can be filled with items.
    vector<string> chest;

    /**
     * @brief TreasureChest is the default consructor that creates a treasure chest object.
     */
    TreasureChest(){
        init_chest();
    }

    /**
     * @brief init_chest initializes a treasure chest and is used in the default constructor.
     */
    void init_chest();

    /**
     * @brief print_chest displays the items contained in a treasure chest.
     */
    void print_chest();

    /**
     * @brief fill_chest adds items to the treasure chest.
     * @param item1 is any item that should be added to the chest.
     * @param item2 is any item that should be added to the chest.
     */
    void fill_chest(string item1, string item2);

    /**
     * @brief empty_chest removes the items from the chest.
     */
    void empty_chest();

    /**
     * @brief size gets the size of the vector that is the treasure chest object.
     * @return returns an integer value.
     */
    int size();
};

#endif // TREASURECHEST_H
