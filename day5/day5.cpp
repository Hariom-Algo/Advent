// hsingh_advent.cpp : Defines the entry point for the application.
//Just a template for everyday

#include "day5.h"

using namespace std;


void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day5/input.txt" };
	auto inputtxt = tl::views::getlines(input) | tl::to<std::vector>();
	auto end = std::ranges::find(inputtxt, "");
	auto rowindex = *(--end);
	// *(end - 1);value is   1   2   3 .carefull whitespace at the end
	auto numberOfRow = *(std::end(rowindex) - 2) - '0';
	std::vector<std::stack<char>> stacks(numberOfRow);
	for (auto& line : std::ranges::subrange(begin(inputtxt), end) | std::views::reverse)
	{
		for (auto [i, stack] : tl::views::enumerate(stacks))
		{
			auto c = line[(i * 4) + 1];
			if (c != ' ')
			{
				stack.push(c);
			}
		}
	}
	for (auto& line : std::ranges::subrange(end + 2, std::end(inputtxt)))
	{
		//auto input = split<std::string>(line, ' ');
		auto input = line | std::ranges::views::split(' ') | tl::to<std::vector>();

		auto n = input[1][0] - '0';
		auto from = (input[3][0] - '0')-1;
		auto to = (input[5][0] - '0')-1;

		while(n-- > 0)
		{
			auto top = stacks[from].top();
			stacks[from].pop();
			stacks[to].push(top);
		}

	}
	auto output = std::stringstream{};
	for (const auto& currentStack : stacks)
	{
		output << currentStack.top();
	}
	std::cout << output.str();

}
void solution2()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day5/input.txt" };
	auto inputtxt = tl::views::getlines(input) | tl::to<std::vector>();
	auto end = std::ranges::find(inputtxt, "");
	auto rowindex = *(--end);
	// *(end - 1);value is   1   2   3 .carefull whitespace at the end
	auto numberOfRow = *(std::end(rowindex) - 2) - '0';
	std::vector<std::stack<char>> stacks(numberOfRow);
	for (auto& line : std::ranges::subrange(begin(inputtxt), end) | std::views::reverse)
	{
		for (auto [i, stack] : tl::views::enumerate(stacks))
		{
			auto c = line[(i * 4) + 1];
			if (c != ' ')
			{
				stack.push(c);
			}
		}
	}
	for (auto& line : std::ranges::subrange(end + 2, std::end(inputtxt)))
	{
		//auto input = split<std::string>(line, ' ');
		auto input = line | std::ranges::views::split(' ') | tl::to<std::vector>();

		auto n = input[1][0] - '0';
		auto from = (input[3][0] - '0') - 1;
		auto to = (input[5][0] - '0') - 1;

		auto crates = std::vector<char>{};
		while (n-- > 0)
		{
			auto top = stacks[from].top();
			stacks[from].pop();
			crates.emplace_back(top);
		}
		for (auto crate : crates | std::ranges::views::reverse)
		{
			stacks[to].push(crate);
		}

	}
	auto output = std::stringstream{};
	for (const auto& currentStack : stacks)
	{
		output << currentStack.top();
	}
	std::cout << output.str();

}




int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
