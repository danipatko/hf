#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, temp;
    cin >> N >> M;
    vector<vector<int>> students(N, vector<int>(1));
    vector<int> schools(M), caps(M), choices(N, -1);

    for (int i = 0; i < N; i++)
    {
        cin >> students[i][0];
        cin >> temp;
        if (temp) 
            students[i].push_back(temp);
    }
    for (int i = 0; i < M; i++)
        cin >> schools[i];

    // put down all students without exceeding capacity
    int i = 0;
    while (i >= 0 && i < N)
    {
        bool ok = false;
        for (int j = choices[i] + 1; j < students[i].size(); j++)
        {
            if (caps[students[i][j] - 1] + 1 <= schools[students[i][j] - 1])
            {
                caps[students[i][j] - 1]++;
                choices[i++] = j;
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            choices[i--] = -1;
            caps[students[i][choices[i]] - 1]--;
        }
    }

    for (int j = 0; j < choices.size(); j++)
        cout << students[j][choices[j]] << " ";
    cout << "\n";
}

