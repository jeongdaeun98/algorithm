import java.util.Map;
import java.util.HashMap;
class Solution {
    public int romanToInt(String s) {
        int answer = 0;
        Map<String, Integer> symbols = new HashMap<>();
        Map<String, Integer> twoSymbols = new HashMap<>();
        symbols.put("I", 1);
        symbols.put("V", 5);
        symbols.put("X", 10);
        symbols.put("L", 50);
        symbols.put("C", 100);
        symbols.put("D", 500);
        symbols.put("M", 1000);
        twoSymbols.put("IV", 4);
        twoSymbols.put("IX", 9);
        twoSymbols.put("XL", 40);
        twoSymbols.put("XC", 90);
        twoSymbols.put("CD", 400);
        twoSymbols.put("CM", 900);
        Set<String> twoSymbolKeys = twoSymbols.keySet();
        for(String twoSymbol : twoSymbolKeys) {
            while(s.contains(twoSymbol)) {
                answer += twoSymbols.get(twoSymbol);
                s = s.replaceFirst(twoSymbol, "");
            }
        }
        Set<String> symbolKeys = symbols.keySet();
        for(String symbol : symbolKeys) {
            while(s.contains(symbol)) {
                answer += symbols.get(symbol);
                s = s.replaceFirst(symbol, "");
            }
        }
        return answer;
    }
}