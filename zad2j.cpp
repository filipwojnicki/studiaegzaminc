#include <iostream>
#include <map>
#include <time.h>
#include <random>

using namespace std;

template<typename M>
void print(const M &listaZawodnikow){
  for (auto it:listaZawodnikow){
    cout << it.first << " " << it.second << endl;
  }

  cout << endl;
}

int main(){
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist1_5(1,5);
  uniform_int_distribution<int> dist6_12(6,12);

  map<int, string> listaZawodnikow {
    {1, "Marek"},
    {2, "Tom"},
    {3, "Marcin"},
    {4, "Tadeusz"},
    {5, "Krzysiek"},
    {6, "Wojtek"},
    {7, "Roman"},
    {8, "Sławek"},
    {9, "Filip"},
    {10, "Irek"},
    {11, "Filip"},
    {12, "Irek"}
  };

  print(listaZawodnikow);

  int zmianaZespolPodstawowy = dist1_5(gen);
  int zmianaZespolRezerwowy = dist6_12(gen);
  cout << zmianaZespolPodstawowy << "<->" << zmianaZespolRezerwowy << endl;

  auto zawodnikRezerwowy = listaZawodnikow.extract(zmianaZespolRezerwowy);
  auto zawodnikPodstawowy = listaZawodnikow.extract(zmianaZespolPodstawowy);
  
  zawodnikRezerwowy.key() = zmianaZespolPodstawowy;
  listaZawodnikow.insert(move(zawodnikRezerwowy));

  zawodnikPodstawowy.key() = zmianaZespolRezerwowy;
  listaZawodnikow.insert(move(zawodnikPodstawowy));

  print(listaZawodnikow);

  zmianaZespolPodstawowy = dist1_5(gen);
  zmianaZespolRezerwowy = dist6_12(gen);
  cout << zmianaZespolPodstawowy << zmianaZespolRezerwowy << endl;

  zawodnikRezerwowy = listaZawodnikow.extract(zmianaZespolRezerwowy);
  zawodnikPodstawowy = listaZawodnikow.extract(zmianaZespolPodstawowy);
  
  zawodnikRezerwowy.key() = zmianaZespolPodstawowy;
  listaZawodnikow.insert(move(zawodnikRezerwowy));

  zawodnikPodstawowy.key() = zmianaZespolRezerwowy;
  listaZawodnikow.insert(move(zawodnikPodstawowy));

  print(listaZawodnikow);
}
