
#include "common.h"
#include "CPUInfo.h"
using namespace std;

int main() {

	cout << CPUInfo::getCpuBrand() << endl << CPUInfo::getCpuClockSpeed() << endl << CPUInfo::getCpuCores() << endl;

    return 0;
}

