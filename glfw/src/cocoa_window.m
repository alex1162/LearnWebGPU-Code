//========================================================================
<<<<<<< HEAD
// GLFW 3.3 macOS - www.glfw.org
=======
// GLFW 3.4 macOS - www.glfw.org
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
//------------------------------------------------------------------------
// Copyright (c) 2009-2019 Camilla Löwy <elmindreda@glfw.org>
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would
//    be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such, and must not
//    be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source
//    distribution.
//
//========================================================================
<<<<<<< HEAD
// It is fine to use C99 in this file because it will not be built with VS
//========================================================================

#include "internal.h"

=======

#include "internal.h"

#if defined(_GLFW_COCOA)

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
#include <float.h>
#include <string.h>

// HACK: This enum value is missing from framework headers on OS X 10.11 despite
//       having been (according to documentation) added in Mac OS X 10.7
#define NSWindowCollectionBehaviorFullScreenNone (1 << 9)

// Returns whether the cursor is in the content area of the specified window
//
static GLFWbool cursorInContentArea(_GLFWwindow* window)
{
    const NSPoint pos = [window->ns.object mouseLocationOutsideOfEventStream];
    return [window->ns.view mouse:pos inRect:[window->ns.view frame]];
}

// Hides the cursor if not already hidden
//
static void hideCursor(_GLFWwindow* window)
{
    if (!_glfw.ns.cursorHidden)
    {
        [NSCursor hide];
        _glfw.ns.cursorHidden = GLFW_TRUE;
    }
}

// Shows the cursor if not already shown
//
static void showCursor(_GLFWwindow* window)
{
    if (_glfw.ns.cursorHidden)
    {
        [NSCursor unhide];
        _glfw.ns.cursorHidden = GLFW_FALSE;
    }
}

// Updates the cursor image according to its cursor mode
//
static void updateCursorImage(_GLFWwindow* window)
{
    if (window->cursorMode == GLFW_CURSOR_NORMAL)
    {
        showCursor(window);

        if (window->cursor)
            [(NSCursor*) window->cursor->ns.object set];
        else
            [[NSCursor arrowCursor] set];
    }
    else
        hideCursor(window);
}

// Apply chosen cursor mode to a focused window
//
static void updateCursorMode(_GLFWwindow* window)
{
    if (window->cursorMode == GLFW_CURSOR_DISABLED)
    {
        _glfw.ns.disabledCursorWindow = window;
<<<<<<< HEAD
        _glfwPlatformGetCursorPos(window,
                                  &_glfw.ns.restoreCursorPosX,
                                  &_glfw.ns.restoreCursorPosY);
=======
        _glfwGetCursorPosCocoa(window,
                               &_glfw.ns.restoreCursorPosX,
                               &_glfw.ns.restoreCursorPosY);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
        _glfwCenterCursorInContentArea(window);
        CGAssociateMouseAndMouseCursorPosition(false);
    }
    else if (_glfw.ns.disabledCursorWindow == window)
    {
        _glfw.ns.disabledCursorWindow = NULL;
<<<<<<< HEAD
        _glfwPlatformSetCursorPos(window,
                                  _glfw.ns.restoreCursorPosX,
                                  _glfw.ns.restoreCursorPosY);
        // NOTE: The matching CGAssociateMouseAndMouseCursorPosition call is
        //       made in _glfwPlatformSetCursorPos as part of a workaround
=======
        _glfwSetCursorPosCocoa(window,
                               _glfw.ns.restoreCursorPosX,
                               _glfw.ns.restoreCursorPosY);
        // NOTE: The matching CGAssociateMouseAndMouseCursorPosition call is
        //       made in _glfwSetCursorPosCocoa as part of a workaround
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    }

    if (cursorInContentArea(window))
        updateCursorImage(window);
}

