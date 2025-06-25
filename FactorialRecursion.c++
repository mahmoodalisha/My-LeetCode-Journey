int factorial(int n){
    if(n == 0){ //base case
        return 1;
    }

    return n* factorial(n-1);
}
/*
How it works:
factorial(3)
→ 3 * factorial(2)
→ 3 * (2 * factorial(1))
→ 3 * (2 * (1 * factorial(0)))
→ 3 * 2 * 1 * 1 = 6
*/