#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // input
    int K, N, B, L;
    cin >> K >> N >> B >> L;
    vector<pair<int, int>> stops(N);

    for (int i = 0; i < N; i++) {
        cin >> stops[i].first >> stops[i].second;
    }
    // add last stop
    stops.push_back(make_pair(K, 0));
    
    int count = 0, curr = 0, last = 0, n = stops.size();
    double tank = B;
    
    while (curr < (n - 1))
    {
        last = curr;
        // find the last gas station where we can refuel
        while (curr < (n - 1))
        {
            // printf("Distance to go: %d | Distance we can go: %f\n", stops[curr + 1].first, tank / (double)L * 100); // DEBUG
            if (stops[curr + 1].first > tank / (double)L * 100) break;
            curr++;
        }

        // can't refuel at the same gas station
        if (last == curr && curr > 0) break;

        // we haven't passed the last gas station
        if (curr < (n - 1))
        {
            // since we're looking at the absolute distances of gas stations, no need to substract the consumed gas
            tank += stops[curr].second;
            // printf("\nRefuel at stop #%d | Tank is now %f\n", curr, tank); // DEBUG
            count++;
        }
    }

    printf("%d\n", count);   
}

