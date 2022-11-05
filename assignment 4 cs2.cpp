
#include <iostream>
#include "dynamichash.h"
#include"linkedhash.h"
#include "employee.h"
using namespace std;
int main()
{
	employee E1("Mina", 30, 10000, 4), E2("Fawzy", 45, 5000, 8), E3("Yara", 19, 2000, 0), E4("Mariam", 32, 8000, 2), E5("Ayman", 33, 4000, 8),
		E6("Roshdy", 28, 9000, 3), E7("Aya", 26, 6000, 3), E8("Abdallah", 29, 7000, 4), E9("Fatma", 21, 3000, 1);

	linkedhash hash;
	dynamichash hash2;
	cout << "Linked list hash: \n";
	hash.Insert(E1);
	hash.Insert(E2);
	hash.Insert(E3);
	hash.Insert(E4);
	hash.Insert(E5);
	hash.Insert(E6);
	hash.Insert(E7);
	hash.Insert(E8);
	hash.Insert(E9);
	hash.print();
	hash.calccols();


	cout << "Dynamic array hash: \n";

	hash2.insert(E1);
	hash2.insert(E2);
	hash2.insert(E3);
	hash2.insert(E4);
	hash2.insert(E5);
	hash2.insert(E6);
	hash2.insert(E7);
	hash2.insert(E8);
	hash2.insert(E9);
	hash2.remove(E1);
	hash2.print();
	hash2.calccols();
}


