import sys
from time import sleep

SYSFS_DIR = "/sys/class/gpio/"

LED_PATH_AM = "/sys/class/gpio/gpio16/"
LED_PATH_VERM = "/sys/class/gpio/gpio20/"
LED_PATH_VERD = "/sys/class/gpio/gpio21/"

LED_PATH = [LED_PATH_AM , LED_PATH_VERM, LED_PATH_VERD ]


LED_NUMBER_AM = "16"
LED_NUMBER_VERM = "20"
LED_NUMBER_VERD = "21"

LED_NUMBER = [LED_NUMBER_AM , LED_NUMBER_VERM, LED_NUMBER_VERD]


#Função que escreve o valor 'value' no arquivo 'path + filename'
def writeLED (filename, value, path=LED_PATH):
    fo = open( path + filename,"w")
    fo.write(value)
    fo.close()
    return

#Função que ligará o led, esperará 'pausa' segundos e então desligará o led
def on_off_led(pausa, led_pth):
    writeLED (filename = 'value', value = '1', path = led_pth)
    sleep(pausa)
    writeLED(filename = 'value', value = '0', path = led_pth)

#Verifica o argumento dado no raspberry
if len( sys.argv ) !=2:
    print("Numero incorreto de argumentos")
    print("uso: ./LED.py ligar")
    sys.exit(2)


#SE O PARÂMETRO NA RASPBERRY FOR 'LIGAR'
if sys.argv[1]== "ligar":
    
    #Ativa o GPIO de todos os LEDs
    for led_num, led_path  in zip(LED_NUMBER, LED_PATH):
        print(f"Habilitando a gpio{led_num} led_num")
        writeLED (filename="export", value=led_num, path=SYSFS_DIR)
        sleep(0.1)
        writeLED (filename="direction", value="out", path= led_path)

    #LOOP 5X
    for i in range(5):
        on_off_led(pausa = 2, led_pth = LED_PATH_VERM) #LIGA LED VERMELHO POR 2 SEGUNDOS
        on_off_led(pausa = 1, led_pth = LED_PATH_VERD) #LIGA LED VERDE POR 1 SEGUNDO
        on_off_led(pausa = 1, led_pth = LED_PATH_AM)   #LIGA LED AMARELO POR 1 SEGUNDO


    #Desativa o GPIO de todos os LEDs
    for led_num, led_path  in zip(LED_NUMBER, LED_PATH):
        print(f'Desabilitando a gpio{led_num}')
        writeLED (filename ="unexport", value = LED_NUMBER , path = SYSFS_DIR)
        
else:
    print('Comando Inválido. Para ativar o programa, digite ./LED.py ligar.')