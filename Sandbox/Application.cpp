//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>

class MyLayer : public PlsEngine::Layer {
public:
        MyLayer()
                : Layer("Example") {
                
        }
        
        void OnUpdate() override {
                if(PlsEngine::Input::isKeyPressed(PLSEK_TAB)) {
                        CLIENT_TRACE("tab key pressed");
                }
        }
        
        void onImGuiRender() override {
                ImGui::Begin("Test");
                ImGui::Text("Hello World!");
                ImGui::End();
        }
        
        void OnEvent(PlsEngine::Event & e) override {
                
        }
};

class Sandbox : public PlsEngine::Application {
public:
    Sandbox() {
        PushLayer(new MyLayer(), false);
    }
    
    ~Sandbox() {
    }
    
private:
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}
