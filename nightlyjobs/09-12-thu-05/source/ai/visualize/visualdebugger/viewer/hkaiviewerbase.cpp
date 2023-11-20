// File Line: 14
// RVA: 0xC3F870
void __fastcall hkaiViewerBase::hkaiViewerBase(hkaiViewerBase *this, hkArray<hkProcessContext *,hkContainerHeapAllocator> *contexts)
{
  hkReferencedObject *v2; // rbp
  int v3; // ebx
  hkArray<hkProcessContext *,hkContainerHeapAllocator> *v4; // r14
  hkaiViewerBase *v5; // rsi
  __int64 v6; // rdi
  const char *v7; // rax
  hkProcessContext *v8; // rdx
  hkReferencedObject *v9; // rcx
  hkaiViewerContext *v10; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_selectable.m_bool = 1;
  v2 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiViewerBase::`vftable'{for `hkReferencedObject'};
  v3 = 0;
  this->vfptr = (hkProcessVtbl *)&hkaiViewerBase::`vftable'{for `hkProcess'};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiViewerBase::`vftable'{for `hkaiViewerContextWorldListener'};
  this->m_context.m_pntr = 0i64;
  v4 = contexts;
  v5 = this;
  if ( contexts->m_size > 0 )
  {
    v6 = 0i64;
    while ( 1 )
    {
      v7 = (const char *)((__int64 (*)(void))v4->m_data[v6]->vfptr->getType)();
      if ( !hkString::strCmp("ai", v7) )
        break;
      ++v3;
      ++v6;
      if ( v3 >= v4->m_size )
        goto LABEL_13;
    }
    v8 = v4->m_data[v3];
    if ( v8 )
      v2 = (hkReferencedObject *)&v8[-1].m_monitorStreamEnds.m_storage[4];
    if ( v2 )
      hkReferencedObject::addReference(v2);
    v9 = (hkReferencedObject *)&v5->m_context.m_pntr->vfptr;
    if ( v9 )
      hkReferencedObject::removeReference(v9);
    v5->m_context.m_pntr = (hkaiViewerContext *)v2;
  }
LABEL_13:
  v10 = v5->m_context.m_pntr;
  if ( v10 )
    hkaiViewerContext::addWorldAddedListener(v10, (hkaiViewerContextWorldListener *)&v5->vfptr);
}

// File Line: 31
// RVA: 0xC3F970
void __fastcall hkaiViewerBase::~hkaiViewerBase(hkaiViewerBase *this)
{
  hkaiViewerBase *v1; // rbx
  hkaiViewerContext *v2; // rcx
  hkReferencedObject *v3; // rcx
  hkReferencedObject *v4; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiViewerBase::`vftable'{for `hkReferencedObject'};
  this->vfptr = (hkProcessVtbl *)&hkaiViewerBase::`vftable'{for `hkProcess'};
  this->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiViewerBase::`vftable'{for `hkaiViewerContextWorldListener'};
  v2 = this->m_context.m_pntr;
  if ( v2 )
  {
    hkaiViewerContext::removeWorldAddedListener(v2, (hkaiViewerContextWorldListener *)&v1->vfptr);
    v3 = (hkReferencedObject *)&v1->m_context.m_pntr->vfptr;
    if ( v3 )
      hkReferencedObject::removeReference(v3);
    v1->m_context.m_pntr = 0i64;
  }
  v4 = (hkReferencedObject *)&v1->m_context.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v1->m_context.m_pntr = 0i64;
  v1->vfptr = (hkaiViewerContextWorldListenerVtbl *)&hkaiViewerContextWorldListener::`vftable';
  v1->vfptr = (hkProcessVtbl *)&hkProcess::`vftable';
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

