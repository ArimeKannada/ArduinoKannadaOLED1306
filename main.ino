#include <Adafruit_SSD1306.h>



Adafruit_SSD1306 display(128, 64, &Wire, -1);


void setup() 
{
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
  }
  Serial.println(F("start"));
  initdisp();
  display.display();
}

String b;
byte xpos, ypos;
void loop() 
{
  char a = '1';


  if(Serial.available())
  {
    a = Serial.read();
  }


  if(a == '/')
  {
    baraha("/");
  }

   if(a == '-')
  {
    xpos = Serial.parseInt();
    ypos = Serial.parseInt();
    haaku(xpos,ypos);
  }
  if(a == '#')
  {
    b = Serial.readString();
    baraha(b);
  }
  

  if(a == '*')
  {
    initdisp();
  }
  

  if(a == '+')
  {
    byte d,m;
    bool drga;
    m = 0;
    d = 0;
     for(byte o = 1; o<247; o++)
    {
      d = d + 1;
      drga = _bari(o);

      if(drga == 1)
      {
        _bari(0);
      }

      if(d == 11)
      {
        d = 0;
        baraha("/");
        m = m + 1;
      }
      
      if(m == 6)
      {
        m = 0;
        delay(2000);
        initdisp();
      }
    }
    delay(2000);
    initdisp();
  }

  if(a == ',')
  {

    b = Serial.readString();
    Serial.println(b);
    display.print(b);
    display.display();
  }
}




void initdisp()
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.display();
  haaku(0,0);
}
