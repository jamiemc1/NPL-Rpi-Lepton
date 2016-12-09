//--------------------------------
//	     GPIO Test 1
//--------------------------------
//
//	Provides a testbed for
//	interacting with the
//	Raspberry Pi through the
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
	GPIOClass* gpio4 = new GPIOClass("4");		// Create new GPIO object for GPIO4
	GPIOClass* gpio17 = new GPIOClass("17");	// Create new GPIO object for GPIO17

	gpio4->export_gpio();				// Export GPIO4
	gpio17->export_gpio();				// Export GPIO17
	cout << "GPIO pins exported." << endl;

	gpio4->setdir_gpio("out");			// Set GPIO4 to output
	gpio17->setdir_gpio("in");			// Set GPIO17 to input
	cout << "GPIO pin directions set." << endl;

	while (1)
	{
		usleep(500000);				// Wait for 0.5 seconds
		gpio17->getval_gpio(inputstate);	// Read state of GPIO17 input pin
		cout << "Current input pin state is " << inputstate << endl;
		if (inputstate == "0")			// If input is "0" (i.e. button pressed)
		{
			cout << "Input pin state is pressed.\nWill check input pin state in 20 milliseconds." << endl;
			usleep(20000);
			gpio17->getval_gpio(inputstate);
							// Checking again to identify it is not noise
			if (inputstate == "0")
			{
				cout << "Input pin state is definitely pressed.\nTurning LED on." << endl;
				gpio4->setval_gpio("1");
							// Turn LED on
			cout << "Waiting until pin is released..." << endl;
			while (inputstate == "0"){
				gpio17->getval_gpio(inputstate);
			};
			cout << "Pin is released." << endl;
			}
			else
				cout << "Input pin state is definitely released." << endl;
		}
		gpio4->setval_gpio("0");
	}
	cout << "Exiting..." << endl;
	return 0;
}
