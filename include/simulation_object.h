#ifndef ATG_ENGINE_SIM_SIMULATION_OBJECT_H
#define ATG_ENGINE_SIM_SIMULATION_OBJECT_H

#include "scs.h"

class EngineSimApplication;
class SimulationObject {
    public:
        struct ViewParameters {
            int Layer0;
            int Layer1;
        };

    public:
        SimulationObject();
        virtual ~SimulationObject();

        virtual void initialize(EngineSimApplication *app);
        virtual void generateGeometry();
        virtual void render(const ViewParameters *settings);
        virtual void process(float dt);
        virtual void destroy();

    protected:
        void resetShader();
        void setTransform(
            atg_scs::RigidBody *rigidBody,
            float scale = 1.0f,
            float lx = 0.0f,
            float ly = 0.0f,
            float theta = 0.0f);

        EngineSimApplication *m_app;
};

#endif /* ATG_ENGINE_SIM_SIMULATION_OBJECT_H */
