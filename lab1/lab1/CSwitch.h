#ifndef   __CSwitch__
#define   __CSwitch__

class CSwitch {
	int state;

	public:
		CSwitch();
		~CSwitch();

		void turnon();
		void turnoff();
		void print();

};


#endif