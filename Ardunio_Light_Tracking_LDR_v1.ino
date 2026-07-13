
int LDR_LEFT = A0; 
int LDR_RIGHT = A1; 
int LED_RIGHT = 4; 
int LED_LEFT = 6; 

int t = 600; 
int t_2 = (t * 2); 

void setup() { 
  // Configure LED pins as outputs
  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  
  Serial.begin(9600); 
} 

void loop() { 
  int LDR_l_v = analogRead(LDR_LEFT); 
  if (LDR_l_v >= t) { 
    digitalWrite(LED_LEFT, HIGH); 
  } else { 
    digitalWrite(LED_LEFT, LOW); 
  } 

  int LDR_r_v = analogRead(LDR_RIGHT); 
  if (LDR_r_v >= t) { 
    digitalWrite(LED_RIGHT, HIGH); 
  } else { 
    digitalWrite(LED_RIGHT, LOW); 
  }


  int LDR_b = LDR_r_v + LDR_l_v; 
  
  if (LDR_b > t_2){ 
    digitalWrite(LED_RIGHT, HIGH); 
    digitalWrite(LED_LEFT, HIGH); 
  } else { 
    digitalWrite(LED_RIGHT, LOW); 
    digitalWrite(LED_LEFT, LOW); 
  }
}
