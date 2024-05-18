#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    // Bubble Sort
    vector<int> bubbleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }

    // Quick Sort
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        int pivot = nums[n / 2];
        vector<int> left, right, equal;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                left.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                right.push_back(nums[i]);
            } else {
                equal.push_back(nums[i]);
            }
        }
        vector<int> res;
        vector<int> left_res = quickSort(left);
        vector<int> right_res = quickSort(right);
        res.insert(res.end(), left_res.begin(), left_res.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), right_res.begin(), right_res.end());
        return res;
    }

    // 5. Insertion Sort
    vector<int> insertionSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
            for (int k = 0; k < nums.size(); k++) {
                cout << nums[k] << " ";
            }
            cout << endl;
        }
        return nums;
    }

    // 6. Bucket Sort
    vector<int> bucketSort(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        int min_val = *min_element(nums.begin(), nums.end());
        int bucket_size = 5;
        int bucket_num = (max_val - min_val) / bucket_size + 1;
        vector<vector<int>> buckets(bucket_num);
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - min_val) / bucket_size;
            buckets[idx].push_back(nums[i]);
        }
        for (int i = 0; i < bucket_num; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        vector<int> res;
        for (int i = 0; i < bucket_num; i++) {
            res.insert(res.end(), buckets[i].begin(), buckets[i].end());
        }
        return res;
    }

    /*
    [1,2,3,4,5]  [6,7,8,9,10]
    */
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 4};
    Solution sol;
    vector<int> res = sol.bucketSort(nums);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}