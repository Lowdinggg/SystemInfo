#include "MemInfo.h"
using namespace std;


 long MemInfo::getFreeMemory() {
	 return getMemStatus().ullAvailPhys;
 }
 long MemInfo::getTotalMemory() {
	 return getMemStatus().ullTotalPhys;
 }
 long MemInfo::getFreeDiskSpace() {
	 return 0;
 }
 long MemInfo::getTotalDiskSpace(){
	 return 0;
 }
 long MemInfo::getMemoryUsage() {
	 return getMemStatus().dwMemoryLoad;
 }