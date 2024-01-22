// 1. 오름차순 소팅
// 2. 순회하면서 비어있을 경우, 한칸 넘기고 채우고 반복.
// 3. 모두 순회했으면 다시 순회하면서 비어있을 경우, 한칸 넘기고 채우고 반복.
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int[] newDeck = new int[deck.length];
        Arrays.sort(deck);
        int count = 0;
        int index = 0;
        boolean pass = false;
        while(count != deck.length) {
            index = index % deck.length;
            if(!pass && newDeck[index] == 0) {
                newDeck[index] = deck[count];
                count++;
                pass = true;
            } else if(newDeck[index] == 0){
                pass = false;
            }
            index++;
        }
        return newDeck;
    }
}