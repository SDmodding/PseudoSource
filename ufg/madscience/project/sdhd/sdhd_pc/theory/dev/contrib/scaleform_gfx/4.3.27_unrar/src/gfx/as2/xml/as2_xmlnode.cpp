// File Line: 77
// RVA: 0x6F6560
__int64 __fastcall Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(Scaleform::GFx::AS2::XmlNodeObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *memberName)
{
  Scaleform::GFx::ASString *v3; // rsi
  char v4; // bl
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v5; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v6; // rdi
  signed __int64 v7; // rax
  signed __int64 v8; // rcx

  v3 = memberName;
  v4 = -1;
  if ( (memberName->pNode->HashFlags >> 29) & 1 )
  {
    v5 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_XMLNode)[1].pWatchpoints;
    v6.pTable = v5->pTable;
    if ( v5->pTable )
    {
      v7 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
             v5,
             v3,
             v6.pTable->SizeMask & v3->pNode->HashFlags);
      if ( v7 >= 0 )
      {
        v8 = (signed __int64)v6.pTable + 8 * (3 * v7 + 3);
        if ( v8 )
          v4 = *(_BYTE *)(v8 + 8);
      }
    }
  }
  return (unsigned int)v4;
}

// File Line: 95
// RVA: 0x6FD6F0
void __fastcall Scaleform::GFx::AS2::XmlNodeObject::InitializeStandardMembers(Scaleform::GFx::AS2::GlobalContext *gc, Scaleform::GFx::ASStringHash<char> *hash)
{
  Scaleform::GFx::ASStringHash<char> *v2; // rdi
  Scaleform::RefCountImplCoreVtbl *v3; // rsi
  Scaleform::GFx::AS2::GASDocument *v4; // rbx
  const char *v5; // r8
  unsigned __int64 v6; // r9
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h]
  char v10; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]

  v2 = hash;
  v3 = gc->pMovieRoot->pASMovieRoot.pObject[39].vfptr;
  if ( !hash->mHash.pTable || hash->mHash.pTable->EntryCount < 0x10 )
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&hash->mHash.pTable,
      hash,
      0x10ui64);
  v4 = Scaleform::GFx::AS2::XmlNodeObject_MemberTable;
  if ( Scaleform::GFx::AS2::XmlNodeObject_MemberTable[0].pName )
  {
    key.pFirst = &result;
    key.pSecond = &v10;
    do
    {
      v5 = v4->pName;
      v6 = -1i64;
      do
        ++v6;
      while ( v5[v6] );
      Scaleform::GFx::ASStringManager::CreateConstString(
        (Scaleform::GFx::ASStringManager *)v3,
        &result,
        v5,
        v6,
        0x20000000u);
      v10 = v4->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&v2->mHash.pTable,
        v2,
        &key,
        result.pNode->HashFlags);
      v7 = result.pNode;
      v8 = result.pNode->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
      ++v4;
    }
    while ( v4->pName );
  }
}

// File Line: 119
// RVA: 0x71F910
void __fastcall Scaleform::GFx::AS2::SetupAttributes(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::ElementNode *preal)
{
  Scaleform::GFx::XML::ElementNode *v2; // rsi
  Scaleform::GFx::AS2::Environment *v3; // r14
  Scaleform::GFx::XML::ShadowRefBase *v4; // rbp
  Scaleform::GFx::ASStringNode *v5; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v6; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v7; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  Scaleform::GFx::XML::Attribute *i; // rdi
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v12; // rbx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::AS2::Value v17; // [rsp+38h] [rbp-50h]
  Scaleform::MemoryHeap *v18; // [rsp+90h] [rbp+8h]
  Scaleform::GFx::ASString v19; // [rsp+98h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+18h]

  v2 = preal;
  v3 = penv;
  v4 = preal->pShadow;
  v18 = penv->StringContext.pContext->pHeap;
  v5 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::Environment *, signed __int64))v18->vfptr->Alloc)(
                                         penv,
                                         96i64);
  v19.pNode = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v5, v3);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v4[2].vfptr;
  if ( v8 )
  {
    v9 = v8->RefCount;
    if ( v9 & 0x3FFFFFF )
    {
      v8->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  v4[2].vfptr = v7;
  if ( UFG::UIGfxTexture::IsValid(v2) )
  {
    for ( i = v2->FirstAttribute; i; i = i->Next )
    {
      v11 = Scaleform::GFx::AS2::ASStringContext::CreateString(&v3->StringContext, &result, i->Value.pNode->pData);
      v17.T.Type = 5;
      v17.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v11->pNode;
      ++v17.V.pStringNode->RefCount;
      v12 = v4[2].vfptr;
      v13 = Scaleform::GFx::AS2::ASStringContext::CreateString(&v3->StringContext, &v19, i->Name.pNode->pData);
      LOBYTE(v18) = 0;
      (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::MemoryHeap **))v12[4].__vecDelDtor
       + 3))(
        v12 + 4,
        v3,
        v13,
        &v17,
        &v18);
      v14 = v19.pNode;
      v15 = v19.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( v17.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v17);
      v16 = result.pNode;
      v15 = result.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    Scaleform::GFx::XML::ElementNode::ClearAttributes(v2);
  }
}

