#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
       long long int numberOfInversions(vector<int> nums) {
          long long cnt=_mergesort(nums,0,nums.size()-1);
          return cnt;
     
          
       }
       //merging two sorted arrays and cnt increasing
          long long merge(vector<int> &nums, int low,int mid,int high){
              vector<int> temp;
              long long cnt=0;
              int left=low;
              int right=mid+1;
              while(left<=mid && right<=high){
                if (nums[left]>nums[right]){
                    temp.push_back(nums[right]);
                    cnt += (mid-left+1);
                    right++;
                }
                else{
                    temp.push_back(nums[left++]);
                }
              }
              while(left<=mid){
                 temp.push_back(nums[left++]);
              }
              while(right<=high){
                 temp.push_back(nums[right++]);
              }
              for(int i=low;i<=high;i++){
                nums[i]=temp[i-low];
              }
              return cnt;
    
          }
             long long _mergesort(vector<int> &nums,int low,int high){
            long long cnt=0;
             if(low>=high){
                return cnt;
             }
             int mid=(low+high)/2;
             cnt+=_mergesort(nums,low,mid);
             cnt+=_mergesort(nums,mid+1,high);
             cnt+=merge(nums,low,mid,high);
             return cnt;

          }
    };
// Function to get number of inversions
int numberOfInversions(vector<int>& a, int n) {
    Solution sol;
    return sol.numberOfInversions(a);
}

int main() {
    // Input array
    vector<int> a = {5, 4, 3, 2, 1};
    int n = a.size();

    // Count inversions
    int cnt = numberOfInversions(a, n);

    cout << "The number of inversions are: " << cnt << endl;

    return 0;
}
