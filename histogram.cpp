#include <iostream>
#include <fstream>
#include <string>
using namespace std; 
int c = 255;

int main(int argc, char **argv)
{   
     for (int f = 1; f < argc; f++)
     {
          
          fstream file;
          file.open(argv[f], ios::in);
          
          if (!file) 
          {
               cout << "No such file";
          }
          else
          {
               cout << "Reading the file " << argv[f] << endl;

               int hist[c];
               char letters[c];
               int temp;
               char ch, temp1;
 
               for (int i = 0; i < c; i++) hist[i] = 0;
     
               while (!file.eof()) 
               {
                    file >> ch;

                    if ((ch != '\n') && 
                    ((ch>='a' && ch<='z') 
                    || (ch>='A' && ch<='Z'))
                    )
                    {
                         if (ch>='A' && ch<='Z')
                         {
                              ch = tolower(ch);
                         }

                         hist[int(ch)]++;
                         letters[int(ch)] = ch;
                    }
               }
          
               file.close();

               // print descending sort array
               for(int i = 0; i < c; i++)
          {	
               if(hist[i] != 0)
               {	
                    for(int j=i+1;j<c;j++)
                    {
                         if(hist[i]<hist[j])
                         {
                              temp       = hist[i];
                              temp1      = letters[i];
                    
                              hist[i]    = hist[j];
                              letters[i] = letters[j];

                              hist[j]    = temp;
                              letters[j] = temp1;
                              
                         }
                    }

                    cout << letters[i] << ": " << hist[i] << endl;

               }
               
          }
          }
          cout << "-------------------------" <<  endl;
     }
     
     

     return 0;
}
