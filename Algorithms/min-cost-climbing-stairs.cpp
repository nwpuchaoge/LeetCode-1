// 746. Min Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/

/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size(), i;
        if (sz == 0) {
            return 0;
        }
        if (sz == 1) {
            return cost[0];
        }
        if (sz == 2) {
            return min(cost[0], cost[1]);
        }
        vector<int> A(sz);
        A[sz - 1] = cost[sz - 1];
        A[sz - 2] = cost[sz - 2];
        i = sz - 3;
        while (i >= 0) {
            A[i] = cost[i] + min(A[i + 1], A[i + 2]);
            --i;
        }
        return min(A[0], A[1]);
    }
};

int main(void) {
    Solution solution;
    vector<int> cost;
    int result;

    cost = {10, 15, 20};
    result = solution.minCostClimbingStairs(cost);
    cout << result << '\n';

    return 0;
}