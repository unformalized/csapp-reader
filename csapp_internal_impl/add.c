int add(int a, int b)
{
    int c = a + b;
    return c;
}

int main()
{
    int a = 0x12340000;
    int b = 0x0000abcd;
    int c = add(a, b);
    return 0;
}
