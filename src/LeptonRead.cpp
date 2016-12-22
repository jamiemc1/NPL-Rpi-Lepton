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


#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include "GPIOClass.h"
using namespace std;


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

	gpio08->setdir_gpio("in");			// Set GPIO08 to input
	gpio09->setdir_gpio("in");			// Set GPIO09 to input
	gpio10->setdir_gpio("in");			// Set GPIO10 to input
	gpio11->setdir_gpio("in");			// Set GPIO11 to input
	cout << "GPIO pin directions set." << endl;

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
}
