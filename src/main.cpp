#include <Arduino.h>

#define TRIGGER_PIN D0
#define ECHO_PIN D1
#define SAMPLE_SIZE 20

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);

  Serial.begin(115200);
  Serial.println("Setup completed.");
}

int averageSamples(int samples[])
{
  int sampleSum = 0;

  for (int i = 0; i < SAMPLE_SIZE; i++)
  {
    sampleSum = sampleSum + samples[i];
  }

  return sampleSum / SAMPLE_SIZE;
}

uint32_t startTime = 0;
uint32_t endTime = 0;
int sampleIndex = 0;
int samples[SAMPLE_SIZE];

void loop() {
  delay(20);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(50);

  startTime = micros();
  endTime = micros();

  while (digitalRead(ECHO_PIN) == LOW)
  {
    yield();
  }

  startTime = micros();
  while (digitalRead(ECHO_PIN) == HIGH)
  {
    yield();
  }
  endTime = micros();

  sampleIndex = sampleIndex + 1;
  if (sampleIndex > SAMPLE_SIZE)
  {
    sampleIndex = 0;
  }

  samples[sampleIndex] = endTime - startTime;
  averageSamples(samples);
  Serial.print(averageSamples(samples), DEC);
  Serial.println(' ');
}
