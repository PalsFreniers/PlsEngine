//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>
#include <iostream>
class Sandbox : public PlsEngine::Application {
public:
    Sandbox() {
    }
    ~Sandbox() {
    }
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}