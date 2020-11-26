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
