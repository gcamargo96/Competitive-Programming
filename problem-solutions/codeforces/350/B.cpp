#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

const int N = 100005;
ll sum[N];
int id[N];
int n, k;

void init(){
	//id[1] = 1;
	memset(sum, 0, sizeof sum);
	for(int i = 1; i < N; i++){
		sum[i] = sum[i-1]+i;
	}
}

int lowb(int beg, int end, ll k){
	int mid = (beg+end)/2;
	if(beg == end) return mid;

	if(sum[mid] <= k) return lowb(mid+1, end, k);
	if(sum[mid] > k) return lowb(beg, mid, k);
}

int main(void){
	ios_base::sync_with_stdio(false);
	init();
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> id[i];
	}

	//cout << "id[1] = " << id[1] << endl;
	ll *lb = lower_bound(sum, sum+N, k);
	int idx = lowb(0, N-1, k);
	//cout << idx << endl;
	if(sum[idx] == k){
		cout << id[k] << endl;
	}
	else{
		*lb--;
		//cout << "lb " << *lb << endl;
		cout << id[k-*lb-1]  << endl;
		//cout << "pos impressa " << idx-k << endl;
		//cout << id[sum[idx]-k] << endl;
	}

	return 0;
}
