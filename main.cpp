#include <iostream>
#include <ApplicationServices/ApplicationServices.h>

void mouse_event(CGMouseButton button, CGEventType type, CGPoint loc)
{
    CGEventRef event = CGEventCreateMouseEvent(NULL, type, loc, button);
    CGEventSetType(event, type);
    CGEventPost(kCGHIDEventTap, event);
}

CGPoint current_loc()
{
    CGEventRef event = CGEventCreate(NULL);
    CGPoint cursor = CGEventGetLocation(event);
    CFRelease(event);
    return cursor;
}

void set_loc(CGFloat x, CGFloat y)
{
    CGPoint loc = CGPointMake(x, y);
    mouse_event(kCGMouseButtonLeft, kCGEventMouseMoved, loc);
}

// void click(CGPoint loc)
// {
//     CGEventCreateMouseEvent(event, button(true), loc);
//     button(false);
// }

void button(bool press)
{
    CGEventType type;
    CGMouseButton button;

    type = (press ? kCGEventLeftMouseDown : kCGEventLeftMouseUp);
    button = kCGMouseButtonLeft;

    CGEventRef event = CGEventCreate(NULL);
    CGPoint loc = current_loc();
    mouse_event(button, type, loc);
}

void click()
{
    button(true);
    button(false);
}

int main()
{
    set_loc(1251, 267);
    click();
    return 0;
}
