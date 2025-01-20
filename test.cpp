// Aleks Sumoski
#include <iostream>
using namespace std;

// function decleration
double calculateCost(int kid, int adult, int senior);

int main() {
  int qtyAdult;
  int qtyKid;
  int qtySenior;
  double ticketPrice = 0;

  qtyAdult = 5;
  qtyKid = 2;
  qtySenior = 4;

  ticketPrice = calculateCost(qtyKid, qtyAdult, qtySenior);
  cout<<"The total cost is "<<ticketPrice<<endl;
  return 0;
}

// details of my function
double calculateCost(int kid, int adult, int senior) {
  double price;
  price = 8.5 * kid + 10.2 * adult + 9.8 * senior;
  return price;
}
