//f1=50, f2=1800
int x[200] = {-110, -164, -128, 0, 182, 254, 254, 254, 254, 254, 102, 0, -16, 56, 182, 254, 254, 254, 190, 0, -190, -256, -256, -256, -182, -56, 16, 0, -102, -256, -256, -256, -256, -256, -182, 0, 128, 164, 110, 0, -110, -164, -128, 0, 182, 254, 254, 254, 254, 254, 102, 0, -16, 56, 182, 254, 254, 254, 190, 0, -190, -256, -256, -256, -182, -56, 16, 0, -102, -256, -256, -256, -256, -256, -182, 0, 128, 164, 110, 0, -110, -164, -128, 0, 182, 254, 254, 254, 254, 254, 102, 0, -16, 56, 182, 254, 254, 254, 190, 0, -190, -256, -256, -256, -182, -56, 16, 0, -102, -256, -256, -256, -256, -256, -182, 0, 128, 164, 110, 0, -110, -164, -128, 0, 182, 254, 254, 254, 254, 254, 102, 0, -16, 56, 182, 254, 254, 254, 190, 0, -190, -256, -256, -256, -182, -56, 16, 0, -102, -256, -256, -256, -256, -256, -182, 0, 128, 164, 110, 0, -110, -164, -128, 0, 182, 254, 254, 254, 254, 254, 102, 0, -16, 56, 182, 254, 254, 254, 190, 0, -190, -256, -256, -256, -182, -56, 16, 0, -102, -256, -256, -256, -256, -256, -182, 0, 128, 164, 110, 0};

int y[206] = {0};
int h[6] = {6, 36, 86, 86, 36, 6};
int n=6, m=200;
void setup() {
  // put your setup code here, to run once:
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