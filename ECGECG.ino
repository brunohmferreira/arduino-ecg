//grafico no reajusta mais
//grafico mais bonito
//buzzermais grave
//comprar modulo e cartao SD para salvar os dados, biblioteca SD.h
//falta imprimir os valores dos batimentos
#include <SD.h>

Sd2Card SDcard;
SdVolume volume;


int LODminus = 10;//LOD-
int LODplus = 11;//LOD+
int buzzer = 13;
const int chipSelect = 4; 


void setup()
{
  Serial.begin(9600);
  pinMode(LODminus, INPUT); // leads off detection LOD-
  pinMode(LODplus, INPUT); // leads off detection LOD+
  pinMode(buzzer, OUTPUT);
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("Falha ao acessar o cartao !");
    return;
  }
}



void loop()
{
  Serial.print(analogRead(A0));//sensor lecture
  Serial.print(" ");
  Serial.print(470);//formatacao do grafico - acima
  Serial.print(" ");
  Serial.println(270);//formatacao do grafico - abaixo

  File dataFile = SD.open("ECG_values.txt", FILE_WRITE);
  if (dataFile) // Grava os dados no arquivo
    {
      dataFile.println(analogRead(A0));
      dataFile.close();
    }  
  else 
    {
      Serial.println("Erro ao abrir arquivo.txt !"); // Mensagem de erro caso ocorra algum problema na abertura do arquivo
    } 

  if (analogRead(A0) > 360) { //pulse
      tone(buzzer, 63);//buzzer 63 Hertz
  }
  else {
      noTone(buzzer);//buzzer off
  }
}





