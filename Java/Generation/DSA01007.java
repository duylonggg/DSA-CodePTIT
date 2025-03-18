import java.util.Scanner;

public class DSA01007 {
    public static void GenAB(int N, String string) {
        if (N == 0) {
            System.out.print(string + " ");
            return;
        }

        GenAB(N - 1, string + "A");
        GenAB(N - 1, string + "B");
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();

            GenAB(N, "");

            System.out.println();
        }
        
        in.close();
    }
}
