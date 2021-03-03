# How mitigate the use of potentially dangerous Function in C/C++

### Risks of Reimplementation
Functions that are considered dangerous today were created because they provided functionality that programmers found useful. When the behavior of a dangerous function is replicated in proprietary code, the overall security of the program is worse off than if the dangerous function were used directly because it can no longer be identified by name alone.

| Bad functions | Reasons | Compliant solutions | Comments
|:----------|:----------:|:------------------| :------------:| 
|<ul><li>strcpy</li><li>strlcpy</li></ul>|strcpy() copies the contents of one buffer into another until a null byte is encountered in the source buffer. A possible bufferoverflow can be encountered if the size of source buffer is larger than the destination.|<ul><li>strncpy</li><li>strcpy_s(MSDN)</li></ul>| It can be used safely if the code surrounding it correctly ensures that the contents of the source buffer are guaranteed to be no larger than the capacity of the destination buffer.| 
