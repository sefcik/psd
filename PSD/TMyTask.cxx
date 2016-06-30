//
//  TMyTask.cxx
//  
//
//  Created by Michal Sefcik on 14/06/16.
//
//

#include <TTask.h>
#include <TROOT.h>
#include <iostream>

#include "TMyTask.h"

ClassImp(TMyTask)
/*
TMyTask::TMyTask(): TTask()
{
}
*/
TMyTask::TMyTask(const char* name, const char* title): TTask(name,title), fOutput(NULL)
{
    fOutput = new TList;
    fOutput->SetName("output");
    fOutput->SetOwner(kTRUE);
}

TMyTask::~TMyTask()
{
    delete fOutput;
}

void TMyTask::Browse(TBrowser * b)
{
    TTask::Browse(b);
    if(fOutput) fOutput->Browse(b);
}

void TMyTask::Exec(Option_t *)
{
    printf("Executed task %s.\n", GetTitle());
}

void TMyTask::ExecuteTasks(Option_t * option)
{
    TTask *task;
    //#pragma omp parallel for private (task)
    //schedule (guided,(int)1e7)
    for(Int_t i=0; i<fTasks->GetEntries(); i++) {
        task = (TTask*)fTasks->At(i);
        //task->Print();
        if (!task->IsActive()) continue;
        
        task->Exec(option);
        task->ExecuteTasks(option);
    }
}
