class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        for(int i = 0; i < flowerbed.length; i++) {
            if(i > 0 && i < flowerbed.length - 1) {
                if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) {
                    n--;
                    flowerbed[i] = 1;
                }
            } else if(i == 0 && i + 1 < flowerbed.length && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                n--;
                flowerbed[i] = 1;
            } else if(i == flowerbed.length - 1 && 0 <= i - 1 && flowerbed[i - 1] == 0 && flowerbed[i] == 0) {
                n--;
                flowerbed[i] = 1;
            }
        }
        if(n <= 0 || flowerbed.length == 1 && flowerbed[0] == 0 && n == 1) {
            return true;
        } else {
            return false;
        }
    }
}