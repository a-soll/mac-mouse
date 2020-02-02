#include <iostream>
#include <ApplicationServices/ApplicationServices.h>

CGPoint current_loc()
{
    CGEventRef event = CGEventCreate(NULL);
    CGPoint cursor = CGEventGetLocation(event);
    CFRelease(event);
    return cursor;
}

void click()
{
    button(true);
    button(false);
}

void button(bool press)
{
    CGEventType type;
    CGMouseButton button;

    switch (button){
        type = (press ? kCGEventLeftMouseDown : kCGEventLeftMouseUp);
        button = kCGMouseButtonLeft;
        break;
    };

    CGEventRef event = CGEventCreate(NULL);

}

int main()
{
    CGPoint p = current_loc();
    std::cout << p.x << std::endl;
    std::cout << p.y << std::endl;
    return 0;
}