// Make the specified window and its video mode active on its monitor
//
static void acquireMonitor(_GLFWwindow* window)
{
<<<<<<< HEAD
    _glfwSetVideoModeNS(window->monitor, &window->videoMode);
    const CGRect bounds = CGDisplayBounds(window->monitor->ns.displayID);
    const NSRect frame = NSMakeRect(bounds.origin.x,
                                    _glfwTransformYNS(bounds.origin.y + bounds.size.height - 1),
=======
    _glfwSetVideoModeCocoa(window->monitor, &window->videoMode);
    const CGRect bounds = CGDisplayBounds(window->monitor->ns.displayID);
    const NSRect frame = NSMakeRect(bounds.origin.x,
                                    _glfwTransformYCocoa(bounds.origin.y + bounds.size.height - 1),
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
                                    bounds.size.width,
                                    bounds.size.height);

    [window->ns.object setFrame:frame display:YES];

    _glfwInputMonitorWindow(window->monitor, window);
}

// Remove the window and restore the original video mode
//
static void releaseMonitor(_GLFWwindow* window)
{
    if (window->monitor->window != window)
        return;

    _glfwInputMonitorWindow(window->monitor, NULL);
<<<<<<< HEAD
    _glfwRestoreVideoModeNS(window->monitor);
=======
    _glfwRestoreVideoModeCocoa(window->monitor);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
}

// Translates macOS key modifiers into GLFW ones
//
static int translateFlags(NSUInteger flags)
{
    int mods = 0;

    if (flags & NSEventModifierFlagShift)
        mods |= GLFW_MOD_SHIFT;
    if (flags & NSEventModifierFlagControl)
        mods |= GLFW_MOD_CONTROL;
    if (flags & NSEventModifierFlagOption)
        mods |= GLFW_MOD_ALT;
    if (flags & NSEventModifierFlagCommand)
        mods |= GLFW_MOD_SUPER;
    if (flags & NSEventModifierFlagCapsLock)
        mods |= GLFW_MOD_CAPS_LOCK;

    return mods;
}

// Translates a macOS keycode to a GLFW keycode
//
static int translateKey(unsigned int key)
{
    if (key >= sizeof(_glfw.ns.keycodes) / sizeof(_glfw.ns.keycodes[0]))
        return GLFW_KEY_UNKNOWN;

    return _glfw.ns.keycodes[key];
}

// Translate a GLFW keycode to a Cocoa modifier flag
//
static NSUInteger translateKeyToModifierFlag(int key)
{
    switch (key)
    {
        case GLFW_KEY_LEFT_SHIFT:
        case GLFW_KEY_RIGHT_SHIFT:
            return NSEventModifierFlagShift;
        case GLFW_KEY_LEFT_CONTROL:
        case GLFW_KEY_RIGHT_CONTROL:
            return NSEventModifierFlagControl;
        case GLFW_KEY_LEFT_ALT:
        case GLFW_KEY_RIGHT_ALT:
            return NSEventModifierFlagOption;
        case GLFW_KEY_LEFT_SUPER:
        case GLFW_KEY_RIGHT_SUPER:
            return NSEventModifierFlagCommand;
        case GLFW_KEY_CAPS_LOCK:
            return NSEventModifierFlagCapsLock;
    }

    return 0;
}

// Defines a constant for empty ranges in NSTextInputClient
//
static const NSRange kEmptyRange = { NSNotFound, 0 };


//------------------------------------------------------------------------
// Delegate for window related notifications
//------------------------------------------------------------------------

@interface GLFWWindowDelegate : NSObject
{
    _GLFWwindow* window;
}

- (instancetype)initWithGlfwWindow:(_GLFWwindow *)initWindow;

@end

@implementation GLFWWindowDelegate

- (instancetype)initWithGlfwWindow:(_GLFWwindow *)initWindow
{
    self = [super init];
    if (self != nil)
        window = initWindow;

    return self;
}

- (BOOL)windowShouldClose:(id)sender
{
    _glfwInputWindowCloseRequest(window);
    return NO;
}

- (void)windowDidResize:(NSNotification *)notification
{
    if (window->context.source == GLFW_NATIVE_CONTEXT_API)
        [window->context.nsgl.object update];

    if (_glfw.ns.disabledCursorWindow == window)
        _glfwCenterCursorInContentArea(window);

    const int maximized = [window->ns.object isZoomed];
    if (window->ns.maximized != maximized)
    {
        window->ns.maximized = maximized;
        _glfwInputWindowMaximize(window, maximized);
    }

    const NSRect contentRect = [window->ns.view frame];
    const NSRect fbRect = [window->ns.view convertRectToBacking:contentRect];

    if (fbRect.size.width != window->ns.fbWidth ||
        fbRect.size.height != window->ns.fbHeight)
    {
        window->ns.fbWidth  = fbRect.size.width;
        window->ns.fbHeight = fbRect.size.height;
        _glfwInputFramebufferSize(window, fbRect.size.width, fbRect.size.height);
    }

    if (contentRect.size.width != window->ns.width ||
        contentRect.size.height != window->ns.height)
    {
        window->ns.width  = contentRect.size.width;
        window->ns.height = contentRect.size.height;
        _glfwInputWindowSize(window, contentRect.size.width, contentRect.size.height);
    }
}

- (void)windowDidMove:(NSNotification *)notification
{
    if (window->context.source == GLFW_NATIVE_CONTEXT_API)
        [window->context.nsgl.object update];

    if (_glfw.ns.disabledCursorWindow == window)
        _glfwCenterCursorInContentArea(window);

    int x, y;
<<<<<<< HEAD
    _glfwPlatformGetWindowPos(window, &x, &y);
=======
    _glfwGetWindowPosCocoa(window, &x, &y);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    _glfwInputWindowPos(window, x, y);
}

- (void)windowDidMiniaturize:(NSNotification *)notification
{
    if (window->monitor)
        releaseMonitor(window);

    _glfwInputWindowIconify(window, GLFW_TRUE);
}

- (void)windowDidDeminiaturize:(NSNotification *)notification
{
    if (window->monitor)
        acquireMonitor(window);

    _glfwInputWindowIconify(window, GLFW_FALSE);
}

- (void)windowDidBecomeKey:(NSNotification *)notification
{
    if (_glfw.ns.disabledCursorWindow == window)
        _glfwCenterCursorInContentArea(window);

    _glfwInputWindowFocus(window, GLFW_TRUE);
    updateCursorMode(window);
}

- (void)windowDidResignKey:(NSNotification *)notification
{
    if (window->monitor && window->autoIconify)
<<<<<<< HEAD
        _glfwPlatformIconifyWindow(window);
=======
        _glfwIconifyWindowCocoa(window);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    _glfwInputWindowFocus(window, GLFW_FALSE);
}

- (void)windowDidChangeOcclusionState:(NSNotification* )notification
{
<<<<<<< HEAD
    if ([window->ns.object occlusionState] & NSWindowOcclusionStateVisible)
        window->ns.occluded = GLFW_FALSE;
    else
        window->ns.occluded = GLFW_TRUE;
=======
#if MAC_OS_X_VERSION_MAX_ALLOWED >= 1090
    if ([window->ns.object respondsToSelector:@selector(occlusionState)])
    {
        if ([window->ns.object occlusionState] & NSWindowOcclusionStateVisible)
            window->ns.occluded = GLFW_FALSE;
        else
            window->ns.occluded = GLFW_TRUE;
    }
#endif
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
}

@end


//------------------------------------------------------------------------
// Content view class for the GLFW window
//------------------------------------------------------------------------

@interface GLFWContentView : NSView <NSTextInputClient>
{
    _GLFWwindow* window;
    NSTrackingArea* trackingArea;
    NSMutableAttributedString* markedText;
}

- (instancetype)initWithGlfwWindow:(_GLFWwindow *)initWindow;

@end

@implementation GLFWContentView

- (instancetype)initWithGlfwWindow:(_GLFWwindow *)initWindow
{
    self = [super init];
    if (self != nil)
    {
        window = initWindow;
        trackingArea = nil;
        markedText = [[NSMutableAttributedString alloc] init];

        [self updateTrackingAreas];
        [self registerForDraggedTypes:@[NSPasteboardTypeURL]];
    }

    return self;
}

- (void)dealloc
{
    [trackingArea release];
    [markedText release];
    [super dealloc];
}

- (BOOL)isOpaque
{
    return [window->ns.object isOpaque];
}

- (BOOL)canBecomeKeyView
{
    return YES;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

- (BOOL)wantsUpdateLayer
{
    return YES;
}

- (void)updateLayer
{
    if (window->context.source == GLFW_NATIVE_CONTEXT_API)
        [window->context.nsgl.object update];

    _glfwInputWindowDamage(window);
}

- (void)cursorUpdate:(NSEvent *)event
{
    updateCursorImage(window);
}

- (BOOL)acceptsFirstMouse:(NSEvent *)event
{
    return YES;
}

- (void)mouseDown:(NSEvent *)event
{
    _glfwInputMouseClick(window,
                         GLFW_MOUSE_BUTTON_LEFT,
                         GLFW_PRESS,
                         translateFlags([event modifierFlags]));
}

- (void)mouseDragged:(NSEvent *)event
{
    [self mouseMoved:event];
}

- (void)mouseUp:(NSEvent *)event
{
    _glfwInputMouseClick(window,
                         GLFW_MOUSE_BUTTON_LEFT,
                         GLFW_RELEASE,
                         translateFlags([event modifierFlags]));
}

- (void)mouseMoved:(NSEvent *)event
{
    if (window->cursorMode == GLFW_CURSOR_DISABLED)
    {
        const double dx = [event deltaX] - window->ns.cursorWarpDeltaX;
        const double dy = [event deltaY] - window->ns.cursorWarpDeltaY;

        _glfwInputCursorPos(window,
                            window->virtualCursorPosX + dx,
                            window->virtualCursorPosY + dy);
    }
    else
    {
        const NSRect contentRect = [window->ns.view frame];
        // NOTE: The returned location uses base 0,1 not 0,0
        const NSPoint pos = [event locationInWindow];

        _glfwInputCursorPos(window, pos.x, contentRect.size.height - pos.y);
    }

    window->ns.cursorWarpDeltaX = 0;
    window->ns.cursorWarpDeltaY = 0;
}

- (void)rightMouseDown:(NSEvent *)event
{
    _glfwInputMouseClick(window,
                         GLFW_MOUSE_BUTTON_RIGHT,
                         GLFW_PRESS,
                         translateFlags([event modifierFlags]));
}

- (void)rightMouseDragged:(NSEvent *)event
{
    [self mouseMoved:event];
}

- (void)rightMouseUp:(NSEvent *)event
{
    _glfwInputMouseClick(window,
                         GLFW_MOUSE_BUTTON_RIGHT,
                         GLFW_RELEASE,
                         translateFlags([event modifierFlags]));
}

- (void)otherMouseDown:(NSEvent *)event
{
    _glfwInputMouseClick(window,
                         (int) [event buttonNumber],
                         GLFW_PRESS,
                         translateFlags([event modifierFlags]));
}

- (void)otherMouseDragged:(NSEvent *)event
{
    [self mouseMoved:event];
}

- (void)otherMouseUp:(NSEvent *)event
{
    _glfwInputMouseClick(window,
                         (int) [event buttonNumber],
                         GLFW_RELEASE,
                         translateFlags([event modifierFlags]));
}

- (void)mouseExited:(NSEvent *)event
{
    if (window->cursorMode == GLFW_CURSOR_HIDDEN)
        showCursor(window);

    _glfwInputCursorEnter(window, GLFW_FALSE);
}

- (void)mouseEntered:(NSEvent *)event
{
    if (window->cursorMode == GLFW_CURSOR_HIDDEN)
        hideCursor(window);

    _glfwInputCursorEnter(window, GLFW_TRUE);
}

- (void)viewDidChangeBackingProperties
{
    const NSRect contentRect = [window->ns.view frame];
    const NSRect fbRect = [window->ns.view convertRectToBacking:contentRect];
    const float xscale = fbRect.size.width / contentRect.size.width;
    const float yscale = fbRect.size.height / contentRect.size.height;

    if (xscale != window->ns.xscale || yscale != window->ns.yscale)
    {
<<<<<<< HEAD
        if (window->ns.retina && window->ns.layer)
=======
        if (window->ns.scaleFramebuffer && window->ns.layer)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
            [window->ns.layer setContentsScale:[window->ns.object backingScaleFactor]];

        window->ns.xscale = xscale;
        window->ns.yscale = yscale;
        _glfwInputWindowContentScale(window, xscale, yscale);
    }

    if (fbRect.size.width != window->ns.fbWidth ||
        fbRect.size.height != window->ns.fbHeight)
    {
        window->ns.fbWidth  = fbRect.size.width;
        window->ns.fbHeight = fbRect.size.height;
        _glfwInputFramebufferSize(window, fbRect.size.width, fbRect.size.height);
    }
}

- (void)drawRect:(NSRect)rect
{
    _glfwInputWindowDamage(window);
}

- (void)updateTrackingAreas
{
    if (trackingArea != nil)
    {
        [self removeTrackingArea:trackingArea];
        [trackingArea release];
    }

    const NSTrackingAreaOptions options = NSTrackingMouseEnteredAndExited |
                                          NSTrackingActiveInKeyWindow |
                                          NSTrackingEnabledDuringMouseDrag |
                                          NSTrackingCursorUpdate |
                                          NSTrackingInVisibleRect |
                                          NSTrackingAssumeInside;

    trackingArea = [[NSTrackingArea alloc] initWithRect:[self bounds]
                                                options:options
                                                  owner:self
                                               userInfo:nil];

    [self addTrackingArea:trackingArea];
    [super updateTrackingAreas];
}

- (void)keyDown:(NSEvent *)event
{
    const int key = translateKey([event keyCode]);
    const int mods = translateFlags([event modifierFlags]);

    _glfwInputKey(window, key, [event keyCode], GLFW_PRESS, mods);

    [self interpretKeyEvents:@[event]];
}

- (void)flagsChanged:(NSEvent *)event
{
    int action;
    const unsigned int modifierFlags =
        [event modifierFlags] & NSEventModifierFlagDeviceIndependentFlagsMask;
    const int key = translateKey([event keyCode]);
    const int mods = translateFlags(modifierFlags);
    const NSUInteger keyFlag = translateKeyToModifierFlag(key);

    if (keyFlag & modifierFlags)
    {
        if (window->keys[key] == GLFW_PRESS)
            action = GLFW_RELEASE;
        else
            action = GLFW_PRESS;
    }
    else
        action = GLFW_RELEASE;

    _glfwInputKey(window, key, [event keyCode], action, mods);
}

- (void)keyUp:(NSEvent *)event
{
    const int key = translateKey([event keyCode]);
    const int mods = translateFlags([event modifierFlags]);
    _glfwInputKey(window, key, [event keyCode], GLFW_RELEASE, mods);
}

- (void)scrollWheel:(NSEvent *)event
{
    double deltaX = [event scrollingDeltaX];
    double deltaY = [event scrollingDeltaY];

    if ([event hasPreciseScrollingDeltas])
    {
        deltaX *= 0.1;
        deltaY *= 0.1;
    }

    if (fabs(deltaX) > 0.0 || fabs(deltaY) > 0.0)
        _glfwInputScroll(window, deltaX, deltaY);
}

- (NSDragOperation)draggingEntered:(id <NSDraggingInfo>)sender
{
    // HACK: We don't know what to say here because we don't know what the
    //       application wants to do with the paths
    return NSDragOperationGeneric;
}

- (BOOL)performDragOperation:(id <NSDraggingInfo>)sender
{
    const NSRect contentRect = [window->ns.view frame];
    // NOTE: The returned location uses base 0,1 not 0,0
    const NSPoint pos = [sender draggingLocation];
    _glfwInputCursorPos(window, pos.x, contentRect.size.height - pos.y);

    NSPasteboard* pasteboard = [sender draggingPasteboard];
    NSDictionary* options = @{NSPasteboardURLReadingFileURLsOnlyKey:@YES};
    NSArray* urls = [pasteboard readObjectsForClasses:@[[NSURL class]]
                                              options:options];
    const NSUInteger count = [urls count];
    if (count)
    {
<<<<<<< HEAD
        char** paths = calloc(count, sizeof(char*));
=======
        char** paths = _glfw_calloc(count, sizeof(char*));
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

        for (NSUInteger i = 0;  i < count;  i++)
            paths[i] = _glfw_strdup([urls[i] fileSystemRepresentation]);

        _glfwInputDrop(window, (int) count, (const char**) paths);

        for (NSUInteger i = 0;  i < count;  i++)
<<<<<<< HEAD
            free(paths[i]);
        free(paths);
=======
            _glfw_free(paths[i]);
        _glfw_free(paths);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    }

    return YES;
}

- (BOOL)hasMarkedText
{
    return [markedText length] > 0;
}

- (NSRange)markedRange
{
    if ([markedText length] > 0)
        return NSMakeRange(0, [markedText length] - 1);
    else
        return kEmptyRange;
}

- (NSRange)selectedRange
{
    return kEmptyRange;
}

- (void)setMarkedText:(id)string
        selectedRange:(NSRange)selectedRange
     replacementRange:(NSRange)replacementRange
{
    [markedText release];
    if ([string isKindOfClass:[NSAttributedString class]])
        markedText = [[NSMutableAttributedString alloc] initWithAttributedString:string];
    else
        markedText = [[NSMutableAttributedString alloc] initWithString:string];
}

- (void)unmarkText
{
    [[markedText mutableString] setString:@""];
}

- (NSArray*)validAttributesForMarkedText
{
    return [NSArray array];
}

- (NSAttributedString*)attributedSubstringForProposedRange:(NSRange)range
                                               actualRange:(NSRangePointer)actualRange
{
    return nil;
}

- (NSUInteger)characterIndexForPoint:(NSPoint)point
{
    return 0;
}

- (NSRect)firstRectForCharacterRange:(NSRange)range
                         actualRange:(NSRangePointer)actualRange
{
    const NSRect frame = [window->ns.view frame];
    return NSMakeRect(frame.origin.x, frame.origin.y, 0.0, 0.0);
}

- (void)insertText:(id)string replacementRange:(NSRange)replacementRange
{
    NSString* characters;
    NSEvent* event = [NSApp currentEvent];
    const int mods = translateFlags([event modifierFlags]);
    const int plain = !(mods & GLFW_MOD_SUPER);

    if ([string isKindOfClass:[NSAttributedString class]])
        characters = [string string];
    else
        characters = (NSString*) string;

    NSRange range = NSMakeRange(0, [characters length]);
    while (range.length)
    {
        uint32_t codepoint = 0;

        if ([characters getBytes:&codepoint
                       maxLength:sizeof(codepoint)
                      usedLength:NULL
                        encoding:NSUTF32StringEncoding
                         options:0
                           range:range
                  remainingRange:&range])
        {
            if (codepoint >= 0xf700 && codepoint <= 0xf7ff)
                continue;

            _glfwInputChar(window, codepoint, mods, plain);
        }
    }
}

- (void)doCommandBySelector:(SEL)selector
{
}

@end


//------------------------------------------------------------------------
// GLFW window class
//------------------------------------------------------------------------

@interface GLFWWindow : NSWindow {}
@end

@implementation GLFWWindow

- (BOOL)canBecomeKeyWindow
{
    // Required for NSWindowStyleMaskBorderless windows
    return YES;
}

- (BOOL)canBecomeMainWindow
{
    return YES;
}

@end


// Create the Cocoa window
//
static GLFWbool createNativeWindow(_GLFWwindow* window,
                                   const _GLFWwndconfig* wndconfig,
                                   const _GLFWfbconfig* fbconfig)
{
    window->ns.delegate = [[GLFWWindowDelegate alloc] initWithGlfwWindow:window];
    if (window->ns.delegate == nil)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to create window delegate");
        return GLFW_FALSE;
    }

    NSRect contentRect;

    if (window->monitor)
    {
        GLFWvidmode mode;
        int xpos, ypos;

<<<<<<< HEAD
        _glfwPlatformGetVideoMode(window->monitor, &mode);
        _glfwPlatformGetMonitorPos(window->monitor, &xpos, &ypos);
=======
        _glfwGetVideoModeCocoa(window->monitor, &mode);
        _glfwGetMonitorPosCocoa(window->monitor, &xpos, &ypos);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

        contentRect = NSMakeRect(xpos, ypos, mode.width, mode.height);
    }
    else
<<<<<<< HEAD
        contentRect = NSMakeRect(0, 0, wndconfig->width, wndconfig->height);
=======
    {
        if (wndconfig->xpos == GLFW_ANY_POSITION ||
            wndconfig->ypos == GLFW_ANY_POSITION)
        {
            contentRect = NSMakeRect(0, 0, wndconfig->width, wndconfig->height);
        }
        else
        {
            const int xpos = wndconfig->xpos;
            const int ypos = _glfwTransformYCocoa(wndconfig->ypos + wndconfig->height - 1);
            contentRect = NSMakeRect(xpos, ypos, wndconfig->width, wndconfig->height);
        }
    }
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    NSUInteger styleMask = NSWindowStyleMaskMiniaturizable;

    if (window->monitor || !window->decorated)
        styleMask |= NSWindowStyleMaskBorderless;
    else
    {
        styleMask |= (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable);

        if (window->resizable)
            styleMask |= NSWindowStyleMaskResizable;
    }

    window->ns.object = [[GLFWWindow alloc]
        initWithContentRect:contentRect
                  styleMask:styleMask
                    backing:NSBackingStoreBuffered
                      defer:NO];

    if (window->ns.object == nil)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR, "Cocoa: Failed to create window");
        return GLFW_FALSE;
    }

    if (window->monitor)
        [window->ns.object setLevel:NSMainMenuWindowLevel + 1];
    else
    {
<<<<<<< HEAD
        [(NSWindow*) window->ns.object center];
        _glfw.ns.cascadePoint =
            NSPointToCGPoint([window->ns.object cascadeTopLeftFromPoint:
                              NSPointFromCGPoint(_glfw.ns.cascadePoint)]);
=======
        if (wndconfig->xpos == GLFW_ANY_POSITION ||
            wndconfig->ypos == GLFW_ANY_POSITION)
        {
            [(NSWindow*) window->ns.object center];
            _glfw.ns.cascadePoint =
                NSPointToCGPoint([window->ns.object cascadeTopLeftFromPoint:
                                NSPointFromCGPoint(_glfw.ns.cascadePoint)]);
        }
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

        if (wndconfig->resizable)
        {
            const NSWindowCollectionBehavior behavior =
                NSWindowCollectionBehaviorFullScreenPrimary |
                NSWindowCollectionBehaviorManaged;
            [window->ns.object setCollectionBehavior:behavior];
        }
        else
        {
            const NSWindowCollectionBehavior behavior =
                NSWindowCollectionBehaviorFullScreenNone;
            [window->ns.object setCollectionBehavior:behavior];
        }

        if (wndconfig->floating)
            [window->ns.object setLevel:NSFloatingWindowLevel];

        if (wndconfig->maximized)
            [window->ns.object zoom:nil];
    }

    if (strlen(wndconfig->ns.frameName))
        [window->ns.object setFrameAutosaveName:@(wndconfig->ns.frameName)];

    window->ns.view = [[GLFWContentView alloc] initWithGlfwWindow:window];
