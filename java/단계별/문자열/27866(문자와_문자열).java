import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String S = br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int idx = Integer.parseInt(st.nextToken());
        idx -= 1;

        // Java는 S[idx]가 먹히지 않는다. 따라서 charAt을 쓴다.
        bw.write(S.charAt(idx));
        br.close();
        bw.flush();
        bw.close();
    }
}