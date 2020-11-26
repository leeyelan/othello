#include <stdio.h>
#include <stdlib.h>
#define ROW 6
#define COLS 6

void main() {
   int i, j;    // for system variable 
   int a,b;   
   int n, m;   // array variable length is m, breadth is n
   int count = 1;  // odd number is white, even number is black. 
   int plate[ROW][COLS] = {{0}};  // To initialize all array 0( 0 is blank. Nothing othello)
   int isPossible = 0;           // The variable for showing all flip result and passisng next turn.
   int standardNum;             // On diagonal line,  the limit point to examine othello.  
   int W = 0, E = 0, N = 0, S = 0, NW= 0, NE = 0, SW = 0, SE = 0;   // Flip result initialize to 0
   plate[2][2] = 1;           
    plate[2][3] = 2;
    plate[3][2] = 2;
    plate[3][3] = 1;     // Initializing first othello game situation. 
    
   printPlate(plate);   // Declared printPlate function = To print plate.
   
   while(1) {                                            // For infinite repeatation
      if(count%2 == 1) {
         printf("put a new white othello: ");           // Because White othello and white count are odd number.
      }
      else {
         printf("put a new black othello: ");           // Because Black othello and black count are even number.
      }
      scanf("%d %d", &n, &m);                           // get array coordinate to put othello
      printf("\n");
      plate[n][m] = count;                              // count = othello color   ( odd - white(O), even - black(X))
      
      
      if(m<=4) {                                                           // To reverse east othello
         if(plate[n][m+1] > 0 && plate[n][m+1]%2 != count%2) {   // When if 1 block in the right direction has othello and it is rival othello, 
            for(i = m+2; i<ROW; i++) {                           // Examine from 2 block in the right direction to end
               if(plate[n][i] == 0)                               // when nothing othello, break
                  break;
               else if(plate[n][i]%2 == count%2) {               // when my othello is founded,
                  for(j = m+1; j<i; j++) {                       //From rival othello to my othello
                     plate[n][j]++;                              // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     E++;                                        // whenever reversing othello, plus 1 in east.
                     isPossible = 1;                             //For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
         
         
      if(m>=1) {                                                           // To reverse west othello
         if(plate[n][m-1] > 0 && plate[n][m-1]%2 != count%2) {            // When if 1 block in the left direction has othello and it is rival othello,
            for(i = m-2; i>=0; i--) {                                         // Examine from 2 block in the left direction to end
               if(plate[n][i] == 0)                                               // when nothing othello, break
                  break;
               else if(plate[n][i]%2 == count%2) {                             // when my othello is founded,
                  for(j = m-1; j>i; j--) {                                     //From rival othello to my othello
                     plate[n][j]++;                                            // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     W++;                                                      // whenever reversing othello, plus 1 in west.
                     isPossible = 1;                                          //For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
         
         
      if(n>=1) {                                                          // To reverse north othello
         if(plate[n-1][m] > 0 && plate[n-1][m]%2 != count%2) {           // When if 1 block in the up direction has othello and it is rival othello,
            for(i = n-2; i>=0; i--) {                                     // Examine from 2 block in the up direction to end
               if(plate[i][m] == 0)                                       // when nothing othello, break
                  break;                                                  
               else if(plate[i][m]%2 == count%2) {                       // when my othello is founed,
                  for(j = n-1; j>i; j--) {                               //From rival othello to my othello      
                     plate[j][m]++;                                       // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     N++;                                                 // whenever reversing othello, plus 1 in north.
                     isPossible = 1;                                      // For flip result, this variable changes to 1.
                     
                  }
                  break;
               }
            }   
         }
      }
         
      if(n<=4) {                                                          // To reverse south othello
         if(plate[n+1][m] > 0 && plate[n+1][m]%2 != count%2) {             // When if 1 block in the down direction has othello and it is rival othello,
            for(i = n+2; i<=COLS; i++) {                                   // Examine from 2 block in the down direction to end
               if(plate[i][m] == 0)                                         // when nothing othello, break
                  break;
               else if(plate[i][m]%2 == count%2) {                         // when my othello is founded,
                  for(j = n+1; j<i; j++) {                                  //From rival othello to my othello
                     plate[j][m]++;                                         // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     S++;                                                      // whenever reversing othello, plus 1 in south.
                     isPossible = 1;                                            // For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
      
      if(n<=4 && m<=4) {                                               // To reverse southeast othello
         if(plate[n+1][m+1] > 0 && plate[n+1][m+1]%2 != count%2) {    // When if 1 block in the southeast direction has othello and it is rival othello,
            if(n>m)      // == 5-n < 5-m
               standardNum = 5-n;
            else
               standardNum = 5-m;                                     // For limit point to go southeast direction
               
            for(i = 1; i<=standardNum; i++) {                         // To examine from 1 block in the southeast direction to limit point
               if(plate[n+i][m+i] == 0)                               // when nothing othello, break  
                  break;                                               
               else if(plate[n+i][m+i]%2 == count%2) {                // when my othello is founded,
                  for(j = 1; j<i; j++) {                              //From rivala othello to my othello
                     plate[n+j][m+j]++;                               // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     SE++;                                             // whenever reversing othello, plus 1 in southeast.   
                     isPossible = 1;                                  // For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
      
      if(n>=1 && m<=4) {                                             // To reverse southeast othello
         if(plate[n-1][m+1] > 0 && plate[n-1][m+1]%2 != count%2) {   // When if 1 block in the northeast direction has othello and it is rival othello,
            if(n<5-m)                                              
               standardNum = n;                         
            else
               standardNum = 5-m;                                   // For limit point to go northeast direction
               for(i = 1; i<=standardNum; i++) {                    // To examine from 1 block in the northeast direction to limit point
                if(plate[n-i][m+i] == 0)                             // when nothing othello, break
                  break;
               else if(plate[n-i][m+i]%2 == count%2) {               // when my othello is founded,
                  for(j = 1; j<i; j++) {                             //From rivala othello to my othello
                     plate[n-j][m+j]++;                               // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     NE++;                                             // whenever reversing othello, plus 1 in northeast.
                     isPossible = 1;                                   // For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
       if(n>=1 && m>=1) {                                             // To reverse northwest othello
         if(plate[n-1][m-1] > 0 && plate[n-1][m-1]%2 != count%2) {     // When if 1 block in the northwest direction has othello and it is rival othello,
            if(n<m)      
               standardNum = n;
            else
               standardNum = m;                                       // For limit point to go northwest direction
               for(i = 1; i<=standardNum; i++) {                       // To examine from 1 block in the northwest direction to limit point
                if(plate[n-i][m-i] == 0)                                // when nothing othello, break
                  break;
               else if(plate[n-i][m-i]%2 == count%2) {                // when my othello is founded,
                  for(j = 1; j<i; j++) {                              //From rivala othello to my othello
                     plate[n-j][m-j]++;                               // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     NW++;                                             // whenever reversing othello, plus 1 in northwest.
                     isPossible = 1;                                     // For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
       if(n<=4  && m>=1) {                                                  // To reverse southwest othello
         if(plate[n+1][m-1] > 0 && plate[n+1][m-1]%2 != count%2) {          // When if 1 block in the northwest direction has othello and it is rival othello,
            if(n>5-m)     
               standardNum = 5-n;
            else
               standardNum = m;                                             // For limit point to go southwest direction
               for(i = 1; i<=standardNum; i++) {                            // To examine from 1 block in the southwest direction to limit point
                if(plate[n+i][m-i] == 0)                                    // when nothing othello, break
                  break;
               else if(plate[n+i][m-i]%2 == count%2) {                      // when my othello is founded,
                  for(j = 1; j<i; j++) {                                    //From rivala othello to my othello
                     plate[n+j][m-j]++;                                      // Plus 1 (rival's(even)-> mine(odd)) / standard for white
                     SW++;                                                   // whenever reversing othello, plus 1 in southwest.
                     isPossible = 1;                                         // For flip result, this variable changes to 1.
                  }
                  break;
               }
            }   
         }
      }
      
      if(isPossible == 1) {                                                // isPossible =1 means successing to reverse.= when user reverses rival's
         printPlate(plate);                                                // function to print plate.
         printf("\n\n");
         printf(" :: flip result ::");
         printf("\n  E:%d W:%d N:%d S:%d SW:%d NW:%d SE:%d NE:%d",E,W, N,S,SW,NW,SE,NE);   // For all flip result
         E = 0;
         W = 0;
         N = 0;
         S = 0;
         SW = 0;
         NW = 0;
         SE = 0;
         NE = 0;                                                                         // For initializing all flip result in all diretion.
         count++;                                                                        // changing turn/ (standarding for white, when plus 1 to count, odd changes to even and it means black turn) 
         printf("\n\n");
         isPossible = 0;                                                                 // initializing isPossible to 0
     }
     else {                                                                            // isPossible = 0 means fail to reverse. = when user can't reverse rival's
      
        printf(" :: flip result ::");
        printf("\n  E:%d W:%d N:%d S:%d SW:%d NW:%d SE:%d NE:%d",E,W, N,S,SW,NW,SE,NE);
        printf("\ninvalid input!(no flip happens)\n");                                        // representing user's othello can't be put.
        plate[n][m] = 0;                                                                     // array that user choices initializes 0 = Blank
        printPlate(plate);                                                                   // function to print plate.
        
    }
     
    if(plate[ROW][COLS] != 0 )                                              // If nothing blank to put othellos,
    exit(0);                                                                  // Game is end.
    
    
   }   //while(1) end 
   
    
    		
		
	
        
   
  
  } //main end
  
  



void printPlate(int plate[ROW][COLS]) {      //  function to print plate.
   int i, j;
   int wCount = 0;               
   int bCount = 0;                      // initialize the number of white Othello and black othello to 0
   printf("  0 1 2 3 4 5\n");
    printf(" -------------\n");
   
   for(i=0; i<ROW; i++) {
      printf("%d|",i);
      for(j=0; j<COLS; j++) {
         if(plate[i][j] == 0)
            printf(" |");
         else if(plate[i][j]%2)
            printf("O|");
         else
            printf("X|");
      }
      printf("\n"); 
        printf(" -------------");
        printf("\n");
   }                                        // Making plate.
   printf("\n");
   
      for(i = 0; i<ROW; i++) {                  
      for(j=0; j<COLS; j++) {
         if(plate[i][j] != 0) {
            if(plate[i][j]%2 == 1)
               wCount++;               // If othello is odd, number counting for white.
            else
               bCount++;               // if othello is even, number counting for black.
         }         
      }
   }
   
   printf(" STATUS - WHITE : %d, BLACK : %d",wCount, bCount); // Result for number of white othello, black othello
   printf("\n\n");
}
