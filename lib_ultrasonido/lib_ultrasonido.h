/*
    Grupo Hydrómetra, 2019.
    Librería para sensor ultrasonido HC-SR04 para
    mini-curso sobre creación de librerías en C++.
    Autor: Nicolás Villegas E.
*/

#include "Arduino.h"

class HCSR04 {

    public:
        HCSR04(int, int);
        float get_cm(void);

    private:
        long count_us(void);
        void trigger(void);
        long tiempo;
        float distancia;
        int pin_trig;
        int pin_echo;

};
