#pragma once
#include <vector>
#include <iostream>

namespace DAEDALUS
{
	enum class DaedalusBusErrorCodes {
		DAEDALUS_BUS_ERROR_SUCCESS = 0,
		DAEDALUS_BUS_ERROR_INVALID_DATA_LINE = 1,
		DAEDALUS_BUS_ERROR_INVALID_ADDRESS_LINE = 2,
		DAEDALUS_BUS_ERROR_INVALID_CLOCK_LINE = 3,
		DAEDALUS_BUS_ERROR_INVALID_DATA = 4,
		DAEDALUS_BUS_ERROR_INVALID_ADDRESS = 5,
		DAEDALUS_BUS_ERROR_INVALID_CLOCK = 6,
		DAEDALUS_BUS_ERROR_INVALID_BUS = 7,
		DAEDALUS_BUS_ERROR_INVALID_BUS_INITIALIZATION = 8,
		DAEDALUS_BUS_ERROR_INVALID_BUS_TRANSMISSION = 9,
		DAEDALUS_BUS_ERROR_INVALID_BUS_RECEPTION = 10,
		DAEDALUS_BUS_ERROR_INVALID_BUS_ADDRESS_LINE_READ = 11,
		DAEDALUS_BUS_ERROR_INVALID_BUS_DATA_LINE_READ = 12,
		DAEDALUS_BUS_ERROR_INVALID_BUS_CLOCK_LINE_READ = 13,
		DAEDALUS_BUS_ERROR_INVALID_BUS_ADDRESS_LINE_SET = 14,
		DAEDALUS_BUS_ERROR_INVALID_BUS_DATA_LINE_SET = 15,
		DAEDALUS_BUS_ERROR_INVALID_BUS_CLOCK_LINE_SET = 16,
		DAEDALUS_BUS_ERROR_INVALID_BUS_ADDRESS_LINE_GET = 17,
		DAEDALUS_BUS_ERROR_INVALID_BUS_DATA_LINE_GET = 18,
		DAEDALUS_BUS_ERROR_INVALID_BUS_CLOCK_LINE_GET = 19,
		DAEDALUS_BUS_ERROR_INVALID_BUS_DESTRUCTION = 20
	};

	enum class DaedalusBusData {
		DAEDALUS_BUS_DATA_LOW = 0,
		DAEDALUS_BUS_DATA_HIGH = 1
	};

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
	private:
		std::vector<bool> dataLine;
		std::vector<bool> addressLine;
		std::vector<bool> clockLine;
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
