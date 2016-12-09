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


#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GPIOClass.h"
using namespace std;


GPIOClass::GPIOClass()
{
	this->gpionum = "4";		// Default is GPIO pin 4
}

GPIOClass::GPIOClass(string gnum)
{
	this->gpionum = gnum;		// Instatiate GPIOClass object for gnum
}

int GPIOClass::export_gpio()
{
	string export_str = "/sys/class/gpio/export";
	ofstream exportgpio(export_str.c_str());
					// Open export file and convert C++ to C-string
	if (!exportgpio){
		cout << "ERROR: Unable to export GPIO" << this->gpionum << "." << endl;
		return -1;
	}

	exportgpio << this->gpionum;	// Write GPIO number to export
	exportgpio.close();		// Close export file
	return 0;
}

int GPIOClass::unexport_gpio()
{
	string unexport_str = "/sys/class/gpio/unexport";
	ofstream unexportgpio(unexport_str.c_str());
					// Open unexport file and convert C++ to C-string
	if (!unexportgpio){
		cout << "ERROR: Unable to unexport GPIO" << this->gpionum << "." << endl;
		return -1;
	}

	unexportgpio << this->gpionum;	// Write GPIO number to unexport
	unexportgpio.close();		// Close unexport file
	return 0;
}

int GPIOClass::setdir_gpio(string dir)
{
	string setdir_str = "/sys/class/gpio/gpio" + this->gpionum + "/direction";
	ofstream setdirgpio(setdir_str.c_str());
					// Open direction file for GPIO
	if (!setdirgpio){
		cout << "ERROR: Unable to set direction of GPIO" << this->gpionum << "." << endl;
		return -1;
	}

	setdirgpio << dir;		// Write direction to direction file
	setdirgpio.close();		// Close direction file
	return 0;
}

int GPIOClass::setval_gpio(string val)
{
	string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
	ofstream setvalgpio(setval_str.c_str());
					// Open value file for GPIO
	if (!setvalgpio){
		cout << "ERROR: Unable to set vale of GPIO" << this->gpionum << "." << endl;
		return -1;
	}

	setvalgpio << val;		// Write value to value file
	setvalgpio.close();		// Close value file
	return 0;
}

int GPIOClass::getval_gpio(string& val){
	string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
	ifstream getvalgpio(getval_str.c_str());
					// Open value file for GPIO
	if (!getvalgpio){
		cout << "ERROR: Unable to get value of GPIO" << this->gpionum << "." << endl;
		return -1;
	}

	getvalgpio >> val;		// Read GPIO value

	if (val != "0")
		val = "1";
	else
		val = "0";

	getvalgpio.close();		// Close the value file
	return 0;
}

string GPIOClass::get_gpionum(){
	return this->gpionum;
}

