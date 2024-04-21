## Descrierea rezolvarii problemelor

# Servere
    Deoarece, in cazul in care un server este subalimentat sau supraalimentat,
puterea acestuia de calcul scade cu o unitate, inseamna ca puterea lui de calcul
este de fapt definita de o functie precum: putere_de_calcul - abs(x - limita_de_
alimentare), unde x reprezinta nivelul de alimentare pe care il primeste server-
ul, astfel abs(x - limita_de_alimentare) va determina numarul de unitati care
sunt "mismatched". Prin trasarea graficelor functiilor fiecarui server, putem
observa ca cea mai buna putere de alimentare pe care o putem alege este chiar
coordonata intersectiei dintre cea mai la dreapta panta ascendenta (panta 1) si
cea mai de la stanga panta descendenta (panta -1). Dupa obtinerea acestei valori
a puterii de alimentare, va urma sa iteram prin toate serverele cu scopul de a
obtine cea mai mica putere de calcul din sistem, pentru ca aceasta va fi puterea
de calcul a tot sistemului. Complexitatea algoritmului meu este de O(N), unde N
este numarul de servere.

# Colorare