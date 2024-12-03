#include "parse_input.h"

#include <charconv>
#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <ranges>

advent_t advent( std::vector< std::string > const& input )
{
    std::vector< int > col1, col2;

    for(auto const& line : input)
    {
        col1.push_back(0);
        col2.push_back(0);
        std::from_chars(line.data(), line.data() + 5, col1.back());
        std::from_chars(line.data() + 8, line.data() + 13, col2.back());
    }

    std::uint32_t out{};

    for(auto const loc : col1)
    {
        out += loc * std::ranges::count(col2, loc);
    }

    return out;
}
