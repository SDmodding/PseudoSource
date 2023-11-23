// File Line: 40
// RVA: 0x4CB5F0
void __fastcall UFG::SimpleTimer::SimpleTimer(UFG::SimpleTimer *this)
{
  this->mTimestamp = 0i64;
  this->mElapsedTime = 0.0;
  this->mIsStarted = 0;
}

// File Line: 58
// RVA: 0x510510
void __fastcall UFG::SimpleTimer::Start(UFG::SimpleTimer *this)
{
  unsigned __int64 mSimTimeMSec; // rax

  mSimTimeMSec = UFG::Metrics::msInstance.mSimTimeMSec;
  this->mElapsedTime = 0.0;
  this->mIsStarted = 1;
  this->mTimestamp = mSimTimeMSec;
}

// File Line: 66
// RVA: 0x510550
void __fastcall UFG::SimpleTimer::Stop(UFG::SimpleTimer *this)
{
  float v1; // xmm0_4

  if ( this->mIsStarted )
  {
    v1 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(this->mTimestamp));
    if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - this->mTimestamp) < 0 )
      v1 = v1 + 1.8446744e19;
    this->mIsStarted = 0;
    this->mElapsedTime = (float)(v1 * 0.001) + this->mElapsedTime;
  }
}

// File Line: 77
// RVA: 0x50F650
void __fastcall UFG::SimpleTimer::Resume(UFG::SimpleTimer *this)
{
  if ( !this->mIsStarted )
  {
    this->mIsStarted = 1;
    this->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
  }
}

// File Line: 87
// RVA: 0x4E1310
float __fastcall UFG::SimpleTimer::GetElapsedSeconds(UFG::SimpleTimer *this)
{
  float result; // xmm0_4
  float v2; // xmm1_4

  result = this->mElapsedTime;
  if ( this->mIsStarted )
  {
    v2 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(this->mTimestamp));
    if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - this->mTimestamp) < 0 )
      v2 = v2 + 1.8446744e19;
    return result + (float)(v2 * 0.001);
  }
  return result;
}

// File Line: 100
// RVA: 0x50FC30
void __fastcall UFG::SimpleTimer::SetElapsedTime(UFG::SimpleTimer *this, float elapsedTime)
{
  bool v2; // zf

  v2 = !this->mIsStarted;
  this->mElapsedTime = elapsedTime;
  if ( !v2 )
    this->mTimestamp = UFG::Metrics::msInstance.mSimTimeMSec;
}

// File Line: 130
// RVA: 0x4D6E90
void UFG::TSTimer::BindAtomics(void)
{
  UFG::SkookumMgr::mspTimerClass = SSBrain::get_class("Timer");
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTimerClass,
    &ASymbolX_ctor,
    UFG::TSTimer::Mthd_constructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTimerClass,
    &ASymbolX_dtor,
    UFG::TSTimer::Mthd_destructor,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTimerClass,
    "start",
    UFG::TSTimer::Mthd_start,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTimerClass,
    "stop",
    UFG::TSTimer::Mthd_stop,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTimerClass,
    "resume",
    UFG::TSTimer::Mthd_resume,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    UFG::SkookumMgr::mspTimerClass,
    "get_elapsed_seconds",
    UFG::TSTimer::Mthd_get_elapsed_seconds,
    SSBindFlag_instance_no_rebind);
}

// File Line: 150
// RVA: 0x4F6CB0
void __fastcall UFG::TSTimer::Mthd_constructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  SSObjectBase *i_obj_p; // rcx

  v3 = UFG::qMalloc(0x10ui64, "Skookum.Timer", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v3->mNext = 0i64;
    LODWORD(v3[1].mNext) = 0;
    BYTE4(v3[1].mNext) = 0;
  }
  else
  {
    v4 = 0i64;
  }
  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( i_obj_p && pScope->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    i_obj_p[2].vfptr = (SSObjectBaseVtbl *)v4;
  else
    *(_QWORD *)&MEMORY[0x20] = v4;
}

// File Line: 161
// RVA: 0x4F7EF0
void __fastcall UFG::TSTimer::Mthd_destructor(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( vfptr )
    operator delete[](vfptr);
}

// File Line: 169
// RVA: 0x50BD90
void __fastcall UFG::TSTimer::Mthd_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  SSObjectBaseVtbl *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  vfptr->__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))UFG::Metrics::msInstance.mSimTimeMSec;
  LODWORD(vfptr->get_obj_type) = 0;
  BYTE4(vfptr->get_obj_type) = 1;
}

// File Line: 179
// RVA: 0x50C1E0
void __fastcall UFG::TSTimer::Mthd_stop(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rcx
  float v4; // xmm0_4

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( BYTE4(vfptr->get_obj_type) )
  {
    v4 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(vfptr->__vecDelDtor));
    if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - (unsigned __int64)vfptr->__vecDelDtor) < 0 )
      v4 = v4 + 1.8446744e19;
    BYTE4(vfptr->get_obj_type) = 0;
    *(float *)&vfptr->get_obj_type = (float)(v4 * 0.001) + *(float *)&vfptr->get_obj_type;
  }
}

// File Line: 189
// RVA: 0x506A20
void __fastcall UFG::TSTimer::Mthd_resume(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rdx
  SSObjectBaseVtbl *vfptr; // rcx

  i_obj_p = pScope->i_scope_p.i_obj_p;
  if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  vfptr = i_obj_p[2].vfptr;
  if ( !BYTE4(vfptr->get_obj_type) )
  {
    BYTE4(vfptr->get_obj_type) = 1;
    vfptr->__vecDelDtor = (void *(__fastcall *)(SSObjectBase *, unsigned int))UFG::Metrics::msInstance.mSimTimeMSec;
  }
}

// File Line: 199
// RVA: 0x4FCB60
void __fastcall UFG::TSTimer::Mthd_get_elapsed_seconds(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // r8
  SSObjectBaseVtbl *vfptr; // rcx
  float v4; // xmm1_4
  float v5; // xmm0_4

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = i_obj_p[2].vfptr;
    v4 = *(float *)&vfptr->get_obj_type;
    if ( BYTE4(vfptr->get_obj_type) )
    {
      v5 = (float)(LODWORD(UFG::Metrics::msInstance.mSimTimeMSec) - LODWORD(vfptr->__vecDelDtor));
      if ( (__int64)(UFG::Metrics::msInstance.mSimTimeMSec - (unsigned __int64)vfptr->__vecDelDtor) < 0 )
        v5 = v5 + 1.8446744e19;
      v4 = v4 + (float)(v5 * 0.001);
    }
    *ppResult = SSInstance::pool_new(SSBrain::c_real_class_p, LODWORD(v4));
  }
}