// File Line: 145
// RVA: 0x71FA90
void __fastcall Scaleform::GFx::AS2::SetupShadow(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::Node *preal, Scaleform::GFx::AS2::XmlNodeObject *asobj)
{
  Scaleform::GFx::AS2::XmlNodeObject *v3; // rdi
  Scaleform::GFx::XML::ElementNode *v4; // rbx
  Scaleform::GFx::AS2::Environment *v5; // rsi
  Scaleform::GFx::XML::ShadowRefBase *v6; // rax

  v3 = asobj;
  v4 = (Scaleform::GFx::XML::ElementNode *)preal;
  v5 = penv;
  if ( !preal->pShadow )
  {
    v6 = (Scaleform::GFx::XML::ShadowRefBase *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::Environment *, signed __int64))preal->MemoryManager.pObject->pHeap->vfptr->Alloc)(
                                                 penv,
                                                 24i64);
    if ( v6 )
    {
      v6->vfptr = (Scaleform::GFx::XML::ShadowRefBaseVtbl *)&Scaleform::GFx::XML::ShadowRefBase::`vftable';
      v6->vfptr = (Scaleform::GFx::XML::ShadowRefBaseVtbl *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable';
      v6[1].vfptr = 0i64;
      v6[2].vfptr = 0i64;
    }
    v4->pShadow = v6;
    if ( v4->Type == 1 )
      Scaleform::GFx::AS2::SetupAttributes(v5, v4);
  }
  v4->pShadow[1].vfptr = (Scaleform::GFx::XML::ShadowRefBaseVtbl *)v3;
  v3->pRealNode = (Scaleform::GFx::XML::Node *)&v4->vfptr;
}

// File Line: 166
// RVA: 0x6E10E0
Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *__fastcall Scaleform::GFx::AS2::CreateShadow(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *result, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::Node *preal, Scaleform::GFx::XML::RootNode *proot)
{
  Scaleform::GFx::XML::RootNode *v4; // rsi
  Scaleform::GFx::XML::Node *v5; // rbp
  Scaleform::GFx::AS2::Environment *v6; // rdi
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v7; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *v8; // r14
  Scaleform::GFx::AS2::XmlNodeObject *v9; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v10; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v11; // rdi
  Scaleform::RefCountNTSImpl *v12; // rcx

  v4 = proot;
  v5 = preal;
  v6 = penv;
  v7 = result;
  v8 = 0i64;
  v9 = (Scaleform::GFx::AS2::XmlNodeObject *)penv->StringContext.pContext->pHeap->vfptr->Alloc(
                                               (Scaleform::MemoryHeap *)result,
                                               112ui64,
                                               0i64);
  if ( v9 )
  {
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v9, v6);
    v8 = v10;
  }
  v7->pObject = v8;
  Scaleform::GFx::AS2::SetupShadow(v6, v5, v7->pObject);
  v11 = v7->pObject;
  if ( v4 )
    ++v4->RefCount;
  else
    v4 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v5->MemoryManager.pObject, v5);
  v12 = (Scaleform::RefCountNTSImpl *)&v11->pRootNode.pObject->vfptr;
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release(v12);
  v11->pRootNode.pObject = v4;
  return v7;
}

// File Line: 183
// RVA: 0x724AD0
void __fastcall Scaleform::GFx::AS2::Xml_CreateIDMap(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::ElementNode *elemNode, Scaleform::GFx::XML::RootNode *proot, Scaleform::GFx::AS2::Object *pobj)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::XML::RootNode *v5; // rdi
  Scaleform::GFx::AS2::Environment *v6; // rbp
  Scaleform::GFx::XML::ElementNode *i; // rsi
  Scaleform::GFx::XML::Attribute *v8; // rbx
  Scaleform::MemoryHeap *v9; // rcx
  Scaleform::GFx::XML::ShadowRefBase *v10; // rbx
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *v11; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v12; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::XmlNodeObject *v15; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v16; // rax
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::GFx::AS2::Value *v18; // rdi
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  unsigned int v22; // eax
  Scaleform::String str; // [rsp+38h] [rbp-70h]
  Scaleform::GFx::ASString v24; // [rsp+40h] [rbp-68h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [rsp+48h] [rbp-60h]
  Scaleform::MemoryHeap *v26; // [rsp+50h] [rbp-58h]
  Scaleform::GFx::AS2::XmlNodeObject *v27; // [rsp+58h] [rbp-50h]
  __int64 v28; // [rsp+60h] [rbp-48h]
  Scaleform::GFx::AS2::Value v29; // [rsp+68h] [rbp-40h]
  char v30; // [rsp+B8h] [rbp+10h]
  Scaleform::GFx::XML::RootNode *v31; // [rsp+C0h] [rbp+18h]
  Scaleform::GFx::AS2::Object *v32; // [rsp+C8h] [rbp+20h]

  v32 = pobj;
  v31 = proot;
  v28 = -2i64;
  v4 = pobj;
  v5 = proot;
  v6 = penv;
  for ( i = (Scaleform::GFx::XML::ElementNode *)elemNode->FirstChild.pObject;
        i;
        i = (Scaleform::GFx::XML::ElementNode *)i->NextSibling.pObject )
  {
    if ( i->Type == 1 )
    {
      Scaleform::GFx::AS2::Xml_CreateIDMap(v6, i, v5, v4);
      v8 = i->FirstAttribute;
      if ( v8 )
      {
        while ( strncmp(v8->Name.pNode->pData, "id", 2ui64) )
        {
          v8 = v8->Next;
          if ( !v8 )
            goto LABEL_30;
        }
        Scaleform::String::String(&str, v8->Value.pNode->pData, v8->Value.pNode->Size);
        v10 = i->pShadow;
        if ( v10 )
        {
          v12 = (Scaleform::GFx::AS2::XmlNodeObject *)v10[1].vfptr;
          if ( v12 )
            v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
          if ( !v12 )
          {
            v26 = v6->StringContext.pContext->pHeap;
            v15 = (Scaleform::GFx::AS2::XmlNodeObject *)v26->vfptr->Alloc(v9, 112ui64, 0i64);
            v27 = v15;
            if ( v15 )
            {
              Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v15, v6);
              v12 = v16;
            }
            else
            {
              v12 = 0i64;
            }
            Scaleform::GFx::AS2::SetupShadow(v6, (Scaleform::GFx::XML::Node *)&i->vfptr, v12);
          }
        }
        else
        {
          v11 = Scaleform::GFx::AS2::CreateShadow(&result, v6, (Scaleform::GFx::XML::Node *)&i->vfptr, v5);
          if ( v11->pObject )
            v11->pObject->RefCount = (v11->pObject->RefCount + 1) & 0x8FFFFFFF;
          v12 = v11->pObject;
          v13 = result.pObject;
          if ( result.pObject )
          {
            v14 = result.pObject->RefCount;
            if ( v14 & 0x3FFFFFF )
            {
              result.pObject->RefCount = v14 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
            }
          }
        }
        Scaleform::GFx::AS2::Value::Value(&v29, (Scaleform::GFx::AS2::Object *)&v12->vfptr);
        v18 = v17;
        v19 = Scaleform::GFx::AS2::Environment::CreateString(v6, &v24, &str);
        v30 = 0;
        v32->vfptr->SetMember(
          (Scaleform::GFx::AS2::ObjectInterface *)&v32->vfptr,
          v6,
          v19,
          v18,
          (Scaleform::GFx::AS2::PropFlags *)&v30);
        v20 = v24.pNode;
        v21 = v24.pNode->RefCount == 1;
        --v20->RefCount;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        if ( v29.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v29);
        if ( v12 )
        {
          v22 = v12->RefCount;
          if ( v22 & 0x3FFFFFF )
          {
            v12->RefCount = v22 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
          }
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v5 = v31;
      }
LABEL_30:
      v4 = v32;
    }
  }
}

// File Line: 236
// RVA: 0x7123D0
void __fastcall Scaleform::GFx::AS2::ResolveNamespace(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::ElementNode *elemNode, Scaleform::GFx::XML::RootNode *proot)
{
  Scaleform::GFx::XML::RootNode *v3; // r14
  Scaleform::GFx::XML::ElementNode *v4; // rsi
  Scaleform::GFx::AS2::Environment *v5; // rdi
  const char *v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::XML::DOMString *v8; // rax
  signed __int64 v9; // rcx
  Scaleform::GFx::XML::DOMString *v10; // rax
  Scaleform::GFx::XML::Node *i; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // rcx
  int v13; // eax
  signed __int64 v14; // rcx
  Scaleform::GFx::XML::DOMString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::AS2::Value v19; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+30h]
  Scaleform::GFx::XML::DOMString v21; // [rsp+88h] [rbp+38h]
  Scaleform::GFx::XML::DOMString v22; // [rsp+98h] [rbp+48h]

  v3 = proot;
  v4 = elemNode;
  v5 = penv;
  Scaleform::GFx::AS2::ASStringContext::CreateString(&penv->StringContext, &result, "xmlns", 5ui64);
  if ( v4->Prefix.pNode->Size )
  {
    Scaleform::GFx::ASString::Append(&result, ":", 1ui64);
    v6 = v4->Prefix.pNode->pData;
    v7 = -1i64;
    do
      ++v7;
    while ( v6[v7] );
    Scaleform::GFx::ASString::Append(&result, v6, v7);
  }
  v19.T.Type = 0;
  v8 = Scaleform::GFx::XML::ObjectManager::EmptyString(v4->MemoryManager.pObject, &v21);
  Scaleform::GFx::XML::DOMString::AssignNode(&v4->Namespace, v8->pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v21);
  v9 = (signed __int64)&v4->pShadow[2].vfptr[4];
  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))(*(_QWORD *)v9 + 32i64))(
    v9,
    v5,
    &result,
    &v19,
    -2i64);
  if ( v19.T.Type && v19.T.Type != 10 )
  {
    Scaleform::GFx::AS2::Value::ToString(&v19, (Scaleform::GFx::ASString *)&v21, v5, -1);
    v10 = Scaleform::GFx::XML::ObjectManager::CreateString(
            v4->MemoryManager.pObject,
            &v22,
            v21.pNode->pData,
            LODWORD(v21.pNode[1].pData));
    Scaleform::GFx::XML::DOMString::AssignNode(&v4->Namespace, v10->pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v22);
LABEL_18:
    v16 = (Scaleform::GFx::ASStringNode *)v21.pNode;
    v17 = v21.pNode->RefCount == 1;
    --v16->RefCount;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  else
  {
    for ( i = (Scaleform::GFx::XML::Node *)&v4->Parent->vfptr; i; i = (Scaleform::GFx::XML::Node *)&i->Parent->vfptr )
    {
      if ( !i->pShadow )
      {
        Scaleform::GFx::AS2::CreateShadow((Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&v21, v5, i, v3);
        v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v21.pNode;
        if ( v21.pNode )
        {
          v13 = v21.pNode->RefCount;
          if ( v13 & 0x3FFFFFF )
          {
            v21.pNode->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
          }
        }
      }
      v14 = (signed __int64)&i->pShadow[2].vfptr[4];
      (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v14 + 32i64))(
        v14,
        v5,
        &result,
        &v19);
      if ( v19.T.Type && v19.T.Type != 10 )
      {
        Scaleform::GFx::AS2::Value::ToString(&v19, (Scaleform::GFx::ASString *)&v21, v5, -1);
        v15 = Scaleform::GFx::XML::ObjectManager::CreateString(
                v4->MemoryManager.pObject,
                &v22,
                v21.pNode->pData,
                LODWORD(v21.pNode[1].pData));
        Scaleform::GFx::XML::DOMString::AssignNode(&v4->Namespace, v15->pNode);
        Scaleform::GFx::XML::DOMString::~DOMString(&v22);
        goto LABEL_18;
      }
    }
  }
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  v18 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
}

// File Line: 298
// RVA: 0x6CDC20
void __fastcall Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(Scaleform::GFx::AS2::XmlNodeObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->pRootNode.pObject = 0i64;
  v3->pRealNode = 0i64;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_XMLNode);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 307
// RVA: 0x6D2B60
void __fastcall Scaleform::GFx::AS2::XmlNodeObject::~XmlNodeObject(Scaleform::GFx::AS2::XmlNodeObject *this)
{
  Scaleform::GFx::AS2::XmlNodeObject *v1; // rbx
  Scaleform::GFx::XML::Node *v2; // rax
  Scaleform::GFx::XML::ShadowRefBase *v3; // rax
  Scaleform::GFx::XML::RootNode *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v2 = this->pRealNode;
  if ( v2 )
  {
    v3 = v2->pShadow;
    if ( v3 )
      v3[1].vfptr = 0i64;
  }
  v4 = this->pRootNode.pObject;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&v1->vfptr);
}

// File Line: 325
// RVA: 0x719400
char __fastcall Scaleform::GFx::AS2::XmlNodeObject::SetMember(Scaleform::GFx::AS2::XmlNodeObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, Scaleform::GFx::AS2::PropFlags *flags)
{
  Scaleform::GFx::AS2::Value *v5; // r15
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::Environment *v7; // r14
  Scaleform::GFx::AS2::XmlNodeObject *v8; // rdi
  Scaleform::GFx::LogState *v9; // rbx
  int v10; // eax
  __int64 v11; // rax
  Scaleform::GFx::XML::DOMString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::XML::ElementNode *v16; // rsi
  unsigned __int64 v17; // rbx
  const char *v18; // r15
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
  unsigned int v32; // eax
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-50h]
  Scaleform::LogMessageId v34; // [rsp+38h] [rbp-48h]
  Scaleform::GFx::ASString v35; // [rsp+40h] [rbp-40h]
  Scaleform::LogMessageId v36; // [rsp+48h] [rbp-38h]
  Scaleform::LogMessageId v37; // [rsp+4Ch] [rbp-34h]
  Scaleform::GFx::XML::DOMString v38; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::XML::DOMString v39; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::XML::DOMString v40; // [rsp+60h] [rbp-20h]
  Scaleform::GFx::XML::DOMString v41; // [rsp+68h] [rbp-18h]
  __int64 v42; // [rsp+70h] [rbp-10h]
  Scaleform::LogMessageId messageType; // [rsp+B0h] [rbp+30h]
  Scaleform::LogMessageId v44; // [rsp+B8h] [rbp+38h]

  v42 = -2i64;
  v5 = val;
  v6 = name;
  v7 = penv;
  v8 = this;
  v9 = (Scaleform::GFx::LogState *)((__int64 (*)(void))penv->Target->vfptr[76].__vecDelDtor)();
  if ( *(_QWORD *)&v8->ResolveHandler.Flags )
  {
    v10 = Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
            (Scaleform::GFx::AS2::XmlNodeObject *)((char *)v8 - 32),
            v7,
            v6);
    if ( v10 )
    {
      if ( v10 != 7 )
      {
        if ( v10 == 9 )
        {
          v11 = *(_QWORD *)&v8->ResolveHandler.Flags;
          if ( v11 && *(_BYTE *)(v11 + 64) != 1 )
          {
            Scaleform::GFx::AS2::Value::ToString(v5, &result, v7, -1);
            v12 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&v8->ResolveHandler.Flags + 16i64),
                    &v38,
                    result.pNode->pData,
                    result.pNode->Size);
            Scaleform::GFx::XML::DOMString::AssignNode(
              (Scaleform::GFx::XML::DOMString *)(*(_QWORD *)&v8->ResolveHandler.Flags + 24i64),
              v12->pNode);
            Scaleform::GFx::XML::DOMString::~DOMString(&v38);
            v13 = result.pNode;
            v14 = result.pNode->RefCount == 1;
            --v13->RefCount;
            if ( v14 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v13);
          }
          else if ( v9 )
          {
            messageType.Id = 147456;
            Scaleform::Log::LogMessageById(
              v9,
              (Scaleform::LogMessageId)&messageType,
              "XMLNodeObject::SetMember - cannot set nodeValue of a malformed node");
            return 1;
          }
          return 1;
        }
        return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
      }
      v16 = *(Scaleform::GFx::XML::ElementNode **)&v8->ResolveHandler.Flags;
      if ( v16 )
      {
        if ( v16->Type == 1 )
        {
          Scaleform::GFx::XML::ObjectManager::EmptyString(
            v16->MemoryManager.pObject,
            (Scaleform::GFx::XML::DOMString *)&result);
          v17 = -1i64;
          Scaleform::GFx::AS2::Value::ToString(v5, &v35, v7, -1);
          v18 = v35.pNode->pData;
          v19 = strchr(v35.pNode->pData, 58);
          v20 = v19;
          if ( v19 )
          {
            v21 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&v8->ResolveHandler.Flags + 16i64),
                    &v41,
                    v18,
                    v19 - v18);
            Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&result, v21->pNode);
            Scaleform::GFx::XML::DOMString::~DOMString(&v41);
            v22 = v20 + 1;
            do
              ++v17;
            while ( v22[v17] );
            v23 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&v8->ResolveHandler.Flags + 16i64),
                    &v39,
                    v22,
                    v17);
            Scaleform::GFx::XML::DOMString::AssignNode(
              (Scaleform::GFx::XML::DOMString *)(*(_QWORD *)&v8->ResolveHandler.Flags + 24i64),
              v23->pNode);
            v24 = &v39;
          }
          else
          {
            v25 = Scaleform::GFx::XML::ObjectManager::CreateString(
                    *(Scaleform::GFx::XML::ObjectManager **)(*(_QWORD *)&v8->ResolveHandler.Flags + 16i64),
                    &v40,
                    v35.pNode->pData,
                    v35.pNode->Size);
            Scaleform::GFx::XML::DOMString::AssignNode(
              (Scaleform::GFx::XML::DOMString *)(*(_QWORD *)&v8->ResolveHandler.Flags + 24i64),
              v25->pNode);
            v24 = &v40;
          }
          Scaleform::GFx::XML::DOMString::~DOMString(v24);
          Scaleform::GFx::XML::DOMString::AssignNode(&v16->Prefix, (Scaleform::GFx::XML::DOMStringNode *)result.pNode);
          Scaleform::GFx::AS2::ResolveNamespace(
            v7,
            v16,
            (Scaleform::GFx::XML::RootNode *)v8->ResolveHandler.pLocalFrame);
          v26 = v35.pNode;
          v14 = v35.pNode->RefCount == 1;
          --v26->RefCount;
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
      v27 = *(_QWORD *)&v8->ResolveHandler.Flags;
      if ( v27 )
      {
        if ( *(_BYTE *)(v27 + 64) == 1 )
        {
          v28 = *(_QWORD *)(v27 + 56);
          v29 = Scaleform::GFx::AS2::Value::ToObject(v5, v7);
          v30 = v29;
          if ( v29 )
            v29->RefCount = (v29->RefCount + 1) & 0x8FFFFFFF;
          v31 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v28 + 16);
          if ( v31 )
          {
            v32 = v31->RefCount;
            if ( v32 & 0x3FFFFFF )
            {
              v31->RefCount = v32 - 1;
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
  return Scaleform::GFx::AS2::Object::SetMember((Scaleform::GFx::AS2::Object *)&v8->vfptr, v7, v6, v5, flags);
}

// File Line: 460
// RVA: 0x6F29B0
char __fastcall Scaleform::GFx::AS2::XmlNodeObject::GetMember(Scaleform::GFx::AS2::XmlNodeObject *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::ASString *v5; // r14
  Scaleform::GFx::AS2::Environment *v6; // r15
  Scaleform::GFx::AS2::XmlNodeObject *v7; // rdi
  Scaleform::GFx::AS2::ASStringContext *v8; // rsi
  __int64 v9; // rcx
  __int64 v10; // rsi
  Scaleform::GFx::XML::Node *v11; // r8
  Scaleform::GFx::XML::ShadowRefBase *v12; // rdx
  Scaleform::GFx::AS2::Object *v13; // rdx
  Scaleform::GFx::AS2::Object **v14; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value *v17; // rcx
  __int64 v19; // r8
  Scaleform::GFx::XML::Node *v20; // r8
  Scaleform::GFx::XML::ShadowRefBase *v21; // rdx
  Scaleform::GFx::AS2::Object **v22; // rax
  __int64 v23; // rax
  Scaleform::GFx::AS2::ArrayObject *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // r14
  Scaleform::GFx::XML::Node *i; // rsi
  Scaleform::GFx::XML::ShadowRefBase *v28; // rax
  Scaleform::GFx::AS2::Object *v29; // rdx
  Scaleform::GFx::AS2::Object **v30; // rax
  Scaleform::GFx::AS2::Value *v31; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v32; // rcx
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
  unsigned int v53; // eax
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
  Scaleform::GFx::ASStringNode *v68; // rcx
  __int64 v69; // rax
  Scaleform::GFx::ASString *v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rcx
  __int64 v72; // rax
  Scaleform::GFx::ASString *v73; // rax
  Scaleform::GFx::ASStringNode *v74; // rcx
  __int64 v75; // rax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v76; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::ASString v77; // [rsp+28h] [rbp-61h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v78; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::ASString v79; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::ASString v80; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::ASString v81; // [rsp+48h] [rbp-41h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v82; // [rsp+50h] [rbp-39h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v83; // [rsp+58h] [rbp-31h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> v84; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::ArrayObject *v85; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::ASString v86; // [rsp+70h] [rbp-19h]
  __int64 v87; // [rsp+78h] [rbp-11h]
  Scaleform::GFx::AS2::Value vala; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::AS2::Value v89; // [rsp+A0h] [rbp+17h]
  Scaleform::GFx::ASString v90; // [rsp+F0h] [rbp+67h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [rsp+F8h] [rbp+6Fh]

  v87 = -2i64;
  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = this;
  v8 = &penv->StringContext;
  if ( !*(_QWORD *)&this->ResolveHandler.Flags )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::XmlNodeObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v7->vfptr[3].~RefCountBaseGC<323>)(
             v7,
             v8,
             v5,
             v4);
  switch ( Scaleform::GFx::AS2::XmlNodeObject::GetStandardMemberConstant(
             (Scaleform::GFx::AS2::XmlNodeObject *)((char *)this - 32),
             penv,
             name) )
  {
    case 0u:
      v47 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v47 )
        goto LABEL_14;
      v48 = *(_QWORD *)(v47 + 56);
      if ( !*(_QWORD *)(v48 + 16) )
      {
        v90.pNode = (Scaleform::GFx::ASStringNode *)v8->pContext->pHeap;
        v49 = (Scaleform::GFx::AS2::Object *)(*((__int64 (__fastcall **)(__int64, signed __int64))v90.pNode->pData + 10))(
                                               v9,
                                               96i64);
        v85 = (Scaleform::GFx::AS2::ArrayObject *)v49;
        if ( v49 )
        {
          Scaleform::GFx::AS2::Object::Object(v49, v6);
          v51 = v50;
        }
        else
        {
          v51 = 0i64;
        }
        v52 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v48 + 16);
        if ( v52 )
        {
          v53 = v52->RefCount;
          if ( v53 & 0x3FFFFFF )
          {
            v52->RefCount = v53 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v52);
          }
        }
        *(_QWORD *)(v48 + 16) = v51;
      }
      v13 = *(Scaleform::GFx::AS2::Object **)(v48 + 16);
      goto LABEL_66;
    case 1u:
      v23 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v23 || *(_BYTE *)(v23 + 64) != 1 )
        goto LABEL_14;
      v90.pNode = (Scaleform::GFx::ASStringNode *)v8->pContext->pHeap;
      v24 = (Scaleform::GFx::AS2::ArrayObject *)(*((__int64 (__fastcall **)(__int64, signed __int64, _QWORD))v90.pNode->pData
                                                 + 10))(
                                                  v9,
                                                  144i64,
                                                  0i64);
      v85 = v24;
      if ( v24 )
      {
        Scaleform::GFx::AS2::ArrayObject::ArrayObject(v24, v6);
        v26 = v25;
      }
      else
      {
        v26 = 0i64;
      }
      v90.pNode = v26;
      for ( i = *(Scaleform::GFx::XML::Node **)(*(_QWORD *)&v7->ResolveHandler.Flags + 104i64);
            i;
            i = i->NextSibling.pObject )
      {
        v28 = i->pShadow;
        if ( v28 && (v29 = (Scaleform::GFx::AS2::Object *)v28[1].vfptr) != 0i64 )
        {
          Scaleform::GFx::AS2::Value::Value(&vala, v29);
          Scaleform::GFx::AS2::ArrayObject::PushBack((Scaleform::GFx::AS2::ArrayObject *)v26, &vala);
          if ( vala.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&vala);
        }
        else
        {
          v30 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                                  &v78,
                                                  v6,
                                                  i,
                                                  (Scaleform::GFx::XML::RootNode *)v7->ResolveHandler.pLocalFrame);
          Scaleform::GFx::AS2::Value::Value(&v89, *v30);
          Scaleform::GFx::AS2::ArrayObject::PushBack((Scaleform::GFx::AS2::ArrayObject *)v26, v31);
          if ( v89.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v89);
          v32 = v78.pObject;
          if ( v78.pObject )
          {
            v33 = v78.pObject->RefCount;
            if ( v33 & 0x3FFFFFF )
            {
              v78.pObject->RefCount = v33 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v32->vfptr);
            }
          }
        }
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v4, (Scaleform::GFx::AS2::Object *)v26);
      if ( !v26 )
        return 1;
      v34 = v26->RefCount;
      if ( !(v34 & 0x3FFFFFF) )
        return 1;
      v26->RefCount = v34 - 1;
      v15 = (Scaleform::GFx::AS2::XmlNodeObject *)v26;
      goto LABEL_12;
    case 2u:
      v10 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v10 )
        goto LABEL_14;
      if ( *(_BYTE *)(v10 + 64) != 1
        || !Scaleform::GFx::XML::ElementNode::HasChildren(*(Scaleform::GFx::XML::ElementNode **)&v7->ResolveHandler.Flags) )
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
                                              &result,
                                              v6,
                                              v11,
                                              (Scaleform::GFx::XML::RootNode *)v7->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(v4, *v14);
      v15 = result.pObject;
      goto LABEL_9;
    case 3u:
      v54 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v54 )
        goto LABEL_14;
      if ( *(_BYTE *)(v54 + 64) != 1
        || !Scaleform::GFx::XML::ElementNode::HasChildren(*(Scaleform::GFx::XML::ElementNode **)&v7->ResolveHandler.Flags) )
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
                                              &v83,
                                              v6,
                                              v55,
                                              (Scaleform::GFx::XML::RootNode *)v7->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(v4, *v57);
      v15 = v83.pObject;
      goto LABEL_9;
    case 4u:
      v66 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v66 || *(_BYTE *)(v66 + 64) != 1 )
        goto LABEL_14;
      v67 = Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &v77, **(const char ***)(v66 + 24));
      Scaleform::GFx::AS2::Value::SetString(v4, v67);
      v68 = v77.pNode;
      v41 = v77.pNode->RefCount == 1;
      --v68->RefCount;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v68);
      return 1;
    case 5u:
      v69 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v69 || *(_BYTE *)(v69 + 64) != 1 )
        goto LABEL_14;
      v70 = Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &v79, **(const char ***)(v69 + 80));
      Scaleform::GFx::AS2::Value::SetString(v4, v70);
      v71 = v79.pNode;
      v41 = v79.pNode->RefCount == 1;
      --v71->RefCount;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v71);
      return 1;
    case 6u:
      v19 = *(_QWORD *)&v7->ResolveHandler.Flags;
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
                                              &v84,
                                              v6,
                                              v20,
                                              (Scaleform::GFx::XML::RootNode *)v7->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(v4, *v22);
      v15 = v84.pObject;
      goto LABEL_9;
    case 7u:
      v35 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v35 )
        goto LABEL_14;
      if ( *(_BYTE *)(v35 + 64) != 1 )
        goto LABEL_13;
      v36 = *(_QWORD *)(v35 + 72);
      if ( *(_DWORD *)(v36 + 20) )
      {
        Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &v90, *(const char **)v36);
        Scaleform::GFx::ASString::Append(&v90, ":", 1ui64);
        v37 = **(const char ***)(v35 + 24);
        v38 = -1i64;
        do
          ++v38;
        while ( v37[v38] );
        Scaleform::GFx::ASString::Append(&v90, v37, v38);
        if ( v4->T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(v4);
        v4->T.Type = 5;
        v39 = v90.pNode;
        v4->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v90.pNode;
        ++v39->RefCount;
        v40 = v90.pNode;
        v41 = v90.pNode->RefCount == 1;
        --v40->RefCount;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v40);
      }
      else
      {
        v42 = Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &v86, **(const char ***)(v35 + 24));
        Scaleform::GFx::AS2::Value::SetString(v4, v42);
        v43 = v86.pNode;
        v41 = v86.pNode->RefCount == 1;
        --v43->RefCount;
        if ( v41 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v43);
      }
      return 1;
    case 8u:
      v75 = *(_QWORD *)&v7->ResolveHandler.Flags;
      v17 = v4;
      if ( !v75 )
        goto LABEL_15;
      Scaleform::GFx::AS2::Value::SetNumber(v4, (double)*(unsigned __int8 *)(v75 + 64));
      return 1;
    case 9u:
      v44 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v44 )
        goto LABEL_14;
      if ( *(_BYTE *)(v44 + 64) == 1 )
        goto LABEL_13;
      v45 = Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &v80, **(const char ***)(v44 + 24));
      Scaleform::GFx::AS2::Value::SetString(v4, v45);
      v46 = v80.pNode;
      v41 = v80.pNode->RefCount == 1;
      --v46->RefCount;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v46);
      return 1;
    case 0xAu:
      v62 = *(_QWORD *)&v7->ResolveHandler.Flags;
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
                                              &v76,
                                              v6,
                                              v63,
                                              (Scaleform::GFx::XML::RootNode *)v7->ResolveHandler.pLocalFrame);
      Scaleform::GFx::AS2::Value::SetAsObject(v4, *v65);
      v15 = v76.pObject;
      goto LABEL_9;
    case 0xBu:
      v72 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( !v72 || *(_BYTE *)(v72 + 64) != 1 )
        goto LABEL_14;
      v73 = Scaleform::GFx::AS2::ASStringContext::CreateString(v8, &v81, **(const char ***)(v72 + 72));
      Scaleform::GFx::AS2::Value::SetString(v4, v73);
      v74 = v81.pNode;
      v41 = v81.pNode->RefCount == 1;
      --v74->RefCount;
      if ( v41 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v74);
      break;
    case 0xCu:
      v58 = *(_QWORD *)&v7->ResolveHandler.Flags;
      if ( v58 )
      {
        v59 = *(Scaleform::GFx::XML::Node **)(v58 + 40);
        if ( v59 )
        {
          v60 = v59->pShadow;
          if ( v60 && (v13 = (Scaleform::GFx::AS2::Object *)v60[1].vfptr) != 0i64 )
          {
LABEL_66:
            Scaleform::GFx::AS2::Value::SetAsObject(v4, v13);
          }
          else
          {
            v61 = (Scaleform::GFx::AS2::Object **)Scaleform::GFx::AS2::CreateShadow(
                                                    &v82,
                                                    v6,
                                                    v59,
                                                    (Scaleform::GFx::XML::RootNode *)v7->ResolveHandler.pLocalFrame);
            Scaleform::GFx::AS2::Value::SetAsObject(v4, *v61);
            v15 = v82.pObject;
LABEL_9:
            if ( v15 )
            {
              v16 = v15->RefCount;
              if ( v16 & 0x3FFFFFF )
              {
                v15->RefCount = v16 - 1;
LABEL_12:
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v15->vfptr);
              }
            }
          }
        }
        else
        {
LABEL_13:
          Scaleform::GFx::AS2::Value::DropRefs(v4);
          v4->T.Type = 1;
        }
      }
      else
      {
LABEL_14:
        v17 = v4;
LABEL_15:
        Scaleform::GFx::AS2::Value::DropRefs(v17);
        v4->T.Type = 0;
      }
      break;
    default:
      return ((__int64 (__fastcall *)(Scaleform::GFx::AS2::XmlNodeObject *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v7->vfptr[3].~RefCountBaseGC<323>)(
               v7,
               v8,
               v5,
               v4);
  }
  return 1;
}

// File Line: 850
// RVA: 0x6CDCA0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::XmlNodeProto(Scaleform::GFx::AS2::XmlNodeProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *prototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  Scaleform::GFx::AS2::XmlNodeProto *v5; // rsi
  Scaleform::GFx::ASString *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
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
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h]
  __int64 v35; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::ASStringHash<char> *v36; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS2::Value val; // [rsp+50h] [rbp-20h]

  v35 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    prototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable';
  result.pNode = (Scaleform::GFx::ASStringNode *)&v5->XMLNodeMemberMap;
  v36 = &v5->XMLNodeMemberMap;
  v5->XMLNodeMemberMap.mHash.pTable = 0i64;
  flags.Flags = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::XmlNodeProto::FunctionTable,
    &flags);
  flags.Flags = 2;
  val.T.Type = 0;
  v6 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "attributes");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v6, &val, &flags);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "childNodes");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v9, &val, &flags);
  v10 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "firstChild");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v11, &val, &flags);
  v12 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "lastChild");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v13, &val, &flags);
  v14 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "localName");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v15, &val, &flags);
  v16 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "namespaceURI");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v17, &val, &flags);
  v18 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "nextSibling");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v19, &val, &flags);
  v20 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "nodeName");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v21, &val, &flags);
  v22 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v23 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "nodeType");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v23, &val, &flags);
  v24 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v24->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v24);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 2;
  val.T.Type = 0;
  v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "nodeValue");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v25, &val, &flags);
  v26 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v26->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v27 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "parentNode");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v27, &val, &flags);
  v28 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v28->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v29 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "prefix");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v29, &val, &flags);
  v30 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v30->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v30);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  flags.Flags = 6;
  val.T.Type = 0;
  v31 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "previousSibling");
  Scaleform::GFx::AS2::Object::SetMemberRaw((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v31, &val, &flags);
  v32 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v32->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v32);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 897
// RVA: 0x6A8EB0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::AppendChild(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  signed __int64 v7; // r14
  __int64 v8; // rax
  Scaleform::GFx::LogState *v9; // rbx
  Scaleform::GFx::XML::ElementNode *v10; // r15
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rax
  Scaleform::GFx::AS2::Object *v13; // rsi
  Scaleform::RefCountNTSImpl *v14; // rbp
  Scaleform::RefCountNTSImpl *v15; // rcx
  const char *v16; // r8
  Scaleform::GFx::LogState *v17; // rcx
  Scaleform::GFx::XML::Node *v18; // rdx
  Scaleform::GFx::XML::ElementNode *v19; // rcx
  __int64 v20; // rax
  Scaleform::RefCountNTSImpl *v21; // rcx
  Scaleform::GFx::XML::ElementNode *v22; // rdx
  Scaleform::RefCountNTSImpl *messageType; // [rsp+50h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( !v3 && !v5 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
    return;
  }
  v6 = v1->ThisPtr;
  if ( v6 )
  {
    v7 = (signed __int64)&v6[-2];
    if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
    {
      v8 = ((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v1->Env->Target->vfptr[76].__vecDelDtor)(v1->Env->Target);
      v9 = (Scaleform::GFx::LogState *)v8;
      v10 = *(Scaleform::GFx::XML::ElementNode **)(v7 + 104);
      if ( v10 )
      {
        if ( v10->Type != 1 )
        {
          if ( !v8 )
            return;
          v16 = "XMLNode::appendChild - trying to add a child to a text node";
          v17 = (Scaleform::GFx::LogState *)v8;
          goto LABEL_40;
        }
        if ( v1->NArgs <= 0 )
          return;
        v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v12 = Scaleform::GFx::AS2::Value::ToObject(v11, v1->Env);
        v13 = v12;
        if ( !v12
          || (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v12->vfptr->gap8[8])(&v12->vfptr) != 29 )
        {
          if ( !v9 )
            return;
          v16 = "XMLNode::appendChild - trying to add a child that is not of type XMLNode";
          v17 = v9;
          goto LABEL_40;
        }
        v14 = (Scaleform::RefCountNTSImpl *)v13[1].pRCC;
        if ( !v14 )
          return;
        v15 = *(Scaleform::RefCountNTSImpl **)(*(_QWORD *)(v7 + 104) + 32i64);
        if ( v15 )
        {
          while ( v15[2].vfptr )
            v15 = (Scaleform::RefCountNTSImpl *)v15[2].vfptr;
        }
        if ( v15 == v14 )
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
        ++v14->RefCount;
        messageType = v14;
        v18 = (Scaleform::GFx::XML::Node *)v13[1].pRCC;
        v19 = v18->Parent;
        if ( v19 )
          Scaleform::GFx::XML::ElementNode::RemoveChild(v19, v18);
        Scaleform::GFx::XML::ElementNode::AppendChild(v10, (Scaleform::GFx::XML::Node *)v13[1].pRCC);
        v20 = *(_QWORD *)(v7 + 96);
        if ( v20 )
          ++*(_DWORD *)(v20 + 8);
        v21 = (Scaleform::RefCountNTSImpl *)v13[1].vfptr;
        if ( v21 )
          Scaleform::RefCountNTSImpl::Release(v21);
        v13[1].vfptr = *(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)(v7 + 96);
        v22 = (Scaleform::GFx::XML::ElementNode *)v13[1].pRCC;
        if ( v22->Type == 1 && !v22->Namespace.pNode->Size )
          Scaleform::GFx::AS2::ResolveNamespace(v1->Env, v22, *(Scaleform::GFx::XML::RootNode **)(v7 + 96));
        Scaleform::RefCountNTSImpl::Release(v14);
      }
    }
  }
}

// File Line: 994
// RVA: 0x6A90C0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::CloneNode(Scaleform::GFx::AS2::FnCall *fn, _BOOL8 a2)
{
  Scaleform::GFx::AS2::FnCall *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  bool v4; // di
  Scaleform::GFx::AS2::ObjectInterface *v5; // rcx
  bool v6; // al
  Scaleform::GFx::AS2::ObjectInterface *v7; // rdi
  signed __int64 v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // rax
  _BYTE *v10; // rdi
  Scaleform::GFx::XML::Node *v11; // rdi
  Scaleform::GFx::AS2::XmlNodeObject *v12; // rcx
  unsigned int v13; // eax
  Scaleform::RefCountNTSImpl *v14; // rcx
  Scaleform::GFx::XML::Node *v15; // rsi
  Scaleform::GFx::AS2::XmlNodeObject *v16; // rcx
  unsigned int v17; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::XML::Node *v19; // [rsp+48h] [rbp+10h]

  v2 = fn;
  v3 = fn->ThisPtr;
  v4 = v3 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) == 29;
  v5 = v2->ThisPtr;
  v6 = v5 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v5->vfptr->gap8[8])(v5) == 28;
  if ( !v4 && !v6 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v2->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
    return;
  }
  v7 = v2->ThisPtr;
  if ( v7 )
  {
    v8 = (signed __int64)&v7[-2];
    if ( v8 )
    {
      if ( *(_QWORD *)(v8 + 104) )
      {
        LOBYTE(a2) = 0;
        if ( v2->NArgs > 0 )
        {
          v9 = Scaleform::GFx::AS2::FnCall::Arg(v2, 0);
          a2 = Scaleform::GFx::AS2::Value::ToBool(v9, v2->Env);
        }
        v10 = *(_BYTE **)(v8 + 104);
        if ( v10[64] != 1 )
        {
          v15 = (Scaleform::GFx::XML::Node *)(*(__int64 (__fastcall **)(_BYTE *, _BOOL8))(*(_QWORD *)v10 + 8i64))(
                                               v10,
                                               a2);
          v19 = v15;
          Scaleform::GFx::AS2::CreateShadow(&result, v2->Env, v15, 0i64);
          v15->Type = v10[64];
          Scaleform::GFx::AS2::Value::SetAsObject(v2->Result, (Scaleform::GFx::AS2::Object *)&result.pObject->vfptr);
          v16 = result.pObject;
          if ( result.pObject )
          {
            v17 = result.pObject->RefCount;
            if ( v17 & 0x3FFFFFF )
            {
              result.pObject->RefCount = v17 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v16->vfptr);
            }
          }
          v14 = (Scaleform::RefCountNTSImpl *)&v15->vfptr;
          goto LABEL_27;
        }
        v11 = (Scaleform::GFx::XML::Node *)(*(__int64 (__fastcall **)(_BYTE *, _BOOL8))(*(_QWORD *)v10 + 8i64))(v10, a2);
        v19 = v11;
        Scaleform::GFx::AS2::CreateShadow(&result, v2->Env, v11, 0i64);
        Scaleform::GFx::AS2::Value::SetAsObject(v2->Result, (Scaleform::GFx::AS2::Object *)&result.pObject->vfptr);
        v12 = result.pObject;
        if ( result.pObject )
        {
          v13 = result.pObject->RefCount;
          if ( v13 & 0x3FFFFFF )
          {
            result.pObject->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
          }
        }
        if ( v11 )
        {
          v14 = (Scaleform::RefCountNTSImpl *)&v11->vfptr;
LABEL_27:
          Scaleform::RefCountNTSImpl::Release(v14);
          return;
        }
      }
    }
  }
}

// File Line: 1046
// RVA: 0x6A9260
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::GetNamespaceForPrefix(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  signed __int64 v7; // rsi
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::LogState *v9; // rax
  Scaleform::GFx::XML::Node *v10; // rbx
  Scaleform::GFx::AS2::Value *v11; // rax
  const char *v12; // rdx
  unsigned __int64 v13; // r8
  signed __int64 v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int v17; // eax
  signed __int64 v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS2::Value v24; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::ASString v25; // [rsp+70h] [rbp+20h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+28h]
  Scaleform::GFx::ASString v27; // [rsp+80h] [rbp+30h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = v1->ThisPtr;
    if ( v6 )
    {
      v7 = (signed __int64)&v6[-2];
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        v8 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v8->T.Type = 1;
        v9 = (Scaleform::GFx::LogState *)((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))v1->Env->Target->vfptr[76].__vecDelDtor)(v1->Env->Target);
        v10 = *(Scaleform::GFx::XML::Node **)(v7 + 104);
        if ( v10 )
        {
          if ( v10->Type == 1 )
          {
            if ( v1->NArgs >= 1 )
            {
              v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
              Scaleform::GFx::AS2::Value::ToString(v11, &result, v1->Env, -1);
              Scaleform::GFx::AS2::ASStringContext::CreateString(&v1->Env->StringContext, &v25, "xmlns", 5ui64);
              if ( result.pNode->Size )
              {
                Scaleform::GFx::ASString::Append(&v25, ":", 1ui64);
                v12 = result.pNode->pData;
                v13 = -1i64;
                do
                  ++v13;
                while ( v12[v13] );
                Scaleform::GFx::ASString::Append(&v25, v12, v13);
              }
              v24.T.Type = 0;
              v14 = (signed __int64)&v10->pShadow[2].vfptr[4];
              (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))(*(_QWORD *)v14 + 32i64))(
                v14,
                v1->Env,
                &v25,
                &v24,
                -2i64);
              if ( v24.T.Type && v24.T.Type != 10 )
              {
                v15 = Scaleform::GFx::AS2::Value::ToString(&v24, &v27, v1->Env, -1);
                Scaleform::GFx::AS2::Value::SetString(v1->Result, v15);
LABEL_32:
                v20 = v27.pNode;
                v21 = v27.pNode->RefCount == 1;
                --v20->RefCount;
                if ( v21 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v20);
              }
              else
              {
                while ( 1 )
                {
                  v10 = (Scaleform::GFx::XML::Node *)&v10->Parent->vfptr;
                  if ( !v10 )
                    break;
                  if ( !v10->pShadow )
                  {
                    Scaleform::GFx::AS2::CreateShadow(
                      (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&v27,
                      v1->Env,
                      v10,
                      *(Scaleform::GFx::XML::RootNode **)(v7 + 96));
                    v16 = v27.pNode;
                    if ( v27.pNode )
                    {
                      v17 = v27.pNode->RefCount;
                      if ( v17 & 0x3FFFFFF )
                      {
                        v27.pNode->RefCount = v17 - 1;
                        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v16);
                      }
                    }
                  }
                  v18 = (signed __int64)&v10->pShadow[2].vfptr[4];
                  (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v18 + 32i64))(
                    v18,
                    v1->Env,
                    &v25,
                    &v24);
                  if ( v24.T.Type && v24.T.Type != 10 )
                  {
                    v19 = Scaleform::GFx::AS2::Value::ToString(&v24, &v27, v1->Env, -1);
                    Scaleform::GFx::AS2::Value::SetString(v1->Result, v19);
                    goto LABEL_32;
                  }
                }
              }
              if ( v24.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v24);
              v22 = v25.pNode;
              v21 = v25.pNode->RefCount == 1;
              --v22->RefCount;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v22);
              v23 = result.pNode;
              v21 = result.pNode->RefCount == 1;
              --v23->RefCount;
              if ( v21 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v23);
            }
          }
          else if ( v9 )
          {
            LODWORD(v25.pNode) = 147456;
            Scaleform::Log::LogMessageById(
              v9,
              (Scaleform::LogMessageId)&v25,
              "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1151
// RVA: 0x723B70
void __fastcall Scaleform::GFx::AS2::XMLPrefixQuerier::Visit(Scaleform::GFx::AS2::XMLPrefixQuerier *this, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, char flags)
{
  const char ***v4; // rdi
  Scaleform::GFx::AS2::XMLPrefixQuerier *v5; // rbx
  Scaleform::GFx::AS2::Value *v6; // rbx
  const char **v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v4 = (const char ***)name;
  v5 = this;
  Scaleform::GFx::AS2::Value::ToString(val, &result, this->pEnv, -1);
  if ( result.pNode == v5->pKey->pNode && !strncmp(**v4, "xmlns", 5ui64) )
  {
    v6 = v5->pVal;
    if ( v6->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 5;
    v7 = *v4;
    v6->V.pStringNode = (Scaleform::GFx::ASStringNode *)*v4;
    ++*((_DWORD *)v7 + 6);
  }
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
}

// File Line: 1166
// RVA: 0x6A97D0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::GetPrefixForNamespace(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  signed __int64 v7; // r15
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::AS2::Environment *v9; // rcx
  Scaleform::GFx::AS2::ASStringContext *v10; // r12
  Scaleform::GFx::LogState *v11; // rax
  __int64 v12; // rbx
  Scaleform::GFx::AS2::Value *v13; // rax
  __int64 v14; // rax
  signed __int64 v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::XML::Node *i; // rbx
  Scaleform::GFx::ASStringNode *v20; // rcx
  unsigned int v21; // eax
  signed __int64 v22; // rcx
  Scaleform::GFx::ASString *v23; // r14
  Scaleform::GFx::AS2::Value *v24; // rsi
  Scaleform::GFx::ASStringNode *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  Scaleform::GFx::AS2::Value *v27; // rcx
  const char *v28; // rbx
  char *v29; // rax
  unsigned int v30; // er9
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASStringNode *v34; // rcx
  void **v35; // [rsp+38h] [rbp-48h]
  __int64 v36; // [rsp+40h] [rbp-40h]
  Scaleform::GFx::ASString *v37; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value *v38; // [rsp+50h] [rbp-30h]
  Scaleform::GFx::AS2::Value v39; // [rsp+58h] [rbp-28h]
  Scaleform::GFx::ASString v40; // [rsp+C0h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+48h]
  Scaleform::GFx::ASString v42; // [rsp+D0h] [rbp+50h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (**)(void))&v4->vfptr->gap8[8])() == 28;
  if ( v3 || v5 )
  {
    v6 = v1->ThisPtr;
    if ( v6 )
    {
      v7 = (signed __int64)&v6[-2];
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        v8 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v8->T.Type = 1;
        v9 = v1->Env;
        v10 = &v9->StringContext;
        v11 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v9->Target->vfptr[76].__vecDelDtor)();
        v12 = *(_QWORD *)(v7 + 104);
        if ( v12 )
        {
          if ( *(_BYTE *)(v12 + 64) == 1 )
          {
            if ( v1->NArgs >= 1 )
            {
              v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
              Scaleform::GFx::AS2::Value::ToString(v13, &result, v1->Env, -1);
              v39.T.Type = 0;
              v14 = (__int64)v1->Env;
              v35 = &Scaleform::GFx::AS2::XMLPrefixQuerier::`vftable';
              v36 = v14;
              v37 = &result;
              v38 = &v39;
              v15 = *(_QWORD *)(*(_QWORD *)(v12 + 56) + 16i64) + 32i64;
              (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, void ***, _QWORD, _QWORD))(*(_QWORD *)v15 + 64i64))(
                v15,
                v10,
                &v35,
                0i64,
                0i64);
              if ( v39.T.Type )
              {
                if ( v39.T.Type != 10 )
                {
                  v16 = Scaleform::GFx::AS2::Value::ToString(&v39, &v40, v1->Env, -1);
                  Scaleform::GFx::AS2::Value::SetString(v1->Result, v16);
                  v17 = v40.pNode;
                  v18 = v40.pNode->RefCount == 1;
                  --v17->RefCount;
                  if ( v18 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
                }
              }
              for ( i = *(Scaleform::GFx::XML::Node **)(v12 + 32);
                    v1->Result->T.Type == 1;
                    i = (Scaleform::GFx::XML::Node *)&i->Parent->vfptr )
              {
                if ( !i )
                  break;
                if ( !i->pShadow )
                {
                  Scaleform::GFx::AS2::CreateShadow(
                    (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *)&v40,
                    v1->Env,
                    i,
                    *(Scaleform::GFx::XML::RootNode **)(v7 + 96));
                  v20 = v40.pNode;
                  if ( v40.pNode )
                  {
                    v21 = v40.pNode->RefCount;
                    if ( v21 & 0x3FFFFFF )
                    {
                      v40.pNode->RefCount = v21 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v20);
                    }
                  }
                }
                v22 = (signed __int64)&i->pShadow[2].vfptr[4];
                (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, void ***, _QWORD, _QWORD))(*(_QWORD *)v22 + 64i64))(
                  v22,
                  v10,
                  &v35,
                  0i64,
                  0i64);
                if ( v39.T.Type && v39.T.Type != 10 )
                {
                  v23 = Scaleform::GFx::AS2::Value::ToString(&v39, &v42, v1->Env, -1);
                  v24 = v1->Result;
                  if ( v24->T.Type >= 5u )
                    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
                  v24->T.Type = 5;
                  v25 = v23->pNode;
                  v24->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v23->pNode;
                  ++v25->RefCount;
                  v26 = v42.pNode;
                  v18 = v42.pNode->RefCount == 1;
                  --v26->RefCount;
                  if ( v18 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v26);
                }
              }
              v27 = v1->Result;
              if ( v27->T.Type != 1 )
              {
                Scaleform::GFx::AS2::Value::ToString(v27, &v40, v1->Env, -1);
                v28 = v40.pNode->pData;
                v29 = strchr(v40.pNode->pData, 58);
                v30 = v40.pNode->Size;
                if ( v29 )
                  v31 = Scaleform::GFx::AS2::ASStringContext::CreateString(v10, &v42, v28 + 6, v30 - 6);
                else
                  v31 = Scaleform::GFx::AS2::ASStringContext::CreateString(v10, &v42, v28 + 5, v30 - 5);
                Scaleform::GFx::AS2::Value::SetString(v1->Result, v31);
                v32 = v42.pNode;
                v18 = v42.pNode->RefCount == 1;
                --v32->RefCount;
                if ( v18 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v32);
                v33 = v40.pNode;
                v18 = v40.pNode->RefCount == 1;
                --v33->RefCount;
                if ( v18 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v33);
              }
              v35 = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
              if ( v39.T.Type >= 5u )
                Scaleform::GFx::AS2::Value::DropRefs(&v39);
              v34 = result.pNode;
              v18 = result.pNode->RefCount == 1;
              --v34->RefCount;
              if ( v18 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v34);
            }
          }
          else if ( v11 )
          {
            LODWORD(v40.pNode) = 147456;
            Scaleform::Log::LogMessageById(
              v11,
              (Scaleform::LogMessageId)&v40,
              "XMLNodeProto::GetNamespaceForPrefix - only element nodes support this method.");
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1263
// RVA: 0x6A9D10
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::HasChildNodes(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  signed __int64 v7; // rdi
  Scaleform::GFx::AS2::Value *v8; // rbx
  Scaleform::GFx::XML::ElementNode *v9; // rcx
  bool v10; // al
  Scaleform::GFx::AS2::Value *v11; // rbx
  bool v12; // di

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (**)(void))&v4->vfptr->gap8[8])() == 28;
  if ( v3 || v5 )
  {
    v6 = v1->ThisPtr;
    if ( v6 )
    {
      v7 = (signed __int64)&v6[-2];
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        v8 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
        v8->T.Type = 2;
        v8->V.BooleanValue = 0;
        v9 = *(Scaleform::GFx::XML::ElementNode **)(v7 + 104);
        if ( v9 )
        {
          if ( v9->Type == 1 )
          {
            v10 = Scaleform::GFx::XML::ElementNode::HasChildren(v9);
            v11 = v1->Result;
            v12 = v10;
            Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
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
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1286
// RVA: 0x6A9DE0
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::InsertBefore(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // bl
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rsi
  signed __int64 v7; // rsi
  Scaleform::GFx::XML::ElementNode *v8; // rbp
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // r14
  Scaleform::GFx::AS2::RefCountCollector<323> *v13; // rax
  Scaleform::GFx::XML::ElementNode *v14; // rax
  Scaleform::RefCountNTSImpl *v15; // rdi
  Scaleform::GFx::XML::Node *v16; // rdx
  Scaleform::GFx::XML::ElementNode *v17; // rcx
  __int64 v18; // rax
  Scaleform::RefCountNTSImpl *v19; // rcx
  Scaleform::GFx::XML::Node *v20; // rdx
  Scaleform::GFx::XML::ElementNode *v21; // rcx
  __int64 v22; // rax
  Scaleform::RefCountNTSImpl *v23; // rcx

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( !v3 && !v5 )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
    return;
  }
  v6 = v1->ThisPtr;
  if ( v6 )
  {
    v7 = (signed __int64)&v6[-2];
    if ( v7 )
    {
      v8 = *(Scaleform::GFx::XML::ElementNode **)(v7 + 104);
      if ( v8 )
      {
        if ( v8->Type == 1 && v1->NArgs > 1 )
        {
          v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
          v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v1->Env);
          v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
          v12 = Scaleform::GFx::AS2::Value::ToObject(v11, v1->Env);
          if ( v10 )
          {
            if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v10->vfptr->gap8[8])(&v10->vfptr) == 29 )
            {
              if ( v12
                && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v12->vfptr->gap8[8])(&v12->vfptr) == 29
                && (v13 = v12[1].pRCC) != 0i64
                && (v14 = (Scaleform::GFx::XML::ElementNode *)v13->Roots.NumPages) != 0i64
                && v14 == v8 )
              {
                v15 = (Scaleform::RefCountNTSImpl *)v10[1].pRCC;
                if ( !v15 )
                  return;
                ++v15->RefCount;
                v16 = (Scaleform::GFx::XML::Node *)v10[1].pRCC;
                v17 = v16->Parent;
                if ( v17 )
                  Scaleform::GFx::XML::ElementNode::RemoveChild(v17, v16);
                Scaleform::GFx::XML::ElementNode::InsertBefore(
                  v8,
                  (Scaleform::GFx::XML::Node *)v10[1].pRCC,
                  (Scaleform::GFx::XML::Node *)v12[1].pRCC);
                v18 = *(_QWORD *)(v7 + 96);
                if ( v18 )
                  ++*(_DWORD *)(v18 + 8);
                v19 = (Scaleform::RefCountNTSImpl *)v10[1].vfptr;
                if ( v19 )
                  Scaleform::RefCountNTSImpl::Release(v19);
                v10[1].vfptr = *(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)(v7 + 96);
              }
              else
              {
                v15 = (Scaleform::RefCountNTSImpl *)v10[1].pRCC;
                if ( !v15 )
                  return;
                ++v15->RefCount;
                v20 = (Scaleform::GFx::XML::Node *)v10[1].pRCC;
                v21 = v20->Parent;
                if ( v21 )
                  Scaleform::GFx::XML::ElementNode::RemoveChild(v21, v20);
                Scaleform::GFx::XML::ElementNode::AppendChild(v8, (Scaleform::GFx::XML::Node *)v10[1].pRCC);
                v22 = *(_QWORD *)(v7 + 96);
                if ( v22 )
                  ++*(_DWORD *)(v22 + 8);
                v23 = (Scaleform::RefCountNTSImpl *)v10[1].vfptr;
                if ( v23 )
                  Scaleform::RefCountNTSImpl::Release(v23);
                v10[1].vfptr = *(Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl **)(v7 + 96);
              }
              Scaleform::RefCountNTSImpl::Release(v15);
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // di
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  signed __int64 v7; // rbx
  Scaleform::GFx::XML::Node *v8; // rdx
  Scaleform::GFx::XML::ElementNode *v9; // rdi
  Scaleform::GFx::XML::RootNode *v10; // rax
  Scaleform::RefCountNTSImpl *v11; // rcx
  Scaleform::GFx::XML::RootNode *v12; // rsi

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (**)(void))&v4->vfptr->gap8[8])() == 28;
  if ( v3 || v5 )
  {
    v6 = v1->ThisPtr;
    if ( v6 )
    {
      v7 = (signed __int64)&v6[-2];
      if ( v7 )
      {
        v8 = *(Scaleform::GFx::XML::Node **)(v7 + 104);
        if ( v8 )
        {
          v9 = v8->Parent;
          if ( v9 )
          {
            v10 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v9->MemoryManager.pObject, v8);
            v11 = *(Scaleform::RefCountNTSImpl **)(v7 + 96);
            v12 = v10;
            if ( v11 )
              Scaleform::RefCountNTSImpl::Release(v11);
            *(_QWORD *)(v7 + 96) = v12;
            Scaleform::GFx::XML::ElementNode::RemoveChild(v9, *(Scaleform::GFx::XML::Node **)(v7 + 104));
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1394
// RVA: 0x723AB0
void __fastcall Scaleform::GFx::AS2::XMLAttributeStringBuilder::Visit(Scaleform::GFx::AS2::XMLAttributeStringBuilder *this, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val, char flags)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  const char ***v5; // rbx
  Scaleform::GFx::AS2::XMLAttributeStringBuilder *v6; // rsi
  const char ***v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v4 = val;
  v5 = (const char ***)name;
  v6 = this;
  Scaleform::StringBuffer::AppendString(this->Dest, " ", -1i64);
  Scaleform::StringBuffer::AppendString(v6->Dest, **v5, -1i64);
  Scaleform::StringBuffer::AppendString(v6->Dest, "=\"", -1i64);
  v7 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v4, &result, v6->pEnv, -1);
  Scaleform::StringBuffer::AppendString(v6->Dest, **v7, -1i64);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  Scaleform::StringBuffer::AppendString(v6->Dest, "\"", -1i64);
}

// File Line: 1409
// RVA: 0x6DBDB0
void __fastcall Scaleform::GFx::AS2::BuildXMLString(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::XML::Node *proot, Scaleform::StringBuffer *dest)
{
  Scaleform::StringBuffer *v3; // rdi
  Scaleform::GFx::XML::Node *v4; // rbp
  Scaleform::GFx::AS2::Environment *v5; // rsi
  const char *v6; // rdx
  Scaleform::GFx::XML::ShadowRefBase *v7; // rbx
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v8; // rcx
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v9; // rbx
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  const char ***v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::XML::Node *i; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v18; // rdx
  Scaleform::GFx::XML::ShadowRefBaseVtbl *v19; // rcx
  Scaleform::GFx::XML::ObjectManager *j; // rbx
  bool v21; // al
  const char *v22; // rdx
  Scaleform::GFx::XML::Node *k; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v24; // rdx
  Scaleform::GFx::ASString v25; // [rsp+30h] [rbp-68h]
  __int64 v26; // [rsp+38h] [rbp-60h]
  Scaleform::GFx::AS2::Value v27; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS2::Value v28; // [rsp+60h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::ASString v30; // [rsp+B8h] [rbp+20h]

  v26 = -2i64;
  v3 = dest;
  v4 = proot;
  v5 = penv;
  if ( proot->Type != 1 )
  {
    v6 = proot->Value.pNode->pData;
LABEL_39:
    Scaleform::StringBuffer::AppendString(v3, v6, -1i64);
    return;
  }
  v7 = proot->pShadow;
  if ( v7 && (v8 = v7[1].vfptr) != 0i64 && (*((unsigned int (**)(void))v8[4].__vecDelDtor + 2))() == 28 )
  {
    v9 = v7[1].vfptr;
    v27.T.Type = 0;
    v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v5->StringContext, &result, "xmlDecl");
    (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v9[4].__vecDelDtor
     + 4))(
      v9 + 4,
      v5,
      v10,
      &v27);
    v11 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( v27.T.Type && v27.T.Type != 10 )
    {
      v13 = (const char ***)Scaleform::GFx::AS2::Value::ToString(&v27, &v30, v5, -1);
      Scaleform::StringBuffer::AppendString(v3, **v13, -1i64);
      v14 = v30.pNode;
      v12 = v30.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v28.T.Type = 0;
      v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v5->StringContext, &v25, "ignoreWhite");
      (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v9[4].__vecDelDtor
       + 4))(
        v9 + 4,
        v5,
        v15,
        &v28);
      v16 = v25.pNode;
      v12 = v25.pNode->RefCount == 1;
      --v16->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      if ( !Scaleform::GFx::AS2::Value::ToBool(&v28, v5) )
        Scaleform::StringBuffer::AppendString(v3, "\n", -1i64);
      if ( v28.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v28);
    }
    for ( i = (Scaleform::GFx::XML::Node *)&v4[1].Parent->vfptr; i; i = i->NextSibling.pObject )
      Scaleform::GFx::AS2::BuildXMLString(v5, i, v3);
    if ( v27.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v27);
  }
  else
  {
    Scaleform::StringBuffer::AppendString(v3, "<", -1i64);
    v18 = v4[1].vfptr;
    if ( HIDWORD(v18[2].__vecDelDtor) )
    {
      Scaleform::StringBuffer::AppendString(v3, (const char *)v18->__vecDelDtor, -1i64);
      Scaleform::StringBuffer::AppendString(v3, ":", -1i64);
    }
    Scaleform::StringBuffer::AppendString(v3, v4->Value.pNode->pData, -1i64);
    if ( v7 && v7[2].vfptr )
    {
      *(_QWORD *)&v27.T.Type = &Scaleform::GFx::AS2::XMLAttributeStringBuilder::`vftable';
      v27.V.pStringNode = (Scaleform::GFx::ASStringNode *)v5;
      v27.V.FunctionValue.pLocalFrame = (Scaleform::GFx::AS2::LocalFrame *)v3;
      v19 = v7[2].vfptr;
      if ( v19 )
        (*((void (__fastcall **)(Scaleform::GFx::XML::ShadowRefBaseVtbl *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Value *, _QWORD, _QWORD))v19[4].__vecDelDtor
         + 8))(
          v19 + 4,
          &v5->StringContext,
          &v27,
          0i64,
          0i64);
      *(_QWORD *)&v27.T.Type = &Scaleform::GFx::AS2::ObjectInterface::MemberVisitor::`vftable';
    }
    else
    {
      for ( j = v4[1].MemoryManager.pObject; j; j = (Scaleform::GFx::XML::ObjectManager *)j->vfptr )
      {
        Scaleform::StringBuffer::AppendString(v3, " ", -1i64);
        Scaleform::StringBuffer::AppendString(v3, (const char *)j->vfptr->__vecDelDtor, -1i64);
        Scaleform::StringBuffer::AppendString(v3, "=\"", -1i64);
        Scaleform::StringBuffer::AppendString(v3, **(const char ***)&j->RefCount, -1i64);
        Scaleform::StringBuffer::AppendString(v3, "\"", -1i64);
      }
    }
    v21 = Scaleform::GFx::XML::ElementNode::HasChildren((Scaleform::GFx::XML::ElementNode *)v4);
    v22 = ">";
    if ( !v21 )
      v22 = " />";
    Scaleform::StringBuffer::AppendString(v3, v22, -1i64);
    for ( k = (Scaleform::GFx::XML::Node *)&v4[1].Parent->vfptr; k; k = k->NextSibling.pObject )
      Scaleform::GFx::AS2::BuildXMLString(v5, k, v3);
    if ( Scaleform::GFx::XML::ElementNode::HasChildren((Scaleform::GFx::XML::ElementNode *)v4) )
    {
      Scaleform::StringBuffer::AppendString(v3, "</", -1i64);
      v24 = v4[1].vfptr;
      if ( HIDWORD(v24[2].__vecDelDtor) )
      {
        Scaleform::StringBuffer::AppendString(v3, (const char *)v24->__vecDelDtor, -1i64);
        Scaleform::StringBuffer::AppendString(v3, ":", -1i64);
      }
      Scaleform::StringBuffer::AppendString(v3, v4->Value.pNode->pData, -1i64);
      v6 = ">";
      goto LABEL_39;
    }
  }
}

// File Line: 1513
// RVA: 0x6AA170
void __fastcall Scaleform::GFx::AS2::XmlNodeProto::ToString(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  bool v3; // di
  Scaleform::GFx::AS2::ObjectInterface *v4; // rcx
  bool v5; // al
  Scaleform::GFx::AS2::ObjectInterface *v6; // rax
  signed __int64 v7; // rdi
  __int64 v8; // rax
  char *v9; // r8
  Scaleform::GFx::ASString *v10; // rdi
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::AS2::Value *v15; // rbx
  Scaleform::StringBuffer dest; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  v3 = v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 29;
  v4 = v1->ThisPtr;
  v5 = v4 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) == 28;
  if ( v3 || v5 )
  {
    v6 = v1->ThisPtr;
    if ( v6 )
    {
      v7 = (signed __int64)&v6[-2];
      if ( v6 != (Scaleform::GFx::AS2::ObjectInterface *)32 )
      {
        Scaleform::StringBuffer::StringBuffer(&dest, Scaleform::Memory::pGlobalHeap);
        v8 = *(_QWORD *)(v7 + 104);
        if ( v8 )
        {
          if ( *(_BYTE *)(v8 + 64) == 1 )
            Scaleform::GFx::AS2::BuildXMLString(v1->Env, *(Scaleform::GFx::XML::Node **)(v7 + 104), &dest);
          else
            Scaleform::StringBuffer::AppendString(&dest, **(const char ***)(v8 + 24), -1i64);
          v9 = &customWorldMapCaption;
          if ( dest.pData )
            v9 = dest.pData;
          v10 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &result, v9, dest.Size);
          v11 = v1->Result;
          if ( v11->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v11);
          v11->T.Type = 5;
          v12 = v10->pNode;
          v11->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v10->pNode;
          ++v12->RefCount;
          v13 = result.pNode;
          v14 = result.pNode->RefCount == 1;
          --v13->RefCount;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        }
        else
        {
          v15 = v1->Result;
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
      v1->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "XMLNode");
  }
}

// File Line: 1561
// RVA: 0x6FAA50
void __fastcall Scaleform::GFx::AS2::XmlNodeCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  signed __int64 v2; // r14
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::AS2::XmlNodeObject *v7; // rax
  Scaleform::GFx::LogState *v8; // rdi
  char v9; // r12
  char v10; // r13
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::AS2::Value *v13; // rdx
  unsigned int v14; // edx
  Scaleform::GFx::AS2::Environment *v15; // r9
  Scaleform::GFx::AS2::Value *v16; // r8
  __int64 v17; // rcx
  double v18; // xmm0_8
  Scaleform::GFx::MovieImpl *v19; // r15
  Scaleform::GFx::ExternalLibPtr *v20; // rdi
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
  Scaleform::GFx::XML::TextNode *v31; // r14
  Scaleform::GFx::XML::RootNode *v32; // r15
  Scaleform::RefCountNTSImpl *v33; // rcx
  Scaleform::GFx::XML::DOMString *v34; // rax
  Scaleform::GFx::XML::DOMString v35; // rax
  Scaleform::GFx::XML::RootNode *v36; // r15
  Scaleform::RefCountNTSImpl *v37; // rcx
  Scaleform::GFx::XML::DOMString v38; // rax
  Scaleform::GFx::XML::RootNode *v39; // r15
  Scaleform::RefCountNTSImpl *v40; // rcx
  Scaleform::GFx::ASStringNode *v41; // rcx
  bool v42; // zf
  const char *v43; // r8
  unsigned int v44; // eax
  Scaleform::GFx::XML::DOMString v45; // [rsp+20h] [rbp-69h]
  Scaleform::GFx::XML::DOMString *v46; // [rsp+28h] [rbp-61h]
  Scaleform::GFx::XML::DOMString *v47; // [rsp+30h] [rbp-59h]
  Scaleform::GFx::XML::ObjectManager *v48; // [rsp+38h] [rbp-51h]
  Scaleform::GFx::AS2::Value v49; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::AS2::Value v50; // [rsp+60h] [rbp-29h]
  __int64 v51; // [rsp+80h] [rbp-9h]
  Scaleform::GFx::XML::DOMString result; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::ASString v53; // [rsp+F8h] [rbp+6Fh]
  Scaleform::GFx::XML::DOMString v54; // [rsp+100h] [rbp+77h]
  Scaleform::GFx::AS2::XmlNodeObject *v55; // [rsp+108h] [rbp+7Fh]

  v51 = -2i64;
  v1 = fn;
  v2 = 0i64;
  v55 = 0i64;
  v3 = fn->ThisPtr;
  if ( v3
    && ((*(unsigned int (**)(void))&v3->vfptr->gap8[8])() == 29
     || (*(unsigned int (**)(void))&v1->ThisPtr->vfptr->gap8[8])() == 28) )
  {
    v4 = v1->ThisPtr;
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
    result.pNode = (Scaleform::GFx::XML::DOMStringNode *)v1->Env->StringContext.pContext->pHeap;
    v6 = (Scaleform::GFx::ASStringNode *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *, signed __int64))result.pNode->pData
                                          + 10))(
                                           v3,
                                           112i64);
    v53.pNode = v6;
    if ( v6 )
    {
      Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject((Scaleform::GFx::AS2::XmlNodeObject *)v6, v1->Env);
      v5 = v7;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v55 = v5;
  v8 = (Scaleform::GFx::LogState *)((__int64 (*)(void))v1->Env->Target->vfptr[76].__vecDelDtor)();
  v9 = 0;
  v49.T.Type = 0;
  v10 = 0;
  v50.T.Type = 0;
  if ( v1->NArgs <= 0 )
    goto LABEL_68;
  v11 = v1->FirstArgBottomIndex;
  v12 = v1->Env;
  v13 = 0i64;
  if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
            + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
    v13 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
  Scaleform::GFx::AS2::Value::operator=(&v49, v13, (__int64)v8);
  if ( v1->NArgs > 1 )
  {
    v14 = v1->FirstArgBottomIndex - 1;
    v15 = v1->Env;
    v16 = 0i64;
    if ( v14 <= 32 * ((unsigned int)v15->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v15->Stack.pCurrent - (char *)v15->Stack.pPageStart) >> 5) )
      v16 = &v15->Stack.Pages.Data.Data[v14 >> 5]->Values[v14 & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&v50, v16, (__int64)v8);
    v10 = v50.T.Type;
  }
  v9 = v49.T.Type;
  if ( !v49.T.Type || v49.T.Type == 10 )
  {
LABEL_68:
    if ( !v8 )
      goto LABEL_59;
    v43 = "XMLNodeCtorFunction::GlobalCtor - node type not specified";
    goto LABEL_58;
  }
  v18 = Scaleform::GFx::AS2::Value::ToNumber(&v49, v1->Env);
  if ( !v10 || v10 == 10 )
  {
    if ( !v8 )
      goto LABEL_59;
    v43 = "XMLNodeCtorFunction::GlobalCtor - malformed XMLNode object";
LABEL_58:
    LODWORD(result.pNode) = 147456;
    Scaleform::Log::LogMessageById(v8, (Scaleform::LogMessageId)&result, v43);
    goto LABEL_59;
  }
  v19 = v1->Env->Target->pASRoot->pMovieImpl;
  v48 = 0i64;
  v20 = v19->pXMLObjectManager;
  if ( v20 )
  {
    v23 = (Scaleform::GFx::XML::ObjectManager *)&v20[-1];
    if ( v23 )
      ++v23->RefCount;
    v48 = v23;
  }
  else
  {
    v45.pNode = (Scaleform::GFx::XML::DOMStringNode *)v1->Env->StringContext.pContext->pHeap;
    v21 = (Scaleform::GFx::XML::ObjectManager *)(*((__int64 (__fastcall **)(__int64, signed __int64, _QWORD))v45.pNode->pData
                                                 + 10))(
                                                  v17,
                                                  120i64,
                                                  0i64);
    v46 = (Scaleform::GFx::XML::DOMString *)v21;
    if ( v21 )
    {
      Scaleform::GFx::XML::ObjectManager::ObjectManager(v21, v19);
      v23 = v22;
    }
    else
    {
      v23 = 0i64;
    }
    v48 = v23;
    if ( v23 )
      v2 = (signed __int64)&v23->vfptr;
    v19->pXMLObjectManager = (Scaleform::GFx::ExternalLibPtr *)v2;
  }
  Scaleform::GFx::XML::ObjectManager::EmptyString(v23, &result);
  Scaleform::GFx::XML::ObjectManager::EmptyString(v23, &v54);
  v24 = -1i64;
  Scaleform::GFx::AS2::Value::ToString(&v50, &v53, v1->Env, -1);
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
    v31 = (Scaleform::GFx::XML::TextNode *)Scaleform::GFx::XML::ObjectManager::CreateElementNode(v23, v30);
    v47 = (Scaleform::GFx::XML::DOMString *)v31;
    v5->pRealNode = (Scaleform::GFx::XML::Node *)&v31->vfptr;
    v32 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v23, (Scaleform::GFx::XML::Node *)&v31->vfptr);
    v33 = (Scaleform::RefCountNTSImpl *)&v5->pRootNode.pObject->vfptr;
    if ( v33 )
      Scaleform::RefCountNTSImpl::Release(v33);
    v5->pRootNode.pObject = v32;
    Scaleform::GFx::XML::DOMString::AssignNode((Scaleform::GFx::XML::DOMString *)&v5->pRealNode[1], v54.pNode);
  }
  else if ( v18 == 3.0 )
  {
    v34 = Scaleform::GFx::XML::ObjectManager::CreateString(v23, &v45, v53.pNode->pData, v53.pNode->Size);
    Scaleform::GFx::XML::DOMString::AssignNode(&result, v34->pNode);
    Scaleform::GFx::XML::DOMString::~DOMString(&v45);
    v47 = &v45;
    Scaleform::GFx::XML::DOMString::DOMString(&v45, &result);
    v31 = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v23, v35);
    v46 = (Scaleform::GFx::XML::DOMString *)v31;
    v5->pRealNode = (Scaleform::GFx::XML::Node *)&v31->vfptr;
    v36 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v23, (Scaleform::GFx::XML::Node *)&v31->vfptr);
    v37 = (Scaleform::RefCountNTSImpl *)&v5->pRootNode.pObject->vfptr;
    if ( v37 )
      Scaleform::RefCountNTSImpl::Release(v37);
    v5->pRootNode.pObject = v36;
  }
  else
  {
    v47 = &v45;
    Scaleform::GFx::XML::DOMString::DOMString(&v45, &result);
    v31 = Scaleform::GFx::XML::ObjectManager::CreateTextNode(v23, v38);
    v46 = (Scaleform::GFx::XML::DOMString *)v31;
    v5->pRealNode = (Scaleform::GFx::XML::Node *)&v31->vfptr;
    v39 = Scaleform::GFx::XML::ObjectManager::CreateRootNode(v23, (Scaleform::GFx::XML::Node *)&v31->vfptr);
    v40 = (Scaleform::RefCountNTSImpl *)&v5->pRootNode.pObject->vfptr;
    if ( v40 )
      Scaleform::RefCountNTSImpl::Release(v40);
    v5->pRootNode.pObject = v39;
    v5->pRealNode->Type = (signed int)v18;
  }
  if ( v31 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v31->vfptr);
  Scaleform::GFx::AS2::SetupShadow(v1->Env, v5->pRealNode, v5);
  v41 = v53.pNode;
  v42 = v53.pNode->RefCount == 1;
  --v41->RefCount;
  if ( v42 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  Scaleform::GFx::XML::DOMString::~DOMString(&v54);
  Scaleform::GFx::XML::DOMString::~DOMString(&result);
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v23->vfptr);
LABEL_59:
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v5->vfptr);
  if ( (unsigned __int8)v10 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v50);
  if ( (unsigned __int8)v9 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v49);
  if ( v5 )
  {
    v44 = v5->RefCount;
    if ( v44 & 0x3FFFFFF )
    {
      v5->RefCount = v44 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v5->vfptr);
    }
  }
}

