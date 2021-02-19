# Bad functions lists and reasons and Safe alternatives

| Bad functions | Reasons | Compliant solutions | Comments
|----------|:-------------:|------------:| ------------:| 
| - gets(str)  - getpw() | `str` buffer size is not checked and it is vulnerable to overflows | - gets_s(str, sizeof(str));  - fgets  - getpwuid | Prevent overflows by enforcing a maximum size for `str` buffer
