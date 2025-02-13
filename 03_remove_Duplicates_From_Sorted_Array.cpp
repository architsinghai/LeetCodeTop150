// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
// such that each unique element appears only once. The relative order of the elements should be kept the same.
// Then return the number of unique elements in nums.

#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach:-

// Declare a HashSet.
// Run a for loop from starting to the end.
// Put every element of the array in the set.
// Store size of the set in a variable size.
// Now put all elements of the set in the array from the starting of the array.
// Return size.

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n) 

int removeDuplicatesUsingSet(vector<int> &nums) {
    int n = nums.size();
    set < int > s;
    for (int i = 0; i < n; i++) {
        s.insert(nums[i]);
    }
    int size = s.size();
    int j = 0;
    for (int el: s) {
        nums[j++] = el;
    }
    return size;
}

// Optimal Approach: Two Pointers

// Take a variable i as 0;
// Use a for loop by using a variable ‘j’ from 1 to length of the array.
// If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
//  After completion of the loop return i+1, i.e size of the array of unique elements.

// Time Complexity: O(N)
// Space Complexity: O(1)

int removeDuplicates(vector<int> &arr)
{
    int n= arr.size();
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[i] != arr[j]) {
        i++;
        arr[i] = arr[j];
        }
    }
    return i + 1;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter "<<n<<" elements for array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //BruteForce Approach Using set
    int ans= removeDuplicatesUsingSet(arr);

    // size of array after removing all occurences of val
    // int ans= removeDuplicates(arr);
    cout<<"Size of array till unique elements: "<<ans<<endl;

    //Printing array after removing duplicates in-place. From ans index to n, duplicate elements are present.
    cout<<"Elements of array after removing duplicates are: "<<endl;
    for(int i=0; i<ans; i++){
        cout<<arr[i]<<" ";
    }
}