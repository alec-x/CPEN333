#ifndef   __CBulb__
#define   __CBulb__
#include <iostream>
#include <stdio.h>
#include <string>

class CBulb {
	int state; // 0 = off, 1 = on
	int watts;

	public:
		CBulb() {
			state = 0;
			watts = 0;
			std::cout << "CBulb default constructor being called..." << std::endl;
		}

		~CBulb() {
			std::cout << "CBulb destructor being called..." << std::endl;
		}

		CBulb(int initialWatts): state(0), watts(initialWatts){

			std::cout << "CBulb constructor being called..." << std::endl;
		}

		void print() {
			if (state == 1) {
				std::cout << "on" << std::endl;
			}
			else if(state == 0){
				std::cout << "off" << std::endl;
			}
			
		}

		void setwatts(int newWatts) {
			watts = newWatts;
		}

		int getstate() {
			return state;
		}

		int getpower() {
			if (getstate()) {
				return watts;
			}
			else {
				return 0;
			}
			
		}

		void on() {
			state = 1;
		}

		void off() {
			state = 0;
		}
};

#endif 
