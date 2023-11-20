// File Line: 120
// RVA: 0x6C7510
void __fastcall Scaleform::GFx::AS2::AvmButton::AvmButton(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::Button *pbutton)
{
  Scaleform::GFx::AS2::AvmButton *v2; // rbx
  Scaleform::GFx::AvmButtonBase *v3; // rax
  Scaleform::GFx::AS2::Environment *v4; // rdx
  Scaleform::GFx::InteractiveObject *v5; // rax
  signed __int64 v6; // rcx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rcx
  unsigned int v10; // eax

  v2 = this;
  Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(
    (Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&pbutton->vfptr);
  v3 = (Scaleform::GFx::AvmButtonBase *)&v2->vfptr;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmButtonBase::`vftable';
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v2->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmButton::`vftable';
  v4 = 0i64;
  v2->ASButtonObj.pObject = 0i64;
  v5 = v2->pDispObj->pParent;
  if ( v5 )
  {
    while ( !((v5->Flags >> 10) & 1) )
    {
      v5 = v5->pParent;
      if ( !v5 )
        goto LABEL_6;
    }
    v6 = (signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset;
    v4 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v6 + 240i64))(v6);
  }
LABEL_6:
  v7 = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
         (Scaleform::GFx::AS2::GlobalContext *)v2->pDispObj->pASRoot[2].vfptr,
         v4,
         ASBuiltin_Button);
  v8 = v7;
  if ( v7 )
    v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
  v9 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->pProto.pObject->vfptr;
  if ( v9 )
  {
    v10 = v9->RefCount;
    if ( v10 & 0x3FFFFFF )
    {
      v9->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  v2->pProto.pObject = v8;
}

// File Line: 135
// RVA: 0x7065A0
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::OnMouseEvent(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::EventId *v2; // rdi
  Scaleform::GFx::AS2::AvmButton *v3; // rsi
  unsigned __int8 v4; // r12
  signed int v5; // er9
  int v6; // er11
  unsigned int v7; // eax
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v8; // r8
  bool (__fastcall *v9)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // rdx
  bool (__fastcall *v10)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // r10
  Scaleform::GFx::AvmButtonBase *(__fastcall *v11)(Scaleform::GFx::AvmDisplayObjBase *); // rcx
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
  signed __int64 v25; // rbx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v26; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v27; // rbx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v28; // rdi
  Scaleform::RefCountNTSImpl *v29; // rcx
  Scaleform::RefCountNTSImpl *v30; // rcx
  Scaleform::GFx::ASStringNode *v31; // rcx
  bool v32; // zf
  __int128 v34; // [rsp+20h] [rbp-C8h]
  int v35; // [rsp+30h] [rbp-B8h]
  __int64 v36; // [rsp+40h] [rbp-A8h]
  bool (__fastcall *v37)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // [rsp+48h] [rbp-A0h]
  unsigned __int64 v38; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::AvmButtonBase *(__fastcall *v39)(Scaleform::GFx::AvmDisplayObjBase *); // [rsp+58h] [rbp-90h]
  Scaleform::GFx::AS2::Value v40; // [rsp+80h] [rbp-68h]
  Scaleform::GFx::AS2::AvmButton *v41; // [rsp+F0h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+F8h] [rbp+10h]
  int v43; // [rsp+100h] [rbp+18h]
  int v44; // [rsp+108h] [rbp+20h]

  result.pNode = (Scaleform::GFx::ASStringNode *)event;
  v41 = this;
  v2 = event;
  v3 = this;
  v4 = 0;
  if ( !event->RollOverCnt )
  {
    v5 = 0;
    v43 = 0;
    v6 = 0;
    v44 = 0;
    v7 = event->Id;
    if ( event->Id == 0x2000 )
    {
      v5 = 1;
      v43 = 1;
    }
    else
    {
      switch ( v7 )
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
          v6 = Scaleform::GFx::EventId::ConvertToButtonKeyCode(event);
          v44 = v6;
          v5 = v43;
          break;
      }
    }
    v8 = v3[-1].vfptr;
    v9 = v8->HasEventHandler;
    if ( v9 )
    {
      v10 = 0i64;
      if ( (*((_WORD *)v9 + 53) >> 10) & 1 )
        v10 = v8->HasEventHandler;
      v37 = v10;
      if ( v10 )
      {
        v11 = v8[2].ToAvmButttonBase;
        v39 = v11;
        v12 = 0i64;
        v38 = *((_QWORD *)v11 + 8);
        v13 = v6;
        v36 = v6;
        if ( v38 )
        {
          do
          {
            v14 = *(_QWORD *)(*((_QWORD *)v11 + 7) + 8 * v12);
            if ( v5 & *(_DWORD *)(v14 + 16) & 0xFFFF01FF || v13 > 0 && ((*(_DWORD *)(v14 + 16) >> 9) & 0x7F) == v6 )
            {
              v15 = (Scaleform::GFx::AS2::AvmSprite *)((char *)v10 + 4 * *((unsigned __int8 *)v10 + 109));
              v17 = (Scaleform::GFx::AS2::ASStringContext *)(((__int64 (__fastcall *)(signed __int64))v15->vfptr[2].GetAbsolutePath)((signed __int64)v10 + 4 * *((unsigned __int8 *)v10 + 109))
                                                           + 232);
              v18 = *(_QWORD *)(v14 + 32);
              v19 = 0i64;
              if ( v18 )
              {
                do
                {
                  v20 = *(_QWORD *)(*(_QWORD *)(v14 + 24) + 8 * v19);
                  if ( *(_DWORD *)(v20 + 24) >= 1u && **(_BYTE **)(v20 + 16) )
                  {
                    v21 = (Scaleform::GFx::AS2::ActionBuffer *)((__int64 (__fastcall *)(__int64, signed __int64))v17->pContext->pHeap->vfptr->Alloc)(
                                                                 v16,
                                                                 64i64);
                    if ( v21 )
                    {
                      Scaleform::GFx::AS2::ActionBuffer::ActionBuffer(
                        v21,
                        v17,
                        *(Scaleform::GFx::AS2::ActionBufferData **)(*(_QWORD *)(v14 + 24) + 8 * v19));
                      v23 = v22;
                    }
                    else
                    {
                      v23 = 0i64;
                    }
                    Scaleform::GFx::AS2::AvmSprite::AddActionBuffer(v15, v23, AP_Frame);
                    if ( v23 )
                      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v23->vfptr);
                  }
                  ++v19;
                }
                while ( v19 < v18 );
                if ( v18 )
                  v4 = 1;
              }
              v13 = v36;
              v6 = v44;
              v10 = v37;
              v5 = v43;
            }
            ++v12;
            v11 = v39;
          }
          while ( v12 < v38 );
          v2 = (Scaleform::GFx::EventId *)result.pNode;
          v3 = v41;
        }
      }
    }
  }
  v24 = ((__int64 (*)(void))v3[-1].pProto.pObject[2].Members.mHash.pTable)();
  if ( v24 )
  {
    v25 = v24 + 232;
    Scaleform::GFx::AS2::EventId_GetFunctionName(
      &result,
      (Scaleform::GFx::AS2::StringManager *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v24 + 232) + 40i64) + 24i64) + 312i64),
      v2);
    if ( result.pNode->Size )
    {
      v40.T.Type = 0;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject **, signed __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v3[-1].pDispObj->pPerspectiveData)(
             &v3[-1].pDispObj,
             v25,
             &result,
             &v40) )
      {
        v4 = 1;
        v26 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)v3[-1].vfptr->ToAvmTextFieldBase + 128),
                AP_Frame);
        v27 = v26;
        if ( v26 )
        {
          v34 = *(_OWORD *)&v2->Id;
          v35 = *(_DWORD *)&v2->RollOverCnt;
          v28 = v3[-1].vfptr;
          v26->Type = 2;
          if ( v28 )
            ++*((_DWORD *)&v28->__vecDelDtor + 2);
          v29 = (Scaleform::RefCountNTSImpl *)&v26->pCharacter.pObject->vfptr;
          if ( v29 )
            Scaleform::RefCountNTSImpl::Release(v29);
          v27->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v28;
          v30 = (Scaleform::RefCountNTSImpl *)&v27->pActionBuffer.pObject->vfptr;
          if ( v30 )
            Scaleform::RefCountNTSImpl::Release(v30);
          v27->pActionBuffer.pObject = 0i64;
          *(_QWORD *)&v27->mEventId.Id = v34;
          v27->mEventId.KeyCode = DWORD2(v34);
          v27->mEventId.AsciiCode = BYTE12(v34);
          *(_DWORD *)&v27->mEventId.RollOverCnt = v35;
        }
      }
      if ( v40.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v40);
    }
    v31 = result.pNode;
    v32 = result.pNode->RefCount == 1;
    --v31->RefCount;
    if ( v32 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  }
  return v4;
}

