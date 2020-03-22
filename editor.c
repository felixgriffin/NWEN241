#include <stdio.h>
#include <string.h>
#include "editor.h"

int editor_insert_char(char editing_buffer[], int editing_buflen, char to_insert, int pos)
{
  
  if (pos > editing_buflen - 1 || pos < 0){
  
  return 0;
      
}
  
  for (int i = editing_buflen - 1; i > pos; i--){
    
 
    editing_buffer[i] = editing_buffer[i-1];


  }
    
  editing_buffer[pos] = to_insert;
    
  return 1;

}

int editor_delete_char(char editing_buffer[], int editing_buflen, char to_delete, int offset){

  if (offset > editing_buflen - 1 || offset < 0){
    
    return 0;
      
  }
  
  int i = offset;
  
  while (editing_buffer[i] != to_delete){
    
      if (i == editing_buflen - 1){
          
          return 0;
          
      }
      
    i++;
      
  }
  
  if (editing_buffer[i] == to_delete){
    
    for (int j = i; j < editing_buflen - 1; j++){
        
      editing_buffer[j] = editing_buffer[j+1];

    }
      
    editing_buffer[editing_buflen-1] = '\0';
      
  }
      
      
      if (editing_buffer[i] == to_delete){
          
          return 0;
          
      }
      
      else {
          
          return 1;
          
      }

  }
  
int editor_replace_str(char editing_buffer[], int editing_buflen, const char *str, const char *replacement, int offset){
  
  int boolean = -2;
  
  int stringlength = strlen(str);
  
  int replacementlength = strlen (replacement);
    
    int jj;
  
  if (stringlength == 0 || offset < 0 || offset > editing_buflen - 1){
    
    return -1;
    
  }
 
 if ((offset + stringlength) > editing_buflen - 1){
   
   return editing_buflen - 1;

    }
  
  for (int i = offset; i < editing_buflen; i++){
      
    if (editing_buffer[i] == str[0]){
      
      for (int j = 0; j > stringlength; j++){
        
        if (j >= editing_buflen){
        
        return editing_buflen - 1;
        
        }
        
        if (editing_buffer[i + j] == str[j]){
          
          if (j == (stringlength - 1)){
            
            boolean = 1;
              
            int jj = j;
              
              break;
            
          }
          
        }
          
      }
        
      if (boolean == 1){
        
          break;
        
      }
      
    }
    
  }
    
    if (boolean == 0){
        
        return -1;
        
    }
    
    if (boolean == 1){
        
        return 0;
        
    }
    
}
