//
//  TFillTask.h
//  
//
//  Created by Michal Sefcik on 17/06/16.
//
//

#ifndef TFillTask_h
#define TFillTask_h

#include <stdio.h>

#include "TMyTask.h"

class TFillTask: public TMyTask {
public:
    TFillTask(const char* name="name", const char* title="");
    virtual void Exec(Option_t *option);
    void SetNFill(Long64_t lNFill) {fNFill = lNFill;}
private:
    Long64_t fNFill;
    ClassDef(TFillTask,1)
};

#endif /* TFillTask_h */
