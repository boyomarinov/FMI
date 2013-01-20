#include<iostream>
using namespace std;

class String{
       private:
              char a[10];
       public:
             String(char* = "");
             int Len();
             String ConCat(const String&);
             String SubStr(int, int);
             String Replace(const String&, const String&);
}

String::String(char *m){
       strcpy(a, m);
}

int String::Len(){
       return strlen(a);
}

String String::ConCat (const String& b){
       String c;
       strcpy(c.a, a); //predavame pyrviq element na masiva
       strcpy(c.a+c.Len(), b.a);
       return c;
}

String String::SubStr(int start, int count){
       String r;
       strncpy(r.a, a+start, count);
       r.a[count] = 0;
       return r;
}

bool StartsWith(char*a, char*b)
{
       if(!*b) return true;
       return *a==*b && StartsWith(a+1,b+1);
}

String String::Replace(const String&, const String&){
       int j=0; String r, m;
       for(int i=0;a[i];i++){
           if(StartsWith(a+i, m.a))        
               r = r.ConCat(SubStr(j,i-j));     
               j = i + m.Len();
               i = j;
       r = r.ConCat(SubStr(j, i-j));               
       }

       return r;       
}



int main()
{
    char a[] = "abcdef";
    char b[] = "bcd";
    
    cout<<a.Len();
    
    
    system("pause");
    return 0;
}





