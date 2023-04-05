#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll arr[2][1000001] = {0,};
ll segment[2000000] = {0,};
int n;

ll build(int cur, int left, int right){
	if(left == right) {
		segment[cur] = arr[0][left];
		arr[1][left] = cur;
	}else{
		int mid  = (left + right) / 2;
		segment[cur] = build(cur * 2, left, mid) + build(cur * 2 + 1, mid + 1, right);
	}
	return segment[cur];
}

void change(ll index, ll val){
	int cur = arr[1][index];
	int gap = val - arr[0][index];
	segment[cur] = arr[0][index] = val;
	int parent = cur / 2;
	while(parent > 0){
		segment[parent] += gap;
		cur = parent;
		parent = cur / 2;
	}
}

ll part_sum(int cur, int left, int right, int lt, int rt){
	if(lt > rt) return 0;
	if(left == lt && right == rt) return segment[cur];
	int mid = (left + right) / 2;
	if(mid >= rt) return part_sum(cur * 2, left, mid, lt, rt);
	else if(mid + 1 <= lt) return part_sum(cur * 2 + 1, mid + 1, right, mid + 1, rt);
	return part_sum(cur * 2, left, mid, lt, mid) + part_sum(cur * 2 + 1, mid + 1, right, mid + 1, rt);
}

void print(){
	for(int i = 1; i <= 10; i++)
		cout << segment[i] <<  ' ';
	cout << endl;
}

int main(){
	int m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> arr[0][i];
	build(1, 1, n);
	for(ll a, b, c, i = 0; i < m + k; i++){
		cin >> a >> b >> c;
		if(a == 1){
			change(b, c);
		}else if(a == 2){
			cout << part_sum(1, 1, n, b, c) << endl;
		}
	}
	return 0;
}
