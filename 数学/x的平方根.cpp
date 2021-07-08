
int mySqrt(int x){
    int l = 0, r = x, ans = -1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if((long long)mid * mid <= x){
            ans = mid;
            r = mid + 1;
        }else{
            l = mid - 1;
        }
    }

}