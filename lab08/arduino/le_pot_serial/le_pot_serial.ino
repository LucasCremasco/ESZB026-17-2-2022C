const int analogInPin = A0;            // o potenciômetro esta ligado ao pino A0
int iniciaColeta = 0;
char charRecebido;                   // cria uma variavel para armazenar o caractere recebido
int coleta_tempo = 0;
long taxa;
int atraso=100;
unsigned long tempo1 = millis();
void setup(){
   // Configura a serial: baud rate de 115200, 8-bit, sem paridade, 1 stop bit
   Serial.begin(115200, SERIAL_8N1);
}

void loop(){
   if (Serial.available()){            // verifica se recebeu algum comando
      charRecebido = Serial.read();    // le o caractere recebido
      switch ( charRecebido ){
          case 'i':                    // inicia coleta
             iniciaColeta = 1;
             break;
             
          case 'p':                    // para a coleta
             iniciaColeta = 0;
             break;
          case 't':
             coleta_tempo = 1;
             break;
          case 'a':
             atraso = atraso + 5;
             break;
          case 'd':
             atraso = atraso - 5;
             break;
          default:                     // outro comando, ignora...
             break;
      }
   }
   if ( iniciaColeta == 1 ){
       int valor = analogRead(analogInPin); // le valor no pino A0 usando conversor ADC de 10-bit
       Serial.write(valor & 0xFF);          // envia byte menos significativo
       Serial.write(valor >> 8);            // envia byte mais significativo
       unsigned long tempo2 = millis();
       taxa = tempo2-tempo1;
       tempo1 = tempo2;
   }
   if (coleta_tempo == 1) {
       Serial.write(taxa & 0xFF);
       Serial.write(taxa >> 8);
       coleta_tempo = 0;
   }
   delay(atraso);                          // aguarda 100ms
  
}
