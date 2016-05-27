#include "Polynom.h"
#include "Task.h"


int main()
{
	/*Polynom p("1 2 3 4 5");
	std::cout << p;
	Polynom p1(p);
	std::cout << p1;
	Polynom p2("2, 3, 4");
	std::cout << p2;
	p1 = p2;
	std::cout << p1;

	p1 = p1 + p2;
	std::cout << p1;*/

	///////////////////////////////

	/*Polynom p("-8 0 14 -7");
	std::cout << p;
	Polynom p2("0 21 -14 -7");
	std::cout << p2;
	Polynom p3 = p - p2;
	std::cout << p3;*/

	///////////////////////////////

	/*Polynom p("4 2 1 1 4 4 3", 7);
	std::cout << p;
	Polynom p2("0 2 6 0 3 0 3", 7);
	std::cout << p2;
	Polynom res1 = p - p2;
	std::cout << res1;
	Polynom p3("5 1 0 4 0 4");
	Polynom res2 = res1 - p3;
	std::cout << res2;*/

	///////////////////////////////

	/*Polynom p("2 0 1", 5);
	std::cout << p;
	Polynom p2("3 1 0", 5);
	std::cout << p2;
	Polynom res1 = p * p2;
	std::cout << "RES1: " << res1;
	Polynom p3("1 3", 5);
	std::cout << p3;
	Polynom p4("2 1", 5);
	std::cout << p4;
	Polynom res2 = p3 * p4;
	std::cout << "RES2: " << res2;

	std::cout << "RES1 * RES2: " << res1 * res2;*/

	///////////////////////////////
	/*
	Polynom p("-3 2 1");
	std::cout << p;
	Polynom p2("0 0 4");
	std::cout << p2;

	Polynom pol("-8 0 2 1 4");
	std::cout << pol;

	Polynom res1 = p*p2;
	std::cout << "RES1: " << res1;
	
	pol = pol - res1;
	std::cout << pol;*/
	
	///////////////////////////////

	/*Polynom p("-8 0 2 1 4");
	Polynom p2("-3 2 1");
	Polynom res1 = p / p2;
	std::cout << res1;*/

	///////////////////////////////

	/*long in = Mod::inverse(3, 5, 7);
	std::cout << in << std::endl;
	long in2 = Mod::inverse(1, 5, 7);
	std::cout << in2 << std::endl;*/

	////////////////////////////////

	Polynom p("-8 0 2 1 4");
	Polynom p2("-3 2 1");
	Task::Task1(p, p2);

	Polynom p3("4 2 1 1 4 4 3", 7);
	Polynom p4("1 3 0 5 0 5", 7);
	Task::Task2(p3, p4);

	system("pause");
}