# Buffer overflow Hub
This article will help you to understand what is the difference between each types of buffer Overflow that you can find in your reports. 

### Buffer Overflow Cin

Example of Non-compliant code: 
```
    char action[255];
    cin >> action;
```
This vulnerability become when you use the "cin" function. In this example, the attacker can write more than 255 characters and generate a buffer overflow because the input is not verify and can be write into a smaller buffer without size verification.The attacker's data overwrites whatever is next on the stack, allowing the attacker to control program structures.

## Buffer Overflow Long String
## Buffer Overflow Unbounded Buffer
Buffer Copy without Checking Size of Input ('Classic Buffer Overflow')
## Buffer Overflow Unbounded Format
## Buffer Overflow Wrong Buffer Size
## Buffer Overflow Address Of Local Var Returned 

## Others...
### Heuristic 2nd Order Buffer Overflow malloc
### Heuristic 2nd Order Buffer Overflow read

## Links
* http://capec.mitre.org/data/definitions/10.html
* https://cwe.mitre.org/data/definitions/1218.html

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
