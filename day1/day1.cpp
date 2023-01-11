// hsingh_advent.cpp : Defines the entry point for the application.
//

#include "day1.h"

using namespace std;

/*
while (i != e)
{
	auto it = std::find(i, e, "");
	std::vector<int> st;
	std::transform(i, it, std::back_inserter(st), [](const std::string& str) { return std::stoi(str); });
	result.push_back(std::accumulate(begin(st), end(st), 0));
	if (it == e) break;
	i = it + 1;
}
*/
void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day1/input.txt" };
	std::vector<int> result;

	//split based on whitespace
	auto v = tl::views::getlines(input)
		| tl::to < std::vector>()
		| std::views::split("");

	for (auto num : v)
	{
		std::vector<int> temp;
		auto st = std::transform(begin(num), end(num), std::back_inserter(temp), [](const std::string& str) { return std::stoi(str); });
		result.push_back(std::accumulate(begin(temp), end(temp), 0));
	}
	std::cout << std::ranges::max(result);
}

void solution2()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day1/input.txt" };
	auto v = tl::views::getlines(input)
		| tl::to < std::vector>()
		| std::views::split("");

	std::vector<int> result;
	auto i = begin(v), e = end(v);
	for (auto num : v)
	{
		std::vector<int> temp;
		auto st = std::transform(begin(num), end(num), std::back_inserter(temp), [](const std::string& str) { return std::stoi(str); });
		result.push_back(std::accumulate(begin(temp), end(temp), 0));
	}
	std::sort(begin(result),end(result),std::greater<int>());
	cout << std::accumulate(begin(result), begin(result) + 3, 0);

}




int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	solution1();
	auto stop = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "\Solution 1 executed in " << durationMs.count() << " ms.\n\n";
	cout << "\n";
	start = std::chrono::high_resolution_clock::now();
	solution2();
	stop = std::chrono::high_resolution_clock::now();
	durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "\nSolution 2 executed in " << durationMs.count() << " ms.\n\n";
 	return 0;
}
