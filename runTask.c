//
//  runTask.c
//  
//
//  Created by Michal Sefcik on 14/06/16.
//
//

#include <TROOT.h>
#include <TSystem.h>
#include <stdio.h>

//#include "TMyTask.h"

void runTask()
{
    const Int_t N = 12;
    /*
    cout<<"----------------------------------------------------"<<endl;
    cout<<" ---> Compiling needed class, please wait... "<<endl;
    //Compile Macro
    Int_t workedornot = gSystem->CompileMacro("TMyTask.cxx","-kfo");
    cout<<"----------------------------------------------------"<<endl;
    cout<<endl;
    if( workedornot == 0 ){
        cout<<"*************************************"<<endl;
        cout<<" TMyTask.cpp compilation failed! "<<endl;
        cout<<"*************************************"<<endl;
        return;
    }
    //Load Class
    //workedornot = gSystem->Load("TMyTask_cxx");
    //cout << "Loading library = " << workedornot << endl;
    */
    //gROOT->LoadMacro("TMyTask.cxx+g");
    //gROOT->LoadMacro("TFillTask.cxx+g");
    //gDebug=2;
    
    gSystem->Load("build/PSD/libPSD.dylib");
    
    TH1::AddDirectory(kFALSE);
    
    TMyTask* lTaskA = new TMyTask("lTaskA","A");
    
    for(Int_t i=0; i<N; i++) {
        TFillTask* lTaskA1 = new TFillTask(Form("lTaskA%d",i),Form("A%d",i));
        lTaskA1->SetNFill(1e7);
        lTaskA->Add(lTaskA1);
    }
    
    lTaskA->ExecuteTask();
    TFile* lFile = TFile::Open("out.root","RECREATE");
    lTaskA->Write();
    lFile->Close();
    gROOT->GetListOfBrowsables()->Add(lTaskA);
    //new TBrowser;
}
