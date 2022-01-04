#pragma once

#include <memory>
#include <stack>
#include "State.h"

namespace pokemania {
    typedef std::unique_ptr<State> StateRef;

    class StateMachine {
    public:
        void AddState(StateRef newState, bool isReplacing = true);

        void RemoveState();

        void ProcessStateChanges();

        StateRef &GetActiveState();

    private:
        std::stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding, _isReplacing;
    };
}