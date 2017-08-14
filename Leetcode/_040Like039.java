import java.util.*;

public class Solution {

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> temp = new ArrayList<>();
        Set<List<Integer>> result = new HashSet<>();
        if (candidates == null || candidates.length == 0) return null;
        Arrays.sort(candidates);
        search(0, candidates, target, result, temp);
        // set转list这么爽的吗？？？？
        return new ArrayList<>(result);
    }

    private void search(int start, int[] candidates, int target, Set<List<Integer>> result, List<Integer> temp) {
        if (target == 0) result.add(new ArrayList<>(temp));
        for (int i = start; i < candidates.length; ++i) {
            if (candidates[i] <= target) {
                temp.add(candidates[i]);
                search(i + 1, candidates, target - candidates[i], result, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }
}
