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
// 只快了一丢丢
// public class Solution {
//     public List<List<Integer>> combinationSum2(int[] candidates, int target) {
//         List<Integer> temp = new ArrayList<>();
//         Set<Integer> to_save = new HashSet<>();
//         List<List<Integer>> result = new ArrayList<>();
//         if (candidates == null || candidates.length == 0) return null;
//         Arrays.sort(candidates);
//         search(0, candidates, target, result, temp, to_save);
//         // set转list这么爽的吗？？？？
//         return new ArrayList<>(result);
//     }

//     private void search(int start, int[] candidates, int target, List<List<Integer>> result, List<Integer> temp, Set<Integer> to_save) {
//         if (target == 0) {
//             int hash = getHash(temp);
//             if (!to_save.contains(hash)) {
//                 result.add(new ArrayList<>(temp));
//                 to_save.add(hash);
//             }
//         }
//         for (int i = start; i < candidates.length; ++i) {
//             if (candidates[i] <= target) {
//                 temp.add(candidates[i]);
//                 search(i + 1, candidates, target - candidates[i], result, temp, to_save);
//                 temp.remove(temp.size() - 1);
//             }
//         }
//     }
    
//     private int getHash(List<Integer>test) {
//         int result = 0;
//         for (Integer aTest : test) {
//             result = result * 39 + aTest;
//         }
//         return result % 1039;
//     }
// }
