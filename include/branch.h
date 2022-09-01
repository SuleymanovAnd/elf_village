#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int getCount (int start, int end){
    srand(time(nullptr));
    return rand() %(end - start) + start;}

class Branch {
    string elfName;
  //  Branch* parent;
    vector <Branch*> children;
  //  class Tree* tparent;
    void createHouse() {
        cout << "Input name of elf";
        cin >> elfName;
    }
public:

    string getNameElf (){
        return elfName;
    }

    vector <Branch*> getChildren (){
        return children;
    }
   // void setTree (Tree* tr){tparent = tr;}

    Branch(int count) {
        if (count>=3) { // если ставить условие проверки (parent == nullptr - то цикл for начинается заново
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
};

