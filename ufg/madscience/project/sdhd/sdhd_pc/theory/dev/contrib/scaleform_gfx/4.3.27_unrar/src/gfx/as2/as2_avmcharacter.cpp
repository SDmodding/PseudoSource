// File Line: 18
// RVA: 0x6C7620
void __fastcall Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::InteractiveObject *pdispObj)
{
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  this->pProto.pObject = 0i64;
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pDispObj = pdispObj;
  this->EventHandlers.mHash.pTable = 0i64;
  Scaleform::GFx::DisplayObjectBase::BindAvmObj(pdispObj, this);
}

// File Line: 23
// RVA: 0x6D0ED0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::~AvmCharacter(Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::AS2::ObjectInterface *v2; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  unsigned int RefCount; // eax

  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v2 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmCharacter::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Clear(&this->EventHandlers.mHash);
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable;
  pObject = v2->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
}

// File Line: 28
// RVA: 0x6EE2B0
Scaleform::GFx::AS2::Environment *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetASEnvironment(
        Scaleform::GFx::AS2::AvmCharacter *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rax
  char *v3; // rcx

  pParent = this->pDispObj->pParent;
  if ( !pParent )
    return 0i64;
  while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
  {
    pParent = pParent->pParent;
    if ( !pParent )
      return 0i64;
  }
  v3 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
  return (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v3 + 240i64))(v3);
}

// File Line: 38
// RVA: 0x6EE2F0
void __fastcall VariableIntArrayImplementation::setAll(
        VariableIntArrayImplementation *this,
        const unsigned __int64 *in,
        __int64 size)
{
  ((void (__fastcall *)(VariableIntArrayImplementation *, const unsigned __int64 *, __int64))this->vfptr[30].__vecDelDtor)(
    this,
    in,
    size);
}

// File Line: 59
// RVA: 0x6EE350
const char *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetAbsolutePath(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::String *ppath)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // rax
  Scaleform::GFx::DisplayObject *pParent; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::AvmCharacter *v9; // rcx
  Scaleform::MsgFormat::Sink r; // [rsp+20h] [rbp-428h] BYREF
  __int64 v12; // [rsp+38h] [rbp-410h]
  Scaleform::MsgFormat v13; // [rsp+40h] [rbp-408h] BYREF
  Scaleform::GFx::ASString result; // [rsp+450h] [rbp+8h] BYREF

  v12 = -2i64;
  pDispObj = this->pDispObj;
  pParent = pDispObj->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pParent, ppath);
    Scaleform::String::AppendString(ppath, ".", -1i64);
    Name = Scaleform::GFx::AS3::AvmDisplayObj::GetName(this, &result);
    Scaleform::String::AppendString(ppath, Name->pNode->pData, -1i64);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else if ( (pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
  {
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&this->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&this->Scaleform::GFx::AS2::ObjectInterface) == 2 )
      v9 = this;
    else
      v9 = 0i64;
    LODWORD(result.pNode) = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))v9[1].Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(&v9[1]);
    r.Type = tStr;
    r.SinkData.pStr = ppath;
    Scaleform::MsgFormat::MsgFormat(&v13, &r);
    Scaleform::MsgFormat::Parse(&v13, "_level{0}");
    Scaleform::MsgFormat::FormatD1<long>(&v13, (int *)&result);
    Scaleform::MsgFormat::FinishFormatD(&v13);
    Scaleform::MsgFormat::~MsgFormat(&v13);
  }
  else
  {
    Scaleform::String::Clear(ppath);
  }
  return (const char *)((ppath->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
}

// File Line: 90
// RVA: 0x6EFB30
Scaleform::RefCountImplCoreVtbl *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetGC(
        Scaleform::GFx::AS2::AvmCharacter *this)
{
  return this->pDispObj->pASRoot[2].vfptr;
}

// File Line: 99
// RVA: 0x6B2B80
void __fastcall Scaleform::GFx::AS2::AvmCharacter::CharacterGetDepth(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdi
  Scaleform::GFx::InteractiveObject *vfptr; // rax
  Scaleform::GFx::AS2::Value *Result; // rbx
  int Depth; // edi

  ThisPtr = fn->ThisPtr;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) - 2 > 3 )
    vfptr = 0i64;
  else
    vfptr = (Scaleform::GFx::InteractiveObject *)ThisPtr[1].vfptr;
  if ( !vfptr )
    vfptr = fn->Env->Target;
  Result = fn->Result;
  Depth = vfptr->Depth;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 4;
  Result->NV.Int32Value = Depth - 0x4000;
}

