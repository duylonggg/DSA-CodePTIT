import java.util.Scanner;

public class DSA01013 {
    public static void convertGrayToBinary(String gray) {
        System.out.print(gray.charAt(0));
        int prev = gray.charAt(0) - '0';

        for (int i = 1; i < gray.length(); ++i) {
            int cur = gray.charAt(i) - '0';
            int bit = cur ^ prev;
            System.out.print(bit);
            prev ^= cur;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int testCases = scanner.nextInt();
        
        while (testCases-- > 0) {
            String gray = scanner.next();
            convertGrayToBinary(gray);
        }

        scanner.close();
    }
}
