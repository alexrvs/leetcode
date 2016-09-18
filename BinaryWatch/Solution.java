public class Solution {

    int[][] times = {
        { 1, 0 },
        { 2, 0 },
        { 4, 0 },
        { 8, 0 },
        { 0, 1 },
        { 0, 2 },
        { 0, 4 },
        { 0, 8 },
        { 0, 16 },
        { 0, 32 },
    };

    private boolean isValidTime(int[] time) {
        if (time[0] < 0 || time[0] > 11) return false;
        if (time[1] < 0 || time[1] > 59) return false;
        return true;
    }

    private void helper(List<String> res, int[] time, int start, int num) {
        if (num == 0) {
            if (isValidTime(time)) {
                String timeStr = time[0] + ":";
                if (time[1] < 10) timeStr += "0" + time[1];
                else timeStr += time[1];
                res.add(timeStr);
            }
            return;
        }
        for (int i = start; i < times.length; i++) {
            time[0] += times[i][0];
            time[1] += times[i][1];
            helper(res, time, i + 1, num - 1);
            time[0] -= times[i][0];
            time[1] -= times[i][1];
        }
        return;
    }

    public List<String> readBinaryWatch(int num) {
        int[] time = new int[2];
        List<String> res = new ArrayList<String>();
        helper(res, time, 0, num);
        return res;
    }
}