// File Line: 219
// RVA: 0x6DF0F0
void __usercall Scaleform::GFx::AS2::AvmButton::ConstructCharacter(Scaleform::GFx::AS2::AvmButton *this@<rcx>, Scaleform::GFx::InteractiveObject *pscriptCh@<rdx>, Scaleform::GFx::ButtonRecord *rec@<r8>, __int64 a4@<r15>)
{
  Scaleform::GFx::ButtonRecord *v4; // rbx
  Scaleform::GFx::InteractiveObject *v5; // rdi
  Scaleform::GFx::AS2::AvmButton *v6; // r12
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *v7; // r13
  Scaleform::GFx::AS2::FunctionObject *v8; // r14
  Scaleform::GFx::AS2::LocalFrame *v9; // rsi
  Scaleform::GFx::MovieDefImpl *v10; // rax
  Scaleform::String *v11; // rbx
  Scaleform::GFx::AS2::Environment *v12; // rax
  signed __int64 v13; // rbx
  __int64 v14; // r10
  __int64 v15; // rbx
  __int64 v16; // r11
  __int64 v17; // r8
  __int64 *v18; // r9
  Scaleform::GFx::ASStringNode *v19; // rdx
  signed __int64 v20; // rdx
  Scaleform::GFx::ASStringNode *v21; // rax
  signed __int64 v22; // rax
  Scaleform::GFx::AS2::FunctionRefBase *v23; // rdx
  Scaleform::GFx::AS2::ObjectInterface *v24; // rbx
  signed __int64 v25; // rcx
  Scaleform::GFx::AS2::AvmCharacter *v26; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v27; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v28; // rbx
  Scaleform::RefCountNTSImpl *v29; // rcx
  Scaleform::RefCountNTSImpl *v30; // rcx
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v31; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v32; // rbx
  Scaleform::RefCountNTSImpl *v33; // rcx
  Scaleform::RefCountNTSImpl *v34; // rcx
  char v35; // bl
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v36; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v37; // rbx
  Scaleform::RefCountNTSImpl *v38; // rcx
  Scaleform::RefCountNTSImpl *v39; // rcx
  Scaleform::GFx::ASStringNode *v40; // rcx
  bool v41; // zf
  unsigned int v42; // eax
  unsigned int v43; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+30h] [rbp-50h]
  Scaleform::GFx::AS2::FunctionRefBase orig; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value v; // [rsp+60h] [rbp-20h]
  Scaleform::GFx::ResourceId rid; // [rsp+C8h] [rbp+48h]
  Scaleform::GFx::ASString result; // [rsp+D8h] [rbp+58h]

  v4 = rec;
  v5 = pscriptCh;
  v6 = this;
  if ( !((pscriptCh->Flags >> 10) & 1) )
    return;
  v7 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)((__int64 (__cdecl *)(Scaleform::GFx::AS2::AvmButton *))this->vfptr[1].OnUnloading)(this);
  LOBYTE(a4) = 0;
  orig.Flags = 0;
  v8 = 0i64;
  orig.Function = 0i64;
  v9 = 0i64;
  orig.pLocalFrame = 0i64;
  rid.Id = v4->CharacterId.Id;
  v10 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->vfptr[66].__vecDelDtor)(v5);
  v11 = Scaleform::GFx::MovieDefImpl::GetNameOfExportedResource(v10, (Scaleform::GFx::ResourceId)&rid);
  if ( v11 )
  {
    v12 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6);
    Scaleform::GFx::AS2::Environment::CreateString(v12, &result, v11);
    v13 = (signed __int64)&v7[3];
    if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6) + 240) <= 6u )
    {
      *(_QWORD *)&rid.Id = &result;
      v21 = result.pNode;
      if ( !result.pNode->pLower )
      {
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(result.pNode);
        v21 = result.pNode;
      }
      if ( !*(_QWORD *)v13 )
        goto LABEL_35;
      v22 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString::NoCaseKey>(
              v7 + 3,
              (Scaleform::GFx::ASString::NoCaseKey *)&rid,
              v21->HashFlags & *(_QWORD *)(*(_QWORD *)v13 + 8i64));
      if ( v22 < 0 )
        goto LABEL_35;
      v20 = *(_QWORD *)v13 + 8 * (5 * v22 + 3);
    }
    else
    {
      v14 = *(_QWORD *)v13;
      if ( !*(_QWORD *)v13 )
        goto LABEL_35;
      v15 = *(_QWORD *)(v14 + 8);
      v16 = (unsigned int)v15 & result.pNode->HashFlags;
      v17 = v16;
      v18 = (__int64 *)(v14 + 8 * (v16 + 4 * v16 + 2));
      if ( *v18 == -2 || ((unsigned int)v15 & *(_DWORD *)(v18[1] + 28)) != v16 )
        goto LABEL_35;
      while ( 1 )
      {
        v19 = (Scaleform::GFx::ASStringNode *)v18[1];
        if ( ((unsigned int)v15 & v19->HashFlags) == v16 && v19 == result.pNode )
          break;
        v17 = *v18;
        if ( *v18 == -1 )
          goto LABEL_35;
        v18 = (__int64 *)(v14 + 8 * (v17 + 4 * v17 + 2));
      }
      if ( v17 < 0 )
        goto LABEL_35;
      v20 = v14 + 8 * (v17 + 4 * v17 + 3);
    }
    if ( v20 )
    {
      v23 = (Scaleform::GFx::AS2::FunctionRefBase *)(v20 + 8);
      if ( v23 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&orig, v23);
        v8 = orig.Function;
        v24 = (Scaleform::GFx::AS2::ObjectInterface *)&orig.Function->vfptr;
        if ( !orig.Function )
          v24 = 0i64;
        v25 = (signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset;
        v26 = (Scaleform::GFx::AS2::AvmCharacter *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v25 + 8i64))(v25);
        Scaleform::GFx::AS2::AvmCharacter::SetProtoToPrototypeOf(v26, v24);
        v27 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v6->pDispObj->pASRoot[3].RefCount,
                AP_Construct);
        v28 = v27;
        if ( v27 )
        {
          v27->Type = 2;
          ++v5->RefCount;
          v29 = (Scaleform::RefCountNTSImpl *)&v27->pCharacter.pObject->vfptr;
          if ( v29 )
            Scaleform::RefCountNTSImpl::Release(v29);
          v28->pCharacter.pObject = v5;
          v30 = (Scaleform::RefCountNTSImpl *)&v28->pActionBuffer.pObject->vfptr;
          if ( v30 )
            Scaleform::RefCountNTSImpl::Release(v30);
          v28->pActionBuffer.pObject = 0i64;
          *(_QWORD *)&v28->mEventId.Id = 0x40000i64;
          v28->mEventId.KeyCode = 0;
          v28->mEventId.AsciiCode = 0;
          *(_DWORD *)&v28->mEventId.RollOverCnt = 65280;
        }
        v31 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v6->pDispObj->pASRoot[3].RefCount,
                AP_Construct);
        v32 = v31;
        if ( v31 )
        {
          v31->Type = 3;
          ++v5->RefCount;
          v33 = (Scaleform::RefCountNTSImpl *)&v31->pCharacter.pObject->vfptr;
          if ( v33 )
            Scaleform::RefCountNTSImpl::Release(v33);
          v32->pCharacter.pObject = v5;
          v34 = (Scaleform::RefCountNTSImpl *)&v32->pActionBuffer.pObject->vfptr;
          if ( v34 )
            Scaleform::RefCountNTSImpl::Release(v34);
          v32->pActionBuffer.pObject = 0i64;
          Scaleform::GFx::AS2::FunctionRefBase::Assign(
            (Scaleform::GFx::AS2::FunctionRefBase *)&v32->Function.Function,
            &orig);
        }
        LOBYTE(a4) = orig.Flags;
        v9 = orig.pLocalFrame;
        goto LABEL_46;
      }
    }