<<<<<<< HEAD
    window->ns.retina = wndconfig->ns.retina;
=======
    window->ns.scaleFramebuffer = wndconfig->scaleFramebuffer;
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    if (fbconfig->transparent)
    {
        [window->ns.object setOpaque:NO];
        [window->ns.object setHasShadow:NO];
        [window->ns.object setBackgroundColor:[NSColor clearColor]];
    }

    [window->ns.object setContentView:window->ns.view];
    [window->ns.object makeFirstResponder:window->ns.view];
    [window->ns.object setTitle:@(wndconfig->title)];
    [window->ns.object setDelegate:window->ns.delegate];
    [window->ns.object setAcceptsMouseMovedEvents:YES];
    [window->ns.object setRestorable:NO];

#if MAC_OS_X_VERSION_MAX_ALLOWED >= 101200
    if ([window->ns.object respondsToSelector:@selector(setTabbingMode:)])
        [window->ns.object setTabbingMode:NSWindowTabbingModeDisallowed];
#endif

<<<<<<< HEAD
    _glfwPlatformGetWindowSize(window, &window->ns.width, &window->ns.height);
    _glfwPlatformGetFramebufferSize(window, &window->ns.fbWidth, &window->ns.fbHeight);
=======
    _glfwGetWindowSizeCocoa(window, &window->ns.width, &window->ns.height);
    _glfwGetFramebufferSizeCocoa(window, &window->ns.fbWidth, &window->ns.fbHeight);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    return GLFW_TRUE;
}


