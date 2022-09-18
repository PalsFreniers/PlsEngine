//
// Created by tidian on 18/09/22.
//

#ifndef PLSENGINE_APPLICATION_H
#define PLSENGINE_APPLICATION_H


namespace PlsEngine {

    class Application {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    //to be defined in client
    Application* CreateApplication();

} // PlsEngine

#endif //PLSENGINE_APPLICATION_H
