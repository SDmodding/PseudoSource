// File Line: 77
// RVA: 0x6F6560
__int64 __fastcall Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *memberName)
{
  char v4; // bl
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *p_pWatchpoints; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v6; // rdi
  __int64 v7; // rax
  unsigned __int64 *v8; // rcx

  v4 = -1;
  if ( (memberName->pNode->HashFlags & 0x20000000) != 0 )
  {
    p_pWatchpoints = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_XMLNode)[1].pWatchpoints;
    v6.pTable = p_pWatchpoints->pTable;
    if ( p_pWatchpoints->pTable )
    {
      v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             p_pWatchpoints,
             memberName,
             v6.pTable->SizeMask & memberName->pNode->HashFlags);
      if ( v7 >= 0 )
      {
        v8 = &v6.pTable[1].SizeMask + 3 * v7;
        if ( v8 )
          return (unsigned int)(char)*((_BYTE *)v8 + 8);
      }
    }
  }
  return (unsigned int)v4;
}

// File Line: 95
// RVA: 0x6FD6F0
void __fastcall Scaleform::GFx::AS2::XmlNodeObject::InitializeStandardMembers(
        Scaleform::GFx::AS2::GlobalContext *gc,
        Scaleform::GFx::ASStringHash<char> *hash)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rsi
  Scaleform::GFx::AS2::GASDocument *v4; // rbx
  const char *pName; // r8
  unsigned __int64 v6; // r9
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h] BYREF
  char Id; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF

  vfptr = gc->pMovieRoot->pASMovieRoot.pObject[39].vfptr;
  if ( !hash->mHash.pTable || hash->mHash.pTable->EntryCount < 0x10 )
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      &hash->mHash,
      hash,
      0x10ui64);
  v4 = Scaleform::GFx::AS2::XmlNodeObject_MemberTable;
  if ( Scaleform::GFx::AS2::XmlNodeObject_MemberTable[0].pName )
  {
    key.pFirst = &result;
    key.pSecond = &Id;
    do
    {
      pName = v4->pName;
      v6 = -1i64;
      do
        ++v6;
      while ( pName[v6] );
      Scaleform::GFx::ASStringManager::CreateConstString(
        (Scaleform::GFx::ASStringManager *)vfptr,
        &result,
        pName,
        v6,
        0x20000000u);
      Id = v4->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        &hash->mHash,
        hash,
        &key,
        result.pNode->HashFlags);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      ++v4;
    }
    while ( v4->pName );
  }
}

// File Line: 119
// RVA: 0x71F910
void __fastcall Scaleform::GFx::AS2::SetupAttributes(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *preal)
{
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // rbp
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v6; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v7; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *vfptr; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::Attribute *i; // rdi
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS2::Value v17; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+90h] [rbp+8h] BYREF
  Scaleform::GFx::ASString v19; // [rsp+98h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+18h] BYREF

  pShadow = preal->pShadow;
  pHeap = penv->StringContext.pContext->pHeap;
  v5 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::Environment *, __int64))pHeap->vfptr->Alloc)(
                                         penv,
                                         96i64);
  v19.pNode = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v5, penv);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)pShadow[2].vfptr;
  if ( vfptr )
  {
    RefCount = vfptr->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      vfptr->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(vfptr);
    }
  }
  pShadow[2].vfptr = v7;
  if ( UFG::UIGfxTexture::IsValid(preal) )
  {
    for ( i = preal->FirstAttribute; i; i = i->Next )
    {
      v11 = Scaleform::GFx::AS2::ASStringContext::CreateString(&penv->StringContext, &result, i->Value.pNode->pData);
      v17.T.Type = 5;
      v17.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
      ++v17.V.pStringNode->RefCount;
      v12 = pShadow[2].vfptr;
      v13 = Scaleform::GFx::AS2::ASStringContext::CreateString(&penv->StringContext, &v19, i->Name.pNode->pData);
      LOBYTE(pHeap) = 0;
      (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))v12[4].__vecDelDtor
       + 3))(
        v12 + 4,
        penv,
        v13,
        &v17,
        &pHeap);
      pNode = v19.pNode;
      v15 = v19.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
      v16 = result.pNode;
      v15 = result.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    Scaleform::GFx::XML::ElementNode::ClearAttributes(preal);
  }
}

