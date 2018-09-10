#ifndef   __CSwitch__
#define   __CSwitch__

class CSwitch {
	int state;

	public:
		CSwitch();
		~CSwitch();

		void turnon();
		void turnoff();
		int getstate();
		void print();

};


#endif