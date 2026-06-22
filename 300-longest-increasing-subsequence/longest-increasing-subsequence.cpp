class Solution {
public:
    int findPosition(vector<int>& tails, int target) {
    int low = 0, high = tails.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (tails[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        int pos = findPosition(tails, num);
        if (pos == tails.size())
            tails.push_back(num);
        else
            tails[pos] = num;
    }
    return tails.size();
}
};