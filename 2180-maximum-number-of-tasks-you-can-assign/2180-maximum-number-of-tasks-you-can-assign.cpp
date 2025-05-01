class Solution {
public:
 bool canAssignTasks(int numTasks, const vector<int>& taskReqs, const vector<int>& workerStrengths, int remainingPills, int pillBoost) {
        multimap<int, int> availableWorkers;
        int totalWorkers = workerStrengths.size();
        for (int i = totalWorkers - numTasks; i < totalWorkers; ++i) {
            availableWorkers.insert({workerStrengths[i], 1});
        }

        for (int idx = numTasks - 1; idx >= 0; --idx) {
            int requiredStrength = taskReqs[idx];
            auto strongestIt = prev(availableWorkers.end());
            if (strongestIt->first >= requiredStrength) {
                if (--strongestIt->second == 0)
                    availableWorkers.erase(strongestIt);
            } else {
                if (remainingPills == 0) return false;
                int minStrengthNeeded = requiredStrength - pillBoost;
                auto boostedIt = availableWorkers.lower_bound(minStrengthNeeded);
                if (boostedIt == availableWorkers.end()) return false;
                if (--boostedIt->second == 0)
                    availableWorkers.erase(boostedIt);
                --remainingPills;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& taskReqs, vector<int>& workerStrengths, int pills, int boost) {
        sort(taskReqs.begin(), taskReqs.end());
        sort(workerStrengths.begin(), workerStrengths.end());
        int left = 0;
        int right = min(taskReqs.size(), workerStrengths.size());
        int maxAssignable = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAssignTasks(mid, taskReqs, workerStrengths, pills, boost)) {
                maxAssignable = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return maxAssignable;
    }
};