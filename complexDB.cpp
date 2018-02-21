//
// Created by ameen on 2/18/2018.
//
#include "complexDB.h"
#include <fstream>

complexDB::complexDB(const complexType& a){
    max_size = 1;
    storage =  new complexType[max_size];
    storage[0] = a;
}

complexDB::~complexDB(){
    delete [] storage;
}

void complexDB::list (std::ostream& out){
   for(int i = 0; i < max_size; i++){
       for (int j = 0; j < max_size-i-1; j++) {
            if(storage[j] > storage[j+1]){
                swap(storage[j], storage[j+1]);
            }
        }
    }
    for(int i = 0; i < max_size; i++){
        out << storage[i] <<endl;
    }
}

bool complexDB::deleteComplex(const complexType& a ){
    for(int i = 0; i < max_size;){
        if( a == storage[i]){
            for(int j = i; j < max_size-1; j++){
                storage[j] = storage[j+1];
            }
            //does not delete the free element
            max_size--;
        }
        else i++;
    }
    return false;
}

complexType* complexDB::add(const complexType& a){
    complexType * tempStorage = new complexType[max_size + 1];
    for(int i = 0; i < max_size; i++){
        tempStorage[i] = storage[i];
    }
    tempStorage[max_size] = a;
    delete [] storage;
    max_size++;
    storage = new complexType[max_size];
    for(int i = 0; i < max_size; i++){
        storage[i] = tempStorage[i];
    }
    delete [] tempStorage;
    return storage;
}

bool complexDB::save(string& name){
    ofstream outfile("C:\\Users\\ameen\\Desktop\\test.txt");
    if (outfile.is_open()){
        list(outfile);
        outfile.close();
        return true;
    }
    else {
        cout << "Could not open file."<< endl;
        return false;
    }
}