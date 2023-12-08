void solve(int c, int l, int r, int mask, int* ans){
    if (c == mask){
        (*ans)++;
        return;
    }
    int p = ~(c | l | r) & mask;
    while (p){
        int b = p & -p;
        p -= b;
        solve(c | b, (l | b) << 1, (r | b) >> 1, mask, ans);
    }
}

int main(){
    print("求解N皇后问题,输入N:");
    int n = input();
    int ans = 0;
    int mask = (1 << n) - 1;
    solve(0, 0, 0, mask, &ans);
    output(ans);
    return 0;
}