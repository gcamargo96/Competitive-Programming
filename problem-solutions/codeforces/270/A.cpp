#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define enld "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 1000002;
int n;
//vector<int> primos;
set<int> primos;
int vis[N];

void crivo(){
	for(int i = 2; i < N; i++){
		if(!vis[i]){
			primos.insert(i);
			for(int j = i; j < N; j += i){
				vis[j] = 1;
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	crivo();
	cin >> n;
	
	int a = n/2, b = n/2;
	if(n%2 == 1) b++;

	while(primos.count(a) or primos.count(b)){
		a--;
		b++;
	}

	cout << a << " " << b << endl;

	return 0;
}
