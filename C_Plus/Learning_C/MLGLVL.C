
 lvl1()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level1();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

