// File Line: 18
// RVA: 0x6C7620
void __fastcall Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::InteractiveObject *pdispObj)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // rax

  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  v2 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  v2->pProto.pObject = 0i64;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pDispObj = pdispObj;
  this->EventHandlers.mHash.pTable = 0i64;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(
    (Scaleform::GFx::DisplayObjectBase *)&pdispObj->vfptr,
    (Scaleform::GFx::AvmDisplayObjBase *)&this->vfptr);
}

// File Line: 23
// RVA: 0x6D0ED0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::~AvmCharacter(Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::AS2::AvmCharacter *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v3; // rcx
  unsigned int v4; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v2 = (Scaleform::GFx::AS2::ObjectInterface *)&this->vfptr;
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&this->EventHandlers.mHash.pTable);
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  v3 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->pProto.pObject->vfptr;
  if ( v3 )
  {
    v4 = v3->RefCount;
    if ( v4 & 0x3FFFFFF )
    {
      v3->RefCount = v4 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
  v1->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
}

// File Line: 28
// RVA: 0x6EE2B0
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetASEnvironment(Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rax

  v1 = this->pDispObj->pParent;
  if ( !v1 )
    return 0i64;
  while ( !((v1->Flags >> 10) & 1) )
  {
    v1 = v1->pParent;
    if ( !v1 )
      return 0i64;
  }
  return (Scaleform::GFx::AS2::Environment *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * (unsigned __int8)v1->AvmObjOffset))[30].__vecDelDtor)();
}

// File Line: 38
// RVA: 0x6EE2F0
void __fastcall VariableIntArrayImplementation::setAll(VariableIntArrayImplementation *this, const unsigned __int64 *in, __int64 size)
{
  ((void (__fastcall *)(VariableIntArrayImplementation *, const unsigned __int64 *, __int64))this->vfptr[30].__vecDelDtor)(
    this,
    in,
    size);
}

// File Line: 59
// RVA: 0x6EE350
const char *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetAbsolutePath(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::String *ppath)
{
  Scaleform::String *v2; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rax
  Scaleform::GFx::DisplayObject *v5; // rcx
  const char ***v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::AS2::AvmCharacter *v9; // rcx
  Scaleform::MsgFormat::Sink r; // [rsp+20h] [rbp-428h]
  __int64 v12; // [rsp+38h] [rbp-410h]
  Scaleform::MsgFormat v13; // [rsp+40h] [rbp-408h]
  Scaleform::GFx::ASString result; // [rsp+450h] [rbp+8h]

  v12 = -2i64;
  v2 = ppath;
  v3 = this;
  v4 = this->pDispObj;
  v5 = (Scaleform::GFx::DisplayObject *)&v4->pParent->vfptr;
  if ( v5 )
  {
    Scaleform::GFx::DisplayObject::GetAbsolutePath(v5, ppath);
    Scaleform::String::AppendString(v2, ".", -1i64);
    v6 = (const char ***)Scaleform::GFx::AS3::AvmDisplayObj::GetName(v3, &result);
    Scaleform::String::AppendString(v2, **v6, -1i64);
    v7 = result.pNode;
    v8 = result.pNode->RefCount == 1;
    --v7->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  }
  else if ( (v4->Flags >> 10) & 1 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v3->vfptr->gap8[8])(&v3->vfptr) == 2 )
      v9 = v3;
    else
      v9 = 0i64;
    LODWORD(result.pNode) = ((__int64 (*)(void))v9[1].vfptr[2].GetAbsolutePath)();
    r.Type = 0;
    r.SinkData.pStr = v2;
    Scaleform::MsgFormat::MsgFormat(&v13, &r);
    Scaleform::MsgFormat::Parse(&v13, "_level{0}");
    Scaleform::MsgFormat::FormatD1<long>(&v13, (const int *)&result);
    Scaleform::MsgFormat::FinishFormatD(&v13);
    Scaleform::MsgFormat::~MsgFormat(&v13);
  }
  else
  {
    Scaleform::String::Clear(ppath);
  }
  return (const char *)((v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 90
// RVA: 0x6EFB30
Scaleform::RefCountImplCoreVtbl *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetGC(Scaleform::GFx::AS2::AvmCharacter *this)
{
  return this->pDispObj->pASRoot[2].vfptr;
}

// File Line: 99
// RVA: 0x6B2B80
void __fastcall Scaleform::GFx::AS2::AvmCharacter::CharacterGetDepth(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rdi
  Scaleform::GFx::AS2::FnCall *v2; // rbx
  _DWORD *v3; // rax
  Scaleform::GFx::AS2::Value *v4; // rbx
  int v5; // edi

  v1 = fn->ThisPtr;
  v2 = fn;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->vfptr->gap8[8])(fn->ThisPtr) - 2 > 3 )
    v3 = 0i64;
  else
    v3 = v1[1].vfptr;
  if ( !v3 )
    v3 = v2->Env->Target;
  v4 = v2->Result;
  v5 = v3[11];
  if ( v4->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v4);
  v4->T.Type = 4;
  v4->NV.Int32Value = v5 - 0x4000;
}

// File Line: 257
// RVA: 0x6FD3D0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(Scaleform::GFx::AS2::GlobalContext *pcontext)
{
  Scaleform::RefCountImplCoreVtbl *v1; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v2; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v3; // rax
  Scaleform::GFx::AS2::AvmCharacter::MemberTableType *v4; // rbx
  const char *v5; // r8
  unsigned __int64 v6; // r9
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h]
  char v10; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]

  v1 = pcontext->pMovieRoot->pASMovieRoot.pObject[39].vfptr;
  v2 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pcontext->StandardMemberMap.mHash.pTable;
  v3 = pcontext->StandardMemberMap.mHash.pTable;
  if ( !v3 || v3->EntryCount < 0x93 )
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&pcontext->StandardMemberMap.mHash.pTable,
      &pcontext->StandardMemberMap,
      0x93ui64);
  v4 = Scaleform::GFx::AS2::AvmCharacter::MemberTable;
  if ( Scaleform::GFx::AS2::AvmCharacter::MemberTable[0].pName )
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
        (Scaleform::GFx::ASStringManager *)v1,
        &result,
        v5,
        v6,
        (v4->CaseInsensitive != 0 ? 0x10000000 : 0) | 0x20000000);
      v10 = v4->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        v2,
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

// File Line: 298
// RVA: 0x6F63B0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::ASString *memberName)
{
  Scaleform::GFx::ASStringNode *v2; // rdi
  Scaleform::GFx::AS2::AvmCharacter *v3; // r14
  char v4; // bp
  Scaleform::GFx::ASStringNode *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rsi
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v10; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v11; // r14
  signed __int64 v12; // rax
  signed __int64 v13; // rcx
  signed __int64 v14; // rax
  signed __int64 v15; // rdx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v18; // [rsp+58h] [rbp+10h]

  v2 = (Scaleform::GFx::ASStringNode *)memberName;
  v3 = this;
  v4 = -1;
  v5 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)(*(_QWORD *)(((__int64 (__cdecl *)(Scaleform::GFx::AS2::AvmCharacter *))this->vfptr[1].OnUnloading)(this)
                                                                + 40)
                                                    + 24i64)
                                        + 312i64);
  v18 = v5;
  ++v5->RefCount;
  if ( (*((_DWORD *)v2->pData + 7) >> 29) & 1 )
  {
LABEL_11:
    v10 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))v3->vfptr[1].OnUnloading)(v3) + 112);
    if ( v5->Size )
    {
      result.pNode = v2;
      if ( !*((_QWORD *)v2->pData + 2) )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)v2->pData);
      if ( v10->pTable )
      {
        v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                v10,
                (Scaleform::GFx::ASString::NoCaseKey *)&result,
                *((unsigned int *)v2->pData + 7) & v10->pTable->SizeMask);
        if ( v14 >= 0 )
        {
          v15 = (signed __int64)v10->pTable + 24 * (v14 + 1);
          if ( v15 )
            v4 = *(_BYTE *)(v15 + 8);
        }
      }
    }
    else
    {
      v11.pTable = v10->pTable;
      if ( v10->pTable )
      {
        v12 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::MovieImpl::StickyVarNode *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)v10,
                (Scaleform::GFx::ASString *)v2,
                *((unsigned int *)v2->pData + 7) & v11.pTable->SizeMask);
        if ( v12 >= 0 )
        {
          v13 = (signed __int64)v11.pTable + 8 * (3 * v12 + 3);
          if ( v13 )
            v4 = *(_BYTE *)(v13 + 8);
        }
      }
    }
    goto LABEL_22;
  }
  if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)v2)
    || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)v2, 0) != 95 )
  {
    goto LABEL_22;
  }
  Scaleform::GFx::ASString::ToLower((Scaleform::GFx::ASString *)v2, &result);
  v6 = result.pNode;
  if ( (result.pNode->HashFlags >> 28) & 1 )
  {
    ++result.pNode->RefCount;
    v7 = v5->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v5 = v6;
    v18 = v6;
    v8 = result.pNode;
    v7 = result.pNode->RefCount == 1;
    --v8->RefCount;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    goto LABEL_11;
  }
  v9 = result.pNode;
  v7 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
LABEL_22:
  v7 = v5->RefCount-- == 1;
  if ( v7 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return (unsigned int)v4;
}

