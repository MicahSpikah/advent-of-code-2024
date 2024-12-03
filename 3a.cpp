#include "parse_input.h"

#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <ranges>
#include <regex>

advent_t advent( std::vector< std::string > const& input )
{
    int out{};
    std::regex word_regex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    for(auto const& line : input)
    {
        auto words_begin =
            std::sregex_iterator(line.begin(), line.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            std::smatch match = *i;
            out += std::stoi(match[1]) * std::stoi(match[2]);
        }
    }

    return out;
}
