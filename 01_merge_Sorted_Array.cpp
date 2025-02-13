// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
// representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#include<bits/stdc++.h>
using namespace std;


// BruteForce Approach- In this we are using extra space to store all elements of both arrays. It's a very 
// straighforward approach

// Time Complexity: O(n+m) where n and m are the sizes of the given arrays.
// Space Complexity: O(n+m) as we use an extra array of size n+m.

vector<int> merge2SortedArrays(vector<int> &arr1, int n, vector<int> &arr2, int m){
    //Declaring ans array for storing all (n+m) elemnets from both arrays
    vector<int> ans(n+m);
    //For keeping track of index to store elements in ans array
    int k=0;
    int i=0, j=0;

    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            ans[k++]= arr1[i++];
        }
        else
            ans[k++]= arr2[j++];
    }

    // To process remaining elements if any in arr1
    while(i<n){
        ans[k++]= arr1[i++];
    }

    // To process remaining elements if any in arr2
    while(j<m){
        ans[k++]= arr2[j++];
    }
    return ans;

}

// Optimal Approach- Two Pointers- Using the 2 pointers, we will swap the bigger elements of arr1 with the 
// smaller elements of arr2 until the minimum of arr2 becomes greater or equal to the maximum of arr1.

// Time Complexity: O(min(n, m)) is for swapping the array elements. And O(n*logn) and O(m*logm) are for sorting the two arrays.
// Space Complexity: O(1)

void merge(vector<int> &arr1, int n, vector<int> &arr2, int m) {

    //Declare 2 pointers:
    int s = n - 1;
    int e = 0;

    //Swap the elements until arr1[left] is smaller than arr2[right]:
    while (s >= 0 && e < m) {
        if (arr1[s] > arr2[e]) {
            swap(arr1[s], arr2[e]);
            s--, e++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}


int main(){
    int n, m;
    cout<<"Enter size of first array: ";
    cin>>n;
    cout<<"Enter size of second array: ";
    cin>>m;
    vector<int> arr1(n), arr2(m);

    cout<<"Enter "<<n<<" elements for array 1: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    cout<<"Enter "<<m<<" elements for array 2: "<<endl;
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    // Bruteforce Approach
    vector<int> ans= merge2SortedArrays(arr1, n, arr2, m);

    // Optimal Approach
    merge(arr1, n, arr2, m);




}