LABEL_35:
    *(_QWORD *)&rid.Id = &pheapAddr;
    pheapAddr.Data = 0i64;
    *(_OWORD *)&pheapAddr.Size = 0ui64;
    v35 = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
    ++v.V.pStringNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    *(_QWORD *)&rid.Id = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( *(_QWORD *)&rid.Id )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, (__int64)v5);
      v35 = v.T.Type;
    }
    if ( (unsigned __int8)v35 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v36 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
            (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v6->pDispObj->pASRoot[3].RefCount,
            AP_Construct);
    v37 = v36;
    if ( v36 )
    {
      v36->Type = 4;
      ++v5->RefCount;
      v38 = (Scaleform::RefCountNTSImpl *)&v36->pCharacter.pObject->vfptr;
      if ( v38 )
        Scaleform::RefCountNTSImpl::Release(v38);
      v37->pCharacter.pObject = v5;
      v39 = (Scaleform::RefCountNTSImpl *)&v37->pActionBuffer.pObject->vfptr;
      if ( v39 )
        Scaleform::RefCountNTSImpl::Release(v39);
      v37->pActionBuffer.pObject = 0i64;
      v37->CFunction = Scaleform::GFx::AS2::AvmSprite::FindClassAndInitializeClassInstance;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v37->FunctionParams.Data,
        (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
        (__int64)v5,
        (__int64)v6,
        0i64,
        0i64,
        a4);
    }
    *(_QWORD *)&rid.Id = &pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
LABEL_46:
    v40 = result.pNode;
    v41 = result.pNode->RefCount == 1;
    --v40->RefCount;
    if ( v41 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  }
  if ( !(a4 & 2) )
  {
    if ( v8 )
    {
      v42 = v8->RefCount;
      if ( v42 & 0x3FFFFFF )
      {
        v8->RefCount = v42 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr);
      }
    }
  }
  orig.Function = 0i64;
  if ( !(a4 & 1) && v9 )
  {
    v43 = v9->RefCount;
    if ( v43 & 0x3FFFFFF )
    {
      v9->RefCount = v43 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
    }
  }
}

// File Line: 264
// RVA: 0x705700
char __fastcall Scaleform::GFx::AS2::AvmButton::OnButtonKeyEvent(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::EventId *id, int *__formal)
{
  Scaleform::GFx::EventId *v3; // rdi
  Scaleform::GFx::AS2::AvmButton *v4; // rsi
  __int64 v5; // rbx
  Scaleform::GFx::MovieImpl *v6; // rbp
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v7; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v8; // rbx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v9; // rdi
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::RefCountNTSImpl *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  __int128 v15; // [rsp+30h] [rbp-58h]
  int v16; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::AS2::Value v17; // [rsp+50h] [rbp-38h]
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp+8h]

  v3 = id;
  v4 = this;
  v5 = ((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::Object> *, Scaleform::GFx::EventId *, int *))this[-1].pProto.pObject[2].Members.mHash.pTable)(
         &this[-1].pProto,
         id,
         __formal);
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 232) + 40i64) + 24i64) + 312i64),
    v3);
  v6 = (Scaleform::GFx::MovieImpl *)*((_QWORD *)v4[-1].vfptr->ToAvmTextFieldBase + 2);
  if ( result.pNode->Size )
  {
    v17.T.Type = 0;
    if ( !((v3->Id - 64) & 0xFFFFFFBF) )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::InteractiveObject **, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v4[-1].pDispObj->pPerspectiveData)(
             &v4[-1].pDispObj,
             v5 + 232,
             &result,
             &v17) )
      {
        if ( *(_BYTE *)(v5 + 240) >= 6u
          && Scaleform::GFx::MovieImpl::IsKeyboardFocused(
               v6,
               (Scaleform::GFx::InteractiveObject *)v4[-1].vfptr,
               v3->ControllerIndex) )
        {
          v7 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)((char *)v4[-1].vfptr->ToAvmTextFieldBase + 128),
                 AP_Frame);
          v8 = v7;
          if ( v7 )
          {
            v15 = *(_OWORD *)&v3->Id;
            v16 = *(_DWORD *)&v3->RollOverCnt;
            v9 = v4[-1].vfptr;
            v7->Type = 2;
            if ( v9 )
              ++*((_DWORD *)&v9->__vecDelDtor + 2);
            v10 = (Scaleform::RefCountNTSImpl *)&v7->pCharacter.pObject->vfptr;
            if ( v10 )
              Scaleform::RefCountNTSImpl::Release(v10);
            v8->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v9;
            v11 = (Scaleform::RefCountNTSImpl *)&v8->pActionBuffer.pObject->vfptr;
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
  v12 = result.pNode;
  v13 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v13 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  return 1;
}

