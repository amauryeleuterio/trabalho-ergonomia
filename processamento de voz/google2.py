import pyaudio
import serial
import speech_recognition as sr
import RPi.GPIO as GPI

GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)

arduino = serial.Serial('/dev/ttyAMA0',9600)
while (True == True):
# obtain audio from the microphone
  r = sr.Recognizer()
  with sr.Microphone() as source:
    #print("Please wait. Calibrating microphone...")
    # listen for 1 second and create the ambient noise energy level
    r.adjust_for_ambient_noise(source, duration=1)
    print("Say something!")
    audio = r.listen(source,phrase_time_limit=3)
 
# recognize speech using Sphinx/Google
  try:
    #response = r.recognize_sphinx(audio)
    response = r.recognize_google(audio)
    print("I think you said: '" + response + "'")
    if ( "help" in response or "hello" in response  or "assistance" in response):
        print("usuario com problemas")
      #   comando ="h"
      #   arduino.write(comando.encode()) #envia a informacao para o arduino  de  que uma vitima foi encontrada
      #   GPIO.output(18,GPIO.HIGH)
        
    if ( "ok" in response ):
        print("usuario sem problemas")
        # comando ="o"
        # arduino.write(comando.encode())    
       
  except sr.UnknownValueError:
    print("I could not understand audio")


