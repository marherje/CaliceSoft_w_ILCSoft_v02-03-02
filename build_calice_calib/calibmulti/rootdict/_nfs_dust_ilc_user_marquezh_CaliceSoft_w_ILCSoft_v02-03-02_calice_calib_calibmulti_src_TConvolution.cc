// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dInfsdIdustdIilcdIuserdImarquezhdICaliceSoft_w_ILCSoft_v02mI03mI02dIbuild_calice_calibdIcalibmultidIrootdictdI_nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "ROOT/RConfig.hxx"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Header files passed as explicit arguments
#include "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_calib/calibmulti/include/TConvolution.h"

// Header files passed via #pragma extra_include

// The generated code does not explicitly qualify STL entities
namespace std {} using namespace std;

namespace ROOT {
   static void *new_TConvolution(void *p = nullptr);
   static void *newArray_TConvolution(Long_t size, void *p);
   static void delete_TConvolution(void *p);
   static void deleteArray_TConvolution(void *p);
   static void destruct_TConvolution(void *p);
   static void streamer_TConvolution(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TConvolution*)
   {
      ::TConvolution *ptr = nullptr;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TConvolution >(nullptr);
      static ::ROOT::TGenericClassInfo 
         instance("TConvolution", ::TConvolution::Class_Version(), "", 31,
                  typeid(::TConvolution), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TConvolution::Dictionary, isa_proxy, 16,
                  sizeof(::TConvolution) );
      instance.SetNew(&new_TConvolution);
      instance.SetNewArray(&newArray_TConvolution);
      instance.SetDelete(&delete_TConvolution);
      instance.SetDeleteArray(&deleteArray_TConvolution);
      instance.SetDestructor(&destruct_TConvolution);
      instance.SetStreamerFunc(&streamer_TConvolution);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TConvolution*)
   {
      return GenerateInitInstanceLocal(static_cast<::TConvolution*>(nullptr));
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal(static_cast<const ::TConvolution*>(nullptr)); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TConvolution::fgIsA(nullptr);  // static to hold class pointer

//______________________________________________________________________________
const char *TConvolution::Class_Name()
{
   return "TConvolution";
}

//______________________________________________________________________________
const char *TConvolution::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TConvolution*)nullptr)->GetImplFileName();
}

//______________________________________________________________________________
int TConvolution::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TConvolution*)nullptr)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TConvolution::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TConvolution*)nullptr)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TConvolution::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TConvolution*)nullptr)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TConvolution::Streamer(TBuffer &R__b)
{
   // Stream an object of class TConvolution.

   UInt_t R__s, R__c;
   if (R__b.IsReading()) {
      Version_t R__v = R__b.ReadVersion(&R__s, &R__c); if (R__v) { }
      TObject::Streamer(R__b);
      { TString R__str; R__str.Streamer(R__b); _name = R__str.Data(); }
      R__b >> _f1;
      R__b >> _f2;
      R__b >> _convolution;
      R__b >> _nPar1;
      R__b >> _nPar2;
      R__b >> _baseNpar;
      R__b >> _stepsPerPoint;
      R__b >> _scaleParNumber;
      R__b >> _f1Rmin;
      R__b >> _f1Rmax;
      R__b >> _f2Rmin;
      R__b >> _f2Rmax;
      R__b >> _Rmin;
      R__b >> _Rmax;
      R__b >> _addScale;
      R__b.CheckByteCount(R__s, R__c, TConvolution::IsA());
   } else {
      R__c = R__b.WriteVersion(TConvolution::IsA(), kTRUE);
      TObject::Streamer(R__b);
      { TString R__str = _name.c_str(); R__str.Streamer(R__b);}
      R__b << _f1;
      R__b << _f2;
      R__b << _convolution;
      R__b << _nPar1;
      R__b << _nPar2;
      R__b << _baseNpar;
      R__b << _stepsPerPoint;
      R__b << _scaleParNumber;
      R__b << _f1Rmin;
      R__b << _f1Rmax;
      R__b << _f2Rmin;
      R__b << _f2Rmax;
      R__b << _Rmin;
      R__b << _Rmax;
      R__b << _addScale;
      R__b.SetByteCount(R__c, kTRUE);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TConvolution(void *p) {
      return  p ? new(p) ::TConvolution : new ::TConvolution;
   }
   static void *newArray_TConvolution(Long_t nElements, void *p) {
      return p ? new(p) ::TConvolution[nElements] : new ::TConvolution[nElements];
   }
   // Wrapper around operator delete
   static void delete_TConvolution(void *p) {
      delete (static_cast<::TConvolution*>(p));
   }
   static void deleteArray_TConvolution(void *p) {
      delete [] (static_cast<::TConvolution*>(p));
   }
   static void destruct_TConvolution(void *p) {
      typedef ::TConvolution current_t;
      (static_cast<current_t*>(p))->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TConvolution(TBuffer &buf, void *obj) {
      ((::TConvolution*)obj)->::TConvolution::Streamer(buf);
   }
} // end of namespace ROOT for class ::TConvolution

namespace {
  void TriggerDictionaryInitialization__nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution_Impl() {
    static const char* headers[] = {
"/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_calib/calibmulti/include/TConvolution.h",
nullptr
    };
    static const char* includePaths[] = {
"/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/root/6.28.04/include/",
"/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_calib/calibmulti/src/",
nullptr
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "_nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_calib/calibmulti/include/TConvolution.h")))  TConvolution;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "_nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "/nfs/dust/ilc/user/marquezh/CaliceSoft_w_ILCSoft_v02-03-02/calice_calib/calibmulti/include/TConvolution.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"TConvolution", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("_nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02-03-02_calice_calib_calibmulti_src_TConvolution",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization__nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization__nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization__nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution() {
  TriggerDictionaryInitialization__nfs_dust_ilc_user_marquezh_CaliceSoft_w_ILCSoft_v02mI03mI02_calice_calib_calibmulti_src_TConvolution_Impl();
}
