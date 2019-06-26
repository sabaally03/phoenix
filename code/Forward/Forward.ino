///////////////////////start//////////////////////////////////////////
#include <Wire.h>
#include <EEPROM.h>
IntervalTimer myTimer;
#define address 0x60
//-------------------------- VAR -------------------------//
unsigned int n_cmp, big_sensor, big_sensor_num = 17, r_stop, nointerrupt;
float reduction ;
float z ;
////EEPROM write
int kaj , nahang , nSETUP, high, low, counter , DISTANCE = 710 , Arezoo = 500 ;
signed int set_m = 0, set_s = 0, Compass;
char Movement;
int SRFReader[6] , compass;
char srfl[3];
char srfb[3];
char srfr[3], Mode;
unsigned char O_Mode, Out, Out_old;
boolean stop_out, other_location, location;
char bluetooth_input[9], other_dn, dn;
int other_big_sensor , other_sensor_value;
float battery_voltage, V;
int Sensor, eeprom_cmp;
unsigned int distance = 800 , noise = 50, intrt = 0;
int kaf_F[2] , kaf_L[2] , kaf_B[2] , kaf_R[2] , DSensor[20], FaseleAzTop ;
int noise_fo , noise_fi , noise_ri , noise_ro , noise_bi , noise_bo , noise_li , noise_lo ;
bool  fo , ro , bo , lo , fi , ri , bi , li ;
int F_noise[2], R_noise[2], L_noise[2], B_noise[2], SENSOR[21], bearing , big_distance_num , big_distance ;
int sofo , sofi , sobo ,  sobi , soro , sori , solo , soli;
//bool fa, fb, la, ra , ba;
char cmp[3], bigsensor[3], bigsensornum[2];
const int led = 13;
int a[16];

//eeprom
//**************************PINS*************************//
int RX = 0, TX = 1, SET = 2,/* RX1 = 7, TX1 = 8*/ PWM_MRF = 6, PWM_MLF = 9, PWM_MRB = 5, PWM_MLB = 10, SHOOT = 29;
int SDAl = 4, SCLl = 3, SDA_TEENSY = 8, SCL_TEENSY = 7 , GPIO_MRF = 25, GPIO_MLF = 26, GPIO_MRB = 24, GPIO_MLB = 28, BUZ = 19;
int SOFO = A10 , SOFI = A11 , SORO = 22 , SORI = 23 , SOLO = 33 , SOLI = 34 , SOBO = 35 , SOBI = 36 , FEEDBACK = A21 , SCENSE1 = 32 , SCENSE2 = 31 , BALL = A22 ;
int AD3 = 17 , AD2 = 16 , AD0 = 14 , AD1 = 15;
int mlf, mrb, mlb, mrf;
int srfL , srfB , srfR ;
int reset_BNO = 30 , sck_pixy = 27 , miso_pixy = 12 , mosi_pixy = 11 , S16 = 21 , S17 = 20 , S18 = 38 , S19 = 37;
///////////////////////////////////////////////////////
void setup()
{
  //=====================PINS=============================//
  pinMode(PWM_MRF, OUTPUT);
  pinMode(PWM_MLF, OUTPUT);
  pinMode(PWM_MRB, OUTPUT);
  pinMode(PWM_MLB, OUTPUT);
  pinMode(AD0, OUTPUT);
  pinMode(AD1, OUTPUT);
  pinMode(AD2, OUTPUT);
  pinMode(AD3, OUTPUT);
  pinMode(GPIO_MRF, OUTPUT);
  pinMode(GPIO_MLF, OUTPUT);
  pinMode(GPIO_MRB, OUTPUT);
  pinMode(GPIO_MLB, OUTPUT);
  pinMode(BALL, INPUT);
  pinMode(SOFO, INPUT);
  pinMode(SOBO, INPUT);
  pinMode(SOBI, INPUT);
  pinMode(SORO, INPUT);
  pinMode(SORI, INPUT);
  pinMode(SOFI, INPUT);
  pinMode(SOLO, INPUT);
  pinMode(SOLI, INPUT);
  pinMode(BUZ, OUTPUT);
  pinMode(SET, INPUT_PULLUP);
  pinMode(FEEDBACK, INPUT);
  //  pinMode(led,OUTPUT);
  //=============================================//
  //    digitalWrite(BUZ, HIGH);
  //    delay(1000);
  //    digitalWrite(BUZ, LOW);
  //    delay(100);
  //    digitalWrite(BUZ, HIGH);
  //    delay(105);
  //    digitalWrite(BUZ, LOW);
  //    delay(300);
  //    digitalWrite(BUZ, HIGH);
  //    delay(200);
  //    digitalWrite(BUZ, LOW);
  //    delay(100);
  ////////////////////
  Wire.setSCL(7);
  Wire.setSDA(8);
  Wire.begin ();
  Serial.begin(38400);
  analogWriteResolution(10);
  analogWriteFrequency(9, 29296);
  myTimer.begin (interrupt, 25000);
  nSETUP  = (EEPROM.read(1) << 8 | EEPROM.read(2));
  //  R_noise[0] = (EEPROM.read(3) << 8 | EEPROM.read(4));
  //  R_noise[1] = (EEPROM.read(5) << 8 | EEPROM.read(6));
  //  F_noise[0] = (EEPROM.read(7) << 8 | EEPROM.read(8));
  //  F_noise[1] = (EEPROM.read(9) << 8 | EEPROM.read(10));
  //  L_noise[0] = (EEPROM.read(11) << 8 | EEPROM.read(12));
  //  L_noise[1] = (EEPROM.read(13) << 8 | EEPROM.read(14));
  //  B_noise[0] = (EEPROM.read(15) << 8 | EEPROM.read(16));
  //  B_noise[1] = (EEPROM.read(17) << 8 | EEPROM.read(18));
  //    Calibrate();
}

//////////////////////////////////////////////////////////////////

void loop()
{
  //  biggest();
  //  if (big_distance > Arezoo)
  //    follow();
  //  else
  //    STOP();

  if (digitalRead(SET) == LOW)
  {
    while (digitalRead(SET) == LOW)
    {
      nointerrupt = 100;
      //             Kaf_setup();
      digitalWrite(BUZ, HIGH);
      read_compass();
      //             set_kaf();
    }

    EEPROM.write(1, highByte(bearing));
    EEPROM.write(2, lowByte(bearing));
    //  EEPROM.write(3, highByte(R_noise[0]));
    //  EEPROM.write(4, lowByte(R_noise[0]));
    //  EEPROM.write(5, highByte(R_noise[1]));
    //  EEPROM.write(6, lowByte(R_noise[1]));
    //  EEPROM.write(7, highByte(F_noise[0]));
    //  EEPROM.write(8, lowByte(F_noise[0]));
    //  EEPROM.write(9, highByte(F_noise[1]));
    //  EEPROM.write(10, lowByte(F_noise[1]));
    //  EEPROM.write(11, highByte(L_noise[0]));
    //  EEPROM.write(12, lowByte(L_noise[0]));
    //  EEPROM.write(13, highByte(L_noise[1]));
    //  EEPROM.write(14, lowByte(L_noise[1]));
    //  EEPROM.write(15, highByte(B_noise[0]));
    //  EEPROM.write(16, lowByte(B_noise[0]));
    //  EEPROM.write(17, highByte(B_noise[1]));
    //  EEPROM.write(18, lowByte(B_noise[1]));
    //}
    //

    digitalWrite(BUZ, LOW);
    nSETUP  = (EEPROM.read(1) << 8 | EEPROM.read(2));
    nointerrupt = 0;
  }


}
