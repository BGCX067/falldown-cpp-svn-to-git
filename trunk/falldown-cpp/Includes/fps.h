
volatile int ticks=1;
volatile int fps_count=0;
volatile int fps_a=0;

void ticker()
{
    ticks++;
}
END_OF_FUNCTION(ticker)

void init_fps()
{
    LOCK_VARIABLE(ticks);
    LOCK_FUNCTION(ticker);
    install_int_ex(ticker, BPS_TO_TIMER(1));
}

void fps(BITMAP *buffer_m)
{
    char string[50];

    if(ticks >= 1)
    {
        fps_a=fps_count;
        fps_count=0;
        ticks=0;
    }
    else
        fps_count++;

    sprintf (string, "fps: %d ", fps_a);
    textout_ex(buffer_m, font, string, 10, 10, makecol(0, 0, 255), -1);

}
