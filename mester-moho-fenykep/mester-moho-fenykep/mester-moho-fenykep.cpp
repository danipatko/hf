#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end(), [](pair<int, int> p1, pair<int, int> p2) {return p1.second < p2.second; });

    int last = 0, i = 0;
    vector<int> nums;
    while (i < N) {
        if (last <= vec[i].first) {
            last = vec[i].second;
            nums.push_back(vec[i].second - 1);
        }
        i++;
    }

    printf("%I64u\n", nums.size());
    for (int& time : nums) printf("%d ", time);
    printf("\n");
}
