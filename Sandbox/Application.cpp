//
// Created by tidian on 18/09/22.
//

#include <PlsEngine.h>

class Sandbox : public PlsEngine::Application {
private:

public:
    Sandbox() {

    }
    ~Sandbox() {
    }
};

PlsEngine::Application* PlsEngine::CreateApplication() {
    return new Sandbox();
}
