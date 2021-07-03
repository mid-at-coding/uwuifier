#include <iostream>
#include <string>
#include <cstring>
using namespace std;
char MatchCase(char from, char to){
  if(to <= 'z' && to >= 'a'){
    return tolower(from);
  }
  if(to >= 'A' && to <= 'Z'){
    return toupper(from);
  }
  return from;
}
bool IsVowel(char in){
  char c = tolower(in);
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
    return true;
  }
  return false;
}
bool IsLetter(char in){
  in = toupper(in);
  if(in >= 'A' && in <= 'Z'){return true;}
  return false;
}
void uwu(char in, char next,char before = ' '){
  switch (tolower(in)) {
    case 'o' :
      if(!IsVowel(before) && before != ' '){
        cout<<"wo";
      }
      else{
        cout<<"o";
      }
      break;
    case 'l' :
    case 'r' :
      cout<<MatchCase('w',in);
      break;
    case 'a' :
      if(before == ' '){
        cout<<MatchCase('a',in);
      }
      else if(!IsVowel(before)){
        cout<<"wa";
      }
      else{
        cout<<"a";
      }
      break;
    case 't' :
      if(next == MatchCase('h',next)){
        cout<<MatchCase('d',in);
      }
      else{
        cout<<MatchCase('t',in);
      }
      break;
    case 'h' :
      if(before == MatchCase('t',before)){
        return;
      }
      else{
        cout<<MatchCase('h',in);
      }
      break;
    case 'e' :
      if(next == ' ' && before == MatchCase('l',before)){
        cout<<"el";
      }
      else{
        cout<<MatchCase('e',in);
      }
      break;
    default :
      cout<<in;
  }
}
bool ixeToiex(char in, char next, char after){
  if(tolower(in) == 'i' && tolower(after) == 'e' && IsLetter(next)){
    cout<<MatchCase('i',in);
    cout<<MatchCase('e',after);
    cout<<next;
    return true;
  }
  return false;
}
void ending(){
  string endings[4] = {"owo", "uwu", "nya!", "-w-"}; //these are straight up lifted from bee, sorry lmfao
  cout<<endings[rand() % 4];
}
void NoArgs(){
  string in;
  while(getline(cin,in)){
    in += ' '; //make the ones that rely on asking if next is space work properly
    for(int i = 0; i < in.size(); i++){
      if(ixeToiex(in[i],in[i+1],in[i+2])){
        i += 3;
      }
      if(!i){
          uwu(in[i],in[i + 1]);
      }
      else{
        uwu(in[i],in[i + 1],in[i - 1]);
      }
    }
    cout<<endl;
  }
}
int main(int argc, char** argv){
  if(argc == 1){
    NoArgs();
  }
  for(int k = 1; k < argc; k++){
     for(int i = 0; i < strlen(argv[k]); i++){
       if(ixeToiex(argv[k][i],argv[k][i+1],argv[k][i+2])){
         i += 3;
       }
       if(!i){
           uwu(argv[k][i],argv[k][i + 1]);
       }
       else{
         uwu(argv[k][i],argv[k][i + 1],argv[k][i - 1]);
       }
     }
		 cout<<" ";
   }
   cout<<endl;
}
