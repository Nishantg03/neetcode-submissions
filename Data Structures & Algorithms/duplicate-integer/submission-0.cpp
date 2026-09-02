class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        int n=nums.size();

        unordered_set<int> st;

        for(int i=0;i<n;i++){
            
            st.insert(nums[i]);
        }

        if(st.size()!=n){
            return true;
        }

        return false;

        
    }
};