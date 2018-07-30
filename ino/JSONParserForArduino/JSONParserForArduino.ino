String findValueWithKey(String message, String key);
String removeDoublequotes(String message);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

}
String findValueWithKey(String message, String key){
  const char startArray = '[';
  const char endArray = ']';
  const char startJson = '{';
  const char endJson = '}';
  const char startValue = ':';
  const char endValue = ',';
  int index =message.indexOf(startValue, message.indexOf(key))+1;
  String returnStr;
  if(index == 0){
    return "Error : Cannot Find ':'";
  }
  int separator1 = (uint16_t)message.indexOf(startArray,index);
  int separator2 = (uint16_t)message.indexOf(startJson,index);
  int separator3 = (uint16_t)message.indexOf(endValue,index);
  if((separator2 > separator3)&&(separator1 > separator3)){//there is not any Array and Json Started.
    returnStr = message.substring(index,separator3);
    returnStr.trim();
    return returnStr;
  }
  
  Serial.print("Separator '[' :");
  Serial.println(separator1);
  Serial.print("Separator '{' :");
  Serial.println(separator2);
  Serial.print("Separator ',' :");
  Serial.println(separator3);
  
  int deepth = 0;
  char* ptr = (char*)message.c_str();
  const char * overIndex = ptr+message.length();
  char compareStartValue;
  char compareEndValue;
  int startSeparator =0;  
  if(separator2 > separator1){//true = Array started first. false = Json started first.
    ptr+=separator1;
    compareStartValue = startArray;
    compareEndValue = endArray;
    startSeparator = separator1;
  }else if(separator2 == separator1){//just key : value 
    startSeparator = index;
    ptr+=index;
    compareStartValue = startJson;
    compareEndValue = endJson;
  }else{
    ptr+=separator2;
    compareStartValue = startJson;
    compareEndValue = endJson;
    startSeparator = separator2;
  }
  Serial.print("Start Var : ");
  Serial.println(compareStartValue);
  Serial.print("End Var : ");
  Serial.println(compareEndValue);
  Serial.print("startSeparator Var : ");
  Serial.println(startSeparator);
  Serial.print("index Var : ");
  Serial.println(index);
  
  const char * ptrStamp = ptr;
  Serial.print("pointer Var : ");
  Serial.println(*ptr);
  Serial.print("Searching Var : ");
  bool checkObject =false;
  while(1){
    returnStr+=*ptr;
    if(*ptr == compareEndValue){
      if(deepth > 1){
        deepth--;
      }else{
        if(!checkObject){
          returnStr.remove(ptr - ptrStamp);
        }
        returnStr.trim();
        break;
      }
    }
    if(*ptr == compareStartValue){
      checkObject = true;
      deepth++;
    }
    ptr++;
    Serial.print(*ptr);
    if(ptr > overIndex){
      returnStr =  "Error : pointer tried to access the location outside of the buffer range";
      break;
    }
  }
  Serial.println();
  return returnStr;
}
String removeDoublequotes(String message){
  char * ptr = (char *)message.c_str();
  int endPtr = 0;
  String retString;
  if(*ptr != '\"'){
    retString = "Error : charater is not started with '\"' ";
    return retString;
  }
  ptr++;
  for(int i = 0; i<message.length();i++){
    if(*ptr == '\"'){
      endPtr = i;
      break;
    }
    ptr++;
    if(ptr > ((char *)message.c_str() + message.length())){
      retString = "Error : pointer tried to access the location outside of the buffer range";
      return retString;
    }
  }
  if(endPtr == message.length()){
    retString = "Error : charater is not ended with '\"' ";
    return retString;
  }else{
    retString = message.substring(1,endPtr+1);
    return retString;
  }
}

