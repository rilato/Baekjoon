import java.io.*;
import java.util.*;

public class Main {
    public static void main (String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];

        for (int i = 1; i <= N; i++) {
            arr[i] = i;

            for (int j = 1; j * j <= i; j++) {
                arr[i] = Math.min(arr[i], arr[i - j * j] + 1);
            }
        }

        bw.write(Integer.toString(arr[N]));
        br.close();
        bw.flush();
        bw.close();
    }
}
