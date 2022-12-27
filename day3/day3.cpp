// hsingh_advent.cpp : Defines the entry point for the application.
//

#include "day3.h"

using namespace std;

int priority(char c)
{
	if (std::islower(c))
	{
		return c - 'a' + 1;
	}
	else
	{
		return c - 'A' + 27;
	}
}

int score_line(std::string line)
{
	auto sizeToCheck = line.size() / 2;
	auto first_half = line.substr(0, sizeToCheck);
	auto second_half = line.substr(sizeToCheck, sizeToCheck);
	auto result = std::ranges::find_first_of(first_half, second_half);
	//std::cout << *result << " "<<priority(*result);
	return priority(*result);
}

void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day3/input.txt" };
	auto resultcalc = tl::views::getlines(input);
	std::vector<int> tmp;
	std::ranges::transform(begin(resultcalc),end(resultcalc), std::back_inserter(tmp), score_line);
	std::cout<<std::accumulate(begin(tmp), end(tmp), 0);
}
void solution2()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day3/input.txt" };
	auto resultchunk = tl::views::getlines(input) | tl::to < std::vector>();
	auto totalScore{ 0 };
	for (auto i = 0; i < resultchunk.size(); i += 3)
	{
		auto firstGroup = resultchunk[i];
		auto secondGroup = resultchunk[i+1];
		auto thirdGroup = resultchunk[i + 2];

		std::ranges::sort(firstGroup);
		std::ranges::sort(secondGroup);
		std::ranges::sort(thirdGroup);

		auto commonGr1Gr2 = std::string();
		std::ranges::set_intersection(firstGroup, secondGroup, std::back_inserter(commonGr1Gr2));

		auto commonGr1Gr2Gr3 = std::string{};
		std::ranges::set_intersection(commonGr1Gr2, thirdGroup, std::back_inserter(commonGr1Gr2Gr3));
		
		const auto [eraseFirst, eraseLast] = std::ranges::unique(commonGr1Gr2Gr3);
		commonGr1Gr2Gr3.erase(eraseFirst, eraseLast);


		totalScore += std::accumulate(commonGr1Gr2Gr3.begin(), commonGr1Gr2Gr3.end(), 0,
			[](int sum, char c)
			{
				return sum + ('a' <= c && c <= 'z' ? 1 + c - 'a' : 27 + c - 'A');
			});
	}
	std::cout << totalScore;
}



int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
