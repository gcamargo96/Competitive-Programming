#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	int k, n, m, x, y;

	cin >> k;
	while(k != 0){
		cin >> n >> m;
		for(int i = 0; i < k; i++){
			cin >> x >> y;

			if(x == n or y == m){
				cout << "divisa\n";
			}
			else if(x > n and y > m){
				cout << "NE\n";
			}
			else if(x > n and y < m){
				cout << "SE\n";
			}
			else if(x < n and y < m){
				cout << "SO\n";
			}
			else{
				cout << "NO\n";
			}
		}
		cin >> k;
	}

	return 0;
}