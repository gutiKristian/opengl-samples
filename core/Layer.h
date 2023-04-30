//
// Created by krist on 29. 4. 2023.
//

#ifndef DUNNO_LAYER_H
#define DUNNO_LAYER_H

class Layer
{
protected:
    Layer() = default;
public:
    virtual void OnAttach() = 0;
    virtual void OnEvent() = 0;
    virtual void OnDetach() = 0;
    virtual void ImGuiRender() = 0;
};

#endif //DUNNO_LAYER_H
