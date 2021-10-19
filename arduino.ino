const int GUN = 12;
const int led2 = 11;
const int led3 = 10;
const int led4 = 9;
const int ldrPin = A0;
const int DUTY_1 = 30;
const int DUTY_2 = 60;
const int DUTY_3 = 120;

int value=0;


void setup()
   {
      Serial.begin(9600);
      pinMode(led1, OUTPUT);
      pinMode(led2, OUTPUT);
      pinMode(led3, OUTPUT);
      pinMode(led4, OUTPUT);
      pinMode(GUN, OUTPUT);
      pinMode(ldrPin, INPUT);
      pinMode(3,INPUT);
      digitalWrite (led1, LOW);
      digitalWrite (led2, LOW);
      digitalWrite (led3, LOW);
      digitalWrite (led4, LOW);
      digitalWrite (GUN, LOW);
      Serial.println("Connection established...");
   }

void loop(){
int ldrStatus = analogRead(ldrPin);


     while (Serial.available())
        {
           value = Serial.read();


        }

     if (value == '1')
        digitalWrite (led1, HIGH);

     else if (value == '2')
        digitalWrite (led1, LOW);

     else if (value == 'A')
        digitalWrite (GUN, HIGH);

     else if (value == 'A')
        digitalWrite (GUN, LOW);

     else if (value == '3')
        digitalWrite (led2, HIGH);

     else if (value == '4')
        digitalWrite (led2, LOW);

     else if (value == '5')
        digitalWrite (led3, HIGH);

     else if (value == '6')
        digitalWrite (led3, LOW);

     else if (value == '7')
        analogWrite( led1, DUTY_1 );

     else if (value == '8')
        analogWrite( led1, DUTY_2 );

     else if (value == '9')
        analogWrite( led1, DUTY_3 );

     else if (value == '0')
        {
        if (ldrStatus <=100)
{
    digitalWrite(led4, LOW);


   }
  else {

    digitalWrite(led4, HIGH);



    Serial.readStringUntil('\n');
    Serial.write("sir some one is comming should i close the door");
    delay(30000);
    }
  }
}
