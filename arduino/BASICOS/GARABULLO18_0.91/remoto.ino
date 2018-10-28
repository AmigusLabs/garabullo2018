
#define EXIT_BUTTON_VALUE (byte)225
#define START_BUTTON_VALUE (byte)224
#define LEFT_BUTTON_VALUE (byte)238
#define RIGHT_BUTTON_VALUE (byte)239
#define UP_BUTTON_VALUE (byte)236
#define DOWN_BUTTON_VALUE (byte)237
#define EMPTY_BUTTON_VALUE (byte)0

byte buttonValue[] = {EXIT_BUTTON_VALUE, EMPTY_BUTTON_VALUE, START_BUTTON_VALUE, UP_BUTTON_VALUE, UP_BUTTON_VALUE, UP_BUTTON_VALUE, LEFT_BUTTON_VALUE, DOWN_BUTTON_VALUE, RIGHT_BUTTON_VALUE};

void remoto()
{
  //cargando(1);
  pantalla_inicio_remoto();
  while (true)
  {
    int boton = boton_pulsado();
    if( boton<9) {
      byte codigo = buttonValue[boton];
      if (codigo != 0) {
        Serial.write(codigo);
      }
      while(boton_pulsado()<9) {delay(1);}
    }
  }
}


void pantalla_inicio_remoto()
{
  pantalla.fillScreen(NEGRO);
  pantalla.setTextSize(2);
  pantalla.setCursor(0, 0);
  pantalla.setTextColor(AMARILLO, ROJO);
  pantalla.print("SALIR");

  pantalla.setCursor(65, 0);
  pantalla.setTextColor(ROJO, AMARILLO);
  pantalla.print("START");


  pantalla.setTextColor(VERDE);
  pantalla.setTextSize(5);
  pantalla.setCursor(50, 55); //arriba
  pantalla.write(24);
  pantalla.setCursor(50, 90); //abajo
  pantalla.write(25);
  pantalla.setCursor(10, 90); //izquierda
  pantalla.write(27);
  pantalla.setCursor(90, 90); //derecha
  pantalla.write(26);

  leds_remoto();
}


void leds_remoto()
{
  apaga_leds(0);
  led.setPixelColor(0, led.Color(brillo/2, 0, 0)); // select
  led.setPixelColor(2, led.Color(brillo/2, brillo/2, 0)); // start

  unsigned int color_verde = led.Color(0, brillo, 0);
  led.setPixelColor(4, color_verde);
  led.setPixelColor(6, color_verde);
  led.setPixelColor(7, color_verde);
  led.setPixelColor(8, color_verde);
  led.show();
}
