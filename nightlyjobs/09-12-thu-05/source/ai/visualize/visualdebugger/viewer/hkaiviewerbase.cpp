// File Line: 14
// RVA: 0xC3F870
void __fastcall hkaiViewerBase::hkaiViewerBase(
        hkaiViewerBase *this,
        hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkaiViewerContext *v2; // rbp
  int v3; // ebx
  __int64 v6; // rdi
  const char *v7; // rax
  hkProcessContext *v8; // rdx
  hkaiViewerContext *m_pntr; // rcx
  hkaiViewerContext *v10; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  v2 = 0i64;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiViewerBase::`vftable{for `hkReferencedObject};
  v3 = 0;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkaiViewerBase::`vftable{for `hkProcess};
  this->hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiViewerBase::`vftable{for `hkaiViewerContextWorldListener};
  this->m_context.m_pntr = 0i64;
  if ( contexts->m_size > 0 )
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = contexts->m_data[v6]->vfptr->getType(contexts->m_data[v6]);
      if ( !hkString::strCmp("ai", v7) )
        break;
      ++v3;
      ++v6;
      if ( v3 >= contexts->m_size )
        goto LABEL_13;
    }
    v8 = contexts->m_data[v3];
    if ( v8 )
      v2 = (hkaiViewerContext *)&v8[-1].m_monitorStreamEnds.m_storage[4];
    if ( v2 )
      hkReferencedObject::addReference(v2);
    m_pntr = this->m_context.m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
    this->m_context.m_pntr = v2;
  }
LABEL_13:
  v10 = this->m_context.m_pntr;
  if ( v10 )
    hkaiViewerContext::addWorldAddedListener(v10, &this->hkaiViewerContextWorldListener);
}

// File Line: 31
// RVA: 0xC3F970
void __fastcall hkaiViewerBase::~hkaiViewerBase(hkaiViewerBase *this)
{
  hkaiViewerContext *m_pntr; // rcx
  hkaiViewerContext *v3; // rcx
  hkaiViewerContext *v4; // rcx

  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkaiViewerBase::`vftable{for `hkReferencedObject};
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkaiViewerBase::`vftable{for `hkProcess};
  this->hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiViewerBase::`vftable{for `hkaiViewerContextWorldListener};
  m_pntr = this->m_context.m_pntr;
  if ( m_pntr )
  {
    hkaiViewerContext::removeWorldAddedListener(m_pntr, &this->hkaiViewerContextWorldListener);
    v3 = this->m_context.m_pntr;
    if ( v3 )
      hkReferencedObject::removeReference(v3);
    this->m_context.m_pntr = 0i64;
  }
  v4 = this->m_context.m_pntr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  this->m_context.m_pntr = 0i64;
  this->hkaiViewerContextWorldListener::vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiViewerContextWorldListener::`vftable;
  this->hkProcess::vfptr = (hkProcessVtbl *)&hkProcess::`vftable;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

