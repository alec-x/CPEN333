#include "pch.h"
#include "CBulb.h"
#include <iostream>
#include <stdio.h>

CBulb::CBulb() {
	state = 0;
	watts = 0;
	std::cout << "CBulb default constructor being called..." << std::endl;
}

CBulb::~CBulb() {
	std::cout << "CBulb destructor being called..." << std::endl;
}

CBulb::CBulb(int initialWatts) : state(0), watts(initialWatts) {

	std::cout << "CBulb constructor being called..." << std::endl;
}

void CBulb::print() {
	if (state == 1) {
		std::cout << "on" << std::endl;
	}
	else if (state == 0) {
		std::cout << "off" << std::endl;
	}

}

void CBulb::setwatts(int newWatts) {
	watts = newWatts;
}

int CBulb::getstate() {
	return state;
}

int CBulb::getpower() {
	if (getstate()) {
		return watts;
	}
	else {
		return 0;
	}

}

void CBulb::on() {
	state = 1;
}

void CBulb::off() {
	state = 0;
}