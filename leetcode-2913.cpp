class Solution {
public:
    int findDist(vector<int>& nums)
    {
        vector<int> dist;
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(dist.begin(), dist.end(), nums[i]) == dist.end())
            {
                dist.push_back(nums[i]);
            }
        }
        
        return dist.size();
    }
    
    int subarrProcess(vector<int>& nums, int sz)
    {
        vector<int> v;
        int res = 0;
        
        if (sz == 1)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                res++;
            }
        }
        else
        {
            for (int i = sz - 1; i < nums.size(); i++)
            {
                v = vector<int>(nums.begin() + i - sz + 1, nums.begin() + i + 1);
                res += pow(findDist(v), 2);
            }
        }

        return res;
    }
    
    int sumCounts(vector<int>& nums)
    {
        int i = 1, res = 0;
        
        while (i <= nums.size())
        {
            res += subarrProcess(nums, i);
            i++;
        }
        
        return res;
    }
};
