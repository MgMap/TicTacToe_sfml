//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_STATEMACHINE_H
#define SFML_PROJECT_STATEMACHINE_H

#include "State.h"
#include <stack>

class StateMachine
{
private:
    std::stack<State*> _states;
    State* _newState;

    bool _isRemoving;
    bool _isAdding;
    bool _isReplacing;

public:
    StateMachine(); //constructor
    ~StateMachine(); //destructor

    void AddState(State* newState, bool isReplacing = true);
    void RemoveState();
    void ProcessStateChanges();
    State* &GetActiveState();

};


#endif //SFML_PROJECT_STATEMACHINE_H
