int LED = 8;//if any electrode is disconnected
int LODminus = 10;//LOD-
int LODplus = 11;//LOD+
int button = 12; //mute mode
int buzzer = 13; 


int state = 0; //mute mode off

void setup() 
{
  Serial.begin(9600);
  pinMode(LODminus, INPUT); // leads off detection LOD-
  pinMode(LODplus, INPUT); // leads off detection LOD+
  pinMode(buzzer, OUTPUT); 
  pinMode(LED, OUTPUT); 
  pinMode(button, INPUT_PULLUP); 
}



void loop() 
{
  if((digitalRead(LODminus) == 1)||(digitalRead(LODplus) == 1)){//if any electrode is disconnected
   Serial.println("ERROR:electrode is disconnected");
   digitalWrite(LED, HIGH);//electrode disconnected alert
  }
  else if(digitalRead(LODplus) == 1){
    Serial.println("ERROR: LA electrode is disconnected");
    digitalWrite(LED, HIGH);//electrode disconnected alert
  }
  else{//if everything is ok
    digitalWrite(LED, LOW);
    Serial.println(analogRead(A0));//sensor lecture
     if(analogRead(A0) > 400){//pulse
       if(state == 0){//mute mode off
         //digitalWrite(buzzer, HIGH);
       }
     }
     else{
       if(state == 0){//mute mode off
        //digitalWrite(buzzer, LOW);
       }
     }
  }
  delay(50);

  //if (digitalRead(button) == LOW){
   // if(state == 0){//mute mode off
    //  digitalWrite(buzzer, LOW);
    //  state = 1;
   // }
   // else if(state == 1){//mute mode on
   //   digitalWrite(buzzer, HIGH);
   //   state = 0;
  //  }
  //  delay(500);
  //}
}
