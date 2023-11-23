// File Line: 7
// RVA: 0xEE45A4
char *__fastcall OSuite::ZError::GetErrorString(OSuite::ZError::EError eError)
{
  return &customCaption;
}

// File Line: 74
// RVA: 0xEE3DDC
void __fastcall OSuite::ZError::ZError(OSuite::ZError *this)
{
  OSuite::ZString *v2; // rax
  OSuite::ZString v3; // [rsp+20h] [rbp-28h] BYREF

  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZError::`vftable;
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>(
    &this->m_threadsErrorMap,
    0x10ui64);
  this->m_enumerator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  this->m_enumerator.m_iterator.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&this->m_enumerator.m_iterator.m_iterator);
  this->m_enumerator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  this->m_errorDelegate.m_Closure.m_pFunction = 0i64;
  this->m_errorDelegate.m_Closure.m_pthis = 0i64;
  OSuite::ZMutex::ZMutex(&this->m_mutex);
  OSuite::ZString::ZString(&v3, "Ok");
  this->m_noError.m_First = ZERROR_OK;
  this->m_noError.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
  OSuite::ZString::ZString(&this->m_noError.m_Second, v2);
  OSuite::ZString::~ZString(&v3);
}

// File Line: 78
// RVA: 0xEE45AC
OSuite::ZRedBlackTreeBase::ZElementBase **__fastcall OSuite::ZError::GetThreadLastError(OSuite::ZError *this)
{
  OSuite::ZMutex *p_m_mutex; // rbx
  unsigned __int64 CurrentTID; // rax
  bool v4; // zf
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pElement; // rdi
  unsigned __int64 key; // [rsp+20h] [rbp-49h] BYREF
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> >::ZIterator result; // [rsp+30h] [rbp-39h] BYREF

  p_m_mutex = &this->m_mutex;
  OSuite::ZMutex::Lock(&this->m_mutex);
  CurrentTID = OSuite::ZThread::GetCurrentTID();
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  key = CurrentTID;
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::Find(
    &this->m_threadsErrorMap,
    &result,
    (_exception *)&key);
  v4 = !OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator);
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  if ( v4 )
  {
    m_pElement = result.m_iterator.m_iterator.m_pElement;
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(p_m_mutex);
    return &m_pElement[1].m_pRight;
  }
  else
  {
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(p_m_mutex);
    return (OSuite::ZRedBlackTreeBase::ZElementBase **)&this->m_noError;
  }
}

// File Line: 101
// RVA: 0xEE480C
void __fastcall OSuite::ZError::SetThreadLastError(
        OSuite::ZError *this,
        OSuite::ZError::EError eError,
        OSuite::ZString *details,
        bool report)
{
  OSuite::ZMutex *p_m_mutex; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase **ThreadLastError; // rax
  unsigned __int64 CurrentTID; // rax
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> value; // [rsp+20h] [rbp-60h] BYREF
  unsigned __int64 key; // [rsp+48h] [rbp-38h] BYREF
  void **v13; // [rsp+50h] [rbp-30h]
  int v14; // [rsp+58h] [rbp-28h]
  OSuite::ZString v15; // [rsp+60h] [rbp-20h] BYREF

  p_m_mutex = &this->m_mutex;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v15.m_pString = 0i64;
  ThreadLastError = OSuite::ZError::GetThreadLastError(this);
  v13 = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
  v14 = *((_DWORD *)ThreadLastError + 2);
  OSuite::ZString::ZString(&v15, (OSuite::ZString *)(ThreadLastError + 2));
  if ( v14 == eError && OSuite::ZString::operator==(&v15, details) )
  {
    v13 = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZMutex::Unlock(p_m_mutex);
  }
  else
  {
    value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
    value.m_First = eError;
    key = OSuite::ZThread::GetCurrentTID();
    OSuite::ZString::ZString(&value.m_Second, details);
    OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::Insert(
      &this->m_threadsErrorMap,
      (_exception *)&key,
      &value);
    value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&value.m_Second);
    v13 = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZMutex::Unlock(p_m_mutex);
    if ( this->m_errorDelegate.m_Closure.m_pthis || this->m_errorDelegate.m_Closure.m_pFunction )
    {
      if ( eError )
      {
        if ( report )
        {
          value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
          value.m_First = eError;
          OSuite::ZString::ZString(&value.m_Second);
          CurrentTID = OSuite::ZThread::GetCurrentTID();
          ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, unsigned __int64, OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *))this->m_errorDelegate.m_Closure.m_pFunction)(
            this->m_errorDelegate.m_Closure.m_pthis,
            CurrentTID,
            &value);
          value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
          OSuite::ZString::~ZString(&value.m_Second);
        }
      }
    }
  }
}

// File Line: 116
// RVA: 0xEE4974
void __fastcall OSuite::ZError::SetThreadLastError(OSuite::ZError *this, OSuite::ZError::EError eError, bool report)
{
  OSuite::ZMutex *p_m_mutex; // rbx
  OSuite::ZRedBlackTreeBase::ZElementBase **ThreadLastError; // rax
  OSuite::ZString *v8; // rax
  unsigned __int64 CurrentTID; // rax
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> value; // [rsp+8h] [rbp-39h] BYREF
  _exception key; // [rsp+30h] [rbp-11h] BYREF
  int v12; // [rsp+58h] [rbp+17h]
  OSuite::ZString v13; // [rsp+60h] [rbp+1Fh] BYREF

  p_m_mutex = &this->m_mutex;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v13.m_pString = 0i64;
  ThreadLastError = OSuite::ZError::GetThreadLastError(this);
  *(_QWORD *)&key.retval = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
  v12 = *((_DWORD *)ThreadLastError + 2);
  OSuite::ZString::ZString(&v13, (OSuite::ZString *)(ThreadLastError + 2));
  if ( v12 == eError )
  {
    *(_QWORD *)&key.retval = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v13);
    OSuite::ZMutex::Unlock(p_m_mutex);
  }
  else
  {
    *(_QWORD *)&key.type = OSuite::ZThread::GetCurrentTID();
    OSuite::ZString::ZString((OSuite::ZString *)&key.name);
    OSuite::ZString::ZString(&value.m_Second, v8);
    OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>>::Insert(
      &this->m_threadsErrorMap,
      &key,
      &value);
    OSuite::ZString::~ZString(&value.m_Second);
    OSuite::ZString::~ZString((OSuite::ZString *)&key.name);
    *(_QWORD *)&key.retval = &OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v13);
    OSuite::ZMutex::Unlock(p_m_mutex);
    if ( this->m_errorDelegate.m_Closure.m_pthis || this->m_errorDelegate.m_Closure.m_pFunction )
    {
      if ( eError )
      {
        if ( report )
        {
          OSuite::ZString::ZString(&value.m_Second);
          CurrentTID = OSuite::ZThread::GetCurrentTID();
          ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, unsigned __int64, OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *))this->m_errorDelegate.m_Closure.m_pFunction)(
            this->m_errorDelegate.m_Closure.m_pthis,
            CurrentTID,
            &value);
          OSuite::ZString::~ZString(&value.m_Second);
        }
      }
    }
  }
}

// File Line: 167
// RVA: 0xEE47F4
void __fastcall OSuite::ZError::SetErrorDelegate(
        OSuite::ZError *this,
        OSuite::fastdelegate::FastDelegate2<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> const &,void> *errorDelegate)
{
  this->m_errorDelegate = *errorDelegate;
}