// File Line: 145
// RVA: 0x71FA90
void __fastcall Scaleform::GFx::AS2::SetupShadow(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *preal,
        Scaleform::GFx::XML::ShadowRefBaseVtbl *asobj)
{
  Scaleform::GFx::XML::ShadowRefBase *v6; // rax

  if ( !preal->pShadow )
  {
    v6 = (Scaleform::GFx::XML::ShadowRefBase *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::Environment *, __int64))preal->MemoryManager.pObject->pHeap->vfptr->Alloc)(
                                                 penv,
                                                 24i64);
    if ( v6 )
    {
      v6->vfptr = (Scaleform::GFx::XML::ShadowRefBaseVtbl *)&Scaleform::GFx::XML::ShadowRefBase::`vftable;
      v6->vfptr = (Scaleform::GFx::XML::ShadowRefBaseVtbl *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable;
      v6[1].vfptr = 0i64;
      v6[2].vfptr = 0i64;
    }
    preal->pShadow = v6;
    if ( preal->Type == 1 )
      Scaleform::GFx::AS2::SetupAttributes(penv, preal);
  }
  preal->pShadow[1].vfptr = asobj;
  asobj[13].__vecDelDtor = (void *(__fastcall *)(Scaleform::GFx::XML::ShadowRefBase *, unsigned int))preal;
}

// File Line: 166
// RVA: 0x6E10E0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::CreateShadow(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::Node *preal,
        Scaleform::GFx::XML::RootNode *proot)
{
  Scaleform::GFx::AS2::XmlNodeObject *v8; // r14
  Scaleform::GFx::AS2::XmlNodeObject *v9; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v10; // rax
  Scaleform::GFx::AS2::XmlNodeObject *vfptr; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx

  v8 = 0i64;
  v9 = (Scaleform::GFx::AS2::XmlNodeObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(result, 112i64, 0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v9, penv);
    v8 = v10;
  }
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v8;
  Scaleform::GFx::AS2::SetupShadow(penv, preal, (Scaleform::GFx::AS2::XmlNodeObject *)result->vfptr);
  vfptr = (Scaleform::GFx::AS2::XmlNodeObject *)result->vfptr;
  if ( proot )
    ++proot->RefCount;
  else
    proot = Scaleform::GFx::XML::ObjectManager::CreateRootNode(preal->MemoryManager.pObject, preal);
  pObject = vfptr->pRootNode.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  vfptr->pRootNode.pObject = proot;
  return result;
}

// File Line: 183
// RVA: 0x724AD0
void __fastcall Scaleform::GFx::AS2::Xml_CreateIDMap(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *elemNode,
        Scaleform::GFx::XML::RootNode *proot,
        Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::XML::RootNode *v5; // rdi
  Scaleform::GFx::XML::ElementNode *i; // rsi
  Scaleform::GFx::XML::Attribute *FirstAttribute; // rbx
  Scaleform::MemoryHeap *v9; // rcx
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // rbx
  Scaleform::MemoryHeap *Shadow; // rax
  Scaleform::MemoryHeapVtbl *vfptr; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::XmlNodeObject *v15; // rax
  Scaleform::MemoryHeapVtbl *v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Value *v18; // rdi
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v22; // eax
  Scaleform::String str; // [rsp+38h] [rbp-70h] BYREF
  Scaleform::GFx::ASString v24; // [rsp+40h] [rbp-68h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+50h] [rbp-58h]
  Scaleform::GFx::AS2::XmlNodeObject *v27; // [rsp+58h] [rbp-50h]
  __int64 v28; // [rsp+60h] [rbp-48h]
  Scaleform::GFx::AS2::Value v29; // [rsp+68h] [rbp-40h] BYREF
  char v30; // [rsp+B8h] [rbp+10h] BYREF
  Scaleform::GFx::XML::RootNode *v31; // [rsp+C0h] [rbp+18h]
  Scaleform::GFx::AS2::Object *v32; // [rsp+C8h] [rbp+20h]

  v32 = pobj;
  v31 = proot;
  v28 = -2i64;
  v4 = pobj;
  v5 = proot;
  for ( i = (Scaleform::GFx::XML::ElementNode *)elemNode->FirstChild.pObject;
        i;
        i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
  {
    if ( i->Type == 1 )
    {
      Scaleform::GFx::AS2::Xml_CreateIDMap(penv, i, v5, v4);
      FirstAttribute = i->FirstAttribute;
      if ( FirstAttribute )
      {
        while ( strncmp(FirstAttribute->Name.pNode->pData, "id", 2ui64) )
        {
          FirstAttribute = FirstAttribute->Next;
          if ( !FirstAttribute )
            goto LABEL_30;
        }
        Scaleform::String::String(&str, FirstAttribute->Value.pNode->pData, FirstAttribute->Value.pNode->Size);
        pShadow = i->pShadow;
        if ( pShadow )
        {
          vfptr = (Scaleform::MemoryHeapVtbl *)pShadow[1].vfptr;
          if ( vfptr )
            *(_DWORD *)&vfptr->gap8[16] = (*(_DWORD *)&vfptr->gap8[16] + 1) & 0x8FFFFFFF;
          if ( !vfptr )
          {
            pHeap = penv->StringContext.pContext->pHeap;
            v15 = (Scaleform::GFx::AS2::XmlNodeObject *)pHeap->vfptr->Alloc(v9, 112ui64, 0i64);
            v27 = v15;
            if ( v15 )
            {
              Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v15, penv);
              vfptr = v16;
            }
            else
            {
              vfptr = 0i64;
            }
            Scaleform::GFx::AS2::SetupShadow(penv, i, (Scaleform::GFx::XML::ShadowRefBaseVtbl *)vfptr);
          }
        }
        else
        {
          Shadow = Scaleform::GFx::AS2::CreateShadow((Scaleform::MemoryHeap *)&result, penv, i, v5);
          if ( Shadow->vfptr )
            *(_DWORD *)&Shadow->vfptr->gap8[16] = (*(_DWORD *)&Shadow->vfptr->gap8[16] + 1) & 0x8FFFFFFF;
          vfptr = Shadow->vfptr;
          pObject = result.pObject;
          if ( result.pObject )
          {
            RefCount = result.pObject->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              result.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
            }
          }
        }
        Scaleform::GFx::AS2::Value::Value(&v29, (Scaleform::GFx::ASStringNode *)vfptr);
        v18 = v17;
        v19 = Scaleform::GFx::AS2::Environment::CreateString(penv, &v24, &str);
        v30 = 0;
        v32->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMember(
          &v32->Scaleform::GFx::AS2::ObjectInterface,
          penv,
          v19,
          v18,
          (Scaleform::GFx::AS2::PropFlags *)&v30);
        pNode = v24.pNode;
        if ( v24.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        if ( vfptr )
        {
          v22 = *(_DWORD *)&vfptr->gap8[16];
          if ( (v22 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)&vfptr->gap8[16] = v22 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)vfptr);
          }
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v5 = v31;
      }
LABEL_30:
      v4 = v32;
    }
  }
}

// File Line: 236
// RVA: 0x7123D0
void __fastcall Scaleform::GFx::AS2::ResolveNamespace(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *elemNode,
        Scaleform::GFx::XML::RootNode *proot)
{
  const char *pData; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::XML::DOMString *v8; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v9; // rcx
  Scaleform::GFx::XML::ElementNode *i; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  int RefCount; // eax
  __int64 v13; // rcx
  Scaleform::GFx::XML::DOMString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::AS2::Value v18; // [rsp+28h] [rbp-28h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+30h] BYREF
  Scaleform::GFx::XML::DOMString v20; // [rsp+88h] [rbp+38h] BYREF
  Scaleform::GFx::XML::DOMString v21; // [rsp+98h] [rbp+48h] BYREF

  Scaleform::GFx::AS2::ASStringContext::CreateString(&penv->StringContext, &result, "xmlns", 5ui64);
  if ( elemNode->Prefix.pNode->Size )
  {
    Scaleform::GFx::ASString::Append(&result, ":", 1ui64);
    pData = elemNode->Prefix.pNode->pData;
    v7 = -1i64;
    do
      ++v7;
    while ( pData[v7] );
    Scaleform::GFx::ASString::Append(&result, pData, v7);
  }
  v18.T.Type = 0;
  v8 = Scaleform::GFx::XML::ObjectManager::EmptyString(elemNode->MemoryManager.pObject, &v20);
  Scaleform::GFx::XML::DOMString::AssignNode(&elemNode->Namespace, v8->pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v20);
  v9 = elemNode->pShadow[2].vfptr + 4;
  (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v9->__vecDelDtor
   + 4))(
    v9,
    penv,
    &result,
    &v18,
    -2i64);
  if ( v18.T.Type && v18.T.Type != 10 )
  {
LABEL_16:
    Scaleform::GFx::AS2::Value::ToString(&v18, (Scaleform::GFx::ASString *)&v20, penv, -1);
    v14 = Scaleform::GFx::XML::ObjectManager::CreateString(
            elemNode->MemoryManager.pObject,
            &v21,
            v20.pNode->pData,
            LODWORD(v20.pNode[1].pData));
    Scaleform::GFx::XML::DOMString::AssignNode(&elemNode->Namespace, v14->pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v21);
    pNode = (Scaleform::GFx::ASStringNode *)v20.pNode;
    v16 = v20.pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    for ( i = elemNode->Parent; i; i = i->Parent )
    {
      if ( !i->pShadow )
      {
        Scaleform::GFx::AS2::CreateShadow((Scaleform::MemoryHeap *)&v20, penv, i, proot);
        v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v20.pNode;
        if ( v20.pNode )
        {
          RefCount = v20.pNode->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v20.pNode->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
          }
        }
      }
      v13 = (__int64)&i->pShadow[2].vfptr[4];
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v13 + 32i64))(
        v13,
        penv,
        &result,
        &v18);
      if ( v18.T.Type && v18.T.Type != 10 )
        goto LABEL_16;
    }
  }
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
  v17 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
}

// File Line: 298
// RVA: 0x6CDC20
void __fastcall Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pRootNode.pObject = 0i64;
  this->pRealNode = 0i64;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_XMLNode);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 307
// RVA: 0x6D2B60
void __fastcall Scaleform::GFx::AS2::XmlNodeObject::~XmlNodeObject(Scaleform::GFx::AS2::XmlNodeObject *this)
{
  Scaleform::GFx::XML::Node *pRealNode; // rax
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // rax
  Scaleform::GFx::XML::RootNode *pObject; // rcx

  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  pRealNode = this->pRealNode;
  if ( pRealNode )
  {
    pShadow = pRealNode->pShadow;
    if ( pShadow )
      pShadow[1].vfptr = 0i64;
  }
  pObject = this->pRootNode.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 325
// RVA: 0x719400
char __fastcall Scaleform::GFx::AS2::XmlNodeObject::SetMember(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::LogState *v9; // rbx
  int StandardMemberConstant; // eax
  __int64 v11; // rax
  Scaleform::GFx::XML::DOMString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  Scaleform::GFx::XML::ElementNode *v16; // rsi
  unsigned __int64 v17; // rbx
  const char *pData; // r15
  char *v19; // rax
  char *v20; // r13
  Scaleform::GFx::XML::DOMString *v21; // rax
  const char *v22; // r8
  Scaleform::GFx::XML::DOMString *v23; // rax
  Scaleform::GFx::XML::DOMString *v24; // rcx
  Scaleform::GFx::XML::DOMString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rdi
  Scaleform::GFx::AS2::Object *v29; // rax
  Scaleform::GFx::AS2::Object *v30; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v31; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::LogMessageId v34; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::ASString v35; // [rsp+40h] [rbp-40h] BYREF
  Scaleform::LogMessageId v36; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::LogMessageId v37; // [rsp+4Ch] [rbp-34h] BYREF
  Scaleform::GFx::XML::DOMString v38; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::XML::DOMString v39; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::XML::DOMString v40; // [rsp+60h] [rbp-20h] BYREF
  Scaleform::GFx::XML::DOMString v41; // [rsp+68h] [rbp-18h] BYREF
  __int64 v42; // [rsp+70h] [rbp-10h]
  Scaleform::LogMessageId messageType; // [rsp+B0h] [rbp+30h] BYREF
  Scaleform::LogMessageId v44; // [rsp+B8h] [rbp+38h] BYREF

  v42 = -2i64;
  v9 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))penv->Target->vfptr[76].__vecDelDtor)(penv->Target);
  if ( *(_QWORD *)&this->ResolveHandler.Flags )
  {
    StandardMemberConstant = Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
                               (Scaleform::GFx::AS2::XmlNodeObject *)((char *)this - 32),
                               penv,
                               name);
    if ( StandardMemberConstant )
    {
      if ( StandardMemberConstant != 7 )
      {
        if ( StandardMemberConstant == 9 )
        {
          v11 = *(_QWORD *)&this->ResolveHandler.Flags;
          if ( !v11 || *(_BYTE *)(v11 + 64) == 1 )
          {
            if ( v9 )
            {
              messageType.Id = 147456;
              Scaleform::Log::LogMessageById(
                v9,
                (Scaleform::LogMessageId)&messageType,
                "XMLNodeObject::SetMember - cannot set nodeValue of a malformed node");
              return 1;
            }
          }
          else
          {
            Scaleform::GFx::AS2::Value::ToString(val, &result, penv, -1);
            v12 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&this->ResolveHandler.Flags + 16i64),
                    &v38,
                    result.pNode->pData,
                    result.pNode->Size);
            Scaleform::GFx::XML::DOMString::AssignNode(
              (Scaleform::GFx::XML::DOMString *)(*(_QWORD *)&this->ResolveHandler.Flags + 24i64),
              v12->pNode);
            Scaleform::GFx::XML::DOMString::~DOMString(&v38);
            pNode = result.pNode;
            v14 = result.pNode->RefCount-- == 1;
            if ( v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          }
          return 1;
        }
        return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
      }
      v16 = *(Scaleform::GFx::XML::ElementNode **)&this->ResolveHandler.Flags;
      if ( v16 )
      {
        if ( v16->Type == 1 )
        {
          Scaleform::GFx::XML::ObjectManager::EmptyString(
            v16->MemoryManager.pObject,
            (Scaleform::GFx::XML::DOMString *)&result);
          v17 = -1i64;
          Scaleform::GFx::AS2::Value::ToString(val, &v35, penv, -1);
          pData = v35.pNode->pData;
          v19 = strchr(v35.pNode->pData, 58);
          v20 = v19;
          if ( v19 )
          {
            v21 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&this->ResolveHandler.Flags + 16i64),
                    &v41,
                    pData,
                    v19 - pData);
            Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&result, v21->pNode);
            Scaleform::GFx::XML::DOMString::~DOMString(&v41);
            v22 = v20 + 1;
            do
              ++v17;
            while ( v22[v17] );
            v23 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&this->ResolveHandler.Flags + 16i64),
                    &v39,
                    v22,
                    v17);
            Scaleform::GFx::XML::DOMString::AssignNode(
              (Scaleform::GFx::XML::DOMString *)(*(_QWORD *)&this->ResolveHandler.Flags + 24i64),
              v23->pNode);
            v24 = &v39;
          }
          else
          {
            v25 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&this->ResolveHandler.Flags + 16i64),
                    &v40,
                    v35.pNode->pData,
                    v35.pNode->Size);
            Scaleform::GFx::XML::DOMString::AssignNode(
              (Scaleform::GFx::XML::DOMString *)(*(_QWORD *)&this->ResolveHandler.Flags + 24i64),
              v25->pNode);
            v24 = &v40;
          }
          Scaleform::GFx::XML::DOMString::~DOMString(v24);
          Scaleform::GFx::XML::DOMString::AssignNode(&v16->Prefix, (Scaleform::GFx::XML::DOMStringNode *)result.pNode);
          Scaleform::GFx::AS2::ResolveNamespace(
            penv,
            v16,
            (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
          v26 = v35.pNode;
          v14 = v35.pNode->RefCount-- == 1;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v26);
          Scaleform::GFx::XML::DOMString::~DOMString((Scaleform::GFx::XML::DOMString *)&result);
        }
        else if ( v9 )
        {
          v44.Id = 147456;
          Scaleform::Log::LogMessageById(
            v9,
            (Scaleform::LogMessageId)&v44,
            "XMLNodeObject::SetMember - cannot set nodeName of node type %d. Only type 1 allowed",
            (unsigned __int8)v16->Type);
        }
      }
      else if ( v9 )
      {
        v37.Id = 147456;
        Scaleform::Log::LogMessageById(
          v9,
          (Scaleform::LogMessageId)&v37,
          "XMLNodeObject::SetMember - cannot set nodeName of a malformed node");
      }
    }
    else
    {
      v27 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( v27 )
      {
        if ( *(_BYTE *)(v27 + 64) == 1 )
        {
          v28 = *(_QWORD *)(v27 + 56);
          v29 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
          v30 = v29;
          if ( v29 )
            v29->RefCount = (v29->RefCount + 1) & 0x8FFFFFFF;
          v31 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v28 + 16);
          if ( v31 )
          {
            RefCount = v31->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v31->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v31);
            }
          }
          *(_QWORD *)(v28 + 16) = v30;
        }
        else if ( v9 )
        {
          v36.Id = 147456;
          Scaleform::Log::LogMessageById(
            v9,
            (Scaleform::LogMessageId)&v36,
            "XMLNodeObject::SetMember - cannot set attributes of node type %d. Only type 1 allowed",
            *(unsigned __int8 *)(v27 + 64));
        }
      }
      else if ( v9 )
      {
        v34.Id = 147456;
        Scaleform::Log::LogMessageById(
          v9,
          (Scaleform::LogMessageId)&v34,
          "XMLNodeObject::SetMember - cannot set attributes of a malformed node");
        return 1;
      }
    }
    return 1;
  }
  return Scaleform::GFx::AS2::Object::SetMember(this, penv, name, val, flags);
}

// File Line: 460
// RVA: 0x6F29B0
char __fastcall Scaleform::GFx::AS2::XmlNodeObject::GetMember(
        Scaleform::GFx::AS2::XmlNodeObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rsi
  __int64 v9; // rcx
  __int64 v10; // rsi
  Scaleform::GFx::XML::Node *v11; // r8
  Scaleform::GFx::XML::ShadowRefBase *v12; // rdx
  Scaleform::GFx::AS2::Object *v13; // rdx
  Scaleform::GFx::AS2::Object **v14; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value *v17; // rcx
  char v18; // al
  __int64 v19; // r8
  Scaleform::GFx::XML::Node *v20; // r8
  Scaleform::GFx::XML::ShadowRefBase *v21; // rdx
  Scaleform::GFx::AS2::Object **v22; // rax
  __int64 v23; // rax
  Scaleform::GFx::AS2::ArrayObject *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // r14
  Scaleform::GFx::XML::Node *i; // rsi
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // rax
  Scaleform::GFx::ASStringNode *vfptr; // rdx
  Scaleform::GFx::ASStringNode **Shadow; // rax
  Scaleform::GFx::AS2::Value *v31; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int v33; // eax
  unsigned int v34; // eax
  __int64 v35; // rdi
  __int64 v36; // r8
  const char *v37; // rdx
  unsigned __int64 v38; // r8
  Scaleform::GFx::ASStringNode *v39; // rax
  Scaleform::GFx::ASStringNode *v40; // rcx
  bool v41; // zf
  Scaleform::GFx::ASString *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  __int64 v44; // rax
  Scaleform::GFx::ASString *v45; // rax
  Scaleform::GFx::ASStringNode *v46; // rcx
  __int64 v47; // rdi
  __int64 v48; // rdi
  Scaleform::GFx::AS2::Object *v49; // rax
  __int64 v50; // rax
  __int64 v51; // r14
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v52; // rcx
  unsigned int RefCount; // eax
  __int64 v54; // rsi
  Scaleform::GFx::XML::Node *v55; // r8
  Scaleform::GFx::XML::ShadowRefBase *v56; // rdx
  Scaleform::GFx::AS2::Object **v57; // rax
  __int64 v58; // r8
  Scaleform::GFx::XML::Node *v59; // r8
  Scaleform::GFx::XML::ShadowRefBase *v60; // rax
  Scaleform::GFx::AS2::Object **v61; // rax
  __int64 v62; // r8
  Scaleform::GFx::XML::Node *v63; // r8
  Scaleform::GFx::XML::ShadowRefBase *v64; // rax
  Scaleform::GFx::AS2::Object **v65; // rax
  __int64 v66; // rax
  Scaleform::GFx::ASString *v67; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 v69; // rax
  Scaleform::GFx::ASString *v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rcx
  __int64 v72; // rax
  Scaleform::GFx::ASString *v73; // rax
  Scaleform::GFx::ASStringNode *v74; // rcx
  __int64 v75; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v76; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::GFx::ASString v77; // [rsp+28h] [rbp-61h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v78; // [rsp+30h] [rbp-59h] BYREF
  Scaleform::GFx::ASString v79; // [rsp+38h] [rbp-51h] BYREF
  Scaleform::GFx::ASString v80; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::GFx::ASString v81; // [rsp+48h] [rbp-41h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v82; // [rsp+50h] [rbp-39h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v83; // [rsp+58h] [rbp-31h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v84; // [rsp+60h] [rbp-29h] BYREF
  Scaleform::GFx::AS2::ArrayObject *v85; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::ASString v86; // [rsp+70h] [rbp-19h] BYREF
  __int64 v87; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::AS2::Value vala; // [rsp+80h] [rbp-9h] BYREF
  Scaleform::GFx::AS2::Value v89; // [rsp+A0h] [rbp+17h] BYREF
  Scaleform::GFx::ASString v90; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [rsp+F8h] [rbp+6Fh] BYREF

  v87 = -2i64;
  p_StringContext = &penv->StringContext;
  if ( !*(_QWORD *)&this->ResolveHandler.Flags )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::XmlNodeObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
             this,
             p_StringContext,
             name,
             val);
  switch ( Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
             (Scaleform::GFx::AS2::XmlNodeObject *)((char *)this - 32),
             penv,
             name) )
  {
    case M_x:
      v47 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v47 )
        goto LABEL_14;
      v48 = *(_QWORD *)(v47 + 56);
      if ( !*(_QWORD *)(v48 + 16) )
      {
        v90.pNode = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pHeap;
        v49 = (Scaleform::GFx::AS2::Object *)(*((__int64 (__fastcall **)(__int64, __int64))v90.pNode->pData + 10))(
                                               v9,
                                               96i64);
        v85 = (Scaleform::GFx::AS2::ArrayObject *)v49;
        if ( v49 )
        {
          Scaleform::GFx::AS2::Object::Object(v49, penv);
          v51 = v50;
        }
        else
        {
          v51 = 0i64;
        }
        v52 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v48 + 16);
        if ( v52 )
        {
          RefCount = v52->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v52->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v52);
          }
        }
        *(_QWORD *)(v48 + 16) = v51;
      }
      v13 = *(Scaleform::GFx::AS2::Object **)(v48 + 16);
      goto LABEL_66;
    case M_y:
      v23 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v23 || *(_BYTE *)(v23 + 64) != 1 )
        goto LABEL_14;
      v90.pNode = (Scaleform::GFx::ASStringNode *)p_StringContext->pContext->pHeap;
      v24 = (Scaleform::GFx::AS2::ArrayObject *)(*((__int64 (__fastcall **)(__int64, __int64, _QWORD))v90.pNode->pData
                                                 + 10))(
                                                  v9,
                                                  144i64,
                                                  0i64);
      v85 = v24;
      if ( v24 )
      {
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v24, penv);
        v26 = v25;
      }
      else
      {
        v26 = 0i64;
      }
      v90.pNode = v26;
      for ( i = *(Scaleform::GFx::XML::Node **)(*(_QWORD *)&this->ResolveHandler.Flags + 104i64);
            i;
            i = i->NextSibling.pObject )
      {
        pShadow = i->pShadow;
        if ( pShadow && (vfptr = (Scaleform::GFx::ASStringNode *)pShadow[1].vfptr) != 0i64 )
        {
          Scaleform::GFx::AS2::Value::Value(&vala, vfptr);
          Scaleform::GFx::AS2::ArrayObject::PushBack((Scaleform::GFx::AS2::ArrayObject *)v26, &vala);
          if ( vala.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&vala);
        }
        else
        {
          Shadow = (Scaleform::GFx::ASStringNode **)Scaleform::GFx::AS2::CreateShadow(
                                                      (Scaleform::MemoryHeap *)&v78,
                                                      penv,
                                                      i,
                                                      (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
          Scaleform::GFx::AS2::Value::Value(&v89, *Shadow);
          Scaleform::GFx::AS2::ArrayObject::PushBack((Scaleform::GFx::AS2::ArrayObject *)v26, v31);
          if ( v89.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v89);
          pObject = v78.pObject;
          if ( v78.pObject )
          {
            v33 = v78.pObject->RefCount;
            if ( (v33 & 0x3FFFFFF) != 0 )
            {
              v78.pObject->RefCount = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
            }
          }
        }
      }
      Scaleform::GFx::AS2::Value::SetAsObject(val, (Scaleform::GFx::AS2::Object *)v26);
      if ( !v26 )
        goto LABEL_16;
      v34 = v26->RefCount;
      if ( (v34 & 0x3FFFFFF) == 0 )
        goto LABEL_16;
      v26->RefCount = v34 - 1;
      v15 = (Scaleform::GFx::AS2::XmlNodeObject *)v26;
      goto LABEL_12;
    case M_xscale:
      v10 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v10 )
        goto LABEL_14;
      if ( *(_BYTE *)(v10 + 64) != 1
        || !Scaleform::GFx::XML::ElementNode::HasChildren(*(Scaleform::GFx::XML::ElementNode **)&this->ResolveHandler.Flags) )
      {
        goto LABEL_13;
      }
      v11 = *(Scaleform::GFx::XML::Node **)(v10 + 104);
      v12 = v11->pShadow;
      if ( v12 )
      {
        v13 = (Scaleform::GFx::AS2::Object *)v12[1].vfptr;
        if ( v13 )
          goto LABEL_66;
      }
      v14 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                              (Scaleform::MemoryHeap *)&result,
                                              penv,
                                              v11,
                                              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, *v14);
      v15 = result.pObject;
      goto LABEL_9;
    case M_yscale:
      v54 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v54 )
        goto LABEL_14;
      if ( *(_BYTE *)(v54 + 64) != 1
        || !Scaleform::GFx::XML::ElementNode::HasChildren(*(Scaleform::GFx::XML::ElementNode **)&this->ResolveHandler.Flags) )
      {
        goto LABEL_13;
      }
      v55 = *(Scaleform::GFx::XML::Node **)(v54 + 112);
      v56 = v55->pShadow;
      if ( v56 )
      {
        v13 = (Scaleform::GFx::AS2::Object *)v56[1].vfptr;
        if ( v13 )
          goto LABEL_66;
      }
      v57 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                              (Scaleform::MemoryHeap *)&v83,
                                              penv,
                                              v55,
                                              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, *v57);
      v15 = v83.pObject;
      goto LABEL_9;
    case M_currentframe:
      v66 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v66 || *(_BYTE *)(v66 + 64) != 1 )
        goto LABEL_14;
      v67 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v77, **(const char ***)(v66 + 24));
      Scaleform::GFx::AS2::Value::SetString(val, v67);
      pNode = v77.pNode;
      v41 = v77.pNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_16;
    case M_totalframes:
      v69 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v69 || *(_BYTE *)(v69 + 64) != 1 )
        goto LABEL_14;
      v70 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v79, **(const char ***)(v69 + 80));
      Scaleform::GFx::AS2::Value::SetString(val, v70);
      v71 = v79.pNode;
      v41 = v79.pNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v71);
      goto LABEL_16;
    case M_alpha:
      v19 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v19 )
        goto LABEL_14;
      v20 = *(Scaleform::GFx::XML::Node **)(v19 + 48);
      if ( !v20 )
        goto LABEL_13;
      v21 = v20->pShadow;
      if ( v21 )
      {
        v13 = (Scaleform::GFx::AS2::Object *)v21[1].vfptr;
        if ( v13 )
          goto LABEL_66;
      }
      v22 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                              (Scaleform::MemoryHeap *)&v84,
                                              penv,
                                              v20,
                                              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, *v22);
      v15 = v84.pObject;
      goto LABEL_9;
    case M_visible:
      v35 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v35 )
        goto LABEL_14;
      if ( *(_BYTE *)(v35 + 64) != 1 )
        goto LABEL_13;
      v36 = *(_QWORD *)(v35 + 72);
      if ( *(_DWORD *)(v36 + 20) )
      {
        Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v90, *(const char **)v36);
        Scaleform::GFx::ASString::Append(&v90, ":", 1ui64);
        v37 = **(const char ***)(v35 + 24);
        v38 = -1i64;
        do
          ++v38;
        while ( v37[v38] );
        Scaleform::GFx::ASString::Append(&v90, v37, v38);
        if ( val->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(val);
        val->T.Type = 5;
        v39 = v90.pNode;
        val->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v90.pNode;
        ++v39->RefCount;
        v40 = v90.pNode;
        v41 = v90.pNode->RefCount-- == 1;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      }
      else
      {
        v42 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v86, **(const char ***)(v35 + 24));
        Scaleform::GFx::AS2::Value::SetString(val, v42);
        v43 = v86.pNode;
        v41 = v86.pNode->RefCount-- == 1;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      }
      goto LABEL_16;
    case M_width:
      v75 = *(_QWORD *)&this->ResolveHandler.Flags;
      v17 = val;
      if ( !v75 )
        goto LABEL_15;
      Scaleform::GFx::AS2::Value::SetNumber(val, (double)*(unsigned __int8 *)(v75 + 64));
      goto LABEL_16;
    case M_height:
      v44 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v44 )
        goto LABEL_14;
      if ( *(_BYTE *)(v44 + 64) == 1 )
        goto LABEL_13;
      v45 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v80, **(const char ***)(v44 + 24));
      Scaleform::GFx::AS2::Value::SetString(val, v45);
      v46 = v80.pNode;
      v41 = v80.pNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v46);
      goto LABEL_16;
    case M_rotation:
      v62 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v62 )
        goto LABEL_14;
      v63 = *(Scaleform::GFx::XML::Node **)(v62 + 32);
      if ( !v63 )
        goto LABEL_13;
      v64 = v63->pShadow;
      if ( v64 )
      {
        v13 = (Scaleform::GFx::AS2::Object *)v64[1].vfptr;
        if ( v13 )
          goto LABEL_66;
      }
      v65 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                              (Scaleform::MemoryHeap *)&v76,
                                              penv,
                                              v63,
                                              (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(val, *v65);
      v15 = v76.pObject;
      goto LABEL_9;
    case M_target:
      v72 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( !v72 || *(_BYTE *)(v72 + 64) != 1 )
        goto LABEL_14;
      v73 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v81, **(const char ***)(v72 + 72));
      Scaleform::GFx::AS2::Value::SetString(val, v73);
      v74 = v81.pNode;
      v41 = v81.pNode->RefCount-- == 1;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v74);
      goto LABEL_16;
    case M_framesloaded:
      v58 = *(_QWORD *)&this->ResolveHandler.Flags;
      if ( v58 )
      {
        v59 = *(Scaleform::GFx::XML::Node **)(v58 + 40);
        if ( v59 )
        {
          v60 = v59->pShadow;
          if ( v60 && (v13 = (Scaleform::GFx::AS2::Object *)v60[1].vfptr) != 0i64 )
          {
LABEL_66:
            Scaleform::GFx::AS2::Value::SetAsObject(val, v13);
          }
          else
          {
            v61 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                                    (Scaleform::MemoryHeap *)&v82,
                                                    penv,
                                                    v59,
                                                    (Scaleform::GFx::XML::RootNode *)this->ResolveHandler.pLocalFrame);
            Scaleform::GFx::AS2::Value::SetAsObject(val, *v61);
            v15 = v82.pObject;
LABEL_9:
            if ( v15 )
            {
              v16 = v15->RefCount;
              if ( (v16 & 0x3FFFFFF) != 0 )
              {
                v15->RefCount = v16 - 1;
LABEL_12:
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
              }
            }
          }
        }
        else
        {
LABEL_13:
          Scaleform::GFx::AS2::Value::DropRefs(val);
          val->T.Type = 1;
        }
      }
      else
      {
LABEL_14:
        v17 = val;
LABEL_15:
        Scaleform::GFx::AS2::Value::DropRefs(v17);
        val->T.Type = 0;
      }
LABEL_16:
      v18 = 1;
      break;
    default:
      return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::XmlNodeObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[3].~RefCountBaseGC<323>)(
               this,
               p_StringContext,
               name,
               val);
  }
  return v18;
}

// File Line: 850
// RVA: 0x6CDCA0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::XmlNodeProto(
        Scaleform::GFx::AS2::XmlNodeProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASStringNode *v30; // rcx
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h] BYREF
  __int64 v35; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::ASStringHash<char> *p_XMLNodeMemberMap; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS2::Value val; // [rsp+50h] [rbp-20h] BYREF

  v35 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable;
  result.pNode = (Scaleform::GFx::ASStringNode *)&this->XMLNodeMemberMap;
  p_XMLNodeMemberMap = &this->XMLNodeMemberMap;
  this->XMLNodeMemberMap.mHash.pTable = 0i64;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    Scaleform::GFx::AS2::XmlNodeProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "attributes");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v6,
    &val,
    &flags);
  pNode = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "childNodes");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v9,
    &val,
    &flags);
  v10 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "firstChild");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v11,
    &val,
    &flags);
  v12 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "lastChild");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v13,
    &val,
    &flags);
  v14 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "localName");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v15,
    &val,
    &flags);
  v16 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "namespaceURI");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v17,
    &val,
    &flags);
  v18 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "nextSibling");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v19,
    &val,
    &flags);
  v20 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "nodeName");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v21,
    &val,
    &flags);
  v22 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "nodeType");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v23,
    &val,
    &flags);
  v24 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "nodeValue");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v25,
    &val,
    &flags);
  v26 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v27 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "parentNode");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v27,
    &val,
    &flags);
  v28 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "prefix");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v29,
    &val,
    &flags);
  v30 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v31 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "previousSibling");
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v31,
    &val,
    &flags);
  v32 = result.pNode;
  v8 = result.pNode->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 897
// RVA: 0x6A8EB0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::AppendChild(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // r14
  __int64 v8; // rax
  Scaleform::GFx::LogState *v9; // rbx
  Scaleform::GFx::XML::ElementNode *pObject; // r15
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::AS2::Object *v13; // rsi
  Scaleform::RefCountNTSImpl *pRCC; // rbp
  Scaleform::RefCountNTSImpl *vfptr; // rcx
  const char *v16; // r8
  Scaleform::GFx::LogState *v17; // rcx
  Scaleform::GFx::XML::Node *v18; // rdx
  Scaleform::GFx::XML::ElementNode *Parent; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v20; // rax
  Scaleform::RefCountNTSImpl *v21; // rcx
  Scaleform::GFx::XML::ElementNode *v22; // rdx
  Scaleform::RefCountNTSImpl *messageType; // [rsp+50h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( !v3 && !v5 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
    return;
  }
  v6 = fn->ThisPtr;
  if ( v6 )
  {
    v7 = v6 - 2;
    if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
      v9 = (Scaleform::GFx::LogState *)v8;
      pObject = (Scaleform::GFx::XML::ElementNode *)v7[6].pProto.pObject;
      if ( pObject )
      {
        if ( pObject->Type != 1 )
        {
          if ( !v8 )
            return;
          v16 = "XMLNode::appendChild - trying to add a child to a text node";
          v17 = (Scaleform::GFx::LogState *)v8;
          goto LABEL_40;
        }
        if ( fn->NArgs <= 0 )
          return;
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v12 = Scaleform::GFx::AS2::Value::ToObject(v11, fn->Env);
        v13 = v12;
        if ( !v12
          || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v12->Scaleform::GFx::AS2::ObjectInterface) != 29 )
        {
          if ( !v9 )
            return;
          v16 = "XMLNode::appendChild - trying to add a child that is not of type XMLNode";
          v17 = v9;
          goto LABEL_40;
        }
        pRCC = (Scaleform::RefCountNTSImpl *)v13[1].pRCC;
        if ( !pRCC )
          return;
        vfptr = (Scaleform::RefCountNTSImpl *)v7[6].pProto.pObject->vfptr;
        if ( vfptr )
        {
          while ( vfptr[2].vfptr )
            vfptr = (Scaleform::RefCountNTSImpl *)vfptr[2].vfptr;
        }
        if ( vfptr == pRCC )
        {
          if ( !v9 )
            return;
          v16 = "XMLNode::appendChild - trying to add a child that is the root of the current tree";
          v17 = v9;
LABEL_40:
          LODWORD(messageType) = 147456;
          Scaleform::Log::LogMessageById(v17, (Scaleform::LogMessageId)&messageType, v16);
          return;
        }
        ++pRCC->RefCount;
        messageType = pRCC;
        v18 = (Scaleform::GFx::XML::Node *)v13[1].pRCC;
        Parent = v18->Parent;
        if ( Parent )
          Scaleform::GFx::XML::ElementNode::RemoveChild(Parent, v18);
        Scaleform::GFx::XML::ElementNode::AppendChild(pObject, (Scaleform::GFx::XML::Node *)v13[1].pRCC);
        v20 = v7[6].vfptr;
        if ( v20 )
          ++*(_DWORD *)v20->gap8;
        v21 = (Scaleform::RefCountNTSImpl *)v13[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
        if ( v21 )
          Scaleform::RefCountNTSImpl::Release(v21);
        v13[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)v7[6].vfptr;
        v22 = (Scaleform::GFx::XML::ElementNode *)v13[1].pRCC;
        if ( v22->Type == 1 && !v22->Namespace.pNode->Size )
          Scaleform::GFx::AS2::ResolveNamespace(fn->Env, v22, (Scaleform::GFx::XML::RootNode *)v7[6].vfptr);
        Scaleform::RefCountNTSImpl::Release(pRCC);
      }
    }
  }
}

// File Line: 994
// RVA: 0x6A90C0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::CloneNode(Scaleform::GFx::AS2::FnCall *fn, _BOOL8 a2)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v4; // di
  Scaleform::GFx::AS2::ObjectInterface *v5; // rcx
  bool v6; // al
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::XML::Node *v11; // rdi
  Scaleform::GFx::AS2::XmlNodeObject *v12; // rcx
  unsigned int v13; // eax
  Scaleform::RefCountNTSImpl *v14; // rcx
  Scaleform::GFx::XML::Node *v15; // rsi
  Scaleform::GFx::AS2::XmlNodeObject *v16; // rcx
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::XML::Node *v19; // [rsp+48h] [rbp+10h]

  ThisPtr = fn->ThisPtr;
  v4 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v5 = fn->ThisPtr;
  v6 = v5 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v5->vfptr->gap8[8])(v5) == 28;
  if ( !v4 && !v6 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
    return;
  }
  v7 = fn->ThisPtr;
  if ( v7 )
  {
    v8 = v7 - 2;
    if ( v8 )
    {
      if ( v8[6].pProto.pObject )
      {
        LOBYTE(a2) = 0;
        if ( fn->NArgs > 0 )
        {
          v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          a2 = Scaleform::GFx::AS2::Value::ToBool(v9, fn->Env);
        }
        pObject = v8[6].pProto.pObject;
        if ( LOBYTE(pObject->ResolveHandler.pLocalFrame) != 1 )
        {
          v15 = (Scaleform::GFx::XML::Node *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *, _BOOL8))pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr->Finalize_GC)(
                                               pObject,
                                               a2);
          v19 = v15;
          Scaleform::GFx::AS2::CreateShadow(&result, fn->Env, v15, 0i64);
          v15->Type = (char)pObject->ResolveHandler.pLocalFrame;
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, result.pObject);
          v16 = result.pObject;
          if ( result.pObject )
          {
            RefCount = result.pObject->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              result.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
            }
          }
          v14 = v15;
          goto LABEL_27;
        }
        v11 = (Scaleform::GFx::XML::Node *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::Object *, _BOOL8))pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr->Finalize_GC)(
                                             pObject,
                                             a2);
        v19 = v11;
        Scaleform::GFx::AS2::CreateShadow(&result, fn->Env, v11, 0i64);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, result.pObject);
        v12 = result.pObject;
        if ( result.pObject )
        {
          v13 = result.pObject->RefCount;
          if ( (v13 & 0x3FFFFFF) != 0 )
          {
            result.pObject->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
          }
        }
        if ( v11 )
        {
          v14 = v11;
LABEL_27:
          Scaleform::RefCountNTSImpl::Release(v14);
        }
      }
    }
  }
}

// File Line: 1046
// RVA: 0x6A9260
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::GetNamespaceForPrefix(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::LogState *v9; // rax
  Scaleform::GFx::XML::Node *pObject; // rbx
  Scaleform::GFx::AS2::Value *v11; // rax
  const char *pData; // rdx
  unsigned __int64 v13; // r8
  __int64 v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  unsigned int RefCount; // eax
  __int64 v17; // rcx
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::AS2::Value v23; // [rsp+28h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v24; // [rsp+70h] [rbp+20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+28h] BYREF
  Scaleform::GFx::ASString v26; // [rsp+80h] [rbp+30h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = fn->ThisPtr;
    if ( v6 )
    {
      v7 = v6 - 2;
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        v8 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v8);
        v8->T.Type = 1;
        v9 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
        pObject = (Scaleform::GFx::XML::Node *)v7[6].pProto.pObject;
        if ( pObject )
        {
          if ( pObject->Type == 1 )
          {
            if ( fn->NArgs >= 1 )
            {
              v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
              Scaleform::GFx::AS2::Value::ToString(v11, &result, fn->Env, -1);
              Scaleform::GFx::AS2::ASStringContext::CreateString(&fn->Env->StringContext, &v24, "xmlns", 5ui64);
              if ( result.pNode->Size )
              {
                Scaleform::GFx::ASString::Append(&v24, ":", 1ui64);
                pData = result.pNode->pData;
                v13 = -1i64;
                do
                  ++v13;
                while ( pData[v13] );
                Scaleform::GFx::ASString::Append(&v24, pData, v13);
              }
              v23.T.Type = 0;
              v14 = (__int64)&pObject->pShadow[2].vfptr[4];
              (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))(*(_QWORD *)v14 + 32i64))(
                v14,
                fn->Env,
                &v24,
                &v23,
                -2i64);
              if ( v23.T.Type && v23.T.Type != 10 )
              {
LABEL_30:
                v18 = Scaleform::GFx::AS2::Value::ToString(&v23, &v26, fn->Env, -1);
                Scaleform::GFx::AS2::Value::SetString(fn->Result, v18);
                pNode = v26.pNode;
                v20 = v26.pNode->RefCount-- == 1;
                if ( v20 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              }
              else
              {
                while ( 1 )
                {
                  pObject = pObject->Parent;
                  if ( !pObject )
                    break;
                  if ( !pObject->pShadow )
                  {
                    Scaleform::GFx::AS2::CreateShadow(
                      (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&v26,
                      fn->Env,
                      pObject,
                      (Scaleform::GFx::XML::RootNode *)v7[6].vfptr);
                    v15 = v26.pNode;
                    if ( v26.pNode )
                    {
                      RefCount = v26.pNode->RefCount;
                      if ( (RefCount & 0x3FFFFFF) != 0 )
                      {
                        v26.pNode->RefCount = RefCount - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v15);
                      }
                    }
                  }
                  v17 = (__int64)&pObject->pShadow[2].vfptr[4];
                  (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v17 + 32i64))(
                    v17,
                    fn->Env,
                    &v24,
                    &v23);
                  if ( v23.T.Type && v23.T.Type != 10 )
                    goto LABEL_30;
                }
              }
              if ( v23.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v23);
              v21 = v24.pNode;
              v20 = v24.pNode->RefCount-- == 1;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v21);
              v22 = result.pNode;
              v20 = result.pNode->RefCount-- == 1;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v22);
            }
          }
          else if ( v9 )
          {
            LODWORD(v24.pNode) = 147456;
            Scaleform::Log::LogMessageById(
              v9,
              (Scaleform::LogMessageId)&v24,
              "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1151
// RVA: 0x723B70
void __fastcall Scaleform::GFx::AS2::XMLPrefixQuerier::Visit(
        Scaleform::GFx::AS2::XMLPrefixQuerier *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        char flags)
{
  Scaleform::GFx::AS2::Value *pVal; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::AS2::Value::ToString(val, &result, this->pEnv, -1);
  if ( result.pNode == this->pKey->pNode && !strncmp(name->pNode->pData, "xmlns", 5ui64) )
  {
    pVal = this->pVal;
    if ( pVal->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(pVal);
    pVal->T.Type = 5;
    pNode = name->pNode;
    pVal->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)name->pNode;
    ++pNode->RefCount;
  }
  v8 = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 1166
// RVA: 0x6A97D0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::GetPrefixForNamespace(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // r15
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::AS2::Environment *Env; // rcx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // r12
  Scaleform::GFx::LogState *v11; // rax
  Scaleform::GFx::AS2::Object *pObject; // rbx
  Scaleform::GFx::AS2::Value *v13; // rax
  Scaleform::GFx::AS2::Environment *v14; // rax
  __int64 v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v18; // zf
  Scaleform::GFx::XML::Node *i; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  unsigned int RefCount; // eax
  __int64 v22; // rcx
  Scaleform::GFx::ASString *v23; // r14
  Scaleform::GFx::AS2::Value *v24; // rsi
  Scaleform::GFx::ASStringNode *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS2::Value *v27; // rcx
  const char *pData; // rbx
  char *v29; // rax
  unsigned int Size; // r9d
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASStringNode *v34; // rcx
  __int64 v35[4]; // [rsp+38h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value v36; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v37; // [rsp+C0h] [rbp+40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+48h] BYREF
  Scaleform::GFx::ASString v39; // [rsp+D0h] [rbp+50h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = fn->ThisPtr;
    if ( v6 )
    {
      v7 = v6 - 2;
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        v8 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v8);
        v8->T.Type = 1;
        Env = fn->Env;
        p_StringContext = &Env->StringContext;
        v11 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))Env->Target->vfptr[76].__vecDelDtor)(Env->Target);
        pObject = v7[6].pProto.pObject;
        if ( pObject )
        {
          if ( LOBYTE(pObject->ResolveHandler.pLocalFrame) == 1 )
          {
            if ( fn->NArgs >= 1 )
            {
              v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
              Scaleform::GFx::AS2::Value::ToString(v13, &result, fn->Env, -1);
              v36.T.Type = 0;
              v14 = fn->Env;
              v35[0] = (__int64)&Scaleform::GFx::AS2::XMLPrefixQuerier::`vftable;
              v35[1] = (__int64)v14;
              v35[2] = (__int64)&result;
              v35[3] = (__int64)&v36;
              v15 = (__int64)&pObject->ResolveHandler.Function->pPrev[1];
              (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v15 + 64i64))(
                v15,
                p_StringContext,
                v35,
                0i64,
                0i64);
              if ( v36.T.Type )
              {
                if ( v36.T.Type != 10 )
                {
                  v16 = Scaleform::GFx::AS2::Value::ToString(&v36, &v37, fn->Env, -1);
                  Scaleform::GFx::AS2::Value::SetString(fn->Result, v16);
                  pNode = v37.pNode;
                  v18 = v37.pNode->RefCount-- == 1;
                  if ( v18 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
                }
              }
              for ( i = (Scaleform::GFx::XML::Node *)pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr;
                    fn->Result->T.Type == 1;
                    i = i->Parent )
              {
                if ( !i )
                  break;
                if ( !i->pShadow )
                {
                  Scaleform::GFx::AS2::CreateShadow(
                    (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&v37,
                    fn->Env,
                    i,
                    (Scaleform::GFx::XML::RootNode *)v7[6].vfptr);
                  v20 = v37.pNode;
                  if ( v37.pNode )
                  {
                    RefCount = v37.pNode->RefCount;
                    if ( (RefCount & 0x3FFFFFF) != 0 )
                    {
                      v37.pNode->RefCount = RefCount - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v20);
                    }
                  }
                }
                v22 = (__int64)&i->pShadow[2].vfptr[4];
                (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, __int64 *, _QWORD, _QWORD))(*(_QWORD *)v22 + 64i64))(
                  v22,
                  p_StringContext,
                  v35,
                  0i64,
                  0i64);
                if ( v36.T.Type && v36.T.Type != 10 )
                {
                  v23 = Scaleform::GFx::AS2::Value::ToString(&v36, &v39, fn->Env, -1);
                  v24 = fn->Result;
                  if ( v24->T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
                  v24->T.Type = 5;
                  v25 = v23->pNode;
                  v24->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v23->pNode;
                  ++v25->RefCount;
                  v26 = v39.pNode;
                  v18 = v39.pNode->RefCount-- == 1;
                  if ( v18 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
                }
              }
              v27 = fn->Result;
              if ( v27->T.Type != 1 )
              {
                Scaleform::GFx::AS2::Value::ToString(v27, &v37, fn->Env, -1);
                pData = v37.pNode->pData;
                v29 = strchr(v37.pNode->pData, 58);
                Size = v37.pNode->Size;
                if ( v29 )
                  v31 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v39, pData + 6, Size - 6);
                else
                  v31 = Scaleform::GFx::AS2::ASStringContext::CreateString(p_StringContext, &v39, pData + 5, Size - 5);
                Scaleform::GFx::AS2::Value::SetString(fn->Result, v31);
                v32 = v39.pNode;
                v18 = v39.pNode->RefCount-- == 1;
                if ( v18 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v32);
                v33 = v37.pNode;
                v18 = v37.pNode->RefCount-- == 1;
                if ( v18 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v33);
              }
              v35[0] = (__int64)&Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
              if ( v36.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v36);
              v34 = result.pNode;
              v18 = result.pNode->RefCount-- == 1;
              if ( v18 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v34);
            }
          }
          else if ( v11 )
          {
            LODWORD(v37.pNode) = 147456;
            Scaleform::Log::LogMessageById(
              v11,
              (Scaleform::LogMessageId)&v37,
              "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1263
// RVA: 0x6A9D10
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::HasChildNodes(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::GFx::XML::ElementNode *pObject; // rcx
  bool HasChildren; // al
  Scaleform::GFx::AS2::Value *v11; // rbx
  bool v12; // di

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = fn->ThisPtr;
    if ( v6 )
    {
      v7 = v6 - 2;
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 2;
        Result->V.BooleanValue = 0;
        pObject = (Scaleform::GFx::XML::ElementNode *)v7[6].pProto.pObject;
        if ( pObject )
        {
          if ( pObject->Type == 1 )
          {
            HasChildren = Scaleform::GFx::XML::ElementNode::HasChildren(pObject);
            v11 = fn->Result;
            v12 = HasChildren;
            Scaleform::GFx::AS2::Value::DropRefs(v11);
            v11->T.Type = 2;
            v11->V.BooleanValue = v12;
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1286
// RVA: 0x6A9DE0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::InsertBefore(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::XML::ElementNode *pObject; // rbp
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // r14
  Scaleform::GFx::AS2::RefCountCollector<323> *v13; // rax
  Scaleform::GFx::XML::ElementNode *NumPages; // rax
  Scaleform::RefCountNTSImpl *pRCC; // rdi
  Scaleform::GFx::XML::Node *v16; // rdx
  Scaleform::GFx::XML::ElementNode *Parent; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // rax
  Scaleform::RefCountNTSImpl *v19; // rcx
  Scaleform::GFx::XML::Node *v20; // rdx
  Scaleform::GFx::XML::ElementNode *v21; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v22; // rax
  Scaleform::RefCountNTSImpl *v23; // rcx

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( !v3 && !v5 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
    return;
  }
  v6 = fn->ThisPtr;
  if ( v6 )
  {
    v7 = v6 - 2;
    if ( v7 )
    {
      pObject = (Scaleform::GFx::XML::ElementNode *)v7[6].pProto.pObject;
      if ( pObject )
      {
        if ( pObject->Type == 1 && fn->NArgs > 1 )
        {
          v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v10 = Scaleform::GFx::AS2::Value::ToObject(v9, fn->Env);
          v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
          v12 = Scaleform::GFx::AS2::Value::ToObject(v11, fn->Env);
          if ( v10 )
          {
            if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v10->Scaleform::GFx::AS2::ObjectInterface) == 29 )
            {
              if ( v12
                && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v12->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v12->Scaleform::GFx::AS2::ObjectInterface) == 29
                && (v13 = v12[1].pRCC) != 0i64
                && (NumPages = (Scaleform::GFx::XML::ElementNode *)v13->Roots.NumPages) != 0i64
                && NumPages == pObject )
              {
                pRCC = (Scaleform::RefCountNTSImpl *)v10[1].pRCC;
                if ( !pRCC )
                  return;
                ++pRCC->RefCount;
                v16 = (Scaleform::GFx::XML::Node *)v10[1].pRCC;
                Parent = v16->Parent;
                if ( Parent )
                  Scaleform::GFx::XML::ElementNode::RemoveChild(Parent, v16);
                Scaleform::GFx::XML::ElementNode::InsertBefore(
                  pObject,
                  (Scaleform::GFx::XML::Node *)v10[1].pRCC,
                  (Scaleform::GFx::XML::Node *)v12[1].pRCC);
                vfptr = v7[6].vfptr;
                if ( vfptr )
                  ++*(_DWORD *)vfptr->gap8;
                v19 = (Scaleform::RefCountNTSImpl *)v10[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
                if ( v19 )
                  Scaleform::RefCountNTSImpl::Release(v19);
                v10[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)v7[6].vfptr;
              }
              else
              {
                pRCC = (Scaleform::RefCountNTSImpl *)v10[1].pRCC;
                if ( !pRCC )
                  return;
                ++pRCC->RefCount;
                v20 = (Scaleform::GFx::XML::Node *)v10[1].pRCC;
                v21 = v20->Parent;
                if ( v21 )
                  Scaleform::GFx::XML::ElementNode::RemoveChild(v21, v20);
                Scaleform::GFx::XML::ElementNode::AppendChild(pObject, (Scaleform::GFx::XML::Node *)v10[1].pRCC);
                v22 = v7[6].vfptr;
                if ( v22 )
                  ++*(_DWORD *)v22->gap8;
                v23 = (Scaleform::RefCountNTSImpl *)v10[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
                if ( v23 )
                  Scaleform::RefCountNTSImpl::Release(v23);
                v10[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)v7[6].vfptr;
              }
              Scaleform::RefCountNTSImpl::Release(pRCC);
            }
          }
        }
      }
    }
  }
}

// File Line: 1356
// RVA: 0x6AA0A0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::RemoveNode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // di
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v7; // rbx
  Scaleform::GFx::XML::Node *pObject; // rdx
  Scaleform::GFx::XML::ElementNode *Parent; // rdi
  Scaleform::GFx::XML::RootNode *RootNode; // rax
  Scaleform::RefCountNTSImpl *vfptr; // rcx
  Scaleform::GFx::XML::RootNode *v12; // rsi

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = fn->ThisPtr;
    if ( v6 )
    {
      v7 = v6 - 2;
      if ( v7 )
      {
        pObject = (Scaleform::GFx::XML::Node *)v7[6].pProto.pObject;
        if ( pObject )
        {
          Parent = pObject->Parent;
          if ( Parent )
          {
            RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode(Parent->MemoryManager.pObject, pObject);
            vfptr = (Scaleform::RefCountNTSImpl *)v7[6].vfptr;
            v12 = RootNode;
            if ( vfptr )
              Scaleform::RefCountNTSImpl::Release(vfptr);
            v7[6].vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)v12;
            Scaleform::GFx::XML::ElementNode::RemoveChild(Parent, (Scaleform::GFx::XML::Node *)v7[6].pProto.pObject);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1394
// RVA: 0x723AB0
void __fastcall Scaleform::GFx::AS2::XMLAttributeStringBuilder::Visit(
        Scaleform::GFx::AS2::XMLAttributeStringBuilder *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val,
        char flags)
{
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::StringBuffer::AppendString(this->Dest, " ", -1i64);
  Scaleform::StringBuffer::AppendString(this->Dest, name->pNode->pData, -1i64);
  Scaleform::StringBuffer::AppendString(this->Dest, "=\"", -1i64);
  v7 = Scaleform::GFx::AS2::Value::ToString(val, &result, this->pEnv, -1);
  Scaleform::StringBuffer::AppendString(this->Dest, v7->pNode->pData, -1i64);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::StringBuffer::AppendString(this->Dest, "\"", -1i64);
}

// File Line: 1409
// RVA: 0x6DBDB0
void __fastcall Scaleform::GFx::AS2::BuildXMLString(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::XML::ElementNode *proot,
        Scaleform::StringBuffer *dest)
{
  const char *pData; // rdx
  Scaleform::GFx::XML::ShadowRefBase *pShadow; // rbx
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v8; // rcx
  Scaleform::GFx::XML::ShadowRefBaseVtbl *vfptr; // rbx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::XML::ElementNode *i; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v18; // rdx
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v19; // rcx
  Scaleform::GFx::XML::ObjectManager *j; // rbx
  bool HasChildren; // al
  const char *v22; // rdx
  Scaleform::GFx::XML::ElementNode *k; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v24; // rdx
  Scaleform::GFx::ASString v25; // [rsp+30h] [rbp-68h] BYREF
  __int64 v26; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS2::Value v27; // [rsp+40h] [rbp-58h] BYREF
  Scaleform::GFx::AS2::Value v28; // [rsp+60h] [rbp-38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+10h] BYREF
  Scaleform::GFx::ASString v30; // [rsp+B8h] [rbp+20h] BYREF

  v26 = -2i64;
  if ( proot->Type != 1 )
  {
    pData = proot->Value.pNode->pData;
LABEL_39:
    Scaleform::StringBuffer::AppendString(dest, pData, -1i64);
    return;
  }
  pShadow = proot->pShadow;
  if ( pShadow
    && (v8 = pShadow[1].vfptr) != 0i64
    && (*((unsigned int (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *))v8[4].__vecDelDtor + 2))(v8 + 4) == 28 )
  {
    vfptr = pShadow[1].vfptr;
    v27.T.Type = 0;
    v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &result, "xmlDecl");
    (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))vfptr[4].__vecDelDtor
     + 4))(
      vfptr + 4,
      penv,
      v10,
      &v27);
    pNode = result.pNode;
    v12 = result.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v27.T.Type && v27.T.Type != 10 )
    {
      v13 = Scaleform::GFx::AS2::Value::ToString(&v27, &v30, penv, -1);
      Scaleform::StringBuffer::AppendString(dest, v13->pNode->pData, -1i64);
      v14 = v30.pNode;
      v12 = v30.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v28.T.Type = 0;
      v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v25, "ignoreWhite");
      (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))vfptr[4].__vecDelDtor
       + 4))(
        vfptr + 4,
        penv,
        v15,
        &v28);
      v16 = v25.pNode;
      v12 = v25.pNode->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( !Scaleform::GFx::AS2::Value::ToBool(&v28, penv) )
        Scaleform::StringBuffer::AppendString(dest, "\n", -1i64);
      if ( v28.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v28);
    }
    for ( i = (Scaleform::GFx::XML::ElementNode *)proot->FirstChild.pObject;
          i;
          i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
    {
      Scaleform::GFx::AS2::BuildXMLString(penv, i, dest);
    }
    if ( v27.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v27);
  }
  else
  {
    Scaleform::StringBuffer::AppendString(dest, "<", -1i64);
    v18 = (Scaleform::RefCountNTSImplCoreVtbl *)proot->Prefix.pNode;
    if ( HIDWORD(v18[2].__vecDelDtor) )
    {
      Scaleform::StringBuffer::AppendString(dest, (const char *)v18->__vecDelDtor, -1i64);
      Scaleform::StringBuffer::AppendString(dest, ":", -1i64);
    }
    Scaleform::StringBuffer::AppendString(dest, proot->Value.pNode->pData, -1i64);
    if ( pShadow && pShadow[2].vfptr )
    {
      *(_QWORD *)&v27.T.Type = &Scaleform::GFx::AS2::XMLAttributeStringBuilder::`vftable;
      v27.V.pStringNode = (Scaleform::GFx::ASStringNode *)penv;
      v27.V.FunctionValue.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)dest;
      v19 = pShadow[2].vfptr;
      if ( v19 )
        (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *, _QWORD, _QWORD))v19[4].__vecDelDtor
         + 8))(
          v19 + 4,
          &penv->StringContext,
          &v27,
          0i64,
          0i64);
      *(_QWORD *)&v27.T.Type = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable;
    }
    else
    {
      for ( j = (Scaleform::GFx::XML::ObjectManager *)proot->FirstAttribute;
            j;
            j = (Scaleform::GFx::XML::ObjectManager *)j->Scaleform::GFx::ExternalLibPtr::vfptr )
      {
        Scaleform::StringBuffer::AppendString(dest, " ", -1i64);
        Scaleform::StringBuffer::AppendString(
          dest,
          (const char *)j->Scaleform::RefCountBaseNTS<Scaleform::GFx::XML::ObjectManager,326>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,326>::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr->__vecDelDtor,
          -1i64);
        Scaleform::StringBuffer::AppendString(dest, "=\"", -1i64);
        Scaleform::StringBuffer::AppendString(dest, **(const char ***)&j->RefCount, -1i64);
        Scaleform::StringBuffer::AppendString(dest, "\"", -1i64);
      }
    }
    HasChildren = Scaleform::GFx::XML::ElementNode::HasChildren(proot);
    v22 = ">";
    if ( !HasChildren )
      v22 = " />";
    Scaleform::StringBuffer::AppendString(dest, v22, -1i64);
    for ( k = (Scaleform::GFx::XML::ElementNode *)proot->FirstChild.pObject;
          k;
          k = (Scaleform::GFx::XML::ElementNode *)k->NextSibling.pObject )
    {
      Scaleform::GFx::AS2::BuildXMLString(penv, k, dest);
    }
    if ( Scaleform::GFx::XML::ElementNode::HasChildren(proot) )
    {
      Scaleform::StringBuffer::AppendString(dest, "</", -1i64);
      v24 = (Scaleform::RefCountNTSImplCoreVtbl *)proot->Prefix.pNode;
      if ( HIDWORD(v24[2].__vecDelDtor) )
      {
        Scaleform::StringBuffer::AppendString(dest, (const char *)v24->__vecDelDtor, -1i64);
        Scaleform::StringBuffer::AppendString(dest, ":", -1i64);
      }
      Scaleform::StringBuffer::AppendString(dest, proot->Value.pNode->pData, -1i64);
      pData = ">";
      goto LABEL_39;
    }
  }
}

// File Line: 1513
// RVA: 0x6AA170
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  bool v3; // di
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  Scaleform::GFx::AS2::Object *pObject; // rax
  char *pData; // r8
  Scaleform::GFx::ASString *v10; // rdi
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::StringBuffer dest; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  v3 = ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29;
  v4 = fn->ThisPtr;
  v5 = v4 && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = fn->ThisPtr;
    if ( v6 )
    {
      v7 = v6 - 2;
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        Scaleform::StringBuffer::StringBuffer(&dest, Scaleform::Memory::pGlobalHeap);
        pObject = v7[6].pProto.pObject;
        if ( pObject )
        {
          if ( LOBYTE(pObject->ResolveHandler.pLocalFrame) == 1 )
            Scaleform::GFx::AS2::BuildXMLString(fn->Env, (Scaleform::GFx::XML::Node *)v7[6].pProto.pObject, &dest);
          else
            Scaleform::StringBuffer::AppendString(&dest, **(const char ***)&pObject->RefCount, -1i64);
          pData = &customCaption;
          if ( dest.pData )
            pData = dest.pData;
          v10 = Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &result, pData, dest.Size);
          v11 = fn->Result;
          if ( v11->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v11);
          v11->T.Type = 5;
          pNode = v10->pNode;
          v11->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v10->pNode;
          ++pNode->RefCount;
          v13 = result.pNode;
          if ( result.pNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        }
        else
        {
          v15 = fn->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v15);
          v15->T.Type = 0;
        }
        Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&dest);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid this is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1561
// RVA: 0x6FAA50
void __fastcall Scaleform::GFx::AS2::XmlNodeCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::ExternalLibPtr *v2; // r14
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v7; // rax
  Scaleform::GFx::LogState *v8; // rdi
  char v9; // r12
  char Type; // r13
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v13; // rdx
  unsigned int v14; // edx
  Scaleform::GFx::AS2::Environment *v15; // r9
  Scaleform::GFx::AS2::Value *v16; // r8
  __int64 v17; // rcx
  double v18; // xmm0_8
  Scaleform::GFx::MovieImpl *pMovieImpl; // r15
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // rdi
  Scaleform::GFx::XML::ObjectManager *v21; // rax
  Scaleform::GFx::XML::ObjectManager *v22; // rax
  Scaleform::GFx::XML::ObjectManager *v23; // rdi
  unsigned __int64 v24; // r14
  char *v25; // rax
  char *v26; // r15
  Scaleform::GFx::XML::DOMString *v27; // rax
  Scaleform::GFx::XML::DOMString *v28; // rax
  Scaleform::GFx::XML::DOMString *v29; // rax
  Scaleform::GFx::XML::DOMString v30; // rax
  Scaleform::GFx::XML::TextNode *ElementNode; // r14
  Scaleform::GFx::XML::RootNode *RootNode; // r15
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::GFx::XML::DOMString *v34; // rax
  Scaleform::GFx::XML::DOMString v35; // rax
  Scaleform::GFx::XML::RootNode *v36; // r15
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::GFx::XML::DOMString v38; // rax
  Scaleform::GFx::XML::RootNode *v39; // r15
  Scaleform::RefCountNTSImpl *v40; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *v43; // r8
  unsigned int RefCount; // eax
  Scaleform::GFx::XML::DOMString v45; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::GFx::XML::DOMString *v46; // [rsp+28h] [rbp-61h]
  Scaleform::GFx::XML::DOMString *v47; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::XML::ObjectManager *v48; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::Value v49; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value v50; // [rsp+60h] [rbp-29h] BYREF
  __int64 v51; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::XML::DOMString result; // [rsp+F0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v53; // [rsp+F8h] [rbp+6Fh] BYREF
  Scaleform::GFx::XML::DOMString v54; // [rsp+100h] [rbp+77h] BYREF
  Scaleform::GFx::AS2::XmlNodeObject *v55; // [rsp+108h] [rbp+7Fh]

  v51 = -2i64;
  v2 = 0i64;
  v55 = 0i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && ((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 29
     || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 28) )
  {
    v4 = fn->ThisPtr;
    if ( v4 )
    {
      v5 = (Scaleform::GFx::AS2::XmlNodeObject *)&v4[-2];
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      v5 = 0i64;
    }
  }
  else
  {
    result.pNode = (Scaleform::GFx::XML::DOMStringNode *)fn->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *, __int64))result.pNode->pData
                                          + 10))(
                                           ThisPtr,
                                           112i64);
    v53.pNode = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject((Scaleform::GFx::AS2::XmlNodeObject *)v6, fn->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v55 = v5;
  v8 = (Scaleform::GFx::LogState *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))fn->Env->Target->vfptr[76].__vecDelDtor)(fn->Env->Target);
  v9 = 0;
  v49.T.Type = 0;
  Type = 0;
  v50.T.Type = 0;
  if ( fn->NArgs <= 0 )
    goto LABEL_56;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v13 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v13 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::operator=(&v49, v13);
  if ( fn->NArgs > 1 )
  {
    v14 = fn->FirstArgBottomIndex - 1;
    v15 = fn->Env;
    v16 = 0i64;
    if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v15->Stack.pCurrent - v15->Stack.pPageStart) )
      v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&v50, v16);
    Type = v50.T.Type;
  }
  v9 = v49.T.Type;
  if ( !v49.T.Type || v49.T.Type == 10 )
  {
LABEL_56:
    if ( !v8 )
      goto LABEL_59;
    v43 = "XMLNodeCtorFunction::GlobalCtor - node type not specified";
    goto LABEL_58;
  }
  v18 = Scaleform::GFx::AS2::Value::ToNumber(&v49, fn->Env);
  if ( !Type || Type == 10 )
  {
    if ( !v8 )
      goto LABEL_59;
    v43 = "XMLNodeCtorFunction::GlobalCtor - malformed XMLNode object";
LABEL_58:
    LODWORD(result.pNode) = 147456;
    Scaleform::Log::LogMessageById(v8, (Scaleform::LogMessageId)&result, v43);
    goto LABEL_59;
  }
  pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
  v48 = 0i64;
  pXMLObjectManager = pMovieImpl->pXMLObjectManager;
  if ( pXMLObjectManager )
  {
    v23 = (Scaleform::GFx::XML::ObjectManager *)&pXMLObjectManager[-1];
    if ( v23 )
      ++v23->RefCount;
    v48 = v23;
  }
  else
  {
    v45.pNode = (Scaleform::GFx::XML::DOMStringNode *)fn->Env->StringContext.pContext->pHeap;
    v21 = (Scaleform::GFx::XML::ObjectManager *)(*((__int64 (__fastcall **)(__int64, __int64, _QWORD))v45.pNode->pData
                                                 + 10))(
                                                  v17,
                                                  120i64,
                                                  0i64);
    v46 = (Scaleform::GFx::XML::DOMString *)v21;
    if ( v21 )
    {
      Scaleform::GFx::XML::ObjectManager::ObjectManager(v21, pMovieImpl);
      v23 = v22;
    }
    else
    {
      v23 = 0i64;
    }
    v48 = v23;
    if ( v23 )
      v2 = &v23->Scaleform::GFx::ExternalLibPtr;
    pMovieImpl->pXMLObjectManager = v2;
  }
  Scaleform::GFx::XML::ObjectManager::EmptyString(v23, &result);
  Scaleform::GFx::XML::ObjectManager::EmptyString(v23, &v54);
  v24 = -1i64;
  Scaleform::GFx::AS2::Value::ToString(&v50, &v53, fn->Env, -1);
  if ( v18 == 1.0 )
  {
    v25 = strchr(v53.pNode->pData, 58);
    v26 = v25;
    if ( v25 )
    {
      v27 = Scaleform::GFx::XML::ObjectManager::CreateString(v23, &v45, v53.pNode->pData, v25 - v53.pNode->pData);
      Scaleform::GFx::XML::DOMString::AssignNode(&v54, v27->pNode);
      Scaleform::GFx::XML::DOMString::~DOMString(&v45);
      do
        ++v24;
      while ( v26[v24] );
      v28 = Scaleform::GFx::XML::ObjectManager::CreateString(v23, &v45, v26 + 1, v24);
      Scaleform::GFx::XML::DOMString::AssignNode(&result, v28->pNode);
    }
    else
    {
      v29 = Scaleform::GFx::XML::ObjectManager::CreateString(v23, &v45, v53.pNode->pData, v53.pNode->Size);
      Scaleform::GFx::XML::DOMString::AssignNode(&result, v29->pNode);
    }
    Scaleform::GFx::XML::DOMString::~DOMString(&v45);
    v46 = &v45;
    Scaleform::GFx::XML::DOMString::DOMString(&v45, &result);
    ElementNode = (Scaleform::GFx::XML::TextNode *)Scaleform::GFx::XML::ObjectManager::CreateElementNode(v23, v30);
    v47 = (Scaleform::GFx::XML::DOMString *)ElementNode;
    v5->pRealNode = ElementNode;
    RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v23, ElementNode);
    pObject = v5->pRootNode.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    v5->pRootNode.pObject = RootNode;
    Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&v5->pRealNode[1], v54.pNode);
  }
  else if ( v18 == 3.0 )
  {
    v34 = Scaleform::GFx::XML::ObjectManager::CreateString(v23, &v45, v53.pNode->pData, v53.pNode->Size);
    Scaleform::GFx::XML::DOMString::AssignNode(&result, v34->pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v45);
    v47 = &v45;
    Scaleform::GFx::XML::DOMString::DOMString(&v45, &result);
    ElementNode = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v23, v35);
    v46 = (Scaleform::GFx::XML::DOMString *)ElementNode;
    v5->pRealNode = ElementNode;
    v36 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v23, ElementNode);
    v37 = v5->pRootNode.pObject;
    if ( v37 )
      Scaleform::RefCountNTSImpl::Release(v37);
    v5->pRootNode.pObject = v36;
  }
  else
  {
    v47 = &v45;
    Scaleform::GFx::XML::DOMString::DOMString(&v45, &result);
    ElementNode = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v23, v38);
    v46 = (Scaleform::GFx::XML::DOMString *)ElementNode;
    v5->pRealNode = ElementNode;
    v39 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v23, ElementNode);
    v40 = v5->pRootNode.pObject;
    if ( v40 )
      Scaleform::RefCountNTSImpl::Release(v40);
    v5->pRootNode.pObject = v39;
    v5->pRealNode->Type = (int)v18;
  }
  if ( ElementNode )
    Scaleform::RefCountNTSImpl::Release(ElementNode);
  Scaleform::GFx::AS2::SetupShadow(fn->Env, v5->pRealNode, v5);
  pNode = v53.pNode;
  if ( v53.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v54);
  Scaleform::GFx::XML::DOMString::~DOMString(&result);
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release(v23);
LABEL_59:
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v50);
  if ( (unsigned __int8)v9 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v49);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}

// File Line: 1671
// RVA: 0x6E09B0
void __fastcall Scaleform::GFx::AS2::XmlNodeCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::XmlNodeCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::XmlNodeObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::XmlNodeObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::XmlNodeCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               this,
                                               112i64);
  if ( v3 )
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v3, penv);
}

// File Line: 1677
// RVA: 0x70F9B0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::XmlNodeCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::XmlNodeProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_objproto; // [rsp+C8h] [rbp+50h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  pHeap = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))pHeap->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  p_objproto = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::XmlNodeCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    pObject = v6->pProto.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v6->pProto.pObject = Prototype;
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v9 = (Scaleform::GFx::AS2::XmlNodeProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                              pObject,
                                              184i64,
                                              0i64);
  pHeap = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::XmlNodeProto::XmlNodeProto(v9, &psc, v10, result);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v12;
  p_objproto = &objproto;
  if ( v12 )
    *(_DWORD *)(v12 + 24) = (*(_DWORD *)(v12 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_XMLNode,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = pgc->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v19.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v19.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v13->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[12].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  Scaleform::GFx::AS2::XmlNodeObject::InitializeStandardMembers(pgc, (Scaleform::GFx::ASStringHash<char> *)(v12 + 176));
  if ( v12 )
  {
    v16 = *(_DWORD *)(v12 + 24);
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v12 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12);
    }
  }
  return result;
}

