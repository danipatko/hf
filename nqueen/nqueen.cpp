#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>* vec)
{
    for (auto& i : *vec)
        cout << i << " ";
    cout << "\n";
}

bool check(const vector<int>* vec, int col, int row)
{
    for (int i = 0; i < vec->size(); i++)
    {
        // there can be only one queen/column or clear column
        if (col == i || (*vec)[i] == -1) continue;
        // in the same row or diagonal -> |x1-x2| == |y1-y2|
        if (row == (*vec)[i] || abs(row - (*vec)[i]) == abs(col - i)) return false;
    }
    return true;
}

bool solve(vector<int>* vec, int col)
{
    int N = vec->size(); bool res = false;
    // all placed
    if (col >= N)
    {
        print(vec);
        return true;
    }
    // try rows
    for (int row = 0; row < N; row++)
    {
        if (check(vec, col, row))
        {
            (*vec)[col] = row;
            res = solve(vec, col + 1) || res;
        }
        // step back
        else (*vec)[col] = -1;
    }

    (*vec)[col] = -1;
    return res;
}

int main()
{
    int N = 4;
    cin >> N;
    vector<int> vec(N, -1);

    if (!solve(&vec, 0))
        cout << "no solution\n";
    
    return 0;
}