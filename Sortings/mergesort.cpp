#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> mergeSort(vector<int>& nums) {
            int low=0;
            int high=nums.size()-1;
             _mergeSort(nums,low,high);   
                return nums;
        }
        void _mergeSort(vector<int>&nums,int low,int high){
            if(low>=high){
                return ;
            }
           int mid=(low+high)/2;
           _mergeSort(nums,low,mid);
           _mergeSort(nums,mid+1,high);
           merge(nums,low,mid,high);
        }
    
    
        void merge(vector<int> &nums,int low,int mid,int high){
             vector<int> temp;
             int left=low;
             int right=mid+1;
             while(left<=mid && right<=high){
                  if(nums[left]<=nums[right]){
                    temp.push_back(nums[left++]);
                  }
                  else{
                    temp.push_back(nums[right++]);
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
    };
    
    
int main() {
    Solution s;
    vector<int> nums={64, 25, 25, 22, 22};
    vector<int> sorted_nums=s.mergeSort(nums);
    for(int i=0;i<sorted_nums.size();i++){
        cout<<sorted_nums[i]<<" ";
    }
     return 0;
}