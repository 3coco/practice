// https://leetcode.com/problems/search-insert-position/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution35 {
public:
    // This function should handle duplicates as well,
    // when there are duplicates, the smallest index
    // will be returned.
    int searchInsert(vector<int> &nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }

        int l = 0;
        int h = nums.size() - 1;
        int found = -1;

        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] >= target) {
                if(nums[mid] == target) {
                    found = mid;
                }
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(nums[l] == target && found == -1) {
            found = l;
        } else if(nums[l] == target && l < found) {
            found = l;
        }

        if(found != -1) {
            return found;
        } else {
            return target < nums[l] ? l : l + 1; 
        }
    }

    // when there are duplicates, the largest index
    // will be returned.
    int searchInsertL(vector<int> &nums, int target) {
        if(nums.size() == 0) {
            return 0;
        }

        int l = 0;
        int h = nums.size() - 1;
        int found = -1;

        while(l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] <= target) {
                if(nums[mid] == target) {
                    found = mid;
                }
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }

        if(nums[l] == target && found == -1) {
            found = l;
        } else if(nums[l] == target && l > found) {
            found = l;
        }

        if(found != -1) {
            return found;
        } else {
            return target < nums[l] ? l : l + 1; 
        }
    }
};

int main() {
    Solution35 sol;
    vector<int> vec0;
    int ans = 0; 
    int ret = sol.searchInsert(vec0, 100);
    if(ans != ret) {
        cout << "Test#0 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    vector<int> vec1;
    vec1.push_back(0);
    ans = 0;
    ret = sol.searchInsert(vec1, 0);
    if(ans != ret) {
        cout << "Test#1 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 0;
    ret = sol.searchInsert(vec1, -1); 
    if(ans != ret) {
        cout << "Test#2 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 1;
    ret = sol.searchInsert(vec1, 1); 
    if(ans != ret) {
        cout << "Test#3 failed: ret = " << ret << ", ans = " << ans << endl;
    } 

    int nums[4] = {1, 3, 5, 6};
    vector<int> vec2(nums, nums + sizeof(nums) / sizeof(nums[0]));
    ans = 2;
    ret = sol.searchInsert(vec2, 5);
    if(ans != ret) {
        cout << "Test#4 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 1;
    ret = sol.searchInsert(vec2, 2);
    if(ans != ret) {
        cout << "Test#5 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 4;
    ret = sol.searchInsert(vec2, 7);
    if(ans != ret) {
        cout << "Test#6 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 0;
    ret = sol.searchInsert(vec2, 0);
    if(ans != ret) {
        cout << "Test#7 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    int dups[4] = {1, 1, 1 ,1};
    vector<int> vec3(dups, dups + sizeof(dups) / sizeof(dups[0]));
    ans = 0;
    ret = sol.searchInsert(vec3, 1);
    if(ans != ret) {
        cout << "Test#8 failed: ret = " << ret << ", ans = " << ans << endl;
    }
    
    ans = 4;
    ret = sol.searchInsert(vec3, 2);
    if(ans != ret) {
        cout << "Test#8 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    int dups2[11] = {1, 1, 1, 3, 3, 3, 5, 6, 6, 6, 6};
    vector<int> vec4(dups2, dups2 + sizeof(dups2) / sizeof(dups2[0]));
    ans = 0;
    ret = sol.searchInsert(vec4, 1);
    if(ans != ret) {
        cout << "Test#9 failed: ret = " << ret << ", ans = " << ans << endl;
    }
    
    ans = 3;
    ret = sol.searchInsert(vec4, 3);
    if(ans != ret) {
        cout << "Test#10 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 7;
    ret = sol.searchInsert(vec4, 6);
    if(ans != ret) {
        cout << "Test#11 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 0;
    ret = sol.searchInsert(vec4, 0);
    if(ans != ret) {
        cout << "Test#12 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 3;
    ret = sol.searchInsert(vec4, 2);
    if(ans != ret) {
        cout << "Test#13 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 6;
    ret = sol.searchInsert(vec4, 4);
    if(ans != ret) {
        cout << "Test#14 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 11;
    ret = sol.searchInsert(vec4, 7);
    if(ans != ret) {
        cout << "Test#15 failed: ret = " << ret << ", ans = " << ans << endl;
    }
   
    // {1, 1, 1, 3, 3, 3, 5, 6, 6, 6, 6};
    // test case #16-22 for returning the largest index when duplicates.
    ans = 2;
    ret = sol.searchInsertL(vec4, 1);
    if(ans != ret) {
        cout << "Test#16 failed: ret = " << ret << ", ans = " << ans << endl;
    }
    
    ans = 5;
    ret = sol.searchInsertL(vec4, 3);
    if(ans != ret) {
        cout << "Test#17 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 10;
    ret = sol.searchInsertL(vec4, 6);
    if(ans != ret) {
        cout << "Test#18 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 0;
    ret = sol.searchInsertL(vec4, 0);
    if(ans != ret) {
        cout << "Test#19 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 3;
    ret = sol.searchInsertL(vec4, 2);
    if(ans != ret) {
        cout << "Test#20 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 6;
    ret = sol.searchInsertL(vec4, 4);
    if(ans != ret) {
        cout << "Test#21 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    ans = 11;
    ret = sol.searchInsertL(vec4, 7);
    if(ans != ret) {
        cout << "Test#22 failed: ret = " << ret << ", ans = " << ans << endl;
    }

    return 0;
}
