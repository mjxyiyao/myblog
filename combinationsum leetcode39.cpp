
class Solution {
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationSum(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> nums;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, nums, res);
    return res;
}

void dfs(vector<int>& candidates, int target, int index, vector<int>& nums, vector<vector<int>>& res) {
    if (target < 0)
        return;
    if (target == 0) {
        res.push_back(nums);
        return;
    }
    for (int i=index; i<candidates.size(); i++) {
        nums.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i, nums, res);
        nums.pop_back();
    }
}
