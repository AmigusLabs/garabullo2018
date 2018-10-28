int boton_pulsado()
{
  if (analogRead (botonera1) > 50)
  {
    delay(20); // espera 1ms para estabilizar la lectura
    int lectura_actual = analogRead(botonera1);
    pita();
    debounce();
    for (byte i=0; i<5; i++) {
      if (abs(lectura_actual - lectura_botones[i]) < umbral)
      {
        tiempo_ultimo_evento = millis();
        return i;
      }
    }
  }
  else if (analogRead (botonera2) > 50)
  {
    delay(20); // espera 1ms para estabilizar la lectura
    int lectura_actual = analogRead(botonera2);
    pita();
    debounce();
    for (byte i=5; i<9; i++) {
      if (abs(lectura_actual - lectura_botones[i]) < umbral)
      {
        tiempo_ultimo_evento = millis();
        return i;
      }
    }
  }
  else return 100;
}

void debounce()
{
  int contador = 0;
  while (contador < 10)
  {
    int lectura_botonera1 = analogRead(botonera1);
    int lectura_botonera2 = analogRead(botonera2);
    if (lectura_botonera1 < 50 && lectura_botonera2 < 50)
    {
      contador += 1;
    }
    else
    {
      contador = 0;
    }
    delayMicroseconds(500);
  }
}
int prueba_lectura()
{
  if (analogRead (botonera1) > 50)
  {
    return analogRead (botonera1);
  }
  else if (analogRead (botonera2) > 50)
  {
    return analogRead (botonera2);
  }
  else return 0;
}

