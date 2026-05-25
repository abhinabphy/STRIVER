#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        long long mergesort(vector<int>&nums,int low,int high){
                long long cnt=0;
               if(low>=high){
                return cnt;
               }
               
               int mid=(low+high)/2;
               cnt+=mergesort(nums,low,mid);
               cnt+=mergesort(nums,mid+1,high);
               cnt+=countpairs(nums,low,mid,high);
               merge(nums,low,mid,high);
               return cnt;
            }
        void merge(vector<int>& nums,int low,int mid,int high){
               vector<int> temp;
               int left=low;
               int right=mid+1;
               while(left<=mid && right<=high){
                if(nums[left]>nums[right]){
                   temp.push_back(nums[right++]);
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
            }
         //sorted halfs 
            int countpairs(vector<int>& nums,int low,int mid,int high){
        int cnt = 0;
        int right = mid + 1;
    
        for(int i=low;i<=mid;i++){
            while(right<=high && (long long)nums[i] > 2LL*nums[right]){
                right++;
            }
            cnt += right-(mid+1);
        }
        return cnt;
    }
        int reversePairs(vector<int>& nums) {
             //ans calc
            return mergesort(nums,0,nums.size()-1);
        }
    };
// Function to get number of inversions
int numberOfInversions(vector<int>& a, int n) {
    Solution sol;
    return sol.reversePairs(a);
}

int main() {
    // Input array
    vector<int> a = {2,4,3,5,1};
    int n = a.size();

    // Count inversions
    int cnt = numberOfInversions(a, n);

    cout << "The number of inversions are: " << cnt << endl;

    return 0;
}
