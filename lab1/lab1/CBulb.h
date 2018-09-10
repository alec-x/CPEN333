#ifndef   __CBulb__
#define   __CBulb__

class CBulb {
	int state;
	int watts;

	public:
		CBulb();
		CBulb(int initialWatts);
		~CBulb();
		void print();
		void setwatts(int newWatts);
		int getstate();
		int getpower();
		void on();
		void off();
};

#endif 
