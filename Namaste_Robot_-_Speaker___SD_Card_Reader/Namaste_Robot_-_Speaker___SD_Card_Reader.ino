#include "SD.h"
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
#include "SPI.h"

TMRpcm tmrpcm;

void setup()
{
  delay(500);
  tmrpcm.speakerPin = 9;
  Serial.begin(9600);
}


void loop()
{
  AudioPlay();
  delay(3000);
}

void AudioPlay()
{

if (!SD.begin(SD_ChipSelectPin)) 
{
  Serial.println("SD fail");
  return;
  }
  
  Serial.println("SD card is good");
  tmrpcm.setVolume(3);
  tmrpcm.play("bleep.wav");
  Serial.println(tmrpcm.isPlaying());
}
