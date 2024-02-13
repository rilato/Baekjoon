import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            int gcd = GCD(N, M);
            int lcm = N * M / gcd;

            bw.write(Integer.toString(lcm) + '\n');
        }

        br.close();
        bw.flush();
        bw.close();
    }

    public static int GCD(int a, int b) {
        while(b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }

        return a;
    }
}