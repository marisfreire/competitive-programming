#include <bits/stdc++.h>
using namespace std;


vector<int> container(1e3);
int target = 0;
auto it = find(container.begin(), container.end(), target);

auto it_lower = lower_bound(container.begin(), container.end(), target);
auto it_lower = upper_bound(container.begin(), container.end(), target);

/*LATEX_DESC_BEGIN 

    STL find() retorna iterador se achou, se não achou retorna container.end()
   
   Complexidade:
   -> Set, map:  O(logN)
   -> List, vector, deques, arrays: O(n)
   -> Unordered maps without collisions: O(1)

    STL lower_bound() e upper_bound() 
    Precisa sortar antes
    Lower retorna primeiro maior ou igual a target
    Upper retorna maior que o target
    Complexidade O(logN)

    
LATEX_DESC_END*/




   
   
