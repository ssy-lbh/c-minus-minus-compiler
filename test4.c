int strcmp(int* a, int* b){
    while((*a & 255) && (*b & 255)){
        if ((*a & 255) != (*b & 255)){
            return 1;
        }
        a++;
        b++;
    }
    return (*a & 255) != (*b & 255);
}

int getline(int* s){
    int c;
    int i = 0;
    while((c = getchar()) != 10){
        *(s + i) = c;
        i++;
    }
    *(s + i) = 0;
    return i;
}

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

    putchar(10);

    int s1[100];
    int s2[100];

    //output(&s1);

    getchar();
    print("input1: ");
    getline(&s1);
    print("input2: ");
    getline(&s2);

    output(s1);
    output(s2);

    if (strcmp(&s1, &s2)){
        println("not equal");
    } else {
        println("equal");
    }

    return 0;
}