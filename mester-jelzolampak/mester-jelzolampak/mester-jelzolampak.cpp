#include <iostream>
#include <vector>

using namespace std;

/*
4 5 6
1 3
1 4
2 1
2 4
3 2
3 3
*/

int main()
{
    int INTMAX = 2147483647;
    int W, H, N;
    cin >> H >> W >> N;

    vector<vector<int>> grid(H, vector<int>(W));
    
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> x >> y;
        grid[x - 1][y - 1] = 1;
    }

    vector<int> route_ends{ 0 };

    // iterate rows
    for (int i = 0; i < H; i++)
    {
        // get the x position, from where additional fields can be covered
        int covered_from = INTMAX;
        for (int end : route_ends)
            if(end < covered_from) 
                covered_from = end;
        
        // check uncovered fields
        int max = -1;
        for (int j = 0; j < covered_from; j++)
            if (grid[i][j] == 1 && j > max)
                max = j;

        // if max is -1, there is no need to add another route, else add max
        if (max != -1)
            route_ends.push_back(max);

        // now check covered fields, and find the route that can cover most fields
        // e.g. find the route end closest to min while being lte to min
        int min = INTMAX;
        max = -1;
        for (int j = covered_from; j < W; j++)
        {
            if (grid[i][j] == 1 && j < min) min = j;
            if (grid[i][j] == 1 && j > max) max = j;
        }

        // row is empty
        if (max == -1) continue;

        int best = INTMAX, best_index = -1;
        for (int j = 0; j < route_ends.size(); j++)
        {
            // cannot cover all
            if (route_ends[j] > min) continue;

            int diff = abs(min - route_ends[j]);
            if (diff < best)
            {
                best = diff;
                best_index = j;
            }
        }

        route_ends[best_index] = max;
    }

    std::cout << route_ends.size() << "\n";

    /*
    for (int item : route_ends)
    {
        cout << item << "\n";
    }
    */

}
