#include "all.h"
using namespace std;

// https://leetcode.com/problems/split-array-largest-sum/
// 2020 1.1
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long l = 0, r = 0;
        for (int i = 0; i < nums.size(); i++) {
            r += nums[i];    //sum of the array items, m==1
            if (nums[i] > l)
                l = nums[i]; //max of the array items, m==nums.size()
        }

        while (l < r) {
            long mid = l + (r - l) / 2; //(l + r) >> 1;
            long sum = 0;   // sum of the current processing subarray
            int cnt = 1;    // # of existing subarrays
            for (int i = 0; i < nums.size(); i++) {
                if (sum + nums[i] > mid) { //need to cut here
                    cnt++;                 //increase # of subarrays
                    sum = nums[i];         //start a new subarray with nums[i]
                }
                else
                    sum += nums[i]; //add it to current subarray, sum <= mid
            }
            if (cnt <= m) { //m: size limit of subarrays
                r = mid;      //decrease mid
            }                 //move search range to lower half 
            else  //mid is too small
                l = mid + 1; //increase mid
        }                    //move search range to upper half
        return l;
    }
    int splitArray_slow(vector<int>& nums, int m) {
        auto n = nums.size();
        vector<vector<vector<int>>> mem(n+1, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        return dfs(nums, 0, nums.size(), m, mem);
    }

    int dfs(vector<int>& nums, int i, int j, int m, vector<vector<vector<int>>>& mem) {
        if (mem[i][j][m] != -1) {
            return mem[i][j][m];
        }
        else if (m == 1) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += nums[k];
            }
            mem[i][j][m] = sum;
            return sum;
        }
        else {
            int pre_sum = 0;
            int local_min = INT_MAX;
            for (int k = i; k <= j - m; ++k) {
                pre_sum += nums[k];
                int r = dfs(nums, k + 1, j, m - 1, mem);
                local_min = min(local_min, max(r, pre_sum));
            }
            mem[i][j][m] = local_min;
            return local_min;
        }
    }

    // https://leetcode.com/problems/trapping-rain-water-ii/
    int trapRainWater_slow(vector<vector<int>>& heightMap) {
        auto cmp = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
        
        vector<vector<int>> directions({ {1,0},{0,1},{-1,0},{0,-1} });
        int res = 0;
        auto m = heightMap.size();
        if (m == 0) {
            return 0;
        }
        auto n = heightMap[0].size();
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                q.push(make_tuple(heightMap[i][j], i, j));
            }
        }
        //vector<vector<int>> bounds(m, vector<int>(n, 0));
        function<int(int, int, vector<vector<bool>>&)> get_bound = [&](int i, int j, vector<vector<bool>>& visited) -> int {
            int bound = INT_MAX;
            if (visited[i][j]) {
                return bound;
            }
            visited[i][j] = true;
            for (int d = 0; d < 4; d++) {
                int next_i = i + directions[d][0];
                int next_j = j + directions[d][1];
                if (next_i == -1 || next_i == m || next_j == -1 || next_j == n) {
                    bound = 0;
                    continue;
                }
                int neib = heightMap[next_i][next_j];
                if (neib > heightMap[i][j]) {
                    bound = min(bound, neib);
                }
                else {
                    bound = min(bound, get_bound(next_i, next_j, visited));
                }
            }
            return bound;
        };

        function<void(int, int)> fill = [&](int i, int j){
            int bound = INT_MAX;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[i][j] = true;
            for (int d = 0; d < 4; ++d) {
                int next_i = i + directions[d][0];
                int next_j = j + directions[d][1];
                if (next_i == -1 || next_i == m || next_j == -1 || next_j == n) {
                    bound = 0;
                    continue;
                }
                int neib = heightMap[next_i][next_j];
                if (neib > heightMap[i][j]) {
                    bound = min(bound, neib);
                }
                else {
                    bound = min(bound, get_bound(next_i, next_j, visited));
                }
            }
            if (bound > heightMap[i][j]) {
                for (int ii = 0; ii < m; ii++) {
                    for (int jj = 0; jj < n; jj++) {
                        if (visited[ii][jj]) {
                            res += bound - heightMap[ii][jj];
                            heightMap[ii][jj] = bound;
                        }
                    }
                }
                q.push(make_tuple(bound, i, j));
            }
            
        };
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int height = get<0>(t);
            int i = get<1>(t);
            int j = get<2>(t);
            if (height < heightMap[i][j]) {
                continue;
            }
            fill(i, j);
        }
        return res;
    }



    int trapRainWater(vector<vector<int>>& heightMap) {
        auto cmp = [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> q(cmp);
        vector<vector<int>> directions({ {1,0},{0,1},{-1,0},{0,-1} });
        size_t m = heightMap.size();
        if (m <= 2) {
            return 0;
        }
        size_t n = heightMap[0].size();
        if (n <= 2) {
            return 0;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            visited[i][0] = visited[i][n - 1] = true;
            q.push(make_tuple(heightMap[i][0], i, 0));
            q.push(make_tuple(heightMap[i][n - 1], i, n - 1));
        }
        for (int j = 1; j < n - 1; j++) {
            visited[0][j] = visited[m - 1][j] = true;
            q.push(make_tuple(heightMap[0][j], 0, j));
            q.push(make_tuple(heightMap[m - 1][j], m - 1, j));
        }

        int res = 0;

        function<void(int, int, int)> compute_wall = [&](int i, int j, int height) {
            for (auto d : directions) {
                int next_i = i + d[0];
                int next_j = j + d[1];
                if (next_i >= 0 && next_i < m && next_j >= 0 && next_j < n && !visited[next_i][next_j]) {
                    visited[next_i][next_j] = true;
                    res += max(0, height - heightMap[next_i][next_j]);
                    heightMap[next_i][next_j] = max(height, heightMap[next_i][next_j]);
                    q.push(make_tuple(heightMap[next_i][next_j], next_i, next_j));
                }
            }
        };

        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            compute_wall(get<1>(t), get<2>(t), get<0>(t));
        }
        return res;
    }
};

int main() {
    cout << Solution().splitArray(vector<int>({ 7,2,5,10,8,11,6,7,1 }), 5) << endl;

    cout << Solution().trapRainWater(vector<vector<int>>({
        {14,11,18,16,14,16},
        {17,3,10,2,3,8},
        {11,10,4,7,1,7},
        {13,7,2,9,8,10},
        {13,1,3,4,8,6},
        {20,3,3,9,10,8} })) << endl;


}