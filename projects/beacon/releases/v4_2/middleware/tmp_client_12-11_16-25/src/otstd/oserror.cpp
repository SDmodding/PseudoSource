// File Line: 7
// RVA: 0xEE45A4
char *__fastcall OSuite::ZError::GetErrorString(OSuite::ZError::EError eError)
{
  return &customWorldMapCaption;
}

// File Line: 74
// RVA: 0xEE3DDC
void __fastcall OSuite::ZError::ZError(OSuite::ZError *this)
{
  OSuite::ZError *v1; // rdi
  OSuite::ZString *v2; // rax
  OSuite::ZString v3; // [rsp+20h] [rbp-28h]

  v1 = this;
  this->vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZError::`vftable;
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::TMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>(
    &this->m_threadsErrorMap,
    0x10ui64);
  v1->m_enumerator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  v1->m_enumerator.m_iterator.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase((OSuite::ZRedBlackTreeBase::ZIteratorBase *)&v1->m_enumerator.m_iterator.m_iterator.vfptr);
  v1->m_enumerator.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  v1->m_errorDelegate.m_Closure.m_pFunction = 0i64;
  v1->m_errorDelegate.m_Closure.m_pthis = 0i64;
  OSuite::ZMutex::ZMutex(&v1->m_mutex);
  OSuite::ZString::ZString(&v3, "Ok");
  v1->m_noError.m_First = 0;
  v1->m_noError.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
  OSuite::ZString::ZString(&v1->m_noError.m_Second, v2);
  OSuite::ZString::~ZString(&v3);
}

// File Line: 78
// RVA: 0xEE45AC
OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *__fastcall OSuite::ZError::GetThreadLastError(OSuite::ZError *this)
{
  OSuite::ZMutex *v1; // rbx
  OSuite::ZError *v2; // rdi
  unsigned __int64 v3; // rax
  bool v4; // zf
  OSuite::ZRedBlackTreeBase::ZElementBase *v5; // rdi
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *v6; // rax
  unsigned __int64 key; // [rsp+20h] [rbp-49h]
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> >::ZIterator result; // [rsp+30h] [rbp-39h]

  v1 = &this->m_mutex;
  v2 = this;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v3 = OSuite::ZThread::GetCurrentTID();
  result.m_pMap = 0i64;
  result.m_iterator.m_iterator.m_pList = 0i64;
  result.m_iterator.m_iterator.m_pElement = 0i64;
  result.m_iterator.m_iterator.m_parents.m_pList = 0i64;
  key = v3;
  OSuite::TMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::Find(
    &v2->m_threadsErrorMap,
    &result,
    &key);
  v4 = (unsigned __int8)OSuite::ZString::IsNull((OSuite::ZString *)&result.m_iterator.m_iterator) == 0;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
  result.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TMap<OSuite::ZString,OSuite::ZJsonValue *>::ZIterator::`vftable;
  result.m_iterator.vfptr = (OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64> >::ZIteratorVtbl *)&OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
  result.m_iterator.m_iterator.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
  result.m_iterator.m_iterator.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
  if ( v4 )
  {
    v5 = result.m_iterator.m_iterator.m_pElement;
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(v1);
    v6 = (OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *)&v5[1].m_pRight;
  }
  else
  {
    if ( result.m_iterator.m_iterator.m_parents.m_pList )
      result.m_iterator.m_iterator.m_parents.m_pList->vfptr->__vecDelDtor(
        (OSuite::ZObject *)result.m_iterator.m_iterator.m_parents.m_pList,
        1u);
    OSuite::ZMutex::Unlock(v1);
    v6 = &v2->m_noError;
  }
  return v6;
}