// File Line: 336
// RVA: 0x71B780
bool __fastcall Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::AvmCharacter::StandardMember member, Scaleform::GFx::AS2::Value *val, bool opcodeFlag)
{
  Scaleform::GFx::AS2::Value *v4; // rsi
  __int64 v5; // rbx
  Scaleform::GFx::DisplayObject **v6; // rdi
  int v7; // eax
  Scaleform::GFx::AS2::Environment *v8; // rax
  Scaleform::GFx::AS2::Environment *v9; // rbp
  bool v10; // al
  long double v11; // xmm0_8
  Scaleform::RefCountNTSImplCoreVtbl *v12; // rbx
  bool v13; // al
  unsigned int v14; // er9
  char **v15; // r10
  unsigned __int8 *v16; // rax
  int v17; // ecx
  int v18; // edx
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  signed int v22; // eax
  signed int v23; // edx
  unsigned int v24; // er9
  Scaleform::GFx::ASString *v25; // rax
  bool v26; // al
  Scaleform::GFx::DisplayObject *v27; // rcx
  bool v28; // al
  Scaleform::GFx::DisplayObject *v29; // rcx
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::AS2::Environment *v31; // rax
  bool v32; // al
  Scaleform::GFx::DisplayObject *v33; // rcx
  Scaleform::GFx::AS2::Environment *v34; // rax
  Scaleform::GFx::AS2::Environment *v35; // rax
  bool v36; // al
  Scaleform::GFx::DisplayObject *v37; // rcx
  Scaleform::GFx::AS2::Environment *v38; // rax
  bool v39; // al
  Scaleform::GFx::DisplayObject *v40; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v41; // rbx
  Scaleform::GFx::AS2::Environment *v42; // rax
  bool v43; // al
  Scaleform::Render::EdgeAAMode v44; // ebx
  Scaleform::GFx::AS2::Environment *v45; // rax
  double v46; // xmm0_8
  Scaleform::Render::TreeNode *v47; // rax
  Scaleform::String v48; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString v50; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ASString v51; // [rsp+38h] [rbp-20h]
  __int64 v52; // [rsp+40h] [rbp-18h]

  v52 = -2i64;
  v4 = val;
  v5 = (signed int)member;
  v6 = (Scaleform::GFx::DisplayObject **)this;
  if ( opcodeFlag && (unsigned int)member > 0x15 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&this->pDispObj->vfptr,
      "Invalid SetProperty request, property number %d",
      member);
    return 0;
  }
  if ( member == -1 )
    return 0;
  if ( (signed int)member > 32 )
    return 0;
  v7 = ((__int64 (*)(void))this->vfptr[2].OnEventLoad)();
  if ( !_bittest(&v7, v5) )
    return 0;
  v8 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
  v9 = v8;
  switch ( (_DWORD)v5 )
  {
    case 0:
      if ( v4->T.Type )
      {
        if ( v4->T.Type != 10 )
        {
          Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
          ((void (*)(void))v6[3]->vfptr[21].__vecDelDtor)();
        }
      }
      return 1;
    case 1:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      ((void (*)(void))v6[3]->vfptr[23].__vecDelDtor)();
      return 1;
    case 2:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      ((void (*)(void))v6[3]->vfptr[27].__vecDelDtor)();
      return 1;
    case 3:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      ((void (*)(void))v6[3]->vfptr[29].__vecDelDtor)();
      return 1;
    case 4:
    case 5:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0xF:
    case 0x14:
    case 0x15:
    case 0x16:
      v30 = Scaleform::GFx::DisplayObject::GetName(v6[3], &v51);
      Scaleform::GFx::AS2::Environment::LogScriptWarning(
        v9,
        "Attempt to write read-only property %s.%s, ignored",
        v30->pNode->pData,
        Scaleform::GFx::AS2::AvmCharacter::MemberTable[v5].pName);
      v21 = v51.pNode;
      goto LABEL_48;
    case 6:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      v11 = Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      Scaleform::GFx::DisplayObjectBase::SetAlpha((Scaleform::GFx::DisplayObjectBase *)&v6[3]->vfptr, v11);
      return 1;
    case 7:
      v12 = v6[3]->vfptr;
      v13 = Scaleform::GFx::AS2::Value::ToBool(v4, v8);
      v12[58].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6[3]->vfptr, v13);
      return 1;
    case 8:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      ((void (*)(void))v6[3]->vfptr[45].__vecDelDtor)();
      return 1;
    case 9:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      ((void (*)(void))v6[3]->vfptr[47].__vecDelDtor)();
      return 1;
    case 0xA:
      if ( !v4->T.Type || v4->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
      ((void (*)(void))v6[3]->vfptr[33].__vecDelDtor)();
      return 1;
    case 0xD:
      v25 = Scaleform::GFx::AS2::Value::ToString(v4, &v50, v8, -1);
      Scaleform::GFx::DisplayObject::SetName(v6[3], v25);
      v21 = v50.pNode;
      goto LABEL_48;
    case 0x10:
    case 0x12:
    case 0x13:
    case 0x19:
      return 1;
    case 0x11:
      if ( v4->T.Type && v4->T.Type != 10 )
      {
        v35 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
        v36 = Scaleform::GFx::AS2::Value::ToBool(v4, v35);
        v37 = v6[3];
        if ( v36 )
        {
          v37[1].Id.Id |= 0x180u;
        }
        else
        {
          v37[1].Id.Id &= 0xFFFFFF7F;
          v37[1].Id.Id |= 0x100u;
        }
      }
      else
      {
        v6[3][1].Id.Id &= 0xFFFFFF9F;
      }
      _((AMD_HD3D *)v6[3]);
      return 1;
    case 0x17:
      if ( v4->T.Type == 5 )
      {
        Scaleform::GFx::AS2::Value::ToString(v4, &result, v8, -1);
        Scaleform::String::String(&v48, result.pNode->pData);
        v14 = 1;
        v15 = off_142093B18;
        while ( 1 )
        {
          v16 = (unsigned __int8 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
          do
          {
            v17 = (unsigned __int8)(*v15)[(_QWORD)v16 - 12 - (v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)];
            v18 = *v16 - v17;
            if ( *v16 != v17 )
              break;
            ++v16;
          }
          while ( v17 );
          if ( !v18 )
            break;
          ++v14;
          ++v15;
          if ( v14 >= 0xF )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v19 = result.pNode;
            v20 = result.pNode->RefCount == 1;
            --v19->RefCount;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v19);
            return 1;
          }
        }
        v6[3]->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v6[3], v14);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v21 = result.pNode;
LABEL_48:
        v20 = v21->RefCount-- == 1;
        if ( !v20 )
          return 1;
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        v10 = 1;
      }
      else
      {
        v22 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v8);
        v23 = 14;
        if ( v22 < 14 )
          v23 = v22;
        v24 = 1;
        if ( v23 > 1 )
          v24 = v23;
        v6[3]->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)v6[3], v24);
        v10 = 1;
      }
      break;
    case 0x18:
      v41 = v6[3]->vfptr;
      v42 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
      v43 = Scaleform::GFx::AS2::Value::ToBool(v4, v42);
      v41[55].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v6[3]->vfptr, v43);
      return 1;
    case 0x1A:
      v26 = Scaleform::GFx::AS2::Value::ToBool(v4, v8);
      v27 = v6[3];
      if ( v26 )
        v27[1].Id.Id |= 0x10u;
      else
        v27[1].Id.Id &= 0xFFFFFFEF;
      return 1;
    case 0x1B:
      v28 = Scaleform::GFx::AS2::Value::ToBool(v4, v8);
      v29 = v6[3];
      if ( v28 )
        v29[1].Id.Id |= 0x4000u;
      else
        v29[1].Id.Id &= 0xFFFFBFFF;
      return 1;
    case 0x1D:
      if ( v4->T.Type && v4->T.Type != 10 )
      {
        v31 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
        v32 = Scaleform::GFx::AS2::Value::ToBool(v4, v31);
        v33 = v6[3];
        if ( v32 )
        {
          v33[1].Id.Id |= 0x60u;
        }
        else
        {
          v33[1].Id.Id &= 0xFFFFFFDF;
          v33[1].Id.Id |= 0x40u;
        }
      }
      else
      {
        v6[3][1].Id.Id &= 0xFFFFFF9F;
      }
      return 1;
    case 0x1E:
      v34 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
      LOWORD(v6[3][1].Depth) = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v4, v34);
      return 1;
    case 0x1F:
      if ( v4->T.Type && v4->T.Type != 10 )
      {
        v38 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
        v39 = Scaleform::GFx::AS2::Value::ToBool(v4, v38);
        v40 = v6[3];
        if ( v39 )
        {
          v40[1].Id.Id |= 0x600u;
        }
        else
        {
          v40[1].Id.Id &= 0xFFFFFDFF;
          v40[1].Id.Id |= 0x400u;
        }
      }
      else
      {
        v6[3][1].Id.Id &= 0xFFFFF9FF;
      }
      return 1;
    case 0x20:
      v44 = 0;
      v45 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject **))(*v6)[1].pIndXFormData)(v6);
      v46 = (double)Scaleform::GFx::AS2::Value::ToInt32(v4, v45);
      if ( v46 == 3.0 )
      {
        v44 = 12;
      }
      else if ( v46 == 1.0 )
      {
        v44 = 4;
      }
      else if ( v46 == 2.0 )
      {
        v44 = 8;
      }
      v47 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v6[3]->vfptr);
      Scaleform::Render::TreeNode::SetEdgeAAMode(v47, v44);
      return 1;
    default:
      return 0;
  }
  return v10;
}

// File Line: 616
// RVA: 0x6F56C0
Scaleform::GFx::AS2::AvmCharacter::GetStandardMember

// File Line: 918
// RVA: 0x6DDC60
Scaleform::GFx::InteractiveObject *__usercall Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject@<rax>(Scaleform::GFx::AS2::AvmCharacter *this@<rcx>, Scaleform::GFx::ASString *newname@<rdx>, int depth@<r8d>, Scaleform::GFx::AS2::ObjectInterface *psource@<r9>, int a5@<xmm0>)
{
  int v5; // er12
  Scaleform::GFx::AS2::AvmCharacter *v6; // r13
  Scaleform::GFx::InteractiveObject *v7; // rcx
  __int64 v8; // r14
  Scaleform::GFx::InteractiveObject *v9; // r15
  __int16 v10; // si
  int v11; // ebx
  __int128 *v12; // rdi
  __int128 *v13; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v14; // r10
  __int64 v15; // rax
  __int128 v17; // [rsp+28h] [rbp-59h]
  __int128 v18; // [rsp+38h] [rbp-49h]
  __int128 v19; // [rsp+48h] [rbp-39h]
  __int128 v20; // [rsp+58h] [rbp-29h]
  Scaleform::Render::RenderBuffer *v21; // [rsp+68h] [rbp-19h]
  int v22; // [rsp+70h] [rbp-11h]
  int v23; // [rsp+74h] [rbp-Dh]
  int v24; // [rsp+78h] [rbp-9h]
  __int64 v25; // [rsp+80h] [rbp-1h]
  __int16 v26; // [rsp+88h] [rbp+7h]
  int v27; // [rsp+8Ah] [rbp+9h]
  __int64 v28; // [rsp+F0h] [rbp+6Fh]
  __int64 v29; // [rsp+100h] [rbp+7Fh]

  v5 = depth;
  v6 = this;
  v7 = this->pDispObj;
  v8 = 0i64;
  v9 = 0i64;
  if ( (v7->pParent->Flags >> 10) & 1 )
    v9 = v7->pParent;
  if ( !v9 || (unsigned int)depth > 0x7EFFFFFD )
    return 0i64;
  v10 = v7->ClipDepth;
  v11 = v7->Id.Id;
  ((void (*)(void))v7->vfptr[17].__vecDelDtor)();
  v12 = (__int128 *)((__int64 (*)(void))v6->pDispObj->vfptr[2].__vecDelDtor)();
  v13 = (__int128 *)Scaleform::GFx::DisplayObjectBase::GetCxform((Scaleform::GFx::DisplayObjectBase *)&v6->pDispObj->vfptr);
  v17 = *v13;
  v18 = v13[1];
  v19 = *v12;
  v20 = v12[1];
  v21 = 0i64;
  v22 = a5;
  v27 = 16777228;
  v23 = v5;
  v24 = v11;
  v26 = v10;
  v25 = 0i64;
  v14 = v9->vfptr;
  *((_QWORD *)&v18 + 1) = v6->pDispObj;
  *(_QWORD *)&v18 = 0i64;
  DWORD2(v17) = 1;
  LODWORD(v17) = -1;
  v15 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, __int128 *, __int64, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v14[118].__vecDelDtor)(
          v9,
          &v17,
          v28,
          0i64,
          v29,
          v17,
          *((_QWORD *)&v17 + 1),
          0i64,
          *((_QWORD *)&v18 + 1),
          v19,
          *((_QWORD *)&v19 + 1),
          v20,
          *((_QWORD *)&v20 + 1));
  if ( v15 && *(_BYTE *)(v15 + 106) < 0 )
    v8 = v15;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  return (Scaleform::GFx::InteractiveObject *)v8;
}

