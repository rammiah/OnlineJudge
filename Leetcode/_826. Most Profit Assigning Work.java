class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        if (difficulty.length == 0 || worker.length == 0) {
            return 0;
        }

        int pro = 0;
        quickSort(difficulty, profit, 0, difficulty.length - 1);
        for (int ability : worker) {
            // find work for person
            int money = 0;
            for (int i = 0; i < difficulty.length; ++i) {
                if (difficulty[i] <= ability) {
                    money = Math.max(money, profit[i]);
                } else {
                    break;
                }
            }
            pro += money;
        }

        return pro;
    }

    void quickSort(int[] diffi, int[] pro, int start, int end) {
        if (start >= end) {
            return;
        }

        int s = start, e = end;
        int dmid = diffi[s];
        int pmid = pro[s];
        while (s < e) {
            while (s < e && diffi[e] >= dmid) {
                --e;
            }
            swap(diffi, s, e);
            swap(pro, s, e);
            while (s < e && diffi[s] <= dmid) {
                ++s;
            }
            swap(diffi, s, e);
            swap(pro, s, e);
        }
        
        diffi[s] = dmid;
        pro[s] = pmid;
        quickSort(diffi, pro, start, s - 1);
        quickSort(diffi, pro, s + 1, end);

    }
    
    void swap(int[] arr, int a, int b) {
        int t = arr[a];
        arr[a] = arr[b];
        arr[b] = t;
    }
}