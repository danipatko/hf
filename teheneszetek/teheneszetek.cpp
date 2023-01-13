#include <iostream>
#include <vector>

using namespace std;

void printarr(const vector<vector<int>>* v, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << "[" << (*v)[i][j] << "]";
        cout << "\n";
    }
}

// use the index to get the following: https://cdn.discordapp.com/attachments/1044165803341254676/1061933206946979850/image.png
void get_vector(int index, vector<int>* v, int M)
{
    // last element is index % M
    // before: (index / M) % M
    // before before: (index / M^2) % M etc..
    int div = 1;
    for (int i = v->size() - 1; i >= 0; i--)
    {
        (*v)[i] = (index / div) % M;
        div *= M;
    }
}

// check the price
// returns negative uzem index if case is not possible due to capacity
int calc(vector<int>* current, vector<int>* teheneszetek, vector<int>* uzemek, vector<vector<int>>* prices)
{
    int sum = 0, uzem_index;
    vector<int> capacities(uzemek->size(), 0);

    for (int i = 0; i < current->size(); i++)
    {
        uzem_index = (*current)[i];
        // at full capacity -> not possible, skip
        capacities[uzem_index] += (*teheneszetek)[i];
        if (capacities[uzem_index] > (*uzemek)[uzem_index])
        {
            cout << "\n[" << i << "] exceeded capacity\n";
            return -i;
        }
        // add price to sum
        sum += (*teheneszetek)[i] * (*prices)[i][uzem_index];
    }

    return sum;
}

// e.g. index = 6, from = 1, M = 2 -> 8
int skip(vector<int>* current, int from, int M)
{
    // TODO: find the index, where the "from" column is incremented
    return -1;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> teheneszetek(N), uzemek(M);
    vector<vector<int>> prices(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        cin >> teheneszetek[i];
    for (int i = 0; i < M; i++)
        cin >> uzemek[i];
    for (int i = 0; i < N ; i++)
        for (int j = 0; j < M; j++)
            cin >> prices[i][j];

    // time complexity is O(N^M)
    // instead of using recursion, we can run a single loop,
    // and determine the current position in each iteration

    vector<int> current(N), best(N);
    int best_price = (1 << 30), price;

    for (int i = 0; i < pow(N, M); i++)
    {
        get_vector(i, &current, M);
        price = calc(&current, &teheneszetek, &uzemek, &prices);

        // if we find an impossible solution, we can just increment
        // i to avoid unneccessary computation
        
        if (price <= 0)
        {
            // TODO: skip
            // cout << i << ") skipping to index " << skip(&current, -price, M, i) << '\n';
            continue;
        }

        if (price < best_price)
        {
            best_price = price;
            best = current;
        }

        // for (int item : current)
        //     cout << item << " ";
        // cout << price << "\n";
        // cout << "\n";
    }

    cout << best_price << "\n";
    for (int item : best)
        cout << item + 1 << " ";
    cout << "\n";
}
