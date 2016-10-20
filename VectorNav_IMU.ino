String data_IMU;
char data_cmp_IMU[100];
String yaw, pitch, roll, gyroX, gyroY, gyroZ, accelX, accelY, accelZ, mX, mY, mZ;
String IMU_data, line;
unsigned long IMU_t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial3.begin(115200);
  //    Serial3.write("$VNWRG,06,14*59");  // START
  //    Serial3.write("$VNWRG,07,4*69");   // CHANGE FREQUENCY
  //    Serial3.write("$VNWRG,06,0*6C");  // STOP
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial3.available() > 0)
  {
    IMU_t = millis();
    data_IMU = Serial3.readStringUntil('\n');
    data_IMU.toCharArray(data_cmp_IMU, 100);
    if (strncmp(data_cmp_IMU, "$VNYMR", 6) == 0)
    {
      yaw = data_IMU.substring(7, 15);
      pitch = data_IMU.substring(16, 24);
      roll = data_IMU.substring(25, 33);
      mX = data_IMU.substring(34, 42);
      mY = data_IMU.substring(43, 51);
      mZ = data_IMU.substring(52, 60);
      accelX = data_IMU.substring(61, 68);
      accelY = data_IMU.substring(69, 76);
      accelZ = data_IMU.substring(77, 84);
      gyroX = data_IMU.substring(85, 95);
      gyroY = data_IMU.substring(96, 106);
      gyroZ = data_IMU.substring(107, 117);
    }
    line = String(IMU_t) + "," + yaw + "," + pitch + "," + roll + "," + gyroX + "," + gyroY + "," + gyroZ + "," + accelX + "," + accelY + "," + accelZ + "," + "," + mX + "," + mY + "," + mZ + "," ;
  }
  Serial.println(line);
}
