import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int answer = 0;
        // 배열 (정적 할당)
        int[] arr = new int[N];
        int[] dp = new int[N];
        // ArrayList는 컬렉션으로, 일반적인 배열과 달리, 길이가 가변적이다. (동적 할당)
        ArrayList<Integer> ans = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < N; i++) {
            dp[i] = 1;

            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > answer) {
                answer = dp[i];

                ans.clear();

                int cnt = dp[i];

                for (int j = i; j >= 0; j--) {
                    if (dp[j] == cnt) {
                        ans.add(arr[j]);
                        cnt--;
                    }
                }
            }
        }

        bw.write(Integer.toString(answer) + '\n');

        for (int i = ans.size() - 1; i >= 0; i--) {
            // ArrayList는 get을 통해 요소를 가져온다.
            bw.write(Integer.toString(ans.get(i)) + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}