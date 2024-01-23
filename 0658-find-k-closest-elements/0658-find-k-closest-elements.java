// 1. 배열에서 슬라이딩을 할 수 있는 범위는 0 ~ length - k 까지 슬라이딩이 가능하므로, 설정
// 2. x를 기준 값으로 x - arr[mid] 와 arr[mid + k] - x 차를 확인했을 때, 
// 3. x - arr[mid]가 더 크다면 오른쪽으로
// 4. arr[mid + k] - x가 더 크다면 왼쪽으로 슬라이딩 해야함.
// 5. 오른쪽 슬라이딩은 mid mid - 1 mid - 2 ...는 볼필요 없는 것이므로 left = mid + 1
// 6. 왼쪽 슬라이딩은 k는 1이상이므로, mid + 1 mid + 2 mid + 3..는 볼필요 없으니 right = mid
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