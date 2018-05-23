import java.util.ArrayList;
import java.util.List;

public class Solution {
    // 还是进了递归的坑啊
    // 按理说改成递推是没有任何问题的，但是可读性应该会下降不少
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<Integer> temp = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        // 如果没戏就返回吧
        if (candidates == null || candidates.length == 0) return result;
        // 开始搜索
        search(0, candidates, target, result, temp);
        return result;
    }
    // 类似深度搜索
    private void search(int start, int[] candidates, int target, List<List<Integer>>result, List<Integer> temp) {
        // 得出结果就加入到result里面，不能直接加入原来的，加入的是引用
        if (target == 0) result.add(new ArrayList<>(temp));
        // 从start那里开始检测，防止重现
        for (int i = start; i < candidates.length; ++i) {
            // 小于等于就继续
            if (candidates[i] <= target) {
                // 这点有点麻烦
                temp.add(candidates[i]);
                search(i, candidates, target - candidates[i], result, temp);
                temp.remove(temp.size() - 1);
            }
        }
    }
}