// File Line: 295
// RVA: 0x6EEF60
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::GetCursorType(Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AS2::AvmButton *v1; // rbx
  __int64 v2; // rax
  Scaleform::GFx::AS2::Environment *v3; // rdi
  signed __int64 v4; // rdx
  __int64 v5; // r8
  signed __int64 v6; // rcx
  Scaleform::GFx::AS2::Object *v7; // rcx
  unsigned int v8; // ebx
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h]

  v1 = this;
  v2 = ((__int64 (__cdecl *)(Scaleform::GFx::AS2::AvmButton *))this->vfptr[2].ToAvmDispContainerBase)(this);
  v3 = (Scaleform::GFx::AS2::Environment *)v2;
  v10.T.Type = 0;
  if ( !v2 || !((v1->pDispObj->Flags >> 4) & 1) )
    goto LABEL_10;
  if ( v1->ASButtonObj.pObject )
  {
    v4 = v2 + 232;
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 232) + 40i64) + 24i64);
    v6 = (signed __int64)&v1->vfptr;
  }
  else
  {
    v7 = v1->pProto.pObject;
    if ( !v7 )
      goto LABEL_8;
    v6 = (signed __int64)&v7->vfptr;
    v4 = v2 + 232;
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 232) + 40i64) + 24i64);
  }
  (*(void (__fastcall **)(signed __int64, signed __int64, __int64, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v6 + 88i64))(
    v6,
    v4,
    v5 + 1336,
    &v10);
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
Scaleform::GFx::AS2::ButtonObject *__fastcall Scaleform::GFx::AS2::AvmButton::GetButtonASObject(Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AS2::AvmButton *v1; // rdi
  Scaleform::GFx::AS2::ButtonObject *v2; // rsi
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::GlobalContext *v4; // rax
  Scaleform::GFx::AS2::ButtonObject *v5; // rax
  Scaleform::GFx::AS2::ButtonObject *v6; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // rcx
  unsigned int v8; // eax
  int v10; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::AS2::ButtonObject *v11; // [rsp+60h] [rbp+18h]

  v1 = this;
  if ( this->ASButtonObj.pObject )
    return this->ASButtonObj.pObject;
  v10 = 323;
  v2 = (Scaleform::GFx::AS2::ButtonObject *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::AvmButton *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              104i64,
                                              &v10,
                                              -2i64);
  v11 = v2;
  if ( v2 )
  {
    v3 = v1->pDispObj;
    v4 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v1->vfptr[1].OnUnloading)(v1);
    Scaleform::GFx::AS2::ButtonObject::ButtonObject(v2, v4, v3);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ASButtonObj.pObject->vfptr;
  if ( v7 )
  {
    v8 = v7->RefCount;
    if ( v8 & 0x3FFFFFF )
    {
      v7->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
    }
  }
  v1->ASButtonObj.pObject = v6;
  return v6;
}

// File Line: 324
// RVA: 0x6EE310
Scaleform::GFx::AS2::ButtonObject *__fastcall Scaleform::GFx::AS2::AvmButton::GetASObject(Scaleform::GFx::AS2::AvmButton *this)
{
  return Scaleform::GFx::AS2::AvmButton::GetButtonASObject(this);
}

// File Line: 333
// RVA: 0x6F0060
char __fastcall Scaleform::GFx::AS2::AvmButton::GetMember(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::Value *v4; // r15
  Scaleform::GFx::ASString *v5; // r14
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::AS2::AvmButton *v7; // rbp
  Scaleform::GFx::AS2::ButtonObject *v8; // rdi
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v9; // eax
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v10; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v12; // rcx
  Scaleform::GFx::AS2::GlobalContext *v13; // rdx

  v4 = pval;
  v5 = name;
  v6 = penv;
  v7 = this;
  if ( (name->pNode->HashFlags >> 29) & 1 )
  {
    v8 = this[-1].ASButtonObj.pObject;
    v9 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
           (Scaleform::GFx::AS2::AvmCharacter *)&this[-1].ASButtonObj,
           name);
    if ( (*(unsigned __int8 (__fastcall **)(Scaleform::Ptr<Scaleform::GFx::AS2::ButtonObject> *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))&v8[2].ResolveHandler.Flags)(
           &v7[-1].ASButtonObj,
           v9,
           v4,
           0i64) )
    {
      return 1;
    }
  }
  v10 = v7->vfptr;
  if ( v10 )
    return (*((__int64 (__fastcall **)(Scaleform::GFx::AvmTextFieldBase *(__fastcall **)(Scaleform::GFx::AvmDisplayObjBase *), Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v10->ToAvmTextFieldBase
            + 4))(
             &v10->ToAvmTextFieldBase,
             v6,
             v5,
             v4);
  if ( v6
    && v5->pNode == (Scaleform::GFx::ASStringNode *)v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl )
  {
    Scaleform::GFx::AS2::Value::SetAsObject(v4, (Scaleform::GFx::AS2::Object *)v7->vfptr);
    return 1;
  }
  v12 = v7->vfptr;
  if ( v12
    && (*((unsigned __int8 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v12->GetMember
        + 4))(
         (signed __int64)&v12->GetMember,
         v6,
         v5,
         v4) )
  {
    return 1;
  }
  if ( !v6 )
    return 0;
  v13 = v6->StringContext.pContext;
  if ( v5->pNode != (Scaleform::GFx::ASStringNode *)v13->pMovieRoot->pASMovieRoot.pObject[20].pMovieImpl )
    return 0;
  Scaleform::GFx::AS2::Value::SetAsObject(v4, v13->pGlobal.pObject);
  return 1;
}

// File Line: 374
// RVA: 0x6DF7E0
void __fastcall Scaleform::GFx::AS2::AvmButton::CreateCharacters(Scaleform::GFx::AS2::AvmButton *this)
{
  Scaleform::GFx::AS2::AvmButton::RecreateCharacters((Scaleform::GFx::AS2::AvmButton *)((char *)this - 40), 0);
}

// File Line: 379
// RVA: 0x721210
void __fastcall Scaleform::GFx::AS2::AvmButton::SwitchState(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  Scaleform::GFx::AS2::AvmButton::RecreateCharacters((Scaleform::GFx::AS2::AvmButton *)((char *)this - 40), mouseState);
}

// File Line: 384
// RVA: 0x6EA3F0
Scaleform::GFx::Button::CharToRec *__fastcall Scaleform::GFx::AS2::AvmButton::FindCharacterAndRemove(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::Button::CharToRec *result, Scaleform::GFx::ButtonRecord *rec)
{
  Scaleform::GFx::Button::CharToRec *v3; // r15
  unsigned int v4; // er9
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v5; // rdi
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rcx
  Scaleform::GFx::ButtonRecord **v8; // rax
  signed __int64 v9; // r14
  Scaleform::GFx::Button::CharToRec *v10; // rcx
  Scaleform::GFx::DisplayObjectBase *v11; // rax
  Scaleform::RefCountNTSImpl *v12; // rsi
  Scaleform::GFx::ButtonRecord *v13; // rbp
  Scaleform::RefCountNTSImpl *v14; // rcx

  v3 = result;
  v4 = 0;
  v5 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&this->pDispObj[1].pWeakProxy;
  while ( 1 )
  {
    if ( v4 != 3 )
    {
      v6 = 0i64;
      v7 = v5->Size;
      if ( v7 )
        break;
    }
LABEL_7:
    ++v4;
    v5 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v5 + 32);
    if ( v4 >= 4 )
    {
      result->Char.pObject = 0i64;
      return v3;
    }
  }
  v8 = &v5->Data->Record;
  while ( *v8 != rec )
  {
    ++v6;
    v8 += 2;
    if ( v6 >= v7 )
      goto LABEL_7;
  }
  v9 = v6;
  v10 = v5->Data;
  v11 = v5->Data[v6].Char.pObject;
  if ( v11 )
    ++v11->RefCount;
  v12 = (Scaleform::RefCountNTSImpl *)&v10[v9].Char.pObject->vfptr;
  v13 = v10[v9].Record;
  if ( v5->Size == 1 )
  {
    Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      v5,
      v5,
      0i64);
  }
  else
  {
    v14 = (Scaleform::RefCountNTSImpl *)&v5->Data[v9].Char.pObject->vfptr;
    if ( v14 )
      Scaleform::RefCountNTSImpl::Release(v14);
    memmove(&v5->Data[v9], &v5->Data[v9 + 1], 16 * (v5->Size - v6 - 1));
    --v5->Size;
  }
  if ( v12 )
    ++v12->RefCount;
  v3->Char.pObject = (Scaleform::GFx::DisplayObjectBase *)v12;
  v3->Record = v13;
  if ( v12 )
    Scaleform::RefCountNTSImpl::Release(v12);
  return v3;
}

// File Line: 408
// RVA: 0x70B820
void __fastcall Scaleform::GFx::AS2::AvmButton::RecreateCharacters(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  Scaleform::GFx::ButtonRecord::MouseState v2; // esi
  Scaleform::GFx::Button *v3; // r14
  __int64 v4; // r15
  Scaleform::GFx::Button::ButtonState v5; // eax
  Scaleform::GFx::Button::ButtonState v6; // er12
  Scaleform::GFx::Button::ButtonState v7; // ebx
  Scaleform::GFx::Button::ButtonState v8; // edi
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v9; // r13
  unsigned __int64 v10; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v11; // rax
  Scaleform::Render::TreeContainer *v12; // rcx
  __int64 v13; // r14
  __int64 v14; // r14
  bool v15; // zf
  Scaleform::GFx::DisplayObjectBase *v16; // r15
  Scaleform::GFx::Button::CharToRec *v17; // rax
  Scaleform::GFx::ButtonRecord *v18; // rdi
  signed __int64 v19; // rcx
  signed __int64 v20; // rdx
  Scaleform::GFx::DisplayObjectBase **v21; // rdx
  Scaleform::Render::TreeNode *v22; // r9
  unsigned __int64 v23; // rcx
  __int64 v24; // rax
  __int64 v25; // rdx
  unsigned __int64 v26; // rdx
  Scaleform::GFx::InteractiveObject *v27; // r9
  Scaleform::GFx::ASSupport *v28; // rcx
  __int64 v29; // rax
  Scaleform::GFx::DisplayObjectBase *v30; // rdi
  signed __int64 v31; // rcx
  signed __int64 v32; // rdx
  Scaleform::GFx::DisplayObjectBase **v33; // rdx
  Scaleform::Render::TreeNode *v34; // r9
  unsigned __int64 v35; // rcx
  __int64 v36; // rax
  __int64 v37; // rdx
  unsigned __int64 v38; // rdx
  Scaleform::GFx::DisplayObjectBase *i; // rsi
  Scaleform::Render::Rect<float> *v40; // rax
  Scaleform::GFx::InteractiveObject *v41; // rsi
  __int64 v42; // rdx
  int v43; // eax
  __int64 v44; // rax
  Scaleform::Render::TreeContainer *v45; // r9
  unsigned __int64 v46; // rcx
  __int64 v47; // rax
  __int64 v48; // rdx
  unsigned __int64 v49; // rdx
  Scaleform::GFx::ResourceId rid[2]; // [rsp+30h] [rbp-99h]
  int v51; // [rsp+38h] [rbp-91h]
  Scaleform::GFx::ButtonDef *v52; // [rsp+40h] [rbp-89h]
  __int64 v53; // [rsp+48h] [rbp-81h]
  __int64 v54; // [rsp+50h] [rbp-79h]
  Scaleform::GFx::Button *v55; // [rsp+58h] [rbp-71h]
  Scaleform::Render::TreeContainer *v56; // [rsp+60h] [rbp-69h]
  Scaleform::GFx::DisplayObjectBase **v57; // [rsp+68h] [rbp-61h]
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [rsp+70h] [rbp-59h]
  Scaleform::GFx::DisplayObjectBase *v59; // [rsp+78h] [rbp-51h]
  Scaleform::GFx::ButtonRecord *v60; // [rsp+80h] [rbp-49h]
  __int64 v61; // [rsp+88h] [rbp-41h]
  __int64 v62; // [rsp+90h] [rbp-39h]
  __int64 v63; // [rsp+98h] [rbp-31h]
  __int64 v64; // [rsp+A0h] [rbp-29h]
  Scaleform::GFx::CharacterCreateInfo v65; // [rsp+A8h] [rbp-21h]
  Scaleform::GFx::Button::CharToRec v66; // [rsp+C0h] [rbp-9h]
  Scaleform::Render::Rect<float> v67; // [rsp+D0h] [rbp+7h]
  Scaleform::GFx::AS2::AvmButton *v68; // [rsp+130h] [rbp+67h]
  Scaleform::GFx::ButtonRecord::MouseState v69; // [rsp+138h] [rbp+6Fh]
  Scaleform::GFx::Button::ButtonState v70; // [rsp+140h] [rbp+77h]
  Scaleform::GFx::Button::ButtonState v71; // [rsp+148h] [rbp+7Fh]

  v69 = mouseState;
  v68 = this;
  v64 = -2i64;
  v2 = mouseState;
  v3 = (Scaleform::GFx::Button *)this->pDispObj;
  v55 = v3;
  v4 = (__int64)v3->pDef;
  v52 = v3->pDef;
  v5 = Scaleform::GFx::Button::GetButtonState(mouseState);
  v70 = v5;
  v6 = 0;
  v7 = 0;
  do
  {
    if ( v7 != v5 && v7 != 3 )
    {
      Scaleform::GFx::Button::ClearRenderTreeForState(v3, v7);
      v5 = v70;
    }
    ++v7;
  }
  while ( (unsigned int)v7 < 4 );
  v8 = 0;
  v71 = 0;
  v9 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&v3->States[0].Characters.Data.Data;
  do
  {
    if ( v8 == v5 || v8 == 3 )
    {
      v10 = v9[-1].Policy.Capacity;
      if ( v10 )
        ++*(_QWORD *)(v10 + 8);
      v56 = (Scaleform::Render::TreeContainer *)v10;
      if ( !v9->Size )
      {
        if ( !v10 )
        {
          v11 = Scaleform::GFx::Button::CreateStateRenderContainer(v3, &result, v8);
          if ( v11->pObject )
            ++v11->pObject->RefCount;
          v10 = (unsigned __int64)v11->pObject;
          v56 = v11->pObject;
          v12 = result.pObject;
          if ( result.pObject )
          {
            v15 = result.pObject->RefCount-- == 1;
            if ( v15 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v12->0);
          }
        }
        v54 = *(_QWORD *)(v4 + 40);
        if ( v54 )
        {
          v13 = 0i64;
          v53 = 0i64;
          while ( 1 )
          {
            v14 = *(_QWORD *)(v4 + 32) + v13;
            if ( v8 == 3 )
            {
              v15 = (*(_BYTE *)(v14 + 84) & 1) == 0;
            }
            else
            {
              if ( v2 == MouseUp )
              {
                if ( *(_BYTE *)(v14 + 84) & 8 )
                  goto LABEL_31;
                goto LABEL_85;
              }
              if ( v2 == 1 )
              {
                if ( *(_BYTE *)(v14 + 84) & 2 )
                  goto LABEL_31;
                goto LABEL_85;
              }
              if ( v2 != 2 )
                goto LABEL_85;
              v15 = (*(_BYTE *)(v14 + 84) & 4) == 0;
            }
            if ( !v15 )
            {
LABEL_31:
              v16 = 0i64;
              v59 = 0i64;
              if ( v8 == 3 )
                goto LABEL_106;
              v17 = Scaleform::GFx::AS2::AvmButton::FindCharacterAndRemove(
                      v68,
                      &v66,
                      (Scaleform::GFx::ButtonRecord *)v14);
              if ( v17->Char.pObject )
                ++v17->Char.pObject->RefCount;
              v16 = v17->Char.pObject;
              v59 = v17->Char.pObject;
              v18 = v17->Record;
              v60 = v17->Record;
              if ( v66.Char.pObject )
                Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v66.Char.pObject->vfptr);
              if ( v16 )
              {
                Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
                  v9,
                  v9,
                  v9->Size + 1);
                v19 = 16 * v9->Size;
                v20 = (signed __int64)&v9->Data[-1];
                v15 = v19 + v20 == 0;
                v21 = (Scaleform::GFx::DisplayObjectBase **)(v19 + v20);
                *(_QWORD *)&rid[0].Id = v21;
                v57 = v21;
                if ( !v15 )
                {
                  ++v16->RefCount;
                  *v21 = v16;
                  v21[1] = (Scaleform::GFx::DisplayObjectBase *)v18;
                }
                v22 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v16);
                v23 = (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v10
                                                                                         - (v10 & 0xFFFFFFFFFFFFF000ui64)
                                                                                         - 56)
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                    + ((unsigned __int64)((unsigned __int128)((signed __int64)(v10 - (v10 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63);
                v24 = *(_QWORD *)((v10 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
                v25 = *(_QWORD *)(*(_QWORD *)(v24 + 8 * v23 + 40) + 144i64);
                if ( v25 )
                {
                  if ( v25 & 1 )
                    v26 = *(_QWORD *)((v25 & 0xFFFFFFFFFFFFFFFEui64) + 8);
                  else
                    v26 = (*(_QWORD *)(*(_QWORD *)(v24 + 8 * v23 + 40) + 152i64) != 0i64) + 1i64;
                }
                else
                {
                  v26 = 0i64;
                }
                Scaleform::Render::TreeContainer::Insert((Scaleform::Render::TreeContainer *)v10, v26, v22);
                if ( *(_QWORD *)(v14 + 64) )
                  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v16->vfptr[56].__vecDelDtor)(v16);
                v16->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v16->vfptr, v14);
                Scaleform::GFx::DisplayObjectBase::SetCxform(v16, (Scaleform::Render::Cxform *)(v14 + 32));
                v16->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v16->vfptr, *(_DWORD *)(v14 + 80));
              }
              else
              {
LABEL_106:
                rid[0] = *(Scaleform::GFx::ResourceId *)(v14 + 72);
                Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                  v68->pDispObj->pDefImpl.pObject,
                  &v65,
                  (Scaleform::GFx::ResourceId)rid);
                if ( v65.pCharDef )
                {
                  v27 = v68->pDispObj;
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
                    v9,
                    v9,
                    v9->Size + 1);
                  v31 = 16 * v9->Size;
                  v32 = (signed __int64)&v9->Data[-1];
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
                    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v30->vfptr);
                  v34 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v30);
                  v35 = (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v10
                                                                                           - (v10 & 0xFFFFFFFFFFFFF000ui64)
                                                                                           - 56)
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                      + ((unsigned __int64)((unsigned __int128)((signed __int64)(v10
                                                                               - (v10 & 0xFFFFFFFFFFFFF000ui64)
                                                                               - 56)
                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63);
                  v36 = *(_QWORD *)((v10 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
                  v37 = *(_QWORD *)(*(_QWORD *)(v36 + 8 * v35 + 40) + 144i64);
                  if ( v37 )
                  {
                    if ( v37 & 1 )
                      v38 = *(_QWORD *)((v37 & 0xFFFFFFFFFFFFFFFEui64) + 8);
                    else
                      v38 = (*(_QWORD *)(*(_QWORD *)(v36 + 8 * v35 + 40) + 152i64) != 0i64) + 1i64;
                  }
                  else
                  {
                    v38 = 0i64;
                  }
                  Scaleform::Render::TreeContainer::Insert((Scaleform::Render::TreeContainer *)v10, v38, v34);
                  if ( *(_QWORD *)(v14 + 64) )
                    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v30->vfptr[56].__vecDelDtor)(v30);
                  v30->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v30->vfptr, v14);
                  Scaleform::GFx::DisplayObjectBase::SetCxform(v30, (Scaleform::Render::Cxform *)(v14 + 32));
                  v30->vfptr[16].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v30->vfptr, *(_DWORD *)(v14 + 80));
                  v30->Flags &= 0xFFFEu;
                  for ( i = v30->pParentChar; i; i = i->pParentChar )
                  {
                    v40 = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(i, &v67);
                    if ( v40->x2 > v40->x1 && v40->y2 > v40->y1 )
                    {
                      v30->Flags |= 1u;
                      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v30->vfptr[20].__vecDelDtor)(v30);
                      break;
                    }
                  }
                  v41 = 0i64;
                  if ( SLOBYTE(v30->Flags) < 0 )
                    v41 = (Scaleform::GFx::InteractiveObject *)v30;
                  if ( v41 )
                  {
                    Scaleform::GFx::AS2::AvmButton::ConstructCharacter(
                      v68,
                      v41,
                      (Scaleform::GFx::ButtonRecord *)v14,
                      (__int64)v16);
                    Scaleform::GFx::InteractiveObject::AddToPlayList(v41);
                    if ( !((v41->Flags >> 21) & 1) || (v41->Flags >> 22) & 1 )
                      v42 = 0i64;
                    else
                      LOBYTE(v42) = 1;
                    v43 = (__int64)v41->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v41->vfptr, v42);
                    if ( v43 == -1 )
                    {
                      v41->Flags |= 0x400000u;
                    }
                    else if ( v43 == 1 )
                    {
                      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v41);
                    }
                    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v30->vfptr[73].__vecDelDtor)(v30);
                  }
                  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v30->vfptr);
                }
              }
              if ( v16 )
                Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v16->vfptr);
              v4 = (__int64)v52;
              v2 = v69;
              v8 = v71;
            }
