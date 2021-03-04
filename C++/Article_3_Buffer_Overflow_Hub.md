# Buffer overflow Hub
This article will help you to understand what is the difference between each types of buffer Overflow that you can find in your reports. 

**Overview**
> *A buffer overflow condition exists when a program attempts to put more data in a buffer than it can hold or when a program attempts to put data in a memory area past a buffer. Writing outside the bounds of a block of allocated memory can corrupt data, crash the program, or cause the execution of malicious code.*

*For more infos about unsafe method, look at this article:* 
* [Dangerous functions](Remediations and Best Practices/C C++/Article_1_Dangerous_Functions.md)

## Buffer Overflow Cin
**The size of the buffer used by main in cin is not properly verified before writing data to the buffer.** This can enable a buffer overflow attack, using the source buffer that main passes to cin to overwrite the target buffer.

Example of No-compliant code: 
```
    char action[255];
    cin >> action;
```
This vulnerability become when you use the "cin" function. In this example, the attacker can write more than 255 characters and generate a buffer overflow because the input is not verify and can be write into a smaller buffer without size verification.The attacker's data overwrites whatever is next on the stack, allowing the attacker to control program structures.

## Buffer Overflow Long String
Example of No-compliant code: 
```
    char *buffer;
    [...]
    char msg[255]="";
    sprintf(msg,"Error %s",buffer);
```
The sprintf() function writes the string pointed to by format to buffer. The string format may contain format specifiers starting with % which are replaced by the values of variables that are passed to the sprintf() function as additional arguments (here it's the buffer variable). **The string format with specific arguments can be more larger than the buffer destination** (here msg variable) and provocate a buffer overflow. To avoid it, it is important to check the size of the additionnal arguments or typically a variable. 

Example of Compliant code: 
```
    snprintf(msg,sizeof(msg)-1,"Error %s",buffer);
```

## Buffer Overflow Unbounded Buffer
It is when a buffer is **written by a potentially unsafe method without any checks** to ensure that the data being written falls within its bounds, it may cause an overflow.

*For more infos about this vulnerability, look at this article:* [Buffer Overflow Unbounded Buffer](Buffer_Overflow_Unbounded_Buffer.md)

## Buffer Overflow Unbounded Format
Sometime, you need to put some data to a buffer **using the format capability of string** functions. If you don't take care of the lenght of yours buffers and variables, the destination buffer could overflow and generate various problems.

*For more infos about this vulnerability, look at this article:* [Buffer Overflow Unbounded Format ](bufferformatoverflow.md)

## Buffer Overflow Wrong Buffer Size
The software uses a method to read or write a buffer, but it uses **an incorrect length value** that causes it to access memory that is outside of the bounds of the buffer.
**An error in calculating the allocated destination buffer** may allow a variable/argument to exceed the size of this buffer, resulting in an overflow.

For more infos about this vulnerability, look at this article:
* [Buffer Overflow Wrong Buffer Size ](Buffer_Overflow_Wrong_Buffer_Size.md)


## Buffer Overflow Address Of Local Var Returned 

## Others...
### Heuristic 2nd Order Buffer Overflow malloc
### Heuristic 2nd Order Buffer Overflow read

## Links
* http://capec.mitre.org/data/definitions/10.html
* https://cwe.mitre.org/data/definitions/1218.html

## Off-by-one Overflow
* [Off by One Error](offbyone.md)

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
