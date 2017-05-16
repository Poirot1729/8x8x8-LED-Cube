//FOR ANODE
int clock_1 = 1; //IC Pin 11
int latch_1 = 2; //IC Pin 12
int data_1  = 3; //IC Pin 14
//FOR CATHODE
int clock_2 = 8; //IC Pin 11
int latch_2 = 9; //IC Pin 12
int data_2  = 10; //IC Pin 14

void setup() {
pinMode(latch_1, OUTPUT);
pinMode(clock_1, OUTPUT);
pinMode(data_1, OUTPUT);
pinMode(latch_2, OUTPUT);
pinMode(clock_2, OUTPUT);
pinMode(data_2, OUTPUT);
}

void H_Layers()                                                         //HORIZONTAL LAYERS 
{
byte shift_8=B11111111;
byte shift_7=B11111111;
byte shift_6=B11111111;
byte shift_5=B11111111;
byte shift_4=B11111111;
byte shift_3=B11111111;
byte shift_2=B11111111;
byte shift_1=B11111111;

byte gnd[]={
B00000001,
B00000010,
B00000100,
B00001000,
B00010000,
B00100000,
B01000000,
B10000000,
B00000000
};

int i=0;
int count=sizeof(gnd);
for(int j=0;j<5;)
{
digitalWrite(latch_1, LOW);
digitalWrite(latch_2, LOW);
shiftOut(data_1, clock_1, MSBFIRST, shift_8);
shiftOut(data_1, clock_1, MSBFIRST, shift_7);
shiftOut(data_1, clock_1, MSBFIRST, shift_6);
shiftOut(data_1, clock_1, MSBFIRST, shift_5);
shiftOut(data_1, clock_1, MSBFIRST, shift_4);
shiftOut(data_1, clock_1, MSBFIRST, shift_3);
shiftOut(data_1, clock_1, MSBFIRST, shift_2);
shiftOut(data_1, clock_1, MSBFIRST, shift_1);
shiftOut(data_2, clock_2, MSBFIRST, gnd[i]);
digitalWrite(latch_1, HIGH);
digitalWrite(latch_2, HIGH);
delay(300);
i++;
if (i>=count)
{i=0;
j++;
}
}
}

int i=0;

void loop() {
H_Layers();
}