//////////////////////////////////////////////////////////////////////////
//////                       GLFW internal API                      //////
//////////////////////////////////////////////////////////////////////////

// Transforms a y-coordinate between the CG display and NS screen spaces
//
<<<<<<< HEAD
float _glfwTransformYNS(float y)
=======
float _glfwTransformYCocoa(float y)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    return CGDisplayBounds(CGMainDisplayID()).size.height - y - 1;
}


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
int _glfwPlatformCreateWindow(_GLFWwindow* window,
                              const _GLFWwndconfig* wndconfig,
                              const _GLFWctxconfig* ctxconfig,
                              const _GLFWfbconfig* fbconfig)
{
    @autoreleasepool {

    if (!_glfw.ns.finishedLaunching)
        [NSApp run];

=======
GLFWbool _glfwCreateWindowCocoa(_GLFWwindow* window,
                                const _GLFWwndconfig* wndconfig,
                                const _GLFWctxconfig* ctxconfig,
                                const _GLFWfbconfig* fbconfig)
{
    @autoreleasepool {

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    if (!createNativeWindow(window, wndconfig, fbconfig))
        return GLFW_FALSE;

    if (ctxconfig->client != GLFW_NO_API)
    {
        if (ctxconfig->source == GLFW_NATIVE_CONTEXT_API)
        {
            if (!_glfwInitNSGL())
                return GLFW_FALSE;
            if (!_glfwCreateContextNSGL(window, ctxconfig, fbconfig))
                return GLFW_FALSE;
        }
        else if (ctxconfig->source == GLFW_EGL_CONTEXT_API)
        {
            // EGL implementation on macOS use CALayer* EGLNativeWindowType so we
            // need to get the layer for EGL window surface creation.
            [window->ns.view setWantsLayer:YES];
            window->ns.layer = [window->ns.view layer];

            if (!_glfwInitEGL())
                return GLFW_FALSE;
            if (!_glfwCreateContextEGL(window, ctxconfig, fbconfig))
                return GLFW_FALSE;
        }
        else if (ctxconfig->source == GLFW_OSMESA_CONTEXT_API)
        {
            if (!_glfwInitOSMesa())
                return GLFW_FALSE;
            if (!_glfwCreateContextOSMesa(window, ctxconfig, fbconfig))
                return GLFW_FALSE;
        }

        if (!_glfwRefreshContextAttribs(window, ctxconfig))
            return GLFW_FALSE;
    }

<<<<<<< HEAD
    if (window->monitor)
    {
        _glfwPlatformShowWindow(window);
        _glfwPlatformFocusWindow(window);
=======
    if (wndconfig->mousePassthrough)
        _glfwSetWindowMousePassthroughCocoa(window, GLFW_TRUE);

    if (window->monitor)
    {
        _glfwShowWindowCocoa(window);
        _glfwFocusWindowCocoa(window);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
        acquireMonitor(window);

        if (wndconfig->centerCursor)
            _glfwCenterCursorInContentArea(window);
    }
    else
    {
        if (wndconfig->visible)
        {
<<<<<<< HEAD
            _glfwPlatformShowWindow(window);
            if (wndconfig->focused)
                _glfwPlatformFocusWindow(window);
=======
            _glfwShowWindowCocoa(window);
            if (wndconfig->focused)
                _glfwFocusWindowCocoa(window);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
        }
    }

    return GLFW_TRUE;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformDestroyWindow(_GLFWwindow* window)
=======
void _glfwDestroyWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    if (_glfw.ns.disabledCursorWindow == window)
        _glfw.ns.disabledCursorWindow = NULL;

    [window->ns.object orderOut:nil];

    if (window->monitor)
        releaseMonitor(window);

    if (window->context.destroy)
        window->context.destroy(window);

    [window->ns.object setDelegate:nil];
    [window->ns.delegate release];
    window->ns.delegate = nil;

    [window->ns.view release];
    window->ns.view = nil;

    [window->ns.object close];
    window->ns.object = nil;

    // HACK: Allow Cocoa to catch up before returning
<<<<<<< HEAD
    _glfwPlatformPollEvents();
=======
    _glfwPollEventsCocoa();
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowTitle(_GLFWwindow* window, const char* title)
=======
void _glfwSetWindowTitleCocoa(_GLFWwindow* window, const char* title)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    NSString* string = @(title);
    [window->ns.object setTitle:string];
    // HACK: Set the miniwindow title explicitly as setTitle: doesn't update it
    //       if the window lacks NSWindowStyleMaskTitled
    [window->ns.object setMiniwindowTitle:string];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowIcon(_GLFWwindow* window,
                                int count, const GLFWimage* images)
{
    // Regular windows do not have icons
}

void _glfwPlatformGetWindowPos(_GLFWwindow* window, int* xpos, int* ypos)
=======
void _glfwSetWindowIconCocoa(_GLFWwindow* window,
                             int count, const GLFWimage* images)
{
    _glfwInputError(GLFW_FEATURE_UNAVAILABLE,
                    "Cocoa: Regular windows do not have icons on macOS");
}

void _glfwGetWindowPosCocoa(_GLFWwindow* window, int* xpos, int* ypos)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect contentRect =
        [window->ns.object contentRectForFrameRect:[window->ns.object frame]];

    if (xpos)
        *xpos = contentRect.origin.x;
    if (ypos)
<<<<<<< HEAD
        *ypos = _glfwTransformYNS(contentRect.origin.y + contentRect.size.height - 1);
=======
        *ypos = _glfwTransformYCocoa(contentRect.origin.y + contentRect.size.height - 1);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowPos(_GLFWwindow* window, int x, int y)
=======
void _glfwSetWindowPosCocoa(_GLFWwindow* window, int x, int y)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect contentRect = [window->ns.view frame];
<<<<<<< HEAD
    const NSRect dummyRect = NSMakeRect(x, _glfwTransformYNS(y + contentRect.size.height - 1), 0, 0);
=======
    const NSRect dummyRect = NSMakeRect(x, _glfwTransformYCocoa(y + contentRect.size.height - 1), 0, 0);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    const NSRect frameRect = [window->ns.object frameRectForContentRect:dummyRect];
    [window->ns.object setFrameOrigin:frameRect.origin];

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformGetWindowSize(_GLFWwindow* window, int* width, int* height)
=======
void _glfwGetWindowSizeCocoa(_GLFWwindow* window, int* width, int* height)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect contentRect = [window->ns.view frame];

    if (width)
        *width = contentRect.size.width;
    if (height)
        *height = contentRect.size.height;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowSize(_GLFWwindow* window, int width, int height)
=======
void _glfwSetWindowSizeCocoa(_GLFWwindow* window, int width, int height)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    if (window->monitor)
    {
        if (window->monitor->window == window)
            acquireMonitor(window);
    }
    else
    {
        NSRect contentRect =
            [window->ns.object contentRectForFrameRect:[window->ns.object frame]];
        contentRect.origin.y += contentRect.size.height - height;
        contentRect.size = NSMakeSize(width, height);
        [window->ns.object setFrame:[window->ns.object frameRectForContentRect:contentRect]
                            display:YES];
    }

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowSizeLimits(_GLFWwindow* window,
                                      int minwidth, int minheight,
                                      int maxwidth, int maxheight)
=======
void _glfwSetWindowSizeLimitsCocoa(_GLFWwindow* window,
                                   int minwidth, int minheight,
                                   int maxwidth, int maxheight)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    if (minwidth == GLFW_DONT_CARE || minheight == GLFW_DONT_CARE)
        [window->ns.object setContentMinSize:NSMakeSize(0, 0)];
    else
        [window->ns.object setContentMinSize:NSMakeSize(minwidth, minheight)];

    if (maxwidth == GLFW_DONT_CARE || maxheight == GLFW_DONT_CARE)
        [window->ns.object setContentMaxSize:NSMakeSize(DBL_MAX, DBL_MAX)];
    else
        [window->ns.object setContentMaxSize:NSMakeSize(maxwidth, maxheight)];

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowAspectRatio(_GLFWwindow* window, int numer, int denom)
=======
void _glfwSetWindowAspectRatioCocoa(_GLFWwindow* window, int numer, int denom)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    if (numer == GLFW_DONT_CARE || denom == GLFW_DONT_CARE)
        [window->ns.object setResizeIncrements:NSMakeSize(1.0, 1.0)];
    else
        [window->ns.object setContentAspectRatio:NSMakeSize(numer, denom)];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformGetFramebufferSize(_GLFWwindow* window, int* width, int* height)
=======
void _glfwGetFramebufferSizeCocoa(_GLFWwindow* window, int* width, int* height)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect contentRect = [window->ns.view frame];
    const NSRect fbRect = [window->ns.view convertRectToBacking:contentRect];

    if (width)
        *width = (int) fbRect.size.width;
    if (height)
        *height = (int) fbRect.size.height;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformGetWindowFrameSize(_GLFWwindow* window,
                                     int* left, int* top,
                                     int* right, int* bottom)
=======
void _glfwGetWindowFrameSizeCocoa(_GLFWwindow* window,
                                  int* left, int* top,
                                  int* right, int* bottom)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect contentRect = [window->ns.view frame];
    const NSRect frameRect = [window->ns.object frameRectForContentRect:contentRect];

    if (left)
        *left = contentRect.origin.x - frameRect.origin.x;
    if (top)
        *top = frameRect.origin.y + frameRect.size.height -
               contentRect.origin.y - contentRect.size.height;
    if (right)
        *right = frameRect.origin.x + frameRect.size.width -
                 contentRect.origin.x - contentRect.size.width;
    if (bottom)
        *bottom = contentRect.origin.y - frameRect.origin.y;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformGetWindowContentScale(_GLFWwindow* window,
                                        float* xscale, float* yscale)
=======
void _glfwGetWindowContentScaleCocoa(_GLFWwindow* window,
                                     float* xscale, float* yscale)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect points = [window->ns.view frame];
    const NSRect pixels = [window->ns.view convertRectToBacking:points];

    if (xscale)
        *xscale = (float) (pixels.size.width / points.size.width);
    if (yscale)
        *yscale = (float) (pixels.size.height / points.size.height);

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformIconifyWindow(_GLFWwindow* window)
=======
void _glfwIconifyWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    [window->ns.object miniaturize:nil];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformRestoreWindow(_GLFWwindow* window)
=======
void _glfwRestoreWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    if ([window->ns.object isMiniaturized])
        [window->ns.object deminiaturize:nil];
    else if ([window->ns.object isZoomed])
        [window->ns.object zoom:nil];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformMaximizeWindow(_GLFWwindow* window)
=======
void _glfwMaximizeWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    if (![window->ns.object isZoomed])
        [window->ns.object zoom:nil];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformShowWindow(_GLFWwindow* window)
=======
void _glfwShowWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    [window->ns.object orderFront:nil];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformHideWindow(_GLFWwindow* window)
=======
void _glfwHideWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    [window->ns.object orderOut:nil];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformRequestWindowAttention(_GLFWwindow* window)
=======
void _glfwRequestWindowAttentionCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    [NSApp requestUserAttention:NSInformationalRequest];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformFocusWindow(_GLFWwindow* window)
=======
void _glfwFocusWindowCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    // Make us the active application
    // HACK: This is here to prevent applications using only hidden windows from
    //       being activated, but should probably not be done every time any
    //       window is shown
    [NSApp activateIgnoringOtherApps:YES];
    [window->ns.object makeKeyAndOrderFront:nil];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowMonitor(_GLFWwindow* window,
                                   _GLFWmonitor* monitor,
                                   int xpos, int ypos,
                                   int width, int height,
                                   int refreshRate)
=======
void _glfwSetWindowMonitorCocoa(_GLFWwindow* window,
                                _GLFWmonitor* monitor,
                                int xpos, int ypos,
                                int width, int height,
                                int refreshRate)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    if (window->monitor == monitor)
    {
        if (monitor)
        {
            if (monitor->window == window)
                acquireMonitor(window);
        }
        else
        {
            const NSRect contentRect =
<<<<<<< HEAD
                NSMakeRect(xpos, _glfwTransformYNS(ypos + height - 1), width, height);
=======
                NSMakeRect(xpos, _glfwTransformYCocoa(ypos + height - 1), width, height);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
            const NSUInteger styleMask = [window->ns.object styleMask];
            const NSRect frameRect =
                [window->ns.object frameRectForContentRect:contentRect
                                                 styleMask:styleMask];

            [window->ns.object setFrame:frameRect display:YES];
        }

        return;
    }

    if (window->monitor)
        releaseMonitor(window);

    _glfwInputWindowMonitor(window, monitor);

    // HACK: Allow the state cached in Cocoa to catch up to reality
    // TODO: Solve this in a less terrible way
<<<<<<< HEAD
    _glfwPlatformPollEvents();
=======
    _glfwPollEventsCocoa();
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    NSUInteger styleMask = [window->ns.object styleMask];

    if (window->monitor)
    {
<<<<<<< HEAD
        styleMask &= ~(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable);
=======
        styleMask &= ~(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
        styleMask |= NSWindowStyleMaskBorderless;
    }
    else
    {
        if (window->decorated)
        {
            styleMask &= ~NSWindowStyleMaskBorderless;
            styleMask |= (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable);
        }

        if (window->resizable)
            styleMask |= NSWindowStyleMaskResizable;
        else
            styleMask &= ~NSWindowStyleMaskResizable;
    }

    [window->ns.object setStyleMask:styleMask];
    // HACK: Changing the style mask can cause the first responder to be cleared
    [window->ns.object makeFirstResponder:window->ns.view];

    if (window->monitor)
    {
        [window->ns.object setLevel:NSMainMenuWindowLevel + 1];
        [window->ns.object setHasShadow:NO];

        acquireMonitor(window);
    }
    else
    {
<<<<<<< HEAD
        NSRect contentRect = NSMakeRect(xpos, _glfwTransformYNS(ypos + height - 1),
=======
        NSRect contentRect = NSMakeRect(xpos, _glfwTransformYCocoa(ypos + height - 1),
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
                                        width, height);
        NSRect frameRect = [window->ns.object frameRectForContentRect:contentRect
                                                            styleMask:styleMask];
        [window->ns.object setFrame:frameRect display:YES];

        if (window->numer != GLFW_DONT_CARE &&
            window->denom != GLFW_DONT_CARE)
        {
            [window->ns.object setContentAspectRatio:NSMakeSize(window->numer,
                                                                window->denom)];
        }

        if (window->minwidth != GLFW_DONT_CARE &&
            window->minheight != GLFW_DONT_CARE)
        {
            [window->ns.object setContentMinSize:NSMakeSize(window->minwidth,
                                                            window->minheight)];
        }

        if (window->maxwidth != GLFW_DONT_CARE &&
            window->maxheight != GLFW_DONT_CARE)
        {
            [window->ns.object setContentMaxSize:NSMakeSize(window->maxwidth,
                                                            window->maxheight)];
        }

        if (window->floating)
            [window->ns.object setLevel:NSFloatingWindowLevel];
        else
            [window->ns.object setLevel:NSNormalWindowLevel];

        if (window->resizable)
        {
            const NSWindowCollectionBehavior behavior =
                NSWindowCollectionBehaviorFullScreenPrimary |
                NSWindowCollectionBehaviorManaged;
            [window->ns.object setCollectionBehavior:behavior];
        }
        else
        {
            const NSWindowCollectionBehavior behavior =
                NSWindowCollectionBehaviorFullScreenNone;
            [window->ns.object setCollectionBehavior:behavior];
        }

        [window->ns.object setHasShadow:YES];
        // HACK: Clearing NSWindowStyleMaskTitled resets and disables the window
        //       title property but the miniwindow title property is unaffected
        [window->ns.object setTitle:[window->ns.object miniwindowTitle]];
    }

    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformWindowFocused(_GLFWwindow* window)
=======
GLFWbool _glfwWindowFocusedCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    return [window->ns.object isKeyWindow];
    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformWindowIconified(_GLFWwindow* window)
=======
GLFWbool _glfwWindowIconifiedCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    return [window->ns.object isMiniaturized];
    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformWindowVisible(_GLFWwindow* window)
=======
GLFWbool _glfwWindowVisibleCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    return [window->ns.object isVisible];
    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformWindowMaximized(_GLFWwindow* window)
=======
GLFWbool _glfwWindowMaximizedCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    if (window->resizable)
        return [window->ns.object isZoomed];
    else
        return GLFW_FALSE;

    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformWindowHovered(_GLFWwindow* window)
=======
GLFWbool _glfwWindowHoveredCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSPoint point = [NSEvent mouseLocation];

    if ([NSWindow windowNumberAtPoint:point belowWindowWithWindowNumber:0] !=
        [window->ns.object windowNumber])
    {
        return GLFW_FALSE;
    }

    return NSMouseInRect(point,
        [window->ns.object convertRectToScreen:[window->ns.view frame]], NO);

    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformFramebufferTransparent(_GLFWwindow* window)
=======
GLFWbool _glfwFramebufferTransparentCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    return ![window->ns.object isOpaque] && ![window->ns.view isOpaque];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowResizable(_GLFWwindow* window, GLFWbool enabled)
=======
void _glfwSetWindowResizableCocoa(_GLFWwindow* window, GLFWbool enabled)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSUInteger styleMask = [window->ns.object styleMask];
    if (enabled)
    {
        [window->ns.object setStyleMask:(styleMask | NSWindowStyleMaskResizable)];
        const NSWindowCollectionBehavior behavior =
            NSWindowCollectionBehaviorFullScreenPrimary |
            NSWindowCollectionBehaviorManaged;
        [window->ns.object setCollectionBehavior:behavior];
    }
    else
    {
        [window->ns.object setStyleMask:(styleMask & ~NSWindowStyleMaskResizable)];
        const NSWindowCollectionBehavior behavior =
            NSWindowCollectionBehaviorFullScreenNone;
        [window->ns.object setCollectionBehavior:behavior];
    }

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowDecorated(_GLFWwindow* window, GLFWbool enabled)
=======
void _glfwSetWindowDecoratedCocoa(_GLFWwindow* window, GLFWbool enabled)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    NSUInteger styleMask = [window->ns.object styleMask];
    if (enabled)
    {
        styleMask |= (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable);
        styleMask &= ~NSWindowStyleMaskBorderless;
    }
    else
    {
        styleMask |= NSWindowStyleMaskBorderless;
        styleMask &= ~(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable);
    }

    [window->ns.object setStyleMask:styleMask];
    [window->ns.object makeFirstResponder:window->ns.view];

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowFloating(_GLFWwindow* window, GLFWbool enabled)
=======
void _glfwSetWindowFloatingCocoa(_GLFWwindow* window, GLFWbool enabled)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    if (enabled)
        [window->ns.object setLevel:NSFloatingWindowLevel];
    else
        [window->ns.object setLevel:NSNormalWindowLevel];
    } // autoreleasepool
}

<<<<<<< HEAD
float _glfwPlatformGetWindowOpacity(_GLFWwindow* window)
=======
void _glfwSetWindowMousePassthroughCocoa(_GLFWwindow* window, GLFWbool enabled)
{
    @autoreleasepool {
    [window->ns.object setIgnoresMouseEvents:enabled];
    }
}

float _glfwGetWindowOpacityCocoa(_GLFWwindow* window)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    return (float) [window->ns.object alphaValue];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetWindowOpacity(_GLFWwindow* window, float opacity)
=======
void _glfwSetWindowOpacityCocoa(_GLFWwindow* window, float opacity)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    [window->ns.object setAlphaValue:opacity];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetRawMouseMotion(_GLFWwindow *window, GLFWbool enabled)
{
}

GLFWbool _glfwPlatformRawMouseMotionSupported(void)
=======
void _glfwSetRawMouseMotionCocoa(_GLFWwindow *window, GLFWbool enabled)
{
    _glfwInputError(GLFW_FEATURE_UNIMPLEMENTED,
                    "Cocoa: Raw mouse motion not yet implemented");
}

GLFWbool _glfwRawMouseMotionSupportedCocoa(void)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    return GLFW_FALSE;
}

<<<<<<< HEAD
void _glfwPlatformPollEvents(void)
{
    @autoreleasepool {

    if (!_glfw.ns.finishedLaunching)
        [NSApp run];

=======
void _glfwPollEventsCocoa(void)
{
    @autoreleasepool {

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    for (;;)
    {
        NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                            untilDate:[NSDate distantPast]
                                               inMode:NSDefaultRunLoopMode
                                              dequeue:YES];
        if (event == nil)
            break;

        [NSApp sendEvent:event];
    }

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformWaitEvents(void)
{
    @autoreleasepool {

    if (!_glfw.ns.finishedLaunching)
        [NSApp run];

=======
void _glfwWaitEventsCocoa(void)
{
    @autoreleasepool {

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    // I wanted to pass NO to dequeue:, and rely on PollEvents to
    // dequeue and send.  For reasons not at all clear to me, passing
    // NO to dequeue: causes this method never to return.
    NSEvent *event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                        untilDate:[NSDate distantFuture]
                                           inMode:NSDefaultRunLoopMode
                                          dequeue:YES];
    [NSApp sendEvent:event];

<<<<<<< HEAD
    _glfwPlatformPollEvents();
=======
    _glfwPollEventsCocoa();
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformWaitEventsTimeout(double timeout)
{
    @autoreleasepool {

    if (!_glfw.ns.finishedLaunching)
        [NSApp run];

=======
void _glfwWaitEventsTimeoutCocoa(double timeout)
{
    @autoreleasepool {

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    NSDate* date = [NSDate dateWithTimeIntervalSinceNow:timeout];
    NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                        untilDate:date
                                           inMode:NSDefaultRunLoopMode
                                          dequeue:YES];
    if (event)
        [NSApp sendEvent:event];

<<<<<<< HEAD
    _glfwPlatformPollEvents();
=======
    _glfwPollEventsCocoa();
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformPostEmptyEvent(void)
{
    @autoreleasepool {

    if (!_glfw.ns.finishedLaunching)
        [NSApp run];

=======
void _glfwPostEmptyEventCocoa(void)
{
    @autoreleasepool {

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    NSEvent* event = [NSEvent otherEventWithType:NSEventTypeApplicationDefined
                                        location:NSMakePoint(0, 0)
                                   modifierFlags:0
                                       timestamp:0
                                    windowNumber:0
                                         context:nil
                                         subtype:0
                                           data1:0
                                           data2:0];
    [NSApp postEvent:event atStart:YES];

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformGetCursorPos(_GLFWwindow* window, double* xpos, double* ypos)
=======
void _glfwGetCursorPosCocoa(_GLFWwindow* window, double* xpos, double* ypos)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    const NSRect contentRect = [window->ns.view frame];
    // NOTE: The returned location uses base 0,1 not 0,0
    const NSPoint pos = [window->ns.object mouseLocationOutsideOfEventStream];

    if (xpos)
        *xpos = pos.x;
    if (ypos)
        *ypos = contentRect.size.height - pos.y;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetCursorPos(_GLFWwindow* window, double x, double y)
=======
void _glfwSetCursorPosCocoa(_GLFWwindow* window, double x, double y)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    updateCursorImage(window);

    const NSRect contentRect = [window->ns.view frame];
    // NOTE: The returned location uses base 0,1 not 0,0
    const NSPoint pos = [window->ns.object mouseLocationOutsideOfEventStream];

    window->ns.cursorWarpDeltaX += x - pos.x;
    window->ns.cursorWarpDeltaY += y - contentRect.size.height + pos.y;

    if (window->monitor)
    {
        CGDisplayMoveCursorToPoint(window->monitor->ns.displayID,
                                   CGPointMake(x, y));
    }
    else
    {
        const NSRect localRect = NSMakeRect(x, contentRect.size.height - y - 1, 0, 0);
        const NSRect globalRect = [window->ns.object convertRectToScreen:localRect];
        const NSPoint globalPoint = globalRect.origin;

        CGWarpMouseCursorPosition(CGPointMake(globalPoint.x,
<<<<<<< HEAD
                                              _glfwTransformYNS(globalPoint.y)));
=======
                                              _glfwTransformYCocoa(globalPoint.y)));
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    }

    // HACK: Calling this right after setting the cursor position prevents macOS
    //       from freezing the cursor for a fraction of a second afterwards
    if (window->cursorMode != GLFW_CURSOR_DISABLED)
        CGAssociateMouseAndMouseCursorPosition(true);

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetCursorMode(_GLFWwindow* window, int mode)
{
    @autoreleasepool {
    if (_glfwPlatformWindowFocused(window))
        updateCursorMode(window);
    } // autoreleasepool
}

const char* _glfwPlatformGetScancodeName(int scancode)
{
    @autoreleasepool {

    if (scancode < 0 || scancode > 0xff ||
        _glfw.ns.keycodes[scancode] == GLFW_KEY_UNKNOWN)
=======
void _glfwSetCursorModeCocoa(_GLFWwindow* window, int mode)
{
    @autoreleasepool {

    if (mode == GLFW_CURSOR_CAPTURED)
    {
        _glfwInputError(GLFW_FEATURE_UNIMPLEMENTED,
                        "Cocoa: Captured cursor mode not yet implemented");
    }

    if (_glfwWindowFocusedCocoa(window))
        updateCursorMode(window);

    } // autoreleasepool
}

const char* _glfwGetScancodeNameCocoa(int scancode)
{
    @autoreleasepool {

    if (scancode < 0 || scancode > 0xff)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    {
        _glfwInputError(GLFW_INVALID_VALUE, "Invalid scancode %i", scancode);
        return NULL;
    }

    const int key = _glfw.ns.keycodes[scancode];
<<<<<<< HEAD
=======
    if (key == GLFW_KEY_UNKNOWN)
        return NULL;
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

    UInt32 deadKeyState = 0;
    UniChar characters[4];
    UniCharCount characterCount = 0;

    if (UCKeyTranslate([(NSData*) _glfw.ns.unicodeData bytes],
                       scancode,
                       kUCKeyActionDisplay,
                       0,
                       LMGetKbdType(),
                       kUCKeyTranslateNoDeadKeysBit,
                       &deadKeyState,
                       sizeof(characters) / sizeof(characters[0]),
                       &characterCount,
                       characters) != noErr)
    {
        return NULL;
    }

    if (!characterCount)
        return NULL;

    CFStringRef string = CFStringCreateWithCharactersNoCopy(kCFAllocatorDefault,
                                                            characters,
                                                            characterCount,
                                                            kCFAllocatorNull);
    CFStringGetCString(string,
                       _glfw.ns.keynames[key],
                       sizeof(_glfw.ns.keynames[key]),
                       kCFStringEncodingUTF8);
    CFRelease(string);

    return _glfw.ns.keynames[key];

    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformGetKeyScancode(int key)
=======
int _glfwGetKeyScancodeCocoa(int key)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    return _glfw.ns.scancodes[key];
}

<<<<<<< HEAD
int _glfwPlatformCreateCursor(_GLFWcursor* cursor,
                              const GLFWimage* image,
                              int xhot, int yhot)
=======
GLFWbool _glfwCreateCursorCocoa(_GLFWcursor* cursor,
                                const GLFWimage* image,
                                int xhot, int yhot)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    NSImage* native;
    NSBitmapImageRep* rep;

    rep = [[NSBitmapImageRep alloc]
        initWithBitmapDataPlanes:NULL
                      pixelsWide:image->width
                      pixelsHigh:image->height
                   bitsPerSample:8
                 samplesPerPixel:4
                        hasAlpha:YES
                        isPlanar:NO
                  colorSpaceName:NSCalibratedRGBColorSpace
                    bitmapFormat:NSBitmapFormatAlphaNonpremultiplied
                     bytesPerRow:image->width * 4
                    bitsPerPixel:32];

    if (rep == nil)
        return GLFW_FALSE;

    memcpy([rep bitmapData], image->pixels, image->width * image->height * 4);

    native = [[NSImage alloc] initWithSize:NSMakeSize(image->width, image->height)];
    [native addRepresentation:rep];

    cursor->ns.object = [[NSCursor alloc] initWithImage:native
                                                hotSpot:NSMakePoint(xhot, yhot)];

    [native release];
    [rep release];

    if (cursor->ns.object == nil)
        return GLFW_FALSE;

    return GLFW_TRUE;

    } // autoreleasepool
}

<<<<<<< HEAD
int _glfwPlatformCreateStandardCursor(_GLFWcursor* cursor, int shape)
{
    @autoreleasepool {

    if (shape == GLFW_ARROW_CURSOR)
        cursor->ns.object = [NSCursor arrowCursor];
    else if (shape == GLFW_IBEAM_CURSOR)
        cursor->ns.object = [NSCursor IBeamCursor];
    else if (shape == GLFW_CROSSHAIR_CURSOR)
        cursor->ns.object = [NSCursor crosshairCursor];
    else if (shape == GLFW_HAND_CURSOR)
        cursor->ns.object = [NSCursor pointingHandCursor];
    else if (shape == GLFW_HRESIZE_CURSOR)
        cursor->ns.object = [NSCursor resizeLeftRightCursor];
    else if (shape == GLFW_VRESIZE_CURSOR)
        cursor->ns.object = [NSCursor resizeUpDownCursor];

    if (!cursor->ns.object)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to retrieve standard cursor");
=======
GLFWbool _glfwCreateStandardCursorCocoa(_GLFWcursor* cursor, int shape)
{
    @autoreleasepool {

    SEL cursorSelector = NULL;

    // HACK: Try to use a private message
    switch (shape)
    {
        case GLFW_RESIZE_EW_CURSOR:
            cursorSelector = NSSelectorFromString(@"_windowResizeEastWestCursor");
            break;
        case GLFW_RESIZE_NS_CURSOR:
            cursorSelector = NSSelectorFromString(@"_windowResizeNorthSouthCursor");
            break;
        case GLFW_RESIZE_NWSE_CURSOR:
            cursorSelector = NSSelectorFromString(@"_windowResizeNorthWestSouthEastCursor");
            break;
        case GLFW_RESIZE_NESW_CURSOR:
            cursorSelector = NSSelectorFromString(@"_windowResizeNorthEastSouthWestCursor");
            break;
    }

    if (cursorSelector && [NSCursor respondsToSelector:cursorSelector])
    {
        id object = [NSCursor performSelector:cursorSelector];
        if ([object isKindOfClass:[NSCursor class]])
            cursor->ns.object = object;
    }

    if (!cursor->ns.object)
    {
        switch (shape)
        {
            case GLFW_ARROW_CURSOR:
                cursor->ns.object = [NSCursor arrowCursor];
                break;
            case GLFW_IBEAM_CURSOR:
                cursor->ns.object = [NSCursor IBeamCursor];
                break;
            case GLFW_CROSSHAIR_CURSOR:
                cursor->ns.object = [NSCursor crosshairCursor];
                break;
            case GLFW_POINTING_HAND_CURSOR:
                cursor->ns.object = [NSCursor pointingHandCursor];
                break;
            case GLFW_RESIZE_EW_CURSOR:
                cursor->ns.object = [NSCursor resizeLeftRightCursor];
                break;
            case GLFW_RESIZE_NS_CURSOR:
                cursor->ns.object = [NSCursor resizeUpDownCursor];
                break;
            case GLFW_RESIZE_ALL_CURSOR:
                cursor->ns.object = [NSCursor closedHandCursor];
                break;
            case GLFW_NOT_ALLOWED_CURSOR:
                cursor->ns.object = [NSCursor operationNotAllowedCursor];
                break;
        }
    }

    if (!cursor->ns.object)
    {
        _glfwInputError(GLFW_CURSOR_UNAVAILABLE,
                        "Cocoa: Standard cursor shape unavailable");
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
        return GLFW_FALSE;
    }

    [cursor->ns.object retain];
    return GLFW_TRUE;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformDestroyCursor(_GLFWcursor* cursor)
=======
void _glfwDestroyCursorCocoa(_GLFWcursor* cursor)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    if (cursor->ns.object)
        [(NSCursor*) cursor->ns.object release];
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetCursor(_GLFWwindow* window, _GLFWcursor* cursor)
=======
void _glfwSetCursorCocoa(_GLFWwindow* window, _GLFWcursor* cursor)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    if (cursorInContentArea(window))
        updateCursorImage(window);
    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformSetClipboardString(const char* string)
=======
void _glfwSetClipboardStringCocoa(const char* string)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {
    NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];
    [pasteboard declareTypes:@[NSPasteboardTypeString] owner:nil];
    [pasteboard setString:@(string) forType:NSPasteboardTypeString];
    } // autoreleasepool
}

<<<<<<< HEAD
const char* _glfwPlatformGetClipboardString(void)
=======
const char* _glfwGetClipboardStringCocoa(void)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

    NSPasteboard* pasteboard = [NSPasteboard generalPasteboard];

    if (![[pasteboard types] containsObject:NSPasteboardTypeString])
    {
        _glfwInputError(GLFW_FORMAT_UNAVAILABLE,
                        "Cocoa: Failed to retrieve string from pasteboard");
        return NULL;
    }

    NSString* object = [pasteboard stringForType:NSPasteboardTypeString];
    if (!object)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to retrieve object from pasteboard");
        return NULL;
    }

<<<<<<< HEAD
    free(_glfw.ns.clipboardString);
=======
    _glfw_free(_glfw.ns.clipboardString);
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
    _glfw.ns.clipboardString = _glfw_strdup([object UTF8String]);

    return _glfw.ns.clipboardString;

    } // autoreleasepool
}

<<<<<<< HEAD
void _glfwPlatformGetRequiredInstanceExtensions(char** extensions)
=======
EGLenum _glfwGetEGLPlatformCocoa(EGLint** attribs)
{
    if (_glfw.egl.ANGLE_platform_angle)
    {
        int type = 0;

        if (_glfw.egl.ANGLE_platform_angle_opengl)
        {
            if (_glfw.hints.init.angleType == GLFW_ANGLE_PLATFORM_TYPE_OPENGL)
                type = EGL_PLATFORM_ANGLE_TYPE_OPENGL_ANGLE;
        }

        if (_glfw.egl.ANGLE_platform_angle_metal)
        {
            if (_glfw.hints.init.angleType == GLFW_ANGLE_PLATFORM_TYPE_METAL)
                type = EGL_PLATFORM_ANGLE_TYPE_METAL_ANGLE;
        }

        if (type)
        {
            *attribs = _glfw_calloc(3, sizeof(EGLint));
            (*attribs)[0] = EGL_PLATFORM_ANGLE_TYPE_ANGLE;
            (*attribs)[1] = type;
            (*attribs)[2] = EGL_NONE;
            return EGL_PLATFORM_ANGLE_ANGLE;
        }
    }

    return 0;
}

EGLNativeDisplayType _glfwGetEGLNativeDisplayCocoa(void)
{
    return EGL_DEFAULT_DISPLAY;
}

EGLNativeWindowType _glfwGetEGLNativeWindowCocoa(_GLFWwindow* window)
{
    return window->ns.layer;
}

void _glfwGetRequiredInstanceExtensionsCocoa(char** extensions)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    if (_glfw.vk.KHR_surface && _glfw.vk.EXT_metal_surface)
    {
        extensions[0] = "VK_KHR_surface";
        extensions[1] = "VK_EXT_metal_surface";
    }
    else if (_glfw.vk.KHR_surface && _glfw.vk.MVK_macos_surface)
    {
        extensions[0] = "VK_KHR_surface";
        extensions[1] = "VK_MVK_macos_surface";
    }
}

<<<<<<< HEAD
int _glfwPlatformGetPhysicalDevicePresentationSupport(VkInstance instance,
                                                      VkPhysicalDevice device,
                                                      uint32_t queuefamily)
=======
GLFWbool _glfwGetPhysicalDevicePresentationSupportCocoa(VkInstance instance,
                                                        VkPhysicalDevice device,
                                                        uint32_t queuefamily)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    return GLFW_TRUE;
}

<<<<<<< HEAD
VkResult _glfwPlatformCreateWindowSurface(VkInstance instance,
                                          _GLFWwindow* window,
                                          const VkAllocationCallbacks* allocator,
                                          VkSurfaceKHR* surface)
=======
VkResult _glfwCreateWindowSurfaceCocoa(VkInstance instance,
                                       _GLFWwindow* window,
                                       const VkAllocationCallbacks* allocator,
                                       VkSurfaceKHR* surface)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    @autoreleasepool {

#if MAC_OS_X_VERSION_MAX_ALLOWED >= 101100
    // HACK: Dynamically load Core Animation to avoid adding an extra
    //       dependency for the majority who don't use MoltenVK
    NSBundle* bundle = [NSBundle bundleWithPath:@"/System/Library/Frameworks/QuartzCore.framework"];
    if (!bundle)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to find QuartzCore.framework");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    // NOTE: Create the layer here as makeBackingLayer should not return nil
    window->ns.layer = [[bundle classNamed:@"CAMetalLayer"] layer];
    if (!window->ns.layer)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to create layer for view");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

<<<<<<< HEAD
    if (window->ns.retina)
=======
    if (window->ns.scaleFramebuffer)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
        [window->ns.layer setContentsScale:[window->ns.object backingScaleFactor]];

    [window->ns.view setLayer:window->ns.layer];
    [window->ns.view setWantsLayer:YES];

    VkResult err;

    if (_glfw.vk.EXT_metal_surface)
    {
        VkMetalSurfaceCreateInfoEXT sci;

        PFN_vkCreateMetalSurfaceEXT vkCreateMetalSurfaceEXT;
        vkCreateMetalSurfaceEXT = (PFN_vkCreateMetalSurfaceEXT)
            vkGetInstanceProcAddr(instance, "vkCreateMetalSurfaceEXT");
        if (!vkCreateMetalSurfaceEXT)
        {
            _glfwInputError(GLFW_API_UNAVAILABLE,
                            "Cocoa: Vulkan instance missing VK_EXT_metal_surface extension");
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }

        memset(&sci, 0, sizeof(sci));
        sci.sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
        sci.pLayer = window->ns.layer;

        err = vkCreateMetalSurfaceEXT(instance, &sci, allocator, surface);
    }
    else
    {
        VkMacOSSurfaceCreateInfoMVK sci;

        PFN_vkCreateMacOSSurfaceMVK vkCreateMacOSSurfaceMVK;
        vkCreateMacOSSurfaceMVK = (PFN_vkCreateMacOSSurfaceMVK)
            vkGetInstanceProcAddr(instance, "vkCreateMacOSSurfaceMVK");
        if (!vkCreateMacOSSurfaceMVK)
        {
            _glfwInputError(GLFW_API_UNAVAILABLE,
                            "Cocoa: Vulkan instance missing VK_MVK_macos_surface extension");
            return VK_ERROR_EXTENSION_NOT_PRESENT;
        }

        memset(&sci, 0, sizeof(sci));
        sci.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
        sci.pView = window->ns.view;

        err = vkCreateMacOSSurfaceMVK(instance, &sci, allocator, surface);
    }

    if (err)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Cocoa: Failed to create Vulkan surface: %s",
                        _glfwGetVulkanResultString(err));
    }

    return err;
#else
    return VK_ERROR_EXTENSION_NOT_PRESENT;
#endif

    } // autoreleasepool
}


//////////////////////////////////////////////////////////////////////////
//////                        GLFW native API                       //////
//////////////////////////////////////////////////////////////////////////

GLFWAPI id glfwGetCocoaWindow(GLFWwindow* handle)
{
    _GLFWwindow* window = (_GLFWwindow*) handle;
    _GLFW_REQUIRE_INIT_OR_RETURN(nil);
<<<<<<< HEAD
    return window->ns.object;
}

=======

    if (_glfw.platform.platformID != GLFW_PLATFORM_COCOA)
    {
        _glfwInputError(GLFW_PLATFORM_UNAVAILABLE,
                        "Cocoa: Platform not initialized");
        return nil;
    }

    return window->ns.object;
}

GLFWAPI id glfwGetCocoaView(GLFWwindow* handle)
{
    _GLFWwindow* window = (_GLFWwindow*) handle;
    _GLFW_REQUIRE_INIT_OR_RETURN(nil);

    if (_glfw.platform.platformID != GLFW_PLATFORM_COCOA)
    {
        _glfwInputError(GLFW_PLATFORM_UNAVAILABLE,
                        "Cocoa: Platform not initialized");
        return nil;
    }

    return window->ns.view;
}

#endif // _GLFW_COCOA

>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
