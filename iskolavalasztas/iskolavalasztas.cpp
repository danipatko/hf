#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> students(N, vector<int>(2, 0));
    vector<int> caps(M), choices(N, -1);

    for (int i = 0; i < N; i++)
        cin >> students[i][0] >> students[i][1];
    for (int i = 0; i < M; i++)
        cin >> caps[i];
    
    int i = 0;
    while (i >= 0 && i < N)
    {
        choices[i]++;
        if (choices[i] < 2 && 0 < students[i][choices[i]] && 0 < caps[students[i][choices[i]] - 1])
        {
            --caps[students[i][choices[i]] - 1];
            i++;
        }
        else
        {
            choices[i] = -1;
            i--;
            if (i == -1) break;
            ++caps[students[i][choices[i]] - 1];
        }
    }

    if (i == -1)
    {
        cout << "Not possible";
    }
    else
    {
        for (int j = 0; j < choices.size(); j++)
            cout << students[j][choices[j]] << " ";
        cout << "\n";
    }
}

