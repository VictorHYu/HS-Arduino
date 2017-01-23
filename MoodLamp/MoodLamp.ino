//Project number 2 Mood Lamp
// Due November 17 
// Kaarthic and Victor
// Robotics 12

//custom made library that holds pitches of all the notes for piezo
#include "pitches.h"

int button1 = 2; //inputs for 3 buttons
int button2 = 3; 
int button3 = 4; 

int led1 = 13; //outputs for RGB led
int led2 = 12;
int led3 = 11;

int sound = 10; //output for piezo sound

int input; //remembers which button user pressed

// the number of notes in first song
int length1 = 26;
// holds the notes of the song
int notes1[] = {
 NOTE_B5, NOTE_A5, NOTE_G5, 
 NOTE_A5, NOTE_B5, NOTE_B5,
 NOTE_B5, NOTE_A5, NOTE_A5,
 NOTE_A5, NOTE_B5, NOTE_D6,
 NOTE_D6, NOTE_B5, NOTE_A5,
 NOTE_G5, NOTE_A5, NOTE_B5,
 NOTE_B5, NOTE_B5, NOTE_B5,
 NOTE_A5, NOTE_A5, NOTE_B5,
 NOTE_A5, NOTE_G5
};
// holds the beats of the song
int beats1[] = {
  1,1,1,
  1,1,1,
  2,1,1,
  2,1,1,
  2,1,1,
  1,1,1,
  1,1,1,
  1,1,1,
  1,1
};

//the number of notes in the second song
int length2 = 61; 
// holds the notes of the second song
int notes2 []={

NOTES_E4, NOTES_G4, NOTES_FS4, 
NOTES_E4, NOTES_B4, NOTES_A4, 
NOTES_FS4, NOTES_E4, NOTES_G4, 
NOTES_FS4, NOTES_DS4, NOTES_F4, 
NOTES_B3, NOTES_B3, NOTES_E4, 
NOTES_G4, NOTES_FS4, NOTES_E4, 
NOTES_B4, NOTES_D5, NOTES_CS5,
NOTES_C5, NOTES_GS4, NOTES_C5,
NOTES_B4, NOTES_AS4, 0, 0, NOTES_G4,
NOTES_E4, NOTES_G4, NOTES_B4,
NOTES_G4, NOTES_B4, NOTES_G4,
NOTES_C5, NOTES_B4, NOTES_AS4,
NOTES_FS4, NOTES_G4, NOTES_B4,
NOTES_AS4, NOTES_AS3, NOTES_B3,
NOTES_B4, NOTES_G4, NOTES_B4,
NOTES_G4, NOTES_B4, NOTES_G4, 
NOTES_D5, NOTES_DS5, NOTES_C5,
NOTES_GS4, NOTES_C5, NOTES_B4,
NOTES_AS4, 0,0, NOTES_G4,
NOTES_E4
*
};
// holds the beats of the second song
int beats2[] = {
3,1,2,4,2,6,6,3,1,2,4,2,8,2,
3,1,2,4,2,4,2,4,2,
3,1,2,2,2,2,8,2,
4,2,4,2,4,2,4,2,
3,1,2,4,2,8,2,
4,2,4,2,4,2,4,2,
3,1,2,2,2,2,8
};

// the number of notes in the third song
int length3 = 26;
//holds the notes of the third song
int notes3[] = {
 NOTE_B5, NOTE_A5, NOTE_G5, 
 NOTE_A5, NOTE_B5, NOTE_B5,
 NOTE_B5, NOTE_A5, NOTE_A5,
 NOTE_A5, NOTE_B5, NOTE_D6,
 NOTE_D6, NOTE_B5, NOTE_A5,
 NOTE_G5, NOTE_A5, NOTE_B5,
 NOTE_B5, NOTE_B5, NOTE_B5,
 NOTE_A5, NOTE_A5, NOTE_B5,
 NOTE_A5, NOTE_G5
};
// holds the beats of the third song
int beats3[] = {
  1,1,1,
  1,1,1,
  2,1,1,
  2,1,1,
  2,1,1,
  1,1,1,
  1,1,1,
  1,1,1,
  1,1
};

//tempos of the songs
int tempo1 = 300;
int tempo2 = 300;
int tempo3 = 300;

//for speaker output, plays specified note for specified duration
void playTone(int tone, int duration) {
  tone = 500000/tone;
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(sound, HIGH);
    delayMicroseconds(tone);
    digitalWrite(sound, LOW);
    delayMicroseconds(tone);
  }
}

//first mood
void mood1 (){   
  //loops as many times as there are notes
  for (int i = 0; i < length1; i++) 
  {
    //randomize the colour of the LEDS
    int blue = random (1, 256);
    int red = random (1,256);
    int green = random (1,256);
    
    //light up the RGB LED
    analogWrite (led1, blue);
    analogWrite (led2, red);
    analogWrite (led3, green);  
    
      if (notes1[i] == 0) //beat is a rest
      {
        delay(beats1[i] * tempo1); // rest
      } 
      else //a note needs to be played
      {
      //call the function that plays a note  
      playTone(notes1[i], beats1[i] * tempo1); 
      }  
    
    //turn off RGB LED  
    digitalWrite (led1, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);  
      
    // pause between notes
    delay(tempo1 / 2); 
  }
}

void mood2 (){
  for (int i = 0; i < length1; i++) 
  {
    //randomize the colour of the LEDS
    int blue = random (1, 256);
    int red = random (1,256);
    int green = random (1,256);
    
    //light up the RGB LED
    analogWrite (led1, blue);
    analogWrite (led2, red);
    analogWrite (led3, green);  
    
      if (notes1[i] == 0) //beat is a rest
      {
        delay(beats1[i] * tempo1); // rest
      } 
      else //a note needs to be played
      {
      //call the function that plays a note  
      playTone(notes1[i], beats1[i] * tempo1);
      }  
    
    //turn off RGB LED  
    digitalWrite (led1, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);  
      
    // pause between notes
    delay(tempo1 / 2); 
  }
}

void mood3 (){
  for (int i = 0; i < length1; i++) 
  {
    //randomize the colour of the LEDS
    int blue = random (1, 256);
    int red = random (1,256);
    int green = random (1,256);
    
    //light up the RGB LED
    analogWrite (led1, blue);
    analogWrite (led2, red);
    analogWrite (led3, green);  
    
      if (notes1[i] == 0) //beat is a rest
      {
        delay(beats1[i] * tempo1); // rest
      } 
      else //a note needs to be played
      {
      //call the function that plays a note  
      playTone(notes1[i], beats1[i] * tempo1);
      }  
    
    //turn off RGB LED  
    digitalWrite (led1, HIGH);
    digitalWrite (led3, HIGH);
    digitalWrite (led2, HIGH);  
      
    // pause between notes
    delay(tempo1 / 2); 
  }
}

void setup()
{
    pinMode (button1, INPUT);
    pinMode (button2, INPUT);
    pinMode (button3, INPUT);
    pinMode (sound, OUTPUT);
    pinMode (led1, OUTPUT);
    pinMode (led2, OUTPUT);
    pinMode (led3, OUTPUT);
    randomSeed(analogRead(0)); //functions like srand in c++
    digitalWrite( led1, HIGH);
    digitalWrite( led2, HIGH);
    digitalWrite( led3, HIGH);
}

//run different mood functions based on user input
void loop()
{
    if (digitalRead(button1) == 1) // if user pressed first button
    {
      mood1();
    }
    else if (digitalRead(button2) == 1) //if user pressed second button
    {
       mood2();
    }
    else if (digitalRead(button3) == 1) //if used pressed third button
    {
       mood3();
    }  
}




