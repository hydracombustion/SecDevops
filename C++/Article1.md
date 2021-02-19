# Bad functions lists and reasons and Safe alternatives

| Bad functions | Reasons | Compliant solutions | Comments
|:----------|:----------:|:------------------| :------------:| 
|<ul><li>gets(str)</li><li>getpw()</li></ul> | `str` buffer size is not checked and it is vulnerable to overflows. | <ul><li>gets_s(str, sizeof(str));</li> <li>fgets</li><li>getpwuid</li><ul> | Prevent overflows by enforcing a maximum size for `str` buffer
  |<ul><li>scanf(str)</li><li>fscanf()</li></ul>| The %s placeholder is used to read a word into a string.It will overflow when a word longer than the buffer size is entered | `char buffer[10]; scanf("%9s", buffer);` | format strings should specify a field width for the "%s" string placeholder
|sprintf()| Library has multiple buffer overflows using sprintf() and strcpy()| |
|strcpy | <ul><li>CVE-2007-1470 CVE-2006-2114</li><li>CVE-2006-0963 </li> <li>CVE-2011-0712 </li> <li>CVE-2008-5005 </li></ul>| strlcpy() | | 
|strcat() | CVE-2009-3849 | |
  
Look : https://rules.sonarsource.com/cpp/type/Vulnerability/RSPEC-1081
* https://owasp.org/www-project-top-ten/2017/A9_2017-Using_Components_with_Known_Vulnerabilities.html
* https://cwe.mitre.org/data/definitions/676
* https://cwe.mitre.org/data/definitions/119
* https://www.sans.org/top25-software-errors/#cat2
