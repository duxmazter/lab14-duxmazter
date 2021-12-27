#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double d[],int N,double sV[]){
    
    double AM, sum = 0;
    for(int i = 0; i < N; i++){
        sum += d[i];
    } AM = sum / N;
    
    double SD; sum = 0;
    for(int i = 0; i < N; i++){
        sum += pow(d[i]-AM,2);
    } SD = sqrt(sum/N);
    
    double GM; sum = 1;
    for(int i = 0; i < N; i++){
        sum *= d[i];
    } GM = pow(sum,(double)1/N);

    double HM; sum = 0;
    for(int i = 0; i < N; i++){
        sum += 1.0/d[i];
    } HM = N / sum;

    double max = d[0] , min = d[0];
    for (int i = 0;i < N; i++){
        if(d[i]>max) max = d[i];
        if(d[i]<min) min = d[i];
    }

    sV[0] = AM;
    sV[1] = SD;
    sV[2] = GM;
    sV[3] = HM;
    sV[4] = max;
    sV[5] = min;
}
