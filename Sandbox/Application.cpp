//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>
#include <iostream>
class Sandbox : public PlsEngine::Application {
public:
    Sandbox() {
        std::cout << "Creating a Sandbox" << std::endl;
    }
    ~Sandbox() {
        std::cout << "Destroying a Sandbox" << std::endl;
    }
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}