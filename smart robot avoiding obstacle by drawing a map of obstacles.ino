// Define pins used for the Ultrasonic Sensor and motor driver IC
const int trigPin = 12;
const int echoPin = 11;
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;

// Set up the motor driver pins as outputs
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}

// Loop through the program
void loop() {
  // Read distance from Ultrasonic Sensor
  long distance = readDistance();

  // If distance is less than or equal to 10 cm, avoid obstacle
  if (distance <= 10) {
    avoidObstacle();
  }
}
/* that part reads the distance from the Ultrasonic Sensor 
and maps the obstacles
*/
// Read distance from Ultrasonic Sensor and map obstacles
long readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2;
  if (distance > 20) {
    distance = 20;
  }
  return distance;
}


/*This function uses the digitalWrite() function to control 
the motors and make the robot turn left 
and right when it detects an obstacle.
*/
// Control motors to avoid obstacles
void avoidObstacle() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(1000);
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(1000);
}


Arduino Uno Kartı
Ultrasonik Sensör (HC-SR04)
L293D Motor Sürücü Entegresi
DC Motorlar
şasi
Jumper Telleri
Breadboard
Güç Kaynağı (Pil veya AC/DC Adaptörü)

Sure, I can provide some guidance on circuit design for this code. Here are the components you will need:

Arduino board (e.g. Uno or Nano)
Ultrasonic Sensor (e.g. HC-SR04)
Motor Driver IC (e.g. L293D)
DC Motors (at least 2)
Power source (e.g. 9V battery or DC adapter)
Jumper wires
Here's how you can connect the components:

Connect the Ultrasonic Sensor to the Arduino board:
VCC of the Ultrasonic Sensor to 5V of Arduino
GND of the Ultrasonic Sensor to GND of Arduino
Trig pin of the Ultrasonic Sensor to pin 12 of Arduino
Echo pin of the Ultrasonic Sensor to pin 11 of Arduino
Connect the Motor Driver IC to the Arduino board:
VCC1 of the Motor Driver IC to 5V of Arduino
GND1 of the Motor Driver IC to GND of Arduino
IN1 of the Motor Driver IC to pin 2 of Arduino
IN2 of the Motor Driver IC to pin 3 of Arduino
IN3 of the Motor Driver IC to pin 4 of Arduino
IN4 of the Motor Driver IC to pin 5 of Arduino
VCC2 of the Motor Driver IC to the positive terminal of your power source
GND2 of the Motor Driver IC to the negative terminal of your power source
Connect the DC Motors to the Motor Driver IC:
Connect the positive terminal of the first DC motor to OUT1 of the Motor Driver IC
Connect the negative terminal of the first DC motor to OUT2 of the Motor Driver IC
Connect the positive terminal of the second DC motor to OUT3 of the Motor Driver IC
Connect the negative terminal of the second DC motor to OUT4 of the Motor Driver IC
Once you have the components connected, you can upload the code you provided to the Arduino board and power on the circuit. The Arduino will read the distance from the Ultrasonic Sensor and control the motors to avoid obstacles when the distance is less than or equal to 10 cm.

I hope this helps! Let me know if you have any further questions.
