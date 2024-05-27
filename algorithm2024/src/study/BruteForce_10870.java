package study;

import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BruteForce_10870 {
    //숫자 입력
    public static int solutionInt() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        return parseInt(br.readLine());

    }
    public static int fibonacci(int num) {
        if(num <= 0) {
            return 0;
        } else if(num == 1) {
            return 1;
        }
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
    public static void main(String[] args) throws IOException {
        System.out.println(fibonacci(solutionInt()));

    }
}