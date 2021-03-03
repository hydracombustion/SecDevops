# Buffer overflow Hub

Different types of Buffer 
Listes des buffers
Expliquer les différences entre les buffer avec phrase courte. 
liens vers les articles sur Wiki + liens vers billet d'humeur.


http://capec.mitre.org/data/definitions/10.html
https://cwe.mitre.org/data/definitions/1218.html

## Buffer Overflow Unbounded format

https://cwe.mitre.org/data/definitions/119.html

## Buffer Overflow Unbounded String
Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')

## Off-by-one Overflow

```
char npath[MAXPATHLEN];
int i;
for (i = 0; *name != '\0' && i < sizeof(npath) - 1; i++, name++) {
  npath[i] = *name;
}
```
La boucle for contruit correctement l'itération en faisant varier i de 0 à MAXPATHLEN-1
ainsi il s'agit bien de npath[MAXPATHLEN-1] qui est mis à '\0' après la boucle.
Toutefois, si la condition du if à l'intérieur est rencontrée la variable i est incrémentée
et npath[MAXPATHLEN] cette fois, est mis à '\0', soit 1 byte en dehors du buffer. 
Des overflows peuvent aussi apparaître dans des boucles for ou while s’il y a des erreurs
avec les indices ou dans la condtion de la boucle par exemple. Ces overflows peuvent
être très difficiles à détécter.
