CODE-1: C PROGRAM
 #include<stdio.h>
#include<sys/types.h>
 #include<unistd.h>
 int main()	
 { 
printf("\n\n this is Yash rathore\n"); 
int a=0; 
int b=0; 
pid_t pid;
 do {
           printf(" enter a number greater than 0 \n"); 
           scanf("%d", &b); 
}while (b <= 0);
 pid = fork();
 if (pid == 0) { 
printf("Child is present or performing\n");
 printf("%d\n",b); 
while (b!=1) { 
if (b%2 == 0) { 
b = b/2; 
} 
else if (b%2 == 1)
 { 

b = 3 * (b) + 1; 

} 

printf("%d\n",b); 

} 

printf("Child process is done.\n");

 } 
else { 
printf("Parents is waiting on child process...\n");
 wait(); 
printf("Parent process is complete.\n");
 }
 return 0;}





CODE 2: C PROGRAM 
#include<stdio.h> 

#include<string.h> 

#include<stdlib.h> 

#include<unistd.h>
 
#include<fcntl.h>
 
#include<errno.h> 

int main(int abc, char *arg[]) 

{ 

int ab[2]; 

int bytelen; 

char buff[100]; 

char childbuff[100];
 
char *src=arg[1]; 

char *dest=arg[2]; 

if(pipe(ab)<0) 
{ 

printf("error !!! %s\n",strerror(errno)); 

exit(1); 

} 

switch(fork()) 

{ 

case -1: 

printf("error forking child process %s\n",strerror(errno)); 

exit(1); 

case 0: 

close(ab[1]); 

ssize_t child_bytes= read(ab[0],childbuff,sizeof(childbuff)); 

close(ab[0]); 

int target=open("dest",O_CREAT|O_WRONLY); 

write(target,childbuff,child_bytes); 

default: 

close(ab[0]); 

int fileindes=open(src,O_RDONLY); 

ssize_t num_bytes=read(fileindes,buffer,sizeof(buff)); 

write(ab[1],buff,num_bytes); 

close(ab[1]); 

} 

return 0; 

}

