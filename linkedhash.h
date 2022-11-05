#pragma once
#include <iostream>
#include "employee.h"
const int SIZE = 9;
using namespace std;
struct linkedhashEntry {
    int key;
    employee value;
    linkedhashEntry* next;
    linkedhashEntry(employee value) {
        this->key = value.getsalary();
        this->value = value;
        this->next = NULL;
    }
};
class linkedhash : public employee
{
public:
    linkedhashEntry** htable;
    linkedhash() {
        htable = new linkedhashEntry * [SIZE];
        for (int i = 0; i < SIZE; i++)
            htable[i] = NULL;
    }
    int HashFunc(employee value) {
        return  value.getsalary() % SIZE;
    }
    void Insert(employee value) {
        int hashkey = HashFunc(value);
        linkedhashEntry* p = NULL;
        linkedhashEntry* en = htable[hashkey];
        while (en != NULL) {
            p = en;
            en = en->next;
        }
        if (en == NULL) {
            en = new linkedhashEntry(value);
            if (p == NULL) {
                htable[hashkey] = en;
            }
            else {
                p->next = en;
            }
        }
        else {
            en->value = value;
        }
    }
    void Remove(employee value) {
        int hashkey = HashFunc(value);
        linkedhashEntry* en = htable[hashkey];
        linkedhashEntry* p = NULL;
        if (en == NULL || en->key != value.getsalary()) {
            cout << "Element does not exist in hash \n ";
            return;
        }
        while (en->next != NULL) {
            p = en;
            en = en->next;
 
        }
        if (p != NULL) {
            p->next = en->next;
        }
        delete en;
    }
    void print() {
        for (int i = 0;i < 9;i++) {
            if (htable[i] != NULL) {
                cout << i+1 << ": ";
                linkedhashEntry* p = htable[i];
                while (p != NULL) {
                    cout << p->value.getname() << " ";
                    cout << p->value.getage() << " ";
                    cout << p->value.getsalary() << " ";
                    cout << p->value.getexp() << " ";
                    p= p->next;
                }
                cout << endl;
            }
        }
    }
    void calccols() {
        double count = 0;
        for (int i = 0;i < 9;i++) {
            if (htable[i] != NULL) {
                linkedhashEntry* p = htable[i];
                while (p->next != NULL) {
                    count++;
                    p = p->next;
                }
                cout << endl;
            }
        }
        cout << "collision rate is = " << (count / (double)SIZE )* 100 << "%";
        cout << endl;
        cout << endl;
        cout << endl;
    }
        ~linkedhash() {
            delete[] htable;
        }
    };
