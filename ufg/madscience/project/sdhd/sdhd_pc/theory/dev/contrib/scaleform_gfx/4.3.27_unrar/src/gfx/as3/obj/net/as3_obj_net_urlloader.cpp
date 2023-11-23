// File Line: 40
// RVA: 0x1596AC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc5_Scaleform::GFx::AS3::Instances::fl_net::URLLoader_0_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_bool_long_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243F3F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc5<Scaleform::GFx::AS3::Instances::fl_net::URLLoader,0,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &,bool,long,bool>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *, Scaleform::GFx::AS3::Value *, Scaleform::GFx::ASString *, Scaleform::GFx::AS3::Value *, bool, int, bool))Scaleform::GFx::AS3::Instances::fl_net::URLLoader::addEventListener;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::URLLoader(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instance::Instance(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::`vftable;
  this->VMRef = t->pVM;
  this->pImpl.pObject = 0i64;
  this->pImpl.Owner = 1;
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_net::URLLoader::`vftable;
  *(_QWORD *)&this->bytesLoaded = 0i64;
  this->data.Flags = 0;
  this->data.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::DefaultValue<Scaleform::GFx::ASString const &>(
    &this->dataFormat,
    this->pTraits.pObject->pVM->StringManagerRef);
  Scaleform::GFx::ASString::operator=(&this->dataFormat, "text");
}

// File Line: 61
// RVA: 0x82B820
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::addEventListener(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::WeakProxy *type,
        Scaleform::GFx::AS3::Value *listener,
        bool useCapture,
        int priority,
        bool useWeakReference)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::addEventListener(
    this,
    result,
    type,
    listener,
    useCapture,
    priority,
    useWeakReference);
}

// File Line: 68
// RVA: 0x830D90
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::close(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method URLLoader::close() is not implemented\n");
}

// File Line: 75
// RVA: 0x852420
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::load(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *request)
{
  Scaleform::GFx::AS3::VMVtbl *vfptr; // rbp
  Scaleform::GFx::LoadQueueEntry::LoadMethod v6; // ebx
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *pData; // rdx
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
  Scaleform::GFx::ASString v20; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+68h] [rbp+20h] BYREF

  vfptr = this->pTraits.pObject->pVM[1].vfptr;
  v6 = LM_None;
  v7 = Scaleform::GFx::AS3::Instances::fl_net::URLRequest::methodGet(request, &resulta);
  Scaleform::GFx::ASString::ToUpper(v7, &v20);
  pNode = resulta.pNode;
  v18 = resulta.pNode->RefCount-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  pData = v20.pNode->pData;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = pData[v10++];
    if ( v11 != httpMethod[v10 - 1] )
      break;
    if ( v10 == 4 )
    {
      v6 = LM_Get;
      goto LABEL_21;
    }
  }
  v12 = 0i64;
  while ( 1 )
  {
    v13 = pData[v12++];
    if ( v13 != aPost_0[v12 - 1] )
      break;
    if ( v12 == 5 )
    {
      v6 = LM_Post;
      goto LABEL_21;
    }
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = pData[v14++];
    if ( v15 != aPut[v14 - 1] )
      break;
    if ( v14 == 4 )
    {
      v6 = LM_Put;
      goto LABEL_21;
    }
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = pData[v16++];
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
    v6 = LM_Delete;
LABEL_21:
  Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
    (Scaleform::GFx::AS3::MovieRoot *)vfptr,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)request,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this,
    v6);
  v19 = v20.pNode;
  v18 = v20.pNode->RefCount-- == 1;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
}

// File Line: 105
// RVA: 0x7999F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::AS3Constructor(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v6; // r9d
  Scaleform::GFx::AS3::VM *pVM; // rsi
  Scaleform::GFx::AS3::Value::V1U *v8; // rax
  char v9; // di
  Scaleform::GFx::AS3::Value::V1U v10; // rbx
  Scaleform::GFx::AS3::Value::V2U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rdx
  int v13; // esi
  const char *pData; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Value v20; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::GFx::AS3::Multiname v21; // [rsp+50h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value v22; // [rsp+80h] [rbp-19h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+A0h] [rbp+7h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+Fh] BYREF
  Scaleform::GFx::AS3::Value::V2U v25; // [rsp+B0h] [rbp+17h]
  __int64 v26; // [rsp+B8h] [rbp+1Fh]
  char v27; // [rsp+108h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString v28; // [rsp+118h] [rbp+7Fh] BYREF

  if ( argc )
  {
    v26 = -2i64;
    v6 = argv->Flags & 0x1F;
    if ( v6 )
    {
      if ( v6 - 12 > 3 && v6 != 10 || argv->value.VS._1.VStr )
      {
        pVM = this->pTraits.pObject->pVM;
        v22.Flags = 0;
        v22.Bonus.pWeakProxy = 0i64;
        v8 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
                                                  pVM->StringManagerRef,
                                                  &result,
                                                  "load");
        v9 = 10;
        v20.Flags = 10;
        v20.Bonus.pWeakProxy = 0i64;
        v10 = *v8;
        v20.value.VS._1 = v10;
        if ( v10.VStr == &v10.VStr->pManager->NullStringNode )
        {
          v10.VStr = 0i64;
          v20.value.VS._1.VStr = 0i64;
          v11.VObj = v25.VObj;
          v20.value.VS._2 = v25;
          v9 = 12;
          v20.Flags = 12;
        }
        else
        {
          ++v10.VStr->RefCount;
          v11.VObj = (Scaleform::GFx::AS3::Object *)v20.value.VS._2;
        }
        pObject = pVM->PublicNamespace.pObject;
        v21.Kind = MN_QName;
        v21.Obj.pObject = pObject;
        if ( pObject )
          pObject->RefCount = (pObject->RefCount + 1) & 0x8FBFFFFF;
        v21.Name.Flags = 0;
        v21.Name.Bonus.pWeakProxy = 0i64;
        v13 = v9 & 0x1F;
        if ( (unsigned int)(v13 - 12) <= 3
          && v10.VStr
          && (pData = v10.VStr[1].pData, *((_DWORD *)pData + 30) == 17)
          && (pData[112] & 0x20) == 0 )
        {
          Scaleform::GFx::AS3::Value::Assign(&v21.Name, (Scaleform::GFx::ASString *)&v10.VStr[1].16);
          Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v21.Obj,
            *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v10.VStr[1].RefCount);
          v21.Kind &= 0xFFFFFFF9;
        }
        else
        {
          _mm_prefetch((const char *)&v20, 2);
          *(_QWORD *)&v21.Name.Flags = *(_QWORD *)&v20.Flags;
          v21.Name.Bonus.pWeakProxy = 0i64;
          v21.Name.value.VS._1 = v10;
          v21.Name.value.VS._2 = v11;
          if ( (v9 & 0x1Fu) > 9 )
          {
            if ( v13 == 10 )
            {
              ++v10.VStr->RefCount;
            }
            else if ( (v9 & 0x1Fu) <= 0xF )
            {
              if ( v10.VStr )
                v10.VStr->Size = (v10.VStr->Size + 1) & 0x8FBFFFFF;
            }
            else if ( (v9 & 0x1Fu) <= 0x11 && v11.VObj )
            {
              v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
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
                pNode = v23.pNode;
                v17 = v23.pNode->RefCount-- == 1;
                if ( v17 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
              }
            }
            v18 = v28.pNode;
            v17 = v28.pNode->RefCount-- == 1;
            if ( v17 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v18);
          }
        }
        if ( (v9 & 0x1Fu) > 9 )
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v20);
        v19 = result.pNode;
        v17 = result.pNode->RefCount-- == 1;
        if ( v17 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v19);
        ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_net::URLLoader *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))this->vfptr[3].~RefCountBaseGC<328>)(
          this,
          &v27,
          &v21,
          &v22,
          argc,
          argv);
        Scaleform::GFx::AS3::Multiname::~Multiname(&v21);
        if ( (v22.Flags & 0x1F) > 9 )
        {
          if ( (v22.Flags & 0x200) != 0 )
          {
            v17 = v22.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v17 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&v22.Bonus, 0, 24);
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteProgressEvent(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        unsigned int bytesLoaded,
        unsigned int totalBytes)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rbp
  Scaleform::GFx::ASStringNode *vecDelDtor; // rbx
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::EventDispatcherImpl *pObject; // r10
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::ArrayLH<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener,2,Scaleform::ArrayDefaultPolicy> *,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // r11
  __int64 v10; // r9
  __int64 v11; // rdx
  __int64 *v12; // r8
  Scaleform::GFx::ASStringNode *v13; // rcx
  unsigned __int64 *v14; // rax
  char *v15; // rax
  Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent *v16; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::ProgressEvent> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString type; // [rsp+68h] [rbp+20h] BYREF

  v3 = totalBytes;
  v4 = bytesLoaded;
  vecDelDtor = (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM[1].vfptr[85].__vecDelDtor;
  type.pNode = vecDelDtor;
  ++vecDelDtor->RefCount;
  pObject = this->pImpl.pObject;
  if ( pObject )
  {
    pTable = pObject->Listeners.mHash.pTable;
    if ( pTable )
    {
      SizeMask = pTable->SizeMask;
      v10 = (unsigned int)SizeMask & vecDelDtor->HashFlags;
      v11 = v10;
      v12 = (__int64 *)(&pTable[v10 + 1].EntryCount + v10);
      if ( *v12 != -2 && ((unsigned int)SizeMask & *(_DWORD *)(v12[1] + 28)) == v10 )
      {
        while ( 1 )
        {
          v13 = (Scaleform::GFx::ASStringNode *)v12[1];
          if ( ((unsigned int)SizeMask & v13->HashFlags) == v10 && v13 == vecDelDtor )
            break;
          v11 = *v12;
          if ( *v12 == -1 )
            goto LABEL_19;
          v12 = (__int64 *)(&pTable[v11 + 1].EntryCount + v11);
        }
        if ( v11 >= 0 )
        {
          v14 = &pTable[1].SizeMask + 3 * v11;
          if ( v14 )
          {
            v15 = (char *)(v14 + 1);
            if ( v15 )
            {
              if ( *(_QWORD *)v15 )
              {
                if ( *(_QWORD *)(*(_QWORD *)v15 + 8i64) )
                {
                  this->bytesLoaded = v4;
                  this->bytesTotal = v3;
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateProgressEventObject(
                    this,
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
                    &type);
                  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
                    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
                  result.pObject->BytesLoaded = v4;
                  result.pObject->BytesTotal = v3;
                  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(
                    this,
                    result.pObject,
                    0);
                  v16 = result.pObject;
                  if ( result.pObject )
                  {
                    if ( ((__int64)result.pObject & 1) != 0 )
                    {
                      --result.pObject;
                    }
                    else
                    {
                      RefCount = result.pObject->RefCount;
                      if ( (RefCount & 0x3FFFFF) != 0 )
                      {
                        result.pObject->RefCount = RefCount - 1;
                        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v16);
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
  if ( vecDelDtor->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(vecDelDtor);
}

// File Line: 173
// RVA: 0x7CE810
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::ExecuteErrorEvent(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const char *errorStr)
{
  Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::IOErrorEvent> result; // [rsp+50h] [rbp+18h] BYREF

  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateIOErrorEventObject(
    this,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&result,
    errorStr);
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&result.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)this);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DispatchSingleEvent(this, result.pObject, 0);
  pObject = result.pObject;
  if ( result.pObject )
  {
    if ( ((__int64)result.pObject & 1) != 0 )
    {
      --result.pObject;
    }
    else
    {
      RefCount = result.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        result.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
}

// File Line: 180
// RVA: 0x820170
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetVariablesDataString(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const char *pdata)
{
  Scaleform::GFx::AS3::ASVM *pVM; // rbx
  Scaleform::GFx::AS3::Class *Class; // rax
  Scaleform::GFx::AS3::Class *v6; // rdi
  bool v7; // al
  Scaleform::GFx::AS3::Object *pObject; // rbx
  unsigned int RefCount; // eax
  bool v10; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int v12; // eax
  Scaleform::StringDataPtr gname; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value argv; // [rsp+48h] [rbp-28h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> pobj; // [rsp+A0h] [rbp+30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+40h] BYREF
  Scaleform::GFx::AS3::Class *v17; // [rsp+B8h] [rbp+48h]

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  gname.pStr = "flash.net.URLVariables";
  gname.Size = 22i64;
  Class = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, pVM->CurrentDomain.pObject);
  v6 = Class;
  v17 = Class;
  if ( Class )
    Class->RefCount = (Class->RefCount + 1) & 0x8FBFFFFF;
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &result,
    pdata);
  argv.Flags = 10;
  argv.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&argv.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    argv.value.VS._1.VStr = 0i64;
    argv.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)gname.Size;
    argv.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  pobj.pObject = 0i64;
  v7 = Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, &pobj, v6, 1u, &argv);
  pObject = pobj.pObject;
  if ( v7 )
    Scaleform::GFx::AS3::Value::Assign(&this->data, pobj.pObject);
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      pobj.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
    }
    else
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  if ( (argv.Flags & 0x1F) > 9 )
  {
    if ( (argv.Flags & 0x200) != 0 )
    {
      v10 = argv.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&argv.Bonus, 0, 24);
      argv.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&argv);
    }
  }
  pNode = result.pNode;
  v10 = result.pNode->RefCount-- == 1;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v6 )
  {
    if ( ((unsigned __int8)v6 & 1) != 0 )
    {
      v17 = (Scaleform::GFx::AS3::Class *)((char *)v6 - 1);
    }
    else
    {
      v12 = v6->RefCount;
      if ( (v12 & 0x3FFFFF) != 0 )
      {
        v6->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v6);
      }
    }
  }
}

// File Line: 201
// RVA: 0x81ED40
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetTextString(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        const char *pdata)
{
  unsigned int Flags; // ebx
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    this->pTraits.pObject->pVM->StringManagerRef,
    &result,
    pdata);
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  *(Scaleform::GFx::ASString *)&other.value.VNumber = (Scaleform::GFx::ASString)result.pNode;
  if ( result.pNode == &result.pNode->pManager->NullStringNode )
  {
    other.value.VS._1.VStr = 0i64;
    other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)other.Bonus.pWeakProxy;
    other.Flags = 12;
  }
  else
  {
    ++result.pNode->RefCount;
  }
  Scaleform::GFx::AS3::Value::Assign(&this->data, &other);
  Flags = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v4 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v4 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&other.Bonus, 0, 24);
      other.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  pNode = result.pNode;
  v4 = result.pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 207
// RVA: 0x818380
void __fastcall Scaleform::GFx::AS3::Instances::fl_net::URLLoader::SetBinaryData(
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *this,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *binaryData)
{
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_utils::ByteArray> result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *v7; // [rsp+48h] [rbp+10h]

  Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray::MakeInstance(
    &result,
    (Scaleform::GFx::AS3::InstanceTraits::fl_utils::ByteArray *)this->pTraits.pObject->pVM->TraitsByteArray.pObject->ITraits.pObject);
  pV = result.pV;
  v7 = result.pV;
  Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Set(result.pV, binaryData->Data.Data, binaryData->Data.Size);
  Scaleform::GFx::AS3::Value::Assign(&this->data, pV);
  if ( pV )
  {
    if ( ((unsigned __int8)pV & 1) != 0 )
    {
      v7 = (Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *)((char *)pV - 1);
    }
    else
    {
      RefCount = pV->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        pV->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pV);
      }
    }
  }
}

// File Line: 254
// RVA: 0x800360
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLLoader> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_net::URLLoader> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 276
// RVA: 0x72C1C0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_net::URLLoader::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_net::URLLoaderCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_net::URLLoader::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_net::URLLoaderCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_net::URLLoader::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    result->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

