// Program name : nerf.cpp
// Author : Conner Foster
// Date last updated : 3 / 26 / 2020
// Purpose : Creates a class for nerf guns and displays objects created in a vector then displays their information

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class nerfGun {
    private:
    string model;
    int range;
    int capacity;
    int numDarts;
    

    public:
    int quantity;
    nerfGun(string model, int range, int capacity) {
        this->model = model;
        range = 100;
        capacity = 144;
        numDarts = capacity;
        if ((capacity > 144) || (capacity <= 0)) {
            throw invalid_argument("Capacity set too high");
        }


    }
        string getModel() {
            return model;
        }
        int getDartCount() {
           // if ((numDarts <= capacity) && (numDarts > 0)) {
            return numDarts; 
            /* }
            else if (numDarts < 0) {
                throw invalid_argument("Dart count cannot be negative");
            }
            else if (numDarts > capacity) {
                throw invalid_argument("Too many darts for the gun.");
            }
            else {
                throw invalid_argument("Error");
         */   }
        //}
        int getRange() {
            return range;
        }
        int getCapacity() {
            return capacity;
        }
        void fire() {
            if (capacity > 0) {
            numDarts--;
            }
            else if (capacity <= 0) {
                throw underflow_error("Gun is empty, cannot fire.");
            }
            else {
                throw invalid_argument("error");
            }
        }
        void reload(int quantity) {
            //int quantity = 0;
            cout << "How many darts would you like to reload?" << endl;
            cin >> quantity;
            numDarts += quantity;
            if (numDarts > capacity){
                throw overflow_error("You are trying to load too many darts");      
            }

        }
    

};


int main() {
    vector<nerfGun> nerfGuns;
    
    string model;
    int range;
    int capacity;
    int numDarts;
    int quantity;
    nerfGun myNerfGun(model,range,capacity);
    cout << "What is the model of your nerf gun? " << endl;
    cin >> model;
    cout << "What is the range of your nerf guns? " << endl;
    cin >> range;
    try {
    cout << "How many darts can your nerf gun hold? Must be 144 or less. " << endl;
    cin >> capacity;
    }
    catch(invalid_argument &e) {
        cout << "Error" << e.what() << endl;
    }

    numDarts = capacity;

    cout << "The Details For Your Nerf Gun are as Follows: " << endl;
    cout << "Model " << myNerfGun.getModel();
    cout << "Range: " << myNerfGun.getRange();
    cout << "Capacity: " << myNerfGun.getCapacity();
    cout << "Darts Currently Loaded: " << myNerfGun.getDartCount();
    nerfGuns.push_back(myNerfGun);

     /* for (int i = 0; i <= 7; i++) {
        cout << nerfGuns[i] << endl;
    }*/



    system("pause");
    return 0;
}