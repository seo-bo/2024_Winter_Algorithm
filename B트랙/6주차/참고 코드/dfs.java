import java.io.*;
import java.util.*;

public class Main
{
    static int dfs(int node, int limit, int distance, ArrayList<ArrayList<Integer>> graph, int[] apple, boolean[] visited)
    {
        visited[node] = true;
        int cnt = apple[node];
        if (distance + 1 <= limit)
        {
            for (int nxt : graph.get(node))
            {
                if (!visited[nxt])
                {
                    cnt += dfs(nxt, limit, distance + 1, graph, apple, visited);
                }
            }
        }
        return cnt;
    }
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/25516
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        int vertex = Integer.parseInt(st.nextToken());
        int dist = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < vertex; i++)
        {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < vertex - 1; i++)
        {
            st = new StringTokenizer(scan.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            graph.get(v1).add(v2);
            graph.get(v2).add(v1);
        }
        int[] apple = new int[vertex];
        st = new StringTokenizer(scan.readLine());
        for (int i = 0; i < vertex; i++)
        {
            apple[i] = Integer.parseInt(st.nextToken());
        }
        boolean[] visited = new boolean[vertex];
        int result = dfs(0, dist, 0, graph, apple, visited);
        System.out.println(result);
        scan.close();
    }
}
