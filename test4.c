int strcmp(int* a, int* b){
    while((*a & 0xFF) && (*b & 0xFF)){
        if ((*a & 0xFF) != (*b & 0xFF)){
            return 1;
        }
        a++;
        b++;
    }
    return (*a & 0xFF) != (*b & 0xFF);
}

int getline(int* s){
    int c;
    int i = 0;
    while((c = getchar()) != '\n'){
        *(s + i) = c;
        i++;
    }
    *(s + i) = '\0';
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

    putchar('\n');

    int s1[0x40];
    int s2[0x40];

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