// File Line: 967
// RVA: 0x6FB0D0
bool __fastcall Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::EventId *id)
{
  unsigned int v2; // eax
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *v3; // rdi
  signed __int64 v4; // rax
  signed __int64 v5; // rax
  bool result; // al
  Scaleform::GFx::EventId key; // [rsp+20h] [rbp-28h]

  v2 = id->Id - 64;
  key.Id = id->Id;
  if ( v2 & 0xFFFFFFBF )
  {
    key.WcharCode = id->WcharCode;
    key.KeyCode = id->KeyCode;
    key.TouchID = id->TouchID;
    *(_DWORD *)&key.RollOverCnt = *(_DWORD *)&id->RollOverCnt;
  }
  else
  {
    *(_QWORD *)&key.WcharCode = 0i64;
    key.AsciiCode = 0;
    *(_DWORD *)&key.RollOverCnt = 65280;
  }
  v3 = &this->EventHandlers;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexAlt<Scaleform::GFx::EventId>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&this->EventHandlers.mHash.pTable,
         &key);
  if ( v4 >= 0 && (v5 = (signed __int64)&v3->mHash.pTable[4 * v4 + 2]) != 0 )
    result = v5 != -24;
  else
    result = 0;
  return result;
}

// File Line: 973
// RVA: 0x6FF6B0
char __fastcall Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::AS2::Environment *v3; // rdi
  unsigned int v4; // eax
  Scaleform::GFx::AS2::AvmCharacter *v5; // rbp
  signed __int64 v6; // rax
  signed __int64 v7; // rbx
  _QWORD *v8; // rbx
  __int64 v9; // rsi
  __int64 v10; // r14
  Scaleform::GFx::EventId key; // [rsp+40h] [rbp-38h]

  v3 = penv;
  v4 = id->Id - 64;
  v5 = this;
  key.Id = id->Id;
  if ( v4 & 0xFFFFFFBF )
  {
    key.WcharCode = id->WcharCode;
    key.KeyCode = id->KeyCode;
    key.TouchID = id->TouchID;
    *(_DWORD *)&key.RollOverCnt = *(_DWORD *)&id->RollOverCnt;
  }
  else
  {
    *(_QWORD *)&key.WcharCode = 0i64;
    key.AsciiCode = 0;
    *(_DWORD *)&key.RollOverCnt = 65280;
  }
  v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexAlt<Scaleform::GFx::EventId>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&this->EventHandlers.mHash.pTable,
         &key);
  if ( v6 < 0 )
    return 0;
  v7 = (signed __int64)&v5->EventHandlers.mHash.pTable[4 * v6 + 2];
  if ( !v7 )
    return 0;
  v8 = (_QWORD *)(v7 + 24);
  if ( !v8 )
    return 0;
  v9 = v8[1];
  if ( v9 )
  {
    v10 = 0i64;
    do
    {
      Scaleform::GFx::AS2::GAS_Invoke(
        (Scaleform::GFx::AS2::Value *)(v10 + *v8),
        0i64,
        (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
        v3,
        0,
        32 * LODWORD(v3->Stack.Pages.Data.Size)
      + ((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5)
      - 31,
        0i64);
      v10 += 32i64;
      --v9;
    }
    while ( v9 );
  }
  return 1;
}

// File Line: 988
// RVA: 0x71B350
void __fastcall Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::EventId *id, Scaleform::GFx::AS2::Value *method)
{
  Scaleform::GFx::AS2::Value *v3; // r15
  Scaleform::GFx::EventId *v4; // rdi
  Scaleform::GFx::AS2::AvmCharacter *v5; // r14
  signed __int64 v6; // rax
  signed __int64 v7; // rbx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *v8; // rbx
  signed __int64 v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *v12; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *v13; // rbx
  signed __int64 v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::EventId key; // [rsp+28h] [rbp-18h]
  Scaleform::GFx::AS2::Value *v17; // [rsp+88h] [rbp+48h]
  Scaleform::GFx::AS2::Value *v18; // [rsp+98h] [rbp+58h]

  v3 = method;
  v4 = id;
  v5 = this;
  key.Id = id->Id;
  if ( (key.Id - 64) & 0xFFFFFFBF )
  {
    key.WcharCode = id->WcharCode;
    key.KeyCode = id->KeyCode;
    key.TouchID = id->TouchID;
    *(_DWORD *)&key.RollOverCnt = *(_DWORD *)&id->RollOverCnt;
  }
  else
  {
    *(_QWORD *)&key.WcharCode = 0i64;
    key.AsciiCode = 0;
    *(_DWORD *)&key.RollOverCnt = 65280;
  }
  v6 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexAlt<Scaleform::GFx::EventId>(
         (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&this->EventHandlers.mHash.pTable,
         &key);
  if ( v6 >= 0
    && (v7 = (signed __int64)&v5->EventHandlers.mHash.pTable[4 * v6 + 2]) != 0
    && (v8 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *)(v7 + 24)) != 0i64 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v8,
      v8,
      v8->Size + 1);
    v9 = 32 * v8->Size - 32;
    v10 = (Scaleform::GFx::AS2::Value *)((char *)v8->Data + v9) == 0;
    v11 = (Scaleform::GFx::AS2::Value *)((char *)v8->Data + v9);
    v17 = v11;
    if ( !v10 )
      Scaleform::GFx::AS2::Value::Value(v11, v3, (__int64)v4);
  }
  else
  {
    LODWORD(v17) = 323;
    v12 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::AvmCharacter *, signed __int64, Scaleform::GFx::AS2::Value **, signed __int64, _QWORD, _QWORD, _QWORD))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, v5, 24i64, &v17, -2i64, *(_QWORD *)&key.Id, *(_QWORD *)&key.KeyCode, *(_QWORD *)&key.RollOverCnt);
    v13 = v12;
    v18 = (Scaleform::GFx::AS2::Value *)v12;
    if ( v12 )
    {
      *(_QWORD *)&key.Id = v12;
      v12->Data = 0i64;
      v12->Size = 0i64;
      v12->Policy.Capacity = 0i64;
    }
    else
    {
      v13 = 0i64;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v13,
      v13,
      v13->Size + 1);
    v14 = 32 * v13->Size - 32;
    v10 = (Scaleform::GFx::AS2::Value *)((char *)v13->Data + v14) == 0;
    v15 = (Scaleform::GFx::AS2::Value *)((char *)v13->Data + v14);
    v18 = v15;
    if ( !v10 )
      Scaleform::GFx::AS2::Value::Value(v15, v3, (__int64)v4);
    *(_QWORD *)&key.Id = v4;
    *(_QWORD *)&key.KeyCode = v13;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *)&v5->EventHandlers.mHash.pTable,
      &v5->EventHandlers,
      (Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef *)&key);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(v13);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
}

