// File Line: 12
// RVA: 0xECFA00
OSuite::SHttpStatus *__fastcall OSuite::ZHttpUtils::GetHttpStatusFromRequest(
        OSuite::SHttpStatus *result,
        OSuite::IHttpRequest *pHttpRequest)
{
  __int64 v4; // rax
  int v5; // eax
  OSuite::ZObjectVtbl *vfptr; // rax
  __int64 v7; // rax
  OSuite::ZRedBlackTreeBase *v8; // rax
  OSuite::ZRedBlackTreeBase::ZElementBase *m_pElement; // rdi
  OSuite::ZString *v10; // rax
  OSuite::ZString *v11; // rbx
  OSuite::ZString *v12; // rax
  int v13; // ebx
  OSuite::AuthenticationManager *v14; // rax
  OSuite::AuthenticationManager *v15; // rax
  OSuite::ZRedBlackTreeBase::ZIteratorBase other; // [rsp+28h] [rbp-D8h] BYREF
  OSuite::ZString v18; // [rsp+88h] [rbp-78h] BYREF
  OSuite::ZString resulta; // [rsp+A0h] [rbp-60h] BYREF
  OSuite::ZString v20; // [rsp+B8h] [rbp-48h] BYREF
  void **v21; // [rsp+D0h] [rbp-30h]
  void **v22; // [rsp+D8h] [rbp-28h]
  OSuite::ZRedBlackTreeBase::ZIteratorBase v23; // [rsp+E0h] [rbp-20h] BYREF

  result->nHttpStatus = -1;
  result->eError = HTTPERROR_OK;
  result->eError = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[28].__vecDelDtor)(pHttpRequest);
  v4 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 32i64))(v4);
  result->nHttpStatus = v5;
  if ( v5 == 403 )
  {
    vfptr = pHttpRequest->vfptr;
    v23.m_pList = 0i64;
    v23.m_pElement = 0i64;
    v23.m_parents.m_pList = 0i64;
    v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))vfptr[33].__vecDelDtor)(pHttpRequest);
    v8 = (OSuite::ZRedBlackTreeBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v7 + 16i64))(v7);
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&other, v8);
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v21 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v22 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    OSuite::ZRedBlackTreeBase::ZIteratorBase::ZIteratorBase(&v23, &other);
    v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    other.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    other.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    other.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( other.m_parents.m_pList )
      other.m_parents.m_pList->vfptr->__vecDelDtor(other.m_parents.m_pList, 1u);
    while ( !OSuite::ZString::IsNull((OSuite::ZString *)&v23) )
    {
      m_pElement = v23.m_pElement;
      OSuite::ZString::ZString(&v18, "OS-Error");
      v11 = OSuite::ZString::ToLower(v10, &resulta);
      v12 = OSuite::ZString::ToLower((OSuite::ZString *)&m_pElement[1].m_pLeft, &v20);
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
    v22 = &OSuite::TOrderedMap<unsigned __int64,OSuite::TPair<enum OSuite::ZError::EError,OSuite::ZString>,OSuite::TOperatorComparer<unsigned __int64>>::ZIterator::`vftable;
    v21 = &OSuite::TConstIterator<OSuite::TOrderedMap<OSuite::ZString,OSuite::TList<OSuite::ZString>,OSuite::TOperatorComparer<OSuite::ZString>>::ZIterator,OSuite::TList<OSuite::ZString>,OSuite::ZString>::`vftable;
    v23.vfptr = (OSuite::ZObjectVtbl *)&OSuite::ZRedBlackTreeBase::TIterator<OSuite::TKeyValueElement<OSuite::ZString,OSuite::ZUsageTracker::ZResourceUsage *>>::`vftable;
    v23.m_parents.vfptr = (OSuite::ZObjectVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::ZObject};
    v23.m_parents.vfptr = (OSuite::IHashableVtbl *)&OSuite::TStack<OSuite::ZRedBlackTreeBase::ZElementBase *>::`vftable{for `OSuite::IHashable};
    if ( v23.m_parents.m_pList )
      v23.m_parents.m_pList->vfptr->__vecDelDtor(v23.m_parents.m_pList, 1u);
  }
  return result;
}

// File Line: 40
// RVA: 0xECF8FC
void __fastcall OSuite::ZHttpUtils::AnalyzeError(
        OSuite::SCallbackData *cbData,
        OSuite::IHttpRequest *pHttpRequest,
        int error)
{
  int v3; // edi
  __int64 v6; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  OSuite::SHttpStatus result; // [rsp+30h] [rbp+8h] BYREF

  v3 = 0;
  if ( error > 10 )
  {
    if ( error == 11 )
    {
      cbData->eEvent = EVENT_ABORTED;
      goto LABEL_16;
    }
    if ( ((error - 13) & 0xFFFFFFFB) != 0 )
    {
LABEL_7:
      cbData->eEvent = EVENT_FINISHED;
      goto LABEL_16;
    }
  }
  else if ( error != 10 )
  {
    if ( error <= 0 )
      goto LABEL_7;
    if ( error > 2 )
    {
      if ( error == 3 )
      {
        cbData->eEvent = EVENT_RESOURCE_ERROR;
        goto LABEL_16;
      }
      if ( (unsigned int)(error - 4) > 4 )
        goto LABEL_7;
    }
  }
  v6 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
  if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 88i64))(v6)
    && (v7 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest),
        (*(int (__fastcall **)(__int64))(*(_QWORD *)v7 + 32i64))(v7) / 100 == 4) )
  {
    v8 = ((__int64 (__fastcall *)(OSuite::IHttpRequest *))pHttpRequest->vfptr[33].__vecDelDtor)(pHttpRequest);
    LOBYTE(v3) = (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v8 + 32i64))(v8) != 403;
    cbData->eEvent = v3 + 1;
  }
  else
  {
    cbData->eEvent = EVENT_SERVER_ERROR;
  }
LABEL_16:
  cbData->Status = *OSuite::ZHttpUtils::GetHttpStatusFromRequest(&result, pHttpRequest);
}

