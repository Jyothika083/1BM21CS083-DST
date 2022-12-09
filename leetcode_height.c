int* canSeePersonsCount(int* heights, int heightsSize, int* returnSize){
    int i,j;
    int max;
    int lar; 
    int *p;
    p=(int*)malloc(heightsSize*sizeof(int));
   
    for(i=0;i<heightsSize;i++)
    {
        lar=0;
        max=0;
        for(j=i+1;j<heightsSize;j++)
        {
            if (heights[j]>heights[i])
            {
                lar++;
                break;
            }
            else if(heights[j]>max && heights[i]>max)
            {
                max=heights[j];
                lar++;
            }
                
        }
        p[i]=lar;
    }
    for(i=0;i<heightsSize;i++)
        printf("%d",p[i]);
    //returnSize=heightsSize;
    return p;
}
