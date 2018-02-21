//
// Created by ameen on 2/18/2018.
//

#ifndef LAB3_COMPLEXDB_H
#define LAB3_COMPLEXDB_H
#include "complexType.h"

class complexDB{
public:
    complexDB(const complexType&);
    ~complexDB();
    void list (ostream& out);
    bool deleteComplex (const complexType& a );
    complexType* add (const complexType& a);
    bool save(string&);
private:
    int size;
    int max_size;
    complexType * storage;
};
#endif //LAB3_COMPLEXDB_H
