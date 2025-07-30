#include <reg52.h>

void send(unsigned char *s);
void delay();

void main(){
  SCON=0x50;
	TMOD=0x20;
	TH1=0xfd;
	TR1=1;
	send("hello ...");
  delay();
	
}

void send(unsigned char *s){
  while(*s){
			SBUF=*s++;
		 
		  while(TI==0);
		   TI=0;

	}
}

void delay(){
	int i;
  for(i=0;i<500000;i++){
	for(i=0;i<500000;i++);
	}
} 