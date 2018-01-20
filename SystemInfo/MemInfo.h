#pragma once
#include "common.h"
class MemInfo {
public:
	static long getFreeMemory();
	static long getTotalMemory();
	static long getFreeDiskSpace();
	static long getTotalDiskSpace();
	static long getMemoryUsage();
private:
	static MEMORYSTATUSEX getMemStatus() {
		MEMORYSTATUSEX statex;
		statex.dwLength = sizeof(statex);
		GlobalMemoryStatusEx(&statex);
		return statex;
	}
};