// File Line: 257
// RVA: 0x6FD3D0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::InitStandardMembers(Scaleform::GFx::AS2::GlobalContext *pcontext)
{
  Scaleform::RefCountImplCoreVtbl *vfptr; // rsi
  Scaleform::GFx::ASStringHash<char> *p_StandardMemberMap; // rdi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // rax
  Scaleform::GFx::AS2::AvmCharacter::MemberTableType *v4; // rbx
  const char *pName; // r8
  unsigned __int64 v6; // r9
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef key; // [rsp+38h] [rbp-20h] BYREF
  char Id; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF

  vfptr = pcontext->pMovieRoot->pASMovieRoot.pObject[39].vfptr;
  p_StandardMemberMap = &pcontext->StandardMemberMap;
  pTable = pcontext->StandardMemberMap.mHash.pTable;
  if ( !pTable || pTable->EntryCount < 0x93 )
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::setRawCapacity(
      &pcontext->StandardMemberMap.mHash,
      &pcontext->StandardMemberMap,
      0x93ui64);
  v4 = Scaleform::GFx::AS2::AvmCharacter::MemberTable;
  if ( Scaleform::GFx::AS2::AvmCharacter::MemberTable[0].pName )
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
        (v4->CaseInsensitive ? 0x10000000 : 0) | 0x20000000);
      Id = v4->Id;
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeRef>(
        &p_StandardMemberMap->mHash,
        p_StandardMemberMap,
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

// File Line: 298
// RVA: 0x6F63B0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::ASStringNode *memberName)
{
  char v4; // bp
  Scaleform::GFx::ASStringNode *v5; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rsi
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v10; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > v11; // r14
  __int64 v12; // rax
  unsigned __int64 *v13; // rcx
  signed __int64 v14; // rax
  __int64 v15; // rdx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [rsp+58h] [rbp+10h]

  v4 = -1;
  v5 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this)
                                                                + 40)
                                                    + 24i64)
                                        + 312i64);
  v18 = v5;
  ++v5->RefCount;
  if ( (*((_DWORD *)memberName->pData + 7) & 0x20000000) != 0 )
  {
LABEL_11:
    v10 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this) + 112);
    if ( v5->Size )
    {
      result.pNode = memberName;
      if ( !*((_QWORD *)memberName->pData + 2) )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl((Scaleform::GFx::ASStringNode *)memberName->pData);
      if ( v10->pTable )
      {
        v14 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,char,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
                v10,
                (Scaleform::GFx::ASString::NoCaseKey *)&result,
                *((unsigned int *)memberName->pData + 7) & v10->pTable->SizeMask);
        if ( v14 >= 0 )
        {
          v15 = (__int64)(&v10->pTable[1].SizeMask + 3 * v14);
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
                (Scaleform::GFx::ASString *)memberName,
                *((unsigned int *)memberName->pData + 7) & v11.pTable->SizeMask);
        if ( v12 >= 0 )
        {
          v13 = &v11.pTable[1].SizeMask + 3 * v12;
          if ( v13 )
            v4 = *((_BYTE *)v13 + 8);
        }
      }
    }
    goto LABEL_22;
  }
  if ( !Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)memberName)
    || Scaleform::GFx::ASConstString::GetCharAt((Scaleform::GFx::ASConstString *)memberName, 0) != 95 )
  {
    goto LABEL_22;
  }
  Scaleform::GFx::ASString::ToLower((Scaleform::GFx::ASString *)memberName, &result);
  pNode = result.pNode;
  if ( (result.pNode->HashFlags & 0x10000000) != 0 )
  {
    ++result.pNode->RefCount;
    v7 = v5->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v5 = pNode;
    v18 = pNode;
    v8 = result.pNode;
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    goto LABEL_11;
  }
  v9 = result.pNode;
  v7 = result.pNode->RefCount-- == 1;
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
bool __fastcall Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        unsigned int member,
        Scaleform::GFx::AS2::Value *val,
        bool opcodeFlag)
{
  __int64 v5; // rbx
  int v7; // eax
  Scaleform::GFx::AS2::Environment *v8; // rax
  Scaleform::GFx::AS2::Environment *v9; // rbp
  bool v10; // al
  long double v11; // xmm0_8
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbx
  bool v13; // al
  unsigned int v14; // r9d
  char **i; // r10
  unsigned __int8 *v16; // rax
  int v17; // ecx
  int v18; // edx
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  int v22; // eax
  int v23; // edx
  unsigned int v24; // r9d
  Scaleform::GFx::ASString *v25; // rax
  bool v26; // al
  Scaleform::GFx::InteractiveObject *v27; // rcx
  bool v28; // al
  Scaleform::GFx::InteractiveObject *v29; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::AS2::Environment *v31; // rax
  bool v32; // al
  Scaleform::GFx::InteractiveObject *v33; // rcx
  Scaleform::GFx::AS2::Environment *v34; // rax
  Scaleform::GFx::AS2::Environment *v35; // rax
  bool v36; // al
  Scaleform::GFx::InteractiveObject *pDispObj; // rcx
  Scaleform::GFx::AS2::Environment *v38; // rax
  bool v39; // al
  Scaleform::GFx::InteractiveObject *v40; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v41; // rbx
  Scaleform::GFx::AS2::Environment *v42; // rax
  bool v43; // al
  Scaleform::Render::EdgeAAMode v44; // ebx
  Scaleform::GFx::AS2::Environment *v45; // rax
  double v46; // xmm0_8
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::String v48; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v50; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v51; // [rsp+38h] [rbp-20h] BYREF
  __int64 v52; // [rsp+40h] [rbp-18h]

  v52 = -2i64;
  v5 = (int)member;
  if ( opcodeFlag && member > 0x15 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptError(
      &this->pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "Invalid SetProperty request, property number %d",
      member);
    return 0;
  }
  if ( member == -1 )
    return 0;
  if ( (int)member > 32 )
    return 0;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].OnEventLoad)(this);
  if ( !_bittest(&v7, v5) )
    return 0;
  v8 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v9 = v8;
  switch ( (int)v5 )
  {
    case 0:
      if ( val->T.Type )
      {
        if ( val->T.Type != 10 )
        {
          Scaleform::GFx::AS2::Value::ToNumber(val, v8);
          ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[21].__vecDelDtor)(this->pDispObj);
        }
      }
      return 1;
    case 1:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[23].__vecDelDtor)(this->pDispObj);
      return 1;
    case 2:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[27].__vecDelDtor)(this->pDispObj);
      return 1;
    case 3:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[29].__vecDelDtor)(this->pDispObj);
      return 1;
    case 4:
    case 5:
    case 11:
    case 12:
    case 14:
    case 15:
    case 20:
    case 21:
    case 22:
      Name = Scaleform::GFx::DisplayObject::GetName(this->pDispObj, &v51);
      Scaleform::GFx::AS2::Environment::LogScriptWarning(
        v9,
        "Attempt to write read-only property %s.%s, ignored",
        Name->pNode->pData,
        Scaleform::GFx::AS2::AvmCharacter::MemberTable[v5].pName);
      pNode = v51.pNode;
      goto LABEL_48;
    case 6:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      v11 = Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      Scaleform::GFx::DisplayObjectBase::SetAlpha(this->pDispObj, v11);
      return 1;
    case 7:
      vfptr = this->pDispObj->vfptr;
      v13 = Scaleform::GFx::AS2::Value::ToBool(val, v8);
      vfptr[58].__vecDelDtor(this->pDispObj, v13);
      return 1;
    case 8:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[45].__vecDelDtor)(this->pDispObj);
      return 1;
    case 9:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[47].__vecDelDtor)(this->pDispObj);
      return 1;
    case 10:
      if ( !val->T.Type || val->T.Type == 10 )
        return 1;
      Scaleform::GFx::AS2::Value::ToNumber(val, v8);
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[33].__vecDelDtor)(this->pDispObj);
      return 1;
    case 13:
      v25 = Scaleform::GFx::AS2::Value::ToString(val, &v50, v8, -1);
      Scaleform::GFx::DisplayObject::SetName(this->pDispObj, v25);
      pNode = v50.pNode;
      goto LABEL_48;
    case 16:
    case 18:
    case 19:
    case 25:
      return 1;
    case 17:
      if ( !val->T.Type || val->T.Type == 10 )
      {
        this->pDispObj->Flags &= 0xFFFFFF9F;
      }
      else
      {
        v35 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        v36 = Scaleform::GFx::AS2::Value::ToBool(val, v35);
        pDispObj = this->pDispObj;
        if ( v36 )
        {
          pDispObj->Flags |= 0x180u;
        }
        else
        {
          pDispObj->Flags &= ~0x80u;
          pDispObj->Flags |= 0x100u;
        }
      }
      _((AMD_HD3D *)this->pDispObj);
      return 1;
    case 23:
      if ( val->T.Type == 5 )
      {
        Scaleform::GFx::AS2::Value::ToString(val, &result, v8, -1);
        Scaleform::String::String(&v48, result.pNode->pData);
        v14 = 1;
        for ( i = off_142093B18; ; ++i )
        {
          v16 = (unsigned __int8 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
          do
          {
            v17 = (unsigned __int8)(*i)[(_QWORD)v16 - 12 - (v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)];
            v18 = *v16 - v17;
            if ( v18 )
              break;
            ++v16;
          }
          while ( v17 );
          if ( !v18 )
            break;
          if ( ++v14 >= 0xF )
          {
            if ( !_InterlockedDecrement((volatile signed __int32 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            v19 = result.pNode;
            v20 = result.pNode->RefCount-- == 1;
            if ( v20 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v19);
            return 1;
          }
        }
        this->pDispObj->vfptr[16].__vecDelDtor(this->pDispObj, v14);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v48.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pNode = result.pNode;
LABEL_48:
        v20 = pNode->RefCount-- == 1;
        if ( !v20 )
          return 1;
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v10 = 1;
      }
      else
      {
        v22 = (int)Scaleform::GFx::AS2::Value::ToNumber(val, v8);
        v23 = 14;
        if ( v22 < 14 )
          v23 = v22;
        v24 = 1;
        if ( v23 > 1 )
          v24 = v23;
        this->pDispObj->vfptr[16].__vecDelDtor(this->pDispObj, v24);
        v10 = 1;
      }
      break;
    case 24:
      v41 = this->pDispObj->vfptr;
      v42 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
      v43 = Scaleform::GFx::AS2::Value::ToBool(val, v42);
      v41[55].__vecDelDtor(this->pDispObj, v43);
      return 1;
    case 26:
      v26 = Scaleform::GFx::AS2::Value::ToBool(val, v8);
      v27 = this->pDispObj;
      if ( v26 )
        v27->Flags |= 0x10u;
      else
        v27->Flags &= ~0x10u;
      return 1;
    case 27:
      v28 = Scaleform::GFx::AS2::Value::ToBool(val, v8);
      v29 = this->pDispObj;
      if ( v28 )
        v29->Flags |= 0x4000u;
      else
        v29->Flags &= ~0x4000u;
      return 1;
    case 29:
      if ( !val->T.Type || val->T.Type == 10 )
      {
        this->pDispObj->Flags &= 0xFFFFFF9F;
      }
      else
      {
        v31 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        v32 = Scaleform::GFx::AS2::Value::ToBool(val, v31);
        v33 = this->pDispObj;
        if ( v32 )
        {
          v33->Flags |= 0x60u;
        }
        else
        {
          v33->Flags &= ~0x20u;
          v33->Flags |= 0x40u;
        }
      }
      return 1;
    case 30:
      v34 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
      this->pDispObj->TabIndex = (int)Scaleform::GFx::AS2::Value::ToNumber(val, v34);
      return 1;
    case 31:
      if ( !val->T.Type || val->T.Type == 10 )
      {
        this->pDispObj->Flags &= 0xFFFFF9FF;
      }
      else
      {
        v38 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
        v39 = Scaleform::GFx::AS2::Value::ToBool(val, v38);
        v40 = this->pDispObj;
        if ( v39 )
        {
          v40->Flags |= 0x600u;
        }
        else
        {
          v40->Flags &= ~0x200u;
          v40->Flags |= 0x400u;
        }
      }
      return 1;
    case 32:
      v44 = EdgeAA_Inherit;
      v45 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
      v46 = (double)Scaleform::GFx::AS2::Value::ToInt32(val, v45);
      if ( v46 == 3.0 )
      {
        v44 = EdgeAA_Disable;
      }
      else if ( v46 == 1.0 )
      {
        v44 = EdgeAA_On;
      }
      else if ( v46 == 2.0 )
      {
        v44 = EdgeAA_Off;
      }
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this->pDispObj);
      Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, v44);
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
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::AvmCharacter::CloneDisplayObject(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::ASString *newname,
        unsigned int depth,
        Scaleform::GFx::AS2::ObjectInterface *psource)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // rcx
  __int64 v7; // r14
  Scaleform::GFx::InteractiveObject *pParent; // r15
  __int16 ClipDepth; // si
  int Id; // ebx
  double v11; // xmm0_8
  int *v12; // rdi
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // r10
  __int64 v14; // rax
  Scaleform::Render::Cxform v16; // [rsp+28h] [rbp-59h] BYREF
  int v17; // [rsp+48h] [rbp-39h]
  int v18; // [rsp+4Ch] [rbp-35h]
  int v19; // [rsp+50h] [rbp-31h]
  int v20; // [rsp+54h] [rbp-2Dh]
  int v21; // [rsp+58h] [rbp-29h]
  int v22; // [rsp+5Ch] [rbp-25h]
  int v23; // [rsp+60h] [rbp-21h]
  int v24; // [rsp+64h] [rbp-1Dh]
  Scaleform::Render::RenderBuffer *v25; // [rsp+68h] [rbp-19h]
  int v26; // [rsp+70h] [rbp-11h]
  unsigned int v27; // [rsp+74h] [rbp-Dh]
  int v28; // [rsp+78h] [rbp-9h]
  __int64 v29; // [rsp+80h] [rbp-1h]
  __int16 v30; // [rsp+88h] [rbp+7h]
  int v31; // [rsp+8Ah] [rbp+9h]
  __int64 v32; // [rsp+F0h] [rbp+6Fh]
  __int64 v33; // [rsp+100h] [rbp+7Fh]

  pDispObj = this->pDispObj;
  v7 = 0i64;
  pParent = 0i64;
  if ( (pDispObj->pParent->Flags & 0x400) != 0 )
    pParent = pDispObj->pParent;
  if ( !pParent || depth > 0x7EFFFFFD )
    return 0i64;
  ClipDepth = pDispObj->ClipDepth;
  Id = pDispObj->Id.Id;
  v11 = ((double (__fastcall *)(Scaleform::GFx::InteractiveObject *))pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[17].__vecDelDtor)(pDispObj);
  v12 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[2].__vecDelDtor)(this->pDispObj);
  v16 = *Scaleform::GFx::DisplayObjectBase::GetCxform(this->pDispObj);
  v17 = *v12;
  v18 = v12[1];
  v19 = v12[2];
  v20 = v12[3];
  v21 = v12[4];
  v22 = v12[5];
  v23 = v12[6];
  v24 = v12[7];
  v25 = 0i64;
  v26 = LODWORD(v11);
  v31 = 16777228;
  v27 = depth;
  v28 = Id;
  v30 = ClipDepth;
  v29 = 0i64;
  vfptr = pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
  *(_QWORD *)&v16.M[1][2] = this->pDispObj;
  *(_QWORD *)&v16.M[1][0] = 0i64;
  LODWORD(v16.M[0][2]) = 1;
  v16.M[0][0] = NAN;
  v14 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, __int64, _QWORD, __int64))vfptr[118].__vecDelDtor)(
          pParent,
          &v16,
          v32,
          0i64,
          v33);
  if ( v14 && *(char *)(v14 + 106) < 0 )
    v7 = v14;
  if ( v25 )
    Scaleform::RefCountImpl::Release(v25);
  return (Scaleform::GFx::InteractiveObject *)v7;
}

