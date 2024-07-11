const int BULB1 = PA0; // declare pinout with int data type and pin value
const int BULB2 = PA1;
const int MOTORP = PA2;
const int MOTORN = PA3;
char inputdata = 0;  //Variable for storing received data
LiquidCrystal_I2C lcd(0x27, 16, 2);// Set the LCD address to 0x27 for a 16 chars and 2 line display
void setup()
{
  // Initialize the LCD
   lcd.init();
  // Turn on the backlight
    lcd.backlight();
   Serial1.begin(9600); //Sets the baud rate for bluetooth pins 
    pinMode(BULB1, OUTPUT); //Sets digital pin PA0 as output pin for led1  
    pinMode(BULB2, OUTPUT);  //Sets digital pin PA1 as output pin for led2
    pinMode(MOTORP, OUTPUT);  //Sets digital pin PA2 as output pin for motor positive
    pinMode(MOTORN, OUTPUT); //Sets digital pin PA3 as output pin for motor negative
     // Print initial message to the LCD
  lcd.setCursor(0, 0);
  lcd.print("LOAD CONTROL:");

}
void loop()
{

   if(Serial1.available() > 0)      // Send data only when you receive data:

   {

      inputdata = Serial1.read();        //Read the incoming data & store into data

      if(inputdata == '1') 

      {

         digitalWrite(BULB1, HIGH); 
         
      }
      else if (inputdata == '2')
       {
      digitalWrite(BULB2, HIGH); 
      }
       else if(inputdata == '3')  

      {  
         digitalWrite(BULB1,LOW);    
         }
         else if(inputdata == '4')
         {
        digitalWrite(BULB2,LOW); 
         }
         else if(inputdata == '5')
         {
          digitalWrite(MOTORP,HIGH);
          digitalWrite(MOTORN,LOW);
          
         }
        else if(inputdata == '6')
        {
          digitalWrite(MOTORP,LOW);
          digitalWrite(MOTORN,HIGH);
         
        }
        else if(inputdata == '7')
        {
          digitalWrite(BULB1,LOW);
          digitalWrite(BULB2,LOW);
          digitalWrite(MOTORP,LOW);
          digitalWrite(MOTORN,LOW);
          
        }
    }
  }