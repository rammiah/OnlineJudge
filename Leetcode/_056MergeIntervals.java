import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

//Definition for an interval.
class Interval {
    int start;
    int end;

    Interval() {
        start = 0;
        end = 0;
    }

    Interval(int s, int e) {
        start = s;
        end = e;
    }
}

class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        // 检查输入
        if (intervals == null || intervals.size() <= 1) return intervals;
        // 使用lambda表达式排序
        intervals.sort(Comparator.comparingInt(a -> a.start));
        // 获取输入数据的数量
        int size = intervals.size();
        // 存储结果的列表
        List<Interval> result = new ArrayList<>();
        // 把第一个写进去
        result.add(intervals.get(0));
        // 存储此时的结尾处数字
        int end = result.get(0).end;
        // 现在的result的size - 1
        int index = 0;

        // 开始处理
        for (int i = 1; i < size; i++) {
            // 可以合并就合并
            if (intervals.get(i).start <= end) {
                result.get(index).end = end = (intervals.get(i).end > end ? intervals.get(i).end : end);
            } else {
                // 不能合并的result里面多一个
                ++index;
                result.add(intervals.get(i));
                end = intervals.get(i).end;
            }
        }

        return result;
    }
}
