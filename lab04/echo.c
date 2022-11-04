/** Programa baseado no codigo disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // biblioteca para comunicacao serial
#include <wiringPi.h>
#include <softPwm.h>


int main(){
   int file, count;
   int pino_PWM = 23;                         // pwm por software na GPIO23
   int brilho;
   int receive_num;
   int range = 100;                           // periodo do PWM = 100us*range
   wiringPiSetupGpio();                       // usar a numeracao GPIO, nao WPi
   pinMode(pino_PWM,OUTPUT);	           // configura GPIO23 como saida	
   softPwmCreate(pino_PWM, 1, range);         // inicializa PWM por software   

	if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;             // cria estruturas para configurar a comunicacao
   tcgetattr(file, &options);          // ajusta os parametros do arquivo

   // Configura a comunicacao
   // 115200 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;   // ignora erros de paridade
   tcflush(file, TCIFLUSH);            // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente
   


   //unsigned char transmit[23] = "Testando a comunicacao\0";  // cria uma frase (\0 indica o final da mensagem)

   //usleep(100000);                     // Espera 100ms pela resposta do Arduino
   unsigned char receive[100];         // cria um buffer para receber os dados
while(1){   
	if ((count = read(file, (void*)receive, 100))<0){        // recebe os dados
      perror("Falha ao ler da entrada\n");
      return -1;
   }
   if (count>0) //printf("Nao houve resposta!\n");
   {
	sscanf(receive, "%d", &receive_num);
        receive_num = receive_num/13;
//        printf("%d\n",receive_num);
	
	
	if (receive_num>0) {
           softPwmWrite (pino_PWM, receive_num); 	   // altera o duty cycle do PWM
           printf("%d\n",receive_num);
        }
   }
   usleep(10000);
   //printf("Foram lidos [%d] caracteres: %s\n",count,receive);
}
   close(file);
   return 0;
	
	
		  
		}
	



