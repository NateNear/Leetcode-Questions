class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count_0 = 0, count_1 = 0;
        for (int student : students) {
            if (student == 0)
                count_0++;
            else
                count_1++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count_0 == 0)
                    return count_1;
                count_0--;
            } else {
                if (count_1 == 0)
                    return count_0;
                count_1--;
            }
        }

        return 0;
    }
};
