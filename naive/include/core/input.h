#ifndef __NV_INPUT_H__
#define __NV_INPUT_H__ 1

#include "stdint.h"
#include "glm/glm/vec2.hpp"

namespace naive {

  class Input {

  public:

    // From glfw3.h.
    enum class KeyCode : uint16_t {

      /* Printable keys */
      kKeyCode_SPACE              = 32,
      kKeyCode_APOSTROPHE         = 39, /* ' */
      kKeyCode_COMMA              = 44, /* , */
      kKeyCode_MINUS              = 45, /* - */
      kKeyCode_PERIOD             = 46, /* . */
      kKeyCode_SLASH              = 47, /* / */
      kKeyCode_0                  = 48,
      kKeyCode_1                  = 49,
      kKeyCode_2                  = 50,
      kKeyCode_3                  = 51,
      kKeyCode_4                  = 52,
      kKeyCode_5                  = 53,
      kKeyCode_6                  = 54,
      kKeyCode_7                  = 55,
      kKeyCode_8                  = 56,
      kKeyCode_9                  = 57,
      kKeyCode_SEMICOLON          = 59, /* ; */
      kKeyCode_EQUAL              = 61, /* = */
      kKeyCode_A                  = 65,
      kKeyCode_B                  = 66,
      kKeyCode_C                  = 67,
      kKeyCode_D                  = 68,
      kKeyCode_E                  = 69,
      kKeyCode_F                  = 70,
      kKeyCode_G                  = 71,
      kKeyCode_H                  = 72,
      kKeyCode_I                  = 73,
      kKeyCode_J                  = 74,
      kKeyCode_K                  = 75,
      kKeyCode_L                  = 76,
      kKeyCode_M                  = 77,
      kKeyCode_N                  = 78,
      kKeyCode_O                  = 79,
      kKeyCode_P                  = 80,
      kKeyCode_Q                  = 81,
      kKeyCode_R                  = 82,
      kKeyCode_S                  = 83,
      kKeyCode_T                  = 84,
      kKeyCode_U                  = 85,
      kKeyCode_V                  = 86,
      kKeyCode_W                  = 87,
      kKeyCode_X                  = 88,
      kKeyCode_Y                  = 89,
      kKeyCode_Z                  = 90,
      kKeyCode_LEFT_BRACKET       = 91, /* [ */
      kKeyCode_BACKSLASH          = 92, /* \ */
      kKeyCode_RIGHT_BRACKET      = 93, /* ] */
      kKeyCode_GRAVE_ACCENT       = 96, /* ` */
      kKeyCode_WORLD_1            = 161, /* non-US #1 */
      kKeyCode_WORLD_2            = 162, /* non-US #2 */

      /* Function keys */
      kKeyCode_ESCAPE             = 256,
      kKeyCode_ENTER              = 257,
      kKeyCode_TAB                = 258,
      kKeyCode_BACKSPACE          = 259,
      kKeyCode_INSERT             = 260,
      kKeyCode_DELETE             = 261,
      kKeyCode_RIGHT              = 262,
      kKeyCode_LEFT               = 263,
      kKeyCode_DOWN               = 264,
      kKeyCode_UP                 = 265,
      kKeyCode_PAGE_UP            = 266,
      kKeyCode_PAGE_DOWN          = 267,
      kKeyCode_HOME               = 268,
      kKeyCode_END                = 269,
      kKeyCode_CAPS_LOCK          = 280,
      kKeyCode_SCROLL_LOCK        = 281,
      kKeyCode_NUM_LOCK           = 282,
      kKeyCode_PRINT_SCREEN       = 283,
      kKeyCode_PAUSE              = 284,
      kKeyCode_F1                 = 290,
      kKeyCode_F2                 = 291,
      kKeyCode_F3                 = 292,
      kKeyCode_F4                 = 293,
      kKeyCode_F5                 = 294,
      kKeyCode_F6                 = 295,
      kKeyCode_F7                 = 296,
      kKeyCode_F8                 = 297,
      kKeyCode_F9                 = 298,
      kKeyCode_F10                = 299,
      kKeyCode_F11                = 300,
      kKeyCode_F12                = 301,
      kKeyCode_F13                = 302,
      kKeyCode_F14                = 303,
      kKeyCode_F15                = 304,
      kKeyCode_F16                = 305,
      kKeyCode_F17                = 306,
      kKeyCode_F18                = 307,
      kKeyCode_F19                = 308,
      kKeyCode_F20                = 309,
      kKeyCode_F21                = 310,
      kKeyCode_F22                = 311,
      kKeyCode_F23                = 312,
      kKeyCode_F24                = 313,
      kKeyCode_F25                = 314,
      kKeyCode_KP_0               = 320,
      kKeyCode_KP_1               = 321,
      kKeyCode_KP_2               = 322,
      kKeyCode_KP_3               = 323,
      kKeyCode_KP_4               = 324,
      kKeyCode_KP_5               = 325,
      kKeyCode_KP_6               = 326,
      kKeyCode_KP_7               = 327,
      kKeyCode_KP_8               = 328,
      kKeyCode_KP_9               = 329,
      kKeyCode_KP_DECIMAL         = 330,
      kKeyCode_KP_DIVIDE          = 331,
      kKeyCode_KP_MULTIPLY        = 332,
      kKeyCode_KP_SUBTRACT        = 333,
      kKeyCode_KP_ADD             = 334,
      kKeyCode_KP_ENTER           = 335,
      kKeyCode_KP_EQUAL           = 336,
      kKeyCode_LEFT_SHIFT         = 340,
      kKeyCode_LEFT_CONTROL       = 341,
      kKeyCode_LEFT_ALT           = 342,
      kKeyCode_LEFT_SUPER         = 343,
      kKeyCode_RIGHT_SHIFT        = 344,
      kKeyCode_RIGHT_CONTROL      = 345,
      kKeyCode_RIGHT_ALT          = 346,
      kKeyCode_RIGHT_SUPER        = 347,
      kKeyCode_MENU               = 348

    };

    enum class MouseButton : uint16_t {

      kMouseButton_BUTTON_1         = 0,
      kMouseButton_BUTTON_2         = 1,
      kMouseButton_BUTTON_3         = 2,
      kMouseButton_BUTTON_4         = 3,
      kMouseButton_BUTTON_5         = 4,
      kMouseButton_BUTTON_6         = 5,
      kMouseButton_BUTTON_7         = 6,
      kMouseButton_BUTTON_8         = 7,
      kMouseButton_BUTTON_LEFT      = kMouseButton_BUTTON_1,
      kMouseButton_BUTTON_RIGHT     = kMouseButton_BUTTON_2,
      kMouseButton_BUTTON_MIDDLE    = kMouseButton_BUTTON_3

    };

    static bool isKeyDown(const KeyCode key_code);
    static bool isKeyPressed(const KeyCode key_code);
    static bool isKeyUp(const KeyCode key_code);

    static bool isMouseButtonDown(const MouseButton mouse_button);
    static bool isMouseButtonPressed(const MouseButton mouse_button);
    static bool isMouseButtonUp(const MouseButton mouse_button);

    static glm::vec2 getMousePosition();
    static float getMouseX();
    static float getMouseY();

  };

}

#endif // !__NV_INPUT_H__
