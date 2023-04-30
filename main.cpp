#include <iostream>
#include "glm/glm.hpp"
#include <glad/glad.h>
#include <glm/ext.hpp>
#include <GLFW/glfw3.h>
#include "core/Log.h"
#include "Application.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
};


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    std::string s = std::format("Viewport change: {}, {}", width, height);
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void draw_point(Vertex vertex, GLfloat size)
{
    glPointSize(size);
    glBegin(GL_POINTS);
    glColor4f(vertex.color.r, vertex.color.g, vertex.color.b, 1.0f);
    glVertex3f(vertex.position.x, vertex.position.y, vertex.position.z);
    glEnd();
}

void draw_line(Vertex v1, Vertex v2, GLfloat width)
{
    glLineWidth(width);
    glBegin(GL_LINES);
    glColor4f(v1.color.r, v1.color.g, v1.color.b, 1.0f);
    glVertex3f(v1.position.x, v1.position.y, v1.position.z);
    glColor4f(v2.color.r, v2.color.g, v2.color.b, 1.0f);
    glVertex3f(v2.position.x, v2.position.y, v2.position.z);
    glEnd();
}

void draw_grid(float grid_size)
{
    //  1742, 686
    float ratio = 1742.0f / 686.0f;
    for(float x = -ratio; x<= ratio; x+=grid_size)
    {
        Vertex v1 = {glm::vec3(x, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)};
        Vertex v2 = {glm::vec3(x, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)};
        draw_line(v1, v2, 1.0f);
    }

    for(float y = -ratio; y <= ratio; y+=grid_size)
    {
        Vertex v1 = {glm::vec3(-ratio, y, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)};
        Vertex v2 = {glm::vec3(ratio, y, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)};
        draw_line(v1, v2, 1.0f);
    }
}


int main()
{

    GL::Log::Init();
    LOG_INFO("Application startup");


    using MyApp = GL::Application;
    auto* app = new MyApp("Sample", 800, 600);
    app->Run();

    delete app;
//
//    glEnable(GL_POINT_SMOOTH);
//    glHint(GL_POINT_SMOOTH, GL_NICEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//
//    float ratio = 800.0f / 600.0f;
//
//    while(!window.ShouldClose())
//    {
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glMatrixMode(GL_PROJECTION);
//        glLoadIdentity();
//        glOrtho(-ratio, ratio, -1.0f, 1.0f, 1.0f, -1.0f);
//        glMatrixMode(GL_MODELVIEW);
//        glLoadIdentity();
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//        GLfloat size=5.0f;
//        for(GLfloat x = -1.0f; x<=1.0f; x+=0.2f, size+=5)
//        {
//            Vertex v = {glm::vec3(x, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)};
//            draw_point(v, size);
//        }
//
//        draw_grid(0.1f);
//
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
    return 0;
}