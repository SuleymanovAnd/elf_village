#include "branch.h"

class Tree {
    vector<Branch *> children;
    string findElf;
public:
    Tree(int count) {
        children.resize(count);
        for (int i = 0; i < count; i++) {
            cout << i + 1 << "tree" << endl;
            children[i] = new Branch(getCount(3, 5));
         //   children[i]->setTree(this);
        }
    }

    vector<Branch *> getChildren() {
        return children;
    }

    void setFindElf() {
        cout << "Enter the name of the elf you want to find";
        cin >> findElf;
    }

    string getFindElf() {
        return findElf;
    }

    int isTheElfOnABigBranch (){
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


    int countNeighbors() {
        int Neighbors = 0;
        if (isTheElfOnABigBranch() == -1) return -1;
        else {
            for (int i = 0; i < children.size(); i++) {

               cout << 1 <<children[i]->getNameElf()<< " " <<  findElf << endl;

                for (int j = 0; j < children[i]->getChildren().size(); j++) {
                    if (isTheElfOnABigBranch () == 1 && children[i]->getChildren()[j]->getNameElf() != findElf
                    && children[i]->getChildren()[j]->getNameElf() != "None") {
                        Neighbors++;
                    }

                    cout << 2 <<children[i]->getChildren()[j]->getNameElf()<< " "<<" "<<findElf<< endl;


                    for (int k = 0; k< children[i]->getChildren()[j]->getChildren().size();k++){

                        if (isTheElfOnABigBranch () == 2 &&
                            children[i]->getChildren()[j]->getChildren()[k]->getNameElf() != "None") {
                            Neighbors++;
                        }

                        cout << 3 <<children[i]->getChildren()[j]->getChildren()[k]->getNameElf()<< " "<<findElf<< endl;

                        if (children[i]->getChildren()[j]->getNameElf() == findElf && isTheElfOnABigBranch () == 1
                        && children[i]->getChildren()[j]->getChildren()[k]->getNameElf() != "None") {
                            Neighbors++;
                        }
                    }
                }
            }
        }
        return Neighbors;
    }
    ~Tree() {for (int i =0;i<children.size();i++){
        delete children[i];
    }};
};