#include "Task.h"

void Task::Task1(Polynom & dividend, Polynom & divider)
{
	Polynom res1 = dividend / divider;
	std::cout << "Polynom division with remainder" << std::endl;
	std::cout << "RESULT: " << res1;

	Polynom res2 = (divider * res1) + Polynom(res1.getRemainder(), dividend.getField());
	std::cout << "Verification of answer: " << res2;
}

void Task::Task2(Polynom & dividend, Polynom & divider)
{
	Task1(dividend, divider);
}

