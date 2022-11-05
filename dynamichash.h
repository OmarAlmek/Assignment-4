#pragma once
#include<iostream>
#include<string>
#include"employee.h"
using namespace std;
const int SIZ = 9; 
class dynamichash
{

    private:
        int emp;
        employee* htable;
        int Hash(int salary) { 
            return salary % SIZ; 
        }
        int col;
    public:
        dynamichash() {
            emp = 0;
            col = 0;
            htable = new employee[SIZ];
        }
        ~dynamichash() {
            delete[]htable;
        }
          void remove(employee removed) {
            int key = Hash(removed.getsalary());
            if (htable[key].getsalary() == NULL)
                cout << "Element does not exist in hash\n";
            else if (htable[key].getsalary() == removed.getsalary()) {
                htable[key].set_Name("");
                htable[key].set_age(0);
                htable[key].set_exp(0);
                htable[key].set_salary(0);
                emp--;
            }
            else {
                for (int i = 0;i < SIZ;i++) {
                    if (htable[i].getsalary() == removed.getsalary()) {
                        htable[key].set_Name("");
                        htable[key].set_age(0);
                        htable[key].set_exp(0);
                        htable[key].set_salary(0);
                        emp--;
                    }
                }
            }
        }
        void insert(employee inserted) {
            int key = Hash(inserted.getsalary());
            if (htable[key].getsalary() == NULL) {
                htable[key] = inserted;
                emp++;
            }
            else {
                while (htable[key].getsalary() != NULL && htable[key].getsalary() != inserted.getsalary()) {
                    key = (key + 1) % 10;
                }
                if (htable[key].getsalary() == NULL) {
                    htable[key] = inserted;
                    emp++;
                    col++;
                }
                else cout << "Element already exists";
            }
        }
        void print() {
            for (int i = 0;i < SIZ;i++) {
                cout << i+1 << ": ";
                if (htable[i].getsalary() != NULL) {
                    cout << htable[i].getname() << " ";
                    cout << htable[i].getage() << " ";
                    cout << htable[i].getsalary() << " ";
                    cout << htable[i].getexp() << " ";
                    cout << "\n";
                }
                else  cout << "\n";
            }
        }
       void calccols() {
           cout << "collision rate is: " << ((double)col / (double)emp) * 100<< "%" << endl;
        }
    };

