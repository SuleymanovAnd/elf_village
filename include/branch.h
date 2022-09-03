#include <iostream>
#include <vector>
#pragma once

using namespace std;



class Branch {

  //  Branch* parent;
  //  class Tree* tparent;


    vector <Branch*> children;
    string elfName;

    void createHouse() {
        cout << "Input name of elf";
        cin >> elfName;
    }

    int getCount (int start, int end){
        srand(time(nullptr));
        return rand() %(end - start) + start;}

public:

    string getNameElf (){
        return elfName;
    }

    vector <Branch*> getChildren (){
        return children;
    }
   // void setTree (Tree* tr){tparent = tr;}

    Branch(int count) {
        if (count>=3) { // если ставить условие проверки (parent == nullptr) - то цикл for начинается заново
            children.resize(count);
            for (int i = 0; i < count; i++) {
                cout << i+1 << "Big branch" << endl;
                children[i] = new Branch(getCount(2, 3));
              //  children[i]->parent = this;
            }
        } else if (count != 0){
            createHouse();
            children.resize(count);
            for (int i = 0; i < count; i++) {
            cout<< i+1 <<" Middle branch" << endl;
            children[i] = new Branch(0);
            }
        } else {createHouse();
            return;}
    }
    ~Branch(){
        for (int i = 0; i < children.size();i++){
            delete children[i];
            children[i] = nullptr;
        }
    };
};

