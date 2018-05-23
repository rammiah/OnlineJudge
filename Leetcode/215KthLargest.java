class Solution {
    // use quick sort solution

    // from big to small, not descending
    int quickSort(int[] arr, final int start, final int end, final int require) {
        int key = arr[start];
        int s = start, e = end;
        while (s < e) {
            while (arr[e] <= key && s < e) --e;
            arr[s] = arr[e];
            while (arr[s] >= key && s < e) ++s;
            arr[e] = arr[s];
        }
        arr[s] = key;
        if (s < require) {
            return quickSort(arr, s + 1, end, require);
        } else if (s > require) {
            return quickSort(arr, start, s - 1, require);
        }
        return arr[s];
    }

    public int findKthLargest(int[] nums, int k) {
        return quickSort(nums, 0, nums.length - 1, k - 1);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {3, 2, 1, 5, 6, 4};
        for (int i = 0; i < arr.length; i++) {
            System.out.println(sol.findKthLargest(arr, i + 1));
        }
    }
}
