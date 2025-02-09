// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place
// such that each unique element appears only once. The relative order of the elements should be kept the same.
// Then return the number of unique elements in nums.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    int ind = 0, r = 0;
    while (r < n - 1)
    {
        while (r < n - 1 && nums[r] == nums[r + 1])
            r++;
        swap(nums[r++], nums[ind++]);
    }
    if (r == n - 1)
    {
        swap(nums[r++], nums[ind++]);
    }
    return ind;
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

    // size of array after removing all occurences of val
    int ans= removeDuplicates(arr);
    cout<<ans<<endl;

    //Printing array after removing duplicates in-place. From ans index to n, duplicate elements are present but since 
    // we are returning ans so it will automatically pick elements till (ans-1) index only.
    for(int i=0; i<ans; i++){
        cout<<arr[i]<<" ";
    }
}