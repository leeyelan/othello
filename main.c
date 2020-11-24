#include <stdio.h>
#include <stdlib.h>
#define ROW 6
#define COLS 6

void main() {
   int isTurn = 0;
   int i, j;
   int n, m;
   int count = 1;
   int plate[ROW][COLS] = {{0}};
   int isPossible = 0;
   int standardNum;
   int W = 0, E = 0, N = 0, S = 0, NW= 0, NE = 0, SW = 0, SE = 0;
   plate[2][2] = 1;
    plate[2][3] = 2;
    plate[3][2] = 2;
    plate[3][3] = 1;
    
   printPlate(plate);
   
   while(1) {
      if(count%2 == 1) {
         printf("put a new white othello: ");
      }
      else {
         printf("put a new black othello: ");
      }
      scanf("%d %d", &n, &m);
      printf("\n");
      plate[n][m] = count;
      
      
      if(m<=4) {
         if(plate[n][m+1] > 0 && plate[n][m+1]%2 != count%2) {
            for(i = m+2; i<ROW; i++) {
               if(plate[n][i] == 0)
                  break;
               else if(plate[n][i]%2 == count%2) {
                  for(j = m+1; j<i; j++) {
                     plate[n][j]++;
                     E++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
         
         
      if(m>=1) {
         if(plate[n][m-1] > 0 && plate[n][m-1]%2 != count%2) {
            for(i = m-2; i>=0; i--) {
               if(plate[n][i] == 0)
                  break;
               else if(plate[n][i]%2 == count%2) {
                  for(j = m-1; j>i; j--) {
                     plate[n][j]++;
                     W++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
         
         
      if(n>=1) {
         if(plate[n-1][m] > 0 && plate[n-1][m]%2 != count%2) {
            for(i = n-2; i>=0; i--) {
               if(plate[i][m] == 0)
                  break;
               else if(plate[i][m]%2 == count%2) {
                  for(j = n-1; j>i; j--) {
                     plate[j][m]++;
                     N++;
                     isPossible = 1;
                     
                  }
                  break;
               }
            }   
         }
      }
         
      if(n<=4) {
         if(plate[n+1][m] > 0 && plate[n+1][m]%2 != count%2) {
            for(i = n+2; i<=COLS; i++) {
               if(plate[i][m] == 0)
                  break;
               else if(plate[i][m]%2 == count%2) {
                  for(j = n+1; j<i; j++) {
                     plate[j][m]++;
                     S++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
      
      if(n<=4 && m<=4) {
         if(plate[n+1][m+1] > 0 && plate[n+1][m+1]%2 != count%2) {
            if(n>m)      // == 5-n < 5-m
               standardNum = 5-n;
            else
               standardNum = 5-m;
               
            for(i = 1; i<=standardNum; i++) {
               if(plate[n+i][m+i] == 0)
                  break;
               else if(plate[n+i][m+i]%2 == count%2) {
                  for(j = 1; j<i; j++) {
                     plate[n+j][m+j]++;
                     SE++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
      
      if(n>=1 && m<=4) {
         if(plate[n-1][m+1] > 0 && plate[n-1][m+1]%2 != count%2) {
            if(n<5-m)      
               standardNum = n;
            else
               standardNum = 5-m;
               for(i = 1; i<=standardNum; i++) {
                if(plate[n-i][m+i] == 0)
                  break;
               else if(plate[n-i][m+i]%2 == count%2) {
                  for(j = 1; j<i; j++) {
                     plate[n-j][m+j]++;
                     NE++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
       if(n>=1 && m>=1) {
         if(plate[n-1][m-1] > 0 && plate[n-1][m-1]%2 != count%2) {
            if(n<m)      
               standardNum = n;
            else
               standardNum = m;
               for(i = 1; i<=standardNum; i++) {
                if(plate[n-i][m-i] == 0)
                  break;
               else if(plate[n-i][m-i]%2 == count%2) {
                  for(j = 1; j<i; j++) {
                     plate[n-j][m-j]++;
                     NW++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
       if(n<=4  && m>=1) {
         if(plate[n+1][m-1] > 0 && plate[n+1][m-1]%2 != count%2) {
            if(n>5-m)     
               standardNum = 5-n;
            else
               standardNum = m;
               for(i = 1; i<=standardNum; i++) {
                if(plate[n+i][m-i] == 0)
                  break;
               else if(plate[n+i][m-i]%2 == count%2) {
                  for(j = 1; j<i; j++) {
                     plate[n+j][m-j]++;
                     SW++;
                     isPossible = 1;
                  }
                  break;
               }
            }   
         }
      }
      
      if(isPossible == 1) {
         printPlate(plate);
         printf("\n\n");
         printf(" :: flip result ::");
         printf("\n  E:%d W:%d N:%d S:%d SW:%d NW:%d SE:%d NE:%d",E,W, N,S,SW,NW,SE,NE);
         E = 0;
         W = 0;
         N = 0;
         S = 0;
         SW = 0;
         NW = 0;
         SE = 0;
         NE = 0;
         count++;
         printf("\n\n");
         isPossible = 0;
     }
     else {
        printf(" :: flip result ::");
        printf("\n  E:%d W:%d N:%d S:%d SW:%d NW:%d SE:%d NE:%d",E,W, N,S,SW,NW,SE,NE);
        printf("\ninvalid input!(no flip happens)\n");
        plate[n][m] = 0;
        printPlate(plate);
     }    
      
   }   
}

void printPlate(int plate[ROW][COLS]) {
   int i, j;
   int wCount = 0;
   int bCount = 0;
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
   }
   printf("\n");
   
      for(i = 0; i<ROW; i++) {
      for(j=0; j<COLS; j++) {
         if(plate[i][j] != 0) {
            if(plate[i][j]%2 == 1)
               wCount++;
            else
               bCount++;
         }         
      }
   }
   
   printf(" STATUS - WHITE : %d, BLACK : %d",wCount, bCount);
   printf("\n\n");
}
