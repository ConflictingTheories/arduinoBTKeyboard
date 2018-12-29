char lookupAscii(int code){
  if(code == 97 || code == 65)
    return 'A';
  if(code == 98 || code == 66)
    return 'B';
  if(code == 99 || code == 67)
    return 'C';
  if(code == 100 || code == 68)
    return 'D';
  if(code == 101 || code == 69)
    return 'E';
  if(code == 102 || code == 70)
    return 'F';
  if(code == 103 || code == 71)
    return 'G'; 
  if(code == 57)
    return '9';
  if(code == 56)
    return '8';
  if(code == 55)
    return '7';
  if(code == 54)
    return '6';
  if(code == 53)
    return '5';
  if(code == 52)
    return '4';
  if(code == 51)
    return '3';
  if(code == 50)
    return '2';
  if(code == 49)
    return '1';
  if(code == 48)
    return '0';
  if(code == 35)
    return '#';
  else
    return '*';
}
