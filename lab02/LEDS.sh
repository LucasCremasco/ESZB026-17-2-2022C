#!/bin/bash

LED_GPIO_AM=16
LED_GPIO_VERM=20
LED_GPIO_VERD=21

#function setLED
#{
#	echo $1 >> "/sys/class/gpio/gpio$LED_GPIO_AM/value"
#}

#inicio do programa
if [ $# -ne 1 ]; then
	echo "Nenhum comando passado. Uso: ./LEDS.sh command,"
	echo "onde comando tem que ser: ligar"
	exit 2
fi

echo "O comando passado foi: $1"

for i in 1 2 3 4 5; do
	if ["$1" == "ligar"]; then
		#Habilitando o LED Vermelho
		echo "Habilitando a GPIO número $LED_GPIO_VERM"
		echo LED_GPIO_VERM >> "/sys/class/gpio/export"
		sleep 1
		echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_VERM/direction"
	
		echo "Acendendo o LED"
		echo 1 >> "/sys/class/gpio/gpio$LED_GPIO_VERM/value"
	
		sleep 2
	
		echo "Desligando o LED"
		echo 0 >> "/sys/class/gpio/gpio$LED_GPIO_VERM/value"
	
		echo "Desabilitando a GPIO número $LED_GPIO_VERM"
		echo $LED_GPIO_VERM	>> "/sys/class/gpio/unexport"	

		#Habilitando o LED Verde
		echo "Habilitando a GPIO número $LED_GPIO_VERD"
		echo LED_GPIO_VERD >> "/sys/class/gpio/export"
		sleep 1
		echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_VERD/direction"

		echo "Acendendo o LED"
		echo 1 >> "/sys/class/gpio/gpio$LED_GPIO_VERD/value"

		sleep 1

		echo "Desligando o LED"
		echo 0 >> "/sys/class/gpio/gpio$LED_GPIO_VERD/value"

		echo "Desabilitando a GPIO número $LED_GPIO_VERD"
		echo $LED_GPIO_VERD >> "/sys/class/gpio/unexport"

		#Habilitando o LED Amarelo
		echo "Habilitando a GPIO número $LED_GPIO_AM"
		echo LED_GPIO_AM >> "/sys/class/gpio/export"
		sleep 1
		echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_AM/direction"

		echo "Acendendo o LED"
		echo 1 >> "/sys/class/gpio/gpio$LED_GPIO_AM/value"

		sleep 1

		echo "Desligando o LED"
		echo 0 >> "/sys/class/gpio/gpio$LED_GPIO_AM/value"

		echo "Desabilitando a GPIO número $LED_GPIO_AM"
		echo $LED_GPIO_AM >> "/sys/class/gpio/unexport"

	else
		echo "Comando não reconhecido."
		exit 3
	fi
done
