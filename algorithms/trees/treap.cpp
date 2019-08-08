#include <bits/stdc++.h>
using namespace std;

struct item {
	int key, prior, cnt;
	item *l, *r;

	item() {}

	item(int x){
		key = x;
		prior = rand();
		cnt = 0;
	}

	item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};

typedef item *treap;

int cnt (treap t) {
    return t ? t->cnt : 0;
}

void upd_cnt (treap t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void split(treap t, int x, treap& l, treap& r){
	if(!t){
		l = r = NULL;
	}
	else if(x < t->key){
		split(t->l, x, l, t->l);
		r = t;
	}
	else{
		split(t->r, x, t->r, r);
		l = t;
	}
	upd_cnt(t);
}

void insert (treap & t, treap it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}

void merge (treap & t, treap l, treap r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void erase (treap & t, int x) {
    if (t->key == x)
        merge (t, t->l, t->r);
    else
        erase (x < t->key ? t->l : t->r, x);
    upd_cnt(t);
}

int find_kth(treap t, int k, int acc = 0){
	if(!t) return -1;

	if(acc + cnt(t->l) + 1 == k){
		return t->key;
	}
	else if(acc + cnt(t->l) + 1 < k){
		return find_kth(t->r, k, acc + cnt(t->l) + 1);
	}
	else{ // acc + cnt(t->l) + 1 > k
		return find_kth(t->l, k, acc);
	}
}

void print(treap t){
	if(!t) return;
	print(t->l);
	printf("(%d,%d) ", t->key, t->cnt);
	print(t->r);
}

int main(void){
	treap t = NULL;

	insert(t, new item(2));
	insert(t, new item(1));
	insert(t, new item(5));

	cout << find_kth(t, 1) << endl;
	cout << find_kth(t, 2) << endl;
	cout << find_kth(t, 3) << endl;

	print(t);
	printf("\n");

	treap L, R;
	split(t, 3, L, R);

	print(L);
	printf("\n");

	print(R);
	printf("\n");


	return 0;
}