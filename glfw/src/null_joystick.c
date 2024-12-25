//========================================================================
<<<<<<< HEAD
// GLFW 3.3 - www.glfw.org
=======
// GLFW 3.4 - www.glfw.org
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
//------------------------------------------------------------------------
// Copyright (c) 2016-2017 Camilla Löwy <elmindreda@glfw.org>
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
=======
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3

#include "internal.h"


//////////////////////////////////////////////////////////////////////////
//////                       GLFW platform API                      //////
//////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
int _glfwPlatformPollJoystick(_GLFWjoystick* js, int mode)
=======
GLFWbool _glfwInitJoysticksNull(void)
{
    return GLFW_TRUE;
}

void _glfwTerminateJoysticksNull(void)
{
}

GLFWbool _glfwPollJoystickNull(_GLFWjoystick* js, int mode)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
    return GLFW_FALSE;
}

<<<<<<< HEAD
void _glfwPlatformUpdateGamepadGUID(char* guid)
=======
const char* _glfwGetMappingNameNull(void)
{
    return "";
}

void _glfwUpdateGamepadGUIDNull(char* guid)
>>>>>>> b549c58221f11ebdd8f076071ebdb97f3cd608c3
{
}

