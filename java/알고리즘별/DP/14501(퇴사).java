import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        ArrayList<Pair> arr = new ArrayList<>();
        int[] dp = new int[N + 1];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            int T = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());

            arr.add(new Pair(T, P));
        }

        for (int i = N - 1; i >= 0; i--) {
            // 오늘 날짜 + 걸리는 일 수 > 최대 마감일
            if (i + arr.get(i).getFirst()> N) {
                dp[i] = dp[i + 1];
            } else {
                dp[i] = Math.max(dp[i + 1], dp[i + arr.get(i).getFirst()] + arr.get(i).getSecond());
            }
        }

        bw.write(Integer.toString(dp[0]));
        br.close();
        bw.flush();
        bw.close();
    }

    public static class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }
}