#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

int FromDecToFact(int *dec);
int FromFactToDec(int *fact);
int factorial(int *f);
int NumberPerm(char *alph, int *n);
int FromAnyToDec(int *f, int *f1);
int PermNumber(char *alph, int *n, int *number, int *word);
int FromDecToAny(int *g, int *cc);
int NextPerm(int *perm1, int *n);


int main(){
    setlocale(LC_ALL, "Rus");
    //1
    printf("�1.������� ����� ��  ���������� � ������������� ��. \n");
    int dec;
    printf("����� � ���������� ������� ���������: ");
    scanf("%d", &dec);
    printf("����� � ������������� ������� ���������: %d\n\n", FromDecToFact(&dec));

    //2
    printf("�2.������� ����� �� ������������� � ���������� ��. \n");
    int fact;
    printf("����� � ������������� ������� ���������: ");
    scanf("%d", &fact);

    printf("����� � ���������� ������� ���������: %d\n\n", FromFactToDec(&fact));


    //4
    printf("�4.��������� ������ �� ������������ � ��������. \n");
    int n;
    char *alph;
    size_t i;
    printf("������� �������� ��������: ");
    scanf("%d", &n);
    alph=(char*)malloc(n*sizeof(char));
    printf("������� �������: \n");
    for (i=0; i<n; i++){
        scanf("%s", &alph[i]); }
    printf("�����: %d \n\n", NumberPerm(&*alph, &n));
    free(alph);

    //5
    printf("�5.��������� ������������ �� ������ � ��������. \n");
    int number, word;
    printf("������� �������� ��������: ");
    scanf("%d", &n);
    printf("������� �������: \n");
    alph=(char*)malloc(n*sizeof(char));
    for (i=0; i<n; i++){
        scanf("%s", &alph[i]); }
    printf("������� ����������� ����� ����� � ������������� ������: ");
    scanf("%d", &word);
    printf("������� ����� ����� � ������: ");
    scanf("%d", &number);
    PermNumber(&*alph, &n, &number, &word);
    free(alph);

return 0;
}
//1
int FromDecToFact(int *dec) {
    int res=0, k, d=1;
    size_t i;
    for (i=2; i<=10; i++) {
            if (i>2) {d=d*10;}
            k=(*dec)%i;
            *dec=(*dec)/i;
            if (k>0) { res=res+k*d; } }
return res;
}

//2
int FromFactToDec(int *fact) {
    int res=0, k=0;
    while ((*fact)!=0){
        k+=1;
        res+=((*fact)%10)*factorial(&k);
        *fact=(*fact)/10;
    }
return res;
}
int factorial(int *f) {
    int num=1;
    size_t i;
    for (i=2; i<=*f; i++) {
        num*=i;
    }
return num;
}



//4
int NumberPerm(char *alph, int *n) {
    int res, np, k=1, r=0;
    char *perm;
    size_t i, j;
    printf("������� ����� �����: ");
    scanf("%d", &np);
    perm=(char*)malloc(np*sizeof(char));
    for (i=0; i<np-1; i++) {k*=10;}
    printf("������� �����: \n");
    for (i=0; i<np; i++){
        scanf("%s", &perm[i]);
        for (j=0; j<*n; j++){
            if (perm[i]==alph[j]) {
                r+=j*k;}}
                k/=10; }
    res=FromAnyToDec(&r, *&n);
return res+1;
}

int FromAnyToDec(int *f, int *cc) {
    int res=0, k=0;
    while ((*f)!=0){
        res+=((*f)%10)*pow(*cc,k);
        *f=(*f)/10;
        k+=1;
    }
return res;
}

//5
int PermNumber(char *alph, int *n, int *number, int *word){
    int num, y;
    char *perm;
    size_t i, j;
    perm=(char*)malloc((*n)*sizeof(char));
    y=*number-1;
    num=FromDecToAny(&y, *&n);
    for (i=0; i<*word; i++){
        if (num!=0) {
                for (j=0; j<*n; j++) {
                    if ((num%10)==j)  {
                    perm[*word-i-1]=alph[j]; } } }
        num/=10;
    }
    printf("�����: ");
    for (i=0; i<*word; i++){
        printf("%c", perm[i]);
    }
free(perm);
return *perm;}

int FromDecToAny(int *g, int *c) {
    int res=0, d=1;
    while ((*g)!=0) {
        res+=d*((*g)%(*c));
        (*g)=(*g)/(*c);
        d*=10; }
return res;

}

