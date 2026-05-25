#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> selectionSort(vector<int>& nums) {
           for(int i=0;i<nums.size();i++){
            int min_i=i;
            //find minimum element
            for(int j=min_i+1;j<nums.size();j++){
                if( nums[j]<nums[min_i]){
                    min_i=j;
                }
            }
            int temp=nums[min_i];
            nums[min_i]=nums[i];
            nums[i]=temp;
           }
              return nums;
        }
    };
    
int main() {
    Solution s;
    vector<int> nums={64, 25, 25, 22, 22};
    vector<int> sorted_nums=s.selectionSort(nums);
    for(int i=0;i<sorted_nums.size();i++){
        cout<<sorted_nums[i]<<" ";
    }
     return 0;
}