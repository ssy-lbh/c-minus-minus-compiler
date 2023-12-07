int main(){
    int a[4];
    int i = 0;

    while(i < 4){
        a[i] = input();
        i = i + 1;
    }

    i = 0;
    while(i < 4){
        output(a[i]);
        i = i + 1;
    }

    return 0;
}