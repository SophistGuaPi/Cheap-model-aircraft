char xd[24];
char yd[6];
char rd1[6]; 
char rd2[6];
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x,y,r1,r2,rr1,rr2;
  x=analogRead(A0);
  y=analogRead(A1);
  r1=analogRead(A3);
  r2=analogRead(A4);
  x = map(x,0,1023,180,0);
  y = map(y,0,1023,180,0);
  r1 = map(r1,0,1023,1000,1500);
  r2 = map(r2,0,1023,-(1500-r1),1500-r1);
  if (r2<0)
  {rr1=r1-r2;
  rr2 = r1;
  }
  else
  {rr1 = r1;
  rr2 =r1+r2;
  }
  dtostrf(x,4,0,xd);  //将value的值放到临时数组test1中     
  dtostrf(y,4,0,yd);
  dtostrf(rr1,4,0,rd1);
  dtostrf(rr2,4,0,rd2);
  strcat(xd,yd);
  strcat(xd,rd1);
  strcat(xd,rd2);
  Serial.println(xd);
  delay(100);
}