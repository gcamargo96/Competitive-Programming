#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 105;
int m, k, n;
unordered_set<int> favs;
int lo[N], hi[N];

int main(void){
	fastcin;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> m >> k;

	int a;
	for(int i = 0; i < k; i++){
		cin >> a;
		favs.insert(a);
	}

	cin >> n;

	string s;
	int d, maiorMenor = 0, maiorMaior = 0;
	for(int i = 0; i < n; i++){
		cin >> s;
		cin >> d;

		int b, cnt0 = 0, cntF = 0, cntN = 0;
		for(int j = 0; j < d; j++){
			cin >> b;

			if(b == 0){
				cnt0++;
			}
			else if(favs.count(b)){
				cntF++;
			}
			else{
				cntN++;
			}
		}

		lo[i] = cntF + max(0, cnt0-m+k+cntN);
		hi[i] = cntF + min(cnt0, k-cntF);
	
		maiorMenor = max(maiorMenor, lo[i]);
		maiorMaior = max(maiorMaior, hi[i]);
	}

	// for(int i = 0; i < n; i++){
	// 	if(lo[i] == maiorMenor and hi[i] == maiorMaior){
	// 		cout << 0 << endl;
	// 	}
	// 	else if(hi[i] >= maiorMenor){
	// 		cout << 2 << endl;
	// 	}
	// 	else{
	// 		cout << 1 << endl;
	// 	}
	// }

	for(int i = 0; i < n; i++){		
		bool favorite = 1;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(hi[j] > lo[i]) favorite = 0;
		}

		if(favorite){
			cout << 0 << endl;
		}
		else if(hi[i] >= maiorMenor){
			cout << 2 << endl;
		}
		else{
			cout << 1 << endl;
		}
	}

	return 0;
}