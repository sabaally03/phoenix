void Calibrate() {
  nointerrupt = 100;
  for (int k = 0 ; k < 4 ; k++) {
    Wire.beginTransmission(address);
    digitalWrite(BUZ, HIGH);
    delay(100);
    Wire.write(15);
    Wire.write(0xff);
    Wire.endTransmission();
    digitalWrite(BUZ, LOW);
    delay(3000);
  }
  nointerrupt = 0;
}
void read_compass() {
  byte highByte;
  byte lowByte;
  Wire.beginTransmission(address);
  Wire.write(2);
  Wire.endTransmission();
  Wire.requestFrom(address, 2);
  highByte = Wire.read();
  lowByte = Wire.read();
  bearing = ((highByte << 8) + lowByte) / 10;
  bearing = map(bearing , 0, 360, 0, 1023);
}
signed int CMPS() {
  int a , b ;
  read_compass();
  a = bearing  - nSETUP ;
  if (a > 0) {
    b = a;
  }
  else {
    b = a + 1023;
  }
  if ( b > 512) {
    b = b - 1023;
  }
  else {
    b = b ;
  }
  compass = -b ;
  return compass ;
}

///////////////////////////////spin speed/////////////////////////
signed int spin_speed(int divided_value , int added_value , int zero_degree) {
  int compass_input , compass_output;
  CMPS();
  compass_input = compass ;
  if (compass_input >= zero_degree)
    compass_output = ( compass_input / divided_value ) + added_value;
  else if (compass_input <= (- zero_degree))
    compass_output = ( compass_input / divided_value ) - added_value;
  else compass_output = 0 ;
  return compass_output ;

}
///////////////////////////////////////////////////////////////////////////
void interrupt() {
  if ( nointerrupt == 0) {
    read_compass();
    set_s = spin_speed(1, 60, 10);
    set_m = spin_speed(1, 60, 10);
    reduction = 0.8;
  }}
//    digitalWrite(19, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);               // wait for a second
//  digitalWrite(19, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);
