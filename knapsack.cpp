#include <iostream>
using namespace std;


class Item {
	public:
	int profit, weight;
	float ratio;
};


void merge(Item *arr, int st, int mid, int en, int approach) {
	Item temp[en-st+1];
	int idx = 0;  //maintain index of temp array
	
	int i = st, j = mid+1;

	while(i<=mid && j<=en) {	
		if(approach==1) {
			if(arr[i].profit>arr[j].profit)
				temp[idx++] = arr[i++];
			else
				temp[idx++] = arr[j++];
		}
		else if(approach==2) {
			if(arr[i].weight<arr[j].weight)
				temp[idx++] = arr[i++];
			else
				temp[idx++] = arr[j++];
		}
		else {
			if(arr[i].ratio>arr[j].ratio)
				temp[idx++] = arr[i++];
			else
				temp[idx++] = arr[j++];
		}
	}
	
	while(i<=mid) {
		if(approach==1)
			temp[idx++] = arr[i++];
		else if(approach==2)
			temp[idx++] = arr[i++];
		else
			temp[idx++] = arr[i++];	
	}
	
	while(j<=en) {
		if(approach==1)
			temp[idx++] = arr[j++];
		else if(approach==2)
			temp[idx++] = arr[j++];
		else
			temp[idx++] = arr[j++];	
	}
	
	for(idx=st; idx<=en; idx++) {
		arr[idx] = temp[idx-st];
	}
}


void mergeSort(Item *arr, int st, int en, int approach) {
	if(st>=en)
		return;
		
	int mid = (st+en)/2;
	mergeSort(arr, st, mid, approach);
	mergeSort(arr, mid+1, en, approach);
	
	merge(arr, st, mid, en, approach);
}

int min(int &a, int &b) {
	if(a<b)
		return a;
	return b;
}


int main() {

	int n, capacity;
	cin>>n>>capacity;
	
	Item arr[n];
	
	for(int i=0; i<n; i++) {
		cin>>arr[i].profit>>arr[i].weight;
		arr[i].ratio = (float)arr[i].profit/arr[i].weight;
	}
	
	int approach;
	cin>>approach;
	
	float totalProfit = 0;
	int i = 0;
	
	mergeSort(arr, 0, n-1, approach);	
	while(capacity>0 && i<n) {
		int maxGrabbed = min(arr[i].weight, capacity);
		totalProfit += arr[i].profit * maxGrabbed / (float)arr[i].weight;
		capacity -= maxGrabbed;
		i++;
	}
	
	cout<<totalProfit<<endl;
	
	return 0;
}