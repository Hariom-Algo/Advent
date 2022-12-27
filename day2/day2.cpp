// hsingh_advent.cpp : Defines the entry point for the application.
//

#include "day2.h"

using namespace std;

enum class choice
{
	rock,paper,scisssors
};
enum class result
{
	loss,draw,win
};

const std::unordered_map<choice, int>  choiceScore = { {choice::rock,1},{choice::paper,2},{choice::scisssors,3} };
const std::unordered_map<result, int>  resultScore = { {result::loss,0},{result::draw,3},{result::win,6} };

struct choicePair
{
	choice m_playerchoice;
	choice m_opponentchoice;
	//Defaulting <=> automatically gives ==, !=, <, >, <=, >= for free
	// Later read herb's answer ,really cool
    // https://stackoverflow.com/questions/47466358/what-is-the-spaceship-three-way-comparison-operator-in-c
	auto operator<=>(const choicePair&) const = default;
};
namespace std {
    //specialize unordered map
    template <>
    struct hash<choicePair>
    {
        std::size_t operator()(const choicePair& k) const
        {
            using boost::hash_value;
            using boost::hash_combine;
            std::size_t seed = 0;


            // Compute individual hash values for first,
            // second and third and combine them using XOR
            // and bit shifting:
            //https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
            hash_combine(seed, hash_value(k.m_playerchoice));
            hash_combine(seed, hash_value(k.m_opponentchoice));
			return seed;
         }
    };

}

const std::unordered_map<choicePair, result> choicesToresult =
{
	{ { choice::rock, choice::paper }, result::loss },
	{ { choice::rock, choice::rock }, result::draw },
	{ { choice::rock, choice::scisssors }, result::win },
	{ { choice::paper, choice::scisssors }, result::loss },
	{ { choice::paper, choice::paper }, result::draw },
	{ { choice::paper, choice::rock }, result::win },
	{ { choice::scisssors, choice::rock }, result::loss },
	{ { choice::scisssors, choice::scisssors }, result::draw },
	{ { choice::scisssors, choice::paper }, result::win },
};
void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day2/input.txt" };
	auto inputtxt = tl::views::getlines(input);
	auto score = 0;
	for (const auto& line : inputtxt)
	{
		auto player1choice = static_cast<choice>(line[0] - 'A');
		auto player2choice = static_cast<choice>(line[2] - 'X');

		score += choiceScore.at(player2choice);
		auto result = choicesToresult.at(choicePair{ player2choice, player1choice });
		score += resultScore.at(result);
	}
	std::cout << score;
}
void solution2()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day2/input.txt" };
	auto inputtxt = tl::views::getlines(input);
	auto score = 0;
	for (const auto& line : inputtxt)
	{
		auto player2choice = static_cast<choice>(line[0] - 'A');
		auto desiredresult = static_cast<result>(line[2] - 'X');

		score += resultScore.at(desiredresult);
		
    	for (auto& [key, value] : choicesToresult)
			{
				if (key.m_opponentchoice == player2choice && value == desiredresult)
				{
					score += choiceScore.at(key.m_playerchoice);
				}
			}
		
	}
	std::cout << score;
}


int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
