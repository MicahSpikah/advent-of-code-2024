#include "parse_input.h"

#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <ranges>

advent_t advent( std::vector< std::string > const& input )
{
    int out{};
    {
        for(int x = 1; x < input.front().size() - 1; ++x)
        for(int y = 1; y < input.size() - 1; ++y)
            if(input[y][x] == 'A')
            if((input[y-1][x-1] == 'M' and input [y+1][x+1] == 'S') or 
               (input[y-1][x-1] == 'S' and input [y+1][x+1] == 'M'))
            if((input[y+1][x-1] == 'M' and input [y-1][x+1] == 'S') or 
               (input[y+1][x-1] == 'S' and input [y-1][x+1] == 'M'))
               ++out;
    }
    return out;
}
