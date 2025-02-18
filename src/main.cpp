#include <Arduino.h>
#include "microslang/microslang.h"
#include "microslang/tokenizer.h"
#include "bluetooth.h"
#include "mothership.h"
#include <GyverOLED.h>
#include <driver/i2s.h>

void setup_i2n(int sampleRate, int bitDepth, int i2sChannel) {
    i2s_config_t i2s_config = {
      .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
      .sample_rate = sampleRate,
      .bits_per_sample = (i2s_bits_per_sample_t)bitDepth,
      .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
      .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
      .dma_buf_count = 6,
      .dma_buf_len = 1024,
      .use_apll = true,
      .tx_desc_auto_clear = true,
    };
    
    i2s_pin_config_t pin_config = {
      .bck_io_num = 26, // BCLK-Pin
      .ws_io_num = 25, // LRCLK-Pin
      .data_out_num = 18, // Daten-Ausgangspins
      .data_in_num = I2S_PIN_NO_CHANGE, // Daten-Eingangspins (kein Eingang)
    };

    i2s_driver_install((i2s_port_t)i2sChannel, &i2s_config, 0, NULL);
    i2s_set_pin((i2s_port_t)i2sChannel, &pin_config);
}

//Bluetooth bt;
const int BUFSIZE = 2048;
uint16_t audioBuffer[BUFSIZE];
//Tokenizer t;
//MicroSlang s(48000);
//BluetoothSerial SerialBT;
String currentProgramm =
    "fn test { "
        "sawtoothsynth(55); "
        "sawtoothsynth(110); "
    "} "
    "test; ";
GyverOLED<SSH1106_128x64> oled;
int sampleRate = 48000;
Mothership m;

void setup() {
    Serial.begin(115200);
    oled.init();
    setup_i2n(sampleRate, 16, 0);
    oled.autoPrintln(true);
    pinMode(2, OUTPUT);
    pinMode(33, INPUT);
    pinMode(32, INPUT);
    pinMode(35, INPUT);
    pinMode(34, INPUT);
    digitalWrite(2, HIGH);
    //SerialBT.begin("The Mothership");
    oled.println("MOTHERSHIP");
    oled.println("Made by Phi Labs");
    //s.interpret(t.tokenize(currentProgramm));
    oled.update();
}


void loop() {
    m.testfunc();
    Serial.println(digitalRead(33));
    Serial.println(digitalRead(32));
    Serial.println(digitalRead(35));
    Serial.println(digitalRead(34));
    Serial.println("=======================");
    usleep(100000);
    //s.printDebug();
    /*if(SerialBT.available()) {
        Serial.println("============= Detected new Slang script! =============");
        String rcv = "";
        rcv = rcv + (char)SerialBT.read();
        while(SerialBT.available()) {
            rcv = rcv + (char)SerialBT.read();
        }
        Serial.println(rcv);
        SerialBT.println("Thanks for the new program. Nom nom...");
        currentProgramm = rcv;
        s.clear();
        s.interpret(t.tokenize(currentProgramm));
        s.printDebug();

        oled.clear();
        oled.setCursor(0,0);
        oled.print(currentProgramm);
        oled.setCursor(0,6);
        oled.println("Made by Phi Labs"); 
        oled.println("Sten Heimbrodt");
        oled.update();
    }

    size_t bytes_written;
    for (int i = 0; i < BUFSIZE; i++) {
        //double sample = sf.getSample();
        double sample = 0.0f;
        for(auto* syn : s.getSawtoothSynths()) {
            sample += syn->getSample();
        }
        for(auto* syn : s.getSineSynths()) {
            sample += syn->getSample();
        }
        //fp.setFreq(step->getSample()*55*ph.getPoti(0));
        //sample *= 0.5;
        audioBuffer[i] = sample;

        
        
    }*/
    
    //i2s_write((i2s_port_t)0, audioBuffer, sizeof(audioBuffer), &bytes_written, portMAX_DELAY);
}


