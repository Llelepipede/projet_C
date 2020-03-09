

void  test_color()
{
    int i=1;

    while(i<81)
    {
        color(0,i%10);
        printf("%d",i%10);
        i++;
    }
}
