// File Line: 111
// RVA: 0x140550
void __fastcall UFG::AudioEventInfo::AudioEventInfo(UFG::AudioEventInfo *this)
{
  this->vfptr = (UFG::AudioEventInfoVtbl *)&UFG::AudioEventInfo::`vftable;
  this->eventId = 0;
  this->objectId = 0i64;
  this->flags = 0;
  this->callbackFun = 0i64;
  this->pUserData = 0i64;
}

// File Line: 121
// RVA: 0x141280
void __fastcall UFG::AudioEventInfo::~AudioEventInfo(UFG::AudioEventInfo *this)
{
  this->vfptr = (UFG::AudioEventInfoVtbl *)&UFG::AudioEventInfo::`vftable;
}

// File Line: 138
// RVA: 0x141760
void __fastcall UFG::WwiseCallbackOperation::~WwiseCallbackOperation(UFG::WwiseCallbackOperation *this)
{
  this->vfptr = (UFG::WwiseCallbackOperationVtbl *)&UFG::WwiseCallbackOperation::`vftable;
  this->eventInfo.vfptr = (UFG::AudioEventInfoVtbl *)&UFG::AudioEventInfo::`vftable;
}

