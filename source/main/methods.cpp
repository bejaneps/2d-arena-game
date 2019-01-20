#include "../headers/header.hpp"

std::pair<short, short> screen_size()
{
    Display *d = XOpenDisplay(NULL);
    Screen *s = DefaultScreenOfDisplay(d);

    return std::make_pair(std::move(s->width), std::move(s->height));
}