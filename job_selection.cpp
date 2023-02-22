#include <iostream>
using namespace std;

struct Job {
	int id, profit, deadline;
	bool isOccupied;
};

int max(int &a, int &b) {
	return (a>b)? a: b;
}

void merge(Job *arr, int st, int mid, int en) {
	Job temp[en-st+1];
	int i = st, j = mid+1, k = 0;
	while(i<=mid && j<=en) {
		if(arr[i].profit>arr[j].profit)
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while(i<=mid) {
		temp[k++] = arr[i++];
	}
	while(j<=en) {
		temp[k++] = arr[j++];
	}
	for(k=st; k<=en; k++) {
		arr[k] = temp[k-st];
	}
}

void mergeSort(Job *arr, int st, int en) {
	if(en<=st)
		return;
	int mid = (st+en)/2;
	mergeSort(arr, st, mid);
	mergeSort(arr, mid+1, en);
	merge(arr, st, mid, en);
}

int main() {
	int n;
	cin>>n;
	Job arr[n];
	for(int i=0; i<n; i++) {
		cin>>arr[i].profit>>arr[i].deadline;
		arr[i].id = i+1;
	}
	mergeSort(arr, 0, n-1);
	int m = 0;  //maximum deadline and max possible jobs count
	for(int i=0; i<n; i++) {
		m = max(m, arr[i].deadline);
	}
	int maxProfit, executionOrder[m];
	for(int i=0; i<m; i++) {
		executionOrder[i] = -1;
	}
	for(int i=m-1; i>=0; i--) {
		for(int j=0; j<n; j++) {
			if(arr[j].deadline>i && !arr[j].isOccupied) {
				maxProfit += arr[j].profit;
				arr[j].isOccupied = true;
				executionOrder[i] = arr[j].id;
				break;
			}
		}
	}
	cout<<maxProfit<<endl;
	for(int i=0; i<m; i++) {
		if(executionOrder[i]!=-1)
			cout<<executionOrder[i]<<" ";
	}
	cout<<endl;
	return 0;
}