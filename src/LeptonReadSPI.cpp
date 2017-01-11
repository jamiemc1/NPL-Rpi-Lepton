/*
-------------------------------------------------------------------------
			    Lepton Read SPI
-------------------------------------------------------------------------

	This is a test for the LeptonSPI class, the lepton object
	is instantiated using the overloaded constructor.

-------------------------------------------------------------------------
*/

#include "SPIClass.h"
using namespace std;


int main(void)
{
	LeptonSPI lepton("/dev/spidev0.1", SPI_MODE_0, 16000000, 8);
	int leptonVal = 0;
	int leptonChannel = 0;
	unsigned char data[3];
	data[0] = 1;
	data[1] = 0;
	data[2] = 0;

	cout << sizeof(data) << endl;
	while (1)
	{
		lepton.spiWriteRead(data, sizeof(data));
	}
	
	
/*	
	while(i>0)
	{
		data[0] = 1;	// First byte transmitted -> start bit
		data[1] = 0b10000000 |( ((leptonChannel & 7) << 4));
	        		// Second byte transmitted -> (SGL/DIF = 1, D2=D1=D0=0)
		data[2] = 0;	// Third byte transmitted....don't care

		lepton.spiWriteRead(data, sizeof(data));

		leptonVal = 0;
		leptonVal = (data[1]<< 8) & 0b1100000000; //merge data[1] & data[2] to get result
		leptonVal |=  (data[2] & 0xff);
		sleep(1);
		cout << "The Result is: " << leptonVal << endl;
		i--;
	}
*/

	return 0;
}
