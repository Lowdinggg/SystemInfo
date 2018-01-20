#include "CPUInfo.h"
using namespace std;

 std::string CPUInfo::getCpuBrand() {
	 int CPUInfo[4] = {-1};
	 unsigned   nExIds, i = 0;
	 char CPUBrandString[0x40];

	 __cpuid(CPUInfo, 0x80000000);
	 nExIds = CPUInfo[0];
	 for(i = 0x80000000; i <= nExIds; ++i) {
		 __cpuid(CPUInfo, i);

		 if(i == 0x80000002)
			 memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		 else if(i == 0x80000003)
			 memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		 else if(i == 0x80000004)
			 memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	 }

	 return string(CPUBrandString);
}
 int CPUInfo::getCpuCores() {
	 return getSysInfo().dwNumberOfProcessors;
}
 double CPUInfo::getCpuClockSpeed() {
	 vector<string> vec;
	 stringstream ss(getCpuBrand());
	 string temp;
	 while(ss >> temp)
		 vec.push_back(temp);
	 string ret = vec[vec.size() - 1];
	 replace(ret, "GHz", "");
	 return stod(ret);
}

