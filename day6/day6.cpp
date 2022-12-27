// hsingh_advent.cpp : Defines the entry point for the application.
//Just a template for everyday

#include "day6.h"

using namespace std;


void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day6/input.txt" };
	auto inputtxt = tl::views::getlines(input) | tl::to<std::vector>();
	auto &text = inputtxt[0];
    constexpr int desiredHeaderSize = 4;
    auto headerEndIndex = -1;
    for (auto i = 0; i < text.size() - desiredHeaderSize; ++i)
    {
        auto header = text.substr(i, desiredHeaderSize);
        std::ranges::sort(header);

        auto [first, last] = std::ranges::unique(header);
        header.erase(first, last);

        if (header.size() == desiredHeaderSize)
        {
            headerEndIndex = i + desiredHeaderSize;
            break;
        }
    }

    std::cout << headerEndIndex;
}

                  
void solution2()
{
    std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day6/input.txt" };
    auto inputtxt = tl::views::getlines(input) | tl::to<std::vector>();
    auto &text = inputtxt[0];
    constexpr int desiredHeaderSize = 14;
    auto headerEndIndex = -1;
    for (auto i = 0; i < text.size() - desiredHeaderSize; ++i)
    {
        auto header = text.substr(i, desiredHeaderSize);
        std::set<char> val;
        for (auto x : header)
        {
            val.insert(x);
        }

        if (val.size() == desiredHeaderSize)
        {
            headerEndIndex = i + desiredHeaderSize;
            break;
        }
    }

    std::cout << headerEndIndex;
}

int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
