import java.io.*;
import java.util.*;

public class Main
{
    static class Pos
    {
        int v, cnt;
        Pos(int v, int cnt)
        {
            this.v = v;
            this.cnt = cnt;
        }
    }

    static ArrayList<Integer> bfs(int vertex, int limit, int start, ArrayList<ArrayList<Integer>> graph)
    {
        boolean[] visited = new boolean[vertex + 1];
        ArrayList<Integer> answer = new ArrayList<>();
        Deque<Pos> queue = new ArrayDeque<>();
        visited[start] = true;
        queue.offer(new Pos(start, 0));
        while (!queue.isEmpty())
        {
            Pos current = queue.poll();
            if (current.cnt == limit)
            {
                answer.add(current.v);
                continue;
            }
            for (int nxt : graph.get(current.v))
            {
                if (!visited[nxt])
                {
                    visited[nxt] = true;
                    queue.offer(new Pos(nxt, current.cnt + 1));
                }
            }
        }
        Collections.sort(answer);
        return answer;
    }

    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/18352
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        StringBuilder result = new StringBuilder();
        int vertex = Integer.parseInt(st.nextToken());
        int edge = Integer.parseInt(st.nextToken());
        int dist = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i <= vertex; i++)
        {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < edge; i++)
        {
            st = new StringTokenizer(scan.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            graph.get(v1).add(v2);
        }
        ArrayList<Integer> ans = bfs(vertex, dist, start, graph);
        if (ans.isEmpty())
        {
            result.append("-1");
        } else
        {
            for (int i : ans)
            {
                result.append(i).append("\n");
            }
        }
        System.out.println(result);
        scan.close();
    }
}
