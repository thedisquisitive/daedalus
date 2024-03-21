#pragma once
#include <vector>

namespace DAEDALUS
{

	class DaedalusBus {
	private:
		std::vector<bool> dataLine;
		std::vector<bool> addressLine;
		std::vector<bool> clockLine;
	public:
		virtual unsigned int initializeBus(unsigned int dataLines, unsigned int addressLines, unsigned int clockLines) = 0;
		virtual unsigned int transmitData() = 0;
		virtual unsigned int receiveData() = 0;
		virtual ~DaedalusBus() = 0;
		virtual unsigned int setAddressLine(std::vector<bool> addressLine) = 0;
		virtual unsigned int setDataLine(std::vector<bool> dataLine) = 0;
		virtual unsigned int setClockLine(std::vector<bool> clockLine) = 0;
		virtual unsigned int readAddressLine() = 0;
		virtual unsigned int readDataLine() = 0;
		virtual unsigned int readClockLine() = 0;
		virtual std::vector<bool> getAddressLine() = 0;
		virtual std::vector<bool> getDataLine() = 0;
		virtual std::vector<bool> getClockLine() = 0;
	};

	class DaedalusBasicBus : public DaedalusBus {
	public:
		unsigned int initializeBus(unsigned int dataLines, unsigned int addressLines, unsigned int clockLines);
		unsigned int transmitData();
		unsigned int receiveData();
		unsigned int setAddressLine(std::vector<bool> addressLine);
		unsigned int setDataLine(std::vector<bool> dataLine);
		unsigned int setClockLine(std::vector<bool> clockLine);
		unsigned int readAddressLine();
		unsigned int readDataLine();
		unsigned int readClockLine();
		std::vector<bool> getAddressLine();
		std::vector<bool> getDataLine();
		std::vector<bool> getClockLine();
	};

}
