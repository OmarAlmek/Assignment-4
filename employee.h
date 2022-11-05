#pragma once
#include <iostream>
#include <string>
using namespace std;
class employee
{
private:
	int AGE;
	string NAME;
	int SALARY;
	int EXP;
public:
	employee() {
		AGE = 0;
		NAME = "";
		SALARY = 0;
		EXP = 0;
	}
	employee(string name, int age, int salary, int exp) {
		AGE = age;
		NAME = name;
		SALARY = salary;
		EXP = exp;
	}
	int getage() {
		return AGE;
	}
	string getname() {
		return NAME;
	}
	int getsalary() {
		return SALARY;
	}
	int getexp() {
		return EXP;
	}
	void set_salary(int s) {
		SALARY = s; }
	void set_exp(int e) { 
	EXP = e; }
	void set_age(int a) {
		AGE = a; }
	void set_Name(string N) { 
		NAME = N; }
};

