// File Line: 120
// RVA: 0x6C7510
void __fastcall Scaleform::GFx::AS2::AvmButton::AvmButton(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::Button *pbutton)
{
  Scaleform::GFx::AS2::Environment *v3; // rdx
  Scaleform::GFx::InteractiveObject *pParent; // rax
  char *v5; // rcx
  Scaleform::GFx::AS2::Object *ActualPrototype; // rax
  Scaleform::GFx::AS2::Object *v7; // rdi
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(this, pbutton);
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmButtonBase::`vftable;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable;
  v3 = 0i64;
  this->ASButtonObj.pObject = 0i64;
  pParent = this->pDispObj->pParent;
  if ( pParent )
  {
    while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    {
      pParent = pParent->pParent;
      if ( !pParent )
        goto LABEL_6;
    }
    v5 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
    v3 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v5 + 240i64))(v5);
  }
LABEL_6:
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].vfptr,
                      v3,
                      ASBuiltin_Button);
  v7 = ActualPrototype;
  if ( ActualPrototype )
    ActualPrototype->RefCount = (ActualPrototype->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = v7;
}

// File Line: 135
// RVA: 0x7065A0
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::OnMouseEvent(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::ASStringNode *event)
{
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::AS2::AvmButton *v3; // rsi
  unsigned __int8 v4; // r12
  int v5; // r9d
  int v6; // r11d
  unsigned int pData; // eax
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // r8
  bool (__fastcall *HasEventHandler)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // rdx
  bool (__fastcall *v10)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // r10
  Scaleform::GFx::AvmButtonBase *(__fastcall *ToAvmButttonBase)(Scaleform::GFx::AvmDisplayObjBase *); // rcx
  unsigned __int64 v12; // r13
  __int64 v13; // rdx
  __int64 v14; // rsi
  Scaleform::GFx::AS2::AvmSprite *v15; // r14
  __int64 v16; // rcx
  Scaleform::GFx::AS2::ASStringContext *v17; // r15
  unsigned __int64 v18; // rbp
  unsigned __int64 v19; // rdi
  __int64 v20; // rax
  Scaleform::GFx::AS2::ActionBuffer *v21; // rax
  Scaleform::GFx::AS2::ActionBuffer *v22; // rax
  Scaleform::GFx::AS2::ActionBuffer *v23; // rbx
  __int64 v24; // rax
  __int64 v25; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v27; // rbx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v28; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::RefCountNTSImpl *v30; // rcx
  Scaleform::GFx::ASStringNode *v31; // rcx
  __int128 v34; // [rsp+20h] [rbp-C8h]
  int pLower; // [rsp+30h] [rbp-B8h]
  __int64 v36; // [rsp+40h] [rbp-A8h]
  bool (__fastcall *v37)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // [rsp+48h] [rbp-A0h]
  unsigned __int64 v38; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::AvmButtonBase *(__fastcall *v39)(Scaleform::GFx::AvmDisplayObjBase *); // [rsp+58h] [rbp-90h]
  Scaleform::GFx::AS2::Value v40; // [rsp+80h] [rbp-68h] BYREF
  Scaleform::GFx::ASString result; // [rsp+F8h] [rbp+10h] BYREF
  int v43; // [rsp+100h] [rbp+18h]
  int v44; // [rsp+108h] [rbp+20h]

  result.pNode = event;
  pNode = event;
  v3 = this;
  v4 = 0;
  if ( !LOBYTE(event->pLower) )
  {
    v5 = 0;
    v43 = 0;
    v6 = 0;
    v44 = 0;
    pData = (unsigned int)event->pData;
    if ( LODWORD(event->pData) == 0x2000 )
    {
      v5 = 1;
      v43 = 1;
    }
    else
    {
      switch ( pData )
      {
        case 0x4000u:
          v5 = 2;
          v43 = 2;
          break;
        case 0x400u:
          v5 = 4;
          v43 = 4;
          break;
        case 0x800u:
          v5 = 8;
          v43 = 8;
          break;
        case 0x10000u:
          v5 = 16;
          v43 = 16;
          break;
        case 0x8000u:
          v5 = 32;
          v43 = 32;
          break;
        case 0x1000u:
          v5 = 64;
          v43 = 64;
          break;
        case 0x20000u:
          v6 = Scaleform::GFx::EventId::ConvertToButtonKeyCode((Scaleform::GFx::EventId *)event);
          v44 = v6;
          v5 = v43;
          break;
      }
    }
    vfptr = v3[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
    HasEventHandler = vfptr->HasEventHandler;
    if ( HasEventHandler )
    {
      v10 = 0i64;
      if ( (*((_WORD *)HasEventHandler + 53) & 0x400) != 0 )
        v10 = vfptr->HasEventHandler;
      v37 = v10;
      if ( v10 )
      {
        ToAvmButttonBase = vfptr[2].ToAvmButttonBase;
        v39 = ToAvmButttonBase;
        v12 = 0i64;
        v38 = *((_QWORD *)ToAvmButttonBase + 8);
        v13 = v6;
        v36 = v6;
        if ( v38 )
        {
          do
          {
            v14 = *(_QWORD *)(*((_QWORD *)ToAvmButttonBase + 7) + 8 * v12);
            if ( (v5 & *(_DWORD *)(v14 + 16) & 0xFFFF01FF) != 0 || v13 > 0 && ((*(int *)(v14 + 16) >> 9) & 0x7F) == v6 )
            {
              v15 = (Scaleform::GFx::AS2::AvmSprite *)((char *)v10 + 4 * *((unsigned __int8 *)v10 + 109));
              v17 = (Scaleform::GFx::AS2::ASStringContext *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmSprite *))v15->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(v15)
                                                           + 232);
              v18 = *(_QWORD *)(v14 + 32);
              v19 = 0i64;
              if ( v18 )
              {
                do
                {
                  v20 = *(_QWORD *)(*(_QWORD *)(v14 + 24) + 8 * v19);
                  if ( *(_DWORD *)(v20 + 24) && **(_BYTE **)(v20 + 16) )
                  {
                    v21 = (Scaleform::GFx::AS2::ActionBuffer *)((__int64 (__fastcall *)(__int64, __int64))v17->pContext->pHeap->vfptr->Alloc)(
                                                                 v16,
                                                                 64i64);
                    if ( v21 )
                    {
                      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
                        v21,
                        v17,
                        *(Scaleform::GFx::Resource **)(*(_QWORD *)(v14 + 24) + 8 * v19));
                      v23 = v22;
                    }
                    else
                    {
                      v23 = 0i64;
                    }
                    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v15, v23, AP_Frame);
                    if ( v23 )
                      Scaleform::RefCountNTSImpl::Release(v23);
                  }
                  ++v19;
                }
                while ( v19 < v18 );
                v4 = 1;
              }
              v13 = v36;
              v6 = v44;
              v10 = v37;
              v5 = v43;
            }
            ++v12;
            ToAvmButttonBase = v39;
          }
          while ( v12 < v38 );
          pNode = result.pNode;
          v3 = this;
        }
      }
    }
  }
  v24 = ((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))v3[-1].pProto.pObject[2].Members.mHash.pTable)(&v3[-1].pProto);
  if ( v24 )
  {
    v25 = v24 + 232;
    Scaleform::GFx::AS2::EventId_GetFunctionName(
      &result,
      (Scaleform::GFx::AS2::StringManager *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v24 + 232) + 40i64) + 24i64) + 312i64),
      (Scaleform::GFx::EventId *)pNode);
    if ( result.pNode->Size )
    {
      v40.T.Type = 0;
      if ( ((unsigned __int64 (__fastcall *)(Scaleform::GFx::InteractiveObject **, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v3[-1].pDispObj->pPerspectiveData)(
             &v3[-1].pDispObj,
             v25,
             &result,
             &v40) )
      {
        v4 = 1;
        inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                     (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)v3[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr->ToAvmTextFieldBase
                                                                       + 128),
                     AP_Frame);
        v27 = inserted;
        if ( inserted )
        {
          v34 = *(_OWORD *)&pNode->pData;
          pLower = (int)pNode->pLower;
          v28 = v3[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
          inserted->Type = Entry_Event;
          if ( v28 )
            ++*((_DWORD *)&v28->__vecDelDtor + 2);
          pObject = inserted->pCharacter.pObject;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          v27->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v28;
          v30 = v27->pActionBuffer.pObject;
          if ( v30 )
            Scaleform::RefCountNTSImpl::Release(v30);
          v27->pActionBuffer.pObject = 0i64;
          *(_QWORD *)&v27->mEventId.Id = v34;
          v27->mEventId.KeyCode = DWORD2(v34);
          v27->mEventId.AsciiCode = BYTE12(v34);
          *(_DWORD *)&v27->mEventId.RollOverCnt = pLower;
        }
      }
      if ( v40.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v40);
    }
    v31 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  }
  return v4;
}

// File Line: 219
// RVA: 0x6DF0F0
void __fastcall Scaleform::GFx::AS2::AvmButton::ConstructCharacter(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::InteractiveObject *pscriptCh,
        Scaleform::GFx::ButtonRecord *rec)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v6; // r13
  char Flags; // r15
  Scaleform::GFx::AS2::FunctionObject *Function; // r14
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rsi
  Scaleform::GFx::MovieDefImpl *v10; // rax
  Scaleform::String *NameOfExportedResource; // rbx
  Scaleform::GFx::AS2::Environment *v12; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v13; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // rbx
  __int64 v16; // r11
  __int64 v17; // r8
  __int64 *v18; // r9
  Scaleform::GFx::ASStringNode *v19; // rdx
  __int64 v20; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rax
  signed __int64 v22; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v23; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v24; // rbx
  char *v25; // rcx
  Scaleform::GFx::AS2::AvmCharacter *v26; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v28; // rbx
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::RefCountNTSImpl *v30; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v31; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v32; // rbx
  Scaleform::RefCountNTSImpl *v33; // rcx
  Scaleform::RefCountNTSImpl *v34; // rcx
  char Type; // bl
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v36; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v37; // rbx
  Scaleform::RefCountNTSImpl *v38; // rcx
  Scaleform::RefCountNTSImpl *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  unsigned int RefCount; // eax
  unsigned int v43; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+60h] [rbp-20h] BYREF
  Scaleform::GFx::ASString::NoCaseKey rid; // [rsp+C8h] [rbp+48h] BYREF
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+58h] BYREF

  if ( (pscriptCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    return;
  v6 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this);
  Flags = 0;
  Function = 0i64;
  memset(&orig, 0, 17);
  pLocalFrame = 0i64;
  LODWORD(rid.pStr) = rec->CharacterId.Id;
  v10 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pscriptCh->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pscriptCh);
  NameOfExportedResource = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(
                             v10,
                             (Scaleform::GFx::ResourceId)&rid);
  if ( NameOfExportedResource )
  {
    v12 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
    Scaleform::GFx::AS2::Environment::CreateString(v12, &result, NameOfExportedResource);
    v13 = v6 + 3;
    if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
                  + 240) <= 6u )
    {
      rid.pStr = &result;
      pNode = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        pNode = result.pNode;
      }
      if ( !v13->pTable )
        goto LABEL_35;
      v22 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
              v6 + 3,
              &rid,
              pNode->HashFlags & v13->pTable->SizeMask);
      if ( v22 < 0 )
        goto LABEL_35;
      v20 = (__int64)(&v13->pTable[1].SizeMask + 5 * v22);
    }
    else
    {
      pTable = v13->pTable;
      if ( !v13->pTable )
        goto LABEL_35;
      SizeMask = pTable->SizeMask;
      v16 = (unsigned int)SizeMask & result.pNode->HashFlags;
      v17 = v16;
      v18 = (__int64 *)(&pTable[2 * v16 + 1].EntryCount + v16);
      if ( *v18 == -2 || ((unsigned int)SizeMask & *(_DWORD *)(v18[1] + 28)) != v16 )
        goto LABEL_35;
      while ( 1 )
      {
        v19 = (Scaleform::GFx::ASStringNode *)v18[1];
        if ( ((unsigned int)SizeMask & v19->HashFlags) == v16 && v19 == result.pNode )
          break;
        v17 = *v18;
        if ( *v18 == -1 )
          goto LABEL_35;
        v18 = (__int64 *)(&pTable[2 * v17 + 1].EntryCount + v17);
      }
      if ( v17 < 0 )
        goto LABEL_35;
      v20 = (__int64)(&pTable[2 * v17 + 1].SizeMask + v17);
    }
    if ( v20 )
    {
      v23 = (Scaleform::GFx::AS2::FunctionRefBase *)(v20 + 8);
      if ( v23 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, v23);
        Function = orig.Function;
        v24 = &orig.Function->Scaleform::GFx::AS2::ObjectInterface;
        if ( !orig.Function )
          v24 = 0i64;
        v25 = (char *)pscriptCh + 4 * (unsigned __int8)pscriptCh->AvmObjOffset;
        v26 = (Scaleform::GFx::AS2::AvmCharacter *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v25 + 8i64))(v25);
        Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(v26, v24);
        inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                     (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
                     AP_Construct);
        v28 = inserted;
        if ( inserted )
        {
          inserted->Type = Entry_Event;
          ++pscriptCh->RefCount;
          pObject = inserted->pCharacter.pObject;
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
          v28->pCharacter.pObject = pscriptCh;
          v30 = v28->pActionBuffer.pObject;
          if ( v30 )
            Scaleform::RefCountNTSImpl::Release(v30);
          v28->pActionBuffer.pObject = 0i64;
          *(_QWORD *)&v28->mEventId.Id = 0x40000i64;
          v28->mEventId.KeyCode = 0;
          v28->mEventId.AsciiCode = 0;
          *(_DWORD *)&v28->mEventId.RollOverCnt = 65280;
        }
        v31 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
                AP_Construct);
        v32 = v31;
        if ( v31 )
        {
          v31->Type = Entry_Function;
          ++pscriptCh->RefCount;
          v33 = v31->pCharacter.pObject;
          if ( v33 )
            Scaleform::RefCountNTSImpl::Release(v33);
          v32->pCharacter.pObject = pscriptCh;
          v34 = v32->pActionBuffer.pObject;
          if ( v34 )
            Scaleform::RefCountNTSImpl::Release(v34);
          v32->pActionBuffer.pObject = 0i64;
          Scaleform::GFx::AS2::FunctionRefBase::Assign(&v32->Function, &orig);
        }
        Flags = orig.Flags;
        pLocalFrame = orig.pLocalFrame;
        goto LABEL_46;
      }
    }
LABEL_35:
    rid.pStr = (Scaleform::GFx::ASString *)&pheapAddr;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    Type = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
    ++result.pNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    rid.pStr = (Scaleform::GFx::ASString *)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( rid.pStr )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      Type = v.T.Type;
    }
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v36 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
            (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&this->pDispObj->pASRoot[3].RefCount,
            AP_Construct);
    v37 = v36;
    if ( v36 )
    {
      v36->Type = Entry_CFunction;
      ++pscriptCh->RefCount;
      v38 = v36->pCharacter.pObject;
      if ( v38 )
        Scaleform::RefCountNTSImpl::Release(v38);
      v37->pCharacter.pObject = pscriptCh;
      v39 = v37->pActionBuffer.pObject;
      if ( v39 )
        Scaleform::RefCountNTSImpl::Release(v39);
      v37->pActionBuffer.pObject = 0i64;
      v37->CFunction = Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        &v37->FunctionParams,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
    }
    rid.pStr = (Scaleform::GFx::ASString *)&pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
LABEL_46:
    v40 = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  }
  if ( (Flags & 2) == 0 )
  {
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  orig.Function = 0i64;
  if ( (Flags & 1) == 0 && pLocalFrame )
  {
    v43 = pLocalFrame->RefCount;
    if ( (v43 & 0x3FFFFFF) != 0 )
    {
      pLocalFrame->RefCount = v43 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
    }
  }
}

// File Line: 264
// RVA: 0x705700
char __fastcall Scaleform::GFx::AS2::AvmButton::OnButtonKeyEvent(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::EventId *id,
        int *__formal)
{
  __int64 v5; // rbx
  Scaleform::GFx::MovieImpl *v6; // rbp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v8; // rbx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::RefCountNTSImpl *v11; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int128 v15; // [rsp+30h] [rbp-58h]
  int v16; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-38h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+8h] BYREF

  v5 = ((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::EventId *, int *))this[-1].pProto.pObject[2].Members.mHash.pTable)(
         &this[-1].pProto,
         id,
         __formal);
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 232) + 40i64) + 24i64) + 312i64),
    id);
  v6 = (Scaleform::GFx::MovieImpl *)*((_QWORD *)this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr->ToAvmTextFieldBase
                                    + 2);
  if ( result.pNode->Size )
  {
    v17.T.Type = 0;
    if ( ((id->Id - 64) & 0xFFFFFFBF) == 0 )
    {
      if ( ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject **, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))this[-1].pDispObj->pPerspectiveData)(
             &this[-1].pDispObj,
             v5 + 232,
             &result,
             &v17) )
      {
        if ( *(_BYTE *)(v5 + 240) >= 6u
          && Scaleform::GFx::MovieImpl::IsKeyboardFocused(
               v6,
               (Scaleform::GFx::Sprite *)this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr,
               id->ControllerIndex) )
        {
          inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                       (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr->ToAvmTextFieldBase
                                                                         + 128),
                       AP_Frame);
          v8 = inserted;
          if ( inserted )
          {
            v15 = *(_OWORD *)&id->Id;
            v16 = *(_DWORD *)&id->RollOverCnt;
            vfptr = this[-1].Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
            inserted->Type = Entry_Event;
            if ( vfptr )
              ++*((_DWORD *)&vfptr->__vecDelDtor + 2);
            pObject = inserted->pCharacter.pObject;
            if ( pObject )
              Scaleform::RefCountNTSImpl::Release(pObject);
            v8->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)vfptr;
            v11 = v8->pActionBuffer.pObject;
            if ( v11 )
              Scaleform::RefCountNTSImpl::Release(v11);
            v8->pActionBuffer.pObject = 0i64;
            *(_QWORD *)&v8->mEventId.Id = v15;
            v8->mEventId.KeyCode = DWORD2(v15);
            v8->mEventId.AsciiCode = BYTE12(v15);
            *(_DWORD *)&v8->mEventId.RollOverCnt = v16;
          }
        }
      }
    }
    if ( v17.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v17);
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  return 1;
}

// File Line: 295
// RVA: 0x6EEF60
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::GetCursorType(Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AvmDisplayObjContainerBase *v2; // rax
  Scaleform::GFx::AS2::Environment *v3; // rdi
  Scaleform::GFx::AS2::ASStringContext *v4; // rdx
  Scaleform::GFx::ASString *v5; // r8
  Scaleform::GFx::AS2::ObjectInterface *v6; // rcx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int v8; // ebx
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h] BYREF

  v2 = this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this);
  v3 = (Scaleform::GFx::AS2::Environment *)v2;
  v10.T.Type = 0;
  if ( !v2 || (this->pDispObj->Flags & 0x10) == 0 )
    goto LABEL_10;
  if ( this->ASButtonObj.pObject )
  {
    v4 = (Scaleform::GFx::AS2::ASStringContext *)&v2[29];
    v5 = (Scaleform::GFx::ASString *)*((_QWORD *)v2[29].vfptr->ToAvmDispContainerBase + 3);
    v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  }
  else
  {
    pObject = this->pProto.pObject;
    if ( !pObject )
      goto LABEL_8;
    v6 = &pObject->Scaleform::GFx::AS2::ObjectInterface;
    v4 = (Scaleform::GFx::AS2::ASStringContext *)&v2[29];
    v5 = (Scaleform::GFx::ASString *)*((_QWORD *)v2[29].vfptr->ToAvmDispContainerBase + 3);
  }
  v6->vfptr->GetMemberRaw(v6, v4, v5 + 167, &v10);
LABEL_8:
  if ( Scaleform::GFx::AS2::Value::ToBool(&v10, v3) )
  {
    v8 = 1;
    goto LABEL_11;
  }
LABEL_10:
  v8 = 0;
LABEL_11:
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  return v8;
}

// File Line: 316
// RVA: 0x6EE7E0
Scaleform::GFx::AS2::ButtonObject *__fastcall Scaleform::GFx::AS2::AvmButton::GetButtonASObject(
        Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AS2::ButtonObject *v2; // rsi
  Scaleform::GFx::InteractiveObject *pDispObj; // rbx
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::ButtonObject *v5; // rax
  Scaleform::GFx::AS2::ButtonObject *v6; // rbx
  Scaleform::GFx::AS2::ButtonObject *pObject; // rcx
  unsigned int RefCount; // eax
  int v10; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::ButtonObject *v11; // [rsp+60h] [rbp+18h]

  if ( this->ASButtonObj.pObject )
    return this->ASButtonObj.pObject;
  v10 = 323;
  v2 = (Scaleform::GFx::AS2::ButtonObject *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::AvmButton *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              104i64,
                                              &v10,
                                              -2i64);
  v11 = v2;
  if ( v2 )
  {
    pDispObj = this->pDispObj;
    v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this);
    Scaleform::GFx::AS2::ButtonObject::ButtonObject(v2, v4, pDispObj);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  pObject = this->ASButtonObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ASButtonObj.pObject = v6;
  return v6;
}

// File Line: 324
// RVA: 0x6EE310
// attributes: thunk
Scaleform::GFx::AS2::ButtonObject *__fastcall Scaleform::GFx::AS2::AvmButton::GetASObject(
        Scaleform::GFx::AS2::AvmButton *this)
{
  return Scaleform::GFx::AS2::AvmButton::GetButtonASObject(this);
}

// File Line: 333
// RVA: 0x6F0060
char __fastcall Scaleform::GFx::AS2::AvmButton::GetMember(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::ButtonObject *pObject; // rdi
  Scaleform::GFx::AS2::AvmCharacter::StandardMember StandardMemberConstant; // eax
  Scaleform::GFx::AvmDisplayObjBaseVtbl *vfptr; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v12; // rcx
  Scaleform::GFx::AS2::GlobalContext *pContext; // rdx

  if ( (name->pNode->HashFlags & 0x20000000) != 0 )
  {
    pObject = this[-1].ASButtonObj.pObject;
    StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                               (Scaleform::GFx::AS2::AvmButton *)((char *)this - 8),
                               name);
    if ( (*(unsigned __int8 (__fastcall **)(Scaleform::Ptr<Scaleform::GFx::AS2::ButtonObject> *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))&pObject[2].ResolveHandler.Flags)(
           &this[-1].ASButtonObj,
           (unsigned int)StandardMemberConstant,
           pval,
           0i64) )
    {
      return 1;
    }
  }
  vfptr = this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr;
  if ( vfptr )
    return (*((__int64 (__fastcall **)(Scaleform::GFx::AvmTextFieldBase *(__fastcall **)(Scaleform::GFx::AvmDisplayObjBase *), Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))vfptr->ToAvmTextFieldBase
            + 4))(
             &vfptr->ToAvmTextFieldBase,
             penv,
             name,
             pval);
  if ( penv
    && name->pNode == (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(
      pval,
      (Scaleform::GFx::AS2::Object *)this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr);
    return 1;
  }
  v12 = this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr;
  if ( v12
    && (*((unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v12->GetMember
        + 4))(
         (__int64)&v12->GetMember,
         penv,
         name,
         pval) )
  {
    return 1;
  }
  if ( !penv )
    return 0;
  pContext = penv->StringContext.pContext;
  if ( name->pNode != (Scaleform::GFx::ASStringNode *)pContext->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl )
    return 0;
  Scaleform::GFx::AS2::Value::SetAsObject(pval, pContext->pGlobal.pObject);
  return 1;
}

// File Line: 374
// RVA: 0x6DF7E0
void __fastcall Scaleform::GFx::AS2::AvmButton::CreateCharacters(Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AS2::AvmButton::RecreateCharacters((Scaleform::GFx::AS2::AvmButton *)((char *)this - 40), MouseUp);
}

// File Line: 379
// RVA: 0x721210
void __fastcall Scaleform::GFx::AS2::AvmButton::SwitchState(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  Scaleform::GFx::AS2::AvmButton::RecreateCharacters((Scaleform::GFx::AS2::AvmButton *)((char *)this - 40), mouseState);
}

// File Line: 384
// RVA: 0x6EA3F0
Scaleform::GFx::Button::CharToRec *__fastcall Scaleform::GFx::AS2::AvmButton::FindCharacterAndRemove(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::Button::CharToRec *result,
        Scaleform::GFx::ButtonRecord *rec)
{
  int v4; // r9d
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *i; // rdi
  unsigned __int64 v6; // rbx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::ButtonRecord **p_Record; // rax
  __int64 v9; // r14
  Scaleform::GFx::Button::CharToRec *Data; // rcx
  Scaleform::GFx::DisplayObjectBase *pObject; // rax
  Scaleform::GFx::DisplayObjectBase *v12; // rsi
  Scaleform::GFx::ButtonRecord *Record; // rbp
  Scaleform::RefCountNTSImpl *v14; // rcx

  v4 = 0;
  for ( i = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&this->pDispObj[1].pWeakProxy;
        ;
        i = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)((char *)i + 32) )
  {
    if ( v4 != 3 )
    {
      v6 = 0i64;
      Size = i->Size;
      if ( Size )
        break;
    }
LABEL_7:
    if ( (unsigned int)++v4 >= 4 )
    {
      result->Char.pObject = 0i64;
      return result;
    }
  }
  p_Record = &i->Data->Record;
  while ( *p_Record != rec )
  {
    ++v6;
    p_Record += 2;
    if ( v6 >= Size )
      goto LABEL_7;
  }
  v9 = v6;
  Data = i->Data;
  pObject = i->Data[v6].Char.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v12 = Data[v6].Char.pObject;
  Record = Data[v9].Record;
  if ( i->Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      i,
      i,
      0i64);
  }
  else
  {
    v14 = i->Data[v9].Char.pObject;
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
    memmove(&i->Data[v9], &i->Data[v9 + 1], 16 * (i->Size - v6 - 1));
    --i->Size;
  }
  if ( v12 )
    ++v12->RefCount;
  result->Char.pObject = v12;
  result->Record = Record;
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release(v12);
  return result;
}

// File Line: 408
// RVA: 0x70B820
void __fastcall Scaleform::GFx::AS2::AvmButton::RecreateCharacters(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  Scaleform::GFx::ButtonRecord::MouseState v2; // esi
  Scaleform::GFx::Button *pDispObj; // r14
  __int64 pDef; // r15
  Scaleform::GFx::Button::ButtonState ButtonState; // eax
  Scaleform::GFx::Button::ButtonState v6; // r12d
  Scaleform::GFx::Button::ButtonState i; // ebx
  Scaleform::GFx::Button::ButtonState v8; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // r13
  unsigned __int64 Capacity; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v11; // rax
  Scaleform::Render::TreeContainer *v12; // rcx
  __int64 v13; // r14
  __int64 v14; // r14
  bool v15; // zf
  Scaleform::GFx::DisplayObjectBase *v16; // r15
  Scaleform::GFx::Button::CharToRec *v17; // rax
  __int64 Record; // rdi
  __int64 v19; // rcx
  __int64 v20; // rdx
  Scaleform::GFx::DisplayObjectBase **v21; // rdx
  Scaleform::Render::TreeNode *v22; // r9
  __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rdx
  unsigned __int64 v26; // rdx
  Scaleform::GFx::InteractiveObject *v27; // r9
  Scaleform::GFx::ASSupport *v28; // rcx
  __int64 v29; // rax
  Scaleform::GFx::DisplayObjectBase *v30; // rdi
  __int64 v31; // rcx
  __int64 v32; // rdx
  Scaleform::GFx::DisplayObjectBase **v33; // rdx
  Scaleform::Render::TreeNode *RenderNode; // r9
  __int64 v35; // rcx
  __int64 v36; // rax
  __int64 v37; // rdx
  unsigned __int64 v38; // rdx
  Scaleform::GFx::DisplayObjectBase *j; // rsi
  Scaleform::Render::Rect<float> *Scale9Grid; // rax
  Scaleform::GFx::InteractiveObject *v41; // rsi
  __int64 v42; // rdx
  unsigned int Flags; // ecx
  int v44; // eax
  unsigned __int64 v45; // r9
  __int64 v46; // rcx
  __int64 v47; // rax
  __int64 v48; // rdx
  unsigned __int64 v49; // rdx
  Scaleform::GFx::ResourceId rid[2]; // [rsp+30h] [rbp-99h] BYREF
  int v51; // [rsp+38h] [rbp-91h]
  __int64 v52; // [rsp+40h] [rbp-89h]
  __int64 v53; // [rsp+48h] [rbp-81h]
  __int64 v54; // [rsp+50h] [rbp-79h]
  Scaleform::GFx::Button *v55; // [rsp+58h] [rbp-71h]
  Scaleform::Render::TreeContainer *pObject; // [rsp+60h] [rbp-69h]
  Scaleform::GFx::DisplayObjectBase **v57; // [rsp+68h] [rbp-61h]
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [rsp+70h] [rbp-59h] BYREF
  Scaleform::GFx::DisplayObjectBase *v59; // [rsp+78h] [rbp-51h]
  __int64 v60; // [rsp+80h] [rbp-49h]
  __int64 v61; // [rsp+88h] [rbp-41h]
  __int64 v62; // [rsp+90h] [rbp-39h]
  __int64 v63; // [rsp+98h] [rbp-31h]
  __int64 v64; // [rsp+A0h] [rbp-29h]
  Scaleform::GFx::CharacterCreateInfo v65; // [rsp+A8h] [rbp-21h] BYREF
  Scaleform::GFx::Button::CharToRec v66; // [rsp+C0h] [rbp-9h] BYREF
  Scaleform::Render::Rect<float> v67; // [rsp+D0h] [rbp+7h] BYREF
  Scaleform::GFx::Button::ButtonState v70; // [rsp+140h] [rbp+77h]
  Scaleform::GFx::Button::ButtonState v71; // [rsp+148h] [rbp+7Fh]

  v64 = -2i64;
  v2 = mouseState;
  pDispObj = (Scaleform::GFx::Button *)this->pDispObj;
  v55 = pDispObj;
  pDef = (__int64)pDispObj->pDef;
  v52 = pDef;
  ButtonState = Scaleform::GFx::Button::GetButtonState(mouseState);
  v70 = ButtonState;
  v6 = Up;
  for ( i = Up; (unsigned int)i < StatesCount; ++i )
  {
    if ( i != ButtonState && i != Hit )
    {
      Scaleform::GFx::Button::ClearRenderTreeForState(pDispObj, i);
      ButtonState = v70;
    }
  }
  v8 = Up;
  v71 = Up;
  p_Data = &pDispObj->States[0].Characters.Data;
  do
  {
    if ( v8 == ButtonState || v8 == Hit )
    {
      Capacity = p_Data[-1].Policy.Capacity;
      if ( Capacity )
        ++*(_QWORD *)(Capacity + 8);
      pObject = (Scaleform::Render::TreeContainer *)Capacity;
      if ( !p_Data->Size )
      {
        if ( !Capacity )
        {
          v11 = Scaleform::GFx::Button::CreateStateRenderContainer(pDispObj, &result, v8);
          if ( v11->pObject )
            ++v11->pObject->RefCount;
          Capacity = (unsigned __int64)v11->pObject;
          pObject = v11->pObject;
          v12 = result.pObject;
          if ( result.pObject )
          {
            v15 = result.pObject->RefCount-- == 1;
            if ( v15 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
          }
        }
        v54 = *(_QWORD *)(pDef + 40);
        if ( v54 )
        {
          v13 = 0i64;
          v53 = 0i64;
          while ( 1 )
          {
            v14 = *(_QWORD *)(pDef + 32) + v13;
            if ( v8 == Hit )
            {
              v15 = (*(_BYTE *)(v14 + 84) & 1) == 0;
            }
            else
            {
              if ( v2 == MouseUp )
              {
                if ( (*(_BYTE *)(v14 + 84) & 8) != 0 )
                  goto LABEL_31;
                goto LABEL_85;
              }
              if ( v2 == MouseDown )
              {
                if ( (*(_BYTE *)(v14 + 84) & 2) != 0 )
                  goto LABEL_31;
                goto LABEL_85;
              }
              if ( v2 != MouseOver )
                goto LABEL_85;
              v15 = (*(_BYTE *)(v14 + 84) & 4) == 0;
            }
            if ( !v15 )
            {
LABEL_31:
              v16 = 0i64;
              v59 = 0i64;
              if ( v8 == Hit )
                goto LABEL_47;
              v17 = Scaleform::GFx::AS2::AvmButton::FindCharacterAndRemove(
                      this,
                      &v66,
                      (Scaleform::GFx::ButtonRecord *)v14);
              if ( v17->Char.pObject )
                ++v17->Char.pObject->RefCount;
              v16 = v17->Char.pObject;
              v59 = v17->Char.pObject;
              Record = (__int64)v17->Record;
              v60 = Record;
              if ( v66.Char.pObject )
                Scaleform::RefCountNTSImpl::Release(v66.Char.pObject);
              if ( !v16 )
              {
LABEL_47:
                rid[0] = *(Scaleform::GFx::ResourceId *)(v14 + 72);
                Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                  this->pDispObj->pDefImpl.pObject,
                  &v65,
                  (Scaleform::GFx::ResourceId)rid);
                if ( v65.pCharDef )
                {
                  v27 = this->pDispObj;
                  v28 = v27->pASRoot->pASSupport.pObject;
                  v51 = *(_DWORD *)(v14 + 72);
                  v29 = ((__int64 (__fastcall *)(Scaleform::GFx::ASSupport *, Scaleform::GFx::MovieImpl *, Scaleform::GFx::CharacterCreateInfo *))v28->vfptr[4].__vecDelDtor)(
                          v28,
                          v27->pASRoot->pMovieImpl,
                          &v65);
                  v30 = (Scaleform::GFx::DisplayObjectBase *)v29;
                  v61 = v29;
                  if ( v29 )
                    ++*(_DWORD *)(v29 + 8);
                  v62 = v29;
                  v63 = v14;
                  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                    p_Data,
                    p_Data,
                    p_Data->Size + 1);
                  v31 = 16 * p_Data->Size;
                  v32 = (__int64)&p_Data->Data[-1];
                  v15 = v31 + v32 == 0;
                  v33 = (Scaleform::GFx::DisplayObjectBase **)(v31 + v32);
                  v57 = v33;
                  *(_QWORD *)&rid[0].Id = v33;
                  if ( !v15 )
                  {
                    if ( v30 )
                      ++v30->RefCount;
                    *v33 = v30;
                    v33[1] = (Scaleform::GFx::DisplayObjectBase *)v14;
                  }
                  if ( v30 )
                    Scaleform::RefCountNTSImpl::Release(v30);
                  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v30);
                  v35 = (unsigned int)((int)(Capacity - (Capacity & 0xFFFFF000) - 56) / 56);
                  v36 = *(_QWORD *)((Capacity & 0xFFFFFFFFFFFFF000ui64) + 0x20);
                  v37 = *(_QWORD *)(*(_QWORD *)(v36 + 8 * v35 + 40) + 144i64);
                  if ( v37 )
                  {
                    if ( (v37 & 1) != 0 )
                      v38 = *(_QWORD *)((v37 & 0xFFFFFFFFFFFFFFFEui64) + 8);
                    else
                      v38 = (*(_QWORD *)(*(_QWORD *)(v36 + 8 * v35 + 40) + 152i64) != 0i64) + 1i64;
                  }
                  else
                  {
                    v38 = 0i64;
                  }
                  Scaleform::Render::TreeContainer::Insert(
                    (Scaleform::Render::TreeContainer *)Capacity,
                    v38,
                    RenderNode);
                  if ( *(_QWORD *)(v14 + 64) )
                    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v30->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor)(v30);
                  v30->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
                    v30,
                    v14);
                  Scaleform::GFx::DisplayObjectBase::SetCxform(v30, (Scaleform::Render::Cxform *)(v14 + 32));
                  v30->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[16].__vecDelDtor(
                    v30,
                    *(_DWORD *)(v14 + 80));
                  v30->Flags &= ~1u;
                  for ( j = v30->pParent; j; j = j->pParent )
                  {
                    Scale9Grid = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(j, &v67);
                    if ( Scale9Grid->x2 > Scale9Grid->x1 && Scale9Grid->y2 > Scale9Grid->y1 )
                    {
                      v30->Flags |= 1u;
                      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v30->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[20].__vecDelDtor)(v30);
                      break;
                    }
                  }
                  v41 = 0i64;
                  if ( SLOBYTE(v30->Flags) < 0 )
                    v41 = (Scaleform::GFx::InteractiveObject *)v30;
                  if ( v41 )
                  {
                    Scaleform::GFx::AS2::AvmButton::ConstructCharacter(this, v41, (Scaleform::GFx::ButtonRecord *)v14);
                    Scaleform::GFx::InteractiveObject::AddToPlayList(v41);
                    Flags = v41->Flags;
                    if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
                      v42 = 0i64;
                    else
                      LOBYTE(v42) = 1;
                    v44 = (int)v41->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                                 v41,
                                 v42);
                    if ( v44 == -1 )
                    {
                      v41->Flags |= 0x400000u;
                    }
                    else if ( v44 == 1 )
                    {
                      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v41);
                    }
                    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v30->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[73].__vecDelDtor)(v30);
                  }
                  Scaleform::RefCountNTSImpl::Release(v30);
                }
              }
              else
              {
                Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  p_Data,
                  p_Data,
                  p_Data->Size + 1);
                v19 = 16 * p_Data->Size;
                v20 = (__int64)&p_Data->Data[-1];
                v15 = v19 + v20 == 0;
                v21 = (Scaleform::GFx::DisplayObjectBase **)(v19 + v20);
                *(_QWORD *)&rid[0].Id = v21;
                v57 = v21;
                if ( !v15 )
                {
                  ++v16->RefCount;
                  *v21 = v16;
                  v21[1] = (Scaleform::GFx::DisplayObjectBase *)Record;
                }
                v22 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v16);
                v23 = (unsigned int)((int)(Capacity - (Capacity & 0xFFFFF000) - 56) / 56);
                v24 = *(_QWORD *)((Capacity & 0xFFFFFFFFFFFFF000ui64) + 0x20);
                v25 = *(_QWORD *)(*(_QWORD *)(v24 + 8 * v23 + 40) + 144i64);
                if ( v25 )
                {
                  if ( (v25 & 1) != 0 )
                    v26 = *(_QWORD *)((v25 & 0xFFFFFFFFFFFFFFFEui64) + 8);
                  else
                    v26 = (*(_QWORD *)(*(_QWORD *)(v24 + 8 * v23 + 40) + 152i64) != 0i64) + 1i64;
                }
                else
                {
                  v26 = 0i64;
                }
                Scaleform::Render::TreeContainer::Insert((Scaleform::Render::TreeContainer *)Capacity, v26, v22);
                if ( *(_QWORD *)(v14 + 64) )
                  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v16->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor)(v16);
                v16->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
                  v16,
                  v14);
                Scaleform::GFx::DisplayObjectBase::SetCxform(v16, (Scaleform::Render::Cxform *)(v14 + 32));
                v16->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[16].__vecDelDtor(
                  v16,
                  *(_DWORD *)(v14 + 80));
              }
              if ( v16 )
                Scaleform::RefCountNTSImpl::Release(v16);
              pDef = v52;
              v2 = mouseState;
              v8 = v71;
            }
LABEL_85:
            v13 = v53 + 96;
            v53 += 96i64;
            if ( !--v54 )
            {
              pDispObj = v55;
              break;
            }
          }
        }
      }
      if ( v8 != Hit && !*(_QWORD *)(Capacity + 32) )
      {
        v45 = ((__int64 (__fastcall *)(Scaleform::GFx::Button *))pDispObj->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(pDispObj);
        v46 = (unsigned int)((int)(v45 - (v45 & 0xFFFFF000) - 56) / 56);
        v47 = *(_QWORD *)((v45 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
        v48 = *(_QWORD *)(*(_QWORD *)(v47 + 8 * v46 + 40) + 144i64);
        if ( v48 )
        {
          if ( (v48 & 1) != 0 )
            v49 = *(_QWORD *)((v48 & 0xFFFFFFFFFFFFFFFEui64) + 8);
          else
            v49 = (*(_QWORD *)(*(_QWORD *)(v47 + 8 * v46 + 40) + 152i64) != 0i64) + 1i64;
        }
        else
        {
          v49 = 0i64;
        }
        Scaleform::Render::TreeContainer::Insert(
          (Scaleform::Render::TreeContainer *)v45,
          v49,
          (Scaleform::Render::TreeNode *)Capacity);
      }
      if ( Capacity )
      {
        v15 = (*(_QWORD *)(Capacity + 8))-- == 1i64;
        if ( v15 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)Capacity);
      }
      ButtonState = v70;
    }
    v71 = ++v8;
    p_Data = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)((char *)p_Data + 32);
  }
  while ( (unsigned int)v8 < StatesCount );
  do
  {
    if ( v6 != ButtonState && v6 != Hit )
    {
      Scaleform::GFx::Button::UnloadCharactersForState(pDispObj, v6);
      ButtonState = v70;
    }
    ++v6;
  }
  while ( (unsigned int)v6 < StatesCount );
}

// File Line: 540
// RVA: 0x6F6390
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::GetStandardMemberBitMask(Scaleform::GFx::AS2::AvmButton *this)
{
  return 4026511311i64;
}

// File Line: 568
// RVA: 0x6F54F0
char __fastcall Scaleform::GFx::AS2::AvmButton::GetStandardMember(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *pval,
        bool opcodeFlag)
{
  bool v7; // bl
  Scaleform::Render::Rect<float> *Scale9Grid; // rax
  Scaleform::GFx::AS2::Environment *v10; // rsi
  __int64 v11; // rcx
  Scaleform::GFx::AS2::RectangleObject *v12; // rax
  Scaleform::GFx::AS2::RectangleObject *v13; // rax
  Scaleform::GFx::AS2::RectangleObject *v14; // rbx
  unsigned int RefCount; // eax
  Scaleform::Render::Rect<float> result; // [rsp+40h] [rbp-38h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-28h] BYREF

  if ( Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(this, member, pval, opcodeFlag) )
    return 1;
  if ( member != M_scale9Grid )
  {
    if ( member == M_hitTestDisable
      && *((_BYTE *)&this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this)[29].vfptr[1].__vecDelDtor
         + 8) == 1 )
    {
      v7 = (this->pDispObj->Flags & 0x800) != 0;
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = v7;
      return 1;
    }
    return 0;
  }
  if ( LOBYTE(this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this)[30].vfptr) >= 8u )
  {
    Scale9Grid = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj, &result);
    if ( Scale9Grid->x2 <= Scale9Grid->x1 || Scale9Grid->y2 <= Scale9Grid->y1 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 0;
    }
    else
    {
      v10 = (Scaleform::GFx::AS2::Environment *)this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this);
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(this->pDispObj, &result);
      v12 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))v10->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                      v11,
                                                      96i64);
      if ( v12 )
      {
        Scaleform::GFx::AS2::RectangleObject::RectangleObject(v12, v10);
        v14 = v13;
      }
      else
      {
        v14 = 0i64;
      }
      r.x1 = (float)(result.x1 * 0.050000001);
      r.y1 = (float)(result.y1 * 0.050000001);
      r.x2 = (float)(result.x2 * 0.050000001);
      r.y2 = (float)(result.y2 * 0.050000001);
      Scaleform::GFx::AS2::RectangleObject::SetProperties(v14, v10, &r);
      Scaleform::GFx::AS2::Value::SetAsObject(pval, v14);
      if ( v14 )
      {
        RefCount = v14->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v14->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v14);
        }
      }
    }
    return 1;
  }
  return 0;
}

// File Line: 625
// RVA: 0x71B4E0
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::SetStandardMember(
        Scaleform::GFx::AS2::AvmButton *this,
        Scaleform::GFx::AS2::AvmCharacter::StandardMember member,
        Scaleform::GFx::AS2::Value *origVal,
        bool opcodeFlag)
{
  __int64 v5; // rdi
  __int64 v7; // rax
  Scaleform::GFx::AS2::Environment *v8; // rsi
  Scaleform::GFx::ASString *v9; // rax
  char v10; // si
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::InteractiveObject *v13; // rdi
  Scaleform::GFx::AS2::Environment *v14; // rax
  Scaleform::GFx::AS2::Environment *v15; // rsi
  Scaleform::GFx::AS2::Object *v16; // rax
  Scaleform::GFx::AS2::RectangleObject *v17; // rdi
  float v18; // xmm1_4
  Scaleform::GFx::InteractiveObject *pDispObj; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int128 *v21; // rdx
  unsigned __int8 v22; // bl
  float v24; // [rsp+28h] [rbp-19h] BYREF
  float v25; // [rsp+2Ch] [rbp-15h]
  float v26; // [rsp+30h] [rbp-11h]
  float v27; // [rsp+34h] [rbp-Dh]
  __int128 v28; // [rsp+38h] [rbp-9h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+48h] [rbp+7h] BYREF
  Scaleform::GFx::AS2::Value newVal; // [rsp+68h] [rbp+27h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+67h] BYREF

  v5 = member;
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&newVal.NV + 24), origVal);
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  v8 = (Scaleform::GFx::AS2::Environment *)v7;
  if ( (int)v5 > 21
    && v7
    && Scaleform::GFx::AS2::AvmButton::GetButtonASObject(this)
    && this->ASButtonObj.pObject->pWatchpoints )
  {
    v.T.Type = 0;
    v9 = Scaleform::GFx::AS2::Environment::CreateConstString(
           v8,
           &result,
           Scaleform::GFx::AS2::AvmCharacter::MemberTable[v5].pName);
    v10 = Scaleform::GFx::AS2::Object::InvokeWatchpoint(this->ASButtonObj.pObject, v8, v9, &newVal, &v);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v10 )
      Scaleform::GFx::AS2::Value::operator=(&newVal, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(
         this,
         (Scaleform::GFx::AS2::AvmCharacter::StandardMember)v5,
         &newVal,
         opcodeFlag) )
  {
    goto LABEL_25;
  }
  if ( (_DWORD)v5 == 37 )
  {
    if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
                  + 240) >= 8u )
    {
      v15 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
      v16 = Scaleform::GFx::AS2::Value::ToObject(&newVal, v15);
      v17 = (Scaleform::GFx::AS2::RectangleObject *)v16;
      if ( v16
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v16->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v16->Scaleform::GFx::AS2::ObjectInterface) == 17 )
      {
        memset(&v, 0, sizeof(v));
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v17, v15, (Scaleform::Render::Rect<double> *)&v);
        v24 = (float)*(double *)&v.T.Type * 20.0;
        v25 = (float)v.NV.NumberValue * 20.0;
        v18 = *(double *)&v.V.FunctionValue.pLocalFrame - *(double *)&v.T.Type;
        v26 = (float)(v18 * 20.0) + v24;
        v27 = (float)((float)(*((double *)&v.NV + 3) - v.NV.NumberValue) * 20.0) + v25;
        pDispObj = this->pDispObj;
        vfptr = pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
        v21 = (__int128 *)&v24;
      }
      else
      {
        pDispObj = this->pDispObj;
        v28 = 0i64;
        vfptr = pDispObj->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
        v21 = &v28;
      }
      vfptr[19].__vecDelDtor(pDispObj, (unsigned int)v21);
      goto LABEL_25;
    }
LABEL_23:
    v22 = 0;
    goto LABEL_26;
  }
  if ( (_DWORD)v5 != 71
    || *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this)
                            + 232)
                + 104i64) != 1 )
  {
    goto LABEL_23;
  }
  v13 = this->pDispObj;
  v14 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
  if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v14) )
    v13->Flags |= 0x800u;
  else
    v13->Flags &= ~0x800u;
LABEL_25:
  v22 = 1;
LABEL_26:
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v22;
}

// File Line: 718
// RVA: 0x6C7D30
void __fastcall Scaleform::GFx::AS2::ButtonProto::ButtonProto(
        Scaleform::GFx::AS2::ButtonProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+78h] [rbp+10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ButtonObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ButtonObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ButtonProto::`vftable;
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    GAS_ButtonFunctionTable,
    &flags);
  flags.Flags = 3;
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl,
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 731
// RVA: 0x6E03A0
void __fastcall Scaleform::GFx::AS2::ButtonCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ButtonCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ButtonObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::ButtonObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ButtonCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                              this,
                                              104i64);
  if ( v3 )
    Scaleform::GFx::AS2::ButtonObject::ButtonObject(v3, penv);
}

// File Line: 736
// RVA: 0x70CD90
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ButtonCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ButtonProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int v16; // eax
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
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)_;
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
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  result->Flags = 0;
  result->Function = v6;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v9 = (Scaleform::GFx::AS2::ButtonProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                             pObject,
                                             168i64,
                                             0i64);
  pHeap = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::ButtonProto::ButtonProto(v9, &psc, v10, result);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  pHeap = (Scaleform::MemoryHeap *)v12;
  p_objproto = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Button,
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
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[9].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v12 )
  {
    v16 = v12->RefCount;
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      v12->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
    }
  }
  return result;
}

