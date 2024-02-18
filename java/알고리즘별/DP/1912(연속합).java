import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int answer = 0;
        int N = Integer.parseInt(br.readLine());
        ArrayList<Integer> list = new ArrayList<>();
        ArrayList<Integer> dp = new ArrayList<>();

        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }

        dp.add(list.get(0));
        answer = dp.get(0);

        for (int i = 1; i < N; i++) {
            if (dp.get(i - 1) + list.get(i)  < list.get(i)) {
                dp.add(list.get(i));
            }
            else {
                dp.add(dp.get(i - 1) + list.get(i));
            }

            answer = Math.max(answer, dp.get(i));
        }

        bw.write(Integer.toString(answer));
        br.close();
        bw.flush();
        bw.close();
    }
}