LABEL_85:
            v13 = v53 + 96;
            v53 += 96i64;
            if ( !--v54 )
            {
              v3 = v55;
              break;
            }
          }
        }
      }
      if ( v8 != 3 && !*(_QWORD *)(v10 + 32) )
      {
        v44 = ((__int64 (__fastcall *)(Scaleform::GFx::Button *))v3->vfptr[69].__vecDelDtor)(v3);
        v45 = (Scaleform::Render::TreeContainer *)v44;
        v46 = (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v44
                                                                                 - (v44 & 0xFFFFFFFFFFFFF000ui64)
                                                                                 - 56)
                                                                * (signed __int128)5270498306774157605i64) >> 64) >> 4)
            + ((unsigned __int64)((unsigned __int128)((signed __int64)(v44 - (v44 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 63);
        v47 = *(_QWORD *)((v44 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
        v48 = *(_QWORD *)(*(_QWORD *)(v47 + 8 * v46 + 40) + 144i64);
        if ( v48 )
        {
          if ( v48 & 1 )
            v49 = *(_QWORD *)((v48 & 0xFFFFFFFFFFFFFFFEui64) + 8);
          else
            v49 = (*(_QWORD *)(*(_QWORD *)(v47 + 8 * v46 + 40) + 152i64) != 0i64) + 1i64;
        }
        else
        {
          v49 = 0i64;
        }
        Scaleform::Render::TreeContainer::Insert(v45, v49, (Scaleform::Render::TreeNode *)v10);
      }
      if ( v10 )
      {
        v15 = (*(_QWORD *)(v10 + 8))-- == 1i64;
        if ( v15 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)v10);
      }
      v5 = v70;
    }
    v71 = ++v8;
    v9 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)((char *)v9 + 32);
  }
  while ( (unsigned int)v8 < 4 );
  do
  {
    if ( v6 != v5 && v6 != 3 )
    {
      Scaleform::GFx::Button::UnloadCharactersForState(v3, v6);
      v5 = v70;
    }
    ++v6;
  }
  while ( (unsigned int)v6 < 4 );
}

