// C++ implementation of the approach
#include<bits/stdc++.h>
#include<map>
using namespace std;


// Function to return the count of subarrays
// with at most K distinct elements using
// the sliding window technique
int atMostK(int arr[], int n, int k)
{

	// To store the result
	int count = 0;

	// Left boundary of window
	int left = 0;

	// Right boundary of window
	int right = 0;

	// Map to keep track of number of distinct
	// elements in the current window
	unordered_map<int,int> map;
	// Loop to calculate the count
	while (right < n) {

		// Calculating the frequency of each
		// element in the current window
		if (map.find(arr[right])==map.end())
			map[arr[right]]=0;
		map[arr[right]]++;

		// Shrinking the window from left if the
		// count of distinct elements exceeds K
		while (map.size() > k) {
			map[arr[left]]= map[arr[left]] - 1;
			if (map[arr[left]] == 0)
				map.erase(arr[left]);
			left++;
		}

		// Adding the count of subarrays with at most
		// K distinct elements in the current window
		count += right - left + 1;
		right++;
	}
	return count;
}

// Function to return the count of subarrays
// with exactly K distinct elements
int exactlyK(int arr[], int n, int k)
{

	// Count of subarrays with exactly k distinct
	// elements is equal to the difference of the
	// count of subarrays with at most K distinct
	// elements and the count of subararys with
	// at most (K - 1) distinct elements
	return (atMostK(arr, n, k) - atMostK(arr, n, k - 1));
}

// Driver code
int main()
{
	int arr[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 5;

	cout<<(exactlyK(arr, n, k));
}
