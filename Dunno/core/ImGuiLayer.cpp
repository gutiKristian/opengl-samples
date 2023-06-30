//
// Created by krist on 28. 6. 2023.
//

#include "ImGuiLayer.h"

namespace Dunno
{
    ImGuiLayer::ImGuiLayer(GLFWwindow *window) : mNativeWindow(window)
    {
    }

    void ImGuiLayer::OnAttach()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();

        ImGui_ImplGlfw_InitForOpenGL(mNativeWindow, true);
        ImGui_ImplOpenGL3_Init("#version 460");
    }


    void ImGuiLayer::OnDetach()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::Begin()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End()
    {
        ImGuiIO& io = ImGui::GetIO();
        int width, height;

        // TODO: Send Window class to ImGuiLayer, abstract this
        glfwGetWindowSize(mNativeWindow, &width, &height);

        io.DisplaySize = ImVec2((float)width, (float)height);

        // Rendering
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    }

}
