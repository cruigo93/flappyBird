#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace Cruigo{
    typedef std::unique_ptr<State> stateRef;
    class StateMachine{
    public:
        StateMachine(){};
        ~StateMachine(){};

        void addState(stateRef newState, bool isReplacing = true);
        void removeState();

        void processState();
        stateRef &getActiveState();

    private:
        std::stack<stateRef> _states;
        stateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}