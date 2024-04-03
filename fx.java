import java.io.PrintWriter;
import java.util.Scanner;

class Minimizer {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        String s = sc.next();
        int[][] lcp = new int[n+1][n+1];
        int[][] deltas = new int[n+1][n+1];
        for (int i = n-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--){
                if (s.charAt(i) == s.charAt(j)) lcp[i][j] = 1+lcp[i+1][j+1];
            }
        }
        
        for (int p = 0; p < n; p++){
            int[] b = new int[n+1];
            int[] a = new int[n+1];
            int b_cand = p+1;
            for (int l = n; l >= 1; l--){
                while (b_cand < n && compare(p,b_cand,l,lcp,s) <= 0) b_cand++;
                b[l] = Math.min(b_cand+l,n+1);
            }
            int a_cand = p-1;
            for (int l = 1; l <= n; l++){
                while (a_cand >= 0 && compare(p,a_cand,l,lcp,s) < 0) a_cand--;
                a[l] = a_cand+1;
            }
            for (int l = 1; l <= n; l++){
                if (l+p > n) continue;
                deltas[l][Math.min(b[l]-a[l]-1,n)]++;
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                System.out.print(deltas[i][j]+" ");
            }
            System.out.println();
        }
        int[] count = new int[n+1];
        for (int l = 1; l <= n; l++){
            int acc = 0;
            for (int k = n; k >= l; k--){
                acc += deltas[l][k];
                count[acc]++;
            }
        }
        for (int i = 1; i <= n; i++){
            pw.println(count[i]);
        }
        pw.close();
    }
    static int compare(int i, int j, int k, int[][] lcp, String orig){
        if (lcp[i][j] >= k) return 0;
        if (i+lcp[i][j] == orig.length()) return -1;
        if (j+lcp[i][j] == orig.length()) return 1;
        return Character.compare(orig.charAt(i+lcp[i][j]),orig.charAt(j+lcp[i][j]));
    }
}