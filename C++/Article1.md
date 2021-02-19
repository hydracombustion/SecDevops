# How mitigate the use of potentially dangerous Function

| Bad functions | Reasons | Compliant solutions | Comments
|:----------|:----------:|:------------------| :------------:| 
|<ul><li>sprintf() and Friends </li></ul>|The sprintf() function makes no guarantees regarding the length of the generated string, a sufficiently long string in name could generate a buffer overflow.|<ul><li>snprintf()</li></ul>| The buffer overflow can be prevented by adding a precision to the %s conversion specification. If the precision is specified, no more than that many bytes are written. A best solution is to use the snprintf() function and control the sizeof the source data. 
|<ul><li>strcpy()</li><li>wcscpy()()</li><li>lstrcpy()</li></ul>| | </li><li>lstrcpy()</li></ul> | | 
|strcat() | CVE-2009-3849 | |
|<ul><li>gets(str)</li><li>getpw()</li></ul> | `str` buffer size is not checked and it is vulnerable to overflows. | <ul><li>gets_s(str, sizeof(str));</li> <li>fgets</li><li>getpwuid</li><li>getline()</li><ul> | Prevent overflows by enforcing a maximum size for `str` buffer
  |<ul><li>scanf(str)</li><li>fscanf()</li><li>wscanf()</li></ul>| The %s placeholder is used to read a word into a string. It will overflow when a word longer than the buffer size is entered | `char buffer[10]; scanf("%9s", buffer);` | If a width specifier is included, such as %255s, scanf() will read up to the specified number of characters into the buffer. Because of the capability to limit the amount of input read, scanf() can potentially be used safely if the format specifier properly bounds the amount of data read. Even when it is used, correct bounds enforcement through format string specifiers is error prone.|<ul><li>sprintf();</li></ul>| Library has multiple buffer overflows using sprintf()| <ul><li>snprintf(dest; sizeof(dest)+1;source);</li></ul>|Use snprintf instead of sprintf. The slight performance overhead can be afforded in a vast majority of projects. Check the buffer size passed to snprintf.
  
Look : 
* https://wiki.sei.cmu.edu/confluence/display/c/STR31-C.+Guarantee+that+storage+for+strings+has+sufficient+space+for+character+data+and+the+null+terminator
* https://owasp.org/www-project-top-ten/2017/A9_2017-Using_Components_with_Known_Vulnerabilities.html
* https://cwe.mitre.org/data/definitions/676
* https://cwe.mitre.org/data/definitions/119
* https://www.sans.org/top25-software-errors/#cat2
