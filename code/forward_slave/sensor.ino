unsigned int convert_adc(int sensor) {
  int a = 0;
  digitalWrite(AD0, (sensor / 1) % 2);
  digitalWrite(AD1, (sensor / 2) % 2);
  digitalWrite(AD2, (sensor / 4) % 2);
  digitalWrite(AD3, (sensor / 8));
  a = 1023 - analogRead(A22);
  return a ;
}
void refresh()
{
  for (int b = 0; b < 16; b++) {
    SENSOR[b] = convert_adc(b);
    if (SENSOR[b] > 1000) SENSOR[b] = 0;
  }


}
void kaf_setup()
{
  sofo = analogRead(A10);
  sofi = analogRead(A11);
  soro = analogRead(22);
  sori = analogRead(23);
  sobo = analogRead(35);
  sobi = analogRead(36);
  solo = analogRead(33);
  soli = analogRead(34);

  kaf_F [0] =  sofo ;
  kaf_F [1] =  sofi ;

  kaf_R [0] =  soro ;
  kaf_R [1] =  sori ;

  kaf_B [0] =  sobo ;
  kaf_B [1] =  sobi ;

  kaf_L [0] =  solo ;
  kaf_L [1] =  soli ;
}
void set_kaf()
{
  kaf_setup();
  F_noise [0] = kaf_F[0] + 120;
  F_noise [1] = kaf_F[1] + 160 ;
  L_noise [0] = kaf_L[0] + 80;
  L_noise [1] = kaf_L[1] + 50 ;
  R_noise [0] = kaf_R[0] + 50 ;
  R_noise [1] = kaf_R[1] + 90 ;
  B_noise [0] = kaf_B[0] + 60;
  B_noise [1] = kaf_B[1] + 110 ;
}
void set_bits()
{
  kaf_F[0] =  analogRead(A10);
  kaf_F[1] =  analogRead(A11);
  kaf_R[0] = analogRead(22);
  kaf_R[1] = analogRead(23);
  kaf_B[0] = analogRead(35);
  kaf_B[1] = analogRead(36);
  kaf_L[0] =  analogRead(33);
  kaf_L[1] =  analogRead(34);

  /////////////////////////////////////////
  if (R_noise[0] < kaf_R[0])  ro = 1;
  else   ro = 0;

  if (F_noise[0] < kaf_F[0])  fo = 1;
  else   fo = 0;

  if ( L_noise[0] < kaf_L[0])  lo = 1;
  else   lo = 0;

  if ( B_noise[0] < kaf_B[0])  bo = 1;
  else   bo = 0;

  ////////////////out of bound 2
  if ( R_noise[1] < kaf_R[1])  ri = 1;
  else   ri = 0;

  if (F_noise[1] < kaf_F[1])  fi = 1;
  else   fi = 0;

  if ( L_noise[1] < kaf_L[1])  li = 1;
  else  li = 0;

  if ( B_noise[1] < kaf_B[1])  bi = 1;
  else   bi = 0;
}
void biggest(void)
{
  refresh();
  int b , c = 0;
  int w , q = 0;
  for (int i = 0; i < 16; i++)
  {
    if (c < SENSOR[i])
    {
      c = SENSOR[i];
      b = i;
    }
  }
  big_sensor = c;
  big_sensor_num = b;
  for (int z = 16 ; z < 20 ; z++)
  {
    if ( q < SENSOR[z])
    {
      q = SENSOR[z];
      w = z;
    }
  }
  big_distance = q;
  big_distance_num = w;
}
void show_kaf() {
  kaf_setup();
  Serial.print("kaf_FO:");
  Serial.print(sofo);
  Serial.print(" | kaf_FI:");
  Serial.print(sofi);
  Serial.print(" | kaf_LO:");
  Serial.print(solo);
  Serial.print(" | kaf_LI:");
  Serial.print(soli);
  Serial.print(" | kaf_BO:");
  Serial.print(sobo);
  Serial.print(" | kaf_BI:");
  Serial.print(sobi);
  Serial.print(" | kaf_RO:");
  Serial.print(soro);
  Serial.print(" | kaf_RI:");
  Serial.println(sori);
  delay(100);
}
/////////////////////////////////////////////SHOW//////////////////////////////
void show_sensor() {
  refresh();
  biggest();
  for (int f = 0 ; f < 16; f++) {
    Serial.print(" ");
    Serial.print(f);
    Serial.print("|");
    Serial.print(SENSOR[f]);
  }
  Serial.println("  ");
  Serial.print(big_sensor_num);
  Serial.print(" | ");
  Serial.println(big_sensor);
  //  Serial.print(big_distance_num);
  //  Serial.print(" | ");
  //  Serial.print(big_distance);
  delay(100);
}
void show_cmps() {
  read_compass();
  Serial.println(bearing);
  //  Serial.println(" | ");
  // Serial.println(CMPS());
  delay(100);
}
void SHOWKAF(void)
{
  set_bits();
  Serial.println(" ");
  Serial.print(" | FO:");
  Serial.print(fo);
  Serial.print(" | FI:");
  Serial.print(fi);

  Serial.print(" | RO:");
  Serial.print(ro);
  Serial.print(" | RI:");
  Serial.print(ri);

  Serial.print(" | BO:");
  Serial.print(bo);
  Serial.print(" | BI:");
  Serial.print(bi);
  
  Serial.print(" | LO:");
  Serial.print(lo);
  Serial.print(" | LI:");
  Serial.println(li);
  delay(50);

}
