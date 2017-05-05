//
//  main.cpp
//  OpenGLtest
//
//  Created by wzcjj on 2017/3/6.
//  Copyright © 2017年 wzcjj. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>

int main()
{
    GLEWwindow* window;
    
    /* Initialize the library */
    if (!glewInit())
        return -1;
    
    /* Create a windowed mode window and its OpenGL context */
    window = glewCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glewTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glewMakeContextCurrent(window);
    
    /* Loop until the user closes the window */
    while (!glewWindowShouldClose(window))
    {
        /* Render here */
        
        /* Swap front and back buffers */
        glewSwapBuffers(window);
        
        /* Poll for and process events */
        glewPollEvents();
    }
    
    glewTerminate();
    return 0;  
}
