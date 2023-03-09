

a3Emp * createEmpDataFromFile(FILE * filePtr) { // helper func
   
   a3Emp * tempPtr;
   
   char oneRecord [100];           // assume that an employee record cannot
                                    // be more than 99 characters long
   
   char tempFname [MAX_LENGTH], tempLname [MAX_LENGTH];
   char tempDependents [2][MAX_LENGTH];
   
   int tempId, tempNumD;
   
   fgets (oneRecord, 100, filePtr);
   
   oneRecord [strlen (oneRecord) - 1] = '\0';
   
   int numRead = sscanf (oneRecord, "%s %s %d%d %s %s", tempFname, tempLname, &tempId, &tempNumD, tempDependents[0], tempDependents [1]);
   
   tempPtr = malloc (sizeof (a3Emp));
   
   strcpy (tempPtr->fname, tempFname);
   strcpy (tempPtr->lname, tempLname);
   
   tempPtr->empId = tempId;
   tempPtr->numDependents = tempNumD;
   
   tempPtr->dependents = malloc (sizeof (char *) * 2);
   
   tempPtr->dependents [0] = malloc (sizeof (strlen (tempDependents[0]) + 1)) ;
   strcpy (tempPtr->dependents [0], tempDependents[0]);
   
   tempPtr->dependents [1] = malloc (sizeof (strlen (tempDependents[1]) + 1)) ;
   strcpy (tempPtr->dependents [1], tempDependents[1]);
   
   //tempPtr->nextEmployee = NULL;
   
   if (numRead == 6) {
      printf ("Creating emp records from File.. %s\n", tempPtr->fname);
      return tempPtr;
   }
   else {
      return NULL;
   }
}

void loadEmpData (struct employee ** headLL, char fileName [MAX_LENGTH]) {
   
   FILE * filePtr;
   
   a3Emp * node;
   a3Emp * tempPtr = *headLL;
   int count = 0;
   
   filePtr = fopen(fileName,"r");
   
   if (filePtr == NULL) {
      printf ("Problem opening the given file \n");
      return;
   }
   
   if(tempPtr != NULL){
      while (tempPtr->nextEmployee != NULL){
         tempPtr = tempPtr->nextEmployee;
      }
   }
   
   while (!feof (filePtr)) {
      
      node = createEmpDataFromFile(filePtr);
      
      if (node != NULL) {
         
         count++;
         
         if (tempPtr == NULL) {
            *headLL = node;
            tempPtr = node;
         }
         else {
            tempPtr->nextEmployee = node;
            tempPtr = tempPtr->nextEmployee;
         }
      }
   }
}
