int y[232];
int x[200];
int h[6] = {-18, -44, -160, 160, 44, 18};
int n=6, m=200;

void setup() {
  pinMode(A0, INPUT);
  for(int i=0;i<m;i++){
    x[i]= analogRead(A0);
    delay(100); 
  }
   
  Serial.begin(9600);  //passes the value 9600 to the speed parameter. 
  //This tells the Arduino to get ready to exchange messages with the Serial Monitor at a data rate of 9600 bits per second.
  
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(i>=j){
        y[i] = y[i] + (h[j]*x[i-j])/256;
      }
    }
  }
  for(int i=0;i<m;i++){
    Serial.println(y[i]);
    Serial.print(",");
    Serial.println(x[i]);
    delayMicroseconds(500); //500ms delay
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
