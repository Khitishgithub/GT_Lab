
#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int N = 5;

bool Hamiltonian_path(
	vector<vector<int> >& adj, int N)
{
	int dp[N][(1 << N)];

	memset(dp, 0, sizeof dp);

	for (int i = 0; i < N; i++)
		dp[i][(1 << i)] = true;

	for (int i = 0; i < (1 << N); i++) {

		for (int j = 0; j < N; j++) {
			if (i & (1 << j)) {
				for (int k = 0; k < N; k++) {

					if (i & (1 << k)
						&& adj[k][j]
						&& j != k
						&& dp[k][i ^ (1 << j)]) {
						dp[j][i] = true;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (dp[i][(1 << N) - 1])
			return true;
	}
	return false;
}

int main()
{   
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;

    vector<vector<int>> adjmat(n,vector<int>(n));
    cout << "Enter the adjacency matrix: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> adjmat[i][j]; 
        }
    }
	
	int N = adjmat.size();

	if (Hamiltonian_path(adjmat, N))
		cout << "Yes, Graph contains Hamiltonian path";
	else
		cout << "NO, Graph does not contain Hamiltonian path";

	return 0;
}
