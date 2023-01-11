
#include "stl1.h"

using namespace std;
int main() {
	vector<int> numbers{ 0 };
	std::map<int,int>counter;
	for (int i : numbers)
		counter[i] = counter[i]+1;
	for (auto& dup : counter)
		if (dup.second % 2 !=0)
		cout <<  dup.first ;
	return 0;
}