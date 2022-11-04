#include < stdio .h >
#include < stdlib .h >
#include < string .h >

#define GPIO_NUMBER_AM "16"
#define GPIO_NUMBER_VERM "20"
#define GPIO_NUMBER_VERD "21"
#define GPIO4_PATH_AM "/ sys / class / gpio / gpio16 /"
#define GPIO4_PATH_VERM "/ sys / class / gpio / gpio20 /"
#define GPIO4_PATH_VERD "/ sys / class / gpio / gpio21 /"
#define GPIO_SYSFS "/ sys / class / gpio /"

void writeGPIO ( char filename [] , char value []) {
FILE * fp ; // cria um ponteiro fp
fp = fopen ( filename , "w+") ; // abre o arquivo para escrita
fprintf (fp , "%s", value ) ; // grava o valor no arquivo
fclose ( fp ); // fecha o arquivo
}

int main ( int argc , char * argv []) {
if( argc !=2) { // o nome do programa eh o argumento 1
printf (" Numero incorreto de argumentos \n") ;
printf (" uso : ./ LED_c comando \n");
printf (" onde comando tem de ser: ligar \n");
return 2; // numero invalido de argumentos
}
if( strcmp ( argv [1] ," ligar ") ==0) {
	//Habilitando a GPIO 20 e o LED Vermelho
	printf (" Habilitando a gpio %s.\n", GPIO_NUMBER_VERM);
	writeGPIO ( GPIO_SYSFS " export ", GPIO_NUMBER_VERM );
	usleep (100000) ; // aguarda 100 ms
	writeGPIO ( GPIO4_PATH_VERM " direction ", " out ");

	printf (" Acendendo o LED\n");
	writeGPIO ( GPIO4_PATH_VERM " value ", "1");
	usleep(2000000); //Aguarda 2 s (Eu acho)

	printf (" Desligando o LED \n");
	writeGPIO ( GPIO4_PATH_VERM " value ", "0");

	printf (" Desabilitando a gpio \n");
	writeGPIO ( GPIO_SYSFS " unexport ", GPIO_NUMBER_VERM );

	//Habilitando a GPIO 21 e o LED Verde
	printf (" Habilitando a gpio %s.\n", GPIO_NUMBER_VERD)
	writeGPIO ( GPIO_SYSFS " export ", GPIO_NUMBER_VERD );
	usleep (100000) ; // aguarda 100 ms
	writeGPIO ( GPIO4_PATH_VERD " direction ", " out ");

	printf (" Acendendo o LED\n");
	writeGPIO ( GPIO4_PATH_VERD " value ", "1");
	usleep(1000000); //Aguarda 1 s (Eu acho)

	printf (" Desligando o LED \n");
	writeGPIO ( GPIO4_PATH_VERD " value ", "0");

	printf (" Desabilitando a gpio \n");
	writeGPIO ( GPIO_SYSFS " unexport ", GPIO_NUMBER_VERD );

	//Habilitando a GPIO 16 e o LED Amarelo
	printf (" Habilitando a gpio %s.\n", GPIO_NUMBER_AM);
	writeGPIO ( GPIO_SYSFS " export ", GPIO_NUMBER_AM );
	usleep (100000) ; // aguarda 100 ms
	writeGPIO ( GPIO4_PATH_AM " direction ", " out ");

	printf (" Acendendo o LED\n");
	writeGPIO ( GPIO4_PATH_AM " value ", "1");
	usleep(1000000); //Aguarda 1 s (Eu acho)

	printf (" Desligando o LED \n");
	writeGPIO ( GPIO4_PATH_AM " value ", "0");

	printf (" Desabilitando a gpio \n");
	writeGPIO ( GPIO_SYSFS " unexport ", GPIO_NUMBER_AM );
else {
printf (" Comando invalido !\n");
}
printf (" Fim do programa em C.\n");
return 0;
}