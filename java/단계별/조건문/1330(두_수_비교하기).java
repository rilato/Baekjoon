import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        // 클래스는 대문자로 시작한다.
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();

        StringTokenizer st = new StringTokenizer(str, " ");
        // 클래스에 들어있는 함수는 소문자로 시작한다.
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        if (a < b) {
            bw.write("<");
        }
        else if (a > b) {
            bw.write(">");
        }
        else {
            bw.write("==");
        }

        bw.flush();
        bw.close();
    }
}