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


    int countNeighbors() {
        int Neighbors = 0;
        bool nameFoundOnBig = false;
        bool nameFoundOnMid = false;
        if (children.empty()) return -1;
        else { setFindElf();
            for (int i = 0; i < children.size(); i++) {

               cout << 1 <<children[i]->getNameElf()<< " " << nameFoundOnBig<< findElf << endl;

                for (int j = 0; j < children[i]->getChildren().size(); j++) {
                    if (children[i]->getChildren()[j]->getNameElf() == findElf) {
                        nameFoundOnBig = true;
                    }

                    cout << 2 <<children[i]->getChildren()[j]->getNameElf()<< " "<<nameFoundOnBig<<" "<<findElf<< endl;

                    if (children[i]->getChildren()[j]->getNameElf() != findElf
                        && children[i]->getChildren()[j]->getNameElf() != "None" && nameFoundOnBig) {
                        Neighbors++;}

                    for (int k = 0; k< children[i]->getChildren()[j]->getChildren().size();k++){

                        if (children[i]->getChildren()[j]->getChildren()[k]->getNameElf() == findElf) {
                            nameFoundOnMid = true;
                        }

                        cout << 3 <<children[i]->getChildren()[j]->getChildren()[k]->getNameElf()<< " "<<nameFoundOnMid<<" "<<findElf<< endl;

                        if (children[i]->getChildren()[j]->getChildren()[k]->getNameElf() != findElf
                        && children[i]->getChildren()[j]->getChildren()[k]->getNameElf() != "None" && (nameFoundOnMid||nameFoundOnBig)) {
                            Neighbors++;
                        }
                    }
                    if (nameFoundOnMid) break;
                }
            }
        }
        return Neighbors;
    }
    ~Tree() {for (int i =0;i<children.size();i++){
        delete children[i];
    }};
};