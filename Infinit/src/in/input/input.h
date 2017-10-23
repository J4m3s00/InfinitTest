#pragma once

#include <Infinit.h>
#include <in\maths\vec2.h>

#define INPUT_MAX_BUTTONS 16
#define INPUT_MAX_KEYS 512

#define IN_KEY_UNKNOWN            -1

/* Printable keys */
#define IN_KEY_SPACE              32
#define IN_KEY_APOSTROPHE         39  /* ' */
#define IN_KEY_COMMA              44  /* , */
#define IN_KEY_MINUS              45  /* - */
#define IN_KEY_PERIOD             46  /* . */
#define IN_KEY_SLASH              47  /* / */
#define IN_KEY_0                  48
#define IN_KEY_1                  49
#define IN_KEY_2                  50
#define IN_KEY_3                  51
#define IN_KEY_4                  52
#define IN_KEY_5                  53
#define IN_KEY_6                  54
#define IN_KEY_7                  55
#define IN_KEY_8                  56
#define IN_KEY_9                  57
#define IN_KEY_SEMICOLON          59  /* ; */
#define IN_KEY_EQUAL              61  /* = */
#define IN_KEY_A                  65
#define IN_KEY_B                  66
#define IN_KEY_C                  67
#define IN_KEY_D                  68
#define IN_KEY_E                  69
#define IN_KEY_F                  70
#define IN_KEY_G                  71
#define IN_KEY_H                  72
#define IN_KEY_I                  73
#define IN_KEY_J                  74
#define IN_KEY_K                  75
#define IN_KEY_L                  76
#define IN_KEY_M                  77
#define IN_KEY_N                  78
#define IN_KEY_O                  79
#define IN_KEY_P                  80
#define IN_KEY_Q                  81
#define IN_KEY_R                  82
#define IN_KEY_S                  83
#define IN_KEY_T                  84
#define IN_KEY_U                  85
#define IN_KEY_V                  86
#define IN_KEY_W                  87
#define IN_KEY_X                  88
#define IN_KEY_Y                  89
#define IN_KEY_Z                  90
#define IN_KEY_LEFT_BRACKET       91  /* [ */
#define IN_KEY_BACKSLASH          92  /* \ */
#define IN_KEY_RIGHT_BRACKET      93  /* ] */
#define IN_KEY_GRAVE_ACCENT       96  /* ` */
#define IN_KEY_WORLD_1            161 /* non-US #1 */
#define IN_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define IN_KEY_ESCAPE             256
#define IN_KEY_ENTER              257
#define IN_KEY_TAB                258
#define IN_KEY_BACKSPACE          259
#define IN_KEY_INSERT             260
#define IN_KEY_DELETE             261
#define IN_KEY_RIGHT              262
#define IN_KEY_LEFT               263
#define IN_KEY_DOWN               264
#define IN_KEY_UP                 265
#define IN_KEY_PAGE_UP            266
#define IN_KEY_PAGE_DOWN          267
#define IN_KEY_HOME               268
#define IN_KEY_END                269
#define IN_KEY_CAPS_LOCK          280
#define IN_KEY_SCROLL_LOCK        281
#define IN_KEY_NUM_LOCK           282
#define IN_KEY_PRINT_SCREEN       283
#define IN_KEY_PAUSE              284
#define IN_KEY_F1                 290
#define IN_KEY_F2                 291
#define IN_KEY_F3                 292
#define IN_KEY_F4                 293
#define IN_KEY_F5                 294
#define IN_KEY_F6                 295
#define IN_KEY_F7                 296
#define IN_KEY_F8                 297
#define IN_KEY_F9                 298
#define IN_KEY_F10                299
#define IN_KEY_F11                300
#define IN_KEY_F12                301
#define IN_KEY_F13                302
#define IN_KEY_F14                303
#define IN_KEY_F15                304
#define IN_KEY_F16                305
#define IN_KEY_F17                306
#define IN_KEY_F18                307
#define IN_KEY_F19                308
#define IN_KEY_F20                309
#define IN_KEY_F21                310
#define IN_KEY_F22                311
#define IN_KEY_F23                312
#define IN_KEY_F24                313
#define IN_KEY_F25                314
#define IN_KEY_KP_0               320
#define IN_KEY_KP_1               321
#define IN_KEY_KP_2               322
#define IN_KEY_KP_3               323
#define IN_KEY_KP_4               324
#define IN_KEY_KP_5               325
#define IN_KEY_KP_6               326
#define IN_KEY_KP_7               327
#define IN_KEY_KP_8               328
#define IN_KEY_KP_9               329
#define IN_KEY_KP_DECIMAL         330
#define IN_KEY_KP_DIVIDE          331
#define IN_KEY_KP_MULTIPLY        332
#define IN_KEY_KP_SUBTRACT        333
#define IN_KEY_KP_ADD             334
#define IN_KEY_KP_ENTER           335
#define IN_KEY_KP_EQUAL           336
#define IN_KEY_LEFT_SHIFT         340
#define IN_KEY_LEFT_CONTROL       341
#define IN_KEY_LEFT_ALT           342
#define IN_KEY_LEFT_SUPER         343
#define IN_KEY_RIGHT_SHIFT        344
#define IN_KEY_RIGHT_CONTROL      345
#define IN_KEY_RIGHT_ALT          346
#define IN_KEY_RIGHT_SUPER        347
#define IN_KEY_MENU               348

