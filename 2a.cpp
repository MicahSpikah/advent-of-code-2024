#include "parse_input.h"

#include <algorithm>
#include <array>
#include <charconv>
#include <map>
#include <numeric>
#include <ranges>

advent_t advent( std::vector< std::string > const& input )
{
    int out{};

    for(auto const& line : input )
    {
        auto start = line.data();
        auto const end = line.data() + line.size();
        std::vector< int > in;
        while(start < end)
        {
            int result{};
            auto [ptr, ec] = std::from_chars(start, end, result);
            
            if(ec == std::errc())
            {
                start = ptr;
                in.push_back(result);
            }
            else ++start;
        }

        std::adjacent_difference(in.begin(), in.end(), in.begin());

        in.erase(in.begin());

        if(std::ranges::all_of(in, [](auto const& t){return t > 0 and t < 4;}) or std::ranges::all_of(in, [](auto const& t){return t < 0 and t > -4;}))
        {
            std::cout << line << '\n';
            ++out;
        }
    }

    return out;
}
