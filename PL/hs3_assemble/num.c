main()
{
   int A[5], i;
  
   for (i =0; i<5; i++)
       A[i] = i*2;
   
   i =0;
   while (i<5)
      printf("%d\n", A[i++]);

   exit(123);

}
