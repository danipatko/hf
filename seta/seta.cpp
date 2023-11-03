#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct G
{
    vector<vector<int>> mat;
    bool is_directed;

    G(int vertex_count, bool directed) {
        mat = vector<vector<int>>(vertex_count, vector<int>());
        is_directed = directed;
    }

    void add_edge(int from, int to)
    {
        mat[from].push_back(to);
        if (!is_directed)
            mat[to].push_back(from);
    }

    void print()
    {
        for (size_t i = 0; i < mat.size(); i++)
        {
            cout << "[" << i << "]: ";
            for (size_t j = 0; j < mat[i].size(); j++)
                cout << mat[i][j] << " ";
            cout << "\n";
        }
    }
};

const int VISITED = 0;
const int NOT_VISITED = 2;
const int IN_STACK = 1;

void print_cycle(int neigh, stack<int> stacc, vector<vector<int>>* cycles) {
    vector<int> cycle = vector<int>();
    cycle.push_back(stacc.top()); stacc.pop();

    while (cycle.back() != neigh)
    {
        cycle.push_back(stacc.top()); stacc.pop();
    }

    cycles->push_back(cycle);

    for (int i : cycle)
        cout << i << " ";
    cout << "\n";
}

void process(G graph, stack<int>* stacc, vector<int>* visited, vector<vector<int>>* cycles) {
    int current = stacc->top();
    for (int adjacent : graph.mat[current]) {
        if ((*visited)[adjacent] == IN_STACK)
        {
            print_cycle(adjacent, *stacc, cycles);
        }
        else if ((*visited)[adjacent] == NOT_VISITED)
        {
            stacc->push(adjacent);
            (*visited)[adjacent] = IN_STACK;
            process(graph, stacc, visited, cycles);
        }
    }

    (*visited)[current] = VISITED; stacc->pop();
}

int main()
{
    int num_nodes, num_edges, A, B;
    cin >> num_nodes >> num_edges >> A >> B;
    num_nodes++;

    G graph = G(num_nodes, true);

    int from, to;
    for (size_t i = 0; i < num_edges; i++)
    {
        cin >> from >> to;
        graph.add_edge(from, to);
    }

    graph.print();

    vector<int> visited = vector<int>(num_nodes, NOT_VISITED);
    vector<vector<int>> cycles = vector<vector<int>>();
    stack<int> stacc;

    // find cycles
    for (size_t i = 0; i < graph.mat.size(); i++) {
        if (visited[i] == NOT_VISITED && graph.mat[i].size() > 0) {
            stacc = stack<int>();
            stacc.push(i);
            visited[i] = IN_STACK;
            process(graph, &stacc, &visited, &cycles);
        }
    }
}
