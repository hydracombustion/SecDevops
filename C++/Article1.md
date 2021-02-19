# Bad functions lists and reasons and Safe alternatives

| Bad functions | Reasons | Compliant solutions | Comments
|:----------|:-------------:|:------------| :------------:| 
|<ul><li>gets(str)</li><li>getpw()</li></ul> | `str` buffer size is not checked and it is vulnerable to overflows | <ul><li>gets_s(str, sizeof(str));</li> <li>fgets</li><li>getpwuid</li><ul> | Prevent overflows by enforcing a maximum size for `str` buffer
