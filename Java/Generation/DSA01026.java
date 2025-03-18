import java.util.Scanner;

public class DSA01026 {
    public static void LocPhat(int N, String locphat) {
        if (locphat.length() == N) {
            if (locphat.charAt(0) == '8' && locphat.charAt(N - 1) == '6' && locphat.contains("88") == false && locphat.contains("6666") == false) {
                System.out.println(locphat);
            }
            return;
        }

        LocPhat(N, locphat + "6");
        LocPhat(N, locphat + "8");
    }
    
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int N = in.nextInt();
        LocPhat(N, "");
        
        in.close();
    }
}
