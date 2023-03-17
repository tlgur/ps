#include <iostream>

using namespace std;

int arr[500000] = {0,};
int seq = -1;
int n, k;
int sze;

int pop(){
	return arr[seq--];
}

void push(int x){
	if(seq == sze - 1) return;
	arr[++seq] = x;
}

bool empty(){
	return seq == -1;
}

int top(){
	return arr[seq];
}

void print(){
	for(int i = 0; i <= seq; i++)
		cout << arr[i];
	cout << endl;
}

void func(int t){
	if(empty()) {
		push(t);
		return;
	}

	while(!empty() && (top() < t && k)){
		k--;
		pop();
	}
	push(t);
}

int main(){
	cin >> n >> k;
	sze = n - k;
	char temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		int t = temp - '0';

		func(t);
	}
	print();
	return 0;
}
