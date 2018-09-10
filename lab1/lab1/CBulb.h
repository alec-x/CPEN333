#ifndef   __CBulb__
#define   __CBulb__

class CBulb {
	int state;
	int watts;

	public:
		CBulb();
		~CBulb();
		CBulb(int initialWatts);
		void print();
		void setwatts(int newWatts);
		int getstate();
		int getpower();
		void on();
		void off();
};

#endif 
