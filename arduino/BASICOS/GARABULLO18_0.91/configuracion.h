String propietario = "Diego Lale";


//umbral lecturas 
int umbral = 30;

//lecturas tipo de cada boton
//empieza a contar desde cero para coincidir con los leds
// y así hacer más fácil la programación led-pulsador-onda-corpúsculo ;)

int lectura_botones[] = {
  /* 0 */ 786, // entrada 1
  /* 1 */ 601,
  /* 2 */ 443,
  /* 3 */ 299,
  /* 4 */ 156,

  /* 5 */ 759, // entrada 2
  /* 6 */ 549,
  /* 7 */ 364,
  /* 8 */ 188
};

// esta variable almacena el brillo inicial. Es modificable mediante el menu de configuración
byte brillo = 25;

int tiempoEntrePaso = 1350;
/****************************Variables pasosRecto y pasosGiro**************************************
   En pasosRecto se debe almacenar el número de pasos que necesita GARABULLO para avanzar un cuadro
   En pasosGiro se debe almacenar el número de pasos que necesita GARABULLO para girar 90º
*/
int pasos_recto;
int pasos_giro;


