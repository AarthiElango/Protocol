#include <reg52.h>
#define lcd P2
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
sbit led=P0^0;

void delay();
void lcd_cmd(int x);
void lcd_data(unsigned char c);
void lcd_init();
void send(unsigned char *s);

void lcd_init(){
  lcd_cmd(0x38);
	delay() ;
	lcd_cmd(0x01);
	delay();
	lcd_cmd(0x80);
	delay();
	lcd_cmd(0x0c);
	delay();
}
void lcd_cmd(int x){
  en=1;
	rs=0;
	rw=0;
	lcd=x;
	delay();
	en=0;
}

void lcd_data(unsigned char c){
  en=1;
	rs=1;
	rw=0;
	lcd=c;
	delay();
	en=0;
}

void send(unsigned char *s){

  while(*s){
	
      	lcd_data(*s);
		while(TI==0);
		TI=0;
		SBUF=*s++;
	}
	}
		
  
	

void delay(){
	 int i,j;
  for(i=0;i<500;i++){
	 for(j=0;j<500;j++);
	}
 }

 int main()
 {
	unsigned char ch;
	TMOD=0x20;
	SCON=0x50;
	TH1=0xfd;
  TR1=1;
  lcd_init();
	lcd_cmd(0x80);
	 
   send("helloo\r\n");
	 
	while(1){ 
	while(RI==0);
	 ch=SBUF;
  RI=0;
	
	lcd_data(ch);
	
  //transmit received data 
	SBUF=ch ;  
	while(TI==0);
  TI=0;

}
  return 0;
 }
 