// File Line: 1006
// RVA: 0x7133A0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::SetClipEventHandlers(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::EventId *id, Scaleform::GFx::AS2::Value *method)
{
  Scaleform::GFx::EventId *v3; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // r14
  unsigned int v6; // edx
  unsigned int v7; // ecx
  unsigned __int8 v8; // dl
  unsigned int v9; // ebp
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int v12; // eax
  Scaleform::GFx::EventId ida; // [rsp+20h] [rbp-38h]

  v3 = id;
  v4 = this;
  v5 = method;
  v6 = (id->Id & 0x55555555) + ((id->Id >> 1) & 0x55555555);
  v7 = (((v6 & 0x33333333) + ((v6 >> 2) & 0x33333333)) & 0xF0F0F0F)
     + ((((v6 & 0x33333333) + ((v6 >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F);
  v8 = v7 + v7 / 0xFF;
  v9 = v8;
  if ( v8 == 1 )
  {
    Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(v4, v3, method);
  }
  else
  {
    v10 = 0;
    v11 = 1;
    if ( v8 )
    {
      do
      {
        if ( v11 & v3->Id )
        {
          ida.Id = v3->Id;
          ida.WcharCode = v3->WcharCode;
          ++v10;
          ida.KeyCode = v3->KeyCode;
          v12 = v3->TouchID;
          ida.Id = v11;
          ida.TouchID = v12;
          *(_DWORD *)&ida.RollOverCnt = *(_DWORD *)&v3->RollOverCnt;
          Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(v4, &ida, v5);
        }
        v11 *= 2;
      }
      while ( v10 < v9 );
    }
  }
}

// File Line: 1033
// RVA: 0x6E7F40
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmCharacter::ExecuteEvent(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v3; // r12
  Scaleform::GFx::InteractiveObject *v4; // r13
  __int64 v5; // rax
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::RefCountNTSImpl *v7; // r14
  __int64 v8; // rdx
  unsigned int v9; // eax
  Scaleform::GFx::KeyboardState *v10; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // r15
  signed __int64 nargs; // rdi
  char v13; // r14
  char v14; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  int v16; // edx
  Scaleform::GFx::ASStringNode *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::AS2::FunctionRef *v19; // r14
  Scaleform::GFx::DisplayObject *v20; // rcx
  Scaleform::GFx::CharacterHandle *v21; // rax
  char v22; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // rcx
  int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  unsigned int v26; // eax
  unsigned int v27; // eax
  int v28; // eax
  char v29; // r14
  Scaleform::GFx::AS2::Value *v30; // rcx
  unsigned int v31; // eax
  char v32; // r15
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v33; // r14
  Scaleform::GFx::AS2::Value *v34; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v35; // r14
  Scaleform::GFx::AS2::Value *v36; // rcx
  int v37; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v38; // r14
  Scaleform::GFx::AS2::Value *v39; // rcx
  char v40; // al
  char v41; // r14
  Scaleform::GFx::AS2::Value *v42; // rcx
  Scaleform::GFx::AS2::Value **v43; // rbx
  Scaleform::GFx::AS2::FunctionRef *v44; // rbx
  Scaleform::GFx::DisplayObject *v45; // rcx
  Scaleform::GFx::CharacterHandle *v46; // rax
  char v47; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v48; // rcx
  int v49; // edx
  Scaleform::GFx::ASStringNode *v50; // rcx
  unsigned int v51; // eax
  Scaleform::GFx::AS2::FunctionRef *v52; // rbx
  Scaleform::GFx::DisplayObject *v53; // rcx
  Scaleform::GFx::CharacterHandle *v54; // rax
  char v55; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v56; // rcx
  int v57; // edx
  Scaleform::GFx::ASStringNode *v58; // rcx
  unsigned int v59; // eax
  Scaleform::GFx::AS2::FunctionRef *v60; // rbx
  Scaleform::GFx::DisplayObject *v61; // rcx
  Scaleform::GFx::CharacterHandle *v62; // rax
  char v63; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v64; // rcx
  int v65; // edx
  Scaleform::GFx::ASStringNode *v66; // rcx
  unsigned int v67; // eax
  Scaleform::GFx::ASStringNode *v68; // rcx
  bool v69; // zf
  Scaleform::GFx::AS2::Value value; // [rsp+40h] [rbp-49h]
  Scaleform::GFx::AS2::Value *v72; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::Value *v73; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::AS2::Value method; // [rsp+70h] [rbp-19h]
  Scaleform::RefCountNTSImpl *v75; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::InteractiveObject *v76; // [rsp+98h] [rbp+Fh]
  __int64 v77; // [rsp+A0h] [rbp+17h]
  signed int v78; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+100h] [rbp+77h]
  Scaleform::RefCountNTSImpl *v80; // [rsp+108h] [rbp+7Fh]

  v77 = -2i64;
  v2 = id;
  v3 = this;
  v4 = this->pDispObj;
  if ( v4 )
    ++v4->RefCount;
  v76 = v4;
  v5 = ((__int64 (*)(void))this->vfptr[2].GetAbsolutePath)();
  v6 = (Scaleform::GFx::AS2::Environment *)v5;
  v7 = *(Scaleform::RefCountNTSImpl **)(v5 + 224);
  v80 = v7;
  if ( v7 )
    ++v7->RefCount;
  v75 = v7;
  if ( !((v2->Id - 64) & 0xFFFFFFBF) )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 224) + 32i64) + 16i64);
    if ( v8 )
    {
      v9 = v2->ControllerIndex;
      if ( v9 >= 6 )
        v10 = 0i64;
      else
        v10 = (Scaleform::GFx::KeyboardState *)(v8 + 1672i64 * v9 + 9192);
      Scaleform::GFx::KeyboardState::UpdateListeners(v10, v2);
    }
  }
  v78 = 0;
  method.T.Type = 0;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(v3, v2) && !v2->RollOverCnt )
  {
    Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(v3, v6, v2);
    v78 = 1;
  }
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    v2);
  if ( result.pNode->Size )
  {
    v11 = (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr;
    if ( v3->vfptr->GetMemberRaw(
           (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
           &v6->StringContext,
           &result,
           &method) )
    {
      if ( method.T.Type == 9 )
      {
        value.T.Type = 0;
        Scaleform::GFx::AS2::Value::GetPropertyValue(
          &method,
          v6,
          (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
          &value);
        Scaleform::GFx::AS2::Value::operator=(&method, &value, 0i64);
        if ( value.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&value);
      }
      if ( method.T.Type != 1 )
      {
        if ( v6->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          nargs = 0i64;
          v13 = 1;
          if ( v2->RollOverCnt )
          {
            Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            if ( *(_QWORD *)&value.T.Type )
            {
              v13 = 1;
              if ( (*(signed int (**)(void))(**(_QWORD **)&value.T.Type + 128i64))() < 2 )
                v13 = 0;
            }
            v14 = *((_BYTE *)&value.NV + 16);
            if ( !(*((char *)&value.NV + 16) & 2) )
            {
              v15 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v16 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( v16 & 0x3FFFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v16 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
                  v14 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( !(v14 & 1) )
            {
              v17 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v18 = value.V.pStringNode->RefCount;
                if ( v18 & 0x3FFFFFF )
                {
                  value.V.pStringNode->RefCount = v18 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v17);
                }
              }
            }
            value.V.pStringNode = 0i64;
            if ( !v13 )
              goto LABEL_139;
          }
          ++v78;
          if ( (v6->Target->pASRoot->pMovieImpl->Flags >> 2) & 1 )
          {
            v19 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            v20 = (Scaleform::GFx::DisplayObject *)&v3->pDispObj->vfptr;
            v21 = v20->pNameHandle.pObject;
            if ( !v21 )
              v21 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v20);
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
              (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v6->vfptr,
              "\n!!! ExecuteEvent started '%s' = %p for %s\n",
              result.pNode->pData,
              v19->Function,
              v21->NamePath.pNode->pData);
            v22 = *((_BYTE *)&value.NV + 16);
            if ( !(*((char *)&value.NV + 16) & 2) )
            {
              v23 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v24 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( v24 & 0x3FFFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v24 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
                  v22 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( !(v22 & 1) )
            {
              v25 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v26 = value.V.pStringNode->RefCount;
                if ( v26 & 0x3FFFFFF )
                {
                  value.V.pStringNode->RefCount = v26 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v25);
                }
              }
            }
            value.V.pStringNode = 0i64;
          }
          v27 = v2->Id;
          if ( v2->Id & 0xF80000 || v27 == 0x8000 || v27 == 0x10000 || v27 == 4096 || v27 == 2048 || v27 == 1024 )
          {
            v28 = (unsigned __int8)v2->AsciiCode;
            v29 = 4;
            value.T.Type = 4;
            value.NV.Int32Value = v28;
            ++v6->Stack.pCurrent;
            if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
            v30 = v6->Stack.pCurrent;
            v72 = v30;
            v73 = v30;
            if ( v30 )
            {
              Scaleform::GFx::AS2::Value::Value(v30, &value, 0i64);
              v29 = value.T.Type;
            }
            if ( (unsigned __int8)v29 >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&value);
            nargs = 1i64;
          }
          v31 = v2->Id;
          if ( v2->Id == 0x2000
            || v31 == 0x4000
            || v31 == 0x8000
            || v31 == 0x10000
            || v31 == 0x400000
            || v31 == 0x800000 )
          {
            v37 = (unsigned __int8)v2->RollOverCnt;
            v32 = 4;
            value.T.Type = 4;
            value.NV.Int32Value = v37;
            v38 = &v6->Stack;
            ++v38->pCurrent;
            if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
            v39 = v38->pCurrent;
            v73 = v39;
            v72 = v39;
            if ( v39 )
            {
              Scaleform::GFx::AS2::Value::Value(v39, &value, nargs);
              v32 = value.T.Type;
            }
          }
          else
          {
            if ( v31 != 1024 && v31 != 2048 && v31 != 0x80000 && v31 != 0x100000 )
            {
LABEL_87:
              v40 = v2->ControllerIndex;
              if ( v40 >= 0 || (_DWORD)nargs )
              {
                v41 = 4;
                value.T.Type = 4;
                value.NV.Int32Value = v40;
                ++v6->Stack.pCurrent;
                if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
                v42 = v6->Stack.pCurrent;
                v73 = v42;
                v72 = v42;
                if ( v42 )
                {
                  Scaleform::GFx::AS2::Value::Value(v42, &value, nargs);
                  v41 = value.T.Type;
                }
                if ( (unsigned __int8)v41 >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&value);
                LODWORD(nargs) = nargs + 1;
              }
              v43 = &v6->Stack.pCurrent;
              Scaleform::GFx::AS2::GAS_Invoke(
                &method,
                0i64,
                v11,
                v6,
                nargs,
                32 * v6->Stack.Pages.Data.Size
              - 32
              + ((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5),
                result.pNode->pData);
              for ( ; (_DWORD)nargs; LODWORD(nargs) = nargs - 1 )
              {
                if ( (*v43)->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(*v43);
                --*v43;
                if ( v6->Stack.pCurrent < v6->Stack.pPageStart )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
              }
              if ( (v6->Target->pASRoot->pMovieImpl->Flags >> 2) & 1 )
              {
                v44 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
                v45 = (Scaleform::GFx::DisplayObject *)&v3->pDispObj->vfptr;
                v46 = v45->pNameHandle.pObject;
                if ( !v46 )
                  v46 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v45);
                Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
                  (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v6->vfptr,
                  "!!! ExecuteEvent finished '%s' = %p for %s\n\n",
                  result.pNode->pData,
                  v44->Function,
                  v46->NamePath.pNode->pData);
                v47 = *((_BYTE *)&value.NV + 16);
                if ( !(*((char *)&value.NV + 16) & 2) )
                {
                  v48 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
                  if ( *(_QWORD *)&value.T.Type )
                  {
                    v49 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                    if ( v49 & 0x3FFFFFF )
                    {
                      *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v49 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
                      v47 = *((_BYTE *)&value.NV + 16);
                    }
                  }
                }
                *(_QWORD *)&value.T.Type = 0i64;
                if ( !(v47 & 1) )
                {
                  v50 = value.V.pStringNode;
                  if ( value.V.pStringNode )
                  {
                    v51 = value.V.pStringNode->RefCount;
                    if ( v51 & 0x3FFFFFF )
                    {
                      value.V.pStringNode->RefCount = v51 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v50);
                    }
                  }
                }
                value.V.pStringNode = 0i64;
              }
LABEL_139:
              v7 = v80;
              goto LABEL_140;
            }
            v32 = 4;
            value.T.Type = 4;
            if ( v2->KeyCode )
            {
              value.NV.Int32Value = -1;
              v35 = &v6->Stack;
              ++v35->pCurrent;
              if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
              v36 = v35->pCurrent;
              v73 = v36;
              v72 = v36;
              if ( v36 )
              {
                Scaleform::GFx::AS2::Value::Value(v36, &value, nargs);
                v32 = value.T.Type;
              }
            }
            else
            {
              value.NV.Int32Value = 0;
              v33 = &v6->Stack;
              ++v33->pCurrent;
              if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
              v34 = v33->pCurrent;
              v73 = v34;
              v72 = v34;
              if ( v34 )
              {
                Scaleform::GFx::AS2::Value::Value(v34, &value, nargs);
                v32 = value.T.Type;
              }
            }
          }
          if ( (unsigned __int8)v32 >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&value);
          v11 = (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr;
          nargs = (unsigned int)(nargs + 1);
          goto LABEL_87;
        }
        if ( !v2->RollOverCnt )
        {
          ++v78;
          if ( (v6->Target->pASRoot->pMovieImpl->Flags >> 2) & 1 )
          {
            v52 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            v53 = (Scaleform::GFx::DisplayObject *)&v3->pDispObj->vfptr;
            v54 = v53->pNameHandle.pObject;
            if ( !v54 )
              v54 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v53);
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
              (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v6->vfptr,
              "\n!!! ExecuteEvent started '%s' = %p for %s\n",
              result.pNode->pData,
              v52->Function,
              v54->NamePath.pNode->pData);
            v55 = *((_BYTE *)&value.NV + 16);
            if ( !(*((char *)&value.NV + 16) & 2) )
            {
              v56 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v57 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( v57 & 0x3FFFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v57 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v56);
                  v55 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( !(v55 & 1) )
            {
              v58 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v59 = value.V.pStringNode->RefCount;
                if ( v59 & 0x3FFFFFF )
                {
                  value.V.pStringNode->RefCount = v59 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v58);
                }
              }
            }
            value.V.pStringNode = 0i64;
          }
          Scaleform::GFx::AS2::GAS_Invoke(
            &method,
            0i64,
            (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
            v6,
            0,
            32 * v6->Stack.Pages.Data.Size
          - 31
          + ((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5),
            0i64);
          if ( (v6->Target->pASRoot->pMovieImpl->Flags >> 2) & 1 )
          {
            v60 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            v61 = (Scaleform::GFx::DisplayObject *)&v3->pDispObj->vfptr;
            v62 = v61->pNameHandle.pObject;
            if ( !v62 )
              v62 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v61);
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
              (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment> *)&v6->vfptr,
              "!!! ExecuteEvent finished '%s' = %p for %s\n\n",
              result.pNode->pData,
              v60->Function,
              v62->NamePath.pNode->pData);
            v63 = *((_BYTE *)&value.NV + 16);
            if ( !(*((char *)&value.NV + 16) & 2) )
            {
              v64 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v65 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( v65 & 0x3FFFFFF )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v65 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v64);
                  v63 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( !(v63 & 1) )
            {
              v66 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v67 = value.V.pStringNode->RefCount;
                if ( v67 & 0x3FFFFFF )
                {
                  value.V.pStringNode->RefCount = v67 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v66);
                }
              }
            }
            value.V.pStringNode = 0i64;
          }
        }
      }
    }
  }
