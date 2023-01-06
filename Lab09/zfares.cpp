//Got help from Geeks for Geeks
#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int printCutRod(int price[], int n, int s[]){
    while (n > 0){ 
        cout << s[n] << " ";
        n = n - s[n];
    }
  return 0;
}


void extBottomUpCut(int price[], int n)
{
    int r[n + 1];
    int s[n + 1];
    r[0] = 0;
    for (int j = 1; j <= n; j++){
        int q = INT_MIN;
        for (int i = 1; i <= j; i++){
            if (q < (price[i] + r[j - i])){
                q = (price[i] + r[j - i]);
                s[j] = i;
            }
        }
        r[j] = q;
    }
  cout << r[n] << endl;
  printCutRod(price, n, s);
  cout << "-1" << endl;
}
 

int main()
{
    int x;
    cin >> x;
    int price[x];
    price[0] = 0;
    for(int i = 1; i< x + 1; i++)
    {
        cin>>price[i];
    }
    extBottomUpCut(price, x);
 
  return 0;
}