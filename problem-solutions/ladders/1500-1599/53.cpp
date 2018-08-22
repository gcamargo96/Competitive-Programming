#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n, k;
string aux, s;

int main(void){
	cin >> n >> k;
	s += '@';
	cin >> aux;
	s += aux;
	s += '@';

	int res = 0;

	if(k == 2){
		int tam = n;
		string mask1, mask2;
		For(i,0,n){
			if(i%2 == 0) mask1 += 'A';
			else mask1 += 'B';
		}
		For(i,0,n){
			if(i%2 == 0) mask2 += 'B';
			else mask2 += 'A';
		}
	
		int cnt1 = 0, cnt2 = 0, m = 0;
		for(int i = 0; i < n; i++){
			if(s[i+1] != mask1[i]) cnt1++;
		}
		for(int i = 0; i < n; i++){
			if(s[i+1] != mask2[i]) cnt2++;
		}
		
		if(cnt1 < cnt2){
			for(int i = 0; i < n; i++){
				s[i+1] = mask1[i];
			}
			res = cnt1;
		}
		else{
			for(int i = 0; i < n; i++){
				s[i+1] = mask2[i];
			}
			res = cnt2;
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			int j = i;
			while(s[i] == s[j]) j++;
			
			if(j > i+1){
				int tam = j-i;
				if(tam%2 == 1){
					char cor;
					For(l,0,k){
						if(l+'A' != s[i]){
							cor = l+'A';
							break;
						}
					}
					bool vez = 0;
					for(int l = i; l < j; l++){
						if(vez){
							s[l] = cor;
							res++;
						}
						vez = !vez;
					}
				}
				else{
					char avoid, cor;
					//if(i != 1){
					avoid = s[j];
					For(l,0,k){
						if(l+'A' != s[i] and l+'A' != avoid){
							cor = l+'A';
							break;
						}
					}
					bool vez = 0;
					for(int l = i; l < j; l++){
						if(vez){
							s[l] = cor;
							res++;
						}
						vez = !vez;
					}
				}
			}
			i = j-1;
		}
	}

	cout << res << endl;
	for(int i = 1; i <= n; i++){
		cout << s[i];
	}
	cout << endl;

	return 0;
}

