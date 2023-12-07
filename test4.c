int main(){
    int a[4];
    int i = 0;

    while(i < 4){
        print("input: ");
        a[i] = input();
        i++;
    }

    i = 0;
    while(i < 4){
        print("output: ");
        output(a[i]);
        i++;
    }

    putchar('\n');

    return 0;
}