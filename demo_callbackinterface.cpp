#include <stdio.h>
#include "CppTimerCallbackInterface.h"
#include <unistd.h>
#include <thread>

class Callback1 : public CppTimerCallbackInterface::Runnable {
	void run() {
		fprintf(stdout,"Bah! ");
		fflush(stdout);
	}
};


class Callback2 : public CppTimerCallbackInterface::Runnable {
	void run() {
		fprintf(stdout,"Buh! \n");
		fflush(stdout);
	}
};


int main( int, const char**) {
	CppTimerCallbackInterface demoTimer1;
	Callback1 callback1;
	demoTimer1.registerEventRunnable(callback1);
	demoTimer1.startns(250000000);
	CppTimerCallbackInterface demoTimer2;
	Callback2 callback2;
	demoTimer2.registerEventRunnable(callback2);
	demoTimer2.startms(1000);

	// do nothing and keep sleeping for 2 secs
	std::this_thread::sleep_for(std::chrono::seconds(2));

        demoTimer1.stop();
        demoTimer2.stop();

	printf("\n");

}
