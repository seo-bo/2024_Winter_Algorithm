import java.io.*;
import java.util.*;

class Edge
{
    int x, y, value;

    public Edge(int x, int y, int value)
    {
        this.x = x;
        this.y = y;
        this.value = value;
    }
}

public class Main
{
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/1261
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++)
        {
            String str = scan.readLine().trim();
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = str.charAt(j) - '0';
            }
        }
        int[][] visited = new int[n][m];
        for (int[] row : visited)
        {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        visited[0][0] = grid[0][0];
        Deque<Edge> dq = new ArrayDeque<>();
        dq.add(new Edge(0, 0, visited[0][0]));
        int[][] dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!dq.isEmpty())
        {
            Edge cur = dq.pollFirst();
            if (cur.x == n - 1 && cur.y == m - 1)
            {
                System.out.println(cur.value);
                break;
            }
            for (int i =0; i < 4;++i)
            {
                int nx = cur.x + dir[i][0];
                int ny = cur.y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (visited[nx][ny] > visited[cur.x][cur.y] + grid[nx][ny])
                    {
                        visited[nx][ny] = visited[cur.x][cur.y] + grid[nx][ny];
                        Edge nextEdge = new Edge(nx, ny, visited[nx][ny]);
                        if (grid[nx][ny] == 1)
                        {
                            dq.addLast(nextEdge);
                        }
                        else
                        {
                            dq.addFirst(nextEdge);
                        }
                    }
                }
            }
        }
        scan.close();
    }
}
