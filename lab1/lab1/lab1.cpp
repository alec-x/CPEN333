// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "CBulb.h"
#include <iostream>
#include <stdio.h>

int main()
{
	int bulbState;
	int bulbWatts;

	//CBulb constructor
	CBulb TestBulb;

	//Test 'on' and 'Print'
	std::cout << std::endl;
	TestBulb.on();
	std::cout << "Set bulb to on state." << std::endl;
	std::cout << "Testing bulb state: ";
	TestBulb.print();
	std::cout << std::endl;

	//Test 'setwatts' and 'getpower' for on state
	TestBulb.setwatts(300);
	std::cout << "Set Watts to 300." << std::endl;
	bulbWatts = TestBulb.getpower();
	std::cout << "Watts in bulb for on state: ";
	std::cout << bulbWatts << std::endl << std::endl;

	//Test 'off' and 'Print'
	TestBulb.off();
	std::cout << "Set bulb to off state." << std::endl;
	std::cout << "Testing bulb state: ";
	TestBulb.print();
	std::cout << std::endl;

	//Test 'getpower' for off state
	bulbWatts = TestBulb.getpower();
	std::cout << "Watts in bulb for off state: ";
	std::cout << bulbWatts << std::endl << std::endl;

	//Test 'getstate'
	bulbState = TestBulb.getstate();
	std::cout << "Value of state of bulb: ";
	std::cout << bulbState << std::endl << std::endl;
	
	//Test 'destructor'
	std::cout << "Destroying bulb." << std::endl;
	TestBulb.~CBulb();
	std::cout << "Getting state of destroyed bulb: " << std::endl;
	TestBulb.getstate(); //not sure if destructor worked? This line just calls the destructor again
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
