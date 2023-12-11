int modpow(int x, int y, int p){
    int result = 1;
    while (y){
        if (y & 1){
            result = (result * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return result;
}

int gcd(int x, int y){
    if(x < y){
        int tmp = x;
        x = y;
        y = tmp;
    }
    while(y > 0){
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

int cpow(int x, int w2, int n, int p){
    int rx = 1;
    int ry = 0;
    int y = 1;
    int t = 0;
    while (n){
        if (n & 1){
            t = (rx * x + ry * y % p * w2) % p;
            ry = (ry * x + rx * y) % p;
            rx = t;
        }
        t = (x * x + y * y % p * w2) % p;
        y = (y * x + x * y) % p;
        x = t;
        n = n >> 1;
    }
    return rx;
}

int modsqrt(int x, int p){
    // cipolla's algorithm
    if (x == 0){
        return 0;
    }
    if (modpow(x, (p - 1) / 2, p) == p - 1){
        return -1;
    }
    int i = 1;
    while(i < p){
        int tmp = (i * i + p - x) % p;
        if (tmp == 0){
            return i;
        }
        if (modpow(tmp, (p - 1) / 2, p) == p - 1){
            return cpow(i, tmp, (p + 1) / 2, p);
        }
        i = i + 1;
    }
    return -1;
}

int main(){
    int mod = 104857601;
    int r = modsqrt(5, mod);
    print("r = ");
    output(r);
    // calculate the fibonacci number (mod 104857601)
    int n = input();
    int inv2 = modpow(2, mod - 2, mod);
    int a = modpow((1 + r) * inv2 % mod, n, mod);
    int b = modpow((1 - r + mod) * inv2 % mod, n, mod);
    int result = (a - b + mod) * modpow(r, mod - 2, mod) % mod;
    output(result);
    return 0;
}