#include<iostream>
#define Maxn 0x3f3f3f3f
using namespace std;
class Graph {
private:
    int vernum;
    string* vertex;
    int** matrix;
public:
    Graph() {
    }
    Graph(int _vernum, string* _vertex, int** mat) {
        vernum = _vernum;
        vertex = new string[vernum];
        for (int i = 0;i < vernum;i++)
            vertex[i] = _vertex[i];
        matrix = new int* [vernum];
        for (int i = 0;i < vernum;i++)
            matrix[i] = new int[vernum];
        for (int i = 0;i < vernum;i++)
            for (int j = 0;j < vernum;j++)
                matrix[i][j] = mat[i][j];
        for (int i = 0;i < vernum;i++)
            for (int j = 0;j < vernum;j++) {
                if (matrix[i][j] == 0)
                    matrix[i][j] = Maxn;
            }

    }
    int findindex(string str) {
        for (int i = 0;i < vernum;i++)
            if (vertex[i] == str)
                return i;
        return 0;
    }
    void dijkstra(string beginning) {
        int i, j, current, minx;
        bool* final = new bool[vernum];
        int* minpath = new int[vernum];
        int index = findindex(beginning);
        string* path = new string[vernum];
        for (i = 0;i < vernum;i++) {
            path[i] = beginning + " ";
            minpath[i] = matrix[index][i];
            final[i] = false;
        }
        minpath[index] = 0;
        final[index] = true;
        for (i = 0;i < vernum;i++) {
            minx = Maxn;
            current = -1;
            for (j = 0;j < vernum;j++) {
                if (final[j] == false && minpath[j] < minx) {
                    current = j;
                    minx = minpath[j];
                }
            }
            if (current != -1) {
                final[current] = true;
                path[current] += vertex[current] + " ";
                for (int k = 0;k < vernum;k++) {
                    if (final[k] == false && minx + matrix[current][k] < minpath[k]) {
                        minpath[k] = minx + matrix[current][k];
                        path[k] = path[current];
                    }
                }
            }
        }
        for (i = 0;i < vernum;i++) {
            if (vertex[i] != beginning) {
                cout << beginning << "-" << vertex[i];
                if (minpath[i] >= Maxn) {
                    cout << "--1" << endl;
                    continue;
                }
                cout << "-" << minpath[i] << "----[" << path[i] << "]" << endl;
            }
        }
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string* vertex = new string[n];
        for (int i = 0;i < n;i++)
            cin >> vertex[i];
        int** matrix = new int* [n];
        for (int i = 0;i < n;i++)
            matrix[i] = new int[n];
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                cin >> matrix[i][j];
        string beginning;
        cin >> beginning;
        Graph g(n, vertex, matrix);
        g.dijkstra(beginning);
    }
}