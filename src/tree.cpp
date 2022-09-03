#include <iostream>
#include "tree.h"

int Tree::isTheElfOnABigBranch (){
    for (int i = 0; i < children.size(); i++) {
        for (int j = 0; j < children[i]->getChildren().size(); j++) {
            if (children[i]->getChildren()[j]->getNameElf() == findElf){
                return 1; // да на большой
            }
            for (int k = 0; k< children[i]->getChildren()[j]->getChildren().size();k++){
                if (children[i]->getChildren()[j]->getChildren()[k]->getNameElf() == findElf){
                    return 2; // нет на маленькой
                }

            }
        }
    } return -1; // его нет ни на одной ветке
}

int Tree::countNeighbors() {
    int Neighbors = 0;
    if (isTheElfOnABigBranch() == -1) return -1;
    else {
        for (int i = 0; i < children.size(); i++) {
            //cout << 1 << endl;
            for (int j = 0; j < children[i]->getChildren().size(); j++) {
                // подсчет соседей по большим веткам
                if (isTheElfOnABigBranch () == 1 && children[i]->getChildren()[j]->getNameElf() != findElf
                    && children[i]->getChildren()[j]->getNameElf() != "None") {
                    Neighbors++;
                }
                //cout << 2 <<children[i]->getChildren()[j]->getNameElf()<< " "<<" "<<findElf<< endl;

                for (int k = 0; k< children[i]->getChildren()[j]->getChildren().size();k++){
                    // подсчет соседей по средним веткам
                    // если эльф живет на средней ветке
                    if (isTheElfOnABigBranch () == 2 &&
                        children[i]->getChildren()[j]->getChildren()[k]->getNameElf() != "None") {
                        Neighbors++;
                    }
                   // если эльф живет на большой ветке
                    if (children[i]->getChildren()[j]->getNameElf() == findElf && isTheElfOnABigBranch () == 1
                        && children[i]->getChildren()[j]->getChildren()[k]->getNameElf() != "None") {
                        Neighbors++;
                    }
                    // cout << 3 <<children[i]->getChildren()[j]->getChildren()[k]->getNameElf()<< " "<<findElf<< endl;
                }
            }
        }
    }
    return Neighbors;
}