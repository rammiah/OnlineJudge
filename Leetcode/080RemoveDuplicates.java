// remove the duplicate items from nums array,
// an item can duplicate no more than 2 times
public class _80RemoveDuplicates {
    public int removeDuplicates(int[] nums) {
        int newIndex = 0;
        int oldIndex = 0;
        while (oldIndex < nums.length) {
            nums[newIndex++] = nums[oldIndex++];
            if (oldIndex < nums.length && nums[oldIndex] == nums[oldIndex - 1]){
                nums[newIndex++] = nums[oldIndex++];
            }
            while (oldIndex < nums.length && nums[oldIndex] == nums[oldIndex - 1]) oldIndex++;
        }
        return newIndex;
    }

    public static void main(String[] args) {
        _80RemoveDuplicates sol = new _80RemoveDuplicates();
        System.out.println(sol.removeDuplicates(new int[]{1, 1, 1, 2, 2, 3}));
    }
}
