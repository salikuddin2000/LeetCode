class Solution {
public:
    double myPow(double x, int n) {
       if(n>0){
       return Pow(x,n);
   }
    else
        return 1/Pow(x,n);
}

double Pow(double x,int n){
     if(n==0){
        return 1;
    }
    double P = Pow(x,n/2);
    
	// n is even
    if(n%2==0){
       return P*P;
    }
	//n is odd
    else{
        return P*P*x;
    }
}
};