// File Line: 101
// RVA: 0xEE480C
void __fastcall OSuite::ZError::SetThreadLastError(OSuite::ZError *this, OSuite::ZError::EError eError, OSuite::ZString *details, bool report)
{
  OSuite::ZMutex *v4; // rbx
  OSuite::ZError *v5; // rdi
  bool v6; // r15
  OSuite::ZString *v7; // r14
  OSuite::ZError::EError v8; // esi
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *v9; // rax
  unsigned __int64 v10; // rax
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> value; // [rsp+20h] [rbp-60h]
  unsigned __int64 key; // [rsp+48h] [rbp-38h]
  void **v13; // [rsp+50h] [rbp-30h]
  OSuite::ZError::EError v14; // [rsp+58h] [rbp-28h]
  OSuite::ZString v15; // [rsp+60h] [rbp-20h]

  v4 = &this->m_mutex;
  v5 = this;
  v6 = report;
  v7 = details;
  v8 = eError;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v15.m_pString = 0i64;
  v9 = OSuite::ZError::GetThreadLastError(v5);
  v13 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
  v14 = v9->m_First;
  OSuite::ZString::ZString(&v15, &v9->m_Second);
  if ( v14 == v8 && OSuite::ZString::operator==(&v15, v7) )
  {
    v13 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZMutex::Unlock(v4);
  }
  else
  {
    value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
    value.m_First = v8;
    key = OSuite::ZThread::GetCurrentTID();
    OSuite::ZString::ZString(&value.m_Second, v7);
    OSuite::TMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::Insert(
      &v5->m_threadsErrorMap,
      &key,
      &value);
    value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&value.m_Second);
    v13 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZMutex::Unlock(v4);
    if ( v5->m_errorDelegate.m_Closure.m_pthis || v5->m_errorDelegate.m_Closure.m_pFunction )
    {
      if ( v8 )
      {
        if ( v6 )
        {
          value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
          value.m_First = v8;
          OSuite::ZString::ZString(&value.m_Second);
          v10 = OSuite::ZThread::GetCurrentTID();
          ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, unsigned __int64, OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *))v5->m_errorDelegate.m_Closure.m_pFunction)(
            v5->m_errorDelegate.m_Closure.m_pthis,
            v10,
            &value);
          value.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
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
  OSuite::ZMutex *v3; // rbx
  OSuite::ZError *v4; // rdi
  bool v5; // r14
  OSuite::ZError::EError v6; // esi
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *v7; // rax
  OSuite::ZString *v8; // rax
  unsigned __int64 v9; // rax
  OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> value; // [rsp+8h] [rbp-39h]
  unsigned __int64 key; // [rsp+30h] [rbp-11h]
  OSuite::ZString v12; // [rsp+38h] [rbp-9h]
  void **v13; // [rsp+50h] [rbp+Fh]
  OSuite::ZError::EError v14; // [rsp+58h] [rbp+17h]
  OSuite::ZString v15; // [rsp+60h] [rbp+1Fh]

  v3 = &this->m_mutex;
  v4 = this;
  v5 = report;
  v6 = eError;
  OSuite::ZMutex::Lock(&this->m_mutex);
  v15.m_pString = 0i64;
  v7 = OSuite::ZError::GetThreadLastError(v4);
  v13 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
  v14 = v7->m_First;
  OSuite::ZString::ZString(&v15, &v7->m_Second);
  if ( v14 == v6 )
  {
    v13 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZMutex::Unlock(v3);
  }
  else
  {
    key = OSuite::ZThread::GetCurrentTID();
    OSuite::ZString::ZString(&v12);
    OSuite::ZString::ZString(&value.m_Second, v8);
    OSuite::TMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>>::Insert(
      &v4->m_threadsErrorMap,
      &key,
      &value);
    OSuite::ZString::~ZString(&value.m_Second);
    OSuite::ZString::~ZString(&v12);
    v13 = &OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>::`vftable;
    OSuite::ZString::~ZString(&v15);
    OSuite::ZMutex::Unlock(v3);
    if ( v4->m_errorDelegate.m_Closure.m_pthis || v4->m_errorDelegate.m_Closure.m_pFunction )
    {
      if ( v6 )
      {
        if ( v5 )
        {
          OSuite::ZString::ZString(&value.m_Second);
          v9 = OSuite::ZThread::GetCurrentTID();
          ((void (__fastcall *)(OSuite::fastdelegate::detail::GenericClass *, unsigned __int64, OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> *))v4->m_errorDelegate.m_Closure.m_pFunction)(
            v4->m_errorDelegate.m_Closure.m_pthis,
            v9,
            &value);
          OSuite::ZString::~ZString(&value.m_Second);
        }
      }
    }
  }
}

// File Line: 167
// RVA: 0xEE47F4
void __fastcall OSuite::ZError::SetErrorDelegate(OSuite::ZError *this, OSuite::fastdelegate::FastDelegate2<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString> const &,void> *errorDelegate)
{
  this->m_errorDelegate = *errorDelegate;
}

