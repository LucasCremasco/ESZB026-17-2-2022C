#include <iostream>
#include <wiringPi.h>
#include <csignal>

// flag para sair do loop principal 
bool RUNNING = true;

// Pisca um LED
void pisca_led(int led, int tempo) {
    digitalWrite(led, HIGH);
    delay(tempo);
    digitalWrite(led, LOW);
    delay(tempo);
}

// Para o programa caso aperte CTRL C
void cancela(int s) {
    std::cout << "CTRL-C detectado. " << s << '\n';
    RUNNING = false;
}

int main() {
        // Registra caso o usuário pressione CTRL-C
        std::signal(SIGINT, cancela);

        // Inicia a wiringPi e permite o uso de pins por números 
        wiringPiSetupGpio();

        std::cout << "Controla os pins da GPIO com wiringPi\n";

        // Define o pin para o cor desejada 
        int verm = 20, am = 16, verd = 21;

        // Configuração dos pins
        pinMode(verm, OUTPUT);
        pinMode(am, OUTPUT);
        pinMode(verd, OUTPUT);

        int tempo = 1000; // interval at which a pin is turned HIGH/LOW
        while (RUNNING) {
            pisca_led(verm, tempo);
            pisca_led(am, tempo);
            pisca_led(verd, tempo);
        }

        std::cout << "Fim do programa ...\n";