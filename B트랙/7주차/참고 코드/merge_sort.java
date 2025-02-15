import java.io.*;
import java.util.*;

public class Main
{
    public static void merge(int[] ary, int left, int mid, int right)
    {
        int n1 = mid - left + 1, n2 = right - mid;
        int[] L = new int[n1], R = new int[n2];
        System.arraycopy(ary, left, L, 0, n1);
        System.arraycopy(ary, mid + 1, R, 0, n2);
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                ary[k++] = L[i++];
            }
            else
            {
                ary[k++] = R[j++];
            }
        }
        while (i < n1)
        {
            ary[k++] = L[i++];
        }
        while (j < n2)
        {
            ary[k++] = R[j++];
        }
    }

    public static void merge_sort(int[] ary, int left, int right)
    {
        if (left < right)
        {
            int mid = (left + right) / 2;
            merge_sort(ary,left,mid);
            merge_sort(ary,mid+1,right);
            merge(ary,left,mid,right);
        }
    }
    public static void main(String[] args) throws IOException
    {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(scan.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] ary = new int[n];
        st = new StringTokenizer(scan.readLine());
        for(int i =0; i<n; ++i)
        {
            ary[i] = Integer.parseInt(st.nextToken());
        }
        merge_sort(ary,0,n-1);
        for(int i =0; i<n;++i)
        {
            System.out.print(ary[i] + " ");
        }
        scan.close();
    }
}
