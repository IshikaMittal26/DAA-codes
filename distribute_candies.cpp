#include <bits/stdc++.h>
using namespace std;

int countCandies(int arr[], int n)
{

	int sum = 0;
	int ans[n];


	if (n == 1) {
		return 1;
	}

	for (int i = 0; i < n; i++)
		ans[i] = 1;

	for (int i = 1; i < n ; i++) {
		if (arr[i ] > arr[i-1]) {

		
			ans[i] = ans[i-1] + 1;
		}
	}


	for (int i = n - 2; i >= 0; i--) {

		if (arr[i] > arr[i + 1] && ans[i] <= ans[i + 1]) {

	
			ans[i] = ans[i + 1] + 1;
		}

	
	}

	for (int i=0;i<n;i++){
		sum=sum+ans[i];
	}
	for (int i=0;i<n;i++){
		cout<<ans[i]<<", ";
	}
	cout<<endl;
	return sum;
}

int main()
{
	int arr[] = { 1,3,7,1};
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << countCandies(arr, N);
	
	return 0;
}
