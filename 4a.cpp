#include "parse_input.h"

#include <algorithm>
#include <array>
#include <map>
#include <numeric>
#include <ranges>

advent_t advent( std::vector< std::string > const& input )
{
    int out{};
    for(auto const [dx,dy]: std::vector<std::pair<int,int>>{{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,-1},{-1,0},{-1,1}})
    {
        for(int x = 0; x < input.front().size(); ++x)
        if(x + dx * 3 >= 0 and x + dx * 3 < input.front().size())
        for(int y = 0; y < input.size(); ++y)
        if(y + dy * 3 >= 0 and y + dy * 3 < input.size())
        {
            if(input[y][x] == 'X' and
               input[y+dy][x+dx] == 'M' and
               input[y+2*dy][x+2*dx] == 'A' and
               input[y+3*dy][x+3*dx] == 'S')
                ++out;
        }
    }
    return out;
}
