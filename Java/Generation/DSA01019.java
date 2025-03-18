import java.util.Scanner;

public class DSA01019 {
    public static void GenHAHA(int N, String string) {
        if (N == 0) {
            if (string.charAt(0) == 'H' && string.charAt(string.length() - 1) == 'A' && string.contains("HH") == false) {
                System.out.println(string);
            }
            return;
        }

        GenHAHA(N - 1, string + "A");
        GenHAHA(N - 1, string + "H");
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int Test = in.nextInt();
        while (Test-- > 0) {
            int N = in.nextInt();

            GenHAHA(N, "");

            System.out.println();
        }
        
        in.close();
    }
}
