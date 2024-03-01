//
// Created by minau on 2/29/2024.
//

#include "StateMachine.h"

StateMachine::StateMachine()
{

}

StateMachine::~StateMachine()
{

}

void StateMachine::AddState(State *newState, bool isReplacing)
{
    _isAdding = true;
    _isReplacing = true;

    _newState = newState;
}

void StateMachine::RemoveState()
{
    _isRemoving = true;
}

void StateMachine::ProcessStateChanges()
{
    if(_isRemoving && !_states.empty())
    {
        _states.pop();
        _isRemoving = false;
    }
    if(_isAdding)
    {
        if(!_states.empty())
        {
            if(_isReplacing)
            {
                _states.pop();
            }
            else
                _states.top()->Pause();
        }

        _states.push(_newState);
        _states.top()->Init();
        _isAdding = false;

    }

}

State *&StateMachine::GetActiveState()
{
    return _states.top();
}
