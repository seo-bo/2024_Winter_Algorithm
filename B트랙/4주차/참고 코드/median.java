import java.io.*;
import java.util.*;

public class Main
{
    static PriorityQueue<Integer> max_heap = new PriorityQueue<>(Collections.reverseOrder());
    static PriorityQueue<Integer> min_heap = new PriorityQueue<>();
    public static void balance()
    {
        if (max_heap.isEmpty() && min_heap.isEmpty())
        {
            return;
        }
        if (!min_heap.isEmpty() && max_heap.peek() > min_heap.peek())
        {
            int mini = min_heap.poll();
            int maxi = max_heap.poll();
            max_heap.add(mini);
            min_heap.add(maxi);
        }
        if (max_heap.size() > min_heap.size() + 1)
        {
           min_heap.add(max_heap.poll());
        }
    }
    public static void main(String[] args) throws IOException // https://www.acmicpc.net/problem/1655
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder ans = new StringBuilder();
        int n = Integer.parseInt(scan.readLine().trim());
        for (int i = 0; i < n; ++i)
        {
            int a = Integer.parseInt(scan.readLine().trim());
            max_heap.add(a);
            balance();
            ans.append(max_heap.peek()).append("\n");
        }
        System.out.println(ans);
        scan.close();
    }
}