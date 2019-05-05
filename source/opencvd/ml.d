/*
Copyright (c) 2019 Ferhat Kurtulmuş
Boost Software License - Version 1.0 - August 17th, 2003
Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:
The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

module opencvd.ml;

import opencvd.cvcore;

private extern (C){
    SVM SVM_Create();
    void SVM_Close(SVM svm);
    double SVM_GetC(SVM svm);
    Mat SVM_GetClassWeights(SVM svm);
    double SVM_GetCoef0(SVM svm);
    double SVM_GetDecisionFunction(SVM svm, int i, Mat alpha, Mat svidx);
    double SVM_GetDegree(SVM svm);
    double SVM_GetGamma(SVM svm);
    int SVM_GetKernelType(SVM svm);
    double SVM_GetNu(SVM svm);
    double SVM_GetP(SVM svm);
    Mat SVM_GetSupportVectors(SVM svm);
    TermCriteria SVM_GetTermCriteria(SVM svm);
    int SVM_GetType(SVM svm);
    Mat SVM_GetUncompressedSupportVectors(SVM svm);
    void SVM_SetC (SVM svm, double val);
    void SVM_SetClassWeights(SVM svm, Mat val);
    void SVM_SetCoef0 (SVM svm, double val);
    void SVM_SetDegree (SVM svm, double val);
    void SVM_SetGamma (SVM svm, double val);
    void SVM_SetKernel (SVM svm, int kernelType);
    void SVM_SetNu (SVM svm, double val);
    void SVM_SetP (SVM svm, double val);
    void SVM_SetTermCriteria(SVM svm, TermCriteria val);
    void SVM_SetType(SVM svm, int val);
    ParamGrid SVM_GetDefaultGridPtr(int param_id);
    bool SVM_TrainAuto0(SVM svm, Mat samples, int layout, Mat responses, int kFold, ParamGrid Cgrid,
        ParamGrid gammaGrid, ParamGrid pGrid, ParamGrid nuGrid, ParamGrid coeffGrid,
        ParamGrid degreeGrid, bool balanced);

    ParamGrid ParamGrid_Create (double minVal, double maxVal, double logstep);
    double ParamGrid_MinVal (ParamGrid pg);
    double ParamGrid_MaxVal (ParamGrid pg);
    double ParamGrid_LogStep (ParamGrid pg);
}

struct SVM {
    void* p;
    
    enum: int { // KernelTypes
        CUSTOM =-1, 
        LINEAR =0, 
        POLY =1, 
        RBF =2, 
        SIGMOID =3, 
        CHI2 =4, 
        INTER =5 
    }
    enum: int { // ParamTypes
        C =0, 
        GAMMA =1, 
        P =2, 
        NU =3, 
        COEF =4, 
        DEGREE =5 
    }
    
    enum: int { // Types
        C_SVC =100, 
        NU_SVC =101, 
        ONE_CLASS =102, 
        EPS_SVR =103, 
        NU_SVR =104 
    }
    
    static SVM opCall(){
        return SVM_Create();
    }
    
    double getC(){
        return SVM_GetC(this);
    }
    
    Mat getClassWeights(){
        return SVM_GetClassWeights(this);
    }
    
    double getCoef0(){
        return SVM_GetCoef0(this);
    }
    
    double getDecisionFunction(int i, Mat alpha, Mat svidx){
        return SVM_GetDecisionFunction(this, i, alpha, svidx);
    }
    
    double getDegree(){
        return SVM_GetDegree(this);
    }
    
    double getGamma(){
        return SVM_GetGamma(this);
    }
    
    int getKernelType(){
        return SVM_GetKernelType(this);
    }
    
    double getNu(){
        return SVM_GetNu(this);
    }
    
    double getP(){
        return SVM_GetP(this);
    }
    
    Mat getSupportVectors(){
        return SVM_GetSupportVectors(this);
    }
    
    TermCriteria getTermCriteria(){
        return SVM_GetTermCriteria(this);
    }
    
    int getType(){
        return SVM_GetType(this);
    }
    
    Mat getUncompressedSupportVectors(){
        return SVM_GetUncompressedSupportVectors(this);
    }
    
    void setC(double val){
        SVM_SetC(this, val);
    }
    
    void setClassWeights(Mat val){
        SVM_SetClassWeights(this, val);
    }
    
    void setCoef0 (double val){
        SVM_SetCoef0 (this, val);
    }
    
    void setDegree(double val){
        SVM_SetDegree (this, val);
    }
    
    void setGamma(double val){
        SVM_SetGamma(this, val);
    }
    
    void setKernel (int kernelType){
        SVM_SetKernel (this, kernelType);
    }
    
    void setNu (double val){
        SVM_SetNu (this, val);
    }
    
    void setP (double val){
        SVM_SetP (this, val);
    }
    
    void setTermCriteria( TermCriteria val){
        SVM_SetTermCriteria(this, val);
    }
    
    void setType( int val){
        SVM_SetType(this, val);
    }
    
    static ParamGrid getDefaultGridPtr(int param_id){
        return SVM_GetDefaultGridPtr(param_id);
    }
    
    bool trainAuto( Mat samples, int layout, Mat responses, int kFold = 10,
        ParamGrid Cgrid = SVM.getDefaultGridPtr(SVM.C),
        ParamGrid gammaGrid = SVM.getDefaultGridPtr(SVM.GAMMA),
        ParamGrid pGrid = SVM.getDefaultGridPtr(SVM.P),
        ParamGrid nuGrid = SVM.getDefaultGridPtr(SVM.NU),
        ParamGrid coeffGrid = SVM.getDefaultGridPtr(SVM.COEF),
        ParamGrid degreeGrid = SVM.getDefaultGridPtr(SVM.DEGREE),
        bool balanced = false){
        
        return SVM_TrainAuto0(this, samples, layout, responses, kFold, Cgrid,
            gammaGrid, pGrid, nuGrid, coeffGrid,
            degreeGrid, balanced);
    }
}

void Destroy(SVM svm){
    SVM_Close(svm);
}

struct ParamGrid {
    void* p;
    
    static ParamGrid opCall(double minVal = 0, double maxVal = 0, double logstep = 1.0){
        return ParamGrid_Create (minVal, maxVal, logstep);
    }
    
    double minVal(){
        return ParamGrid_MinVal (this);
    }
    
    double maxVal (){
        return ParamGrid_MaxVal (this);
    }
    
    double logStep (){
        return ParamGrid_LogStep (this);
    }
}
