
#include <iostream>
//#include <vector>

using namespace std;

// Input
// 5(n) 10(capacity)
// 1 2 5 9 4 (v[n])
// 2 3 3 4 6 (w[n])

int maxValue(int n, int c, int v[], int w[]) {
	int **dp = new int*[n];

	for (int i = 0; i < n; i++) {
		dp[i] = new int[c + 1];
		for (int j = 0; j <= c; j++)
			dp[i][j] = 0;
	}

	// Populate the first row
	for (int j = 0; j <= c; j++)
		dp[0][j] += j >= w[0] ? v[0] : 0;

	// Populate the rest
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= c; j++) {
			if (j<w[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = __max(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
		}
	}

	return dp[n - 1][c];
}

int main() {
	int n = 5, capa = 10;
	//cin >> n >> capa;

	//vector<int> values(n, 0);
	//vector<int> weights(n, 0);

	int values[] = {1,2,5,9,4};
	int weights[] = {2,3,3,4,6};

	/*for (int i = 0; i < n; i++)
		cin >> values[i];

	for (int j = 0; j < n; j++)
		cin >> weights[j];*/

	cout << maxValue(n, capa, values, weights) << endl;

	system("pause");
	return 0;
}
