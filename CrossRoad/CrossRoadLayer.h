//
// Created by krist on 27. 6. 2023.
//

#ifndef OPENGL_SAMPLES_CROSSROADLAYER_H
#define OPENGL_SAMPLES_CROSSROADLAYER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "core/Layer.h"

class CrossRoadLayer : public Dunno::Layer
{
public:
    void OnAttach() override;
    void OnUpdate() override;
    void OnEvent(Dunno::Event&) override;
    void OnDetach() override;
    void OnImGuiRender() override;
};


#endif //OPENGL_SAMPLES_CROSSROADLAYER_H
