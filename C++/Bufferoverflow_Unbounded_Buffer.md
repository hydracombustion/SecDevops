# Standard C++

## BufferOverflow Unbounded Buffer - FGETS TEST

```
#include <iostream>
#include <cstring>

using namespace std;

typedef struct {
	char Text[1024];
	int count=0; 
} sTEXT1024;

static int Function_to_Test( FILE *inFile){
	sTEXT1024 inLine, inBufLine, cmdLine;
	int count=0;
	while(fgets(inLine.Text, 1024+1,inFile) != NULL){
		*(inBufLine.Text) = '\0';
		strcpy(inBufLine.Text, inLine.Text);
		count+=1;
	}
	return count;
}

int main(int argc, char *argv[]){
	FILE *inFile = NULL;
	inFile = fopen(argv[1],"r");
	sTEXT1024 cmdLine;
	//inFile = fopen(argv[1],"rw");
	//cin >> cmdLine.Text;
	//fputs(cmdLine.Text,inFile);
	cout << Function_to_Test(inFile) << endl;
	return 0;
}
```

Execute the program with this lines:
```
python -c "print 'A'*1035" > exploit.txt
g++ main.cpp -o TEST
./TEST exploit.txt
```
