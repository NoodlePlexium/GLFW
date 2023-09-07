#ifndef INPUT_H
#define INPUT_H

#include <GLFW/glfw3.h>
#include <unordered_map>
#include <thread>

class InputSystem {
public:

	// Constructor
    InputSystem (GLFWwindow* _window) : window(_window) {}

    enum class KeyCode {
        Unknown = -1,
        Apostrophe = GLFW_KEY_APOSTROPHE,
        Semicolon = GLFW_KEY_SEMICOLON,
        Comma = GLFW_KEY_COMMA,
        Period = GLFW_KEY_PERIOD,
        Num0 = GLFW_KEY_0,
        Num1 = GLFW_KEY_1,
        Num2 = GLFW_KEY_2,
        Num3 = GLFW_KEY_3,
        Num4 = GLFW_KEY_4,
        Num5 = GLFW_KEY_5,
        Num6 = GLFW_KEY_6,
        Num7 = GLFW_KEY_7,
        Num8 = GLFW_KEY_8,
        Num9 = GLFW_KEY_9,
        Plus = GLFW_KEY_KP_ADD,
        Minus = GLFW_KEY_MINUS,
        Equal = GLFW_KEY_EQUAL,
        Slash = GLFW_KEY_SLASH,
        A = GLFW_KEY_A,
        B = GLFW_KEY_B,
        C = GLFW_KEY_C,
        D = GLFW_KEY_D,
        E = GLFW_KEY_E,
        F = GLFW_KEY_F,
        G = GLFW_KEY_G,
        H = GLFW_KEY_H,
        I = GLFW_KEY_I,
        J = GLFW_KEY_J,
        K = GLFW_KEY_K,
        L = GLFW_KEY_L,
        M = GLFW_KEY_M,
        N = GLFW_KEY_N,
        O = GLFW_KEY_O,
        P = GLFW_KEY_P,
        Q = GLFW_KEY_Q,
        R = GLFW_KEY_R,
        S = GLFW_KEY_S,
        T = GLFW_KEY_T,
        U = GLFW_KEY_U,
        V = GLFW_KEY_V,
        W = GLFW_KEY_W,
        X = GLFW_KEY_X,
        Y = GLFW_KEY_Y,
        Z = GLFW_KEY_Z,
        Space = GLFW_KEY_SPACE,
        LeftShift = GLFW_KEY_LEFT_SHIFT,
        RightShift = GLFW_KEY_RIGHT_SHIFT,
        LeftControl = GLFW_KEY_LEFT_CONTROL,
        RightControl = GLFW_KEY_RIGHT_CONTROL,
        LeftAlt = GLFW_KEY_LEFT_ALT,
        RightAlt = GLFW_KEY_RIGHT_ALT,
        Tab = GLFW_KEY_TAB,
        Escape = GLFW_KEY_ESCAPE,
        ArrowLeft = GLFW_KEY_LEFT,
        ArrowRight = GLFW_KEY_RIGHT,
        ArrowUp = GLFW_KEY_UP,
        ArrowDown = GLFW_KEY_DOWN
    };

    bool GetKeyDown(int KeyCode)
    {
    	return keyStates[KeyCode] == 1;
    }

    bool GetKeyUp(int KeyCode)
    {
    	return keyStates[KeyCode] == 3;
    }

    bool GetKey(int KeyCode)
    {
    	return keyStates[KeyCode] == 1 || keyStates[KeyCode] == 2;
    }

    void Update() 
    {
    	for (const auto& pair : keyStates) 
        {
            const int& key = pair.first;
            int state = pair.second;
            
            if (isKeyPressed(key))
            {
                if (state == 0) { state = 1; } // Key Down
                if (state == 1) { state = 2; } // Key Pressed
            }
            else
            {
            	if (state == 1) { state = 0; }
                if (state == 2) { state = 3; } // Key Up
                if (state == 3) { state = 0; } // Set to nothing
            }

            keyStates[key] = state;
        }
    }


private:

	GLFWwindow* window;

	std::unordered_map<int, int> keyStates;
    // 0 - nothing
    // 1 - on down
    // 2 - pressed
    // 3 - on up

    bool isKeyPressed(int KeyCode) {
    	return glfwGetKey(window, KeyCode) == GLFW_PRESS;
	}
};
	
#endif

