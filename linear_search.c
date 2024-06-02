#include <stdio.h>
void main()
{
    int n,a[10],i,x;
    int count=0;
    printf("ENTER TOTAL NUMBER OF ELEMENTS\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("ENTER ELEMENTS TO SEARCH\n");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        if(a[i] == x)
        {
            count=1;
            break;
        }
    }
    if(count == 1)
    {
        printf("ELEMENT %d FOUND AT POSITION %d",x,i);
    }
    else
    {
        printf("ELEMENT NOT FOUND");
    }
}