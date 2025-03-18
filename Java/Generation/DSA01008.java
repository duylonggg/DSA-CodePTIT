import java.util.Scanner;

public class DSA01008 {
    public static void GenBit(int N, int K, String string) {
        if (N == 0) {
            if (K == 0) {
                System.out.println(string);
            }
            return;
        }

        GenBit(N - 1, K, string + "0");
        GenBit(N - 1, K - 1, string + "1");
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt(), K = in.nextInt();

            GenBit(N, K, "");

            System.out.println();
        }
        
        in.close();
    }
}
