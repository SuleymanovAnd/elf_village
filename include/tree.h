#include "branch.h"
#pragma once

class Tree {
    vector<Branch *> children;
    string findElf;

    int getCount (int start, int end){
        srand(time(nullptr));
        return rand() %(end - start) + start;}
public:
    Tree(int count) {
        children.resize(count);
        for (int i = 0; i < count; i++) {
            cout << i + 1 << "tree" << endl;
            children[i] = new Branch(getCount(3, 5));
         //   children[i]->setTree(this);
        }
    }

   /* vector<Branch *> getChildren() {
        return children;
    }*/

    void setFindElf() {
        cout << "Enter the name of the elf you want to find";
        cin >> findElf;
    }

    string getFindElf() {
        return findElf;
    }

    int isTheElfOnABigBranch ();


    int countNeighbors();
    ~Tree() {for (int i =0;i<children.size();i++){
        delete children[i];
        children[i] = nullptr;
    }};
};