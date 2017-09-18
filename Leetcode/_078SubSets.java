import java.util.ArrayList;
import java.util.List;
// find all the subset for the given array
public class _78SubSets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        result.add(new ArrayList<>());
        search(result, new ArrayList<>(), nums, 0);
        return result;
    }

    // 还是先想好怎么写比较重要啊
    void search(List<List<Integer>> result, List<Integer> temp, int[] nums, int index) {
        if (index >= nums.length) return;
        for (int i = index; i < nums.length; i++) {
            temp.add(nums[i]);
            result.add(new ArrayList<>(temp));
            search(result, temp, nums, i + 1);
            temp.remove(temp.size() - 1);
        }
    }
}
