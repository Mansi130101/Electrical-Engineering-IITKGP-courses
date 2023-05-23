//pooling

void setup() {   
  Serial.begin(9600);  
  DDRB=0xFF;
  DDRD=0xFF;
  DDRC=0x0;
  ADCSRA=0x87;
  const int adc_pin=0;
  ADMUX=bit(REFS0)|(adc_pin&7);
  while(1){
    ADCSRA|=(1<<ADSC);
    while((ADCSRA&(1<<ADIF))==0);
    PORTD=ADCL;
    PORTB=ADCH;
    Serial.println(PORTB);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
