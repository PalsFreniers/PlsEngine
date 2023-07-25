//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>

class Sandbox : public PlsEngine::Application {
private:
    
public:
    Sandbox() {
        PushLayer(new PlsEngine::ImGUILayer(), true);
    }
    ~Sandbox() {
    }
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}
