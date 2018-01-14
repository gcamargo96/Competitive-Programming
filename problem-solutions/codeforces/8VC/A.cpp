#include <bits/stdc++.h>
using namespace std;

int g[12][12];

int main(void){
	ios_base::sync_with_stdio(false);
	int n, r, c, k, res = 0;
	cin >> r >> c >> n >> k;

	int a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		g[a][b] = 1;
	}

	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			for(int x = i; x <= r; x++){
				for(int y = j; q <= c; y++){
					int cont = 0;
					for(int l = i; l <= x; l++){
						for(int m = j; m <= y; m++){
							if(g[l][m] == 1) cont++;
						}
					}
					if(cont >= k) res++;
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}
