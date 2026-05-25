#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int low=0;int high=nums.size()-1;
          
          while(low<=high){
            int mid=low+(high-low)/2;
            if (nums[mid]==target){
                return true;
            }
            // Edge case: all three are equal, we cannot determine which side is sorted
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            
                if(nums[mid]<=nums[high]){
                    //right half is sorted
                    //target found in right sorted array
                    if(nums[mid]<=target && nums[high]>=target){
                        low=mid+1;
                    }
                    else{
                        //search in non sorted right array
                        high=mid-1;
                    }
    
    
                }
                else{
                //left half is sorted 
                   if(nums[low]<=target && nums[mid]>=target){
                     high=mid-1;
                   }
                   else{
                    low=mid+1;
                   }
                }
            }
          
          return false;
    
        }
    };

int main() {
    Solution s;
    vector<int> nums={2,5,6,0,0,1,2};
    int target=0;
    bool found=s.search(nums,target);
    if(found){  
        cout<<"Target found in the array."<<endl;
    }
    else{
        cout<<"Target not found in the array."<<endl;
    }
     return 0;
}