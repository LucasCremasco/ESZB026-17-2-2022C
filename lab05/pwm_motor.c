/** Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

// Ajustando o PWM por HARDWARE na Raspberry Pi

#include <stdio.h>
#include <wiringPi.h>

#define pino_PWM0 18                    // o PWM sera acionado na GPIO18

int main() {                            // este programa deve ser rodado com 'sudo'
   int dc, ciclos;
   wiringPiSetupGpio();                 // usa a numeracao da GPIO
   pinMode(pino_PWM0, PWM_OUTPUT);      // configura a GPIO18 com o PWM por hardware

   // frequencia PWM = 19,2 MHz / (divisor * range)
   // 33862,43 Hz = 19200000 / (27 * 21)
   pwmSetMode(PWM_MODE_MS);             // usando frequencia fixa
   pwmSetRange(100);                    // passos do duty cycle (max=4096)
   pwmSetClock(21);                     // fornece uma frequencia de 10kHz (max=4096)
   printf("Iniciando...\n");
        pwmWrite(pino_PWM0, 27);	//Define o duty cycle de 27
	printf("dc: %d\n", 27);		//Printa na tela o valor do duty cycle
        usleep(10000000);		//Mantém o motor em rotação por 10 sec
	pwmWrite(pino_PWM0, 0);		//Desliga o motor

   printf("Fim.\n");
   return 0;                            // a saida PWM permanece ligada apos o termino do programa
}
