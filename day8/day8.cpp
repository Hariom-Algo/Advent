// hsingh_advent.cpp : Defines the entry point for the application.
//Just a template for everyday

#include "day8.h"

using namespace std;


void solution1()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day8/input.txt" };
	auto inputtxt = tl::views::getlines(input) | tl::to<std::vector>();
	auto height_map_grid = Utilities::Grid2d<int>(inputtxt[0].size(), inputtxt.size());
	for (auto y = 0; y < inputtxt.size(); ++y)
	{
		const auto& line = inputtxt[y];
		for (auto x = 0; x < line.size(); ++x)
		{
			height_map_grid.at(x, y) = line[x] - '0';
		}
	}
	auto countVisible = height_map_grid.Width() * 2 + (height_map_grid.Height() - 2) * 2;
	for (auto y = 1; y < height_map_grid.Height() - 1; ++y)
	{
		for (auto x = 1; x < height_map_grid.Width() - 1; ++x)
		{
			auto current = height_map_grid.at(x, y);

			const auto checkRow = [&height_map_grid, y, current](int i) { return height_map_grid.at(i, y) < current; };
			auto visibleFromLeft = std::ranges::all_of(std::ranges::views::iota(0, x), checkRow);
			auto visibleFromRight = std::ranges::all_of(std::ranges::views::iota(x + 1, static_cast<int>(height_map_grid.Width())), checkRow);

			const auto checkColumn = [&height_map_grid, x, current](int i) { return height_map_grid.at(x, i) < current; };
			auto visibleFromTop = std::ranges::all_of(std::ranges::views::iota(0, y), checkColumn);
			auto visibleFromBottom = std::ranges::all_of(std::ranges::views::iota(y + 1, static_cast<int>(height_map_grid.Height())), checkColumn);

			if (visibleFromLeft || visibleFromRight || visibleFromTop || visibleFromBottom)
			{
				++countVisible;
			}
		}
	}
	std::cout << countVisible;
}

long calculate_score(auto& map, int y, int x) {
	auto score = 1;
	auto height = map[y][x];

	auto new_score = 0;
	for (auto i = y + 1; i < map.size(); ++i) {
		++new_score;
		if (map[i][x] >= height) break;
	}
	score *= new_score;

	new_score = 0;
	for (auto i = y - 1; i >= 0; --i) {
		++new_score;
		if (map[i][x] >= height) break;
	}
	score *= new_score;

	new_score = 0;
	for (auto i = x + 1; i < map.size(); ++i) {
		++new_score;
		if (map[y][i] >= height) break;
	}
	score *= new_score;

	new_score = 0;
	for (auto i = x - 1; i >= 0; --i) {
		++new_score;
		if (map[y][i] >= height) break;
	}
	score *= new_score;

	return score;
}
void solution2()
{
	std::ifstream input{ "C:/Users/hsingh/source/repos/hsingh_advent/day8/input.txt" };
	auto inputtxt = tl::views::getlines(input) | tl::to<std::vector>();
	auto height_map_grid = Utilities::Grid2d<int>(inputtxt[0].size(), inputtxt.size());
	for (auto y = 0; y < inputtxt.size(); ++y)
	{
		const auto& line = inputtxt[y];
		for (auto x = 0; x < line.size(); ++x)
		{
			height_map_grid.at(x, y) = line[x] - '0';
		}
	}
	auto scenicScoresGrid = Utilities::Grid2d<int>(height_map_grid.Width(), height_map_grid.Height());
	for (auto y = 1; y < height_map_grid.Height() - 1; ++y)
	{
		for (auto x = 1; x < height_map_grid.Width() - 1; ++x)
		{
			auto current = height_map_grid.at(x, y);

			auto visibleLeft = 0;
			for (int i = x - 1; i >= 0; --i)
			{
				++visibleLeft;
				if (height_map_grid.at(i, y) >= current) { break; }
			}

			auto visibleRight = 0;
			for (int i = x + 1; i < height_map_grid.Width(); ++i)
			{
				++visibleRight;
				if (height_map_grid.at(i, y) >= current) { break; }
			}

			auto visibleTop = 0;
			for (int i = y - 1; i >= 0; --i)
			{
				++visibleTop;
				if (height_map_grid.at(x, i) >= current) { break; }
			}

			auto visibleBottom = 0;
			for (int i = y + 1; i < height_map_grid.Height(); ++i)
			{
				++visibleBottom;
				if (height_map_grid.at(x, i) >= current) { break; }
			}

			scenicScoresGrid.at(x, y) = visibleLeft * visibleRight * visibleTop * visibleBottom;
		}
	}
	std::cout << std::ranges::max(scenicScoresGrid);

}


int main()
{

	solution1();
	cout << "\n";
	solution2();
	return 0;
}
