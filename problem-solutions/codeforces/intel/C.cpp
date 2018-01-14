#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 100005;

struct Node{
	Node() {
		flag = true;
	}
	
	Node(bool b){ 
		flag = false;
	}

	int flag;
	ll sum, maxsum;
	ll lr, rl;
};

int a, b;
Node seg[4*N];

void atribui(int r, ll x, int i, int j){
	seg[r].sum = x;
	seg[r].maxsum = x;
	seg[r].lr = x;
	seg[r].rl = x;
}

void update(int r, ll x, int i, int j){
	if(j < a or i > b) return;
	if(a <= i and j <= b){
		atribui(r, x, i, j);
		return;
	}
	int mid = (i+j)/2;
	update(2*r, x, i, mid);
	update(2*r+1, x, mid+1, j);
	//seg[r] = max(max(seg[2*r], seg[2*r+1]), seg[2*r]+seg[2*r+1]);
	seg[r].sum =  max(-1000000000000000LL, seg[2*r].sum + seg[2*r+1].sum);
	seg[r].lr = max(seg[2*r].lr, seg[2*r].sum + seg[2*r+1].lr);
	seg[r].rl = max(seg[2*r+1].rl, seg[2*r+1].sum + seg[2*r].rl);
	seg[r].maxsum = seg[r].sum;

	if(seg[2*r].rl + seg[2*r+1].lr > seg[r].maxsum){
		seg[r].maxsum = seg[2*r].rl + seg[2*r+1].lr;
	}
	if(seg[2*r].maxsum > seg[r].maxsum){
		seg[r].maxsum = seg[2*r].maxsum;
	}
	if(seg[2*r+1].maxsum > seg[r].maxsum){
		seg[r].maxsum = seg[2*r+1].maxsum;
	}
}

Node query(int r, int i, int j){
	if(j < a or i > b) return Node(false);
	if(a <= i and j <= b) return seg[r];
	int mid = (i+j)/2;
	auto left = query(2*r, i, mid);
	auto right = query(2*r+1, mid+1, j);
	//return max(max(L, R), L+R);
	if(!left.flag) return right;
	if(!right.flag) return left;
	
	Node ret;
	ret.maxsum = max(max(left.maxsum, right.maxsum), left.rl+right.lr);
	ret.lr = max(left.lr, left.sum + right.lr);
	ret.rl = max(right.rl, right.sum + left.rl);
	ret.sum = max(-1000000000000000LL, left.sum + right.sum);

	return ret;
}

int n, m;
int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	ll x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		a = b = i;
		update(1, x, 1, N);
	}

	for(int i = 1; i <= n; i++){
		cin >> x;
		a = b = x;
		update(1, -1000000000000000LL, 1, N);
		a = 1, b = N;
		auto res = query(1, 1, N);
		cout << max(0LL, res.maxsum) << "\n";
	}

	return 0;
}