// File Line: 967
// RVA: 0x6FB0D0
bool __fastcall Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::EventId *id)
{
  unsigned int v2; // eax
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *p_EventHandlers; // rdi
  signed __int64 v4; // rax
  __int64 v5; // rax
  Scaleform::GFx::EventId key; // [rsp+20h] [rbp-28h] BYREF

  v2 = id->Id - 64;
  key.Id = id->Id;
  if ( (v2 & 0xFFFFFFBF) != 0 )
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
  p_EventHandlers = &this->EventHandlers;
  v4 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::findIndexAlt<Scaleform::GFx::EventId>(
         &this->EventHandlers.mHash,
         &key);
  return v4 >= 0 && (v5 = (__int64)&p_EventHandlers->mHash.pTable[4 * v4 + 2]) != 0 && v5 != -24;
}

// File Line: 973
// RVA: 0x6FF6B0
char __fastcall Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::EventId *id)
{
  unsigned int v4; // eax
  signed __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> >::TableType *v7; // rbx
  unsigned __int64 *p_SizeMask; // rbx
  unsigned __int64 v9; // rsi
  __int64 v10; // r14
  Scaleform::GFx::EventId key; // [rsp+40h] [rbp-38h] BYREF

  v4 = id->Id - 64;
  key.Id = id->Id;
  if ( (v4 & 0xFFFFFFBF) != 0 )
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
         &this->EventHandlers.mHash,
         &key);
  if ( v6 < 0 )
    return 0;
  v7 = &this->EventHandlers.mHash.pTable[4 * v6 + 2];
  if ( !v7 )
    return 0;
  p_SizeMask = &v7[1].SizeMask;
  if ( !p_SizeMask )
    return 0;
  v9 = p_SizeMask[1];
  if ( v9 )
  {
    v10 = 0i64;
    do
    {
      Scaleform::GFx::AS2::GAS_Invoke(
        (Scaleform::GFx::AS2::Value *)(v10 + *p_SizeMask),
        0i64,
        &this->Scaleform::GFx::AS2::ObjectInterface,
        penv,
        0,
        32 * LODWORD(penv->Stack.Pages.Data.Size) + penv->Stack.pCurrent - penv->Stack.pPageStart - 31,
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
void __fastcall Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::EventId *id,
        Scaleform::GFx::AS2::Value *method)
{
  signed __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> >::TableType *v7; // rbx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *p_SizeMask; // rbx
  __int64 v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::Value *v11; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *v12; // rax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *v13; // rbx
  __int64 v14; // rcx
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::EventId key; // [rsp+28h] [rbp-18h] BYREF
  Scaleform::GFx::AS2::Value *v17; // [rsp+88h] [rbp+48h] BYREF
  Scaleform::GFx::AS2::Value *v18; // [rsp+98h] [rbp+58h]

  key.Id = id->Id;
  if ( ((key.Id - 64) & 0xFFFFFFBF) != 0 )
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
         &this->EventHandlers.mHash,
         &key);
  if ( v6 >= 0
    && (v7 = &this->EventHandlers.mHash.pTable[4 * v6 + 2]) != 0i64
    && (p_SizeMask = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *)&v7[1].SizeMask) != 0i64 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      p_SizeMask,
      p_SizeMask,
      p_SizeMask->Size + 1);
    v9 = 32 * p_SizeMask->Size - 32;
    v10 = (Scaleform::GFx::AS2::Value *)((char *)p_SizeMask->Data + v9) == 0;
    v11 = (Scaleform::GFx::AS2::Value *)((char *)p_SizeMask->Data + v9);
    v17 = v11;
    if ( !v10 )
      Scaleform::GFx::AS2::Value::Value(v11, method);
  }
  else
  {
    LODWORD(v17) = 323;
    v12 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,323>,Scaleform::ArrayDefaultPolicy> *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::AvmCharacter *, __int64, Scaleform::GFx::AS2::Value **, __int64, _QWORD, _QWORD, _DWORD))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(Scaleform::Memory::pGlobalHeap, this, 24i64, &v17, -2i64, *(_QWORD *)&key.Id, *(_QWORD *)&key.KeyCode, *(_DWORD *)&key.RollOverCnt);
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
      Scaleform::GFx::AS2::Value::Value(v15, method);
    *(_QWORD *)&key.Id = id;
    *(_QWORD *)&key.KeyCode = v13;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::EventId,323>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef>(
      &this->EventHandlers.mHash,
      &this->EventHandlers,
      (Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeRef *)&key);
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(v13);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
  }
}

// File Line: 1006
// RVA: 0x7133A0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::SetClipEventHandlers(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::EventId *id,
        Scaleform::GFx::AS2::Value *method)
{
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned __int8 v8; // dl
  unsigned int v9; // ebp
  unsigned int v10; // esi
  unsigned int v11; // edi
  unsigned int TouchID; // eax
  Scaleform::GFx::EventId ida; // [rsp+20h] [rbp-38h] BYREF

  v6 = (id->Id & 0x55555555) + ((id->Id >> 1) & 0x55555555);
  v7 = (((v6 & 0x33333333) + ((v6 >> 2) & 0x33333333)) & 0xF0F0F0F)
     + ((((v6 & 0x33333333) + ((v6 >> 2) & 0x33333333)) >> 4) & 0xF0F0F0F);
  v8 = v7 + v7 / 0xFF;
  v9 = v8;
  if ( v8 == 1 )
  {
    Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(this, id, method);
  }
  else
  {
    v10 = 0;
    v11 = 1;
    if ( v8 )
    {
      do
      {
        if ( (v11 & id->Id) != 0 )
        {
          ida.Id = id->Id;
          ida.WcharCode = id->WcharCode;
          ++v10;
          ida.KeyCode = id->KeyCode;
          TouchID = id->TouchID;
          ida.Id = v11;
          ida.TouchID = TouchID;
          *(_DWORD *)&ida.RollOverCnt = *(_DWORD *)&id->RollOverCnt;
          Scaleform::GFx::AS2::AvmCharacter::SetSingleClipEventHandler(this, &ida, method);
        }
        v11 *= 2;
      }
      while ( v10 < v9 );
    }
  }
}