LABEL_140:
  v68 = result.pNode;
  v69 = result.pNode->RefCount == 1;
  --v68->RefCount;
  if ( v69 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v68);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  return v78 != 0;
}

// File Line: 1186
// RVA: 0x6E8B20
char __fastcall Scaleform::GFx::AS2::AvmCharacter::ExecuteFunction(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::FunctionRef *function, Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *params)
{
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // r12
  Scaleform::GFx::AS2::FunctionRef *v4; // rsi
  Scaleform::GFx::AS2::AvmCharacter *v5; // r13
  __int64 v6; // rax
  _QWORD *v7; // r9
  unsigned __int64 v8; // r14
  __int64 v9; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v10; // rbx
  signed __int64 v11; // rsi
  Scaleform::GFx::AS2::Value *v12; // r15
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v14; // rbx
  int v15; // edx
  char v16; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // rcx
  unsigned int v18; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // rcx
  unsigned int v20; // eax
  void **v22; // [rsp+20h] [rbp-59h]
  Scaleform::GFx::AS2::Value *v23; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS2::ObjectInterface *v24; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v25; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v26; // [rsp+40h] [rbp-39h]
  char v27; // [rsp+48h] [rbp-31h]
  _QWORD *v28; // [rsp+50h] [rbp-29h]
  int v29; // [rsp+58h] [rbp-21h]
  int v30; // [rsp+5Ch] [rbp-1Dh]
  Scaleform::GFx::AS2::Value *v31; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS2::Value v32; // [rsp+68h] [rbp-11h]
  __int64 v33; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::AS2::Value *v34; // [rsp+90h] [rbp+17h]
  Scaleform::GFx::AS2::FunctionRef *v35; // [rsp+E8h] [rbp+6Fh]
  _QWORD *v36; // [rsp+F8h] [rbp+7Fh]

  v35 = function;
  v33 = -2i64;
  v3 = params;
  v4 = function;
  v5 = this;
  if ( !function->Function )
    return 0;
  v32.T.Type = 0;
  v6 = ((__int64 (*)(void))this->vfptr[2].GetAbsolutePath)();
  v7 = (_QWORD *)v6;
  v36 = (_QWORD *)v6;
  v8 = v3->Data.Size;
  if ( (signed int)v8 > 0 )
  {
    v9 = (unsigned int)(v8 - 1);
    if ( (signed int)v9 >= 0 )
    {
      v10 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v6 + 8);
      v11 = (signed int)v9;
      do
      {
        v12 = &v3->Data.Data[v11];
        ++v10->pCurrent;
        if ( v10->pCurrent >= v10->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v10);
        v13 = v10->pCurrent;
        v34 = v13;
        v31 = v13;
        if ( v13 )
          Scaleform::GFx::AS2::Value::Value(v13, v12, v9);
        --v11;
        v9 = (unsigned int)(v9 - 1);
      }
      while ( (signed int)v9 >= 0 );
      v4 = v35;
      v7 = v36;
    }
  }
  v14 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v7 + 1);
  v15 = ((v7[1] - v7[2]) >> 5) - 32 + 32 * v7[6];
  v22 = &Scaleform::GFx::AS2::FnCall::`vftable';
  v23 = &v32;
  v24 = (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr;
  v27 = 0;
  v25 = 0i64;
  v26 = 0i64;
  v28 = v7;
  v29 = v8;
  v30 = v15;
  ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD, void **, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::ObjectInterfaceVtbl **))v4->Function->vfptr[3].Finalize_GC)(
    v4->Function,
    &v22,
    v4->pLocalFrame,
    0i64,
    &Scaleform::GFx::AS2::FnCall::`vftable',
    &v32,
    &v5->vfptr);
  v22 = &Scaleform::GFx::AS2::FnCall::`vftable';
  v16 = v27;
  if ( !(v27 & 2) )
  {
    v17 = v25;
    if ( v25 )
    {
      v18 = v25->RefCount;
      if ( v18 & 0x3FFFFFF )
      {
        v25->RefCount = v18 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        v16 = v27;
      }
    }
  }
  v25 = 0i64;
  if ( !(v16 & 1) )
  {
    v19 = v26;
    if ( v26 )
    {
      v20 = v26->RefCount;
      if ( v20 & 0x3FFFFFF )
      {
        v26->RefCount = v20 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v19);
      }
    }
  }
  v26 = 0i64;
  v22 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
  if ( (signed int)v8 > 0 )
  {
    do
    {
      if ( v14->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v14->pCurrent);
      --v14->pCurrent;
      if ( v14->pCurrent < v14->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v14);
      LODWORD(v8) = v8 - 1;
    }
    while ( (_DWORD)v8 );
  }
  if ( v32.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v32);
  return 1;
}

// File Line: 1210
// RVA: 0x6E7D70
char __fastcall Scaleform::GFx::AS2::AvmCharacter::ExecuteCFunction(Scaleform::GFx::AS2::AvmCharacter *this, void (__fastcall *const function)(Scaleform::GFx::AS2::FnCall *), Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *params)
{
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *v3; // r12
  Scaleform::GFx::AS2::AvmCharacter *v4; // r13
  __int64 v5; // rax
  _QWORD *v6; // r9
  unsigned __int64 v7; // rsi
  __int64 v8; // rdi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v9; // rbx
  signed __int64 v10; // r14
  Scaleform::GFx::AS2::Value *v11; // r15
  Scaleform::GFx::AS2::Value *v12; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v13; // rbx
  __int64 v14; // rdx
  char v15; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  unsigned int v19; // eax
  void **v21; // [rsp+20h] [rbp-59h]
  Scaleform::GFx::AS2::Value *v22; // [rsp+28h] [rbp-51h]
  Scaleform::GFx::AS2::ObjectInterface *v23; // [rsp+30h] [rbp-49h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v25; // [rsp+40h] [rbp-39h]
  char v26; // [rsp+48h] [rbp-31h]
  _QWORD *v27; // [rsp+50h] [rbp-29h]
  int v28; // [rsp+58h] [rbp-21h]
  int v29; // [rsp+5Ch] [rbp-1Dh]
  Scaleform::GFx::AS2::Value *v30; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS2::Value v31; // [rsp+68h] [rbp-11h]
  __int64 v32; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::AS2::Value *v33; // [rsp+90h] [rbp+17h]
  void (__fastcall *v34)(Scaleform::GFx::AS2::FnCall *); // [rsp+E8h] [rbp+6Fh]
  _QWORD *v35; // [rsp+F8h] [rbp+7Fh]

  v34 = function;
  v32 = -2i64;
  v3 = params;
  v4 = this;
  if ( !function )
    return 0;
  v31.T.Type = 0;
  v5 = ((__int64 (*)(void))this->vfptr[2].GetAbsolutePath)();
  v6 = (_QWORD *)v5;
  v35 = (_QWORD *)v5;
  v7 = v3->Data.Size;
  if ( (signed int)v7 > 0 )
  {
    v8 = (unsigned int)(v7 - 1);
    if ( (signed int)v8 >= 0 )
    {
      v9 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v5 + 8);
      v10 = (signed int)v8;
      do
      {
        v11 = &v3->Data.Data[v10];
        ++v9->pCurrent;
        if ( v9->pCurrent >= v9->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v9);
        v12 = v9->pCurrent;
        v33 = v12;
        v30 = v12;
        if ( v12 )
          Scaleform::GFx::AS2::Value::Value(v12, v11, v8);
        --v10;
        v8 = (unsigned int)(v8 - 1);
      }
      while ( (signed int)v8 >= 0 );
      v6 = v35;
    }
  }
  v13 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v6 + 1);
  v14 = (unsigned int)((v6[1] - v6[2]) >> 5) - 32 + 32 * (unsigned int)v6[6];
  v21 = &Scaleform::GFx::AS2::FnCall::`vftable';
  v22 = &v31;
  v23 = (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr;
  v26 = 0;
  v24 = 0i64;
  v25 = 0i64;
  v27 = v6;
  v28 = v7;
  v29 = v14;
  ((void (__fastcall *)(void ***, __int64, Scaleform::GFx::AS2::ObjectInterfaceVtbl **))v34)(&v21, v14, &v4->vfptr);
  v21 = &Scaleform::GFx::AS2::FnCall::`vftable';
  v15 = v26;
  if ( !(v26 & 2) )
  {
    v16 = v24;
    if ( v24 )
    {
      v17 = v24->RefCount;
      if ( v17 & 0x3FFFFFF )
      {
        v24->RefCount = v17 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        v15 = v26;
      }
    }
  }
  v24 = 0i64;
  if ( !(v15 & 1) )
  {
    v18 = v25;
    if ( v25 )
    {
      v19 = v25->RefCount;
      if ( v19 & 0x3FFFFFF )
      {
        v25->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
      }
    }
  }
  v25 = 0i64;
  v21 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
  if ( (signed int)v7 > 0 )
  {
    do
    {
      if ( v13->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v13->pCurrent);
      --v13->pCurrent;
      if ( v13->pCurrent < v13->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v13);
      LODWORD(v7) = v7 - 1;
    }
    while ( (_DWORD)v7 );
  }
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
  return 1;
}

// File Line: 1235
// RVA: 0x71B0D0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ObjectInterface *psrcObj)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v3; // rdi
  __int64 v4; // rsi
  signed __int64 v5; // rbx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v6; // rdi
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-30h]

  v2 = psrcObj;
  v3 = this;
  v8.T.Type = 0;
  v4 = ((__int64 (__cdecl *)(Scaleform::GFx::AS2::AvmCharacter *))this->vfptr[2].GetAbsolutePath)(this) + 232;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, __int64, signed __int64, Scaleform::GFx::AS2::Value *, signed __int64))v2->vfptr->GetMemberRaw)(
         v2,
         v4,
         *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v4 + 40i64) + 24i64) + 928i64,
         &v8,
         -2i64) )
  {
    v5 = (signed __int64)&v3->vfptr;
    v6 = v3->vfptr;
    v7 = Scaleform::GFx::AS2::Value::ToObject(&v8, 0i64);
    v6->Set__proto__((Scaleform::GFx::AS2::ObjectInterface *)v5, (Scaleform::GFx::AS2::ASStringContext *)v4, v7);
  }
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
}

// File Line: 1244
// RVA: 0x723FC0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::VisitMembers(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor, unsigned int visitFlags)
{
  unsigned int v4; // ebp
  Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *v5; // r14
  Scaleform::GFx::AS2::ASStringContext *v6; // r15
  Scaleform::GFx::AS2::AvmCharacter *v7; // rsi
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *v8; // rdi
  __int64 v9; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v11; // rdx
  unsigned int v12; // eax

  v4 = visitFlags;
  v5 = pvisitor;
  v6 = psc;
  v7 = this;
  v8 = &this[-1].EventHandlers;
  v9 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].EntryCount)(&this[-1].EventHandlers);
  v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  if ( v9 )
  {
    v11 = 0i64;
    if ( v8 )
      v11 = v7;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, _QWORD, Scaleform::GFx::AS2::AvmCharacter *))(*(_QWORD *)(v9 + 32) + 64i64))(
      v9 + 32,
      v6,
      v5,
      v4,
      v11);
  }
  if ( v10 )
  {
    v12 = v10->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v10->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
}

// File Line: 1253
// RVA: 0x6E1F80
char __fastcall Scaleform::GFx::AS2::AvmCharacter::DeleteMember(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // r14
  Scaleform::GFx::AS2::AvmCharacter *v5; // rbp
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  __int64 v12; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rbx
  bool v14; // di
  unsigned int v15; // ecx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h]

  v3 = name;
  v4 = psc;
  v5 = this;
  if ( !((name->pNode->HashFlags >> 29) & 1) )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&name->pNode)
      || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&v3->pNode, 0) != 95 )
    {
      goto LABEL_15;
    }
    Scaleform::GFx::ASString::ToLower(v3, &result);
    v6 = result.pNode;
    if ( !((result.pNode->HashFlags >> 28) & 1) )
    {
      v7 = result.pNode->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      goto LABEL_15;
    }
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  }
  v8 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
         (Scaleform::GFx::AS2::AvmCharacter *)((char *)v5 - 8),
         v3);
  v9 = v8;
  if ( v8 != -1 && (signed int)v8 <= 32 )
  {
    v10 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v5[-1].EventHandlers.mHash.pTable[16].SizeMask)(&v5[-1].EventHandlers);
    if ( _bittest(&v10, v9) )
    {
      if ( v9 != 31 )
        return 0;
      *(_DWORD *)&v5->pProto.pObject[1].ArePropertiesSet &= 0xFFFFF9FF;
      return 1;
    }
  }
LABEL_15:
  v12 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v5[-1].EventHandlers.mHash.pTable[12].SizeMask)(&v5[-1].EventHandlers);
  v13 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12;
  if ( v12 )
    *(_DWORD *)(v12 + 24) = (*(_DWORD *)(v12 + 24) + 1) & 0x8FFFFFFF;
  result.pNode = (Scaleform::GFx::ASStringNode *)v12;
  v14 = v12
     && (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_QWORD *)(v12 + 32) + 48i64))(
          v12 + 32,
          v4,
          v3);
  if ( v13 )
  {
    v15 = v13->RefCount;
    if ( v15 & 0x3FFFFFF )
    {
      v13->RefCount = v15 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
    }
  }
  return v14;
}

// File Line: 1285
// RVA: 0x719920
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::SetMemberFlags(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, const char flags)
{
  unsigned __int8 v4; // di
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS2::ASStringContext *v6; // rbp
  __int64 v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  unsigned __int8 v9; // di
  unsigned int v10; // eax

  v4 = flags;
  v5 = name;
  v6 = psc;
  v7 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  if ( v7 )
    v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)(v7 + 32) + 56i64))(
           v7 + 32,
           v6,
           v5,
           v4);
  else
    v9 = 0;
  if ( v8 )
  {
    v10 = v8->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v8->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v9;
}

// File Line: 1294
// RVA: 0x715440
bool __fastcall Scaleform::GFx::AS2::AvmCharacter::SetMember(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::AS2::Value *v4; // r14
  Scaleform::GFx::ASString *v5; // r12
  Scaleform::GFx::AS2::Environment *v6; // r13
  Scaleform::GFx::AS2::AvmCharacter *v7; // rsi
  Scaleform::GFx::ASStringNode *v8; // rcx
  __int64 v9; // rbx
  __int64 v10; // rax
  Scaleform::GFx::AS2::Environment *v11; // rax
  bool v12; // al
  Scaleform::GFx::AS2::Object *v13; // rcx
  Scaleform::GFx::AS2::Object *v14; // rdx
  Scaleform::GFx::MovieImpl *v15; // rcx
  Scaleform::GFx::AS2::Environment *v16; // rax
  bool v17; // al
  __int64 v18; // rdx
  Scaleform::GFx::AS2::Object *v19; // rcx
  Scaleform::GFx::AS2::FunctionObject *v20; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v21; // rbx
  Scaleform::GFx::AS2::Environment *v22; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v23; // rbx
  Scaleform::GFx::AS2::Environment *v24; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v25; // rbx
  Scaleform::GFx::AS2::Environment *v26; // rax
  Scaleform::GFx::AS2::Object *v27; // rax
  Scaleform::GFx::AS2::ObjectInterface *v28; // rax
  __int64 v29; // rbx
  signed __int64 v30; // rdi
  __int64 v31; // r15
  Scaleform::GFx::AS2::Value *v32; // rcx
  float v33; // xmm1_4
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v34; // rbx
  Scaleform::GFx::AS2::Environment *v35; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v36; // rbx
  Scaleform::GFx::AS2::Environment *v37; // rax
  Scaleform::GFx::AS2::Environment *v38; // rax
  unsigned int v39; // eax
  bool v40; // zf
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v41; // rbx
  Scaleform::GFx::AS2::Object *v42; // rax
  __int64 v43; // r10
  __int128 v45; // [rsp+18h] [rbp-41h]
  __int128 v46; // [rsp+28h] [rbp-31h]
  __int128 v47; // [rsp+38h] [rbp-21h]
  __int128 Dst; // [rsp+48h] [rbp-11h]
  __int128 v49; // [rsp+58h] [rbp-1h]
  __int128 v50; // [rsp+68h] [rbp+Fh]
  int v51; // [rsp+84h] [rbp+2Bh]
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+6Fh]
  void *retaddr; // [rsp+D8h] [rbp+7Fh]

  v4 = val;
  v5 = name;
  v6 = penv;
  v7 = this;
  if ( !((name->pNode->HashFlags >> 29) & 1) )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&name->pNode)
      || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&v5->pNode, 0) != 95 )
    {
      goto LABEL_53;
    }
    Scaleform::GFx::ASString::ToLower(v5, &result);
    v8 = result.pNode;
    if ( !((result.pNode->HashFlags >> 28) & 1) )
    {
      v40 = result.pNode->RefCount-- == 1;
      if ( v40 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      goto LABEL_53;
    }
    v40 = result.pNode->RefCount-- == 1;
    if ( v40 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v9 = (unsigned int)Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                       (Scaleform::GFx::AS2::AvmCharacter *)((char *)v7 - 8),
                       v5);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, __int64, Scaleform::GFx::AS2::Value *, _QWORD))v7[-1].EventHandlers.mHash.pTable[17].EntryCount)(
         &v7[-1].EventHandlers,
         v9,
         v4,
         0i64) )
  {
    LOBYTE(v10) = 1;
    return v10;
  }
  switch ( (_DWORD)v9 )
  {
    case 0x59:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v11 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        v12 = Scaleform::GFx::AS2::Value::ToBool(v4, v11);
        v13 = v7->pProto.pObject;
        if ( v12 )
          WORD1(v13[1].pNext) |= 2u;
        else
          WORD1(v13[1].pNext) &= 0xFFFDu;
        v14 = v7->pProto.pObject;
        v15 = *(Scaleform::GFx::MovieImpl **)&v14->vfptr->gap8[8];
        if ( (BYTE2(v14[1].pNext) >> 1) & 1 )
          Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(v15, (Scaleform::GFx::InteractiveObject *)v14);
        else
          Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(v15, (Scaleform::GFx::DisplayObjectBase *)v14);
      }
      break;
    case 0x5A:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v16 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        v17 = Scaleform::GFx::AS2::Value::ToBool(v4, v16);
        v18 = (__int64)v7->pProto.pObject;
        if ( v17 != ((*(_DWORD *)(v18 + 184) >> 2) & 1) )
        {
          if ( v17 )
            *(_DWORD *)(v18 + 184) |= 4u;
          else
            *(_DWORD *)(v18 + 184) &= 0xFFFFFFFB;
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(
            (Scaleform::GFx::InteractiveObject *)v7->pProto.pObject,
            v18);
          v19 = v7->pProto.pObject;
          v20 = v19->ResolveHandler.Function;
          if ( v20 )
          {
            if ( !((*(_DWORD *)&v20[1].ArePropertiesSet >> 2) & 1) )
              ((void (*)(void))v19->vfptr[35].ExecuteForEachChild_GC)();
          }
        }
      }
      break;
    case 0x5B:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1
        && v4->T.Type
        && v4->T.Type != 10 )
      {
        v38 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        v39 = Scaleform::GFx::AS2::Value::ToUInt32(v4, v38);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, _QWORD))v7->pProto.pObject->vfptr[35].Finalize_GC)(
          v7->pProto.pObject,
          v39);
      }
      break;
    case 0x6F:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v23 = v7->pProto.pObject->vfptr;
        v24 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(v4, v24);
        v23[8].Finalize_GC((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->pProto.pObject->vfptr);
      }
      break;
    case 0x70:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v25 = v7->pProto.pObject->vfptr;
        v26 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(v4, v26);
        v25[10].Finalize_GC((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->pProto.pObject->vfptr);
      }
      break;
    case 0x71:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v34 = v7->pProto.pObject->vfptr;
        v35 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(v4, v35);
        v34[11].~RefCountBaseGC<323>((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->pProto.pObject->vfptr);
      }
      break;
    case 0x72:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v36 = v7->pProto.pObject->vfptr;
        v37 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(v4, v37);
        v36[12].Finalize_GC((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->pProto.pObject->vfptr);
      }
      break;
    case 0x73:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v27 = Scaleform::GFx::AS2::Value::ToObject(v4, v6);
        if ( v27 )
        {
          if ( (*(unsigned int (**)(void))&v27->vfptr->gap8[8])() == 7 )
          {
            v28 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, v6);
            v29 = 0i64;
            v30 = (signed __int64)&v28[-2];
            if ( !v28 )
              v30 = 0i64;
            memset(&Dst, 0, 0x40ui64);
            LODWORD(Dst) = 1065353216;
            DWORD1(v49) = 1065353216;
            DWORD2(v50) = 1065353216;
            v51 = 1065353216;
            v31 = *(signed int *)(v30 + 112);
            if ( v31 > 0 )
            {
              do
              {
                v32 = *(Scaleform::GFx::AS2::Value **)(*(_QWORD *)(v30 + 104) + 8 * v29);
                if ( v32 && (unsigned __int8)(v32->T.Type - 3) <= 1u )
                {
                  v33 = Scaleform::GFx::AS2::Value::ToNumber(v32, v6);
                  *((float *)&Dst + v29) = v33;
                }
                ++v29;
              }
              while ( v29 < v31 );
            }
            Scaleform::Render::Matrix4x4<float>::Transpose((Scaleform::Render::Matrix4x4<float> *)&Dst);
            v45 = Dst;
            v46 = v49;
            v47 = v50;
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int128 *))v7->pProto.pObject->vfptr[1].~RefCountBaseGC<323>)(
              v7->pProto.pObject,
              &v45);
          }
        }
        else
        {
          Scaleform::GFx::DisplayObjectBase::Clear3D((Scaleform::GFx::DisplayObjectBase *)v7->pProto.pObject, 0);
        }
      }
      break;
    case 0x74:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v21 = v7->pProto.pObject->vfptr;
        v22 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[15].EntryCount)(&v7[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(v4, v22);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *))v21[13].ExecuteForEachChild_GC)(v7->pProto.pObject);
      }
      break;
    default:
      break;
  }
LABEL_53:
  if ( v6->StringContext.SWFVersion <= 6u )
  {
    if ( !v5->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v5->pNode);
    v40 = v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl->vfptr == (Scaleform::GFx::StateBagVtbl *)v5->pNode->pLower;
  }
  else
  {
    v40 = v5->pNode == (Scaleform::GFx::ASStringNode *)v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl;
  }
  if ( v40 && v4->T.Type != 10 )
  {
    v41 = v7->vfptr;
    v42 = Scaleform::GFx::AS2::Value::ToObject(v4, 0i64);
    (*((void (__fastcall **)(Scaleform::GFx::AS2::AvmCharacter *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))&v41[1].__vecDelDtor
     + 1))(
      v7,
      &v6->StringContext,
      v42);
  }
  v10 = ((__int64 (*)(void))v7[-1].EventHandlers.mHash.pTable[12].SizeMask)();
  if ( v10 )
  {
    v43 = *(_QWORD *)(v10 + 32);
    *((_QWORD *)&v45 + 1) = retaddr;
    LOBYTE(v10) = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(v43 + 24))(
                    v10 + 32,
                    v6,
                    v5,
                    v4);
  }
  return v10;
}

// File Line: 1432
// RVA: 0x6FB400
char __fastcall Scaleform::GFx::AS2::AvmCharacter::HasMember(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, bool inclPrototypes)
{
  bool v4; // r14
  Scaleform::GFx::ASString *v5; // rdi
  Scaleform::GFx::AS2::ASStringContext *v6; // r15
  Scaleform::GFx::AS2::AvmCharacter *v7; // rbp
  Scaleform::GFx::ASStringNode *v8; // rcx
  bool v9; // zf
  signed int v10; // eax
  unsigned int v11; // ebx
  int v12; // eax
  __int64 v14; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rbx
  char v16; // di
  unsigned int v17; // eax
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h]

  v4 = inclPrototypes;
  v5 = name;
  v6 = psc;
  v7 = this;
  if ( !((name->pNode->HashFlags >> 29) & 1) )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&name->pNode)
      || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)&v5->pNode, 0) != 95 )
    {
      goto LABEL_13;
    }
    Scaleform::GFx::ASString::ToLower(v5, &result);
    v8 = result.pNode;
    if ( !((result.pNode->HashFlags >> 28) & 1) )
    {
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      goto LABEL_13;
    }
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  }
  v10 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
          (Scaleform::GFx::AS2::AvmCharacter *)((char *)v7 - 8),
          v5);
  v11 = v10;
  if ( v10 != -1 && v10 <= 32 )
  {
    v12 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[16].SizeMask)(&v7[-1].EventHandlers);
    if ( _bittest(&v12, v11) )
      return 1;
  }
LABEL_13:
  v14 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))v7[-1].EventHandlers.mHash.pTable[12].SizeMask)(&v7[-1].EventHandlers);
  v15 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14;
  if ( v14 )
    *(_DWORD *)(v14 + 24) = (*(_DWORD *)(v14 + 24) + 1) & 0x8FFFFFFF;
  result.pNode = (Scaleform::GFx::ASStringNode *)v14;
  if ( v14 )
    v16 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, bool, signed __int64))(*(_QWORD *)(v14 + 32) + 72i64))(
            v14 + 32,
            v6,
            v5,
            v4,
            -2i64);
  else
    v16 = 0;
  if ( v15 )
  {
    v17 = v15->RefCount;
    if ( v17 & 0x3FFFFFF )
    {
      v15->RefCount = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
    }
  }
  return v16;
}

// File Line: 1450
// RVA: 0x6EB070
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::FindMember(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Member *pmember)
{
  Scaleform::GFx::AS2::Member *v4; // rdi
  Scaleform::GFx::ASString *v5; // rsi
  Scaleform::GFx::AS2::ASStringContext *v6; // rbp
  __int64 v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  unsigned __int8 v9; // di
  unsigned int v10; // eax

  v4 = pmember;
  v5 = name;
  v6 = psc;
  v7 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  if ( v7 )
    v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))(*(_QWORD *)(v7 + 32) + 40i64))(
           v7 + 32,
           v6,
           v5,
           v4);
  else
    v9 = 0;
  if ( v8 )
  {
    v10 = v8->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v8->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v9;
}

// File Line: 1456
// RVA: 0x71E140
void __fastcall Scaleform::GFx::AS2::AvmCharacter::Set__proto__(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *protoObj)
{
  Scaleform::GFx::AS2::Object *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rbp
  Scaleform::GFx::AS2::AvmCharacter *v5; // rsi
  __int64 v6; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rcx
  unsigned int v9; // eax
  unsigned int v10; // eax

  v3 = protoObj;
  v4 = psc;
  v5 = this;
  v6 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6;
  if ( v6 )
    *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  if ( v6 )
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(*(_QWORD *)(v6 + 32) + 104i64))(
      v6 + 32,
      v4,
      v3);
  if ( v3 )
    v3->RefCount = (v3->RefCount + 1) & 0x8FFFFFFF;
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5->vfptr;
  if ( v8 )
  {
    v9 = v8->RefCount;
    if ( v9 & 0x3FFFFFF )
    {
      v8->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)v3;
  if ( v7 )
  {
    v10 = v7->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v7->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
}

// File Line: 1472
// RVA: 0x6FD9D0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::InstanceOf(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Object *prototype, bool inclInterfaces)
{
  bool v4; // di
  Scaleform::GFx::AS2::Object *v5; // rsi
  Scaleform::GFx::AS2::Environment *v6; // rbp
  __int64 v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  unsigned __int8 v9; // di
  unsigned int v10; // eax

  v4 = inclInterfaces;
  v5 = prototype;
  v6 = penv;
  v7 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].EntryCount)(&this[-1].EventHandlers);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  if ( v7 )
    v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *, bool))(*(_QWORD *)(v7 + 32) + 144i64))(
           v7 + 32,
           v6,
           v5,
           v4);
  else
    v9 = 0;
  if ( v8 )
  {
    v10 = v8->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v8->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v9;
}

// File Line: 1478
// RVA: 0x7244E0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::Watch(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *prop, Scaleform::GFx::AS2::FunctionRef *callback, Scaleform::GFx::AS2::Value *userData)
{
  Scaleform::GFx::AS2::FunctionRef *v5; // rdi
  Scaleform::GFx::ASString *v6; // rsi
  Scaleform::GFx::AS2::ASStringContext *v7; // rbp
  __int64 v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rbx
  unsigned __int8 v10; // di
  unsigned int v11; // eax

  v5 = callback;
  v6 = prop;
  v7 = psc;
  v8 = ((__int64 (*)(void))this[-1].EventHandlers.mHash.pTable[12].SizeMask)();
  v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8;
  if ( v8 )
    *(_DWORD *)(v8 + 24) = (*(_DWORD *)(v8 + 24) + 1) & 0x8FFFFFFF;
  if ( v8 )
    v10 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v8 + 32) + 152i64))(
            v8 + 32,
            v7,
            v6,
            v5,
            userData);
  else
    v10 = 0;
  if ( v9 )
  {
    v11 = v9->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v9->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  return v10;
}

// File Line: 1484
// RVA: 0x722C60
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::Unwatch(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::ASString *prop)
{
  Scaleform::GFx::ASString *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rsi
  __int64 v5; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rbx
  unsigned __int8 v7; // di
  unsigned int v8; // eax

  v3 = prop;
  v4 = psc;
  v5 = ((__int64 (__cdecl *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5;
  if ( v5 )
    *(_DWORD *)(v5 + 24) = (*(_DWORD *)(v5 + 24) + 1) & 0x8FFFFFFF;
  if ( v5 )
    v7 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_QWORD *)(v5 + 32) + 160i64))(
           v5 + 32,
           v4,
           v3);
  else
    v7 = 0;
  if ( v6 )
  {
    v8 = v6->RefCount;
    if ( v8 & 0x3FFFFFF )
    {
      v6->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return v7;
}

// File Line: 1494
// RVA: 0x706010
void __fastcall Scaleform::GFx::AS2::AvmCharacter::OnFocus(Scaleform::GFx::AS2::AvmCharacter *this, Scaleform::GFx::InteractiveObject::FocusEventType *event, Scaleform::GFx::InteractiveObject *oldOrNewFocusCh, unsigned int controllerIdx)
{
  signed int v4; // er14
  Scaleform::GFx::InteractiveObject *v5; // r15
  int v6; // edi
  Scaleform::GFx::AS2::AvmCharacter *v7; // r12
  __int64 v8; // rax
  Scaleform::GFx::AS2::Environment *v9; // rsi
  signed __int64 NargsIn; // rdi
  __int64 v11; // rax
  char v12; // r14
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v14; // rbx
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rax
  Scaleform::GFx::DisplayObject *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rax
  __int64 v19; // rax
  char v20; // al
  Scaleform::GFx::AS2::FunctionObject *v21; // rcx
  unsigned int v22; // edx
  Scaleform::GFx::AS2::LocalFrame *v23; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  bool v26; // zf
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+30h] [rbp-A8h]
  Scaleform::GFx::AS2::Value *v28; // [rsp+48h] [rbp-90h]
  Scaleform::GFx::AS2::Value *v29; // [rsp+50h] [rbp-88h]
  Scaleform::GFx::AS2::Value v; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::AS2::Value v31; // [rsp+78h] [rbp-60h]
  Scaleform::GFx::AS2::FnCall v32; // [rsp+98h] [rbp-40h]
  Scaleform::GFx::ASStringNode *v33; // [rsp+118h] [rbp+40h]

  *((_QWORD *)&v31.NV + 3) = -2i64;
  v4 = controllerIdx;
  v5 = oldOrNewFocusCh;
  v6 = (signed int)event;
  v7 = this;
  v31.T.Type = 0;
  v8 = ((__int64 (*)(void))this->vfptr[2].GetAbsolutePath)();
  v9 = (Scaleform::GFx::AS2::Environment *)v8;
  if ( v8 )
  {
    v33 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 232) + 40i64) + 24i64)
                                           + 8i64 * (v6 != 1)
                                           + 1016);
    ++v33->RefCount;
    if ( v7->vfptr->GetMemberRaw(
           (Scaleform::GFx::AS2::ObjectInterface *)&v7->vfptr,
           (Scaleform::GFx::AS2::ASStringContext *)(v8 + 232),
           (Scaleform::GFx::ASString *)&v33,
           &v31) )
    {
      Scaleform::GFx::AS2::Value::ToFunction(&v31, &result, 0i64);
      if ( result.Function )
      {
        NargsIn = 1i64;
        if ( v9->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          ++v9->Stack.pCurrent;
          if ( v9->Stack.pCurrent >= v9->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
          v11 = (__int64)v9->Stack.pCurrent;
          v28 = (Scaleform::GFx::AS2::Value *)v11;
          v29 = (Scaleform::GFx::AS2::Value *)v11;
          if ( v11 )
          {
            *(_BYTE *)v11 = 3;
            *(double *)(v11 + 8) = (double)v4;
          }
          NargsIn = 2i64;
        }
        if ( v5 )
        {
          v12 = 7;
          v.T.Type = 7;
          v13 = (Scaleform::GFx::ASStringNode *)v5->pNameHandle.pObject;
          if ( !v13 )
            v13 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v5->vfptr);
          v.V.pStringNode = v13;
          if ( v13 )
            ++LODWORD(v13->pData);
          v14 = &v9->Stack;
          ++v14->pCurrent;
          if ( v9->Stack.pCurrent >= v9->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
          v15 = v14->pCurrent;
          v29 = v15;
          v28 = v15;
          if ( v15 )
          {
            Scaleform::GFx::AS2::Value::Value(v15, &v, NargsIn);
            v12 = v.T.Type;
          }
          if ( (unsigned __int8)v12 >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        else
        {
          v14 = &v9->Stack;
          ++v14->pCurrent;
          if ( v9->Stack.pCurrent >= v9->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
          v16 = v14->pCurrent;
          v29 = v16;
          v28 = v16;
          if ( v16 )
            v16->T.Type = 1;
        }
        v.V.FunctionValue.Flags = 0;
        v17 = (Scaleform::GFx::DisplayObject *)&v7->pDispObj->vfptr;
        v.T.Type = 7;
        if ( v17 )
        {
          v18 = (Scaleform::GFx::ASStringNode *)v17->pNameHandle.pObject;
          if ( !v18 )
            v18 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v17);
          v.V.pStringNode = v18;
          if ( v18 )
            ++LODWORD(v18->pData);
        }
        else
        {
          v.V.pStringNode = 0i64;
        }
        Scaleform::GFx::AS2::FnCall::FnCall(
          &v32,
          (Scaleform::GFx::AS2::Value *)((char *)&v + 24),
          &v,
          v9,
          NargsIn,
          32 * v14->Pages.Data.Size - 32 + ((_QWORD)((char *)v14->pCurrent - (char *)v14->pPageStart) >> 5));
        ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, __int64, Scaleform::GFx::AS2::LocalFrame *, _QWORD))result.Function->vfptr[3].Finalize_GC)(
          result.Function,
          v19,
          result.pLocalFrame,
          0i64);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v32);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        for ( ; (_DWORD)NargsIn; LODWORD(NargsIn) = NargsIn - 1 )
        {
          if ( v14->pCurrent->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v14->pCurrent);
          --v14->pCurrent;
          if ( v14->pCurrent < v14->pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v14);
        }
        if ( v.V.FunctionValue.Flags >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v + 24));
      }
      v20 = result.Flags;
      if ( !(result.Flags & 2) )
      {
        v21 = result.Function;
        if ( result.Function )
        {
          v22 = result.Function->RefCount;
          if ( v22 & 0x3FFFFFF )
          {
            result.Function->RefCount = v22 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v21->vfptr);
            v20 = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( !(v20 & 1) )
      {
        v23 = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v24 = result.pLocalFrame->RefCount;
          if ( v24 & 0x3FFFFFF )
          {
            result.pLocalFrame->RefCount = v24 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v23->vfptr);
          }
        }
      }
      result.pLocalFrame = 0i64;
    }
    v25 = v33;
    v26 = v33->RefCount == 1;
    --v25->RefCount;
    if ( v26 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  }
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
}

// File Line: 1526
// RVA: 0x6F71D0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetTopParent(Scaleform::GFx::AS2::AvmCharacter *this, __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // r8
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::GFx::InteractiveObject *result; // rax

  v2 = this->pDispObj;
  v3 = v2->pParent;
  if ( v3 && v3->pASRoot->AVMVersion == 1 )
    result = (Scaleform::GFx::InteractiveObject *)v3->vfptr[68].__vecDelDtor(
                                                    (Scaleform::RefCountNTSImplCore *)&v3->vfptr,
                                                    ignoreLockRoot);
  else
    result = v2;
  return result;
}

// File Line: 1534
// RVA: 0x6EE6C0
Scaleform::GFx::AS2::AvmCharacter *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetAvmTopParent(Scaleform::GFx::AS2::AvmCharacter *this, __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // rcx
  __int64 v4; // rax

  v2 = this->pDispObj->pParent;
  if ( v2->pASRoot->AVMVersion != 1 )
    return 0i64;
  v4 = (__int64)v2->vfptr[68].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, ignoreLockRoot);
  return (Scaleform::GFx::AS2::AvmCharacter *)(v4 + 4i64 * *(unsigned __int8 *)(v4 + 109));
}

// File Line: 1542
// RVA: 0x700CA0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::IsTabable(Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::AS2::AvmCharacter *v1; // rbx
  __int64 v2; // rax
  int v3; // ecx
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rax
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::ASString *v7; // rax
  _BOOL8 v8; // rdi
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  bool v11; // bl
  Scaleform::GFx::InteractiveObject *v12; // rcx
  unsigned __int8 v13; // al
  __int64 v14; // rax
  Scaleform::GFx::AS2::Value v15; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = ((__int64 (__cdecl *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[59].__vecDelDtor)(this->pDispObj);
  if ( !(_BYTE)v2 )
    return v2;
  v3 = v1->pDispObj->Flags & 0x60;
  if ( v3 )
    return v3 == 96;
  v4 = v1->pProto.pObject;
  if ( v4 )
  {
    v15.T.Type = 0;
    v5 = (Scaleform::GFx::AS2::Environment *)v1->vfptr[2].ToAvmDispContainerBase((Scaleform::GFx::AvmDisplayObjBase *)&v1->vfptr);
    v6 = v5;
    v7 = Scaleform::GFx::AS2::Environment::CreateConstString(v5, &result, "tabEnabled");
    v8 = v4->vfptr->GetMemberRaw((Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr, &v6->StringContext, v7, &v15);
    v9 = result.pNode;
    v10 = result.pNode->RefCount == 1;
    --v9->RefCount;
    if ( v10 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v9);
    if ( (_BYTE)v8 && v15.T.Type && v15.T.Type != 10 )
    {
      v11 = Scaleform::GFx::AS2::Value::ToBool(&v15, v6);
      if ( v15.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v15);
      return v11;
    }
    if ( v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
  }
  v12 = v1->pDispObj;
  v13 = v12->AvmObjOffset;
  v2 = v13
    && (v14 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v12->vfptr + 4 * v13))[1].__vecDelDtor)(),
        (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v14 + 96i64))(v14))
    || v1->pDispObj->TabIndex > 0;
  return v2;
}

// File Line: 1572
// RVA: 0x6C9070
void __fastcall Scaleform::GFx::AS2::GenericDisplayObj::GenericDisplayObj(Scaleform::GFx::AS2::GenericDisplayObj *this, Scaleform::GFx::CharacterDef *pdef, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::CharacterDef *v5; // rsi
  Scaleform::GFx::AS2::GenericDisplayObj *v6; // rdi

  v5 = pdef;
  v6 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::GenericDisplayObj::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS2::GenericDisplayObj::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( v5 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&v5->vfptr);
  v6->pDef.pObject = (Scaleform::GFx::ShapeBaseCharacterDef *)v5;
}

// File Line: 1580
// RVA: 0x6F7190
__int64 __fastcall Scaleform::GFx::AS2::GenericDisplayObj::GetTopMostMouseEntity(Scaleform::GFx::AS2::GenericDisplayObj *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rax

  v3 = pdescr;
  v4 = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
         (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
         (Scaleform::GFx::CharacterDef *)&this->pDef.pObject->vfptr,
         pt,
         pdescr->TestAll,
         pdescr->pIgnoreMC);
  v3->pResult = v4;
  return 2 - (unsigned int)(v4 != 0i64);
}

// File Line: 1588
// RVA: 0x708330
__int64 __fastcall Scaleform::GFx::AS2::GenericDisplayObj::PointTestLocal(Scaleform::GFx::AS2::GenericDisplayObj *this, Scaleform::Render::Point<float> *pt, __int64 hitTestMask)
{
  LOBYTE(hitTestMask) = hitTestMask & 1;
  return ((__int64 (__fastcall *)(Scaleform::GFx::ShapeBaseCharacterDef *, Scaleform::Render::Point<float> *, __int64, Scaleform::GFx::AS2::GenericDisplayObj *))this->pDef.pObject->vfptr[1].GetResourceTypeCode)(
           this->pDef.pObject,
           pt,
           hitTestMask,
           this);
}

// File Line: 1593
// RVA: 0x6E1070
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::AS2::GenericDisplayObj::CreateRenderNode(Scaleform::GFx::AS2::GenericDisplayObj *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v3; // rdi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v4; // rsi
  Scaleform::GFx::ShapeBaseCharacterDef *v5; // rbx
  Scaleform::GFx::MovieDefImpl *v6; // rax

  v3 = context;
  v4 = result;
  v5 = this->pDef.pObject;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__cdecl *)(Scaleform::GFx::AS2::GenericDisplayObj *, Scaleform::Ptr<Scaleform::Render::TreeNode> *))this->vfptr[66].__vecDelDtor)(
                                         this,
                                         result);
  Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(v5, v4, v3, v6);
  return v4;
}

// File Line: 1598
// RVA: 0x6F5070
float __fastcall Scaleform::GFx::AS3::ShapeObject::GetRatio(Scaleform::GFx::AS2::GenericDisplayObj *this)
{
  Scaleform::Render::TreeNode *v1; // r9
  float result; // xmm0_4

  v1 = this->pRenNode.pObject;
  if ( v1
    && *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                            + 8
                            * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                                                      - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                             + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                                                                  - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                            + 40)
                + 8i64) == 3 )
  {
    result = *(float *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                  + 8
                                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1] - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                                                            - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                  + 40)
                      + 152i64);
  }
  else
  {
    result = 0.0;
  }
  return result;
}

// File Line: 1610
// RVA: 0x71B280
void __fastcall Scaleform::GFx::AS3::ShapeObject::SetRatio(Scaleform::GFx::AS2::GenericDisplayObj *this, float f)
{
  Scaleform::GFx::AS2::GenericDisplayObj *v2; // rbx
  unsigned __int64 v3; // rax
  unsigned __int64 v4; // rdx

  v2 = this;
  v3 = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  if ( v3 )
  {
    v4 = (signed __int64)((unsigned __int128)((signed __int64)(v3 - (v3 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4;
    if ( *(_WORD *)(*(_QWORD *)(*(_QWORD *)((v3 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8 * ((unsigned int)v4 + (v4 >> 63))
                              + 40)
                  + 8i64) == 3 )
      *(float *)&Scaleform::Render::ContextImpl::Entry::getWritableData(
                   (Scaleform::Render::ContextImpl::Entry *)&v2->pRenNode.pObject->0,
                   0x10u)[9].Type = f;
  }
}

