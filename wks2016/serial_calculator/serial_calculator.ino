
String arg1;
String arg2;
char oper;

void cleanup()
{
  arg1 = "";
  arg2 = "";
  oper = 0;
}

void calculate()
{
  int v1 = arg1.toInt();
  int v2 = arg2.toInt();
  int result = 0;
  switch(oper)
  {
    case '+':
      result = v1 + v2;
      break;
    case '-':
      result = v1 - v2;
      break;
    case '*':
      result = v1 * v2;
      break;
    case '/':
      result = v1 / v2;
      break;
  }

  Serial.print(v1);
  Serial.print(" ");
  Serial.print(oper);
  Serial.print(" ");
  Serial.print(v2);
  Serial.print(" = ");
  Serial.println(result);

  cleanup();
}

void setup()
{
  cleanup();
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()) // If data has been sent to the serial monitor
  {
    char c = Serial.read();

    Serial.print("Read char: ");
    Serial.println(c);

    switch(c)
    {
      case '+':
      case '-':
      case '*':
      case '/':
        oper = c;
        break;
      case '=':
        calculate();
        break;
      default:
        if (isDigit(c))
        {
          if (oper)
          {
            arg2 += c;
          }
          else
          {
            arg1 += c;
          }
        }
    }
  }
}