// File Line: 1033
// RVA: 0x6E7F40
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmCharacter::ExecuteEvent(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // r13
  __int64 v5; // rax
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::RefCountNTSImpl *v7; // r14
  __int64 v8; // rdx
  unsigned int ControllerIndex; // eax
  Scaleform::GFx::KeyboardState *v10; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v11; // r15
  int nargs; // edi
  bool v13; // r14
  char v14; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  int v16; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::FunctionRef *v19; // r14
  Scaleform::GFx::InteractiveObject *v20; // rcx
  Scaleform::GFx::CharacterHandle *pObject; // rax
  char v22; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // rcx
  int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  unsigned int v26; // eax
  unsigned int v27; // eax
  int AsciiCode; // eax
  char Type; // r14
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  unsigned int v31; // eax
  char v32; // r15
  Scaleform::GFx::AS2::Value *v33; // rcx
  Scaleform::GFx::AS2::Value *v34; // rcx
  int RollOverCnt; // eax
  Scaleform::GFx::AS2::Value *v36; // rcx
  char v37; // al
  char v38; // r14
  Scaleform::GFx::AS2::Value *v39; // rcx
  Scaleform::GFx::AS2::Value **p_pCurrent; // rbx
  Scaleform::GFx::AS2::FunctionRef *v41; // rbx
  Scaleform::GFx::InteractiveObject *v42; // rcx
  Scaleform::GFx::CharacterHandle *CharacterHandle; // rax
  char v44; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v45; // rcx
  int v46; // edx
  Scaleform::GFx::ASStringNode *v47; // rcx
  unsigned int v48; // eax
  Scaleform::GFx::AS2::FunctionRef *v49; // rbx
  Scaleform::GFx::InteractiveObject *v50; // rcx
  Scaleform::GFx::CharacterHandle *v51; // rax
  char v52; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v53; // rcx
  int v54; // edx
  Scaleform::GFx::ASStringNode *v55; // rcx
  unsigned int v56; // eax
  Scaleform::GFx::AS2::FunctionRef *v57; // rbx
  Scaleform::GFx::InteractiveObject *v58; // rcx
  Scaleform::GFx::CharacterHandle *v59; // rax
  char v60; // al
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v61; // rcx
  int v62; // edx
  Scaleform::GFx::ASStringNode *v63; // rcx
  unsigned int v64; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value value; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::Value *v69; // [rsp+60h] [rbp-29h]
  Scaleform::GFx::AS2::Value *v70; // [rsp+68h] [rbp-21h]
  Scaleform::GFx::AS2::Value method; // [rsp+70h] [rbp-19h] BYREF
  Scaleform::RefCountNTSImpl *v72; // [rsp+90h] [rbp+7h]
  Scaleform::GFx::InteractiveObject *v73; // [rsp+98h] [rbp+Fh]
  __int64 v74; // [rsp+A0h] [rbp+17h]
  int v75; // [rsp+F0h] [rbp+67h]
  Scaleform::GFx::ASString result; // [rsp+100h] [rbp+77h] BYREF
  Scaleform::RefCountNTSImpl *v77; // [rsp+108h] [rbp+7Fh]

  v74 = -2i64;
  pDispObj = this->pDispObj;
  if ( pDispObj )
    ++pDispObj->RefCount;
  v73 = pDispObj;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v6 = (Scaleform::GFx::AS2::Environment *)v5;
  v7 = *(Scaleform::RefCountNTSImpl **)(v5 + 224);
  v77 = v7;
  if ( v7 )
    ++v7->RefCount;
  v72 = v7;
  if ( ((id->Id - 64) & 0xFFFFFFBF) == 0 )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 224) + 32i64) + 16i64);
    if ( v8 )
    {
      ControllerIndex = id->ControllerIndex;
      if ( ControllerIndex >= 6 )
        v10 = 0i64;
      else
        v10 = (Scaleform::GFx::KeyboardState *)(v8 + 1672i64 * ControllerIndex + 9192);
      Scaleform::GFx::KeyboardState::UpdateListeners(v10, id);
    }
  }
  v75 = 0;
  method.T.Type = 0;
  if ( Scaleform::GFx::AS2::AvmCharacter::HasClipEventHandler(this, id) && !id->RollOverCnt )
  {
    Scaleform::GFx::AS2::AvmCharacter::InvokeClipEventHandlers(this, v6, id);
    v75 = 1;
  }
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    id);
  if ( result.pNode->Size )
  {
    v11 = &this->Scaleform::GFx::AS2::ObjectInterface;
    if ( this->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
           &this->Scaleform::GFx::AS2::ObjectInterface,
           &v6->StringContext,
           &result,
           &method) )
    {
      if ( method.T.Type == 9 )
      {
        value.T.Type = 0;
        Scaleform::GFx::AS2::Value::GetPropertyValue(&method, v6, &this->Scaleform::GFx::AS2::ObjectInterface, &value);
        Scaleform::GFx::AS2::Value::operator=(&method, &value);
        if ( value.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&value);
      }
      if ( method.T.Type != 1 )
      {
        if ( v6->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          nargs = 0;
          v13 = 1;
          if ( id->RollOverCnt )
          {
            Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            if ( *(_QWORD *)&value.T.Type )
              v13 = (*(int (__fastcall **)(_QWORD))(**(_QWORD **)&value.T.Type + 128i64))(*(_QWORD *)&value.T.Type) >= 2;
            v14 = *((_BYTE *)&value.NV + 16);
            if ( (*(_BYTE *)(&value.NV + 1) & 2) == 0 )
            {
              v15 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v16 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( (v16 & 0x3FFFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v16 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
                  v14 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( (v14 & 1) == 0 )
            {
              pStringNode = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                RefCount = value.V.pStringNode->RefCount;
                if ( (RefCount & 0x3FFFFFF) != 0 )
                {
                  value.V.pStringNode->RefCount = RefCount - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
                }
              }
            }
            value.V.pStringNode = 0i64;
            if ( !v13 )
              goto LABEL_138;
          }
          ++v75;
          if ( (v6->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
          {
            v19 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            v20 = this->pDispObj;
            pObject = v20->pNameHandle.pObject;
            if ( !pObject )
              pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v20);
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
              v6,
              "\n!!! ExecuteEvent started %s = %p for %s\n",
              result.pNode->pData,
              v19->Function,
              pObject->NamePath.pNode->pData);
            v22 = *((_BYTE *)&value.NV + 16);
            if ( (*(_BYTE *)(&value.NV + 1) & 2) == 0 )
            {
              v23 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v24 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( (v24 & 0x3FFFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v24 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
                  v22 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( (v22 & 1) == 0 )
            {
              v25 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v26 = value.V.pStringNode->RefCount;
                if ( (v26 & 0x3FFFFFF) != 0 )
                {
                  value.V.pStringNode->RefCount = v26 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v25);
                }
              }
            }
            value.V.pStringNode = 0i64;
          }
          v27 = id->Id;
          if ( (id->Id & 0xF80000) != 0 || v27 == 0x8000 || v27 == 0x10000 || v27 == 4096 || v27 == 2048 || v27 == 1024 )
          {
            AsciiCode = (unsigned __int8)id->AsciiCode;
            Type = 4;
            value.T.Type = 4;
            value.NV.Int32Value = AsciiCode;
            if ( ++v6->Stack.pCurrent >= v6->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
            pCurrent = v6->Stack.pCurrent;
            v69 = pCurrent;
            v70 = pCurrent;
            if ( pCurrent )
            {
              Scaleform::GFx::AS2::Value::Value(pCurrent, &value);
              Type = value.T.Type;
            }
            if ( (unsigned __int8)Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&value);
            nargs = 1;
          }
          v31 = id->Id;
          if ( id->Id == 0x2000
            || v31 == 0x4000
            || v31 == 0x8000
            || v31 == 0x10000
            || v31 == 0x400000
            || v31 == 0x800000 )
          {
            RollOverCnt = (unsigned __int8)id->RollOverCnt;
            v32 = 4;
            value.T.Type = 4;
            value.NV.Int32Value = RollOverCnt;
            if ( ++v6->Stack.pCurrent >= v6->Stack.pPageEnd )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
            v36 = v6->Stack.pCurrent;
            v70 = v36;
            v69 = v36;
            if ( v36 )
            {
              Scaleform::GFx::AS2::Value::Value(v36, &value);
              v32 = value.T.Type;
            }
          }
          else
          {
            if ( v31 != 1024 && v31 != 2048 && v31 != 0x80000 && v31 != 0x100000 )
            {
LABEL_86:
              v37 = id->ControllerIndex;
              if ( v37 >= 0 || nargs )
              {
                v38 = 4;
                value.T.Type = 4;
                value.NV.Int32Value = v37;
                if ( ++v6->Stack.pCurrent >= v6->Stack.pPageEnd )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
                v39 = v6->Stack.pCurrent;
                v70 = v39;
                v69 = v39;
                if ( v39 )
                {
                  Scaleform::GFx::AS2::Value::Value(v39, &value);
                  v38 = value.T.Type;
                }
                if ( (unsigned __int8)v38 >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(&value);
                ++nargs;
              }
              p_pCurrent = &v6->Stack.pCurrent;
              Scaleform::GFx::AS2::GAS_Invoke(
                &method,
                0i64,
                v11,
                v6,
                nargs,
                32 * v6->Stack.Pages.Data.Size - 32 + v6->Stack.pCurrent - v6->Stack.pPageStart,
                result.pNode->pData);
              for ( ; nargs; --nargs )
              {
                if ( (*p_pCurrent)->T.Type >= 5u )
                  Scaleform::GFx::AS2::Value::DropRefs(*p_pCurrent);
                --*p_pCurrent;
                if ( v6->Stack.pCurrent < v6->Stack.pPageStart )
                  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
              }
              if ( (v6->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
              {
                v41 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
                v42 = this->pDispObj;
                CharacterHandle = v42->pNameHandle.pObject;
                if ( !CharacterHandle )
                  CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v42);
                Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
                  v6,
                  "!!! ExecuteEvent finished %s = %p for %s\n\n",
                  result.pNode->pData,
                  v41->Function,
                  CharacterHandle->NamePath.pNode->pData);
                v44 = *((_BYTE *)&value.NV + 16);
                if ( (*(_BYTE *)(&value.NV + 1) & 2) == 0 )
                {
                  v45 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
                  if ( *(_QWORD *)&value.T.Type )
                  {
                    v46 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                    if ( (v46 & 0x3FFFFFF) != 0 )
                    {
                      *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v46 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v45);
                      v44 = *((_BYTE *)&value.NV + 16);
                    }
                  }
                }
                *(_QWORD *)&value.T.Type = 0i64;
                if ( (v44 & 1) == 0 )
                {
                  v47 = value.V.pStringNode;
                  if ( value.V.pStringNode )
                  {
                    v48 = value.V.pStringNode->RefCount;
                    if ( (v48 & 0x3FFFFFF) != 0 )
                    {
                      value.V.pStringNode->RefCount = v48 - 1;
                      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v47);
                    }
                  }
                }
                value.V.pStringNode = 0i64;
              }
LABEL_138:
              v7 = v77;
              goto LABEL_139;
            }
            v32 = 4;
            value.T.Type = 4;
            if ( id->KeyCode )
            {
              value.NV.Int32Value = -1;
              if ( ++v6->Stack.pCurrent >= v6->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
              v34 = v6->Stack.pCurrent;
              v70 = v34;
              v69 = v34;
              if ( v34 )
              {
                Scaleform::GFx::AS2::Value::Value(v34, &value);
                v32 = value.T.Type;
              }
            }
            else
            {
              value.NV.Int32Value = 0;
              if ( ++v6->Stack.pCurrent >= v6->Stack.pPageEnd )
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
              v33 = v6->Stack.pCurrent;
              v70 = v33;
              v69 = v33;
              if ( v33 )
              {
                Scaleform::GFx::AS2::Value::Value(v33, &value);
                v32 = value.T.Type;
              }
            }
          }
          if ( (unsigned __int8)v32 >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&value);
          v11 = &this->Scaleform::GFx::AS2::ObjectInterface;
          ++nargs;
          goto LABEL_86;
        }
        if ( !id->RollOverCnt )
        {
          ++v75;
          if ( (v6->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
          {
            v49 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            v50 = this->pDispObj;
            v51 = v50->pNameHandle.pObject;
            if ( !v51 )
              v51 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v50);
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
              v6,
              "\n!!! ExecuteEvent started %s = %p for %s\n",
              result.pNode->pData,
              v49->Function,
              v51->NamePath.pNode->pData);
            v52 = *((_BYTE *)&value.NV + 16);
            if ( (*(_BYTE *)(&value.NV + 1) & 2) == 0 )
            {
              v53 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v54 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( (v54 & 0x3FFFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v54 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v53);
                  v52 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( (v52 & 1) == 0 )
            {
              v55 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v56 = value.V.pStringNode->RefCount;
                if ( (v56 & 0x3FFFFFF) != 0 )
                {
                  value.V.pStringNode->RefCount = v56 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v55);
                }
              }
            }
            value.V.pStringNode = 0i64;
          }
          Scaleform::GFx::AS2::GAS_Invoke(
            &method,
            0i64,
            &this->Scaleform::GFx::AS2::ObjectInterface,
            v6,
            0,
            32 * v6->Stack.Pages.Data.Size - 31 + v6->Stack.pCurrent - v6->Stack.pPageStart,
            0i64);
          if ( (v6->Target->pASRoot->pMovieImpl->Flags & 4) != 0 )
          {
            v57 = Scaleform::GFx::AS2::Value::ToFunction(&method, (Scaleform::GFx::AS2::FunctionRef *)&value, v6);
            v58 = this->pDispObj;
            v59 = v58->pNameHandle.pObject;
            if ( !v59 )
              v59 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v58);
            Scaleform::GFx::LogBase<Scaleform::GFx::AS2::Environment>::LogAction(
              v6,
              "!!! ExecuteEvent finished %s = %p for %s\n\n",
              result.pNode->pData,
              v57->Function,
              v59->NamePath.pNode->pData);
            v60 = *((_BYTE *)&value.NV + 16);
            if ( (*(_BYTE *)(&value.NV + 1) & 2) == 0 )
            {
              v61 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&value.T.Type;
              if ( *(_QWORD *)&value.T.Type )
              {
                v62 = *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64);
                if ( (v62 & 0x3FFFFFF) != 0 )
                {
                  *(_DWORD *)(*(_QWORD *)&value.T.Type + 24i64) = v62 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v61);
                  v60 = *((_BYTE *)&value.NV + 16);
                }
              }
            }
            *(_QWORD *)&value.T.Type = 0i64;
            if ( (v60 & 1) == 0 )
            {
              v63 = value.V.pStringNode;
              if ( value.V.pStringNode )
              {
                v64 = value.V.pStringNode->RefCount;
                if ( (v64 & 0x3FFFFFF) != 0 )
                {
                  value.V.pStringNode->RefCount = v64 - 1;
                  Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v63);
                }
              }
            }
            value.V.pStringNode = 0i64;
          }
        }
      }
    }
  }
