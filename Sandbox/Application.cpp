//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>

class MyLayer : public PlsEngine::Layer {
public:
    MyLayer() : Layer("MyLayer") {}
    
    void OnUpdate() override {
        CLIENT_INFO("MyLayer class OnUpdate");
    }
    
    void OnEvent(PlsEngine::Event& e) override {
        CLIENT_INFO("{0}", e);
    }
};

class Sandbox : public PlsEngine::Application {
private:
    
public:
    Sandbox() {
        PushLayer(new MyLayer(), 0);
    }
    ~Sandbox() {
    }
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}
