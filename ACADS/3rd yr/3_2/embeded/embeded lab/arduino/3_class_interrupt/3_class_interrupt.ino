//interrupt

void setup() {   
  Serial.begin(9600);  
  DDRB=0xff;
  DDRD=0xff;
  DDRC=0;
  sei();
  ADCSRA=0x8F;
  const int adc_pin=0;
  ADMUX=bit(REFS0)|(adc_pin&7);
  ADCSRA|=(1<<ADSC);
  while(1){
    Serial.println(PORTB);
  }
}

ISR(ADC_vect){
  PORTD=ADCL;
  PORTB=ADCH;
  ADCSRA|=(1<<ADSC);
}

void loop() {
  // put your main code here, to run repeatedly:
}
