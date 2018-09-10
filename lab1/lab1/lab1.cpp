// lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "CBulb.h"
#include "CSwitch.h"
#include "CLamp3Bulb.h"
#include <iostream>
#include <stdio.h>

int main()
{
	int bulbState, bulbWatts, switchState;

	CBulb TestBulb;
	// === TESTING BULB ===
	// Test 'on' and 'Print'
	std::cout << std::endl;
	TestBulb.on();
	std::cout << "Set bulb to on state." << std::endl;
	std::cout << "Testing bulb state: ";
	TestBulb.print();
	std::cout << std::endl;

	// Test 'setwatts' and 'getpower' for on state
	TestBulb.setwatts(300);
	std::cout << "Set Watts to 300." << std::endl;
	bulbWatts = TestBulb.getpower();
	std::cout << "Watts in bulb for on state: ";
	std::cout << bulbWatts << std::endl << std::endl;

	// Test 'off' and 'Print'
	TestBulb.off();
	std::cout << "Set bulb to off state." << std::endl;
	std::cout << "Testing bulb state: ";
	TestBulb.print();
	std::cout << std::endl;

	// Test 'getpower' for off state
	bulbWatts = TestBulb.getpower();
	std::cout << "Watts in bulb for off state: ";
	std::cout << bulbWatts << std::endl << std::endl;

	// Test 'getstate'
	bulbState = TestBulb.getstate();
	std::cout << "Value of state of bulb: ";
	std::cout << bulbState << std::endl << std::endl;

	std::cout << "============================================" << std::endl;
	CSwitch TestSwitch;
	// === TESTING SWITCH ===
	// Test 'Print'
	std::cout << "Testing initial switch state: ";
	TestSwitch.print();
	std::cout << std::endl;

	// Test 'turnon'
	std::cout << "Setting state to on.";
	TestSwitch.turnon();
	std::cout << std::endl;
	std::cout << "Testing switch state: ";
	TestSwitch.print();
	std::cout << std::endl;

	// Test 'turnoff'
	std::cout << "Setting state to off.";
	TestSwitch.turnoff();
	std::cout << std::endl;
	std::cout << "Testing switch state: ";
	TestSwitch.print();
	std::cout << std::endl;

	std::cout << "============================================" << std::endl;
	CLamp3Bulb TestCLamp3Bulb(100, 200, 300);
	// === TESTING 3 BULB ===
	// Test 'Print'
	std::cout << "Testing initial lamp state: ";
	TestCLamp3Bulb.Print();
	std::cout << std::endl;

	// Test 'LampOn'
	std::cout << "Setting state to on.";
	TestCLamp3Bulb.LampOn();
	std::cout << std::endl;
	std::cout << "Testing lamp state: ";
	TestCLamp3Bulb.Print();
	std::cout << std::endl;

	// Test 'GetPower'
	std::cout << "Get the lamp power: ";
	std::cout << TestCLamp3Bulb.GetPower();
	std::cout << std::endl;

	// Test 'LampOff'
	std::cout << "Setting state to off.";
	TestCLamp3Bulb.LampOff();
	std::cout << std::endl;
	std::cout << "Testing lamp state: ";
	TestCLamp3Bulb.Print();
	std::cout << std::endl;

	// Test 'GetPower'
	std::cout << "Get the lamp power: ";
	std::cout << TestCLamp3Bulb.GetPower();
	std::cout << std::endl;

	// Test 'exchange'
	std::cout << "Create and exchange new bulb (then destroy new bulb)." << std::endl;
	CBulb *newBulb = new CBulb(60);
	newBulb = TestCLamp3Bulb.exchange(newBulb, 0);
	delete newBulb;
	std::cout << std::endl;

	// Test 'LampOn'
	std::cout << "Setting state to on.";
	TestCLamp3Bulb.LampOn();
	std::cout << std::endl;
	std::cout << "Testing lamp state: ";
	TestCLamp3Bulb.Print();
	std::cout << std::endl;

	// Test 'GetPower'
	std::cout << "Get the lamp power: ";
	std::cout << TestCLamp3Bulb.GetPower();
	std::cout << std::endl;
	
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