// File Line: 540
// RVA: 0x6F6390
signed __int64 __fastcall Scaleform::GFx::AS2::AvmButton::GetStandardMemberBitMask(Scaleform::GFx::AS2::AvmButton *this)
{
  return 4026511311i64;
}

// File Line: 568
// RVA: 0x6F54F0
char __fastcall Scaleform::GFx::AS2::AvmButton::GetStandardMember(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::AS2::AvmCharacter::StandardMember member, Scaleform::GFx::AS2::Value *pval, bool opcodeFlag)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v5; // esi
  Scaleform::GFx::DisplayObjectBase **v6; // rbx
  bool v7; // bl
  Scaleform::Render::Rect<float> *v9; // rax
  Scaleform::GFx::AS2::Environment *v10; // rsi
  __int64 v11; // rcx
  Scaleform::GFx::AS2::RectangleObject *v12; // rax
  Scaleform::GFx::AS2::RectangleObject *v13; // rax
  Scaleform::GFx::AS2::RectangleObject *v14; // rbx
  unsigned int v15; // eax
  Scaleform::Render::Rect<float> result; // [rsp+40h] [rbp-38h]
  Scaleform::Render::Rect<double> r; // [rsp+50h] [rbp-28h]

  v4 = pval;
  v5 = member;
  v6 = (Scaleform::GFx::DisplayObjectBase **)this;
  if ( Scaleform::GFx::AS2::AvmCharacter::GetStandardMember(
         (Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr,
         member,
         pval,
         opcodeFlag) )
  {
    return 1;
  }
  if ( v5 != 37 )
  {
    if ( v5 == 71
      && *(_BYTE *)(*(_QWORD *)((*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObjectBase **))&(*v6)[2].RefCount)(v6)
                              + 232)
                  + 104i64) == 1 )
    {
      v7 = (LODWORD(v6[3][1].pRenNode.pObject) >> 11) & 1;
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 2;
      v4->V.BooleanValue = v7;
      return 1;
    }
    return 0;
  }
  if ( *(_BYTE *)((*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObjectBase **))&(*v6)[2].RefCount)(v6) + 240) >= 8u )
  {
    v9 = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(v6[3], &result);
    if ( v9->x2 <= v9->x1 || v9->y2 <= v9->y1 )
    {
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->T.Type = 0;
    }
    else
    {
      v10 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObjectBase **))&(*v6)[2].RefCount)(v6);
      Scaleform::GFx::DisplayObjectBase::GetScale9Grid(v6[3], &result);
      v12 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, signed __int64))v10->StringContext.pContext->pHeap->vfptr->Alloc)(
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
      Scaleform::GFx::AS2::Value::SetAsObject(v4, (Scaleform::GFx::AS2::Object *)&v14->vfptr);
      if ( v14 )
      {
        v15 = v14->RefCount;
        if ( v15 & 0x3FFFFFF )
        {
          v14->RefCount = v15 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v14->vfptr);
        }
      }
    }
    return 1;
  }
  return 0;
}

