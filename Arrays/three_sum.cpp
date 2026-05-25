#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            set<int> s;
            vector<vector<int>> sol;
            set<vector<int>> ans_st;
            for (int i=0;i<nums.size();i++){
                s.clear();
                for (int j=i+1;j<nums.size();j++){
                   int rem=-(nums[i]+nums[j]);
                   if(s.find(rem)!=s.end()){
                    vector<int> temp={nums[i],nums[j],rem};
                    sort(temp.begin(),temp.end());
                    ans_st.insert(temp);
                   }
                   s.insert(nums[j]);
                }
    
            }
           sol.assign(ans_st.begin(), ans_st.end()); 
            return sol;
        }
    };
    int main() {
        Solution solution;
        vector<int> nums = {-1, 0, 1, 2, -1, -4};
        vector<vector<int>> result = solution.threeSum(nums);
        for (const auto& vec : result) {
            for (const auto& num : vec) {
                cout << num << " ";
            }
            cout << endl;
        }
         return 0;

       
    }