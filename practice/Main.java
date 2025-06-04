import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(3, 4, 6, 1, 5);
        
        Stream<Integer> s1 = nums.stream();
        Stream<Integer> s2 = s1.filter(n -> n%2==0);
        Stream<Integer> s3 = s2.map(n -> 2*n);
        int result = s3.reduce(0, (c,e) -> c+e);

        // int result = nums.stream()
        //                     .filter(n -> n%2==0)
        //                     .map(n -> 2*n)
        //                     .reduce(0, (c,e) -> c+e);

        System.out.println(result);
        s2.forEach(n -> System.out.println(n));
        s3.forEach(n -> System.out.println(n));
    }
}