LABEL_139:
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( method.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&method);
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  if ( pDispObj )
    Scaleform::RefCountNTSImpl::Release(pDispObj);
  return v75 != 0;
}ase(v7);
  if ( pDispObj )
    Scaleform::RefCountNTSImpl::Release(pDispObj);
  return v75 != 0;
}

// File Line: 1186
// RVA: 0x6E8B20
char __fastcall Scaleform::GFx::AS2::AvmCharacter::ExecuteFunction(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::FunctionRef *function,
        Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *params)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rsi
  __int64 v6; // rax
  _QWORD *v7; // r9
  unsigned __int64 Size; // r14
  int v9; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v10; // rbx
  __int64 v11; // rsi
  Scaleform::GFx::AS2::Value *v12; // r15
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v14; // rbx
  int v15; // edx
  char v16; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v17; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // rcx
  unsigned int v20; // eax
  __int64 v22[3]; // [rsp+20h] [rbp-59h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // [rsp+40h] [rbp-39h]
  char v25; // [rsp+48h] [rbp-31h]
  _QWORD *v26; // [rsp+50h] [rbp-29h]
  int v27; // [rsp+58h] [rbp-21h]
  int v28; // [rsp+5Ch] [rbp-1Dh]
  Scaleform::GFx::AS2::Value *v29; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS2::Value v30; // [rsp+68h] [rbp-11h] BYREF
  __int64 v31; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::AS2::Value *v32; // [rsp+90h] [rbp+17h]
  _QWORD *v34; // [rsp+F8h] [rbp+7Fh]

  v31 = -2i64;
  v4 = function;
  if ( !function->Function )
    return 0;
  v30.T.Type = 0;
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v7 = (_QWORD *)v6;
  v34 = (_QWORD *)v6;
  Size = params->Data.Size;
  if ( (int)Size > 0 )
  {
    v9 = Size - 1;
    if ( (int)Size - 1 >= 0 )
    {
      v10 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v6 + 8);
      v11 = v9;
      do
      {
        v12 = &params->Data.Data[v11];
        if ( ++v10->pCurrent >= v10->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v10);
        pCurrent = v10->pCurrent;
        v32 = pCurrent;
        v29 = pCurrent;
        if ( pCurrent )
          Scaleform::GFx::AS2::Value::Value(pCurrent, v12);
        --v11;
        --v9;
      }
      while ( v9 >= 0 );
      v4 = function;
      v7 = v34;
    }
  }
  v14 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v7 + 1);
  v15 = ((__int64)(v7[1] - v7[2]) >> 5) - 32 + 32 * v7[6];
  v22[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
  v22[1] = (__int64)&v30;
  v22[2] = (__int64)&this->Scaleform::GFx::AS2::ObjectInterface;
  v25 = 0;
  v23 = 0i64;
  v24 = 0i64;
  v26 = v7;
  v27 = Size;
  v28 = v15;
  ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, __int64 *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))v4->Function->vfptr[3].Finalize_GC)(
    v4->Function,
    v22,
    v4->pLocalFrame,
    0i64);
  v22[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
  v16 = v25;
  if ( (v25 & 2) == 0 )
  {
    v17 = v23;
    if ( v23 )
    {
      RefCount = v23->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v23->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        v16 = v25;
      }
    }
  }
  v23 = 0i64;
  if ( (v16 & 1) == 0 )
  {
    v19 = v24;
    if ( v24 )
    {
      v20 = v24->RefCount;
      if ( (v20 & 0x3FFFFFF) != 0 )
      {
        v24->RefCount = v20 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v19);
      }
    }
  }
  v24 = 0i64;
  v22[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  if ( (int)Size > 0 )
  {
    do
    {
      if ( v14->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v14->pCurrent);
      if ( --v14->pCurrent < v14->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v14);
      LODWORD(Size) = Size - 1;
    }
    while ( (_DWORD)Size );
  }
  if ( v30.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v30);
  return 1;
}

// File Line: 1210
// RVA: 0x6E7D70
char __fastcall Scaleform::GFx::AS2::AvmCharacter::ExecuteCFunction(
        Scaleform::GFx::AS2::AvmCharacter *this,
        void (__fastcall *function)(__int64 *, __int64, Scaleform::GFx::AS2::ObjectInterface *),
        Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *params)
{
  __int64 v5; // rax
  _QWORD *v6; // r9
  unsigned __int64 Size; // rsi
  int v8; // edi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v9; // rbx
  __int64 v10; // r14
  Scaleform::GFx::AS2::Value *v11; // r15
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v13; // rbx
  __int64 v14; // rdx
  char v15; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v16; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v18; // rcx
  unsigned int v19; // eax
  __int64 v21[3]; // [rsp+20h] [rbp-59h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [rsp+38h] [rbp-41h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // [rsp+40h] [rbp-39h]
  char v24; // [rsp+48h] [rbp-31h]
  _QWORD *v25; // [rsp+50h] [rbp-29h]
  int v26; // [rsp+58h] [rbp-21h]
  int v27; // [rsp+5Ch] [rbp-1Dh]
  Scaleform::GFx::AS2::Value *v28; // [rsp+60h] [rbp-19h]
  Scaleform::GFx::AS2::Value v29; // [rsp+68h] [rbp-11h] BYREF
  __int64 v30; // [rsp+88h] [rbp+Fh]
  Scaleform::GFx::AS2::Value *v31; // [rsp+90h] [rbp+17h]
  _QWORD *v33; // [rsp+F8h] [rbp+7Fh]

  v30 = -2i64;
  if ( !function )
    return 0;
  v29.T.Type = 0;
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v6 = (_QWORD *)v5;
  v33 = (_QWORD *)v5;
  Size = params->Data.Size;
  if ( (int)Size > 0 )
  {
    v8 = Size - 1;
    if ( (int)Size - 1 >= 0 )
    {
      v9 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v5 + 8);
      v10 = v8;
      do
      {
        v11 = &params->Data.Data[v10];
        if ( ++v9->pCurrent >= v9->pPageEnd )
          Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v9);
        pCurrent = v9->pCurrent;
        v31 = pCurrent;
        v28 = pCurrent;
        if ( pCurrent )
          Scaleform::GFx::AS2::Value::Value(pCurrent, v11);
        --v10;
        --v8;
      }
      while ( v8 >= 0 );
      v6 = v33;
    }
  }
  v13 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v6 + 1);
  v14 = (unsigned int)((__int64)(v6[1] - v6[2]) >> 5) - 32 + 32 * (unsigned int)v6[6];
  v21[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
  v21[1] = (__int64)&v29;
  v21[2] = (__int64)&this->Scaleform::GFx::AS2::ObjectInterface;
  v24 = 0;
  v22 = 0i64;
  v23 = 0i64;
  v25 = v6;
  v26 = Size;
  v27 = v14;
  function(v21, v14, &this->Scaleform::GFx::AS2::ObjectInterface);
  v21[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
  v15 = v24;
  if ( (v24 & 2) == 0 )
  {
    v16 = v22;
    if ( v22 )
    {
      RefCount = v22->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v22->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v16);
        v15 = v24;
      }
    }
  }
  v22 = 0i64;
  if ( (v15 & 1) == 0 )
  {
    v18 = v23;
    if ( v23 )
    {
      v19 = v23->RefCount;
      if ( (v19 & 0x3FFFFFF) != 0 )
      {
        v23->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v18);
      }
    }
  }
  v23 = 0i64;
  v21[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  if ( (int)Size > 0 )
  {
    do
    {
      if ( v13->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v13->pCurrent);
      if ( --v13->pCurrent < v13->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v13);
      LODWORD(Size) = Size - 1;
    }
    while ( (_DWORD)Size );
  }
  if ( v29.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v29);
  return 1;
}    while ( (_DWORD)Size );
  }
  if ( v29.T

// File Line: 1235
// RVA: 0x71B0D0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ObjectInterface *psrcObj)
{
  __int64 v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // rbx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // rdi
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Value v8; // [rsp+28h] [rbp-30h] BYREF

  v8.T.Type = 0;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
     + 232;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, __int64, __int64, Scaleform::GFx::AS2::Value *, __int64))psrcObj->vfptr->GetMemberRaw)(
         psrcObj,
         v4,
         *(_QWORD *)(*(_QWORD *)(*(_QWORD *)v4 + 40i64) + 24i64) + 928i64,
         &v8,
         -2i64) )
  {
    v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
    vfptr = this->Scaleform::GFx::AS2::ObjectInterface::vfptr;
    v7 = Scaleform::GFx::AS2::Value::ToObject(&v8, 0i64);
    vfptr->Set__proto__(v5, (Scaleform::GFx::AS2::ASStringContext *)v4, v7);
  }
  if ( v8.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v8);
}

