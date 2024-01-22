// 순회하면서 hashMap 빈도 저장
// 정렬할 때 hashMap 값 큰 순으로 정렬
class Solution {
    public String frequencySort(String s) {
        Map<String, Integer> stringAndCount = new HashMap<>();
        
        for(int i = 0; i < s.length(); i++) {
            String str = Character.toString(s.charAt(i));
            stringAndCount.put(str, stringAndCount.getOrDefault(str, 0) + 1);
        }
        String[] answer = s.split("");
        Arrays.sort(answer, (a1, a2) ->{
            if(stringAndCount.get(a2) - stringAndCount.get(a1) == 0) {
                return a2.charAt(0) - a1.charAt(0);
            }
            return stringAndCount.get(a2) - stringAndCount.get(a1);
            });
        return Arrays.asList(answer).stream().collect(Collectors.joining());
    }
}