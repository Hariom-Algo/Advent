// hsingh_advent.cpp : Defines the entry point for the application.
//Just a template for everyday

#include "day9.h"

using namespace std;

std::string convert(std::string text) {
	bool flag = false;
	bool flag2 = false;
	for (std::size_t i = 0; i < text.length(); ++i)
	{
		if (i > 0 && (text[i - 1] == '-') )
		{
			text[i] = std::toupper(text[i]);
			flag = true;
		}
		if (i > 0 &&  (text[i - 1] == '_'))
		{
			text[i] = std::toupper(text[i]);
			flag2 = true;
		}
	}
	if (flag)
	{
		text.erase(std::remove(begin(text), end(text), '-'), end(text));
	}
	if(flag2)
	{
		text.erase(std::remove(begin(text), end(text), '_'), end(text));
	}
	return text;
}
void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day9/input.txt" };
	auto inputtxt = tl::views::getlines(input);
	std::cout<<convert("The_Cat_Was-kawaii");

}
void solution2()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day9/input.txt" };
	auto inputtxt = tl::views::getlines(input);

}


int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
