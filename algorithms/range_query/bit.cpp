#include <bits/stdc++.h>
using namespace std;

const int N = 100002;
int bit[N];

void update(int id, int x){
	while(id < N){
		bit[id] += x;
		id += id & -id;
	}
}

int query(int id){
	int sum = 0;
	while(id > 0){
		sum += bit[id];
		id -= id & -id;
	}
	return sum;
}
