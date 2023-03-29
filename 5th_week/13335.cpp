#include <iostream>
#include <queue>

using namespace std;

int arr[1001] = {0,};
int seq = 1;

void print(int time, queue<int> q){
	cout << time << " : ";
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
	}
	cout << endl;
}

int main(){
	int n, w, l;
	cin >> n >> w >> l;
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	queue<int> q;
	for(int i = 0; i < w; i++)
		q.push(0);
	int sum = 0;
	int time = 0;
	while(q.front() != n){
		time++;
		sum -= arr[q.front()];
		q.pop();
		if(seq <= n && sum + arr[seq] <= l) q.push(seq++);
		else q.push(0);
		
		sum += arr[q.back()];
		print(time, q);
	}
	cout << time + 1 << endl;
	return 0;
}
