#include <iostream>
#include "tree.h"

int main() {
    Tree forest = *new Tree (1);
     cout << forest.countNeighbors() << " is neighbors to " << forest.getFindElf();
}
