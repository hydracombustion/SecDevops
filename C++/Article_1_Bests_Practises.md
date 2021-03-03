# How mitigate the use of potentially dangerous Function in C/C++

### Risks of Reimplementation
Functions that are considered dangerous today were created because they provided functionality that programmers found useful. When the behavior of a dangerous function is replicated in proprietary code, the overall security of the program is worse off than if the dangerous function were used directly because it can no longer be identified by name alone.

| Bad functions | Reasons | Compliant solutions | Comments
|:----------|:----------:|:------------------| :------------:| 
|<ul><li>strcpy</li><li>strlcpy</li><li>wcscpy()()</li><li>lstrcpy()</li></ul>|strcpy() copies the contents of one buffer into another until a null byte is encountered in the source buffer. A possible bufferoverflow can be encountered if the size of source buffer is larger than the destination.|<ul><li>strncpy</li><li>strcpy_s(MSDN)</li></ul>| It can be used safely if the code surrounding it correctly ensures that the contents of the source buffer are guaranteed to be no larger than the capacity of the destination buffer.| 
|<ul><li>strcat()</li><li>strlcat()</li></ul>| Look at the appsec-warehouse -> C++ -> bad-use-strcat.md  |<ul><li>strcat_s() -strtok</li><li>strncat</li></ul> | This functions fix the potential buffer overloads.|
|<ul><li>sprintf()</li></ul>|The sprintf() function makes no guarantees regarding the length of the generated string, a sufficiently long string in name could generate a buffer overflow.|<ul><li>sprintf_s()</li><li>snprintf()</li></ul>| The buffer overflow can be prevented by adding a precision to the %s conversion specification. If the precision is specified, no more than that many bytes are written. A best solution is to use the snprintf() function and control the sizeof the source data. |
|<ul><li>gets(str)</li><li>getpw()</li></ul> | `str` buffer size is not checked and it is vulnerable to overflows. | <ul><li>gets_s(str, sizeof(str));</li> <li>fgets</li><li>getpwuid</li><li>getline()</li><ul> | Prevent overflows by enforcing a maximum size for `str` buffer.|
|<ul><li>scanf(str)</li><li>sscanf()</li><li>fscanf()</li><li>wscanf()</li></ul>| The %s placeholder is used to read a word into a string. It will overflow when a word longer than the buffer size is entered | <ul><li>the use of %[sizeof(buffer)-1]s </li><li>sscanf_s()</li></ul> | Example : `char buffer[10]; scanf("%9s", buffer);` If a width specifier is included, such as %9s, scanf() will read up to the specified number of characters into the buffer. Because of the capability to limit the amount of input read, scanf() can potentially be used safely if the format specifier properly bounds the amount of data read. Even when it is used, correct bounds enforcement through format string specifiers is error prone.|
|<ul><li>vsprintf</li></ul>|x| <ul><li>vsnprintf</li></ul> |x|
|<ul><li>makepath</li></ul>|x| <ul><li>_makepath_s (MSDN)</li></ul> |x|
|<ul><li>_splitpath</li></ul>|x| <ul><li>_splitpath_s (MSDN)</li></ul> |x|
|<ul><li>snscanf</li></ul>|x| <ul><li_snscanf_s (MSDN)</li></ul> |x|
|<ul><li>strlen</li></ul>|x| <ul><li>strnlen_s (MSDN)</li></ul> |x|
|<ul><li></li></ul>|x| <ul><li> </li></ul> |x|
|<ul><li>fflush(stdin)</li></ul> |fflush is considered as unsafe because |<ul><li>fflush(stdout)</li></ul>| The stream must be used for output. The standard says: If stream points to an output stream or an update stream in which the most recent operation was not input, the fflush function causes any unwritten data for that stream to be delivered to the host environment to be written to the file; otherwise, the behavior is undefined.
 |<ul><li></li></ul> | |<ul><li></li></ul> | https://levelup.gitconnected.com/introduction-to-secure-coding-in-c-and-c-d8ece627facb|
  
Look : 
* https://wiki.sei.cmu.edu/confluence/display/c/STR31-C.+Guarantee+that+storage+for+strings+has+sufficient+space+for+character+data+and+the+null+terminator
* https://owasp.org/www-project-top-ten/2017/A9_2017-Using_Components_with_Known_Vulnerabilities.html
* https://cwe.mitre.org/data/definitions/676
* https://cwe.mitre.org/data/definitions/119
* https://www.sans.org/top25-software-errors/#cat2
