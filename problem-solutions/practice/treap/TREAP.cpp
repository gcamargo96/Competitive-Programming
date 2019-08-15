#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

struct item {
	int key, prior, cnt, mx, mn, mindif;
	item *l, *r;

	item() {}

	item(int x){
		key = x;
		prior = rand();
		cnt = 1;
		mx = mn = x;
		mindif = INF;
		l = r = 0;
	}

	item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};

typedef item *treap;

int cnt (treap t) {
    return t ? t->cnt : 0;
}

int mn(treap t){
	return t ? t->mn : INF;
}

int mx(treap t){
	return t ? t->mx : -INF;
}

int mindif(treap t){
	return t ? t->mindif : INF;
}

void upd (treap t) {
    if (t){
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
        t->mn = min(t->key, mn(t->l));
        t->mx = max(t->key, mx(t->r));
        t->mindif = t->cnt == 1 ? INF : min(min(mindif(t->l), mindif(t->r)), min(t->key-mx(t->l), mn(t->r)-t->key));
    }
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
	upd(t);
}

// menor ou igual vai pra esquerda, maior vai pra direita
void split_pos(treap t, int pos, treap& l, treap& r, int acc = 0){
	if(!t){
		l = r = NULL;
	}
	else if(pos < acc + cnt(t->l) + 1){
		split_pos(t->l, pos, l, t->l, acc);
		r = t;
	}
	else{
		split_pos(t->r, pos, t->r, r, acc + cnt(t->l) + 1);
		l = t;
	}
	upd(t);
}

void insert (treap & t, treap it) {
    if (!t)
        t = it;
    else if(it->key == t->key){
    	return;
    }
    else if (it->prior > t->prior){
        split (t, it->key, it->l, it->r),  t = it;
    }
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd(t);
}


void merge (treap & t, treap l, treap r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd(t);
}

int has (treap t, int x) {
	if(!t) return 0;
    if (t->key == x) 
    	return 1;
    else
        return has (x < t->key ? t->l : t->r, x);
}



void erase (treap & t, int x) {
	if(!t) return;
    if (t->key == x)
        merge (t, t->l, t->r);
    else
        erase (x < t->key ? t->l : t->r, x);
    upd(t);
}

// one based
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

int find_mindif(treap t, int i, int j){
	if(i == j) return -1;

	treap L = NULL, R = NULL;
	split_pos(t, i-1, L, t);
	split_pos(t, j-i+1, t, R);

	int ans = mindif(t);

	merge(t, L, t);
	merge(t, t, R);

	return ans;
}

void print(treap t){
	if(!t) return;
	print(t->l);
		cout << '(' << t->key << "," << t->cnt << "," << t->mn << "," << t->mx << "," << t->mindif << ") ";
	print(t->r);
}


int main(void){
	int n; scanf("%d", &n);

	treap t = 0;

	char op;
	int k, l, r;

	while(n--){
		scanf(" %c", &op);
		int ans;

		switch(op){
			case 'I':
				scanf("%d", &k);
				if(has(t, k) == 0) insert(t, new item(k));
				break;
			case 'D':
				scanf("%d", &k);
				erase(t, k);
				break;
			case 'N':
				scanf("%d%d", &l, &r);
				ans = find_mindif(t, l+1, r+1);
				printf("%d\n", ans);
				break;
			case 'X':
				scanf("%d%d", &l, &r);
				if(l < r){
					ans = find_kth(t, r+1) - find_kth(t, l+1);
					printf("%d\n", ans);
				}
				else
					printf("-1\n");
				break;
			case 'P':
				print(t);
				printf("\n");
				break;
		}
	}

	return 0;
}