// File Line: 1244
// RVA: 0x723FC0
void __fastcall Scaleform::GFx::AS2::AvmCharacter::VisitMembers(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *pvisitor,
        unsigned int visitFlags)
{
  Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *p_EventHandlers; // rdi
  __int64 v9; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v10; // rbx
  Scaleform::GFx::AS2::AvmCharacter *v11; // rdx
  unsigned int RefCount; // eax

  p_EventHandlers = &this[-1].EventHandlers;
  v9 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].EntryCount)(&this[-1].EventHandlers);
  v10 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  if ( v9 )
  {
    v11 = 0i64;
    if ( p_EventHandlers )
      v11 = this;
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterface::MemberVisitor *, _QWORD, Scaleform::GFx::AS2::AvmCharacter *))(*(_QWORD *)(v9 + 32) + 64i64))(
      v9 + 32,
      psc,
      pvisitor,
      visitFlags,
      v11);
  }
  if ( v10 )
  {
    RefCount = v10->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v10->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
    }
  }
}

// File Line: 1253
// RVA: 0x6E1F80
char __fastcall Scaleform::GFx::AS2::AvmCharacter::DeleteMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  int StandardMemberConstant; // eax
  unsigned int v9; // ebx
  int v10; // eax
  __int64 v12; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rbx
  bool v14; // di
  unsigned int RefCount; // ecx
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h] BYREF

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_15;
    Scaleform::GFx::ASString::ToLower(name, &result);
    pNode = result.pNode;
    if ( (result.pNode->HashFlags & 0x10000000) == 0 )
    {
      v7 = result.pNode->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_15;
    }
    v7 = result.pNode->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmCharacter *)((char *)this - 8),
                             name);
  v9 = StandardMemberConstant;
  if ( StandardMemberConstant != -1 && StandardMemberConstant <= 32 )
  {
    v10 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[16].SizeMask)(&this[-1].EventHandlers);
    if ( _bittest(&v10, v9) )
    {
      if ( v9 != 31 )
        return 0;
      *(_DWORD *)&this->pProto.pObject[1].ArePropertiesSet &= 0xFFFFF9FF;
      return 1;
    }
  }
LABEL_15:
  v12 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v13 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v12;
  if ( v12 )
    *(_DWORD *)(v12 + 24) = (*(_DWORD *)(v12 + 24) + 1) & 0x8FFFFFFF;
  result.pNode = (Scaleform::GFx::ASStringNode *)v12;
  v14 = v12
     && (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_QWORD *)(v12 + 32) + 48i64))(
          v12 + 32,
          psc,
          name);
  if ( v13 )
  {
    RefCount = v13->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v13->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
    }
  }
  return v14;
}

// File Line: 1285
// RVA: 0x719920
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::SetMemberFlags(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        unsigned __int8 flags)
{
  __int64 v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  unsigned __int8 v9; // di
  unsigned int RefCount; // eax

  v7 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  if ( v7 )
    v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, _QWORD))(*(_QWORD *)(v7 + 32) + 56i64))(
           v7 + 32,
           psc,
           name,
           flags);
  else
    v9 = 0;
  if ( v8 )
  {
    RefCount = v8->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v9;
}

// File Line: 1294
// RVA: 0x715440
bool __fastcall Scaleform::GFx::AS2::AvmCharacter::SetMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *val)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 StandardMemberConstant; // rbx
  __int64 v10; // rax
  Scaleform::GFx::AS2::Environment *v11; // rax
  bool v12; // al
  Scaleform::GFx::AS2::Object *pObject; // rcx
  Scaleform::GFx::AS2::Object *v14; // rdx
  Scaleform::GFx::MovieImpl *v15; // rcx
  Scaleform::GFx::AS2::Environment *v16; // rax
  bool v17; // al
  Scaleform::GFx::AS2::Object *v18; // rdx
  Scaleform::GFx::AS2::Object *v19; // rcx
  Scaleform::GFx::AS2::FunctionObject *Function; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v21; // rbx
  Scaleform::GFx::AS2::Environment *v22; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *vfptr; // rbx
  Scaleform::GFx::AS2::Environment *v24; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v25; // rbx
  Scaleform::GFx::AS2::Environment *v26; // rax
  Scaleform::GFx::AS2::Object *v27; // rax
  Scaleform::GFx::AS2::ObjectInterface *v28; // rax
  __int64 v29; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v30; // rdi
  __int64 vfptr_low; // r15
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
  __int128 v44[3]; // [rsp+18h] [rbp-41h] BYREF
  Scaleform::Render::Matrix4x4<float> Dst; // [rsp+48h] [rbp-11h] BYREF
  Scaleform::GFx::ASString result; // [rsp+C8h] [rbp+6Fh] BYREF
  void *retaddr; // [rsp+D8h] [rbp+7Fh]

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_53;
    Scaleform::GFx::ASString::ToLower(name, &result);
    pNode = result.pNode;
    if ( (result.pNode->HashFlags & 0x10000000) == 0 )
    {
      v40 = result.pNode->RefCount-- == 1;
      if ( v40 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_53;
    }
    v40 = result.pNode->RefCount-- == 1;
    if ( v40 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  StandardMemberConstant = (unsigned int)Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                                           (Scaleform::GFx::AS2::AvmCharacter *)((char *)this - 8),
                                           (Scaleform::GFx::ASStringNode *)name);
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *, __int64, Scaleform::GFx::AS2::Value *, _QWORD))this[-1].EventHandlers.mHash.pTable[17].EntryCount)(
         &this[-1].EventHandlers,
         StandardMemberConstant,
         val,
         0i64) )
  {
    LOBYTE(v10) = 1;
    return v10;
  }
  switch ( (int)StandardMemberConstant )
  {
    case Y:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v11 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        v12 = Scaleform::GFx::AS2::Value::ToBool(val, v11);
        pObject = this->pProto.pObject;
        if ( v12 )
          WORD1(pObject[1].pNext) |= 2u;
        else
          WORD1(pObject[1].pNext) &= ~2u;
        v14 = this->pProto.pObject;
        v15 = *(Scaleform::GFx::MovieImpl **)&v14->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8];
        if ( (BYTE2(v14[1].pNext) & 2) != 0 )
          Scaleform::GFx::MovieImpl::AddTopmostLevelCharacter(v15, (Scaleform::GFx::InteractiveObject *)v14);
        else
          Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(v15, (Scaleform::GFx::DisplayObjectBase *)v14);
      }
      break;
    case Z:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v16 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        v17 = Scaleform::GFx::AS2::Value::ToBool(val, v16);
        v18 = this->pProto.pObject;
        if ( v17 != ((*(_DWORD *)&v18[1].ArePropertiesSet & 4) != 0) )
        {
          if ( v17 )
            *(_DWORD *)&v18[1].ArePropertiesSet |= 4u;
          else
            *(_DWORD *)&v18[1].ArePropertiesSet &= ~4u;
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(
            (Scaleform::GFx::InteractiveObject *)this->pProto.pObject,
            (__int64)v18);
          v19 = this->pProto.pObject;
          Function = v19->ResolveHandler.Function;
          if ( Function )
          {
            if ( (*(_DWORD *)&Function[1].ArePropertiesSet & 4) == 0 )
              ((void (__fastcall *)(Scaleform::GFx::AS2::Object *))v19->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr[35].ExecuteForEachChild_GC)(v19);
          }
        }
      }
      break;
    case [:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1
        && val->T.Type
        && val->T.Type != 10 )
      {
        v38 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        v39 = Scaleform::GFx::AS2::Value::ToUInt32(val, v38);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, _QWORD))this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr[35].Finalize_GC)(
          this->pProto.pObject,
          v39);
      }
      break;
    case o:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        vfptr = this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr;
        v24 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(val, v24);
        vfptr[8].Finalize_GC(this->pProto.pObject);
      }
      break;
    case p:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v25 = this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr;
        v26 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(val, v26);
        v25[10].Finalize_GC(this->pProto.pObject);
      }
      break;
    case q:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v34 = this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr;
        v35 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(val, v35);
        v34[11].~RefCountBaseGC<323>(this->pProto.pObject);
      }
      break;
    case r:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v36 = this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr;
        v37 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(val, v37);
        v36[12].Finalize_GC(this->pProto.pObject);
      }
      break;
    case s:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v27 = Scaleform::GFx::AS2::Value::ToObject(val, penv);
        if ( v27 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v27->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v27->Scaleform::GFx::AS2::ObjectInterface) == 7 )
          {
            v28 = Scaleform::GFx::AS2::Value::ToObjectInterface(val, penv);
            v29 = 0i64;
            v30 = v28 - 2;
            if ( !v28 )
              v30 = 0i64;
            memset(&Dst, 0, sizeof(Dst));
            Dst.M[0][0] = 1.0;
            Dst.M[1][1] = 1.0;
            Dst.M[2][2] = 1.0;
            Dst.M[3][3] = 1.0;
            vfptr_low = SLODWORD(v30[7].vfptr);
            if ( vfptr_low > 0 )
            {
              do
              {
                v32 = (Scaleform::GFx::AS2::Value *)*((_QWORD *)&v30[6].pProto.pObject->vfptr + v29);
                if ( v32 && (unsigned __int8)(v32->T.Type - 3) <= 1u )
                {
                  v33 = Scaleform::GFx::AS2::Value::ToNumber(v32, penv);
                  Dst.M[0][v29] = v33;
                }
                ++v29;
              }
              while ( v29 < vfptr_low );
            }
            Scaleform::Render::Matrix4x4<float>::Transpose(&Dst);
            v44[0] = *(_OWORD *)&Dst.M[0][0];
            v44[1] = *(_OWORD *)&Dst.M[1][0];
            v44[2] = *(_OWORD *)&Dst.M[2][0];
            ((void (__fastcall *)(Scaleform::GFx::AS2::Object *, __int128 *))this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr[1].~RefCountBaseGC<323>)(
              this->pProto.pObject,
              v44);
          }
        }
        else
        {
          Scaleform::GFx::DisplayObjectBase::Clear3D((Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject, 0);
        }
      }
      break;
    case t:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers)
                                + 232)
                    + 104i64) == 1 )
      {
        v21 = this->pProto.pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr;
        v22 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[15].EntryCount)(&this[-1].EventHandlers);
        Scaleform::GFx::AS2::Value::ToNumber(val, v22);
        ((void (__fastcall *)(Scaleform::GFx::AS2::Object *))v21[13].ExecuteForEachChild_GC)(this->pProto.pObject);
      }
      break;
    default:
      break;
  }
