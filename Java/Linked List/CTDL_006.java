import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class CTDL_006 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        LinkedList<Integer> linkedList = new LinkedList<>();
        int n = input.nextInt();
        for (int i = 0; i < n; ++i) {
            linkedList.add(input.nextInt());
        }

        LinkedList<Integer> distinctList = linkedList.stream()
                                             .distinct()
                                             .collect(Collectors.toCollection(LinkedList::new));

        for (int num : distinctList) {
            System.out.print(num + " ");
        }
        System.out.println();

        input.close();
    }
}
