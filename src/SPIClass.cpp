/*
------------------------------------------------------------------------
			Lepton SPI Communications
------------------------------------------------------------------------

	spiOpen() function is called by the constructor.

	It is responsible for opening the spidev device
	"devspi" and then setting up the spidev interface.

	Private member variables are used to configure spidev.

	They must be set appropriately by the constructor before
	calling	this function.

------------------------------------------------------------------------
*/

#include "SPIClass.h"
using namespace std;


int LeptonSPI::spiOpen(std::string devspi)
{
    int statusVal = -1;
    this->spifd = open(devspi.c_str(), O_RDWR);
    if(this->spifd < 0)
    {
        perror("Could not open SPI device");
        exit(1);
    }

    statusVal = ioctl (this->spifd, SPI_IOC_WR_MODE, &(this->mode));
    if(statusVal < 0)
    {
        perror("Could not set SPIMode (WR). ioctl failure.");
        exit(1);
    }

    statusVal = ioctl (this->spifd, SPI_IOC_RD_MODE, &(this->mode));
    if(statusVal < 0)
    {
      perror("Could not set SPIMode (RD). ioctl failure.");
      exit(1);
    }

    statusVal = ioctl (this->spifd, SPI_IOC_WR_BITS_PER_WORD, &(this->bitsPerWord));
    if(statusVal < 0)
    {
      perror("Could not set SPI bitsPerWord (WR). ioctl failure.");
      exit(1);
    }

    statusVal = ioctl (this->spifd, SPI_IOC_RD_BITS_PER_WORD, &(this->bitsPerWord));
    if(statusVal < 0)
    {
      perror("Could not set SPI bitsPerWord (RD). ioctl failure.");
      exit(1);
    }

    statusVal = ioctl (this->spifd, SPI_IOC_WR_MAX_SPEED_HZ, &(this->speed));
    if(statusVal < 0)
    {
      perror("Could not set SPI speed (WR). ioctl failure.");
      exit(1);
    }

    statusVal = ioctl (this->spifd, SPI_IOC_RD_MAX_SPEED_HZ, &(this->speed));
    if(statusVal < 0)
    {
      perror("Could not set SPI speed (RD). ioctl failure.");
      exit(1);
    }
    return statusVal;
}


/*
------------------------------------------------------------------------
	spiClose(): Responsible for closing the spidev interface.
	Called in destructor.
------------------------------------------------------------------------
*/

int LeptonSPI::spiClose()
{
    int statusVal = -1;
    statusVal = close(this->spifd);
        if(statusVal < 0)
	{
	  perror("Could not close SPI device.");
	  exit(1);
    	}
    return statusVal;
}


/*
------------------------------------------------------------------------
	This function writes data "data" of length "6" to the
	spidev device. Data shifted in from the spidev device is
	saved back into "data".
------------------------------------------------------------------------
*/

int LeptonSPI::spiWriteRead( unsigned char *data, int length)
{

  struct spi_ioc_transfer spi[length];
  int i = 0;
  int retVal = -1;

  // One SPI transfer for each byte

  for (i=0; i<length; i++)
  {

    spi[i].tx_buf        = (unsigned long)(data + i);	// transmit from "data"
    spi[i].rx_buf        = (unsigned long)(data + i);	// receive into "data"
    spi[i].len           = sizeof(*(data + i));
    spi[i].delay_usecs   = 0;
    spi[i].speed_hz      = this->speed;
    spi[i].bits_per_word = this->bitsPerWord;
    spi[i].cs_change	 = 0;
  }

  retVal = ioctl (this->spifd, SPI_IOC_MESSAGE(length), &spi);

  if(retVal < 0)
  {
    perror("Problem transmitting spi data.");
    exit(1);
  }

  return retVal;

}


/*
------------------------------------------------------------------------
	Default constructor. Set member variables to
	default values and then call spiOpen().
------------------------------------------------------------------------
*/

LeptonSPI::LeptonSPI()
{
    this->mode = SPI_MODE_0 ;
    this->bitsPerWord = 8;
    this->speed = 16000000;
    this->spifd = -1;

    this->spiOpen(std::string("/dev/spidev0.0"));

}


/*
------------------------------------------------------------------------
	Overloaded constructor. Let user set member variables
	and then call spiOpen().
------------------------------------------------------------------------
*/

LeptonSPI::LeptonSPI(std::string devspi, unsigned char spiMode, unsigned int spiSpeed, unsigned char spibitsPerWord)
{
    this->mode = spiMode;
    this->bitsPerWord = spibitsPerWord;
    this->speed = spiSpeed;
    this->spifd = -1;

    this->spiOpen(devspi);

}


/*
------------------------------------------------------------------------
	Destructor: calls spiClose().
------------------------------------------------------------------------
*/

LeptonSPI::~LeptonSPI()
{
    this->spiClose();
}



