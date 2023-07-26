//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>

class Sandbox : public PlsEngine::Application {
public:
    Sandbox() {
        PushLayer(new PlsEngine::ImGUILayer(), true);
    }
    
    ~Sandbox() {
    }
    
private:
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}
