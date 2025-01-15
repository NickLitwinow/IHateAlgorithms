#include <iostream>
using namespace std;

int main () {
  int n, step = 5, sum = 0;
  cin>>n;

  while (step > 0) {
    sum += n/step;
    n = n%step;
    step--;
  }
  cout<<sum<<endl;
  return 0;
}