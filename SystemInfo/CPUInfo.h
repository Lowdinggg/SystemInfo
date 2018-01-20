#pragma once
#include "common.h"
#include <vector>
#include <sstream>
class CPUInfo {
public:
	static std::string getCpuBrand();
	static int getCpuCores();
	static double getCpuClockSpeed();
private:
	static SYSTEM_INFO getSysInfo() {
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		return sysInfo;
	};
	static bool replace(std::string& str, const std::string& from, const std::string& to) /*https://stackoverflow.com/a/3418285*/ {
		size_t start_pos = str.find(from);
		if(start_pos == std::string::npos)
			return false;
		str.replace(start_pos, from.length(), to);
		return true;
	}

};

