import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str, " ");

        int N = Integer.parseInt(st.nextToken());

        for (int i = 1; i < 10; i++) {
            bw.write(N + " * " + i + " = " + (N * i));
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}