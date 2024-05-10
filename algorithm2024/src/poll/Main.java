package poll;

import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    //문자열 입력
    public void solutionStr() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
    }

    //숫자 입력
    public void solutionInt() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int number = parseInt(br.readLine());
    }
    // 공백으로 한단어씩 받는 경우
    public void solutionSplit(int m) throws Exception {
        int[] targetArray = new int[100];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < m; i++){
            targetArray[i] = Integer.parseInt(st.nextToken());
        }
    }
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}