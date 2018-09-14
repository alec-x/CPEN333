// Completed by:
// Alex von Schulmann	- 13975140
// Alec Xu				- 38108130

#ifndef   __CSwitch__
#define   __CSwitch__

class CSwitch {
	int state;

	public:
		CSwitch();
		CSwitch(int initState);
		~CSwitch();

		void turnon();
		void turnoff();
		int getstate();
		void print();

};


#endif