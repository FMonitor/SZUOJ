#include<bits/stdc++.h>
using namespace std;
#define i_n for(int i = 1; i <= n; i++)
#define j_n for(int j = 1; j <= n; j++)
#define k_n for(int k = 1; k <= n; k++)
#define INF 0x3f3f3f3f

int n, matrix[501][501];
string vertex[501];
vector<int> path;
vector<int> dis;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        i_n{
            j_n{
                matrix[i][j] = (i == j ? 0 : INF);
            }
        }
        i_n{
            cin >> vertex[i];
        }
        i_n {
            j_n {
                cin >> matrix[i][j];
            }
        }
        string s;
        cin >> s;
        int m;
        i_n{
            if (vertex[i] == s) {
                m = i;
                break;
            }
        }
        i_n{
            j_n {
                if (matrix[m][i] < matrix[m][j] + matrix[j][i]) {
                    matrix[m][i] = matrix[m][j] + matrix[j][i];
                    path.push_back(j);
                    path.push_back(i);
                    dis.push_back(matrix[m][j] + dis[dis.size() - 1]);
                    dis.push_back(matrix[j][i] + dis[dis.size() - 1]);
                } else {
                    path.push_back(i);
                    dis.push_back(matrix[m][i] + dis[dis.size() - 1]);
                }
            }
        }
        i_n {
            j_n{
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < dis.size(); i++) {
            cout << dis[i] << "-";
        }
        cout << "---[";
        for (int i = 0; i < path.size(); i++) {
            cout << vertex[path[i]] << " ";
        }
        cout << "]\n";
    }
}

