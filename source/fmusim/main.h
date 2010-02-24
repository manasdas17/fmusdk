/* ------------------------------------------------------------------------- 
 * main.h
 * Function types for all FMU functions and a struct to wrap a FMU dll. 
 * Copyright 2010 QTronic GmbH. All rights reserved. 
 * -------------------------------------------------------------------------
 */

#ifndef main_h
#define main_h

#include <windows.h>
#include "fmiModelFunctions.h"
#include "xml_parser.h"

typedef const char* (*fGetModelTypesPlatform)();
typedef const char* (*fGetVersion)();
typedef fmiComponent (*fInstantiateModel)(fmiString instanceName, fmiString GUID,
                                        fmiCallbackFunctions functions, fmiBoolean loggingOn);
typedef void      (*fFreeModelInstance)  (fmiComponent c);
typedef fmiStatus (*fSetDebugLogging)    (fmiComponent c, fmiBoolean loggingOn);
typedef fmiStatus (*fSetTime)            (fmiComponent c, fmiReal time);
typedef fmiStatus (*fSetContinuousStates)(fmiComponent c, const fmiReal x[], size_t nx);
typedef fmiStatus (*fCompletedIntegratorStep)(fmiComponent c, fmiBoolean* callEventUpdate);
typedef fmiStatus (*fSetReal)   (fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiReal    value[]);
typedef fmiStatus (*fSetInteger)(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiInteger value[]);
typedef fmiStatus (*fSetBoolean)(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiBoolean value[]);
typedef fmiStatus (*fSetString) (fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiString  value[]);
typedef fmiStatus (*fInitialize)(fmiComponent c, fmiBoolean toleranceControlled, 
                               fmiReal relativeTolerance, fmiEventInfo* eventInfo);
typedef fmiStatus (*fGetDerivatives)    (fmiComponent c, fmiReal derivatives[]    , size_t nx);
typedef fmiStatus (*fGetEventIndicators)(fmiComponent c, fmiReal eventIndicators[], size_t ni);
typedef fmiStatus (*fGetReal)   (fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiReal    value[]);
typedef fmiStatus (*fGetInteger)(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiInteger value[]);
typedef fmiStatus (*fGetBoolean)(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiBoolean value[]);
typedef fmiStatus (*fGetString) (fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiString  value[]);
typedef fmiStatus (*fEventUpdate)               (fmiComponent c, fmiBoolean intermediateResults, fmiEventInfo* eventInfo);
typedef fmiStatus (*fGetContinuousStates)       (fmiComponent c, fmiReal states[], size_t nx);
typedef fmiStatus (*fGetNominalContinuousStates)(fmiComponent c, fmiReal x_nominal[], size_t nx);
typedef fmiStatus (*fGetStateValueReferences)   (fmiComponent c, fmiValueReference vrx[], size_t nx);
typedef fmiStatus (*fTerminate)                 (fmiComponent c);    

typedef struct {
    ModelDescription* modelDescription;
    HANDLE dllHandle;
    fGetModelTypesPlatform getModelTypesPlatform;
    fGetVersion getVersion;
    fInstantiateModel instantiateModel;
    fFreeModelInstance freeModelInstance;
    fSetDebugLogging setDebugLogging;
    fSetTime setTime;
    fSetContinuousStates setContinuousStates;
    fCompletedIntegratorStep completedIntegratorStep;
    fSetReal setReal;
    fSetInteger setInteger;
    fSetBoolean setBoolean;
    fSetString setString;
    fInitialize initialize;
    fGetDerivatives getDerivatives;
    fGetEventIndicators getEventIndicators;
    fGetReal getReal;
    fGetInteger getInteger;
    fGetBoolean getBoolean;
    fGetString getString;
    fEventUpdate eventUpdate;
    fGetContinuousStates getContinuousStates;
    fGetNominalContinuousStates getNominalContinuousStates;
    fGetStateValueReferences getStateValueReferences;
    fTerminate terminate;
} FMU;

#endif // main_h