#define IN_KEY_LAST               IN_KEY_MENU

/*! @} */

/*! @defgroup mods Modifier key flags
*
*  See [key input](@ref input_key) for how these are used.
*
*  @ingroup input
*  @{ */

/*! @brief If this bit is set one or more Shift keys were held down.
*/
#define IN_MOD_SHIFT           0x0001
/*! @brief If this bit is set one or more Control keys were held down.
*/
#define IN_MOD_CONTROL         0x0002
/*! @brief If this bit is set one or more Alt keys were held down.
*/
#define IN_MOD_ALT             0x0004
/*! @brief If this bit is set one or more Super keys were held down.
*/
#define IN_MOD_SUPER           0x0008

/*! @} */

/*! @defgroup buttons Mouse buttons
*
*  See [mouse button input](@ref input_mouse_button) for how these are used.
*
*  @ingroup input
*  @{ */
#define IN_MOUSE_BUTTON_1         0
#define IN_MOUSE_BUTTON_2         1
#define IN_MOUSE_BUTTON_3         2
#define IN_MOUSE_BUTTON_4         3
#define IN_MOUSE_BUTTON_5         4
#define IN_MOUSE_BUTTON_6         5
#define IN_MOUSE_BUTTON_7         6
#define IN_MOUSE_BUTTON_8         7
#define IN_MOUSE_BUTTON_LAST      IN_MOUSE_BUTTON_8
#define IN_MOUSE_BUTTON_LEFT      IN_MOUSE_BUTTON_1
#define IN_MOUSE_BUTTON_RIGHT     IN_MOUSE_BUTTON_2
#define IN_MOUSE_BUTTON_MIDDLE    IN_MOUSE_BUTTON_3


namespace in {

	namespace graphics {
		class Window;
	}

	class Input
	{
	private:
		static graphics::Window* m_Window;

		static INString m_TypedText;

		static float m_MouseWheelAmmount;

		static INInt m_MouseX;
		static INInt m_MouseY;

		static bool m_KeysRepeated[INPUT_MAX_KEYS];
		static bool m_KeysPressed[INPUT_MAX_KEYS];
		static bool m_KeysReleased[INPUT_MAX_KEYS];
		static bool m_KeysTyped[INPUT_MAX_KEYS];

		static bool m_ButtonsRepeated[INPUT_MAX_BUTTONS];
		static bool m_ButtonsPressed[INPUT_MAX_BUTTONS];
		static bool m_ButtonsReleased[INPUT_MAX_BUTTONS];
	public:
		static void Update();

		static maths::vec2& GetMousePosition() { return maths::vec2((float) m_MouseX, (float) m_MouseY); }
		static INInt GetMouseX() { return m_MouseX; }
		static INInt GetMouseY() { return m_MouseY; }
		static float GetOrthographicsMouseX(float width);
		static float GetOrthographicsMouseY(float height);

		static const INString& GetTypedText() { return m_TypedText; }

		//Gettinfinitg the mouse and keyboard states
		static bool IsKeyPressed(INUint key);
		static bool IsKeyDown(INUint key);
		static bool IsKeyTyped(INUint key);

		static bool IsMousePressed(INUint key);
		static bool IsMouseDown(INUint key);

		static float GetMouseWheel() { return m_MouseWheelAmmount; }

		static void SetMouseHidden(INUint cursorState);

		//setting the buttons should not happen outside the enigne
		static void SetKeyPressed(INUint key, bool state) { m_KeysPressed[key] = state; }
		static void SetKeyDown(INUint key, bool state) { m_KeysRepeated[key] = state; }
		static void SetKeyTyped(INUint key, bool state) { m_KeysTyped[key] = state; }

		static void SetMousePressed(INUint key, bool state) { m_ButtonsPressed[key] = state; }
		static void SetMouseDown(INUint key, bool state) { m_ButtonsRepeated[key] = state; }

		static void SetMousePosition(double x, double y) { m_MouseX = (INInt) x; m_MouseY = (INInt) y; }
		static void SetWindow(graphics::Window* window) { m_Window = window; }

		static void SetMouseWheelAmmount(const float& ammt) { m_MouseWheelAmmount = ammt; }

		static void SetTypedText(const INString& string);

		static void AppendTypedText(const INString& string);
		static void AppendTypedText(const char* string);
		static void AppendTypedText(char c);
	};

}