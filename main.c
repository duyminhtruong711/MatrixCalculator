#include <stdio.h>

int numerator[10][10];
int denominator[10][10];

int main() {
    int row, col;
    do {
    printf("Please enter the size of your matrix: \n");
    scanf("%dx%d", &row, &col);
    if(row>=1 && row<=10 && col>=1 && col<=10) break;
    printf("The size must be equal or smaller than 10x10!\n");
    } while(1);
    printf("Please enter your matrix: \n");
    enterMatrix(row, col);
    irMatrix(row, col);
    printf("Your matrix is: \n");
    printMatrix(row, col);
}

void enterMatrix(int row, int col) { //done
    for(int i=1; i<=row; ++i) {
        printf("Row %d: ", i);
        for(int j=1; j<=col; ++j) {
            enterElement(i, j);
        }
    }
}

void enterElement(int row, int col) { //done
    scanf("%d", &numerator[row][col]);
    char temp;
    scanf("%c", &temp);
    if(temp=='/') {
        scanf("%d", &denominator[row][col]);
    }
    else denominator[row][col]=1;
}

void printMatrix(int row, int col) { //done
    for(int i=1; i<=row; ++i) {
        for(int j=1; j<=col; ++j) {
            printElement(i, j);
            if(j==col) printf("\n");
        }
    }
}

void printElement(int row, int col) { //done
    if(denominator[row][col]==1) {
        printf("%4d", numerator[row][col]);
        printf("    ");
    }
    else {
        printf("%3d", numerator[row][col]);
        printf("/%d", denominator[row][col]);
        int temp=denominator[row][col], count=0;
        do {
            temp/=10;
            ++count;
        } while(temp!=0);
        for(int i=0; i<(4-count); ++i) {
            printf(" ");
        }
    }
}

int compareElement(int row, int col, int number) { //done
    if(denominator[row][col]==1) {
        if(numerator[row][col]==number) return 1;
        else return 0;
    }
    else if(numerator[row][col]==number && number==0) return 1;
    else return 0;
}

void mulRow(int row, int col, int mul) { //done
    for(int i=1; i<=col; ++i) {
        numerator[row][i]*=mul;
    }
}

void divRow(int row, int col, int div) { //done
    for(int i=1; i<=col; ++i) {
        denominator[row][i]*=div;
    }
}

void addRow(int row, int col) { //add to cloneRow; done
    for(int i=1; i<=col; ++i) {
        numerator[row][i]=numerator[row][i]*denominator[0][i]+numerator[0][i]*denominator[row][i];
        denominator[row][i]*=denominator[0][i];
    }
}

void cloneRow(int row, int col) { //is row 0; done
    for(int i=1; i<=col; ++i) {
        numerator[0][i]=numerator[row][i];
        denominator[0][i]=denominator[row][i];
    }
}

void irMatrix(int row, int col) { //done
    int temp1;
    int temp2;
    for(int i=1; i<=row; ++i) { 
        for(int j=1; j<=col; ++j) {
            if(numerator[i][j]!=0){
                temp1=numerator[i][j];
                temp2=denominator[i][j];
                temp1=(temp1>0)?temp1:-temp1;
                temp2=(temp2>0)?temp2:-temp2;
                while(temp1!=temp2) {
                    if(temp1>temp2) temp1-=temp2;
                    else temp2-=temp1;
                }
                numerator[i][j]/=temp1;
                denominator[i][j]/=temp1;
            }
        }
    }
}