#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	int low = 0, hi = 0;

	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt++;
		if(cnt == 6 or cnt == 7){
			low++;
		}
		if(cnt == 7) cnt = 0;
	}

	cnt = 0;
	for(int i = 0; i < n; i++){
		cnt++;
		if(cnt == 1 or cnt == 2){
			hi++;
		}

		if(cnt == 7) cnt = 0;
	}

	cout << low << " " << hi << endl;

	return 0;
}
