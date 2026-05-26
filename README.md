# LAN Party

## DESCRIERE
* Acest program simulează un turneu LAN la care participă mai multe echipe

### Etapa 1: Filtrarea echipelor

* Programul analizează toate echipele
* Verifică punctajul fiecărui jucător și calculează punctajul fiecărei echipe.
* Apoi elimină echipele cu cele mai mici scoruri până când rămân doar echipele care se încadrează într-o grupă


### Faza 2: Simularea eliminării directe

* Echipele sunt împerecheate și joacă una împotriva celeilalte
* Echipa câștigătoare este cea care are scorul mai mare și trece în runda următoare
* Echipa învinsă este eliminată din turneu
* Se repetă acest proces până când rămâne o singură echipă


### Faza 3: Clasamentul de elită

* Primele opt echipe sunt introduse într-un BST sortat după punctajul lor
* Dacă două echipe au același punctaj, ele sunt sortate după nume
* Programul afișează apoi clasamentul


## UTILIZARE

### COMPILARE
* Faceți acest lucru tastând următoarea comandă în terminal:
`make build`

### RULARE
* Apoi, îl puteți rula tastând următoarea comandă în terminal:
`make runall`


#### DESCRIEREA FIȘIERELOR

* `c.in` indică programului ce parte a turneului trebuie rulată.

* `d.in` conține o listă a echipelor, a jucătorilor acestora și a punctajelor inițiale.

* `r.out` afișează rezultatele.


## ÎMBUNĂTĂȚIRI DE EFECTUAT

* Programul actual funcționează, dar poate fi îmbunătățit în domenii precum: stabilitate, gestionarea resurselor și performanță

### Gestionarea memoriei
* Verificarea alocării: în prezent nu verifică erorile malloc
* Persistența datelor: nu are nicio modalitate de a înregistra progresul în cazul în care procesul este oprit sau întrerupt

### Scalabilitate
* Scalare dinamică: nu utilizează alocarea dinamică, ci doar dimensiuni fixe

### Performanță
* Complexitate: utilizează un arbore BST de bază; ar fi putut utiliza un arbore AVL
