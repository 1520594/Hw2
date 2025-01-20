//Aleks Sumoski | Dr. Mitofsky
#include <cmath>
#include <iostream>
using namespace std;

double vRectangle(double l, double w, double h);
double vCylinder(double r, double h);
double vSphere(double r);
double vTetra(double l);
double vCone(double r, double h);

int main() {
  int mode, Loop;
  double largestVolume = 0.0;
  mode = 0;
  Loop = 1;

  while (Loop == 1) {
    cout << "Please choose which type of object you have >> Rectangular "
            "Prism[1], Cylinder[2], Sphere[3], Regular Tetrahedron[4], Right "
            "Circular Cone[5]"
         << endl;
    cout << "> ";
    cin >> mode;

    double V = 0.0;

    switch (mode) {
    case 1: {
      double l, w, h;
      cout << "You chose Rectangular Prism!" << endl;
      cout << "Please enter the length >> ";
      cin >> l;
      cout << "Please enter the width >> ";
      cin >> w;
      cout << "Please enter the height >> ";
      cin >> h;
      V = vRectangle(l, w, h);
      break;
    }
    case 2: {
      double r, h;
      cout << "You chose Cylinder!" << endl;
      cout << "Please enter the radius >> ";
      cin >> r;
      cout << "Please enter the height >> ";
      cin >> h;
      V = vCylinder(r, h);
      cout << "*******************" << endl;
      cout << "Volume = " << V << endl;
      cout << "*******************" << endl;
      break;
    }
    case 3: {
      double r;
      cout << "You chose Sphere!" << endl;
      cout << "Please enter the radius >> ";
      cin >> r;
      V = vSphere(r);
      cout << "*******************" << endl;
      cout << "Volume = " << V << endl;
      cout << "*******************" << endl;
      break;
    }
    case 4: {
      double l;
      cout << "You chose Regular Tetrahedron!" << endl;
      cout << "Please enter the length >> ";
      cin >> l;
      V = vTetra(l);
      cout << "*******************" << endl;
      cout << "Volume = " << V << endl;
      cout << "*******************" << endl;
      break;
    }
    case 5: {
      double r, h;
      cout << "You chose Right Circular Cone!" << endl;
      cout << "Please enter the radius >> ";
      cin >> r;
      cout << "Please enter the height >> ";
      cin >> h;
      V = vCone(r, h);
      cout << "*******************" << endl;
      cout << "Volume = " << V << endl;
      cout << "*******************" << endl;
      break;
    }
    default: {
      cout << "Invalid mode" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // line 91 and 92 are to stop an infinite loop edgecase if you input a non numeric character that I couldn't solve by my self, so I got a friend to help and we ended up using chatGPT to help debug this after trying ourseves.
      continue;
    }
    }

    cout << "*******************" << endl; // didnt specify it had to match length of string below
    cout << "Volume = " << V << endl;
    cout << "*******************" << endl;
      
    if (V > largestVolume) {
        largestVolume = V;
    }
    
    cout << "Would you like to find the volume of another solid?" << endl;
    cout << "Yes[1] / No[0]" << endl;
    cin >> Loop;
  } // loop ends

  cout << "The largest solid had a volume of" << endl;
  cout << "*******************" << endl;
  cout << "Volume = " << largestVolume << endl;
  cout << "*******************" << endl;

  return 0;
}

double vRectangle(double l, double w, double h) { return l * w * h; }

double vCylinder(double r, double h) { return M_PI * pow(r, 2) * h; }

double vSphere(double r) { return float(4.0 / 3.0) * M_PI * pow(r, 3); }

double vTetra(double l) { return (1.0 / (6 * sqrt(2))) * pow(l, 3); }

double vCone(double r, double h) { return float(M_PI / 3) * pow(r, 2) * h; }
