#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>

volatile int analogVal;
const byte adc_pin = A0;
int n=33;
int x[33]={0};
//filter coefficients
int h[33] ={0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 10, 14, 16, 20, 24, 26, 26, 26, 24, 20, 16, 14, 10, 6, 4, 2, 0, 0, 0, 0, 0, 0, 0};
//current filter output sample value
float yi;
//filtered output sample value
float yv;
//current input sample value
float xv;

void setup(){
  Serial.begin(9600);
  ADCSRA = 1<<ADPS2 | 1<<ADPS1 | 1<<ADPS0;        
  ADCSRA |= 1<<ADEN;                           
  ADMUX |= 1<<ADLAR;                             
  ADMUX |= 1<<REFS0;                            
  ADMUX |= ((adc_pin -14) & 0x07);              
}

void loop(){
  ADCSRA |= 1<<ADSC;
  while((ADCSRA & (1<<ADIF)) == 0);
  analogVal = ADCH;
  for(int i=0;i<n-1;i++){
    x[i] = x[i+1];
  }
  x[n-1] = analogVal;
  
  yi = 0;
  for(int j=0;j<n;j++){                           //convolution
    yi+=(h[j]*x[n-1-j]*1.0)/270;
  }

  yv = 5*((yi*1.0)/255);
  xv = 5*((x[n-1]*1.0)/255);
  Serial.print(xv);
  Serial.print(",");
  Serial.println(yv); 
}
