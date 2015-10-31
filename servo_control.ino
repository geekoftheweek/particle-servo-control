Servo myservo;

int pos = 0;

bool going_crazy = false;

// When looking around randomly, this is how long the eye
// will stay pointing in a direction.
int sleep_min = 200;
int sleep_max = 1000;

// Set reasonable servo ranges here -- will vary by project
int servo_min = 10;
int servo_max = 170;

//
// Built-in Functions
//

void setup() {
    myservo.attach(A0);
    
    // Briefly connect the 3v3 pin to the D0 pin
    // if you want to connect to WiFi.
    pinMode(D7, OUTPUT);
    attachInterrupt(D0, connect, FALLING);
    
    // These will be exposed to the Particle web API
    Spark.function("setpos", setPosition);
    Spark.variable("getpos", &pos, INT);
    Spark.function("crazy", crazyToggle);
    
    // Look around randomly by default
    going_crazy = true;
}

void loop() {

    if (going_crazy) {
        setRandomPosition();
        delay(random(sleep_min, sleep_max));
    }
}


//
// Helper Functions
//

void connect() {
    if (Spark.connected() == false) {
        Spark.connect();
    }
}

void setRandomPosition() {
    pos = random(servo_min, servo_max);
    myservo.write(pos);
}


//
// Directly Callable via API
//

int crazyToggle(String unused) {
    going_crazy = !going_crazy;
    if (going_crazy) {
        return 1;
    } else {
        return 0;
    }
}

int setPosition(String posValue) {
    going_crazy = false;
    pos = posValue.toInt();
    myservo.write(pos);
    return pos;
}