// File Line: 1671
// RVA: 0x6E09B0
void __fastcall Scaleform::GFx::AS2::XmlNodeCtorFunction::CreateNewObject(Scaleform::GFx::AS2::XmlNodeCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::XmlNodeObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::XmlNodeObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::XmlNodeCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               this,
                                               112i64);
  if ( v3 )
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v3, v2);
}

// File Line: 1677
// RVA: 0x70F9B0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::XmlNodeCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  Scaleform::GFx::AS2::XmlNodeProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  __int64 v11; // rax
  __int64 v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // r14
  Scaleform::GFx::ASStringNode *v14; // rax
  Scaleform::GFx::AS2::LocalFrame *v15; // rdx
  int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-38h]
  Scaleform::GFx::AS2::Value v19; // [rsp+50h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+B8h] [rbp+40h]
  Scaleform::MemoryHeap *v21; // [rsp+C0h] [rbp+48h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v22; // [rsp+C8h] [rbp+50h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  v21 = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))v21->vfptr->Alloc)(
                                        result,
                                        104i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  v22 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::XmlNodeCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->pProto.pObject->vfptr;
    if ( v5 )
    {
      v8 = v5->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v5->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v6->pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::XmlNodeCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v9 = (Scaleform::GFx::AS2::XmlNodeProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                              v5,
                                              184i64,
                                              0i64);
  v21 = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::XmlNodeProto::XmlNodeProto(v9, &psc, v10, v3);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v21 = (Scaleform::MemoryHeap *)v12;
  v22 = &objproto;
  if ( v12 )
    *(_DWORD *)(v12 + 24) = (*(_DWORD *)(v12 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_XMLNode,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = v2->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  v14 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v19.V.pStringNode = v14;
  if ( v14 )
  {
    ++v14->RefCount;
    v14->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  v15 = v3->pLocalFrame;
  if ( v15 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v19.NV.8,
      v15,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v13->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[12].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  Scaleform::GFx::AS2::XmlNodeObject::InitializeStandardMembers(v2, (Scaleform::GFx::ASStringHash<char> *)(v12 + 176));
  if ( v12 )
  {
    v16 = *(_DWORD *)(v12 + 24);
    if ( v16 & 0x3FFFFFF )
    {
      *(_DWORD *)(v12 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12);
    }
  }
  return v3;
}

