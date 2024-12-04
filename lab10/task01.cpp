//23k-0832
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> slidingWindowMaximum(const vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> maxHeap; // Max-heap to store (value, index)
    vector<int> result;

    for (int i = 0; i < nums.size(); i++)
    {
        // Add current element with its index to the heap
        maxHeap.push({nums[i], i});

        // Remove elements that are out of the current window
        while (!maxHeap.empty() && maxHeap.top().second <= i - k)
        {
            maxHeap.pop();
        }

        // Add the maximum element of the current window to the result
        if (i >= k - 1)
        {
            result.push_back(maxHeap.top().first);
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = slidingWindowMaximum(nums, k);

    cout << "Sliding Window Maximums: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
