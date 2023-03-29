#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> heap;

void insert(int x){
	heap.push_back(x);
	int cur = heap.size() - 1;
	int parent = cur / 2;
	while(cur > 1 && heap[cur] < heap[parent]){
		swap(heap[cur], heap[parent]);
		cur = parent;
		parent = cur / 2;
	}
}

int pop(){
	int r = heap[1];
	swap(heap[1], heap[heap.size() - 1]);
	heap.pop_back();
	
	int cur = 1;
	while(1){
		int left_child = cur * 2;
		int right_child = cur * 2 + 1;
		if(left_child >= heap.size()) break;
		int smaller_child = right_child;
		if(right_child >= heap.size() || heap[left_child] < heap[right_child]) smaller_child = left_child;

		if(heap[cur] > heap[smaller_child]) swap(heap[cur], heap[smaller_child]);
		else break;

		cur = smaller_child;
	}
	return r;
}

int main(){
	int n;
	cin >> n;
	heap.push_back(-1);
	for(int i = 0, temp; i < n; i++){
		cin >> temp;
		insert(temp);
	for(int i = 0; i < heap.size(); i++)
		cout <<heap[i] << ' ';
	cout << endl;


	}
	int cost = 0;
	while(heap.size() > 2){
		int a = pop();
		int b = pop();
		int c = a + b;
		printf("(%d + %d)\n", a, b);
		cost += c;
		insert(c);
	}
	cout << cost << endl;
	return 0;
}
