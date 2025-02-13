// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    int ans = 0;

    while (l <= r)
    {
        while (l <= r && nums[l] != val)
        {
            ans++;
            l++;
        }
        while (l <= r && nums[r] == val)
        {
            r--;
        }
        if (l > r)
            break;
        swap(nums[l++], nums[r--]);
        ans++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int val;
    cout<<"Enter value whose all occurence we need to remove from array: ";
    cin>>val;

    vector<int> arr(n);
    cout<<"Enter "<<n<<" elements for array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    // size of array after removing all occurences of val
    int ans= removeElement(arr, val);
    cout<<ans<<endl;

    //Printing array after removing elements in-place. From ans index to n, duplicate elements are present.
    for(int i=0; i<ans; i++){
        cout<<arr[i]<<" ";
    }
}