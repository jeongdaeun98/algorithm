using namespace std;

int solution(int X, int Y, int D) {
    if(X == Y) return 0;
    if((Y-X)%D > 0) return (Y-X)/D + 1;
    return (Y-X)/D;
}
