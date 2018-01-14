#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define pb push_back
#define eb emplace_back
#define BEG 0
#define END 1
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

// const int N = 500002;
int t;
string a, b;

int main(void){
	// ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		cin >> a >> b;
		if(a == b) cout << "B" << endl;
		else if(a.size() == 1) cout << "B" << endl;
		else cout << "A" << endl;
	}

	return 0;
}