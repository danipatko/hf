#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> students(N);
    vector<int> schools(M), caps(M), choices(N, -1), pain(N, -1);

    for (int i = 0; i < N; i++)
        cin >> students[i].first >> students[i].second;
    for (int i = 0; i < M; i++)
        cin >> schools[i];

    // put down all students without exceeding capacity
    int i = 0;
    while (i >= 0 && i < N)
    {
        cout << i << "\n";
        // try first school for i-th student
        if ((pain[i] == -1 || students[i].second == 0) && caps[students[i].first - 1] + 1 <= schools[students[i].first - 1])
        {
            caps[students[i].first - 1]++;
            choices[i] = students[i].first;
            pain[i] = 0;
            i++;
            continue;
        }
        // try second school
        if (pain[i] == 0 && students[i].second != 0 && caps[students[i].second - 1] + 1 <= schools[students[i].second - 1])
        {
            caps[students[i].second - 1]++;
            choices[i] = students[i].second;
            pain[i] = 1;
            i++;
            continue;
        }
        // step back
        pain[i] = -1;
        i--;
        caps[choices[i] - 1]--;
    }

    for (auto& i : choices)
        cout << i << " ";
    cout << "\n";
}

