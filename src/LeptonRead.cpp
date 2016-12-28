//--------------------------------
//	    Lepton Read
//--------------------------------
//
//	Provides a testbed for
//	interacting with the
//	FLIR Lepton through the
//	GPIO pins.
//
//--------------------------------

#include <chrono>
#include <iomanip>

#include <iostream>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"
using namespace std;
using namespace std::chrono;


int clock_gpio( GPIOClass* gpio, int freq )
{
	struct timespec delay = {0};
	delay.tv_sec = 0;
	delay.tv_nsec = ((1/freq)*1000000000);
	while (1)
	{
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		gpio->setval_gpio("0");
		//nanosleep(&delay, (struct timespec *)NULL);

		gpio->setval_gpio("1");
		//nanosleep(&delay, (struct timespec *)NULL);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(t2-t1).count();

		cout << "Time: " << setw(6) << duration << endl; 
	}
	return 0;
}


int main(void)
{
	string inputstate;

	GPIOClass* gpio08 = new GPIOClass("8");		// Create new GPIO object for GPIO08
	GPIOClass* gpio09 = new GPIOClass("9");		// Create new GPIO object for GPIO09
	GPIOClass* gpio10 = new GPIOClass("10");	// Create new GPIO object for GPIO10
	GPIOClass* gpio11 = new GPIOClass("11");	// Create new GPIO object for GPIO11
	
	gpio08->export_gpio();				// Export GPIO08
	gpio09->export_gpio();				// Export GPIO09
	gpio10->export_gpio();				// Export GPIO10
	gpio11->export_gpio();				// Export GPIO11
	cout << "GPIO pins exported." << endl;

	gpio08->setdir_gpio("out");			// Set GPIO08 to output
	gpio09->setdir_gpio("in");			// Set GPIO09 to input
	gpio10->setdir_gpio("out");			// Set GPIO10 to output
	gpio11->setdir_gpio("out");			// Set GPIO11 to output
	cout << "GPIO pin directions set." << endl;

	gpio08->setval_gpio("0");			// Set CS low to select SPI chip 
	clock_gpio(gpio11, 2);			// Start the Master clock

	cout << "Clock is running." << endl;
/*

	while (1)
	{
		usleep(2000000);				// Wait for 2 seconds

		gpio08->getval_gpio(inputstate);	// Read state of GPIO08 input pin
		cout << "Current input pin GPIO08 state is " << inputstate << endl;

		gpio09->getval_gpio(inputstate);	// Read state of GPIO09 input pin
		cout << "Current input pin GPIO09 state is " << inputstate << endl;

		gpio10->getval_gpio(inputstate);	// Read state of GPIO10 input pin
		cout << "Current input pin GPIO10 state is " << inputstate << endl;

		gpio11->getval_gpio(inputstate);	// Read state of GPIO11 input pin
		cout << "Current input pin GPIO11 state is " << inputstate << endl;
		cout << endl;
	}
	cout << "Exiting..." << endl;
	return 0;
*/

}
