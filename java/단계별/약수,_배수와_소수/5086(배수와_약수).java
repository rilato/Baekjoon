import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // while문 안에 1을 넣으면 안된다.
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());

            // !A !B가 작동하지 않는다.
            if (A == 0 && B == 0) {
                break;
            }

            if (B > A && B % A == 0) {
                bw.write("factor\n");
            }
            else if (A > B && A % B == 0) {
                bw.write("multiple\n");
            }
            else {
                bw.write("neither\n");
            }
        }

        br.close();
        bw.flush();
        bw.close();
    }
}