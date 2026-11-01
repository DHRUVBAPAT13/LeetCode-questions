class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        
        long long minv = LLONG_MAX; 

        for(size_t i = 0; i < nums.size(); i = i + 2){
                        
            std::string merged = std::to_string(nums[i]) + std::to_string(nums[i+1]);

            long long val = std::stoi(merged);

            if(minv > val){
                minv = val;
            }
        }
        return minv;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna