// 1. 배열에서 슬라이딩을 할 수 있는 범위는 0 ~ length - k 까지 슬라이딩이 가능하므로, 설정
// 2. x를 기준 값으로 x - arr[mid] 와 arr[mid + k] - x 차를 확인했을 때, 
// 3. x - arr[mid]가 더 크다면 오른쪽으로
// 4. arr[mid + k] - x가 더 크다면 왼쪽으로 슬라이딩 해야함.
// 5. 오른쪽 슬라이딩은 left = mid + 1로 하면 x - arr[mid + 1] arr[mid + 1 - k] - x이므로 오른쪽 슬라이딩
// 6. 왼쪽 슬라이딩은 right = mid 로 한다면 x - arr[]
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int left = 0, right = arr.length - k;
        while(left < right) {
            int mid = (left + right) / 2;
            if(x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return Arrays.stream(arr, left, left + k).boxed().collect(Collectors.toList());
    }
}