
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

https://leetcode.com/problems/combination-sum-ii/submissions/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int tar) {
        vector<vector<int>>res;
        vector<int> comb;
        sort(cand.begin(), cand.end());
        dfs(cand, tar, 0, comb, res);
        return res;
    }
    void dfs(vector<int>& cand, int tar, int begin, vector<int>& comb, vector<vector<int>>& res){
       // if(begin >= cand.size())return;
        if(tar == 0){
            res.push_back(comb);
            return;
        }
        for(int i = begin; i < cand.size() && tar >= cand[i]; i++){
            if(i == begin || cand[i] != cand[i-1] ){ //这里可能会存在116 这样重复的两个1，所以才加的这个判断条件，需要进一步加深理解
                //continue;
            comb.push_back(cand[i]);
            dfs(cand, tar-cand[i], i+1, comb, res);
            comb.pop_back();
            }
        }
    }
};
https://leetcode.com/problems/combination-sum-iii/submissions/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>  res;
        vector<int> mp;
        dfs(k, n, 1, mp, res);
        return res;
    }
    void dfs(int k, int n, int st, vector<int>&mp, vector<vector<int>>& res){
        if(k==0){
            if(n==0) res.push_back(mp);
            return;
        }
        for(int i = st; i < 10; i++){
            mp.push_back(i);
            dfs(k-1, n-i, i+1, mp, res); // 结果是[[1,2,4]] ，如果把i+1改成st+1结果是[[1,2,4],[1,3,3],[2,2,3]] 也就是可以存在重复的数
            mp.pop_back();
        }
    }
};
