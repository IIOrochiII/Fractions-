#include <cmath>
#include <iostream>

/*Opis: Program wykonujący podstawowe operacje na 2 ułamkach 
 *Author: Daniel Postołowicz
 *Date:28.02.2024
 */

int nwd(int a, int b) {
  int temp;
  while (b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

typedef struct ulamek {
  int mianownik;
  int licznik;
  void skroc() {
    int d = nwd(licznik, mianownik);
    licznik /= d;
    mianownik /= d;
  }
  void dodawanie() {}
} ulamek;

ulamek odejmij(ulamek u1, ulamek u2) {
  ulamek temp;
  temp.mianownik = u1.mianownik * u2.mianownik;
  temp.licznik = u1.licznik * u2.mianownik - u2.licznik * u1.mianownik;
  return temp;
}

ulamek dodawanie(ulamek u1, ulamek u2) {
  ulamek temp;
  temp.mianownik = u1.mianownik * u2.mianownik;
  temp.licznik = u1.licznik * u2.mianownik + u2.licznik * u1.mianownik;
  return temp;
}

ulamek pomnoz(ulamek u1, ulamek u2) {
  ulamek temp;
  temp.licznik = u1.licznik * u2.licznik;
  temp.mianownik = u1.mianownik * u2.mianownik;
  return temp;
};

ulamek podziel(ulamek u1, ulamek u2) {
  if (u2.mianownik == 0) {
    exit(1);
  }
  ulamek temp;
  temp.licznik = u1.licznik * u2.mianownik;
  temp.mianownik = u1.mianownik * u2.licznik;
  return temp;
}

void wypisz(ulamek u) {
  int cz_calkowita;
  int ile_zostanie_licznik;
  bool flag=0;
  if (u.licznik >= u.mianownik) {
    flag = 1;
    if (u.licznik % u.mianownik == 0) {
      std::cout << "Pozostala tylko liczba calkowita wynoszaca: " << u.licznik / u.mianownik;
      return;
    } else {
      ile_zostanie_licznik = u.licznik % u.mianownik;
      cz_calkowita = u.licznik / u.mianownik;
    }
  }
  if (flag) {
    std::cout << "Twoj ulamek:\t" << cz_calkowita << " " << ile_zostanie_licznik << "/" << u.mianownik;
  }
  else{
    std::cout << "Twoj ulamek:\t" << u.licznik << "/" << u.mianownik;
  }
}

int main() {
  ulamek u1, u2;
  ulamek temp;
  int opcja;
  std::cout << "Prosze o podanie 2 ulamkow\n";
  std::cin >> u1.licznik >> u1.mianownik;
  std::cin >> u2.licznik >> u2.mianownik;
  u1.skroc();
  u2.skroc();
  std::cout
      << "Witaj, jestem programem obslugujacym podstawowe operacje na ulamkach\
  co dzisiaj chcialbys zrobic: \n1)Dodawania\n2)Odejmowanie\n3)Mnozenie\n4)Dzielenie\nWybierz opcje:\t";
  std::cin >> opcja;
  switch (opcja) {
  case 1:
    temp = dodawanie(u1, u2);
    break;
  case 2:
    temp = odejmij(u1, u2);
    break;
  case 3:
    temp = pomnoz(u1, u2);
    break;
  case 4:
    temp = podziel(u1, u2);
    break;
  default:
    std::cout << "Nie znam takiej opcji";
  }
  temp.skroc();
  wypisz(temp);
  return 0;
};
