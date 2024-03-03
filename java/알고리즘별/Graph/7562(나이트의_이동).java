import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(br.readLine());
            int[][] arr = new int[N][N];
            boolean[][] visited = new boolean[N][N];
            boolean flag = false;
            int[] dr = { 1, 1, -1, -1, 2, 2, -2, -2 };
            int[] dc = { 2, -2, 2, -2, 1, -1, 1, -1 };

            StringTokenizer st1 = new StringTokenizer(br.readLine(), " ");

            int startRow = Integer.parseInt(st1.nextToken());
            int startCol = Integer.parseInt(st1.nextToken());

            StringTokenizer st2 = new StringTokenizer(br.readLine(), " ");

            int endRow = Integer.parseInt(st2.nextToken());
            int endCol = Integer.parseInt(st2.nextToken());

            arr[startRow][startCol] = 0;
            visited[startRow][startCol] = true;

            Queue<Pair> q = new LinkedList<>();

            q.add(new Pair(startRow, startCol));

            while (!q.isEmpty()) {
                int r = q.peek().getFirst();
                int c = q.peek().getSecond();

                q.remove();

                if (r == endRow && c == endCol) {
                    flag = true;
                    bw.write(Integer.toString(arr[r][c]));
                    bw.newLine();
                    break;
                }

                for (int j = 0; j < 8; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];

                    if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        arr[nr][nc] = arr[r][c] + 1;
                        q.add(new Pair(nr, nc));
                    }
                }
            }

            if (!flag) {
                bw.write("0");
                bw.newLine();
            }
        }

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
