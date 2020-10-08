# AlexaIRRemote
M5StickCによるAlexa向け赤外線リモコン

## これはなに？
このデバイスは東芝レグザTVの赤外線リモコンとして動作します。
Alexaの音声コマンドから操作できます。

AlexaからはPhilips社Hueデバイスとして認識され、
輝度値の設定でTVに送るコマンドを決定します。

コードでは以下のように設定しています。

|輝度・明るさ(%)|REGZA command|
|--------------|-------------|
|1|電源|
|2|入力切替|
|5|音量UP|
|6|音量UP|
|8|音量DOWN|
|9|音量DOWN|
|11| チャンネル 1(NHK総合)|
|12| チャンネル 2(ETV)|
|14| チャンネル 4(日テレ)|
|15| チャンネル 5(テレ朝)|
|16| チャンネル 6(TBS)|
|17| チャンネル 7(テレ東)|
|18| チャンネル 8(フジ)|
|19| チャンネル 9(MX)|

## 必要なもの
platformio向けソースコードになっています。

- デバイス
  - M5StickC
  - 物理的なAlexaデバイスがネットワーク上にあること
    - (例) Echo 3nd Generation
- ライブラリ
  - M5Stick-C
    - https://github.com/m5stack/M5StickC
  - IRRemoteESP8266
    - https://github.com/crankyoldgit/IRremoteESP8266
  - Espalexa
    - https://github.com/Aircoookie/Espalexa

## 書いた人
tkhshmsy@gmail.com