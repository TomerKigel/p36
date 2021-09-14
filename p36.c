int poli_int(long i)
{
   int temp_i = i;
   int j = 0;
   int size = 0;
   long f_h = 0;
   long s_h = 0;
    int even = 0;
   while(temp_i >= 1)
   {
    size++;
    temp_i /= 10;
   }

   if(size % 2 != 0)
        even=1;

   temp_i = i;
   for(j = 0; j < size / 2; j++){
        f_h *= 10;
        f_h += temp_i%10;
        temp_i /= 10;
   }

   if(even)
    temp_i /= 10;

   s_h = temp_i;

   if(s_h == f_h)
    return 1;
   return 0;

}

int poli_bin(long i)
{
    int m = 0;
    long j = 1;
    int len = 0;
    int even = 0;
    for(m = 1; m <= 32; m++)
    {
        if(j & i)
            len = m;
        j = j << 1;
    }
    if(len % 2 != 0)
        even=1;

    len = len / 2;
    j = 0;
    for(m = 0; m < len; m++)
        j = j << 1 | 1;
    int f_h = i & j;

    if(even)
        i = i >> 1;
    for(m = 0; m < len; m++)
        i = i >> 1;

    int s_h = i;
    long rev = 0;
    for(m = 0; m < len; m++){
        rev = rev << 1;
        rev += s_h & 1;
        s_h = s_h >> 1;
    }
    if((f_h ^ rev) == 0)
        return 1;
    return 0;
}

int main()
{
    long i = 0;
    long sum = 1;
    for(i = 2; i < 1000000;i++)
    {
        if(i == 15351)
            printf("hi");
        if(poli_int(i) && poli_bin(i)){
            sum += i;
            printf("%d\n",i);
        }
    }
    printf("%d",sum);
}


