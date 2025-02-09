// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
// representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

#include<bits/stdc++.h>
using namespace std;

vector<int> merge2SortedArrays(vector<int> arr1, int n, vector<int> arr2, int m){
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

    //Function calling for merging arrays
    vector<int> ans= merge2SortedArrays(arr1, n, arr2, m);

    //Printing ans array
    for(int i=0; i<n+m; i++){
        cout<<ans[i]<<" ";
    }
}