//
//  TMyTask.h
//  
//
//  Created by Michal Sefcik on 14/06/16.
//
//

#ifndef TMyTask_h
#define TMyTask_h

#include <TTask.h>

#include <stdio.h>

class TMyTask: public TTask {
public:
    //TMyTask();
    TMyTask(const char* name="name", const char* title="");
    ~TMyTask();
    virtual void Browse(TBrowser * b);
    virtual void Exec(Option_t * option);
    virtual void ExecuteTasks(Option_t * option);
    TList* GetOutput() {return fOutput;}
protected:
    TList* fOutput;
    ClassDef(TMyTask,1)
};

#endif /* TMyTask_hpp */