// File Line: 625
// RVA: 0x71B4E0
__int64 __fastcall Scaleform::GFx::AS2::AvmButton::SetStandardMember(Scaleform::GFx::AS2::AvmButton *this, Scaleform::GFx::AS2::AvmCharacter::StandardMember member, Scaleform::GFx::AS2::Value *origVal, bool opcodeFlag)
{
  bool v4; // r14
  __int64 v5; // rdi
  Scaleform::GFx::AS2::AvmButton *v6; // rbx
  __int64 v7; // rax
  Scaleform::GFx::AS2::Environment *v8; // rsi
  Scaleform::GFx::ASString *v9; // rax
  __int64 v10; // rsi
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::InteractiveObject *v13; // rdi
  Scaleform::GFx::AS2::Environment *v14; // rax
  Scaleform::GFx::AS2::Environment *v15; // rax
  Scaleform::GFx::AS2::Environment *v16; // rsi
  Scaleform::GFx::AS2::Object *v17; // rax
  Scaleform::GFx::AS2::RectangleObject *v18; // rdi
  float v19; // xmm1_4
  Scaleform::GFx::InteractiveObject *v20; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v21; // rax
  __int128 *v22; // rdx
  unsigned __int8 v23; // bl
  float v25; // [rsp+28h] [rbp-19h]
  float v26; // [rsp+2Ch] [rbp-15h]
  float v27; // [rsp+30h] [rbp-11h]
  float v28; // [rsp+34h] [rbp-Dh]
  __int128 v29; // [rsp+38h] [rbp-9h]
  Scaleform::GFx::AS2::Value v; // [rsp+48h] [rbp+7h]
  Scaleform::GFx::AS2::Value newVal; // [rsp+68h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+67h]

  v4 = opcodeFlag;
  v5 = (signed int)member;
  v6 = this;
  Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)((char *)&newVal + 24), origVal, (signed int)member);
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6);
  v8 = (Scaleform::GFx::AS2::Environment *)v7;
  if ( (signed int)v5 > 21
    && v7
    && Scaleform::GFx::AS2::AvmButton::GetButtonASObject(v6)
    && v6->ASButtonObj.pObject->pWatchpoints )
  {
    v.T.Type = 0;
    v9 = Scaleform::GFx::AS2::Environment::CreateConstString(
           v8,
           &result,
           Scaleform::GFx::AS2::AvmCharacter::MemberTable[v5].pName);
    v10 = (unsigned __int8)Scaleform::GFx::AS2::Object::InvokeWatchpoint(
                             (Scaleform::GFx::AS2::Object *)&v6->ASButtonObj.pObject->vfptr,
                             v8,
                             v9,
                             &newVal,
                             &v);
    v11 = result.pNode;
    v12 = result.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    if ( (_BYTE)v10 )
      Scaleform::GFx::AS2::Value::operator=(&newVal, &v, v5);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( Scaleform::GFx::AS2::AvmCharacter::SetStandardMember(
         (Scaleform::GFx::AS2::AvmCharacter *)&v6->vfptr,
         (Scaleform::GFx::AS2::AvmCharacter::StandardMember)v5,
         &newVal,
         v4) )
  {
    goto LABEL_25;
  }
  if ( (_DWORD)v5 == 37 )
  {
    if ( *(_BYTE *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6) + 240) >= 8u )
    {
      v15 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6);
      v16 = v15;
      v17 = Scaleform::GFx::AS2::Value::ToObject(&newVal, v15);
      v18 = (Scaleform::GFx::AS2::RectangleObject *)v17;
      if ( v17 && (*(unsigned int (**)(void))&v17->vfptr->gap8[8])() == 17 )
      {
        *(_OWORD *)&v.T.Type = 0ui64;
        *((_OWORD *)&v.NV + 1) = 0ui64;
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v18, v16, (Scaleform::Render::Rect<double> *)&v);
        v25 = (float)*(double *)&v.T.Type * 20.0;
        v26 = (float)v.NV.NumberValue * 20.0;
        v19 = *((double *)&v.NV + 2) - *(double *)&v.T.Type;
        v27 = (float)(v19 * 20.0) + v25;
        v28 = (float)((float)(*((double *)&v.NV + 3) - v.NV.NumberValue) * 20.0) + v26;
        v20 = v6->pDispObj;
        v21 = v20->vfptr;
        v22 = (__int128 *)&v25;
      }
      else
      {
        v20 = v6->pDispObj;
        v29 = 0i64;
        v21 = v20->vfptr;
        v22 = &v29;
      }
      v21[19].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v20->vfptr, (unsigned int)v22);
      goto LABEL_25;
    }
