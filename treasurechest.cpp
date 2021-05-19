#include "treasurechest.h"

using namespace std;

/**
 * @brief init_chest initializes a treasure chest and is used in the default constructor.
 */
void TreasureChest::init_chest(){
    //An empty chest.
    chest = {};
}

/**
 * @brief print_chest displays the items contained in a treasure chest.
 */
void TreasureChest::print_chest(){
    for(unsigned int i = 0; i < chest.size(); i++){
        cout << chest.at(i) << endl;
    }
}

/**
 * @brief fill_chest adds items to the treasure chest.
 * @param item1 is any item that should be added to the chest.
 * @param item2 is any item that should be added to the chest.
 */
void TreasureChest::fill_chest(string item1, string item2){
    chest.push_back(item1);
    chest.push_back(item2);
}

/**
 * @brief empty_chest removes the items from the chest.
 */
void TreasureChest::empty_chest(){
    chest.pop_back();
    chest.pop_back();
}

/**
 * @brief size gets the size of the vector that is the treasure chest object.
 * @return returns an integer value.
 */
int TreasureChest::size(){
    return chest.size();
}
