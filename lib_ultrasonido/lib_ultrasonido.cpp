/*
    Grupo Hydrómetra, 2019.
    Librería para sensor ultrasonido HC-SR04 para
    mini-curso sobre creación de librerías en C++.
    Autor: Nicolás Villegas E.
*/

#include <lib_ultrasonido.h>

HCSR04::HCSR04(int trig, int echo) {

    /* Se guardan los números de pines en variables privadas: */
    pin_trig = trig;
    pin_echo = echo;
    pinMode(pin_trig, OUTPUT);
    pinMode(pin_echo, INPUT);

    /* Por si acaso: */
    digitalWrite(pin_trig, LOW);

}

long HCSR04::count_us(void) {

    /* Espera hasta que el pin echo esté en alto: */
    while(!digitalRead(pin_echo)) {}

    /* Comienza a contar el tiempo: */
    long start_us = micros();

    /*
        Ahora espera hasta que el pin echo vuelva a bajo.
        En caso de que se esté demorando mucho, devuelve
        un error (representado por un número negativo).
    */
    while(digitalRead(pin_echo)) {
        if (micros() - start_us > 20e3) {
        return -1;
        }
    }

    /* Cuando cuando echo sea bajo, termina de tomar el tiempo: */
    long end_us = micros();

    /* Devuelve el tiempo (en microsegundos) que tardó la señal: */
    return end_us - start_us;

}

void HCSR04::trigger(void) {

    /* Genera un pulso cuadrado de 10us de ancho: */
    digitalWrite(pin_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pin_trig, LOW);

}

float HCSR04::get_cm(void) {

    trigger();

    /* Tiempo que tarda el sonido desde la fuente al objetivo: */
    tiempo = count_us() / 2.0;

    if (tiempo < 0) {
        distancia = -1.0;
    }
    else {
        distancia = tiempo * 0.034;
    }

    return distancia;

}
