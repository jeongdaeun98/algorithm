import java.util.*;
class RandomizedSet {

    Set<Integer> set;
    Random rand;
    
    public RandomizedSet() {
        set = new HashSet<>();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        boolean exist = set.contains(val);
        set.add(val);
        return !exist;
    }
    
    public boolean remove(int val) {
        boolean exist = set.contains(val);
        set.remove(val);
        return exist;
    }
    
    public int getRandom() {
        int randomIndex = rand.nextInt(set.size());
        AtomicInteger index = new AtomicInteger(0);
        Optional<Integer> number = set.stream().filter(num -> index.getAndIncrement() == randomIndex).findFirst();
        return number.get();
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */