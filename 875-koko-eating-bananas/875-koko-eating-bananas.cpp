class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int a = 1, b = piles.back(), sum, mid;
        while(a < b){
            mid = (a + b) / 2;
            sum = 0;
            for(int pile:piles){
                sum += ceil(pile*1.0/mid);
            }
            if(sum > h)
                a = mid + 1;
            else
                b = mid;
        }
        return a;
    }
};