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

const int N = 100002;
int n, k;
int v[N];
map<int,int> cnt;

int main(void){
	scanf("%d%d", &n, &k);

	For(i,0,n){
		scanf("%d", &v[i]);
	}

	int j = 0;
	int res = INF, l = -1, r = -1;
	For(i,0,n){
		while(j < n and cnt.size() < k){
			cnt[v[j]]++;
			j++;
		}
		if(cnt.size() == k and j-i+1 < res){
			res = j-i+1;
			l = i+1;
			r = j;
		}
		bool entrou = 0;
		while(cnt.size() == k){
			if(j-i+1 < res){
				res = j-i+1;
				l = i+1;
				r = j;
			}
			cnt[v[i]]--;
			if(cnt[v[i]] == 0) cnt.erase(v[i]);
			i++;
			entrou = 1;
		}
		if(entrou) i--;
	}

	printf("%d %d\n", l, r);

	return 0;
}

