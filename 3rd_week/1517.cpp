#include <iostream>

using namespace std;

int arr[500000] = {0,};
	int temp[500000] = {0,};
int cnt = 0;

void mergeSort(int left, int mid, int right);

void merge(int left, int right){
	if(left == right) return;
	int mid = (left + right) / 2;
	merge(left, mid);
	merge(mid + 1, right);
	mergeSort(left, mid, right);
}

void mergeSort(int left, int mid, int right){
	int index = 0;
	int l = left, r = mid + 1;
	int t = 0;
	while(l <= mid && r <= right){
		if(arr[l] <= arr[r]) {
			temp[index++] = arr[l++];
			cnt += t;
		}
		else {
			temp[index++] = arr[r++];
			t++;
		}
	}
	while(l <= mid) {
		temp[index++] = arr[l++];
		cnt += t;
	}
	while(r <= right) temp[index++] = arr[r++];
	
	for(int i = 0; i < index; i++) arr[left + i] = temp[i];
}

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	merge(0, n - 1);

	for(int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
	cout << cnt << endl;
	return 0;
}
