#include <iostream>
#include "tree.h"

int main() {
    Tree forest = *new Tree (1);
    forest.setFindElf();
    if(forest.isTheElfOnABigBranch() != -1) {
        cout << forest.countNeighbors() << " is neighbors to " << forest.getFindElf();
    }else {
        cout << "There is no such elf among the inhabitants of the forest";
    }

}