LABEL_53:
  if ( penv->StringContext.SWFVersion <= 6u )
  {
    if ( !name->pNode->pLower )
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(name->pNode);
    v40 = penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl->vfptr == (Scaleform::GFx::StateBagVtbl *)name->pNode->pLower;
  }
  else
  {
    v40 = name->pNode == (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl;
  }
  if ( v40 && val->T.Type != 10 )
  {
    v41 = this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
    v42 = Scaleform::GFx::AS2::Value::ToObject(val, 0i64);
    (*((void (__fastcall **)(Scaleform::GFx::AS2::AvmCharacter *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))&v41[1].__vecDelDtor
     + 1))(
      this,
      &penv->StringContext,
      v42);
  }
  v10 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  if ( v10 )
    LOBYTE(v10) = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, void *))(*(_QWORD *)(v10 + 32) + 24i64))(
                    v10 + 32,
                    penv,
                    name,
                    val,
                    retaddr);
  return v10;
}

// File Line: 1432
// RVA: 0x6FB400
char __fastcall Scaleform::GFx::AS2::AvmCharacter::HasMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        bool inclPrototypes)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  int StandardMemberConstant; // eax
  unsigned int v11; // ebx
  int v12; // eax
  __int64 v14; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rbx
  char v16; // di
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+18h] BYREF

  if ( (name->pNode->HashFlags & 0x20000000) == 0 )
  {
    if ( !Scaleform::GFx::ASConstString::GetLength(name) || Scaleform::GFx::ASConstString::GetCharAt(name, 0) != 95 )
      goto LABEL_13;
    Scaleform::GFx::ASString::ToLower(name, &result);
    pNode = result.pNode;
    if ( (result.pNode->HashFlags & 0x10000000) == 0 )
    {
      v9 = result.pNode->RefCount-- == 1;
      if ( v9 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_13;
    }
    v9 = result.pNode->RefCount-- == 1;
    if ( v9 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmCharacter *)((char *)this - 8),
                             (Scaleform::GFx::ASStringNode *)name);
  v11 = StandardMemberConstant;
  if ( StandardMemberConstant != -1 && StandardMemberConstant <= 32 )
  {
    v12 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[16].SizeMask)(&this[-1].EventHandlers);
    if ( _bittest(&v12, v11) )
      return 1;
  }
LABEL_13:
  v14 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v15 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v14;
  if ( v14 )
    *(_DWORD *)(v14 + 24) = (*(_DWORD *)(v14 + 24) + 1) & 0x8FFFFFFF;
  result.pNode = (Scaleform::GFx::ASStringNode *)v14;
  if ( v14 )
    v16 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, bool, __int64))(*(_QWORD *)(v14 + 32) + 72i64))(
            v14 + 32,
            psc,
            name,
            inclPrototypes,
            -2i64);
  else
    v16 = 0;
  if ( v15 )
  {
    RefCount = v15->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v15->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
    }
  }
  return v16;
}

// File Line: 1450
// RVA: 0x6EB070
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::FindMember(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Member *pmember)
{
  __int64 v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  unsigned __int8 v9; // di
  unsigned int RefCount; // eax

  v7 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  if ( v7 )
    v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Member *))(*(_QWORD *)(v7 + 32) + 40i64))(
           v7 + 32,
           psc,
           name,
           pmember);
  else
    v9 = 0;
  if ( v8 )
  {
    RefCount = v8->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v9;
}

// File Line: 1456
// RVA: 0x71E140
void __fastcall Scaleform::GFx::AS2::AvmCharacter::Set__proto__(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::ObjectInterfaceVtbl *protoObj)
{
  __int64 v6; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *vfptr; // rcx
  unsigned int RefCount; // eax
  unsigned int v10; // eax

  v6 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v6;
  if ( v6 )
    *(_DWORD *)(v6 + 24) = (*(_DWORD *)(v6 + 24) + 1) & 0x8FFFFFFF;
  if ( v6 )
    (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::ObjectInterfaceVtbl *))(*(_QWORD *)(v6 + 32) + 104i64))(
      v6 + 32,
      psc,
      protoObj);
  if ( protoObj )
    LODWORD(protoObj->SetMember) = (LODWORD(protoObj->SetMember) + 1) & 0x8FFFFFFF;
  vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)this->Scaleform::GFx::AS2::ObjectInterface::vfptr;
  if ( vfptr )
  {
    RefCount = vfptr->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      vfptr->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(vfptr);
    }
  }
  this->Scaleform::GFx::AS2::ObjectInterface::vfptr = protoObj;
  if ( v7 )
  {
    v10 = v7->RefCount;
    if ( (v10 & 0x3FFFFFF) != 0 )
    {
      v7->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
}

// File Line: 1472
// RVA: 0x6FD9D0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::InstanceOf(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Object *prototype,
        bool inclInterfaces)
{
  __int64 v7; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v8; // rbx
  unsigned __int8 v9; // di
  unsigned int RefCount; // eax

  v7 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].EntryCount)(&this[-1].EventHandlers);
  v8 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
  if ( v7 )
    *(_DWORD *)(v7 + 24) = (*(_DWORD *)(v7 + 24) + 1) & 0x8FFFFFFF;
  if ( v7 )
    v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::Object *, bool))(*(_QWORD *)(v7 + 32) + 144i64))(
           v7 + 32,
           penv,
           prototype,
           inclInterfaces);
  else
    v9 = 0;
  if ( v8 )
  {
    RefCount = v8->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
  return v9;
}

// File Line: 1478
// RVA: 0x7244E0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::Watch(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *prop,
        Scaleform::GFx::AS2::FunctionRef *callback,
        Scaleform::GFx::AS2::Value *userData)
{
  __int64 v8; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rbx
  unsigned __int8 v10; // di
  unsigned int RefCount; // eax

  v8 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v8;
  if ( v8 )
    *(_DWORD *)(v8 + 24) = (*(_DWORD *)(v8 + 24) + 1) & 0x8FFFFFFF;
  if ( v8 )
    v10 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::FunctionRef *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v8 + 32) + 152i64))(
            v8 + 32,
            psc,
            prop,
            callback,
            userData);
  else
    v10 = 0;
  if ( v9 )
  {
    RefCount = v9->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v9->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  return v10;
}

// File Line: 1484
// RVA: 0x722C60
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::Unwatch(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::ASString *prop)
{
  __int64 v5; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rbx
  unsigned __int8 v7; // di
  unsigned int RefCount; // eax

  v5 = ((__int64 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this[-1].EventHandlers.mHash.pTable[12].SizeMask)(&this[-1].EventHandlers);
  v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v5;
  if ( v5 )
    *(_DWORD *)(v5 + 24) = (*(_DWORD *)(v5 + 24) + 1) & 0x8FFFFFFF;
  if ( v5 )
    v7 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *))(*(_QWORD *)(v5 + 32) + 160i64))(
           v5 + 32,
           psc,
           prop);
  else
    v7 = 0;
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return v7;
}

