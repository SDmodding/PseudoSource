// File Line: 12
// RVA: 0xECFA00
OSuite::SHttpStatus *__fastcall OSuite::ZHttpUtils::GetHttpStatusFromRequest(OSuite::SHttpStatus *result, OSuite::IHttpRequest *pHttpRequest)
{
  OSuite::SHttpStatus *v2; // rsi
  OSuite::IHttpRequest *v3; // rbx
  __int64 v4; // rax
  int v5; // eax
  OSuite::ZObjectVtbl *v6; // rax
  __int64 v7; // rax
  OSuite::ZRedBlackTreeBase *v8; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *v9; // rdi
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rbx
  OSuite::ZString *v12; // rax
  int v13; // ebx
  OSuite::AuthenticationManager *v14; // rax
  OSuite::AuthenticationManager *v15; // rax
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+28h] [rbp-D8h]
  OSuite::ZString v18; // [rsp+88h] [rbp-78h]
  OSuite::ZString resulta; // [rsp+A0h] [rbp-60h]
  OSuite::ZString v20; // [rsp+B8h] [rbp-48h]
  void **v21; // [rsp+D0h] [rbp-30h]
  void **v22; // [rsp+D8h] [rbp-28h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v23; // [rsp+E0h] [rbp-20h]

  result->nHttpStatus = -1;
  result->eError = 0;
  v2 = result;
  v3 = pHttpRequest;
  result->eError = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[28].__vecDelDtor)(pHttpRequest);
  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v3->vfptr[33].__vecDelDtor)(v3);
  v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 32i64))(v4);
  v2->nHttpStatus = v5;
  if ( v5 == 403 )
  {
    v6 = v3->vfptr;
    v23.m_pList = 0i64;
    v23.m_pElement = 0i64;
    v23.m_parents.m_pList = 0i64;
    v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v6[33].__vecDelDtor)(v3);
    v8 = (OSuite::ZRedBlackTreeBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, v8);
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    v21 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    v22 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v23, &other);
    v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( other.m_parents.m_pList )
      other.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)other.m_parents.m_pList, 1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v23) )
    {
      v9 = v23.m_pElement;
      OSuite::ZString::ZString(&v18, "OS-Error");
      v11 = OSuite::ZString::ToLower(v10, &resulta);
      v12 = OSuite::ZString::ToLower((OSuite::ZString *)&v9[1].m_pLeft, &v20);
      LOBYTE(v11) = OSuite::ZString::operator==(v12, v11);
      OSuite::ZString::~ZString(&v20);
      OSuite::ZString::~ZString(&resulta);
      OSuite::ZString::~ZString(&v18);
      if ( (_BYTE)v11 )
      {
        v13 = OSuite::ZString::ToInt((OSuite::ZString *)&v23.m_pElement[2]);
        v14 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
        if ( OSuite::AuthenticationManager::IsTicketFound(v14) && v13 == 2 )
        {
          v15 = OSuite::TSingleton<OSuite::AuthenticationManager>::Object();
          OSuite::AuthenticationManager::ForceTicketUpdate(v15);
        }
        break;
      }
      OSuite::ZRedBlackTreeBase::ZIteratorBase::Next(&v23);
    }
    v22 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum  OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable';
    v21 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable';
    v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable';
    v23.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::ZObject'};
    v23.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable'{for `OSuite::IHashable'};
    if ( v23.m_parents.m_pList )
      v23.m_parents.m_pList->vfptr->__vecDelDtor((OSuite::ZObject *)v23.m_parents.m_pList, 1u);
  }
  return v2;
}

// File Line: 40
// RVA: 0xECF8FC
void __fastcall OSuite::ZHttpUtils::AnalyzeError(OSuite::SCallbackData *cbData, OSuite::IHttpRequest *pHttpRequest, OSuite::ZHttp::EError error)
{
  int v3; // edi
  OSuite::IHttpRequest *v4; // rsi
  OSuite::SHttpStatus *v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  OSuite::SHttpStatus result; // [rsp+30h] [rbp+8h]

  v3 = 0;
  v4 = pHttpRequest;
  v5 = &cbData->Status;
  if ( (signed int)error > 10 )
  {
    if ( error == 11 )
    {
      cbData->eEvent = 5;
      goto LABEL_17;
    }
    if ( (error - 13) & 0xFFFFFFFB )
    {
LABEL_8:
      cbData->eEvent = 4;
      goto LABEL_17;
    }
  }
  else if ( error != 10 )
  {
    if ( error == HTTPERROR_OK || (signed int)error <= 0 )
      goto LABEL_8;
    if ( (signed int)error > 2 )
    {
      if ( error == 3 )
      {
        cbData->eEvent = 2;
        goto LABEL_17;
      }
      if ( (unsigned int)(error - 4) > 4 )
        goto LABEL_8;
    }
  }
  v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 88i64))(v6)
    && (v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[33].__vecDelDtor)(v4),
        (*(signed int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) / 100 == 4) )
  {
    v8 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))v4->vfptr[33].__vecDelDtor)(v4);
    LOBYTE(v3) = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v8 + 32i64))(v8) != 403;
    v5[1].nHttpStatus = v3 + 1;
  }
  else
  {
    v5[1].nHttpStatus = 3;
  }
LABEL_17:
  *v5 = *OSuite::ZHttpUtils::GetHttpStatusFromRequest(&result, v4);
}

