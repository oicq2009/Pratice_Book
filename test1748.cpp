   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
// BF
int n = 0;
for (int i = 0;i <= 10; i++)
    for (int j = 0;j <= 5; j++)
        if (i + 2 * j == 10) { 
            printf("one step："+ i + "two step:"+ j + "\n");
            n++;
        }
    }
}


// DP
int a = 1;
int b = 2;
int temp = 0;

if (n == 1) {
    temp = 1;
    printf("Ways: "+temp);
}
if (n == 2) {
    temp=2;
    printf("Ways: "+temp);
}
if(n >= 3) {
    for (int i = 0;i < n - 2; i++) {
    temp = a + b;
    a = b;
    b = temp;
}




   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
// BF
int n = 0;
for (int i = 0;i <= 10; i++)
    for (int j = 0;j <= 5; j++)
        if (i + 2 * j == 10) { 
            printf("one step："+ i + "two step:"+ j + "\n");
            n++;
        }
    }
}


// DP
int a = 1;
int b = 2;
int temp = 0;

if (n == 1) {
    temp = 1;
    printf("Ways: "+temp);
}
if (n == 2) {
    temp=2;
    printf("Ways: "+temp);
}
if(n >= 3) {
    for (int i = 0;i < n - 2; i++) {
    temp = a + b;
    a = b;
    b = temp;
}




