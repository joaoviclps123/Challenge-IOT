int pinoTrigger = 10; 
int pinoEcho = 11;

void setup() {
  
  pinMode(pinoTrigger, OUTPUT); 
  pinMode(pinoEcho, INPUT);
  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
 
  digitalWrite(pinoTrigger, LOW); 
  delayMicroseconds(2);
  
  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pinoTrigger, LOW);
  
  long duracaoAlto = pulseIn(pinoEcho, HIGH); 
  long distancia = usParaCm(duracaoAlto);
  
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");
  
  if(distancia < 20) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW); 
  }
  
  if(distancia < 15) {
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
  }
  
  if(distancia < 10) {
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(6, LOW);
  }
}

long usParaCm(long duracaoAlto) {
  
  long d = (duracaoAlto / 2) * .0343;
  
  return d;
  
}