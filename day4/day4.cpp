// hsingh_advent.cpp : Defines the entry point for the application.
//Just a template for everyday

#include "day4.h"

using namespace std;


void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day4/input.txt" };
	auto inputtxt = tl::views::getlines(input)
		| tl::to < std::vector>();

	int sum = 0;
	for (auto line : inputtxt)
	{   
		std::vector<int> listval;
		auto split = line
			| std::ranges::views::split(',')
			| std::ranges::views::transform([](auto&& str) { return std::string_view(&*str.begin(), std::ranges::distance(str)); });

		for (auto&& first : split)
		{
			auto split2 = first
				| std::ranges::views::split('-')
				| std::ranges::views::transform([](auto&& str) { return std::string_view(&*str.begin(), std::ranges::distance(str)); });
			for (auto&& word : split2)
			{
				listval.push_back(std::atoi(word.data()));
			}
		}
		auto leftBegin = listval.at(0);
		auto rightBegin = listval.at(2);
		auto leftEnd = listval.at(1);
		auto rightEnd = listval.at(3);
		
		if (leftBegin <= rightBegin && rightEnd <= leftEnd || rightBegin <= leftBegin && leftEnd <= rightEnd)
		{
			sum = sum + 1;
		}
		else
		{
			sum = sum;
		}
		
	}
	std::cout << sum;
}
void solution2()
{
		std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day4/input.txt" };
		auto inputtxt = tl::views::getlines(input)
			| tl::to < std::vector>();

		int sum = 0;
		for (auto line : inputtxt)
		{
			std::vector<int> listval;
			auto split = line
				| std::ranges::views::split(',')
				| std::ranges::views::transform([](auto&& str) { return std::string_view(&*str.begin(), std::ranges::distance(str)); });

			for (auto&& first : split)
			{
				auto split2 = first
					| std::ranges::views::split('-')
					| std::ranges::views::transform([](auto&& str) { return std::string_view(&*str.begin(), std::ranges::distance(str)); });
				for (auto&& word : split2)
				{
					listval.push_back(std::atoi(word.data()));
				}
			}
			auto leftBegin = listval.at(0);
			auto rightBegin = listval.at(2);
			auto leftEnd = listval.at(1);
			auto rightEnd = listval.at(3);

			if (leftBegin <= rightBegin && rightBegin <= leftEnd || rightBegin <= leftBegin && leftBegin <= rightEnd)
			{
				sum = sum + 1;
			}
			else
			{
				sum = sum;
			}

		}
		std::cout << sum;

}


int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
