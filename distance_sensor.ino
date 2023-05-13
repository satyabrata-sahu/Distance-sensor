#define echoPin A4 //connect to echo pin 
#define trigPin A3 //connect to trig pin 
#define Rled 9     //connect to red led pin               
#define Gled 4     //connect to green led pin 

 
long duration; // Variable to store time taken to the pulse
int distance; // Variable to store distance calculated using
      

void setup()
{
  pinMode(trigPin,OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(Rled,OUTPUT);
  pinMode(Gled,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Distance measurement using Arduino Uno.");
  delay(500);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // wait for 2 ms to avoid
  digitalWrite(trigPin,HIGH); // turn on the Trigger to generate pulse
  delayMicroseconds(10); // keep the trigger "ON" for 10 ms to generate
      // pulse for 10 ms.

  digitalWrite(trigPin,LOW); // Turn off the pulse trigger to stop
          

  duration = pulseIn(echoPin, HIGH);
  distance= duration * 0.0344 / 2; // Expression to calculate
  Serial.print("Distance: ");
  Serial.print(distance); 
  Serial.println(" cm");
  delay(100);

  if(distance>30){
  digitalWrite(Rled,LOW);
  digitalWrite(Gled,HIGH);
    }
  else{
  digitalWrite(Gled,LOW);
  digitalWrite(Rled,HIGH);
    }
    
    
}
