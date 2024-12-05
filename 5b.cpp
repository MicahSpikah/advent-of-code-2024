#include "parse_input.h"

#include <charconv>
#include <algorithm>
#include <array>
#include <map>
#include <set>
#include <numeric>
#include <ranges>

std::vector< int > readAllInts( std::string const& line )
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
    return in;
}

advent_t advent( std::vector< std::string > const& input )
{
    int out{};
    constexpr int part1 = 1176;

    std::set<std::pair<int, int>> precedes;

    for(int i = 0; i < part1; ++i)
    {
        int a, b;
        std::sscanf(input[i].data(), "%d|%d", &a, &b);
        precedes.insert({a,b});
    }

    for(int i = part1 + 1; i < input.size(); ++i)
    {
        auto pages = readAllInts(input[i]);
        bool sorted = true;
        for(int j = 0; j < pages.size() and sorted; ++j)
            for(int k = j + 1; k < pages.size() and sorted; ++k)
                if(precedes.contains({pages[k],pages[j]}))
                   sorted = false;
        
        if(not sorted)
        {
            while( not sorted )
            {
                sorted = true;
                for(int j = 0; j < pages.size() / 2 + 1 and sorted; ++j)
                    for(int k = j + 1; k < pages.size() and sorted; ++k)
                        if(precedes.contains({pages[k],pages[j]}))
                        {
                            std::swap( pages[j], pages[k] );
                            sorted = false;
                        }
            }
            out += pages[ pages.size() / 2 ];
        }
    }

    return out;
}
