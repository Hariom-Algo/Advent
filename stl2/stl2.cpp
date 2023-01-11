
#include "stl2.h"
using namespace std;

template <typename T>
void pspan(span<T> s)
{
	cout << format("number of elements {}", s.size());
	cout << format("size  of elements {}", s.size_bytes());
	cout << "\n";
	for (auto e : s)
	{
		cout << format("{}", e);
	}
	cout << "\n";
}

class Accumul
{
public:
	static std::string accum(const std::string& s);
};
class Accumul2
{
public:
	static std::string accum(const std::string& s) {
		stringstream result;
		for (int i = 0; i < s.length(); i++)
			result << "-" << string(1, toupper(s[i])) << string(i, tolower(s[i]));
		return result.str().substr(1);
	}
};
std::string Accumul::accum(const std::string& s)
{
	std::vector<char> y;
	bool flag = true;
	int count = 0;
	char ch;
	for (auto x : s)
	{
		if (flag)
		{
			ch = std::toupper(x);
			y.push_back(ch);
			y.push_back('-');
			count = count + 1;
			flag = false;
		}
		else
		{ 
			ch = std::toupper(x);
			y.push_back(ch);
			if (x == toupper(x))
			{
				x = std::tolower(x);
			}
			for (int i = 0; i < count; i++)
			{

					y.push_back(x);

			}
			if (count < s.length()-1) 
			{
				y.push_back('-');
			}
			count = count + 1;
		}
	}
	std::string result(y.begin(), y.end());
	return result;

}


int main() {
	array<int, 5> a1{ 1,2,3,4,5 };
	array<string,1> b1{"hello frnd"};
	pspan<int>(a1);
	pspan<string>(b1);

	//structure binding
	int nums[]{ 1, 2, 3, 4, 5 };

	auto [a, b, c, d, e] = nums;

	// reference can be also used
	// auto& [a, b, c, d, e] = nums;
	cout << format(" a {} b {} c {} d {} e {}\n", a, b, c, d, e);

	tuple<int, double, string> tuplee{ 1, 2.7, "three" };

	auto [first,second,third] = tuplee;

	cout << format("first {} seconf {} third {}\n", first, second, third);

	map<string, uint64_t> inhabitants{{ "humans",7000000000 },
		                              { "pokemon",17863376 },
		                              { "klingons",24246291 },
		                              { "cats",1086881528 }};

	for (const auto& [creature, pop] : inhabitants) {

		cout << format("there are {} {}\n",pop, creature);

	}
	string s = "ZpglnRxqenU";
	auto y = Accumul::accum(s);
	auto z = Accumul2::accum(s);
	std::cout << y<<"\n"<<z;

	return 0;
}