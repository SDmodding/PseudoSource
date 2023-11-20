// File Line: 40
// RVA: 0x1596AC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_net::URLLoader_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_bool_long_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F3F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Method = Scaleform::GFx::AS3::Instances::fl_net::URLLoader::addEventListener;
  return result;
}

// File Line: 41
// RVA: 0x158E2D0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_net::URLLoader_1_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F400 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,1,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Instances::fl_net::URLLoader::close;
  return result;
}

// File Line: 42
// RVA: 0x1593B20
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_net::URLLoader_2_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_net::URLRequest_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F410 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_net::URLRequest *>::Method = Scaleform::GFx::AS3::Instances::fl_net::URLLoader::load;
  return result;
}

// File Line: 54
// RVA: 0x7838D0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::URLLoader(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::InstanceTraits::Traits *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v3; // rdi

  v2 = t;
  v3 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable';
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable';
  v3->VMRef = v2->pVM;
  v3->pImpl.pObject = 0i64;
  v3->pImpl.Owner = 1;
  v3->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::URLLoader::`vftable';
  *(_QWORD *)&v3->bytesLoaded = 0i64;
  v3->data.Flags = 0;
  v3->data.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &v3->dataFormat,
    v3->pTraits.pObject->pVM->StringManagerRef);
  Scaleform::GFx::ASString::operator=(&v3->dataFormat, "text");
}

// File Line: 61
// RVA: 0x82B820
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::addEventListener(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *type, Scaleform::GFx::AS3::Value *listener, bool useCapture, int priority, bool useWeakReference)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this->vfptr,
    result,
    type,
    listener,
    useCapture,
    priority,
    useWeakReference);
}

// File Line: 68
// RVA: 0x830D90
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::close(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method URLLoader::close() is not implemented\n");
}

// File Line: 75
// RVA: 0x852420
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::load(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLRequest *v3; // rdi
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v4; // rsi
  Scaleform::GFx::AS3::VMVtbl *v5; // rbp
  Scaleform::GFx::LoadQueueEntry::LoadMethod v6; // ebx
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  const char *v9; // rdx
  __int64 v10; // rcx
  char v11; // al
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rax
  char v17; // r8
  bool v18; // zf
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString v20; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString resulta; // [rsp+68h] [rbp+20h]

  v3 = request;
  v4 = this;
  v5 = this->pTraits.pObject->pVM[1].vfptr;
  v6 = 0;
  v7 = Scaleform::GFx::AS3::Instances::fl_net::URLRequest::methodGet(request, &resulta);
  Scaleform::GFx::ASString::ToUpper(v7, &v20);
  v8 = resulta.pNode;
  v18 = resulta.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  v9 = v20.pNode->pData;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = v9[v10++];
    if ( v11 != httpMethod[v10 - 1] )
      break;
    if ( v10 == 4 )
    {
      v6 = 1;
      goto LABEL_21;
    }
  }
  v12 = 0i64;
  while ( 1 )
  {
    v13 = v9[v12++];
    if ( v13 != aPost_0[v12 - 1] )
      break;
    if ( v12 == 5 )
    {
      v6 = 2;
      goto LABEL_21;
    }
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = v9[v14++];
    if ( v15 != aPut[v14 - 1] )
      break;
    if ( v14 == 4 )
    {
      v6 = 3;
      goto LABEL_21;
    }
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = v9[v16++];
    v18 = v17 == aDelete_0[v16 - 1];
    if ( v17 != aDelete_0[v16 - 1] )
      break;
    if ( v16 == 7 )
    {
      v18 = v17 == aDelete_0[6];
      break;
    }
  }
  if ( v18 )
    v6 = 4;
LABEL_21:
  Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry((Scaleform::GFx::AS3::MovieRoot *)v5, v3, v4, v6);
  v19 = v20.pNode;
  v18 = v20.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 105
// RVA: 0x7999F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // r14
  unsigned int v4; // er15
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v5; // r12
  unsigned int v6; // er9
  Scaleform::GFx::AS3::VM *v7; // rsi
  long double *v8; // rax
  unsigned int v9; // edi
  long double v10; // rbx
  Scaleform::GFx::AS3::Value::V2U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rdx
  int v13; // esi
  __int64 v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Value v20; // [rsp+30h] [rbp-69h]
  Scaleform::GFx::AS3::Multiname v21; // [rsp+50h] [rbp-49h]
  Scaleform::GFx::AS3::Value v22; // [rsp+80h] [rbp-19h]
  Scaleform::GFx::ASString v23; // [rsp+A0h] [rbp+7h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+Fh]
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+B0h] [rbp+17h]
  __int64 v26; // [rsp+B8h] [rbp+1Fh]
  char v27; // [rsp+108h] [rbp+6Fh]
  Scaleform::GFx::ASString v28; // [rsp+118h] [rbp+7Fh]

  if ( argc >= 1 )
  {
    v26 = -2i64;
    v3 = argv;
    v4 = argc;
    v5 = this;
    v6 = argv->Flags & 0x1F;
    if ( v6 )
    {
      if ( v6 - 12 > 3 && v6 != 10 || *(_QWORD *)&argv->value.VNumber )
      {
        v7 = this->pTraits.pObject->pVM;
        v22.Flags = 0;
        v22.Bonus.pWeakProxy = 0i64;
        v8 = (long double *)Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                              (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v7->StringManagerRef->Builtins,
                              &result,
                              "load");
        v9 = 10;
        v20.Flags = 10;
        v20.Bonus.pWeakProxy = 0i64;
        v10 = *v8;
        v20.value.VNumber = v10;
        if ( *(_QWORD *)&v10 == *(_QWORD *)(*(_QWORD *)&v10 + 8i64) + 104i64 )
        {
          v10 = 0.0;
          v20.value.VNumber = 0.0;
          v11.VObj = v25.VObj;
          v20.value.VS._2 = v25;
          v9 = 12;
          v20.Flags = 12;
        }
        else
        {
          ++*(_DWORD *)(*(_QWORD *)&v10 + 24i64);
          v11.VObj = (Scaleform::GFx::AS3::Object *)v20.value.VS._2;
        }
        v12 = (Scaleform::GFx::AS3::GASRefCountBase *)&v7->PublicNamespace.pObject->vfptr;
        v21.Kind = 0;
        v21.Obj.pObject = v12;
        if ( v12 )
          v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
        v21.Name.Flags = 0;
        v21.Name.Bonus.pWeakProxy = 0i64;
        v13 = v9 & 0x1F;
        if ( (unsigned int)(v13 - 12) <= 3
          && v10 != 0.0
          && (v14 = *(_QWORD *)(*(_QWORD *)&v10 + 40i64), *(_DWORD *)(v14 + 120) == 17)
          && ~(*(_BYTE *)(v14 + 112) >> 5) & 1 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v21.Name, (Scaleform::GFx::ASString *)(*(_QWORD *)&v10 + 56i64));
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v21.Obj,
            *(Scaleform::GFx::AS3::Instances::fl::XMLList **)(*(_QWORD *)&v10 + 64i64));
          v21.Kind &= 0xFFFFFFF9;
        }
        else
        {
          __asm { prefetcht1 byte ptr [rbp+57h+var_C0.Flags]; Prefetch to all cache levels }
          *(_QWORD *)&v21.Name.Flags = *(_QWORD *)&v20.Flags;
          v21.Name.Bonus.pWeakProxy = 0i64;
          v21.Name.value.VNumber = v10;
          v21.Name.value.VS._2 = v11;
          if ( v13 > 9 )
          {
            if ( (v9 >> 9) & 1 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] + 1;
            }
            else if ( v13 == 10 )
            {
              ++*(_DWORD *)(*(_QWORD *)&v10 + 24i64);
            }
            else if ( v13 > 10 )
            {
              if ( v13 <= 15 )
              {
                if ( v10 != 0.0 )
                  *(_DWORD *)(*(_QWORD *)&v10 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v10 + 32i64) + 1) & 0x8FBFFFFF;
              }
              else if ( v13 <= 17 && v11.VObj )
              {
                v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
              }
            }
          }
          if ( (v21.Name.Flags & 0x1F) == 10 )
          {
            Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v21.Name, &v28);
            if ( v28.pNode->Size )
            {
              if ( *v28.pNode->pData == 64 )
              {
                v21.Kind |= 8u;
                v15 = Scaleform::GFx::ASString::Substring(&v28, &v23, 1, v28.pNode->Size);
                Scaleform::GFx::AS3::Value::Assign(&v21.Name, v15);
                v16 = v23.pNode;
                v17 = v23.pNode->RefCount == 1;
                --v16->RefCount;
                if ( v17 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v16);
              }
            }
            v18 = v28.pNode;
            v17 = v28.pNode->RefCount == 1;
            --v18->RefCount;
            if ( v17 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v18);
          }
        }
        if ( v13 > 9 )
        {
          if ( (v9 >> 9) & 1 )
          {
            LODWORD(MEMORY[0]) = MEMORY[0] - 1;
            if ( !(_DWORD)MEMORY[0] )
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
            v20.Bonus.pWeakProxy = 0i64;
            v20.value = 0ui64;
            v20.Flags = v9 & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
          }
        }
        v19 = result.pNode;
        v17 = result.pNode->RefCount == 1;
        --v19->RefCount;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))v5->vfptr[3].~RefCountBaseGC<328>)(
          v5,
          &v27,
          &v21,
          &v22,
          v4,
          v3);
        Scaleform::GFx::AS3::Multiname::~Multiname(&v21);
        if ( (v22.Flags & 0x1F) > 9 )
        {
          if ( (v22.Flags >> 9) & 1 )
          {
            v17 = v22.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v17 )
              ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            v22.Bonus.pWeakProxy = 0i64;
            v22.value = 0ui64;
            v22.Flags &= 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v22);
          }
        }
      }
    }
  }
}

// File Line: 133
// RVA: 0x7D03C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, unsigned int bytesLoaded, unsigned int totalBytes)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rbp
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *v7; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *v8; // r10
  unsigned __int64 v9; // r11
  __int64 v10; // r9
  signed __int64 v11; // rdx
  unsigned __int64 *v12; // r8
  Scaleform::GFx::ASStringNode *v13; // rcx
  signed __int64 v14; // rax
  signed __int64 v15; // rax
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *v16; // rcx
  unsigned int v17; // eax
  bool v18; // zf
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString type; // [rsp+68h] [rbp+20h]

  v3 = totalBytes;
  v4 = bytesLoaded;
  v5 = this;
  v6 = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].vfptr[85].__vecDelDtor;
  type.pNode = v6;
  ++v6->RefCount;
  v7 = this->pImpl.pObject;
  if ( v7 )
  {
    v8 = v7->Listeners.mHash.pTable;
    if ( v8 )
    {
      v9 = v8->SizeMask;
      v10 = (unsigned int)v9 & v6->HashFlags;
      v11 = v10;
      v12 = &v8->EntryCount + v10 + 2 * (v10 + 1);
      if ( *v12 != -2i64 && ((unsigned int)v9 & *(_DWORD *)(v12[1] + 28)) == v10 )
      {
        while ( 1 )
        {
          v13 = (Scaleform::GFx::ASStringNode *)v12[1];
          if ( ((unsigned int)v9 & v13->HashFlags) == v10 && v13 == v6 )
            break;
          v11 = *v12;
          if ( *v12 == -1i64 )
            goto LABEL_19;
          v12 = &v8->EntryCount + v11 + 2 * (v11 + 1);
        }
        if ( v11 >= 0 )
        {
          v14 = (signed __int64)v8 + 24 * (v11 + 1);
          if ( v14 )
          {
            v15 = v14 + 8;
            if ( v15 )
            {
              if ( *(_QWORD *)v15 )
              {
                if ( *(_QWORD *)(*(_QWORD *)v15 + 8i64) )
                {
                  v5->bytesLoaded = v4;
                  v5->bytesTotal = v3;
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(
                    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v5->vfptr,
                    &result,
                    &type);
                  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v5);
                  result.pObject->BytesLoaded = v4;
                  result.pObject->BytesTotal = v3;
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v5->vfptr,
                    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&result.pObject->vfptr,
                    0);
                  v16 = result.pObject;
                  if ( result.pObject )
                  {
                    if ( (_QWORD)result.pObject & 1 )
                    {
                      --result.pObject;
                    }
                    else
                    {
                      v17 = result.pObject->RefCount;
                      if ( v17 & 0x3FFFFF )
                      {
                        result.pObject->RefCount = v17 - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_19:
  v18 = v6->RefCount-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
}

// File Line: 173
// RVA: 0x7CE810
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteErrorEvent(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, const char *errorStr)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v2; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> result; // [rsp+50h] [rbp+18h]

  v2 = this;
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&this->vfptr,
    &result,
    errorStr);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v2);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v2->vfptr,
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&result.pObject->vfptr,
    0);
  v3 = result.pObject;
  if ( result.pObject )
  {
    if ( (_QWORD)result.pObject & 1 )
    {
      --result.pObject;
    }
    else
    {
      v4 = result.pObject->RefCount;
      if ( v4 & 0x3FFFFF )
      {
        result.pObject->RefCount = v4 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v3->vfptr);
      }
    }
  }
}

// File Line: 180
// RVA: 0x820170
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, const char *pdata)
{
  const char *v2; // r14
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v3; // rsi
  Scaleform::GFx::AS3::ASVM *v4; // rbx
  Scaleform::GFx::AS3::Class *v5; // rax
  Scaleform::GFx::AS3::Class *v6; // rdi
  bool v7; // al
  Scaleform::GFx::AS3::Object *v8; // rbx
  unsigned int v9; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  unsigned int v12; // eax
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-38h]
  Scaleform::GFx::AS3::Value argv; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+A0h] [rbp+30h]
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+40h]
  Scaleform::GFx::AS3::Class *v17; // [rsp+B8h] [rbp+48h]

  v2 = pdata;
  v3 = this;
  v4 = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  gname.pStr = "flash.net.URLVariables";
  gname.Size = 22i64;
  v5 = Scaleform::GFx::AS3::VM::GetClass((Scaleform::GFx::AS3::VM *)&v4->vfptr, &gname, v4->CurrentDomain.pObject);
  v6 = v5;
  v17 = v5;
  if ( v5 )
    v5->RefCount = (v5->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v3->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &result,
    v2);
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = result;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    argv.value.VNumber = 0.0;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)gname.Size;
    argv.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  pobj.pObject = 0i64;
  v7 = Scaleform::GFx::AS3::ASVM::_constructInstance(v4, &pobj, (Scaleform::GFx::AS3::Object *)&v6->vfptr, 1u, &argv);
  v8 = pobj.pObject;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Assign(&v3->data, pobj.pObject);
  if ( v8 )
  {
    if ( (unsigned __int8)v8 & 1 )
    {
      pobj.pObject = (Scaleform::GFx::AS3::Object *)((char *)v8 - 1);
    }
    else
    {
      v9 = v8->RefCount;
      if ( v9 & 0x3FFFFF )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v8->vfptr);
      }
    }
  }
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags >> 9) & 1 )
    {
      v10 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      argv.Bonus.pWeakProxy = 0i64;
      argv.value = 0ui64;
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  v11 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( v6 )
  {
    if ( (unsigned __int8)v6 & 1 )
    {
      v17 = (Scaleform::GFx::AS3::Class *)((char *)v6 - 1);
    }
    else
    {
      v12 = v6->RefCount;
      if ( v12 & 0x3FFFFF )
      {
        v6->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v6->vfptr);
      }
    }
  }
}

// File Line: 201
// RVA: 0x81ED40
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, const char *pdata)
{
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v2; // rbx
  unsigned int v3; // ebx
  bool v4; // zf
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v2 = this;
  Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
    &result,
    pdata);
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&other.value.VNumber = result;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    other.value.VNumber = 0.0;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)other.Bonus.pWeakProxy;
    other.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  Scaleform::GFx::AS3::Value::Assign(&v2->data, &other);
  v3 = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v4 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags = v3 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  v5 = result.pNode;
  v4 = result.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}

// File Line: 207
// RVA: 0x818380
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *binaryData)
{
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_net::URLLoader *v3; // rsi
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v4; // rbx
  unsigned int v5; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> result; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v7; // [rsp+48h] [rbp+10h]

  v2 = binaryData;
  v3 = this;
  Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *)this->pTraits.pObject->pVM->TraitsByteArray.pObject->ITraits.pObject);
  v4 = result.pV;
  v7 = result.pV;
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Set(result.pV, v2->Data.Data, v2->Data.Size);
  Scaleform::GFx::AS3::Value::Assign(&v3->data, (Scaleform::GFx::AS3::Object *)&v4->vfptr);
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
    {
      v7 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)((char *)v4 - 1);
    }
    else
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}

// File Line: 254
// RVA: 0x800360
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLLoader> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 276
// RVA: 0x72C1C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_net::URLLoader::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_net::URLLoaderCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_net::URLLoader::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_net::URLLoaderCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable';
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader::`vftable';
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