LABEL_23:
    v23 = 0;
    goto LABEL_26;
  }
  if ( (_DWORD)v5 != 71
    || *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6)
                            + 232)
                + 104i64) != 1 )
  {
    goto LABEL_23;
  }
  v13 = v6->pDispObj;
  v14 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmButton *))v6->vfptr[2].GetAbsolutePath)(v6);
  if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v14) )
    v13->Flags |= 0x800u;
  else
    v13->Flags &= 0xFFFFF7FF;
LABEL_25:
  v23 = 1;
LABEL_26:
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v23;
}

// File Line: 718
// RVA: 0x6C7D30
void __fastcall Scaleform::GFx::AS2::ButtonProto::ButtonProto(Scaleform::GFx::AS2::ButtonProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *prototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::ButtonProto *v5; // rsi
  Scaleform::GFx::AS2::Value val; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+78h] [rbp+10h]

  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    prototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::ButtonProto::`vftable';
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    GAS_ButtonFunctionTable,
    &flags);
  flags.Flags = 3;
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    (Scaleform::GFx::ASString *)&v4->pContext->pMovieRoot->pASMovieRoot.pObject[33].pMovieImpl,
    &val,
    &flags);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}

// File Line: 731
// RVA: 0x6E03A0
void __fastcall Scaleform::GFx::AS2::ButtonCtorFunction::CreateNewObject(Scaleform::GFx::AS2::ButtonCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::ButtonObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::ButtonObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::ButtonCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                              this,
                                              104i64);
  if ( v3 )
    Scaleform::GFx::AS2::ButtonObject::ButtonObject(v3, v2);
}

// File Line: 736
// RVA: 0x70CD90
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::ButtonCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  Scaleform::GFx::AS2::ButtonProto *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rbx
  Scaleform::GFx::AS2::Object *v13; // r14
  Scaleform::GFx::ASStringNode *v14; // rax
  Scaleform::GFx::AS2::LocalFrame *v15; // rdx
  unsigned int v16; // eax
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
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)_;
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
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::ButtonCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::ButtonCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v9 = (Scaleform::GFx::AS2::ButtonProto *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                             v5,
                                             168i64,
                                             0i64);
  v21 = (Scaleform::MemoryHeap *)v9;
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::ButtonProto::ButtonProto(v9, &psc, v10, v3);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v21 = (Scaleform::MemoryHeap *)v12;
  v22 = &objproto;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v12;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Button,
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
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[9].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v12 )
  {
    v16 = v12->RefCount;
    if ( v16 & 0x3FFFFFF )
    {
      v12->RefCount = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v12->vfptr);
    }
  }
  return v3;
}

