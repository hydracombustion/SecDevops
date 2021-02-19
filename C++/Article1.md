# Bad functions lists and reasons and Safe alternatives

| Bad functions | Reasons | Compliant solutions | Comments
|----------|:-------------:|------------:| ------------:| 
| - gets(str) and - getpw() | `str` buffer size is not checked and it is vulnerable to overflows | - gets_s(str, sizeof(str)); or - fgets or - getpwuid | Prevent overflows by enforcing a maximum size for `str` buffer
