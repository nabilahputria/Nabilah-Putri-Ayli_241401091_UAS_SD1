#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int node, const vector<vector<int>>& tree) {
    int max_depth = 0;
    for (int child : tree[node]) {
        max_depth = max(max_depth, dfs(child, tree)); 
    }
    return max_depth + 1; 
}

int main() {
    int n;
    cin >> n; 
    if (n <= 0) {
        cout << "Jumlah karyawan harus lebih dari 0." << endl;
        return 0;
    }   

    vector<int> managers(n + 1); 
    vector<vector<int>> tree(n + 1); 
    vector<int> roots; 
    
  
    for (int i = 1; i <= n; ++i) {
        cin >> managers[i];
        if (managers[i] == -1) {
            roots.push_back(i); 
        } else {
            tree[managers[i]].push_back(i); 
            roots.push_back(0);
        }
    }

    int max_groups = 0;
    for (int root : roots) {
        max_groups = max(max_groups, dfs(root, tree)); 

    }

    cout << max_groups << endl;
    cout << "Proses selesai." << endl;
    cout << "Terima kasih." << endl;

    return 0;
}
