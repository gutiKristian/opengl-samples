//
// Created by krist on 28. 6. 2023.
//

#ifndef OPENGL_SAMPLES_IMGUILAYER_H
#define OPENGL_SAMPLES_IMGUILAYER_H

#include "core/Layer.h"
#include "GLFW/glfw3.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Dunno
{
    class ImGuiLayer : public Layer
    {
        GLFWwindow* mNativeWindow = nullptr;
    public:
        explicit ImGuiLayer(GLFWwindow* window);
        void OnAttach() override;
        void OnDetach() override;
        void Begin();
        void End();
    };

}


#endif //OPENGL_SAMPLES_IMGUILAYER_H
