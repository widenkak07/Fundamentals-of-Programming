# Zadanie B1: Sito Eratostenesa

Rozwiązanie algorytmiczne zadania polegającego na efektywnym zliczaniu liczb pierwszych w zadanych przedziałach oraz wyznaczaniu najmniejszych dzielników pierwszych.

## Opis problemu

Zadanie wymaga przetworzenia dużej liczby zapytań ($1 \le z \le 10^7$) dotyczących przedziałów $[a, b]$ (gdzie $1 \le a \le b \le 10^7$). Dla każdego zapytania program musi zwrócić:
1. Liczbę liczb pierwszych znajdujących się w przedziale $[a, b]$ (włącznie z granicami).
2. Najmniejszy dzielnik pierwszy liczby $a$ (lub samą liczbę $a$, jeśli jest pierwsza bądź wynosi $1$).
3. Najmniejszy dzielnik pierwszy liczby $b$ (lub samą liczbę $b$, jeśli jest pierwsza bądź wynosi $1$).

### Ograniczenia techniczne:
- **Dostępna pamięć:** $128\text{ MB}$
- **Język programowania:** C
- **Maksymalna wartość liczb:** $10^7$

## Podejście algorytmiczne

Ze względu na restrykcyjne limity czasowe przy $10^7$ zapytaniach, zastosowano optymalizację opartą na dwóch technikach:
- **Tablica SPF (Smallest Prime Factor):** Zmodyfikowane Sito Eratostenesa, które dla każdej liczby zapisuje jej najmniejszy dzielnik pierwszy.
- **Sumy prefixowe:** Tablica pomocnicza przechowująca kumulatywną liczbę liczb pierwszych, co pozwala na odpowiedź na każde zapytanie o przedział w czasie stałym $\mathcal{O}(1)$.
- **Złożoność pamięciowa:** Dwie tablice wielkości $10^7$ typu `int` mieszczą się w około $80\text{ MB}$, co bezpiecznie mieści się w limicie $128\text{ MB}$.

## Kompilacja i uruchomienie

Aby skompletować i uruchomić program na systemie Linux z najwyższą optymalizacją kompilatora, użyj polecenia:

```bash
gcc -O3 rozwiazanie.c -o rozwiazanie
./rozwiazanie
```

## Przykład

### Wejście:
```text
8
1 10
1 100
505 999
2 19
25 28
3 35
71 121
221 323
```

### Wyjście:
```text
4 1 2
25 1 2
72 5 3
8 2 19
0 5 2
10 3 5
11 71 11
19 13 17
```