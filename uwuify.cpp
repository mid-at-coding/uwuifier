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
bool IsVowelOrW(char in){
  char c = tolower(in);
  if(!IsVowel(c) && c != 'l' && c != 'r' && c != ' ' && c != 'w'){
    return false;
  }
  return true;
}
void uwu(char in, char next,char before = ' '){
  switch (tolower(in)) {
    case 'c' :
      if(next == 'k'){
        cout<<MatchCase('k',in);
      }
      else if(before == ' '){
        cout<<MatchCase('k',in);
      }
      else{
        cout<<MatchCase('c',in);
      }
      break;
    case 'k' :
      if(before == 'c'){
        break;
      }
      else{
        cout<<MatchCase('k',in);
      }
      break;
    case 's' :
      if(next == ' '){
        cout<<MatchCase('z',in);
      }
      else{
        cout<<MatchCase('s',in);
      }
      break;
    case 'o' :
      if(!IsVowelOrW(before) && next != ' '){
        cout<<"wo";
      }
      else if(!IsVowel(before) && next == ' '){
        cout<<"ow";
      }
      else if(IsVowel(before) && !IsVowel(next)){
        cout<<"ow";
      }
      else{
        cout<<MatchCase('o',in);
      }
      break;
    case 'l' :
    case 'r' :
      if(before != MatchCase('l',before) && before != MatchCase('r',before) && next != MatchCase('l',next) && next != MatchCase('r',next) && next != ' '){
        cout<<MatchCase('w',in);
        break;
      }
      cout<<in;
      break;
    case 'a' :
      if(!IsVowelOrW(before)){
        cout<<"wa";
      }
      else{
        cout<<MatchCase('a',in);
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
      else if(!IsVowel(before) && before != MatchCase('s',before)){
        cout<<"we";
      }
      else{
        cout<<MatchCase('e',in);
      }
      break;
    default :
      cout<<in;
  }
}
bool TheToDa(char in, char next, char after){
  if(in == MatchCase('t',in) && next == MatchCase('h',next) && after == MatchCase('e',after)){
    cout<<MatchCase('d',in)<<MatchCase('a',after);
    return true;
  }
  return false;
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
      if(TheToDa(in[i],in[i+1],in[i+2])){
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
       if(ixeToiex(argv[k][i],argv[k][i+1],argv[k][i+2]) || TheToDa(argv[k][i],argv[k][i+1],argv[k][i+2])){
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
   ending();
   cout<<endl;
}
