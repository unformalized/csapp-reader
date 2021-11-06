void pointer_cast() {
    char c = 2;
    char *cp = &c;
    int *ip = (int *) cp;
}