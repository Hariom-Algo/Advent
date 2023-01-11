
#include "stl3.h"
#include<algorithm>

#include <string>
#include <unordered_map>
#include <algorithm>

#include <cctype>
/*
DESCRIPTION:
Count the number of Duplicates
Write a function that will return the count of distinct case-insensitive alphabetic characters and numeric digits that occur more than once in the input string. The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice*/

std::size_t duplicateCount2(const char* in) {
	std::unordered_map<char, unsigned> counts;
	for (const char* c = in; *c != '\0'; ++c) {
		++counts[tolower(*c)];
	}
	return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {
		return count.second > 1;
		});
}
size_t duplicateCount(const char* in)
{
	std::map<char, int> duplicates;
	for (auto i = 0; in[i] != '\0'; i++)
	{
		auto it = duplicates.find(tolower(in[i]));
		auto contains = false;
		if (duplicates.end() != it)
		{
			contains = true;
		}
		if (contains)
		{
			duplicates[tolower(in[i])] = duplicates[tolower(in[i])] +1 ;
		}
		else
		{
			duplicates[tolower(in[i])] = 1;
		}
	}
	size_t count = 0;
	for (auto [key, val] : duplicates)
	{
		if (val >= 2)
		{
			count = count + 1;
		}
	}
	return count;
}

int main() {
	
	const  char *in = "ABBA";
	std::cout<<duplicateCount(in);
	return 0;
}