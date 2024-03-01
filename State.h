//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_STATE_H
#define SFML_PROJECT_STATE_H


class State
{
public:
    virtual void Init()=0;
    virtual void InputHandler()=0;
    virtual void Update(float dt) = 0;
    virtual void Draw(float dt) =0;
    virtual void Pause(){};
    virtual void Resume(){};
};


#endif //SFML_PROJECT_STATE_H
