#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool image[][M]){
    for(int i = 0; i < 72 ; i++)cout <<"-"; 
    cout <<endl;
    for(int Row = 0; Row < N ; Row++){
        cout <<"|";
        for(int i = 0; i < M ; i++){
            if(image[Row][i] == 0) cout <<" ";
            else cout <<"*";
        }
        cout <<"|"<<endl;
    }
    for(int i = 0; i < 72 ; i++ )cout <<"-";
    cout <<endl;
}

void updateImage(bool image[][M],int s,int x,int y){
    int i, j;
    for(i = 0; i < N ; i++){
        for(j = 0; j < M ; j++){
            if (sqrt(pow(i-x,2) + pow(j-y,2)) <= s-1){
            image[i][j] = 1;
            }
        }
    }
}
