class Solution {
public:
    vector<int> counts;
    vector<pair<int, int>> arr;

    void mergeSort(int left, int right) {

        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }


    void merge(int left, int mid, int right) {

        vector<pair<int, int>> temp;

        int i = left;
        int j = mid + 1;

        int rightSmaller = 0;

        while (i <= mid && j <= right) {

            if (arr[j].first < arr[i].first) {

                // arr[j] is smaller than arr[i]
                rightSmaller++;

                temp.push_back(arr[j]);
                j++;

            } else {

                // All right elements already taken
                // are smaller than arr[i]
                counts[arr[i].second] += rightSmaller;

                temp.push_back(arr[i]);
                i++;
            }
        }


        // Remaining left elements
        while (i <= mid) {

            counts[arr[i].second] += rightSmaller;

            temp.push_back(arr[i]);
            i++;
        }


        // Remaining right elements
        while (j <= right) {

            temp.push_back(arr[j]);
            j++;
        }


        // Copy back
        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }
    }


    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        counts.assign(n, 0);

        // Store {value, original index}
        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(0, n - 1);

        return counts;
    }
};