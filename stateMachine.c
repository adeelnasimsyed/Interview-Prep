#include <stdio.h>

//Different state of ATM machine
typedef enum
{
    Idle_State,
    Card_Inserted_State,
    Pin_Entered_State,
    Option_Selected_State,
    Amount_Entered_State,
    last_State
} eSystemState;

//Different type events
typedef enum
{
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event,
    last_Event
} eSystemEvent;

typedef eSystemState (*pfEventHandler)(void);

//structure of state and event with event handler
typedef struct
{
    eSystemState eStateMachine;
    eSystemEvent eStateMachineEvent;
    pfEventHandler pfStateMachineEvnentHandler;
} StateMachine_t;


eSystemState insertCardHandler(void)
{
    return Card_Inserted_State;
}

eSystemState pinEnterHandler(void)
{
    return Pin_Entered_State;
}

eSystemState optionSelectionHandler(void)
{
    return Option_Selected_State;
}

eSystemState amountEnterHandler(void)
{
    return Amount_Entered_State;
}

eSystemState amountDispatchHandler(void)
{
    return Idle_State;
}

StateMachine_t stateMachine[] = 
{
    {Idle_State,             Card_Insert_Event,      insertCardHandler},
    {Card_Inserted_State,    Pin_Enter_Event,        pinEnterHandler},
    {Pin_Entered_State,      Option_Selection_Event, optionSelectionHandler},
    {Option_Selected_State,  Amount_Enter_Event,     amountEnterHandler},
    {Amount_Entered_State,   Amount_Dispatch_Event,  amountDispatchHandler}
};

//main function
int main()
{
    eSystemState eNextState = Idle_State;
    while(1)
    {
        //Api read the event
        eSystemEvent eNewEvent = read_event();
        if((eNextState < last_State) && (eNewEvent < last_Event)&& (stateMachine[eNextState].eStateMachineEvent == eNewEvent) && (stateMachine[eNextState].pfStateMachineEvnentHandler != NULL))
        {
            // function call as per the state and event and return the next state of the finite state machine
            eNextState = (*stateMachine[eNextState].pfStateMachineEvnentHandler)();
        }
        else
        {
            //Invalid
        }
    }
    return 0;
}
