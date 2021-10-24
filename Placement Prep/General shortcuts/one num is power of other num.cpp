

let 'n' be a number;

if(n>0)
power of 2 : n&(n-1)==0
power of 4 : n&(n-1)==0 && n&(0x55555555);
general power of p : (int) log(n)/log(p)==(double)log(n)/log(p);


Power of 2:
If we subtract a power of 2 numbers by 1 then all unset bits after the only set bit become set; and the set bit become unset.

For example for 4 ( 100) and 16(10000), we get following after subtracting 1
3 –> 011
15 –> 01111

So, if a number n is a power of 2 then bitwise & of n and n-1 will be zero. 
We can say n is a power of 2 or not based on value of n&(n-1). 
The expression n&(n-1) will not work when n is 0. 
To handle this case also, our expression will become n& (!n&(n-1))

// Take care of log base 10 value :((

    bool isPowerOfThree(int n) {
        if(n<1)
            return 0;
        double t=log10(n)/log10(3);
        return t==(int)t;
    }