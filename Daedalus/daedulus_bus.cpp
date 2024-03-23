#include "daedalus_bus.h"

namespace DAEDALUS
{
	unsigned int DaedalusBasicBus::initializeBus(unsigned int dataLines, 
												unsigned int addressLines, 
												unsigned int clockLines)
	{
		// Initialize the bus
		dataLines = dataLines;
		addressLines = addressLines;
		clockLines = clockLines;

		return 0;
	}

	unsigned int DaedalusBasicBus::setAddressLine(std::vector<bool> address)
	{
		addressLine = address;

		return 0;
	}
}