// File Line: 1494
// RVA: 0x706010
void __fastcall Scaleform::GFx::AS2::AvmCharacter::OnFocus(
        Scaleform::GFx::AS2::AvmCharacter *this,
        Scaleform::GFx::InteractiveObject::FocusEventType *event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        int controllerIdx)
{
  int v6; // edi
  __int64 v8; // rax
  Scaleform::GFx::AS2::Environment *v9; // rsi
  int NargsIn; // edi
  __int64 pCurrent; // rax
  char Type; // r14
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // rbx
  Scaleform::GFx::AS2::Value *v15; // rcx
  Scaleform::GFx::AS2::Value *v16; // rax
  Scaleform::GFx::InteractiveObject *pDispObj; // rcx
  Scaleform::GFx::ASStringNode *CharacterHandle; // rax
  __int64 v19; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v24; // eax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::AS2::Value *v28; // [rsp+48h] [rbp-90h]
  Scaleform::GFx::AS2::Value *v29; // [rsp+50h] [rbp-88h]
  Scaleform::GFx::AS2::Value v; // [rsp+58h] [rbp-80h] BYREF
  Scaleform::GFx::AS2::Value v31; // [rsp+78h] [rbp-60h] BYREF
  Scaleform::GFx::AS2::FnCall v32; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::GFx::ASStringNode *v33; // [rsp+118h] [rbp+40h] BYREF

  *((_QWORD *)&v31.NV + 3) = -2i64;
  v6 = (int)event;
  v31.T.Type = 0;
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmCharacter *))this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v9 = (Scaleform::GFx::AS2::Environment *)v8;
  if ( v8 )
  {
    v33 = *(Scaleform::GFx::ASStringNode **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v8 + 232) + 40i64) + 24i64)
                                           + 8i64 * (v6 != 1)
                                           + 1016);
    ++v33->RefCount;
    if ( this->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
           &this->Scaleform::GFx::AS2::ObjectInterface,
           (Scaleform::GFx::AS2::ASStringContext *)(v8 + 232),
           (Scaleform::GFx::ASString *)&v33,
           &v31) )
    {
      Scaleform::GFx::AS2::Value::ToFunction(&v31, &result, 0i64);
      if ( result.Function )
      {
        NargsIn = 1;
        if ( v9->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          if ( ++v9->Stack.pCurrent >= v9->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
          pCurrent = (__int64)v9->Stack.pCurrent;
          v28 = (Scaleform::GFx::AS2::Value *)pCurrent;
          v29 = (Scaleform::GFx::AS2::Value *)pCurrent;
          if ( pCurrent )
          {
            *(_BYTE *)pCurrent = 3;
            *(double *)(pCurrent + 8) = (double)controllerIdx;
          }
          NargsIn = 2;
        }
        if ( oldOrNewFocusCh )
        {
          Type = 7;
          v.T.Type = 7;
          pObject = oldOrNewFocusCh->pNameHandle.pObject;
          if ( !pObject )
            pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(oldOrNewFocusCh);
          v.V.pStringNode = (Scaleform::GFx::ASStringNode *)pObject;
          if ( pObject )
            ++pObject->RefCount;
          p_Stack = &v9->Stack;
          if ( ++v9->Stack.pCurrent >= v9->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
          v15 = p_Stack->pCurrent;
          v29 = v15;
          v28 = v15;
          if ( v15 )
          {
            Scaleform::GFx::AS2::Value::Value(v15, &v);
            Type = v.T.Type;
          }
          if ( (unsigned __int8)Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        else
        {
          p_Stack = &v9->Stack;
          if ( ++v9->Stack.pCurrent >= v9->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v9->Stack);
          v16 = p_Stack->pCurrent;
          v29 = v16;
          v28 = v16;
          if ( v16 )
            v16->T.Type = 1;
        }
        v.V.FunctionValue.Flags = 0;
        pDispObj = this->pDispObj;
        v.T.Type = 7;
        if ( pDispObj )
        {
          CharacterHandle = (Scaleform::GFx::ASStringNode *)pDispObj->pNameHandle.pObject;
          if ( !CharacterHandle )
            CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(pDispObj);
          v.V.pStringNode = CharacterHandle;
          if ( CharacterHandle )
            ++LODWORD(CharacterHandle->pData);
        }
        else
        {
          v.V.pStringNode = 0i64;
        }
        Scaleform::GFx::AS2::FnCall::FnCall(
          &v32,
          (Scaleform::GFx::AS2::Value *)((char *)&v.NV + 24),
          &v,
          v9,
          NargsIn,
          32 * p_Stack->Pages.Data.Size - 32 + p_Stack->pCurrent - p_Stack->pPageStart);
        ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, __int64, Scaleform::GFx::AS2::LocalFrame *, _QWORD))result.Function->vfptr[3].Finalize_GC)(
          result.Function,
          v19,
          result.pLocalFrame,
          0i64);
        Scaleform::GFx::AS2::FnCall::~FnCall(&v32);
        if ( v.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v);
        do
        {
          if ( p_Stack->pCurrent->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
          if ( --p_Stack->pCurrent < p_Stack->pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
          --NargsIn;
        }
        while ( NargsIn );
        if ( v.V.FunctionValue.Flags >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)((char *)&v.NV + 24));
      }
      Flags = result.Flags;
      if ( (result.Flags & 2) == 0 )
      {
        Function = result.Function;
        if ( result.Function )
        {
          RefCount = result.Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            result.Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
            Flags = result.Flags;
          }
        }
      }
      result.Function = 0i64;
      if ( (Flags & 1) == 0 )
      {
        pLocalFrame = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v24 = result.pLocalFrame->RefCount;
          if ( (v24 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v24 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      result.pLocalFrame = 0i64;
    }
    v25 = v33;
    if ( v33->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  }
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
}

// File Line: 1526
// RVA: 0x6F71D0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetTopParent(
        Scaleform::GFx::AS2::AvmCharacter *this,
        __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // r8
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  pDispObj = this->pDispObj;
  pParent = pDispObj->pParent;
  if ( pParent && pParent->pASRoot->AVMVersion == 1 )
    return (Scaleform::GFx::InteractiveObject *)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                                  pParent,
                                                  ignoreLockRoot);
  else
    return pDispObj;
}

// File Line: 1534
// RVA: 0x6EE6C0
Scaleform::GFx::AS2::AvmCharacter *__fastcall Scaleform::GFx::AS2::AvmCharacter::GetAvmTopParent(
        Scaleform::GFx::AS2::AvmCharacter *this,
        __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  __int64 v4; // rax

  pParent = this->pDispObj->pParent;
  if ( pParent->pASRoot->AVMVersion != 1 )
    return 0i64;
  v4 = (__int64)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                  pParent,
                  ignoreLockRoot);
  return (Scaleform::GFx::AS2::AvmCharacter *)(v4 + 4i64 * *(unsigned __int8 *)(v4 + 109));
}

// File Line: 1542
// RVA: 0x700CA0
__int64 __fastcall Scaleform::GFx::AS2::AvmCharacter::IsTabable(Scaleform::GFx::AS2::AvmCharacter *this)
{
  __int64 v2; // rax
  unsigned int v3; // ecx
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rsi
  Scaleform::GFx::ASString *v6; // rax
  bool v7; // di
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // bl
  Scaleform::GFx::InteractiveObject *pDispObj; // rcx
  unsigned __int8 AvmObjOffset; // al
  __int64 v13; // rax
  Scaleform::GFx::AS2::Value v14; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  v2 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->vfptr[59].__vecDelDtor)(this->pDispObj);
  if ( !(_BYTE)v2 )
    return v2;
  v3 = this->pDispObj->Flags & 0x60;
  if ( v3 )
    return v3 == 96;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    v14.T.Type = 0;
    v5 = (Scaleform::GFx::AS2::Environment *)this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this);
    v6 = Scaleform::GFx::AS2::Environment::CreateConstString(v5, &result, "tabEnabled");
    v7 = pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw(
           &pObject->Scaleform::GFx::AS2::ObjectInterface,
           &v5->StringContext,
           v6,
           &v14);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v7 && v14.T.Type && v14.T.Type != 10 )
    {
      v10 = Scaleform::GFx::AS2::Value::ToBool(&v14, v5);
      if ( v14.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v14);
      return v10;
    }
    if ( v14.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v14);
  }
  pDispObj = this->pDispObj;
  AvmObjOffset = pDispObj->AvmObjOffset;
  v2 = AvmObjOffset
    && (v13 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                        + 4 * AvmObjOffset))[1].__vecDelDtor)((__int64)pDispObj + 4 * AvmObjOffset),
        (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v13 + 96i64))(v13))
    || this->pDispObj->TabIndex > 0;
  return v2;
}

// File Line: 1572
// RVA: 0x6C9070
void __fastcall Scaleform::GFx::AS2::GenericDisplayObj::GenericDisplayObj(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::GFx::ShapeBaseCharacterDef *pdef,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        _DWORD *id)
{
  LODWORD(id) = *id;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(this, pasRoot, pparent, (Scaleform::GFx::ResourceId)&id);
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::AS2::GenericDisplayObj::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::AS2::GenericDisplayObj::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( pdef )
    Scaleform::Render::RenderBuffer::AddRef(pdef);
  this->pDef.pObject = pdef;
}

// File Line: 1580
// RVA: 0x6F7190
__int64 __fastcall Scaleform::GFx::AS2::GenericDisplayObj::GetTopMostMouseEntity(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::InteractiveObject *TopMostMouseEntityDef; // rax

  TopMostMouseEntityDef = Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
                            this,
                            this->pDef.pObject,
                            pt,
                            pdescr->TestAll,
                            pdescr->pIgnoreMC);
  pdescr->pResult = TopMostMouseEntityDef;
  return 2 - (unsigned int)(TopMostMouseEntityDef != 0i64);
}

// File Line: 1588
// RVA: 0x708330
__int64 __fastcall Scaleform::GFx::AS2::GenericDisplayObj::PointTestLocal(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Render::Point<float> *pt,
        __int64 hitTestMask)
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
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::AS2::GenericDisplayObj::CreateRenderNode(
        Scaleform::GFx::AS2::GenericDisplayObj *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::GFx::ShapeBaseCharacterDef *pObject; // rbx
  Scaleform::GFx::MovieDefImpl *v6; // rax

  pObject = this->pDef.pObject;
  v6 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::GenericDisplayObj *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this);
  Scaleform::GFx::ShapeBaseCharacterDef::CreateTreeShape(pObject, result, context, v6);
  return result;
}

// File Line: 1598
// RVA: 0x6F5070
float __fastcall Scaleform::GFx::AS3::ShapeObject::GetRatio(Scaleform::GFx::AS2::GenericDisplayObj *this)
{
  Scaleform::Render::TreeNode *pObject; // r9

  pObject = this->pRenNode.pObject;
  if ( pObject
    && *(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                            + 8i64
                            * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                            + 40)
                + 8i64) == 3 )
  {
    return *(float *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                + 8i64
                                * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                                + 40)
                    + 152i64);
  }
  else
  {
    return 0.0;
  }
}

// File Line: 1610
// RVA: 0x71B280
void __fastcall Scaleform::GFx::AS3::ShapeObject::SetRatio(Scaleform::GFx::AS2::GenericDisplayObj *this, float f)
{
  unsigned __int64 RenderNode; // rax
  unsigned __int64 v4; // rdx

  RenderNode = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  if ( RenderNode )
  {
    v4 = (__int64)((unsigned __int128)((__int64)(RenderNode - (RenderNode & 0xFFFFFFFFFFFFF000ui64) - 56)
                                     * (__int128)0x4924924924924925i64) >> 64) >> 4;
    if ( *(_WORD *)(*(_QWORD *)(*(_QWORD *)((RenderNode & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8 * ((unsigned int)v4 + (v4 >> 63))
                              + 40)
                  + 8i64) == 3 )
      *(float *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this->pRenNode.pObject, 0x10u)[9].Type = f;
  }
}

