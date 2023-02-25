#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> teheneszetek(N), uzemek(M), choices(N, -1), caps(M, 0);
    vector<vector<int>> prices(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        cin >> teheneszetek[i];
    for (int i = 0; i < M; i++)
        cin >> uzemek[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> prices[i][j];

    int i = 0;
    while (i >= 0)
    {
        if (i >= N)
        {
            for (auto& it : choices)
                cout << it << " ";
            cout << "\n";
            i--;
        }

        int j = choices[i] + 1;
        while (j < M && caps[j] + teheneszetek[i] > uzemek[j])
            j++;

        if (j < M)
        {
            caps[j] += teheneszetek[i];
            choices[i++] = j;
        }
        else
        {
            caps[choices[i]] -= teheneszetek[i];
            choices[i--] = -1;
        }
    }
}
