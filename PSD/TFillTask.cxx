//
//  TFillTask.cxx
//  
//
//  Created by Michal Sefcik on 17/06/16.
//
//

#include <TF1.h>
#include <TH1D.h>

#include "TMyTask.h"
#include "TFillTask.h"

ClassImp(TFillTask)

TFillTask::TFillTask(const char* name, const char* title): TMyTask(name,title), fNFill(1e5)
{
}

void TFillTask::Exec(Option_t *)
{
    printf("Executing task %s.\n", GetTitle());
    TH1D* lHist = new TH1D("lHist","Hist",100,-50.,50.);
    TF1* lFun = new TF1("lFun","gaus(0)",-50.,50.);
    lFun->SetParameter(0,1.);
    lFun->SetParameter(1,0.);
    lFun->SetParameter(2,20.);
    lHist->FillRandom("lFun",fNFill);
    //lHist->Print();
    fOutput->Add(lHist);
}
