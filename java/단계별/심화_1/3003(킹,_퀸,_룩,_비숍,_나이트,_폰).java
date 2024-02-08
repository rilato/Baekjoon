import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] chess = {1, 1, 2, 2, 2, 8};
        int[] answer = new int[6];
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        for (int i = 0; i < 6; i++) {
            int n = Integer.parseInt(st.nextToken());
            answer[i] = chess[i] - n;
        }

        for (int i = 0; i < 6; i++) {
            bw.write(Integer.toString(answer[i]) + " ");
        }

        br.close();
        bw.flush();
        bw.close();
    }
}