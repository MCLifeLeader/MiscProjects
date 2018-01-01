

		/* Peace of code to drop to dos */
     if(!strcmp(input, "     ")) {
       MS_DOS();
       strcpy(input, "QUIT");
     }






 MS_DOS()               /* The peace of code that drops to dos */
  {
     system("c:\command.com");
}
