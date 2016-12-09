#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

//--------------------------------
//	     GPIO Class
//--------------------------------
//
//	Defines the GPIO class,
//	from which objects can
//	control a GPIO pin on
//	the Raspberry Pi.
//
//--------------------------------

#include <string>
using namespace std;

class GPIOClass
{
	public:
		GPIOClass();			// Default GPIO object
		GPIOClass(string x);		// User-defined GPIO object	
		
		int export_gpio();		// Exports GPIO
		int unexport_gpio();		// Unexports GPIO

		int setdir_gpio(string dir);	// Set GPIO direction
		int setval_gpio(string val);	// Set GPIO value
		int getval_gpio(string& val);	// Get GPIO value

		string get_gpionum();		// Get GPIO number

	private:
		string gpionum;			// GPIO number of object

};

#endif
