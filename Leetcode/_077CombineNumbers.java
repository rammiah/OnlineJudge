import java.util.ArrayList;
import java.util.List;
// find all the combination of k numbers from 1 to n
public class _077CombineNumbers {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        search(result, new ArrayList<Integer>(), 0, n, k);
        return result;
    }

    void search(List<List<Integer>> result, List<Integer> temp, int index, int limit, int leftDepth) {
        if (leftDepth == 0) {
            result.add(new ArrayList<>(temp));
            return;
        }
        for (int i = index + 1; i <= limit; i++) {
            temp.add(i);
            search(result, temp, i, limit, leftDepth - 1);
            temp.remove(temp.size() - 1);
        }
    }

    public static void main(String[] args) {
        _077CombineNumbers sol = new _077CombineNumbers();
        System.out.println(sol.combine(4, 2));
    }
}
