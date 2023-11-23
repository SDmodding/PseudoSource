// File Line: 59
// RVA: 0x783E10
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::UserDefinedFunction(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        Scaleform::GFx::AS3::InstanceTraits::Traits *t,
        Scaleform::GFx::Resource *pcontext,
        void *puserData)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx

  Scaleform::GFx::AS3::Instances::FunctionBase::FunctionBase(this, t);
  this->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::UserDefinedFunction::`vftable;
  this->pContext.pObject = 0i64;
  if ( pcontext )
    Scaleform::Render::RenderBuffer::AddRef(pcontext);
  pObject = (Scaleform::Render::RenderBuffer *)this->pContext.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pContext.pObject = (Scaleform::GFx::FunctionHandler *)pcontext;
  this->pUserData = puserData;
}

// File Line: 68
// RVA: 0x7D0EF0
// attributes: thunk
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::ExecuteUnsafe(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc)
{
  Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(this, _this, result, argc);
}

// File Line: 72
// RVA: 0x7CA930
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::Execute(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv,
        bool discard_result)
{
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::VM *pVM; // rcx
  bool v9; // zf
  Scaleform::GFx::AS3::Value *pCurrent; // rax
  Scaleform::GFx::AS3::Value::V1U v11; // r8
  Scaleform::GFx::AS3::Value::V2U v12; // r9
  Scaleform::GFx::AS3::Value v13; // [rsp+48h] [rbp-30h] BYREF

  v13.Flags = 0;
  v13.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(this, _this, &v13, argc, argv);
  pWeakProxy = v13.Bonus.pWeakProxy;
  Flags = v13.Flags;
  if ( !discard_result )
  {
    pVM = this->pTraits.pObject->pVM;
    v9 = pVM->OpStack.pCurrent++ == (Scaleform::GFx::AS3::Value *)-32i64;
    pCurrent = pVM->OpStack.pCurrent;
    if ( !v9 )
    {
      pCurrent->Flags = Flags;
      pCurrent->Bonus.pWeakProxy = pWeakProxy;
      v11 = v13.value.VS._1;
      pCurrent->value.VS._1.VStr = v13.value.VS._1.VStr;
      v12.VObj = (Scaleform::GFx::AS3::Object *)v13.value.VS._2;
      pCurrent->value.VS._2.VObj = v13.value.VS._2.VObj;
      if ( (Flags & 0x1F) > 9 )
      {
        if ( (Flags & 0x200) != 0 )
        {
          ++pWeakProxy->RefCount;
        }
        else if ( (Flags & 0x1F) == 10 )
        {
          ++v11.VStr->RefCount;
        }
        else if ( (Flags & 0x1F) > 0xA )
        {
          if ( (Flags & 0x1F) <= 0xF )
          {
            if ( v11.VStr )
              v11.VStr->Size = (v11.VStr->Size + 1) & 0x8FBFFFFF;
          }
          else if ( (Flags & 0x1F) <= 0x11 && v12.VObj )
          {
            v12.VObj->RefCount = (v12.VObj->RefCount + 1) & 0x8FBFFFFF;
          }
        }
      }
    }
  }
  if ( (Flags & 0x1F) > 9 )
  {
    if ( (Flags & 0x200) != 0 )
    {
      v9 = pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v13.Bonus, 0, 24);
      v13.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v13);
    }
  }
}

// File Line: 79
// RVA: 0x7EBD00
__int64 __fastcall Scaleform::GFx::AS3::UserDefinedFunction::GetMaxParamNum(
        Scaleform::GFx::AS3::UserDefinedFunction *this)
{
  return 4095i64;
}

// File Line: 88
// RVA: 0x7CEE20
void __fastcall Scaleform::GFx::AS3::UserDefinedFunction::ExecuteImpl(
        Scaleform::GFx::AS3::UserDefinedFunction *this,
        Scaleform::GFx::AS3::Value *_this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc)
{
  __int64 v4; // r14
  Scaleform::GFx::AS3::VM *pVM; // r13
  Scaleform::GFx::AS3::MovieRoot *vfptr; // rsi
  Scaleform::GFx::Value *v9; // rdx
  Scaleform::GFx::AS3::Value *v10; // rbx
  __int64 v11; // rdi
  Scaleform::GFx::Value *v12; // rdx
  unsigned __int64 Size; // rdi
  Scaleform::GFx::Value *Data; // rdx
  Scaleform::GFx::Value *v15; // rbx
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-B8h] BYREF
  Scaleform::GFx::Value pdestVal; // [rsp+38h] [rbp-A0h] BYREF
  Scaleform::GFx::Value gfxVal; // [rsp+68h] [rbp-70h] BYREF
  __int64 v19; // [rsp+98h] [rbp-40h]
  __int64 v20[4]; // [rsp+A8h] [rbp-30h] BYREF
  Scaleform::GFx::Value *v21; // [rsp+C8h] [rbp-10h]
  int v22; // [rsp+D0h] [rbp-8h]
  void *pUserData; // [rsp+D8h] [rbp+0h]
  __int64 v24; // [rsp+E0h] [rbp+8h]
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *p_pheapAddr; // [rsp+118h] [rbp+40h]
  Scaleform::GFx::AS3::Value *retaddr; // [rsp+138h] [rbp+60h]

  v24 = -2i64;
  v4 = argc;
  p_pheapAddr = &pheapAddr;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  pdestVal.pObjectInterface = 0i64;
  pdestVal.Type = VT_Undefined;
  gfxVal.mValue.pString = 0i64;
  LODWORD(gfxVal.DataAux) = 0;
  pVM = this->pTraits.pObject->pVM;
  vfptr = (Scaleform::GFx::AS3::MovieRoot *)pVM[1].vfptr;
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(vfptr, _this, &pdestVal);
  Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  v9 = &pheapAddr.Data[pheapAddr.Size - 1];
  p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)v9;
  gfxVal.pNext = v9;
  if ( v9 )
  {
    v9->pObjectInterface = 0i64;
    v9->Type = pdestVal.Type;
    v9->mValue.pString = pdestVal.mValue.pString;
    v9->DataAux = pdestVal.DataAux;
    if ( (pdestVal.Type & 0x40) != 0 )
    {
      v9->pObjectInterface = pdestVal.pObjectInterface;
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))pdestVal.pObjectInterface->vfptr->gap8)(
        pdestVal.pObjectInterface,
        v9,
        v9->mValue);
    }
  }
  if ( (_DWORD)v4 )
  {
    v10 = retaddr;
    v11 = v4;
    do
    {
      gfxVal.pObjectInterface = 0i64;
      pdestVal.mValue.IValue = 0;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(vfptr, v10, &gfxVal);
      Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v12 = &pheapAddr.Data[pheapAddr.Size - 1];
      p_pheapAddr = (Scaleform::ArrayDataBase<Scaleform::GFx::Value,Scaleform::AllocatorGH_CPP<Scaleform::GFx::Value,2>,Scaleform::ArrayDefaultPolicy> *)v12;
      gfxVal.pNext = v12;
      if ( v12 )
      {
        v12->pObjectInterface = 0i64;
        v12->Type = pdestVal.mValue.IValue;
        v12->mValue.pString = (const char *)pdestVal.DataAux;
        v12->DataAux = (unsigned __int64)gfxVal.pPrev;
        if ( (pdestVal.mValue.BValue & 0x40) != 0 )
        {
          v12->pObjectInterface = gfxVal.pObjectInterface;
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))gfxVal.pObjectInterface->vfptr->gap8)(
            gfxVal.pObjectInterface,
            v12,
            v12->mValue);
        }
      }
      if ( (pdestVal.mValue.BValue & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, unsigned __int64))&gfxVal.pObjectInterface->vfptr->gap8[8])(
          gfxVal.pObjectInterface,
          &gfxVal,
          pdestVal.DataAux);
        gfxVal.pObjectInterface = 0i64;
      }
      pdestVal.mValue.IValue = 0;
      ++v10;
      --v11;
    }
    while ( v11 );
  }
  v20[1] = (__int64)pVM[1].vfptr[2].__vecDelDtor;
  v20[0] = (__int64)&gfxVal.pObjectInterface;
  v20[2] = (__int64)&pdestVal;
  if ( (_DWORD)v4 )
    v21 = pheapAddr.Data + 1;
  else
    v21 = 0i64;
  v20[3] = (__int64)pheapAddr.Data;
  v22 = LODWORD(pheapAddr.Size) - 1;
  pUserData = this->pUserData;
  this->pContext.pObject->vfptr[1].__vecDelDtor(this->pContext.pObject, (unsigned int)v20);
  if ( (gfxVal.DataAux & 0x8F) != 0 )
    Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(vfptr, (Scaleform::GFx::Value *)&gfxVal.pObjectInterface, result);
  if ( (gfxVal.DataAux & 0x40) != 0 )
  {
    (*((void (__fastcall **)(Scaleform::GFx::Value::ValueUnion, Scaleform::GFx::Value::ObjectInterface **, __int64))*gfxVal.mValue.pStringManaged
     + 2))(
      gfxVal.mValue,
      &gfxVal.pObjectInterface,
      v19);
    gfxVal.mValue.pString = 0i64;
  }
  LODWORD(gfxVal.DataAux) = 0;
  if ( (pdestVal.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
      pdestVal.pObjectInterface,
      &pdestVal,
      pdestVal.mValue);
    pdestVal.pObjectInterface = 0i64;
  }
  pdestVal.Type = VT_Undefined;
  p_pheapAddr = &pheapAddr;
  Size = pheapAddr.Size;
  Data = pheapAddr.Data;
  v15 = &pheapAddr.Data[pheapAddr.Size - 1];
  if ( pheapAddr.Size )
  {
    do
    {
      if ( (v15->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v15->pObjectInterface->vfptr->gap8[8])(
          v15->pObjectInterface,
          v15,
          v15->mValue);
        v15->pObjectInterface = 0i64;
      }
      v15->Type = VT_Undefined;
      --v15;
      --Size;
    }
    while ( Size );
    Data = pheapAddr.Data;
  }
  if ( Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 221
// RVA: 0x7E5C70
Scaleform::AmpStats *__fastcall Scaleform::GFx::AS2ValueObjectInterface::GetAdvanceStats(
        Scaleform::GFx::AS2ValueObjectInterface *this)
{
  return this->pMovieRoot->pASMovieRoot.pObject->pMovieImpl->AdvanceStats.pObject;
}

// File Line: 226
// RVA: 0x802A40
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::ObjectAddRef(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        unsigned __int64 pobj)
{
  __int32 v5; // eax

  v5 = val->Type & 0x8F;
  if ( v5 == 6 )
  {
    ++*(_DWORD *)(pobj + 24);
    goto LABEL_10;
  }
  if ( v5 == 7 )
  {
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)(pobj - 24));
    goto LABEL_10;
  }
  if ( (val->Type & 0x8Fu) > 7 )
  {
    if ( (val->Type & 0x8Fu) <= 0xA )
    {
LABEL_7:
      *(_DWORD *)(pobj + 32) = (*(_DWORD *)(pobj + 32) + 1) & 0x8FBFFFFF;
      goto LABEL_10;
    }
    if ( v5 == 11 )
    {
      pobj &= ~2ui64;
      goto LABEL_7;
    }
  }
LABEL_10:
  val->pPrev = this->ExternalObjRefs.Root.pPrev;
  val->pNext = (Scaleform::GFx::Value *)&this->ExternalObjRefs;
  this->ExternalObjRefs.Root.pPrev->pNext = val;
  this->ExternalObjRefs.Root.pPrev = val;
}

// File Line: 267
// RVA: 0x802AC0
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::ObjectRelease(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::Value *val,
        unsigned __int64 pobj)
{
  __int32 v4; // eax
  int v5; // eax

  v4 = val->Type & 0x8F;
  if ( v4 == 6 )
  {
    if ( (*(_DWORD *)(pobj + 24))-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)pobj);
  }
  else
  {
    if ( v4 == 7 )
    {
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)(pobj - 24));
      goto LABEL_12;
    }
    if ( (val->Type & 0x8Fu) > 7 )
    {
      if ( (val->Type & 0x8Fu) > 0xA )
      {
        if ( v4 != 11 )
          goto LABEL_12;
        pobj &= ~2ui64;
      }
      v5 = *(_DWORD *)(pobj + 32);
      if ( (v5 & 0x3FFFFF) != 0 )
      {
        *(_DWORD *)(pobj + 32) = v5 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pobj);
      }
    }
  }
LABEL_12:
  val->pPrev->pNext = val->pNext;
  val->pNext->Scaleform::ListNode<Scaleform::GFx::Value>::$41EDDC8CC4664C9FE26D4D23F9ACAEE4::pPrev = val->pPrev;
}

// File Line: 315
// RVA: 0x7F2050
_BOOL8 __fastcall Scaleform::GFx::AS3ValueObjectInterface::HasMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Object *pdata,
        const char *name,
        bool isdobj)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rsi
  Scaleform::RefCountImplCoreVtbl *vfptr; // r15
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *v8; // r13
  char v9; // di
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Value::V2U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *vecDelDtor; // rdx
  int v13; // esi
  const char *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::Traits *v20; // r9
  __int64 v21; // rdx
  __int64 v22; // rcx
  __int64 v23; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v24; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v25; // rbx
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int Size; // eax
  bool v28; // bl
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v30; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Multiname mn; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::GFx::AS3::Value v34; // [rsp+50h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::PropRef v35; // [rsp+70h] [rbp-29h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+7h] BYREF
  Scaleform::GFx::AS3::Value::V2U v37; // [rsp+A8h] [rbp+Fh]
  __int64 v38; // [rsp+B0h] [rbp+17h]
  Scaleform::GFx::ASString v39; // [rsp+100h] [rbp+67h] BYREF
  Scaleform::GFx::ASString namea; // [rsp+108h] [rbp+6Fh] BYREF

  v38 = -2i64;
  pObject = this->pMovieRoot->pASMovieRoot.pObject;
  vfptr = pObject[2].vfptr;
  v8 = (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&pObject[9];
  v9 = 10;
  v34.Flags = 10;
  v34.Bonus.pWeakProxy = 0i64;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&pObject[9],
            &result,
            name)->pNode;
  v34.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    pNode = 0i64;
    v34.value.VS._1.VStr = 0i64;
    v11.VObj = v37.VObj;
    v34.value.VS._2 = v37;
    v9 = 12;
    v34.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
    v11.VObj = (Scaleform::GFx::AS3::Object *)v34.value.VS._2;
  }
  vecDelDtor = (Scaleform::GFx::AS3::GASRefCountBase *)pObject[2].vfptr[53].__vecDelDtor;
  mn.Kind = MN_QName;
  mn.Obj.pObject = vecDelDtor;
  if ( vecDelDtor )
    vecDelDtor->RefCount = (vecDelDtor->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0i64;
  v13 = v9 & 0x1F;
  if ( (unsigned int)(v13 - 12) <= 3
    && pNode
    && (v14 = pNode[1].pData, *((_DWORD *)v14 + 30) == 17)
    && (v14[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&mn.Name, (Scaleform::GFx::ASString *)&pNode[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
    mn.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v34, 2);
    *(_QWORD *)&mn.Name.Flags = *(_QWORD *)&v34.Flags;
    mn.Name.Bonus.pWeakProxy = 0i64;
    mn.Name.value.VS._1.VStr = pNode;
    mn.Name.value.VS._2 = v11;
    if ( (v9 & 0x1Fu) > 9 )
    {
      if ( v13 == 10 )
      {
        ++pNode->RefCount;
      }
      else if ( (v9 & 0x1Fu) <= 0xF )
      {
        if ( pNode )
          pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v9 & 0x1Fu) <= 0x11 && v11.VObj )
      {
        v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (mn.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &v39);
      if ( v39.pNode->Size )
      {
        if ( *v39.pNode->pData == 64 )
        {
          mn.Kind |= 8u;
          v15 = Scaleform::GFx::ASString::Substring(&v39, &namea, 1, v39.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&mn.Name, v15);
          v16 = namea.pNode;
          v17 = namea.pNode->RefCount-- == 1;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
      }
      v18 = v39.pNode;
      v17 = v39.pNode->RefCount-- == 1;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  if ( (v9 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v34);
  v19 = result.pNode;
  v17 = result.pNode->RefCount-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  memset(&v35, 0, 20);
  v35.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Object::FindProperty(pdata, &v35, &mn, FindGet);
  if ( (v35.This.Flags & 0x1F) != 0
    && (((__int64)v35.pSI & 1) == 0 || ((unsigned __int64)v35.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)v35.pSI & 2) == 0 || ((unsigned __int64)v35.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0)
    || (v20 = pdata->pTraits.pObject, (unsigned int)(v20->TraitsType - 29) >= 5)
    || (v20->Flags & 0x20) != 0 )
  {
    v28 = (v35.This.Flags & 0x1F) != 0
       && (((__int64)v35.pSI & 1) == 0 || ((unsigned __int64)v35.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
       && (((__int64)v35.pSI & 2) == 0 || ((unsigned __int64)v35.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0);
  }
  else
  {
    v21 = 0i64;
    if ( (*(_WORD *)(*(_QWORD *)&pdata[1].RefCount + 106i64) & 0x200) != 0 )
      v21 = *(_QWORD *)&pdata[1].RefCount;
    if ( !v21
      || (v22 = v21 + 4i64 * *(unsigned __int8 *)(v21 + 109),
          v23 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v22 + 40i64))(v22),
          v24 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v23 - 72),
          !v23) )
    {
      v24 = 0i64;
    }
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(v8, &namea, name);
    v25 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
            v24,
            (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&v39,
            &namea)->pObject;
    v26 = v39.pNode;
    if ( v39.pNode )
    {
      if ( ((__int64)v39.pNode & 1) != 0 )
      {
        --v39.pNode;
      }
      else
      {
        Size = v39.pNode->Size;
        if ( (Size & 0x3FFFFF) != 0 )
        {
          v39.pNode->Size = Size - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v26);
        }
      }
    }
    if ( v25 )
    {
      v28 = 1;
    }
    else
    {
      if ( LOBYTE(vfptr[21].__vecDelDtor) )
        LOBYTE(vfptr[21].__vecDelDtor) = 0;
      v28 = 0;
    }
    v29 = namea.pNode;
    v17 = namea.pNode->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  }
  if ( (v35.This.Flags & 0x1F) > 9 )
  {
    if ( (v35.This.Flags & 0x200) != 0 )
    {
      v17 = v35.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v35.This.Bonus, 0, 24);
      v35.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35.This);
    }
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      v17 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v30 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
      }
    }
  }
  return v28;
}

// File Line: 358
// RVA: 0x7EBD10
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        char *name,
        Scaleform::GFx::Value *pval)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // r13
  Scaleform::GFx::AS3::VM *v7; // r15
  char v8; // si
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rdx
  int v12; // r14d
  const char *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v23; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // rbx
  Scaleform::GFx::ASStringNode *v25; // rcx
  unsigned int Size; // eax
  unsigned int Flags; // ebx
  unsigned __int8 v28; // bl
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v30; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value other; // [rsp+20h] [rbp-71h] BYREF
  int v34; // [rsp+40h] [rbp-51h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v35; // [rsp+48h] [rbp-49h] BYREF
  Scaleform::GFx::AS3::Value v36; // [rsp+50h] [rbp-41h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+70h] [rbp-21h] BYREF
  Scaleform::GFx::ASString result; // [rsp+90h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::Value::V2U v39; // [rsp+98h] [rbp+7h]
  __int64 v40; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::ASString v41; // [rsp+F0h] [rbp+5Fh] BYREF
  Scaleform::GFx::ASString namea; // [rsp+F8h] [rbp+67h] BYREF
  char *pstr; // [rsp+100h] [rbp+6Fh]

  pstr = name;
  v40 = -2i64;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = pObject->pAVM.pObject;
  v8 = 10;
  other.Flags = 10;
  other.Bonus.pWeakProxy = 0i64;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            &pObject->BuiltinsMgr,
            &result,
            name)->pNode;
  other.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    pNode = 0i64;
    other.value.VS._1.VStr = 0i64;
    v10.VObj = v39.VObj;
    other.value.VS._2 = v39;
    v8 = 12;
    other.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
    v10.VObj = (Scaleform::GFx::AS3::Object *)other.value.VS._2;
  }
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7->PublicNamespace.pObject;
  v34 = 0;
  v35.pObject = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v36.Flags = 0;
  v36.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && pNode
    && (v13 = pNode[1].pData, *((_DWORD *)v13 + 30) == 17)
    && (v13[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v36, (Scaleform::GFx::ASString *)&pNode[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v35,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
    v34 &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&other, 2);
    *(_QWORD *)&v36.Flags = *(_QWORD *)&other.Flags;
    v36.Bonus.pWeakProxy = 0i64;
    v36.value.VS._1.VStr = pNode;
    v36.value.VS._2 = v10;
    if ( (v8 & 0x1Fu) > 9 )
    {
      if ( v12 == 10 )
      {
        ++pNode->RefCount;
      }
      else if ( (v8 & 0x1Fu) <= 0xF )
      {
        if ( pNode )
          pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v8 & 0x1Fu) <= 0x11 && v10.VObj )
      {
        v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v36.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v36, &v41);
      if ( v41.pNode->Size )
      {
        if ( *v41.pNode->pData == 64 )
        {
          v34 |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v41, &namea, 1, v41.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v36, v14);
          v15 = namea.pNode;
          v16 = namea.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = v41.pNode;
      v16 = v41.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( (v8 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
  v18 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD *, Scaleform::GFx::ASString *, int *, Scaleform::GFx::AS3::Value *))(*pdata + 32i64))(
                   pdata,
                   &v41,
                   &v34,
                   &value) )
  {
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, pval);
    if ( v7->HandleException )
    {
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
      v28 = 0;
    }
    else
    {
      v28 = 1;
    }
  }
  else
  {
    v19 = pdata[5];
    if ( (unsigned int)(*(_DWORD *)(v19 + 120) - 29) >= 5 || (*(_BYTE *)(v19 + 112) & 0x20) != 0 )
    {
      if ( v7->HandleException )
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
      if ( (pval->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
          pval->pObjectInterface,
          pval,
          pval->mValue);
        pval->pObjectInterface = 0i64;
      }
      pval->Type = VT_Undefined;
      v28 = 0;
    }
    else
    {
      v20 = 0i64;
      if ( (*(_WORD *)(pdata[11] + 106i64) & 0x200) != 0 )
        v20 = pdata[11];
      if ( !v20
        || (v21 = v20 + 4i64 * *(unsigned __int8 *)(v20 + 109),
            v22 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v21 + 40i64))(v21),
            v23 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v22 - 72),
            !v22) )
      {
        v23 = 0i64;
      }
      Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
        &pObject->BuiltinsMgr,
        &namea,
        pstr);
      v24 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
              v23,
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *)&v41,
              &namea)->pObject;
      v25 = v41.pNode;
      if ( v41.pNode )
      {
        if ( ((__int64)v41.pNode & 1) != 0 )
        {
          --v41.pNode;
        }
        else
        {
          Size = v41.pNode->Size;
          if ( (Size & 0x3FFFFF) != 0 )
          {
            v41.pNode->Size = Size - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v25);
          }
        }
      }
      if ( v24 )
      {
        other.Flags = 12;
        other.Bonus.pWeakProxy = 0i64;
        other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v24;
        v24->RefCount = (v24->RefCount + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(&value, &other);
        Flags = other.Flags;
        if ( (other.Flags & 0x1F) > 9 )
        {
          if ( (other.Flags & 0x200) != 0 )
          {
            v16 = other.Bonus.pWeakProxy->RefCount-- == 1;
            if ( v16 )
              ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            memset(&other.Bonus, 0, 24);
            other.Flags = Flags & 0xFFFFFDE0;
          }
          else
          {
            Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
          }
        }
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, pval);
        v28 = 1;
      }
      else
      {
        if ( v7->HandleException )
          v7->HandleException = 0;
        if ( (pval->Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
            pval->pObjectInterface,
            pval,
            pval->mValue);
          pval->pObjectInterface = 0i64;
        }
        pval->Type = VT_Undefined;
        v28 = 0;
      }
      v29 = namea.pNode;
      v16 = namea.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    }
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v16 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  if ( (v36.Flags & 0x1F) > 9 )
  {
    if ( (v36.Flags & 0x200) != 0 )
    {
      v16 = v36.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v36.Bonus, 0, 24);
      v36.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v36);
    }
  }
  v30 = v35.pObject;
  if ( v35.pObject )
  {
    if ( ((__int64)v35.pObject & 1) != 0 )
    {
      --v35.pObject;
    }
    else
    {
      RefCount = v35.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v35.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
      }
    }
  }
  return v28;
}

// File Line: 414
// RVA: 0x81A110
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        char *name,
        Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // r13
  Scaleform::GFx::AS3::VM *v7; // r14
  char v8; // di
  Scaleform::GFx::ASStringNode *pNode; // rbx
  unsigned __int64 VObj; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v11; // rdx
  int v12; // esi
  const char *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  __int64 v19; // rcx
  __int64 v20; // rdx
  __int64 v21; // rcx
  __int64 v22; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v23; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v25; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v27; // rcx
  unsigned __int8 v28; // bl
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *v30; // rcx
  unsigned int v31; // eax
  int v33; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v34; // [rsp+28h] [rbp-D8h] BYREF
  Scaleform::GFx::AS3::Value v35; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::ASString namea; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::String v37; // [rsp+58h] [rbp-A8h] BYREF
  Scaleform::GFx::AS3::Value v38; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> v40; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::ASString v41; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp-50h] BYREF
  __int64 v43; // [rsp+B8h] [rbp-48h]
  __int64 v44; // [rsp+C0h] [rbp-40h]
  unsigned __int64 v45; // [rsp+C8h] [rbp-38h]
  Scaleform::MsgFormat::Sink r; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::MsgFormat v47; // [rsp+F0h] [rbp-10h] BYREF
  char v48; // [rsp+540h] [rbp+440h] BYREF
  Scaleform::GFx::ASString v49; // [rsp+548h] [rbp+448h] BYREF
  char *v; // [rsp+550h] [rbp+450h] BYREF
  Scaleform::GFx::Value *gfxVal; // [rsp+558h] [rbp+458h]

  gfxVal = value;
  v = name;
  v43 = -2i64;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = pObject->pAVM.pObject;
  v8 = 10;
  v38.Flags = 10;
  v38.Bonus.pWeakProxy = 0i64;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            &pObject->BuiltinsMgr,
            &result,
            name)->pNode;
  v38.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    pNode = 0i64;
    v44 = 0i64;
    v38.value = (Scaleform::GFx::AS3::Value::VU)__PAIR128__(v45, 0i64);
    VObj = v45;
    v8 = 12;
    v38.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
    VObj = (unsigned __int64)v38.value.VS._2.VObj;
  }
  v11 = (Scaleform::GFx::AS3::Instances::fl::XMLList *)v7->PublicNamespace.pObject;
  v33 = 0;
  v34.pObject = v11;
  if ( v11 )
    v11->RefCount = (v11->RefCount + 1) & 0x8FBFFFFF;
  v35.Flags = 0;
  v35.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && pNode
    && (v13 = pNode[1].pData, *((_DWORD *)v13 + 30) == 17)
    && (v13[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v35, (Scaleform::GFx::ASString *)&pNode[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v34,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
    v33 &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v38, 2);
    *(_QWORD *)&v35.Flags = *(_QWORD *)&v38.Flags;
    v35.Bonus.pWeakProxy = 0i64;
    v35.value.VS._1.VStr = pNode;
    v35.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)VObj;
    if ( (v8 & 0x1Fu) > 9 )
    {
      if ( v12 == 10 )
      {
        ++pNode->RefCount;
      }
      else if ( (v8 & 0x1Fu) <= 0xF )
      {
        if ( pNode )
          pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v8 & 0x1Fu) <= 0x11 && VObj )
      {
        *(_DWORD *)(VObj + 32) = (*(_DWORD *)(VObj + 32) + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v35.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v35, &v49);
      if ( v49.pNode->Size )
      {
        if ( *v49.pNode->pData == 64 )
        {
          v33 |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v49, &v41, 1, v49.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v35, v14);
          v15 = v41.pNode;
          v16 = v41.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      v17 = v49.pNode;
      v16 = v49.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( (v8 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v38);
  v18 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v19 + 120) - 29) < 5 && (*(_BYTE *)(v19 + 112) & 0x20) == 0 )
  {
    v20 = 0i64;
    if ( (*(_WORD *)(pdata[11] + 106i64) & 0x200) != 0 )
      v20 = pdata[11];
    if ( !v20
      || (v21 = v20 + 4i64 * *(unsigned __int8 *)(v20 + 109),
          v22 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v21 + 40i64))(v21),
          v23 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v22 - 72),
          !v22) )
    {
      v23 = 0i64;
    }
    Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
      &pObject->BuiltinsMgr,
      &namea,
      name);
    v24 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(v23, &v40, &namea)->pObject;
    v25 = v40.pObject;
    if ( v40.pObject )
    {
      if ( ((__int64)v40.pObject & 1) != 0 )
      {
        --v40.pObject;
      }
      else
      {
        RefCount = v40.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v40.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
        }
      }
    }
    if ( v24 )
    {
      Scaleform::String::String(&v37);
      r.Type = tStr;
      r.SinkData.pStr = &v37;
      Scaleform::MsgFormat::MsgFormat(&v47, &r);
      Scaleform::MsgFormat::Parse(&v47, "Property {0} already exists as a DisplayObject. SetMember aborted.");
      Scaleform::MsgFormat::FormatD1<char const *>(&v47, (const char **)&v);
      Scaleform::MsgFormat::FinishFormatD(&v47);
      Scaleform::MsgFormat::~MsgFormat(&v47);
      pObject->Scaleform::GFx::AS3::FlashUI::vfptr->Output(
        &pObject->Scaleform::GFx::AS3::FlashUI,
        Output_Error,
        (const char *)((v37.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v37.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v27 = namea.pNode;
      v16 = namea.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v27);
      v28 = 0;
      goto LABEL_62;
    }
    v29 = namea.pNode;
    v16 = namea.pNode->RefCount-- == 1;
    if ( v16 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  }
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, gfxVal, &pdestVal);
  if ( *(_BYTE *)(*(__int64 (__fastcall **)(_QWORD *, char *, int *, Scaleform::GFx::AS3::Value *))(*pdata + 24i64))(
                   pdata,
                   &v48,
                   &v33,
                   &pdestVal) )
  {
    v28 = 1;
  }
  else
  {
    if ( v7->HandleException )
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v7);
    v28 = 0;
  }
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags & 0x200) != 0 )
    {
      v16 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pdestVal.Bonus, 0, 24);
      pdestVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
LABEL_62:
  if ( (v35.Flags & 0x1F) > 9 )
  {
    if ( (v35.Flags & 0x200) != 0 )
    {
      v16 = v35.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v35.Bonus, 0, 24);
      v35.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v35);
    }
  }
  v30 = v34.pObject;
  if ( v34.pObject )
  {
    if ( ((__int64)v34.pObject & 1) != 0 )
    {
      --v34.pObject;
    }
    else
    {
      v31 = v34.pObject->RefCount;
      if ( (v31 & 0x3FFFFF) != 0 )
      {
        v34.pObject->RefCount = v31 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v30);
      }
    }
  }
  return v28;
}

// File Line: 460
// RVA: 0x7F69B0
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::Invoke(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Object *pdata,
        Scaleform::GFx::Value *presult,
        const char *name,
        Scaleform::GFx::Value *pargs,
        unsigned __int64 nargs)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // r12
  Scaleform::GFx::AS3::VM *v8; // r13
  char v9; // di
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::AS3::Value::V2U v11; // rcx
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rdx
  int v13; // esi
  const char *v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *Data; // rcx
  unsigned __int64 v20; // r14
  __int64 v21; // rbx
  Scaleform::GFx::Value *v22; // rdi
  unsigned __int64 v23; // rsi
  unsigned __int8 v24; // bl
  Scaleform::GFx::AS3::GASRefCountBase *v25; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value _this; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> result; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::GFx::AS3::Value v31; // [rsp+A8h] [rbp-58h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+C8h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::PropRef v33; // [rsp+E8h] [rbp-18h] BYREF
  Scaleform::GFx::ASString v34; // [rsp+118h] [rbp+18h] BYREF
  __int64 v35; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ASString v36; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::GFx::Value *pdestVal; // [rsp+180h] [rbp+80h]

  pdestVal = presult;
  v35 = -2i64;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = pObject->pAVM.pObject;
  v9 = 10;
  _this.Flags = 10;
  _this.Bonus.pWeakProxy = 0i64;
  pNode = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            &pObject->BuiltinsMgr,
            (Scaleform::GFx::ASString *)&result,
            name)->pNode;
  _this.value.VS._1.VStr = pNode;
  if ( pNode == &pNode->pManager->NullStringNode )
  {
    pNode = 0i64;
    _this.value.VS._1.VStr = 0i64;
    v11.VObj = (Scaleform::GFx::AS3::Object *)result.Size;
    _this.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)result.Size;
    v9 = 12;
    _this.Flags = 12;
  }
  else
  {
    ++pNode->RefCount;
    v11.VObj = (Scaleform::GFx::AS3::Object *)_this.value.VS._2;
  }
  v12 = v8->PublicNamespace.pObject;
  mn.Kind = MN_QName;
  mn.Obj.pObject = v12;
  if ( v12 )
    v12->RefCount = (v12->RefCount + 1) & 0x8FBFFFFF;
  mn.Name.Flags = 0;
  mn.Name.Bonus.pWeakProxy = 0i64;
  v13 = v9 & 0x1F;
  if ( (unsigned int)(v13 - 12) <= 3
    && pNode
    && (v14 = pNode[1].pData, *((_DWORD *)v14 + 30) == 17)
    && (v14[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&mn.Name, (Scaleform::GFx::ASString *)&pNode[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&mn.Obj,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&pNode[1].RefCount);
    mn.Kind &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&_this, 2);
    *(_QWORD *)&mn.Name.Flags = *(_QWORD *)&_this.Flags;
    mn.Name.Bonus.pWeakProxy = 0i64;
    mn.Name.value.VS._1.VStr = pNode;
    mn.Name.value.VS._2 = v11;
    if ( (v9 & 0x1Fu) > 9 )
    {
      if ( v13 == 10 )
      {
        ++pNode->RefCount;
      }
      else if ( (v9 & 0x1Fu) <= 0xF )
      {
        if ( pNode )
          pNode->Size = (pNode->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v9 & 0x1Fu) <= 0x11 && v11.VObj )
      {
        v11.VObj->RefCount = (v11.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (mn.Name.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&mn.Name, &v36);
      if ( v36.pNode->Size )
      {
        if ( *v36.pNode->pData == 64 )
        {
          mn.Kind |= 8u;
          v15 = Scaleform::GFx::ASString::Substring(&v36, &v34, 1, v36.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&mn.Name, v15);
          v16 = v34.pNode;
          v17 = v34.pNode->RefCount-- == 1;
          if ( v17 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v16);
        }
      }
      v18 = v36.pNode;
      v17 = v36.pNode->RefCount-- == 1;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
  if ( (v9 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
  Data = (Scaleform::GFx::ASStringNode *)result.Data;
  v17 = LODWORD(result.Data->value.VS._2.VObj)-- == 1;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(Data);
  memset(&v33, 0, 20);
  v33.This.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::Object::FindProperty(pdata, &v33, &mn, FindGet);
  if ( (v33.This.Flags & 0x1F) != 0
    && (((__int64)v33.pSI & 1) == 0 || ((unsigned __int64)v33.pSI & 0xFFFFFFFFFFFFFFFEui64) != 0)
    && (((__int64)v33.pSI & 2) == 0 || ((unsigned __int64)v33.pSI & 0xFFFFFFFFFFFFFFFDui64) != 0) )
  {
    value.Flags = 0;
    value.Bonus.pWeakProxy = 0i64;
    v31.Flags = 0;
    v31.Bonus.pWeakProxy = 0i64;
    if ( !Scaleform::GFx::AS3::PropRef::GetSlotValueUnsafe(
            &v33,
            (Scaleform::GFx::AS3::CheckResult *)&v36,
            v8,
            &value,
            valGet)->Result )
      goto LABEL_63;
    v20 = nargs;
    if ( nargs )
    {
      v36.pNode = (Scaleform::GFx::ASStringNode *)&result;
      v21 = 0i64;
      memset(&result, 0, sizeof(result));
      Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
        &result,
        (int)nargs);
      if ( v20 )
      {
        v22 = pargs;
        v23 = v20;
        do
        {
          Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, v22++, &result.Data[v21++]);
          --v23;
        }
        while ( v23 );
      }
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0i64;
      _this.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pdata;
      if ( pdata )
        pdata->RefCount = (pdata->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v8, &value, &_this, &v31, v20, result.Data, 0);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags & 0x200) != 0 )
        {
          v17 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v17 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&_this.Bonus, 0, 24);
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
      v36.pNode = (Scaleform::GFx::ASStringNode *)&result;
      Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(result.Data, result.Size);
      if ( result.Data )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    else
    {
      _this.Flags = 12;
      _this.Bonus.pWeakProxy = 0i64;
      _this.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)pdata;
      if ( pdata )
        pdata->RefCount = (pdata->RefCount + 1) & 0x8FBFFFFF;
      Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v8, &value, &_this, &v31, 0, 0i64, 0);
      if ( (_this.Flags & 0x1F) > 9 )
      {
        if ( (_this.Flags & 0x200) != 0 )
        {
          v17 = _this.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v17 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&_this.Bonus, 0, 24);
          _this.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&_this);
        }
      }
    }
    if ( v8->HandleException )
      goto LABEL_63;
    if ( pdestVal )
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &v31, pdestVal);
    if ( v8->HandleException )
    {
LABEL_63:
      Scaleform::GFx::AS3::VM::OutputAndIgnoreException(v8);
      v24 = 0;
    }
    else
    {
      v24 = 1;
    }
    if ( (v31.Flags & 0x1F) > 9 )
    {
      if ( (v31.Flags & 0x200) != 0 )
      {
        v17 = v31.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&v31.Bonus, 0, 24);
        v31.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v31);
      }
    }
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v17 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
        value.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
  }
  else
  {
    v24 = 0;
  }
  if ( (v33.This.Flags & 0x1F) > 9 )
  {
    if ( (v33.This.Flags & 0x200) != 0 )
    {
      v17 = v33.This.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v33.This.Bonus, 0, 24);
      v33.This.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v33.This);
    }
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      v17 = mn.Name.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v17 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v25 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v25);
      }
    }
  }
  return v24;
}

// File Line: 518
// RVA: 0x7F7A80
// positive sp value has been detected, the output may be wrong!
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::InvokeClosure(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        unsigned __int64 pdata,
        Scaleform::GFx::AS3::Value::V1U dataAux,
        Scaleform::GFx::Value *presult)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // r12
  Scaleform::GFx::AS3::VM *v6; // r13
  unsigned __int64 v7; // rbx
  unsigned int Flags; // edi
  bool v9; // zf
  __int64 v10; // rdi
  Scaleform::GFx::Value *v11; // rsi
  __int64 v12; // r14
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  unsigned __int8 v18; // di
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v20; // rcx
  unsigned int v21; // eax
  unsigned int v22; // ebx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v24; // rcx
  unsigned int Size; // eax
  unsigned int v26; // edx
  Scaleform::GFx::AS3::Value other; // [rsp+18h] [rbp-59h] BYREF
  Scaleform::GFx::AS3::Value func; // [rsp+38h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value result; // [rsp+58h] [rbp-19h] BYREF
  Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> v31; // [rsp+78h] [rbp+7h] BYREF
  __int64 v32; // [rsp+90h] [rbp+1Fh]
  Scaleform::GFx::Value *vars0; // [rsp+E0h] [rbp+6Fh]
  Scaleform::GFx::Value *retaddr; // [rsp+E8h] [rbp+77h]
  __int64 argc; // [rsp+F0h] [rbp+7Fh]

  v32 = -2i64;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v6 = pObject->pAVM.pObject;
  func.Flags = 0;
  func.Bonus.pWeakProxy = 0i64;
  result.Flags = 0;
  result.Bonus.pWeakProxy = 0i64;
  v7 = pdata & 0xFFFFFFFFFFFFFFFDui64;
  other.Bonus.pWeakProxy = 0i64;
  other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)(pdata & 0xFFFFFFFFFFFFFFFDui64);
  if ( ((pdata >> 1) & 1) != 0 )
  {
    other.Flags = 17;
    other.value.VS._1.VInt = dataAux.VInt;
    if ( v7 )
      *(_DWORD *)((pdata & 0xFFFFFFFFFFFFFFFDui64) + 0x20) = (*(_DWORD *)((pdata & 0xFFFFFFFFFFFFFFFDui64) + 0x20) + 1) & 0x8FBFFFFF;
  }
  else
  {
    other.Flags = 16;
    other.value.VS._1 = dataAux;
    if ( v7 )
      *(_DWORD *)((pdata & 0xFFFFFFFFFFFFFFFDui64) + 0x20) = (*(_DWORD *)((pdata & 0xFFFFFFFFFFFFFFFDui64) + 0x20) + 1) & 0x8FBFFFFF;
  }
  Scaleform::GFx::AS3::Value::Assign(&func, &other);
  Flags = other.Flags;
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags & 0x200) != 0 )
    {
      v9 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Flags = Flags & 0xFFFFFDE0;
      memset(&other.Bonus, 0, 24);
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
  if ( argc )
  {
    memset(&v31, 0, sizeof(v31));
    Scaleform::ArrayData<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v31,
      (int)argc);
    if ( argc )
    {
      v10 = 0i64;
      v11 = retaddr;
      v12 = argc;
      do
      {
        Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, v11++, &v31.Data[v10++]);
        --v12;
      }
      while ( v12 );
      presult = vars0;
    }
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v7;
    if ( v7 )
      *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, &func, &other, &result, argc, v31.Data, 0);
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v9 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        switch ( other.Flags & 0x1F )
        {
          case 0xA:
            VStr = other.value.VS._1.VStr;
            v9 = other.value.VS._1.VStr->RefCount-- == 1;
            if ( v9 )
              Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
            break;
          case 0xB:
          case 0xC:
          case 0xD:
          case 0xE:
          case 0xF:
            VObj = other.value.VS._1.VObj;
            if ( !other.value.VS._1.VBool )
              goto LABEL_32;
            --other.value.VS._1.VStr;
            break;
          case 0x10:
          case 0x11:
            VObj = other.value.VS._2.VObj;
            if ( ((__int64)other.value.VS._2.VObj & 1) != 0 )
            {
              --other.value.VS._2.VObj;
            }
            else
            {
LABEL_32:
              if ( VObj )
              {
                RefCount = VObj->RefCount;
                if ( (RefCount & 0x3FFFFF) != 0 )
                {
                  VObj->RefCount = RefCount - 1;
                  Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                }
              }
            }
            break;
          default:
            break;
        }
      }
    }
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(v31.Data, v31.Size);
    if ( v31.Data )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
    other.Flags = 12;
    other.Bonus.pWeakProxy = 0i64;
    other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v7;
    if ( v7 )
      *(_DWORD *)(v7 + 32) = (*(_DWORD *)(v7 + 32) + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::VM::ExecuteInternalUnsafe(v6, &func, &other, &result, 0, 0i64, 0);
    if ( (other.Flags & 0x1F) > 9 )
    {
      if ( (other.Flags & 0x200) != 0 )
      {
        v9 = other.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&other.Bonus, 0, 24);
        other.Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
      }
    }
  }
  if ( v6->HandleException )
  {
    v6->HandleException = 0;
    p_ExceptionObj = &v6->ExceptionObj;
    Scaleform::GFx::AS3::VM::OutputError(v6, &v6->ExceptionObj);
    if ( (v6->ExceptionObj.Flags & 0x1F) > 9 )
    {
      if ( (v6->ExceptionObj.Flags & 0x200) != 0 )
      {
        pWeakProxy = v6->ExceptionObj.Bonus.pWeakProxy;
        v9 = pWeakProxy->RefCount-- == 1;
        if ( v9 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v6->ExceptionObj.Bonus.pWeakProxy = 0i64;
        v6->ExceptionObj.value.VS._1.VStr = 0i64;
        v6->ExceptionObj.value.VS._2.VObj = 0i64;
        p_ExceptionObj->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v6->ExceptionObj);
      }
    }
    p_ExceptionObj->Flags &= 0xFFFFFFE0;
    v18 = 0;
  }
  else
  {
    if ( presult )
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &result, presult);
    v18 = 1;
  }
  if ( (result.Flags & 0x1F) > 9 )
  {
    if ( (result.Flags & 0x200) != 0 )
    {
      v9 = result.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&result.Bonus, 0, 24);
      result.Flags &= 0xFFFFFDE0;
    }
    else
    {
      switch ( result.Flags & 0x1F )
      {
        case 0xA:
          v19 = result.value.VS._1.VStr;
          v9 = result.value.VS._1.VStr->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v19);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v20 = result.value.VS._1.VObj;
          if ( !result.value.VS._1.VBool )
            goto LABEL_68;
          --result.value.VS._1.VStr;
          break;
        case 0x10:
        case 0x11:
          v20 = result.value.VS._2.VObj;
          if ( ((__int64)result.value.VS._2.VObj & 1) != 0 )
          {
            --result.value.VS._2.VObj;
          }
          else
          {
LABEL_68:
            if ( v20 )
            {
              v21 = v20->RefCount;
              if ( (v21 & 0x3FFFFF) != 0 )
              {
                v20->RefCount = v21 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
              }
            }
          }
          break;
        default:
          break;
      }
    }
  }
  v22 = func.Flags;
  if ( (func.Flags & 0x1F) > 9 )
  {
    if ( (func.Flags & 0x200) != 0 )
    {
      v9 = func.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v9 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&func.Bonus, 0, 24);
      func.Flags = v22 & 0xFFFFFDE0;
    }
    else
    {
      switch ( func.Flags & 0x1F )
      {
        case 0xA:
          v23 = func.value.VS._1.VStr;
          v9 = func.value.VS._1.VStr->RefCount-- == 1;
          if ( v9 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v23);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          if ( func.value.VS._1.VBool )
          {
            --func.value.VS._1.VStr;
          }
          else
          {
            v24 = func.value.VS._1.VObj;
            if ( func.value.VS._1.VStr )
            {
              Size = func.value.VS._1.VStr->Size;
              if ( (Size & 0x3FFFFF) != 0 )
              {
                func.value.VS._1.VStr->Size = Size - 1;
                goto LABEL_89;
              }
            }
          }
          break;
        case 0x10:
        case 0x11:
          if ( ((__int64)func.value.VS._2.VObj & 1) != 0 )
          {
            --func.value.VS._2.VObj;
          }
          else
          {
            v24 = func.value.VS._2.VObj;
            if ( func.value.VS._2.VObj )
            {
              v26 = func.value.VS._2.VObj->RefCount;
              if ( (v26 & 0x3FFFFF) != 0 )
              {
                func.value.VS._2.VObj->RefCount = v26 - 1;
LABEL_89:
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v24);
              }
            }
          }
          break;
        default:
          return v18;
      }
    }
  }
  return v18;
}

// File Line: 561
// RVA: 0x7C0AA0
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::DeleteMember(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        void *pdata,
        const char *name,
        bool isdobj)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rsi
  Scaleform::GFx::AS3::Value::V1U *v7; // rax
  char v8; // di
  Scaleform::GFx::AS3::Value::V1U v9; // rbx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  Scaleform::GFx::AS3::Instances::fl::XMLList *vecDelDtor; // rdx
  int v12; // esi
  const char *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v16; // zf
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned __int8 v19; // bl
  Scaleform::GFx::AS3::Instances::fl::XMLList *v20; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString result; // [rsp+20h] [rbp-39h] BYREF
  Scaleform::GFx::AS3::Value::V2U v24; // [rsp+28h] [rbp-31h]
  __int64 v25; // [rsp+30h] [rbp-29h]
  Scaleform::GFx::AS3::Value v26; // [rsp+38h] [rbp-21h] BYREF
  int v27; // [rsp+58h] [rbp-1h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> v28; // [rsp+60h] [rbp+7h] BYREF
  Scaleform::GFx::AS3::Value v29; // [rsp+68h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v30; // [rsp+C0h] [rbp+67h] BYREF
  Scaleform::GFx::ASString v31; // [rsp+C8h] [rbp+6Fh] BYREF

  v25 = -2i64;
  pObject = this->pMovieRoot->pASMovieRoot.pObject;
  vfptr = pObject[2].vfptr;
  v7 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                            (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)&pObject[9],
                                            &result,
                                            name);
  v8 = 10;
  v26.Flags = 10;
  v26.Bonus.pWeakProxy = 0i64;
  v9 = *v7;
  v26.value.VS._1 = v9;
  if ( v9.VStr == &v9.VStr->pManager->NullStringNode )
  {
    v9.VStr = 0i64;
    v26.value.VS._1.VStr = 0i64;
    v10.VObj = v24.VObj;
    v26.value.VS._2 = v24;
    v8 = 12;
    v26.Flags = 12;
  }
  else
  {
    ++v9.VStr->RefCount;
    v10.VObj = (Scaleform::GFx::AS3::Object *)v26.value.VS._2;
  }
  vecDelDtor = (Scaleform::GFx::AS3::Instances::fl::XMLList *)vfptr[53].__vecDelDtor;
  v27 = 0;
  v28.pObject = vecDelDtor;
  if ( vecDelDtor )
    vecDelDtor->RefCount = (vecDelDtor->RefCount + 1) & 0x8FBFFFFF;
  v29.Flags = 0;
  v29.Bonus.pWeakProxy = 0i64;
  v12 = v8 & 0x1F;
  if ( (unsigned int)(v12 - 12) <= 3
    && v9.VStr
    && (v13 = v9.VStr[1].pData, *((_DWORD *)v13 + 30) == 17)
    && (v13[112] & 0x20) == 0 )
  {
    Scaleform::GFx::AS3::Value::Assign(&v29, (Scaleform::GFx::ASString *)&v9.VStr[1].16);
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      &v28,
      *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v9.VStr[1].RefCount);
    v27 &= 0xFFFFFFF9;
  }
  else
  {
    _mm_prefetch((const char *)&v26, 2);
    *(_QWORD *)&v29.Flags = *(_QWORD *)&v26.Flags;
    v29.Bonus.pWeakProxy = 0i64;
    v29.value.VS._1 = v9;
    v29.value.VS._2 = v10;
    if ( (v8 & 0x1Fu) > 9 )
    {
      if ( v12 == 10 )
      {
        ++v9.VStr->RefCount;
      }
      else if ( (v8 & 0x1Fu) <= 0xF )
      {
        if ( v9.VStr )
          v9.VStr->Size = (v9.VStr->Size + 1) & 0x8FBFFFFF;
      }
      else if ( (v8 & 0x1Fu) <= 0x11 && v10.VObj )
      {
        v10.VObj->RefCount = (v10.VObj->RefCount + 1) & 0x8FBFFFFF;
      }
    }
    if ( (v29.Flags & 0x1F) == 10 )
    {
      Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v29, &v30);
      if ( v30.pNode->Size )
      {
        if ( *v30.pNode->pData == 64 )
        {
          v27 |= 8u;
          v14 = Scaleform::GFx::ASString::Substring(&v30, &v31, 1, v30.pNode->Size);
          Scaleform::GFx::AS3::Value::Assign(&v29, v14);
          pNode = v31.pNode;
          v16 = v31.pNode->RefCount-- == 1;
          if ( v16 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
      v17 = v30.pNode;
      v16 = v30.pNode->RefCount-- == 1;
      if ( v16 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
    }
  }
  if ( (v8 & 0x1Fu) > 9 )
    Scaleform::GFx::AS3::Value::ReleaseInternal(&v26);
  v18 = result.pNode;
  v16 = result.pNode->RefCount-- == 1;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  v19 = *(_BYTE *)(*(__int64 (__fastcall **)(void *, Scaleform::GFx::ASString *, int *))(*(_QWORD *)pdata + 64i64))(
                    pdata,
                    &v30,
                    &v27);
  if ( (v29.Flags & 0x1F) > 9 )
  {
    if ( (v29.Flags & 0x200) != 0 )
    {
      v16 = v29.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v16 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&v29.Bonus, 0, 24);
      v29.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v29);
    }
  }
  v20 = v28.pObject;
  if ( v28.pObject )
  {
    if ( ((__int64)v28.pObject & 1) != 0 )
    {
      --v28.pObject;
    }
    else
    {
      RefCount = v28.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v28.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v20);
      }
    }
  }
  return v19;
}

// File Line: 577
// RVA: 0x829B50
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::VisitMembers(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value::ObjectInterface::ObjVisitor *visitor,
        __int64 isdobj)
{
  Scaleform::GFx::AS3::Object *v5; // r14
  Scaleform::GFx::AS3::MovieRoot *pObject; // r12
  __int64 *v7; // r10
  Scaleform::GFx::AS3::Value::Extra v8; // rax
  _QWORD *v9; // rcx
  Scaleform::GFx::AS3::Value::Extra v10; // rdi
  __int64 v11; // rbx
  _QWORD *v12; // rcx
  Scaleform::GFx::AS3::Traits *v13; // rsi
  __int64 v14; // rbx
  unsigned __int64 FirstOwnSlotNum; // rdx
  Scaleform::GFx::ASStringNode *SlotNameNode; // rdi
  unsigned __int64 v17; // rax
  Scaleform::GFx::AS3::SlotInfo *SlotInfo; // r10
  int v19; // ecx
  bool v20; // zf
  unsigned __int64 Size; // rdx
  Scaleform::GFx::AS3::Traits *v22; // rcx
  __int64 v23; // rdx
  __int64 v24; // rcx
  __int64 v25; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v26; // rsi
  unsigned int i; // edi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v28; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v29; // rcx
  unsigned int RefCount; // eax
  unsigned int Flags; // ebx
  Scaleform::GFx::ASStringNode *VStr; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *VObj; // rcx
  unsigned int v34; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Value value; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::GFx::Value pdestVal; // [rsp+50h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> result; // [rsp+C0h] [rbp+40h] BYREF
  Scaleform::GFx::ASString v39; // [rsp+C8h] [rbp+48h] BYREF

  v5 = (Scaleform::GFx::AS3::Object *)pdata;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v7 = (__int64 *)(pdata + 48);
  if ( pdata != (char *)-48i64 )
  {
    isdobj = *v7;
    if ( *v7 )
    {
      v8.pWeakProxy = 0i64;
      v9 = (_QWORD *)(isdobj + 16);
      do
      {
        if ( *v9 != -2i64 )
          break;
        ++v8.pWeakProxy;
        v9 += 8;
      }
      while ( v8.pWeakProxy <= (Scaleform::GFx::AS3::WeakProxy *)*(_QWORD *)(isdobj + 8) );
      *(_QWORD *)&value.Flags = pdata + 48;
      value.Bonus = v8;
    }
    else
    {
      *(_QWORD *)&value.Flags = 0i64;
      value.Bonus.pWeakProxy = 0i64;
    }
    v10.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)value.Bonus;
    while ( *(_QWORD *)&value.Flags
         && **(_QWORD **)&value.Flags
         && (__int64)v10.pWeakProxy <= *(_QWORD *)(**(_QWORD **)&value.Flags + 8i64) )
    {
      pdestVal.pObjectInterface = 0i64;
      pdestVal.Type = VT_Undefined;
      v11 = **(_QWORD **)&value.Flags + ((__int64)v10.pWeakProxy << 6);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, (Scaleform::GFx::AS3::Value *)(v11 + 48), &pdestVal);
      visitor->vfptr->Visit(visitor, **(const char ***)(v11 + 40), &pdestVal);
      if ( (pdestVal.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
          pdestVal.pObjectInterface,
          &pdestVal,
          pdestVal.mValue);
        pdestVal.pObjectInterface = 0i64;
      }
      pdestVal.Type = VT_Undefined;
      pdata = *(char **)(**(_QWORD **)&value.Flags + 8i64);
      if ( (__int64)v10.pWeakProxy <= (__int64)pdata && ++v10.pWeakProxy <= (Scaleform::GFx::AS3::WeakProxy *)pdata )
      {
        v12 = (_QWORD *)(((__int64)v10.pWeakProxy << 6) + **(_QWORD **)&value.Flags + 16i64);
        do
        {
          if ( *v12 != -2i64 )
            break;
          ++v10.pWeakProxy;
          v12 += 8;
        }
        while ( v10.pWeakProxy <= (Scaleform::GFx::AS3::WeakProxy *)pdata );
      }
    }
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Value::ObjectInterface::ObjVisitor *, char *, Scaleform::GFx::Value::ObjectInterface::ObjVisitor *, __int64))visitor->vfptr->IncludeAS3PublicMembers)(
         visitor,
         pdata,
         visitor,
         isdobj) )
  {
    v13 = v5->pTraits.pObject;
    v14 = 0i64;
    if ( v13->FirstOwnSlotNum + v13->VArray.Data.Size )
    {
      do
      {
        pdestVal.pObjectInterface = 0i64;
        pdestVal.Type = VT_Undefined;
        if ( v14 < 0 || (FirstOwnSlotNum = v13->FirstOwnSlotNum, v14 < FirstOwnSlotNum) )
          SlotNameNode = Scaleform::GFx::AS3::Slots::GetSlotNameNode(
                           v13->Parent,
                           (Scaleform::GFx::AS3::AbsoluteIndex)v14);
        else
          SlotNameNode = v13->VArray.Data.Data[(unsigned int)v14 - FirstOwnSlotNum].Key.pObject;
        v39.pNode = SlotNameNode;
        ++SlotNameNode->RefCount;
        if ( v14 < 0 || (v17 = v13->FirstOwnSlotNum, v14 < v17) )
          SlotInfo = Scaleform::GFx::AS3::Slots::GetSlotInfo(v13->Parent, (Scaleform::GFx::AS3::AbsoluteIndex)v14);
        else
          SlotInfo = &v13->VArray.Data.Data[(unsigned int)v14 - v17].Value;
        v19 = (int)(*(_DWORD *)SlotInfo << 17) >> 27;
        if ( v19 != 11 && v19 <= 12 && !((int)(*((_DWORD *)SlotInfo->pNs.pObject + 10) << 28) >> 28) )
        {
          value.Flags = 0;
          value.Bonus.pWeakProxy = 0i64;
          Scaleform::GFx::AS3::SlotInfo::GetSlotValueUnsafe(
            SlotInfo,
            (Scaleform::GFx::AS3::CheckResult *)&result,
            &value,
            v5);
          Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, &pdestVal);
          visitor->vfptr->Visit(visitor, SlotNameNode->pData, &pdestVal);
          if ( (value.Flags & 0x1F) > 9 )
          {
            if ( (value.Flags & 0x200) != 0 )
            {
              v20 = value.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v20 )
                ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
              memset(&value.Bonus, 0, 24);
              value.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
            }
          }
        }
        v20 = SlotNameNode->RefCount-- == 1;
        if ( v20 )
          Scaleform::GFx::ASStringNode::ReleaseNode(SlotNameNode);
        if ( (pdestVal.Type & 0x40) != 0 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
            pdestVal.pObjectInterface,
            &pdestVal,
            pdestVal.mValue);
          pdestVal.pObjectInterface = 0i64;
        }
        pdestVal.Type = VT_Undefined;
        Size = v13->VArray.Data.Size;
        if ( v14 < 0 || v14 < Size + v13->FirstOwnSlotNum )
          ++v14;
      }
      while ( (unsigned int)v14 < Size + v13->FirstOwnSlotNum );
    }
  }
  v22 = v5->pTraits.pObject;
  if ( (unsigned int)(v22->TraitsType - 29) < 5 && (v22->Flags & 0x20) == 0 )
  {
    v23 = 0i64;
    if ( (*(_WORD *)(*(_QWORD *)&v5[1].RefCount + 106i64) & 0x200) != 0 )
      v23 = *(_QWORD *)&v5[1].RefCount;
    if ( !v23
      || (v24 = v23 + 4i64 * *(unsigned __int8 *)(v23 + 109),
          v25 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 40i64))(v24),
          v26 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v25 - 72),
          !v25) )
    {
      v26 = 0i64;
    }
    for ( i = 0; i < LODWORD(v26->pDispObj[1].pGeomData); ++i )
    {
      v28 = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildAt(v26, &result, i)->pObject;
      v29 = result.pObject;
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
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v29);
          }
        }
      }
      Scaleform::GFx::DisplayObject::GetName(v28->pDispObj.pObject, &v39);
      value.Flags = 12;
      value.Bonus.pWeakProxy = 0i64;
      value.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v28;
      v28->RefCount = (v28->RefCount + 1) & 0x8FBFFFFF;
      pdestVal.pObjectInterface = 0i64;
      pdestVal.Type = VT_Undefined;
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, &pdestVal);
      visitor->vfptr->Visit(visitor, v39.pNode->pData, &pdestVal);
      if ( (pdestVal.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pdestVal.pObjectInterface->vfptr->gap8[8])(
          pdestVal.pObjectInterface,
          &pdestVal,
          pdestVal.mValue);
        pdestVal.pObjectInterface = 0i64;
      }
      pdestVal.Type = VT_Undefined;
      Flags = value.Flags;
      if ( (value.Flags & 0x1F) > 9 )
      {
        if ( (value.Flags & 0x200) != 0 )
        {
          v20 = value.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          memset(&value.Bonus, 0, 24);
          value.Flags = Flags & 0xFFFFFDE0;
        }
        else
        {
          switch ( value.Flags & 0x1F )
          {
            case 0xA:
              VStr = value.value.VS._1.VStr;
              v20 = value.value.VS._1.VStr->RefCount-- == 1;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(VStr);
              break;
            case 0xB:
            case 0xC:
            case 0xD:
            case 0xE:
            case 0xF:
              if ( !value.value.VS._1.VBool )
              {
                VObj = value.value.VS._1.VObj;
                goto LABEL_76;
              }
              --value.value.VS._1.VStr;
              break;
            case 0x10:
            case 0x11:
              if ( ((__int64)value.value.VS._2.VObj & 1) != 0 )
              {
                --value.value.VS._2.VObj;
              }
              else
              {
                VObj = value.value.VS._2.VObj;
LABEL_76:
                if ( VObj )
                {
                  v34 = VObj->RefCount;
                  if ( (v34 & 0x3FFFFF) != 0 )
                  {
                    VObj->RefCount = v34 - 1;
                    Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(VObj);
                  }
                }
              }
              break;
            default:
              break;
          }
        }
      }
      pNode = v39.pNode;
      v20 = v39.pNode->RefCount-- == 1;
      if ( v20 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 665
// RVA: 0x7F8640
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::IsInstanceOf(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        const char *className)
{
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  unsigned __int64 v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  _QWORD *v7; // rbx
  unsigned __int8 v8; // bl
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr qname; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  qname.pStr = className;
  if ( className )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( className[v5] );
    qname.Size = v5;
  }
  else
  {
    qname.Size = 0i64;
  }
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &qname);
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( !v6 )
    goto LABEL_11;
  v7 = (_QWORD *)pdata[5];
  if ( !v7[17] )
    (*(void (__fastcall **)(_QWORD))(*v7 + 80i64))(pdata[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v7[17] + 40i64),
         v6) )
  {
    v8 = 1;
  }
  else
  {
LABEL_11:
    v8 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return v8;
}

// File Line: 684
// RVA: 0x7F8290
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::IsByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata)
{
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rsi
  _QWORD *v5; // rbx
  unsigned __int8 v6; // bl
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr v11; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11.pStr = "flash.utils.ByteArray";
  v11.Size = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &v11);
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( !v4 )
    goto LABEL_6;
  v5 = (_QWORD *)pdata[5];
  if ( !v5[17] )
    (*(void (__fastcall **)(_QWORD))(*v5 + 80i64))(pdata[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v5[17] + 40i64),
         v4) )
  {
    v6 = 1;
  }
  else
  {
LABEL_6:
    v6 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return v6;
}

// File Line: 704
// RVA: 0x7E6870
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetByteArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata)
{
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rsi
  _QWORD *v5; // rbx
  unsigned int v6; // ebx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr v11; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11.pStr = "flash.utils.ByteArray";
  v11.Size = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &v11);
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( !v4 )
    goto LABEL_6;
  v5 = (_QWORD *)pdata[5];
  if ( !v5[17] )
    (*(void (__fastcall **)(_QWORD))(*v5 + 80i64))(pdata[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v5[17] + 40i64),
         v4) )
  {
    v6 = *((_DWORD *)pdata + 16);
  }
  else
  {
LABEL_6:
    v6 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return v6;
}

// File Line: 721
// RVA: 0x818580
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetByteArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pdata,
        unsigned __int64 setSize)
{
  unsigned int v3; // esi
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v6; // rbp
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *v9; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr v11; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  v3 = setSize;
  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11.pStr = "flash.utils.ByteArray";
  v11.Size = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &v11);
  v6 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( v6 )
  {
    pObject = pdata->pTraits.pObject;
    if ( !pObject->pConstructor.pObject )
      pObject->vfptr[3].~RefCountBaseGC<328>(pdata->pTraits.pObject);
    if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
           (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject->pConstructor.pObject->pTraits.pObject,
           v6) )
    {
      Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::lengthSet(pdata, v3);
    }
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v9 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
  }
}

// File Line: 738
// RVA: 0x80EF50
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::ReadFromByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pdata,
        char *destBuff,
        unsigned __int64 destBuffSz)
{
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v8; // rsi
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  unsigned __int8 v10; // bl
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr v15; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v15.pStr = "flash.utils.ByteArray";
  v15.Size = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &v15);
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( !v8 )
    goto LABEL_6;
  pObject = pdata->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pdata->pTraits.pObject);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject->pConstructor.pObject->pTraits.pObject,
         v8) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Get(pdata, destBuff, destBuffSz);
    v10 = 1;
  }
  else
  {
LABEL_6:
    v10 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v12 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
      }
    }
  }
  return v10;
}

// File Line: 756
// RVA: 0x82A350
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::WriteToByteArray(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *pdata,
        const char *srcBuff,
        unsigned __int64 writeSize)
{
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v8; // rsi
  Scaleform::GFx::AS3::Traits *pObject; // rbx
  unsigned __int8 v10; // bl
  Scaleform::GFx::AS3::GASRefCountBase *v12; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr v15; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v15.pStr = "flash.utils.ByteArray";
  v15.Size = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &v15);
  v8 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( !v8 )
    goto LABEL_6;
  pObject = pdata->pTraits.pObject;
  if ( !pObject->pConstructor.pObject )
    pObject->vfptr[3].~RefCountBaseGC<328>(pdata->pTraits.pObject);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         (Scaleform::GFx::AS3::ClassTraits::Traits *)pObject->pConstructor.pObject->pTraits.pObject,
         v8) )
  {
    Scaleform::GFx::AS3::Instances::fl_utils::ByteArray::Set(pdata, srcBuff, writeSize);
    v10 = 1;
  }
  else
  {
LABEL_6:
    v10 = 0;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  v12 = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v12);
      }
    }
  }
  return v10;
}

// File Line: 774
// RVA: 0x7EEA90
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetRawDataPtr(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata)
{
  Scaleform::GFx::AS3::VM *vfptr; // rbx
  Scaleform::GFx::AS3::ClassTraits::Traits *v4; // rsi
  _QWORD *v5; // rbx
  __int64 v6; // rbx
  Scaleform::GFx::AS3::GASRefCountBase *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::StringDataPtr v11; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::AS3::Multiname mn; // [rsp+38h] [rbp-40h] BYREF

  vfptr = (Scaleform::GFx::AS3::VM *)this->pMovieRoot->pASMovieRoot.pObject[2].vfptr;
  v11.pStr = "flash.utils.ByteArray";
  v11.Size = 21i64;
  Scaleform::GFx::AS3::Multiname::Multiname(&mn, vfptr, &v11);
  v4 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(vfptr, &mn, vfptr->CurrentDomain.pObject);
  if ( !v4 )
    goto LABEL_6;
  v5 = (_QWORD *)pdata[5];
  if ( !v5[17] )
    (*(void (__fastcall **)(_QWORD))(*v5 + 80i64))(pdata[5]);
  if ( Scaleform::GFx::AS3::ClassTraits::Traits::IsOfType(
         *(Scaleform::GFx::AS3::ClassTraits::Traits **)(v5[17] + 40i64),
         v4) )
  {
    v6 = pdata[9];
  }
  else
  {
LABEL_6:
    v6 = 0i64;
  }
  if ( (mn.Name.Flags & 0x1F) > 9 )
  {
    if ( (mn.Name.Flags & 0x200) != 0 )
    {
      if ( mn.Name.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&mn.Name.Bonus, 0, 24);
      mn.Name.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&mn.Name);
    }
  }
  pObject = mn.Obj.pObject;
  if ( mn.Obj.pObject )
  {
    if ( ((__int64)mn.Obj.pObject & 1) != 0 )
    {
      --mn.Obj.pObject;
    }
    else
    {
      RefCount = mn.Obj.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        mn.Obj.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
      }
    }
  }
  return v6;
}

// File Line: 791
// RVA: 0x7E5F60
__int64 __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        unsigned int *pdata)
{
  return pdata[14];
}

// File Line: 799
// RVA: 0x818360
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetArraySize(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int sz)
{
  Scaleform::GFx::AS3::Impl::SparseArray::Resize((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 56), sz);
  return 1;
}

// File Line: 808
// RVA: 0x7E93F0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetElement(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::Value *pval)
{
  unsigned __int64 v5; // rdi
  Scaleform::GFx::AS3::Value *v9; // rax

  v5 = idx;
  if ( (pval->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      pval->mValue);
    pval->pObjectInterface = 0i64;
  }
  pval->Type = VT_Undefined;
  if ( (unsigned int)v5 >= *((_DWORD *)pdata + 14) )
    return 0;
  v9 = Scaleform::GFx::AS3::Impl::SparseArray::At((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 56), v5);
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(
    (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject,
    v9,
    pval);
  return 1;
}

// File Line: 824
// RVA: 0x8198A0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetElement(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // rcx
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+28h] [rbp-30h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &pdestVal);
  Scaleform::GFx::AS3::Impl::SparseArray::Set((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 56), idx, &pdestVal);
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags & 0x200) != 0 )
    {
      if ( pdestVal.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pdestVal.Bonus, 0, 24);
      pdestVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
  return 1;
}

// File Line: 838
// RVA: 0x8299F0
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::VisitElements(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *pdata,
        Scaleform::GFx::Value::ObjectInterface::ArrVisitor *visitor,
        unsigned int idx,
        int count)
{
  unsigned int v5; // r14d
  Scaleform::GFx::AS3::MovieRoot *pObject; // r13
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *pTable; // rcx
  int v10; // eax
  unsigned int v11; // ebp
  unsigned __int64 v12; // rdi
  __int64 v13; // r15
  Scaleform::GFx::AS3::Value *v14; // rdx
  signed __int64 Index; // rax
  __int64 v16; // rdx
  Scaleform::GFx::Value pdestVal; // [rsp+28h] [rbp-60h] BYREF
  unsigned __int64 key; // [rsp+90h] [rbp+8h] BYREF

  v5 = idx;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pTable = pdata[7].pTable;
  if ( idx < (unsigned int)pTable )
  {
    v10 = count;
    if ( count < 0 )
      v10 = (_DWORD)pTable - idx;
    pdestVal.pObjectInterface = 0i64;
    pdestVal.Type = VT_Undefined;
    v11 = idx + v10;
    if ( (unsigned int)pTable < idx + v10 )
      v11 = (unsigned int)pTable;
    if ( idx < v11 )
    {
      v12 = idx;
      v13 = 2i64 * idx;
      do
      {
        key = v12;
        if ( (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)v12 >= pdata[15].pTable )
        {
          if ( (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)v12 < pdata[8].pTable
            || (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> >::TableType *)v12 > pdata[9].pTable
            || (Index = Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::findIndexAlt<unsigned __int64>(
                          pdata + 18,
                          &key),
                Index < 0)
            || (v16 = (__int64)&pdata[18].pTable[2] + 56 * Index) == 0
            || (v14 = (Scaleform::GFx::AS3::Value *)(v16 + 8)) == 0i64 )
          {
            v14 = (Scaleform::GFx::AS3::Value *)&pdata[10];
          }
        }
        else
        {
          v14 = (Scaleform::GFx::AS3::Value *)&pdata[14].pTable[v13];
        }
        Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, v14, &pdestVal);
        visitor->vfptr->Visit(visitor, v5++, (Scaleform::GFx::Value *)((char *)&pdestVal.pVoidPrev + 2));
        ++v12;
        v13 += 2i64;
      }
      while ( v5 < v11 );
    }
    if ( (BYTE2(pdestVal.Type) & 0x40) != 0 )
      (*(void (__fastcall **)(_QWORD, char *, _QWORD))(**(_QWORD **)((char *)&pdestVal.pObjectInterface + 2) + 16i64))(
        *(Scaleform::GFx::Value::ObjectInterface **)((char *)&pdestVal.pObjectInterface + 2),
        (char *)&pdestVal.pVoidPrev + 2,
        *(_QWORD *)((char *)&pdestVal.mValue + 2));
  }
}

// File Line: 862
// RVA: 0x80AB90
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::PushBack(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *value)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // rcx
  __int64 v5; // rcx
  Scaleform::GFx::AS3::Value::VU *v6; // rdx
  Scaleform::GFx::AS3::Value::V1U VObj; // rax
  Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeRef key; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+38h] [rbp-28h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, value, &pdestVal);
  v5 = *((_QWORD *)pdata + 7);
  if ( v5 != *((_QWORD *)pdata + 15) )
  {
    *((_QWORD *)pdata + 9) = v5;
    key.pFirst = (const unsigned __int64 *)(pdata + 72);
    key.pSecond = &pdestVal;
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Set<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64>>::NodeRef>(
      (Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeAltHashF,Scaleform::AllocatorDH<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >,Scaleform::HashNode<unsigned __int64,Scaleform::GFx::AS3::Value,Scaleform::FixedSizeHash<unsigned __int64> >::NodeHashF> > *)pdata
    + 18,
      *((void **)pdata + 19),
      &key);
    goto LABEL_17;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorDH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *)(pdata + 112),
    *((const void **)pdata + 17),
    *((_QWORD *)pdata + 15) + 1i64);
  v6 = (Scaleform::GFx::AS3::Value::VU *)(32i64 * *((_QWORD *)pdata + 15) + *((_QWORD *)pdata + 14) - 32i64);
  if ( v6 )
  {
    v6->VS._1.VInt = pdestVal.Flags;
    v6->VS._2.VObj = (Scaleform::GFx::AS3::Object *)pdestVal.Bonus.pWeakProxy;
    v6[1] = pdestVal.value;
    if ( (pdestVal.Flags & 0x1F) > 9 )
    {
      if ( (pdestVal.Flags & 0x200) != 0 )
      {
        ++pdestVal.Bonus.pWeakProxy->RefCount;
        goto LABEL_17;
      }
      if ( (pdestVal.Flags & 0x1F) == 10 )
      {
        ++pdestVal.value.VS._1.VStr->RefCount;
      }
      else
      {
        if ( (pdestVal.Flags & 0x1F) <= 0xA )
          goto LABEL_17;
        if ( (pdestVal.Flags & 0x1F) <= 0xF )
        {
          VObj = pdestVal.value.VS._1;
        }
        else
        {
          if ( (pdestVal.Flags & 0x1F) > 0x11 )
            goto LABEL_17;
          VObj = (Scaleform::GFx::AS3::Value::V1U)pdestVal.value.VS._2.VObj;
        }
        if ( VObj.VStr )
        {
          ++VObj.VStr->Size;
          VObj.VStr->Size &= 0x8FBFFFFF;
        }
      }
    }
  }
LABEL_17:
  ++*((_QWORD *)pdata + 7);
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags & 0x200) != 0 )
    {
      if ( pdestVal.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pdestVal.Bonus, 0, 24);
      pdestVal.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
  return 1;
}

// File Line: 875
// RVA: 0x807680
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::PopBack(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        Scaleform::GFx::Value *pval)
{
  int v3; // esi
  Scaleform::GFx::AS3::Impl::SparseArray *v4; // rdi
  Scaleform::GFx::AS3::MovieRoot *pObject; // rbp
  Scaleform::GFx::AS3::Value *v8; // rax

  v3 = *((_DWORD *)pdata + 14);
  v4 = (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 56);
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  if ( v3 > 0 )
  {
    if ( pval )
    {
      v8 = Scaleform::GFx::AS3::Impl::SparseArray::At((Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 56), v3 - 1);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, v8, pval);
    }
    Scaleform::GFx::AS3::Impl::SparseArray::Resize(v4, v3 - 1);
    return 1;
  }
  else
  {
    if ( pval )
    {
      if ( (pval->Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
          pval->pObjectInterface,
          pval,
          pval->mValue);
        pval->pObjectInterface = 0i64;
      }
      pval->Type = VT_Undefined;
    }
    return 0;
  }
}

// File Line: 897
// RVA: 0x811880
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::RemoveElements(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        char *pdata,
        unsigned int idx,
        unsigned int count)
{
  unsigned int v4; // eax
  unsigned int v6; // eax

  v4 = *((_DWORD *)pdata + 14);
  if ( idx >= v4 )
    return 0;
  if ( (count & 0x80000000) != 0 )
    count = v4 - idx;
  v6 = v4 - idx;
  if ( v6 < count )
    count = v6;
  Scaleform::GFx::AS3::Impl::SparseArray::CutMultipleAt(
    (Scaleform::GFx::AS3::Impl::SparseArray *)(pdata + 56),
    idx,
    count,
    0i64);
  return 1;
}

// File Line: 910
// RVA: 0x7F1B30
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetWorldMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  __int64 v3; // rcx
  Scaleform::GFx::DisplayObjectBase *v5; // rcx
  float v6; // xmm1_4
  bool result; // al
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmata; // [rsp+20h] [rbp-28h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[11];
  *(_OWORD *)&pmata.M[0][0] = _xmm;
  *(__m128 *)&pmata.M[1][0] = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v5, &pmata);
  v6 = pmata.M[0][1];
  result = 1;
  v8 = pmata.M[0][3];
  v9 = pmata.M[1][3];
  pmat->M[0][0] = pmata.M[0][0];
  v10 = pmata.M[0][2];
  pmat->M[0][1] = v6;
  v11 = pmata.M[1][0];
  pmat->M[0][2] = v10;
  v12 = pmata.M[1][1];
  pmat->M[1][0] = v11;
  v13 = pmata.M[1][2];
  pmat->M[1][1] = v12;
  pmat->M[0][3] = v8 * 0.050000001;
  pmat->M[1][2] = v13;
  pmat->M[1][3] = v9 * 0.050000001;
  return result;
}

// File Line: 926
// RVA: 0x7E9060
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  __int64 v3; // rcx
  __int64 v5; // rax
  float v6; // xmm6_4
  float v7; // xmm4_4
  float v8; // xmm7_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm5_4
  bool result; // al

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v5 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)pdata[11] + 16i64))(pdata[11]);
  v6 = *(float *)(v5 + 20);
  v7 = *(float *)(v5 + 12) * 0.050000001;
  v8 = *(float *)(v5 + 24);
  v9 = *(float *)v5;
  v10 = *(float *)(v5 + 4);
  v11 = *(float *)(v5 + 8);
  v12 = *(float *)(v5 + 16);
  pmat->M[1][3] = *(float *)(v5 + 28) * 0.050000001;
  result = 1;
  pmat->M[1][1] = v6;
  pmat->M[1][2] = v8;
  pmat->M[0][0] = v9;
  pmat->M[0][1] = v10;
  pmat->M[0][2] = v11;
  pmat->M[0][3] = v7;
  pmat->M[1][0] = v12;
  return result;
}

// File Line: 942
// RVA: 0x8196C0
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayMatrix(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  __int64 v3; // rcx
  Scaleform::GFx::DisplayObjectBase *v5; // rdi
  bool result; // al
  int v7; // xmm0_4
  float v8; // xmm2_4
  int v9; // xmm1_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm0_4
  float v14; // xmm4_4
  __m128 v15; // xmm3
  __m128 v16; // xmm2
  __m128d v17; // xmm0
  __m128d v18; // xmm2
  double v19; // xmm1_8
  int v20[8]; // [rsp+20h] [rbp-39h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+40h] [rbp-19h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[11];
  result = Scaleform::Render::Matrix2x4<float>::IsValid(mat);
  if ( result )
  {
    v7 = LODWORD(mat->M[0][0]);
    v8 = mat->M[0][3];
    v20[1] = LODWORD(mat->M[0][1]);
    v9 = LODWORD(mat->M[1][1]);
    v20[0] = v7;
    v10 = LODWORD(mat->M[0][2]);
    v20[5] = v9;
    *(float *)&v11 = mat->M[1][3] * 20.0;
    v20[2] = v10;
    v12 = LODWORD(mat->M[1][0]);
    *(float *)&v20[3] = v8 * 20.0;
    v20[4] = v12;
    v13 = LODWORD(mat->M[1][2]);
    v20[7] = v11;
    v20[6] = v13;
    v5->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
      v5,
      (unsigned int)v20);
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.Rotation = 0.0;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
    v14 = mat->M[1][0];
    v15 = (__m128)LODWORD(mat->M[0][0]);
    v16 = (__m128)LODWORD(mat->M[0][1]);
    geomData.X = (int)mat->M[0][3];
    v17 = _mm_cvtps_pd(v15);
    v18 = _mm_cvtps_pd(v16);
    geomData.Y = (int)mat->M[1][3];
    v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] + v14 * v14;
    v19 = mat->M[1][1] * mat->M[1][1];
    geomData.XScale = _mm_sqrt_pd(v17).m128d_f64[0] * 100.0;
    v18.m128d_f64[0] = v18.m128d_f64[0] * v18.m128d_f64[0] + v19;
    geomData.YScale = _mm_sqrt_pd(v18).m128d_f64[0] * 100.0;
    geomData.Rotation = atan2(v14, v15.m128_f32[0]) * 180.0 * 0.3183098861837907;
    Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &geomData);
    return 1;
  }
  return result;
}

// File Line: 976
// RVA: 0x7EBA80
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetMatrix3D(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  __int64 v3; // rcx
  __int64 v5; // rax
  float v6; // xmm8_4
  float v7; // xmm12_4
  float v8; // xmm4_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm9_4
  float v12; // xmm10_4
  float v13; // xmm11_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  bool result; // al

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v5 = (*(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)pdata[11] + 32i64))(pdata[11]);
  v6 = *(float *)(v5 + 28) * 0.050000001;
  v7 = *(float *)(v5 + 44) * 0.050000001;
  v8 = *(float *)(v5 + 12) * 0.050000001;
  v9 = *(float *)(v5 + 20);
  v10 = *(float *)(v5 + 24);
  v11 = *(float *)(v5 + 32);
  v12 = *(float *)(v5 + 36);
  v13 = *(float *)(v5 + 40);
  v14 = *(float *)v5;
  v15 = *(float *)(v5 + 4);
  v16 = *(float *)(v5 + 8);
  v17 = *(float *)(v5 + 16);
  result = 1;
  pmat->M[0][0] = v14;
  pmat->M[0][1] = v15;
  pmat->M[0][2] = v16;
  pmat->M[0][3] = v8;
  pmat->M[1][0] = v17;
  pmat->M[1][1] = v9;
  pmat->M[1][2] = v10;
  pmat->M[1][3] = v6;
  pmat->M[2][0] = v11;
  pmat->M[2][1] = v12;
  pmat->M[2][2] = v13;
  pmat->M[2][3] = v7;
  return result;
}

// File Line: 992
// RVA: 0x819EF0
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetMatrix3D(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  __int64 v3; // rcx
  Scaleform::GFx::DisplayObjectBase *v5; // rdi
  bool result; // al
  int v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  int v10; // xmm0_4
  int v11; // xmm1_4
  int v12; // xmm0_4
  int v13; // xmm1_4
  int v14; // xmm0_4
  float v15; // xmm1_4
  __m128 v16; // xmm2
  int v17[12]; // [rsp+20h] [rbp-49h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+50h] [rbp-19h] BYREF
  float eX; // [rsp+D8h] [rbp+6Fh] BYREF
  float eY; // [rsp+E8h] [rbp+7Fh] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[11];
  result = Scaleform::Render::Matrix3x4<float>::IsValid(mat);
  if ( result )
  {
    v7 = LODWORD(mat->M[0][1]);
    v8 = mat->M[0][3];
    v9 = mat->M[1][3];
    v17[0] = LODWORD(mat->M[0][0]);
    v17[2] = LODWORD(mat->M[0][2]);
    v10 = LODWORD(mat->M[1][0]);
    v17[1] = v7;
    v11 = LODWORD(mat->M[1][1]);
    v17[4] = v10;
    v17[6] = LODWORD(mat->M[1][2]);
    v12 = LODWORD(mat->M[2][0]);
    v17[5] = v11;
    v13 = LODWORD(mat->M[2][1]);
    v17[8] = v12;
    v14 = LODWORD(mat->M[2][2]);
    v17[9] = v13;
    v15 = mat->M[2][3];
    v17[10] = v14;
    *(float *)&v17[3] = v8 * 20.0;
    *(float *)&v17[7] = v9 * 20.0;
    *(float *)&v17[11] = v15 * 20.0;
    v5->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[5].__vecDelDtor(
      v5,
      (unsigned int)v17);
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.Rotation = 0.0;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
    v16 = (__m128)LODWORD(mat->M[0][2]);
    v16.m128_f32[0] = (float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(mat->M[1][2] * mat->M[1][2]);
    geomData.Z = mat->M[2][3];
    v16.m128_f32[0] = v16.m128_f32[0] + (float)(mat->M[2][2] * mat->M[2][2]);
    geomData.ZScale = _mm_sqrt_ps(v16).m128_f32[0] * 100.0;
    Scaleform::Render::Matrix3x4<float>::GetEulerAngles(mat, &eX, &eY, 0i64);
    geomData.XRotation = eX * 180.0 * 0.3183098861837907;
    geomData.YRotation = eY * 180.0 * 0.3183098861837907;
    Scaleform::GFx::DisplayObjectBase::SetGeomData(v5, &geomData);
    return 1;
  }
  return result;
}

// File Line: 1029
// RVA: 0x7F8570
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::IsDisplayObjectActive(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata)
{
  __int64 v2; // rcx

  v2 = pdata[5];
  return (unsigned int)(*(_DWORD *)(v2 + 120) - 22) < 0xC && (*(_BYTE *)(v2 + 112) & 0x20) == 0 && pdata[11] != 0i64;
}

// File Line: 1038
// RVA: 0x7EDB00
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetParent(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::GFx::Value *pparent)
{
  __int64 v4; // r8
  __int64 v6; // rcx
  __int64 v7; // rcx
  Scaleform::GFx::AS3::MovieRoot *pObject; // r10
  __int64 v9; // rax
  _QWORD *v10; // r9

  v4 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v4 + 120) - 22) >= 0xC )
    return 0;
  if ( (*(_BYTE *)(v4 + 112) & 0x20) != 0 )
    return 0;
  v6 = pdata[11];
  if ( !v6 )
    return 0;
  v7 = *(_QWORD *)(v6 + 56);
  if ( v7 )
  {
    pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
    v9 = *(unsigned __int8 *)(v7 + 109);
    v10 = *(_QWORD **)(v7 + 4 * v9 + 16);
    if ( !v10 )
      v10 = *(_QWORD **)(v7 + 4 * v9 + 8);
    if ( ((unsigned __int8)v10 & 1) != 0 )
      v10 = (_QWORD *)((char *)v10 - 1);
    return Scaleform::GFx::AS3::MovieRoot::CreateObjectValue(
             pObject,
             pparent,
             pObject->pMovieImpl->pObjectInterface,
             v10);
  }
  else
  {
    if ( (pparent->Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion, Scaleform::GFx::AS3ValueObjectInterface *))&pparent->pObjectInterface->vfptr->gap8[8])(
        pparent->pObjectInterface,
        pparent,
        pparent->mValue,
        this);
      pparent->pObjectInterface = 0i64;
    }
    pparent->Type = VT_Null;
    return 1;
  }
}

// File Line: 1062
// RVA: 0x7E8BC0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetDisplayInfo(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  __int64 v3; // rcx
  Scaleform::GFx::TextField *v5; // rdi
  long double Rotation; // xmm7_8
  long double XScale; // xmm8_8
  long double YScale; // xmm9_8
  long double v10; // xmm11_8
  long double v11; // xmm10_8
  long double v12; // xmm6_8
  char v13; // al
  double Z; // xmm0_8
  long double YRotation; // xmm1_8
  long double XRotation; // xmm0_8
  long double ZScale; // xmm0_8
  long double v18; // xmm0_8
  int v19; // xmm0_4
  int v20; // xmm1_4
  int v21; // xmm0_4
  int v22; // xmm1_4
  int v23; // xmm0_4
  int v24; // xmm1_4
  int v25; // xmm0_4
  int v26; // xmm1_4
  int v27; // xmm0_4
  int v28; // xmm1_4
  int v29; // xmm0_4
  int v30; // xmm1_4
  int v31; // xmm0_4
  int v32; // xmm1_4
  int v33; // xmm0_4
  int v34; // xmm1_4
  int v35; // xmm0_4
  int v36; // xmm1_4
  int v37; // xmm0_4
  int v38; // xmm1_4
  int v39; // xmm0_4
  int v40; // xmm1_4
  int v41; // xmm0_4
  int v42; // xmm1_4
  int v43; // xmm0_4
  int v44; // xmm1_4
  int v45; // xmm0_4
  int v46; // xmm1_4
  unsigned __int64 RenderNode; // rax
  unsigned __int64 v48; // rdx
  int v49[12]; // [rsp+20h] [rbp-E0h] BYREF
  int Dst[16]; // [rsp+50h] [rbp-B0h] BYREF
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+90h] [rbp-70h] BYREF

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::TextField *)pdata[11];
  if ( !v5 )
    return 0;
  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::GetGeomData(v5, &geomData);
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v5) == 4 )
  {
    Scaleform::GFx::TextField::GetPosition(v5, pinfo);
  }
  else
  {
    Rotation = geomData.Rotation;
    XScale = geomData.XScale;
    YScale = geomData.YScale;
    v10 = (double)geomData.X * 0.05;
    v11 = (double)geomData.Y * 0.05;
    v12 = (float)(Scaleform::GFx::DisplayObjectBase::GetCxform(v5)->M[0][3] * 100.0);
    v13 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(v5);
    Z = geomData.Z;
    pinfo->Visible = v13;
    pinfo->VarsSet |= 0x7FFu;
    YRotation = geomData.YRotation;
    pinfo->X = v10;
    pinfo->Z = Z * 0.05;
    XRotation = geomData.XRotation;
    pinfo->Y = v11;
    pinfo->XRotation = XRotation;
    ZScale = geomData.ZScale;
    pinfo->Rotation = Rotation;
    pinfo->XScale = XScale;
    pinfo->YScale = YScale;
    pinfo->Alpha = v12;
    pinfo->ZScale = ZScale;
    pinfo->YRotation = YRotation;
  }
  v18 = ((double (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[40].__vecDelDtor)(v5);
  pinfo->VarsSet |= 0x800u;
  pinfo->FOV = v18;
  memset(Dst, 0, sizeof(Dst));
  Dst[0] = 1065353216;
  Dst[5] = 1065353216;
  Dst[10] = 1065353216;
  Dst[15] = 1065353216;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
         v5,
         Dst,
         0i64) )
  {
    v19 = Dst[0];
    v20 = Dst[1];
    pinfo->VarsSet |= 0x1000u;
    LODWORD(pinfo->ProjectionMatrix3D.M[0][0]) = v19;
    v21 = Dst[2];
    LODWORD(pinfo->ProjectionMatrix3D.M[0][1]) = v20;
    v22 = Dst[3];
    LODWORD(pinfo->ProjectionMatrix3D.M[0][2]) = v21;
    v23 = Dst[4];
    LODWORD(pinfo->ProjectionMatrix3D.M[0][3]) = v22;
    v24 = Dst[5];
    LODWORD(pinfo->ProjectionMatrix3D.M[1][0]) = v23;
    v25 = Dst[6];
    LODWORD(pinfo->ProjectionMatrix3D.M[1][1]) = v24;
    v26 = Dst[7];
    LODWORD(pinfo->ProjectionMatrix3D.M[1][2]) = v25;
    v27 = Dst[8];
    LODWORD(pinfo->ProjectionMatrix3D.M[1][3]) = v26;
    v28 = Dst[9];
    LODWORD(pinfo->ProjectionMatrix3D.M[2][0]) = v27;
    v29 = Dst[10];
    LODWORD(pinfo->ProjectionMatrix3D.M[2][1]) = v28;
    v30 = Dst[11];
    LODWORD(pinfo->ProjectionMatrix3D.M[2][2]) = v29;
    v31 = Dst[12];
    LODWORD(pinfo->ProjectionMatrix3D.M[2][3]) = v30;
    v32 = Dst[13];
    LODWORD(pinfo->ProjectionMatrix3D.M[3][0]) = v31;
    v33 = Dst[14];
    LODWORD(pinfo->ProjectionMatrix3D.M[3][1]) = v32;
    v34 = Dst[15];
    LODWORD(pinfo->ProjectionMatrix3D.M[3][2]) = v33;
    LODWORD(pinfo->ProjectionMatrix3D.M[3][3]) = v34;
  }
  memset(v49, 0, sizeof(v49));
  v49[0] = 1065353216;
  v49[5] = 1065353216;
  v49[10] = 1065353216;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, int *, _QWORD))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
         v5,
         v49,
         0i64) )
  {
    v35 = v49[0];
    v36 = v49[1];
    pinfo->VarsSet |= 0x2000u;
    LODWORD(pinfo->ViewMatrix3D.M[0][0]) = v35;
    v37 = v49[2];
    LODWORD(pinfo->ViewMatrix3D.M[0][1]) = v36;
    v38 = v49[3];
    LODWORD(pinfo->ViewMatrix3D.M[0][2]) = v37;
    v39 = v49[4];
    LODWORD(pinfo->ViewMatrix3D.M[0][3]) = v38;
    v40 = v49[5];
    LODWORD(pinfo->ViewMatrix3D.M[1][0]) = v39;
    v41 = v49[6];
    LODWORD(pinfo->ViewMatrix3D.M[1][1]) = v40;
    v42 = v49[7];
    LODWORD(pinfo->ViewMatrix3D.M[1][2]) = v41;
    v43 = v49[8];
    LODWORD(pinfo->ViewMatrix3D.M[1][3]) = v42;
    v44 = v49[9];
    LODWORD(pinfo->ViewMatrix3D.M[2][0]) = v43;
    v45 = v49[10];
    LODWORD(pinfo->ViewMatrix3D.M[2][1]) = v44;
    v46 = v49[11];
    LODWORD(pinfo->ViewMatrix3D.M[2][2]) = v45;
    LODWORD(pinfo->ViewMatrix3D.M[2][3]) = v46;
  }
  RenderNode = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
  v48 = (__int64)((unsigned __int128)((__int64)(RenderNode - (RenderNode & 0xFFFFFFFFFFFFF000ui64) - 56)
                                    * (__int128)0x4924924924924925i64) >> 64) >> 4;
  LODWORD(RenderNode) = *(_WORD *)(*(_QWORD *)(*(_QWORD *)((RenderNode & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                             + 8 * ((unsigned int)v48 + (v48 >> 63))
                                             + 40)
                                 + 10i64) & 0xC;
  pinfo->VarsSet |= 0x4000u;
  pinfo->EdgeAAMode = RenderNode;
  return 1;
}>> 63))
                                             + 40)
                                 + 10i64) 

// File Line: 1108
// RVA: 0x818CC0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetDisplayInfo(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::GFx::Value::DisplayInfo *cinfo)
{
  __int64 v3; // rcx
  Scaleform::GFx::TextField *v5; // rdi
  char v6; // r14
  bool v7; // r12
  Scaleform::Render::EdgeAAMode EdgeAAMode; // ebx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::Cxform *Cxform; // rax
  double v11; // xmm1_8
  float v12; // xmm0_4
  double v13; // xmm8_8
  double v14; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  double ZScale; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v17; // rax
  long double XRotation; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v19; // rbx
  double v20; // xmm0_8
  long double YRotation; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v22; // rbx
  double v23; // xmm0_8
  unsigned __int16 VarsSet; // cx
  long double v25; // xmm0_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v26; // rbx
  char v27; // r14
  __int64 v28; // rax
  float v29; // xmm2_4
  __m128d v30; // xmm0
  float v31; // xmm1_4
  __m128d v32; // xmm11
  __m128d v33; // xmm10
  unsigned __int16 v34; // r15
  __m128 v35; // xmm7
  float v36; // xmm6_4
  __m128 v37; // xmm9
  float v38; // xmm8_4
  long double v39; // xmm0_8
  __m128d v40; // xmm2
  double v41; // xmm7_8
  double v42; // xmm3_8
  double v43; // xmm8_8
  __m128d v44; // xmm1
  double v45; // xmm6_8
  long double Rotation; // xmm0_8
  double v47; // xmm0_8
  double v48; // xmm6_8
  double v49; // xmm1_8
  double v50; // xmm0_8
  double v51; // xmm14_8
  double v52; // xmm0_8
  double v53; // xmm1_8
  int v54; // ecx
  int v55; // eax
  int v56; // ecx
  bool v57; // zf
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  double v59; // xmm11_8
  double v60; // xmm11_8
  double v61; // xmm10_8
  double v62; // xmm10_8
  unsigned __int64 v64; // [rsp+28h] [rbp-C8h]
  double v65; // [rsp+28h] [rbp-C8h]
  unsigned __int64 v66; // [rsp+30h] [rbp-C0h]
  Scaleform::Render::Matrix2x4<float> v67; // [rsp+40h] [rbp-B0h] BYREF
  Scaleform::Render::Cxform v68; // [rsp+60h] [rbp-90h] BYREF
  unsigned __int64 retaddr; // [rsp+148h] [rbp+58h] BYREF
  double v70; // [rsp+158h] [rbp+68h]

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) < 0xC && (*(_BYTE *)(v3 + 112) & 0x20) == 0 )
  {
    v5 = (Scaleform::GFx::TextField *)pdata[11];
    v6 = 0;
    v7 = ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v5) == 4;
    if ( (cinfo->VarsSet & 0x4000) != 0 )
    {
      EdgeAAMode = cinfo->EdgeAAMode;
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v5);
      Scaleform::Render::TreeNode::SetEdgeAAMode(RenderNode, EdgeAAMode);
    }
    if ( (cinfo->VarsSet & 0x20) != 0 )
    {
      retaddr = *(unsigned __int64 *)&cinfo->Alpha;
      if ( (retaddr & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (retaddr & 0xFFFFFFFFFFFFFi64) == 0 )
      {
        Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(v5);
        v11 = cinfo->Alpha * 0.01;
        v68 = *Cxform;
        v12 = v11;
        if ( _mm_shuffle_ps(*(__m128 *)&v68.M[0][0], *(__m128 *)&v68.M[0][0], 255).m128_f32[0] != v12 )
        {
          v68.M[0][3] = v11;
          Scaleform::GFx::DisplayObjectBase::SetCxform(v5, &v68);
          v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
            v5,
            0);
        }
      }
    }
    if ( (cinfo->VarsSet & 0x40) != 0 )
      v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[58].__vecDelDtor(
        v5,
        cinfo->Visible);
    v13 = DOUBLE_20_0;
    if ( SLOBYTE(cinfo->VarsSet) < 0 )
    {
      v14 = cinfo->Z * 20.0;
      *(double *)&retaddr = v14;
      if ( (*(_QWORD *)&v14 & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && (*(_QWORD *)&v14 & 0xFFFFFFFFFFFFFi64) != 0 )
      {
        v14 = 0.0;
      }
      *(double *)&retaddr = v14;
      if ( v14 == -INFINITY || (*(double *)&retaddr = v14, v14 == INFINITY) )
        v14 = 0.0;
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
      pGeomData = v5->pGeomData;
      if ( v14 != pGeomData->Z )
      {
        pGeomData->Z = v14;
        v6 = 1;
      }
    }
    if ( (cinfo->VarsSet & 0x400) != 0 )
    {
      ZScale = cinfo->ZScale;
      *(double *)&retaddr = ZScale;
      if ( (*(_QWORD *)&ZScale & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
        && (*(_QWORD *)&ZScale & 0xFFFFFFFFFFFFFi64) != 0
        || (*(double *)&retaddr = ZScale, ZScale == -INFINITY)
        || (*(double *)&retaddr = ZScale, ZScale == INFINITY) )
      {
        ZScale = DOUBLE_100_0;
      }
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
      v17 = v5->pGeomData;
      if ( ZScale != v17->ZScale )
      {
        v17->ZScale = ZScale;
        v6 = 1;
      }
    }
    if ( (cinfo->VarsSet & 0x100) != 0 )
    {
      XRotation = cinfo->XRotation;
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
      v19 = v5->pGeomData;
      v20 = fmod(XRotation, 360.0);
      if ( v20 <= 180.0 )
      {
        if ( v20 < -180.0 )
          v20 = v20 + 360.0;
      }
      else
      {
        v20 = v20 + -360.0;
      }
      if ( v20 != v19->XRotation )
      {
        v19->XRotation = v20;
        v6 = 1;
      }
    }
    if ( (cinfo->VarsSet & 0x200) == 0 )
      goto LABEL_43;
    YRotation = cinfo->YRotation;
    Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v5);
    v22 = v5->pGeomData;
    v23 = fmod(YRotation, 360.0);
    if ( v23 <= 180.0 )
    {
      if ( v23 < -180.0 )
        v23 = v23 + 360.0;
    }
    else
    {
      v23 = v23 + -360.0;
    }
    if ( v23 == v22->YRotation )
    {
LABEL_43:
      if ( !v6 )
        goto LABEL_45;
    }
    else
    {
      v22->YRotation = v23;
    }
    ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(v5);
LABEL_45:
    VarsSet = cinfo->VarsSet;
    if ( (VarsSet & 0x800) != 0 )
    {
      v25 = fmod(cinfo->FOV, 180.0);
      if ( v25 != ((double (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[40].__vecDelDtor)(v5) )
        ((void (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[39].__vecDelDtor)(v5);
    }
    else
    {
      if ( (VarsSet & 0x1000) != 0 )
        v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[7].__vecDelDtor(
          v5,
          (unsigned int)&cinfo->ProjectionMatrix3D);
      if ( (cinfo->VarsSet & 0x2000) != 0 )
        v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[10].__vecDelDtor(
          v5,
          (unsigned int)&cinfo->ViewMatrix3D);
    }
    if ( (cinfo->VarsSet & 0x1F) == 0 )
      return 1;
    if ( v7 )
    {
      v5->Flags |= 0x2000u;
      Scaleform::GFx::TextField::SetDirtyFlag(v5);
    }
    v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      v5,
      0);
    v26 = v5->pGeomData;
    v27 = 0;
    v28 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v5);
    *(_QWORD *)&v67.M[0][0] = *(_QWORD *)v28;
    v67.M[0][2] = *(float *)(v28 + 8);
    v29 = *(float *)(v28 + 12);
    v67.M[0][3] = v29;
    *(_QWORD *)&v67.M[1][0] = *(_QWORD *)(v28 + 16);
    v30 = (__m128d)*(unsigned int *)(v28 + 24);
    v67.M[1][2] = *(float *)(v28 + 24);
    v31 = *(float *)(v28 + 28);
    v67.M[1][3] = v31;
    if ( v7 && (cinfo->VarsSet & 3) != 0 )
    {
      Scaleform::GFx::TextField::TransformToTextRectSpace(v5, (Scaleform::Render::Point<float> *)&retaddr, cinfo);
      v31 = v67.M[1][3];
      v29 = v67.M[0][3];
      v32 = _mm_cvtps_pd((__m128)(unsigned int)retaddr);
      v33 = _mm_cvtps_pd((__m128)HIDWORD(retaddr));
    }
    else
    {
      if ( (cinfo->VarsSet & 1) != 0 )
        v32 = (__m128d)*(unsigned __int64 *)&cinfo->X;
      else
        v32 = (__m128d)v64;
      if ( (cinfo->VarsSet & 2) != 0 )
        v33 = (__m128d)*(unsigned __int64 *)&cinfo->Y;
      else
        v33 = (__m128d)v66;
    }
    v34 = cinfo->VarsSet;
    if ( (v34 & 0x1C) != 0 )
    {
      v35 = (__m128)LODWORD(v26->OrigMatrix.M[0][0]);
      v36 = v26->OrigMatrix.M[1][0];
      v37 = (__m128)LODWORD(v26->OrigMatrix.M[0][1]);
      v38 = v26->OrigMatrix.M[1][1];
      v68.M[0][2] = v26->OrigMatrix.M[0][2];
      *(_QWORD *)&v68.M[1][2] = __PAIR64__(LODWORD(v31), LODWORD(v26->OrigMatrix.M[1][2]));
      *(_QWORD *)&v68.M[0][0] = __PAIR64__(v37.m128_u32[0], v35.m128_u32[0]);
      *(_QWORD *)&v68.M[1][0] = __PAIR64__(LODWORD(v38), LODWORD(v36));
      v68.M[0][3] = v29;
      v39 = atan2(v36, v35.m128_f32[0]);
      v40 = _mm_cvtps_pd(v35);
      v41 = v26->YScale * 0.01;
      v65 = v39;
      v40.m128d_f64[0] = v40.m128d_f64[0] * v40.m128d_f64[0] + v36 * v36;
      v42 = v38;
      v43 = v26->XScale * 0.01;
      v44 = _mm_cvtps_pd(v37);
      retaddr = *(_OWORD *)&_mm_sqrt_pd(v40);
      v44.m128d_f64[0] = v44.m128d_f64[0] * v44.m128d_f64[0] + v42 * v42;
      v45 = v26->Rotation * 3.141592653589793 * 0.005555555555555556;
      *(_QWORD *)&v70 = *(_OWORD *)&_mm_sqrt_pd(v44);
      if ( (v34 & 4) != 0 )
        Rotation = cinfo->Rotation;
      else
        Rotation = Scaleform::GFx::NumberUtil::NaN();
      if ( (*(_QWORD *)&Rotation & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
        || (*(_QWORD *)&Rotation & 0xFFFFFFFFFFFFFi64) == 0 )
      {
        v47 = fmod(Rotation, 360.0);
        v48 = v47;
        if ( v47 <= 180.0 )
        {
          if ( v47 < -180.0 )
            v48 = v47 + 360.0;
        }
        else
        {
          v48 = v47 + -360.0;
        }
        if ( v48 != v26->Rotation )
        {
          v26->Rotation = v48;
          v27 = 1;
        }
        v45 = v48 * 3.141592653589793 * 0.005555555555555556;
      }
      if ( (cinfo->VarsSet & 8) != 0 )
      {
        v49 = DOUBLE_0_01;
        v50 = cinfo->XScale * 0.01;
      }
      else
      {
        v50 = Scaleform::GFx::NumberUtil::NaN();
        v49 = DOUBLE_0_01;
      }
      v51 = *(double *)&retaddr;
      if ( v50 != v43 && (*(_QWORD *)&v50 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
      {
        v26->XScale = cinfo->XScale;
        if ( *(double *)&retaddr == 0.0 || v50 > 1.0e16 )
        {
          v50 = 0.0;
          v51 = DOUBLE_1_0;
        }
        v43 = v50;
        v27 = 1;
      }
      if ( (cinfo->VarsSet & 0x10) != 0 )
        v52 = cinfo->YScale * v49;
      else
        v52 = Scaleform::GFx::NumberUtil::NaN();
      v53 = v70;
      if ( v52 != v41 )
      {
        *(double *)&retaddr = v52;
        if ( (*(_QWORD *)&v52 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
        {
          v26->YScale = cinfo->YScale;
          if ( v70 == 0.0 || v52 > 1.0e16 )
          {
            v52 = 0.0;
            v53 = DOUBLE_1_0;
          }
          v41 = v52;
          v27 = 1;
        }
      }
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        (Scaleform::Render::Matrix2x4<float> *)&v68,
        v43 / v51,
        v41 / v53,
        v45 - v65);
      v13 = DOUBLE_20_0;
      v67 = (Scaleform::Render::Matrix2x4<float>)v68;
      v30.m128d_f64[1] = *(long double *)&v68.M[1][2];
    }
    if ( (cinfo->VarsSet & 1) != 0 )
      v30 = v32;
    else
      v30.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    retaddr = *(unsigned __int64 *)&v30.m128d_f64[0];
    if ( (*(_QWORD *)&v30.m128d_f64[0] & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
      || (*(_QWORD *)&v30.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      retaddr = *(unsigned __int64 *)&v30.m128d_f64[0];
      if ( *(_QWORD *)&v30.m128d_f64[0] == 0xFFF0000000000000ui64
        || (retaddr = *(unsigned __int64 *)&v30.m128d_f64[0], *(_QWORD *)&v30.m128d_f64[0] == 0x7FF0000000000000i64) )
      {
        v30 = 0i64;
      }
      v30.m128d_f64[0] = v30.m128d_f64[0] * v13;
      v54 = (int)v30.m128d_f64[0];
      if ( (double)v54 != v30.m128d_f64[0] )
        v30.m128d_f64[0] = (double)(v54 - (_mm_movemask_pd(_mm_unpacklo_pd(v30, v30)) & 1));
      v55 = (int)v30.m128d_f64[0];
      v26->X = (int)v30.m128d_f64[0];
      v30 = (__m128d)LODWORD(v67.M[0][3]);
      if ( v67.M[0][3] != (float)v55 )
      {
        v67.M[0][3] = (float)v55;
        v27 = 1;
      }
    }
    if ( (cinfo->VarsSet & 2) != 0 )
      v30 = v33;
    else
      v30.m128d_f64[0] = Scaleform::GFx::NumberUtil::NaN();
    retaddr = *(unsigned __int64 *)&v30.m128d_f64[0];
    if ( (*(_QWORD *)&v30.m128d_f64[0] & 0x7FF0000000000000i64) == 0x7FF0000000000000i64
      && (*(_QWORD *)&v30.m128d_f64[0] & 0xFFFFFFFFFFFFFi64) != 0 )
    {
      goto LABEL_122;
    }
    retaddr = *(unsigned __int64 *)&v30.m128d_f64[0];
    if ( *(_QWORD *)&v30.m128d_f64[0] == 0xFFF0000000000000ui64
      || (retaddr = *(unsigned __int64 *)&v30.m128d_f64[0], *(_QWORD *)&v30.m128d_f64[0] == 0x7FF0000000000000i64) )
    {
      v30 = 0i64;
    }
    v30.m128d_f64[0] = v30.m128d_f64[0] * v13;
    v56 = (int)v30.m128d_f64[0];
    if ( (double)v56 != v30.m128d_f64[0] )
      v30.m128d_f64[0] = (double)(v56 - (_mm_movemask_pd(_mm_unpacklo_pd(v30, v30)) & 1));
    v26->Y = (int)v30.m128d_f64[0];
    if ( v67.M[1][3] == (float)(int)v30.m128d_f64[0] )
    {
LABEL_122:
      if ( !v27 )
      {
LABEL_127:
        if ( v7 )
        {
          if ( (cinfo->VarsSet & 1) != 0 )
          {
            v59 = v32.m128d_f64[0] * v13;
            if ( v59 <= 0.0 )
              v60 = v59 - 0.5;
            else
              v60 = v59 + 0.5;
            v26->X = (int)v60;
          }
          if ( (cinfo->VarsSet & 2) != 0 )
          {
            v61 = v33.m128d_f64[0] * v13;
            if ( v61 <= 0.0 )
              v62 = v61 - 0.5;
            else
              v62 = v61 + 0.5;
            v26->Y = (int)v62;
          }
        }
        return 1;
      }
    }
    else
    {
      v67.M[1][3] = (float)(int)v30.m128d_f64[0];
    }
    if ( Scaleform::Render::Matrix2x4<float>::IsValid(&v67) )
    {
      v57 = !Scaleform::GFx::DisplayObjectBase::Has3D(v5);
      vfptr = v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      if ( v57 )
        vfptr[3].__vecDelDtor(v5, (unsigned int)&v67);
      else
        ((void (__fastcall *)(Scaleform::GFx::TextField *))vfptr[13].__vecDelDtor)(v5);
    }
    goto LABEL_127;
  }
  return 0;
}

// File Line: 1406
// RVA: 0x81EA40
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        const char *ptext,
        bool reqHtml)
{
  __int64 v8; // rdx
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  char v11; // bl
  unsigned int Flags; // eax
  unsigned int v14; // eax
  char v15[16]; // [rsp+38h] [rbp-40h] BYREF
  __int64 v16; // [rsp+48h] [rbp-30h]
  int v17; // [rsp+50h] [rbp-28h]
  const char *v18; // [rsp+58h] [rbp-20h]

  v8 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v8 + 120) - 22) >= 0xC || (*(_BYTE *)(v8 + 112) & 0x20) != 0 )
    return 0;
  v9 = (Scaleform::GFx::TextField *)pdata[11];
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v9->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v9) == 4 )
  {
    Flags = v9->Flags;
    if ( reqHtml )
    {
      if ( (v9->Flags & 2) == 0 )
      {
        v14 = Flags | 2;
LABEL_14:
        v9->Flags = v14;
      }
    }
    else if ( (v9->Flags & 2) != 0 )
    {
      v14 = Flags & 0xFFFFFFFD;
      goto LABEL_14;
    }
    Scaleform::GFx::TextField::SetTextValue(v9, ptext, reqHtml, 1);
    return 1;
  }
  v16 = 0i64;
  v17 = 6;
  v18 = ptext;
  v10 = "text";
  if ( reqHtml )
    v10 = "htmlText";
  v11 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS3ValueObjectInterface *, _QWORD *, const char *, char *, char))&this->vfptr->gap8[32])(
          this,
          pdata,
          v10,
          v15,
          1);
  if ( (v17 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
    v16 = 0i64;
  }
  v17 = 0;
  return v11;
}

// File Line: 1424
// RVA: 0x81EB80
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        const wchar_t *ptext,
        bool reqHtml)
{
  __int64 v8; // rdx
  Scaleform::GFx::TextField *v9; // rbx
  const char *v10; // r8
  char v11; // bl
  char v13[16]; // [rsp+38h] [rbp-40h] BYREF
  __int64 v14; // [rsp+48h] [rbp-30h]
  int v15; // [rsp+50h] [rbp-28h]
  const wchar_t *v16; // [rsp+58h] [rbp-20h]

  v8 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v8 + 120) - 22) >= 0xC || (*(_BYTE *)(v8 + 112) & 0x20) != 0 )
    return 0;
  v9 = (Scaleform::GFx::TextField *)pdata[11];
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v9->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v9) == 4 )
  {
    Scaleform::GFx::TextField::SetText(v9, ptext, reqHtml);
    return 1;
  }
  else
  {
    v14 = 0i64;
    v15 = 7;
    v16 = ptext;
    v10 = "text";
    if ( reqHtml )
      v10 = "htmlText";
    v11 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS3ValueObjectInterface *, _QWORD *, const char *, char *, char))&this->vfptr->gap8[32])(
            this,
            pdata,
            v10,
            v13,
            1);
    if ( (v15 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const wchar_t *))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
      v14 = 0i64;
    }
    v15 = 0;
    return v11;
  }
}

// File Line: 1442
// RVA: 0x7F0240
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetText(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::GFx::Value *pval,
        bool reqHtml)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // r12
  __int64 v9; // rdx
  Scaleform::GFx::TextField *v10; // rbx
  const char *v11; // r8
  Scaleform::GFx::ASString *Html; // rax
  char v14; // di
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int Flags; // edi
  Scaleform::GFx::AS3::Value::V2U v20; // [rsp+48h] [rbp-28h]
  Scaleform::GFx::AS3::Value value; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::GFx::ASString v22; // [rsp+B0h] [rbp+40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B8h] [rbp+48h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v9 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v9 + 120) - 22) >= 0xC || (*(_BYTE *)(v9 + 112) & 0x20) != 0 )
    return 0;
  v10 = (Scaleform::GFx::TextField *)pdata[11];
  if ( ((unsigned int (__fastcall *)(Scaleform::GFx::TextField *))v10->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[81].__vecDelDtor)(v10) == 4 )
  {
    if ( reqHtml )
    {
      Html = Scaleform::GFx::TextField::GetHtml(v10, &result);
      v14 = 1;
    }
    else
    {
      Html = Scaleform::GFx::TextField::GetText(v10, &v22, 0);
      v14 = 2;
    }
    pNode = Html->pNode;
    ++Html->pNode->RefCount;
    if ( (v14 & 2) != 0 )
    {
      v14 &= ~2u;
      v16 = v22.pNode;
      v17 = v22.pNode->RefCount-- == 1;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
    }
    if ( (v14 & 1) != 0 )
    {
      v18 = result.pNode;
      v17 = result.pNode->RefCount-- == 1;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
    value.Flags = 10;
    value.Bonus.pWeakProxy = 0i64;
    value.value.VS._1.VStr = pNode;
    if ( pNode == &pNode->pManager->NullStringNode )
    {
      value.value.VS._1.VStr = 0i64;
      value.value.VS._2 = v20;
      value.Flags = 12;
    }
    else
    {
      ++pNode->RefCount;
    }
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, pval);
    Flags = value.Flags;
    if ( (value.Flags & 0x1F) > 9 )
    {
      if ( (value.Flags & 0x200) != 0 )
      {
        v17 = value.Bonus.pWeakProxy->RefCount-- == 1;
        if ( v17 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        memset(&value.Bonus, 0, 24);
        value.Flags = Flags & 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
      }
    }
    v17 = pNode->RefCount-- == 1;
    if ( v17 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    return 1;
  }
  else
  {
    v11 = "text";
    if ( reqHtml )
      v11 = "htmlText";
    return (*(__int64 (__fastcall **)(Scaleform::GFx::AS3ValueObjectInterface *, _QWORD *, const char *, Scaleform::GFx::Value *, char))&this->vfptr->gap8[24])(
             this,
             pdata,
             v11,
             pval,
             1);
  }
}

// File Line: 1462
// RVA: 0x7F1CE0
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        const char *frame,
        __int64 stop)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  __int64 v5; // rcx
  char v6; // si
  Scaleform::GFx::AS3::MovieRoot *pObject; // rdi
  _WORD *v8; // rbx
  unsigned int v10; // [rsp+30h] [rbp+8h] BYREF

  pMovieRoot = this->pMovieRoot;
  v5 = pdata[5];
  v6 = stop;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  if ( (unsigned int)(*(_DWORD *)(v5 + 120) - 22) >= 0xC || (*(_BYTE *)(v5 + 112) & 0x20) != 0 )
    return 0;
  v8 = (_WORD *)pdata[11];
  if ( (v8[53] & 0x400) == 0 )
    return 0;
  LOBYTE(stop) = 1;
  if ( !(*(unsigned __int8 (__fastcall **)(_WORD *, const char *, unsigned int *, __int64))(*(_QWORD *)v8 + 864i64))(
          v8,
          frame,
          &v10,
          stop) )
    return 0;
  (*(void (__fastcall **)(_WORD *, _QWORD))(*(_QWORD *)v8 + 880i64))(v8, v10);
  (*(void (__fastcall **)(_WORD *, bool))(*(_QWORD *)v8 + 912i64))(v8, v6 != 0);
  Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)pObject->pStage.pObject->FrameCounterObj.pObject);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_Highest);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_High);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_Frame);
  return 1;
}

// File Line: 1492
// RVA: 0x7F1C00
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::GotoAndPlay(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        unsigned int frame,
        bool stop)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS3::MovieRoot *pObject; // rdi
  _WORD *v8; // rbx

  pMovieRoot = this->pMovieRoot;
  v5 = pdata[5];
  pObject = (Scaleform::GFx::AS3::MovieRoot *)pMovieRoot->pASMovieRoot.pObject;
  if ( (unsigned int)(*(_DWORD *)(v5 + 120) - 22) >= 0xC || (*(_BYTE *)(v5 + 112) & 0x20) != 0 )
    return 0;
  v8 = (_WORD *)pdata[11];
  if ( (v8[53] & 0x400) == 0 )
    return 0;
  (*(void (__fastcall **)(_WORD *, _QWORD))(*(_QWORD *)v8 + 880i64))(v8, frame - 1);
  (*(void (__fastcall **)(_WORD *, bool))(*(_QWORD *)v8 + 912i64))(v8, stop);
  Scaleform::GFx::AS3::FrameCounter::QueueFrameActions((Scaleform::GFx::AS3::FrameCounter *)pObject->pStage.pObject->FrameCounterObj.pObject);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_Highest);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_High);
  Scaleform::GFx::AS3::MovieRoot::ExecuteActionQueue(pObject, AL_Frame);
  return 1;
}

// File Line: 1518
// RVA: 0x7E74F0
bool __fastcall Scaleform::GFx::AS3ValueObjectInterface::GetCxform(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        void *pdata,
        Scaleform::Render::Cxform *pcx)
{
  __int64 v3; // rcx
  Scaleform::Render::Cxform *Cxform; // rax
  __int128 v6; // xmm1
  bool result; // al

  v3 = *((_QWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(*((Scaleform::GFx::DisplayObjectBase **)pdata + 11));
  *(_OWORD *)&pcx->M[0][0] = *(_OWORD *)&Cxform->M[0][0];
  v6 = *(_OWORD *)&Cxform->M[1][0];
  result = 1;
  *(_OWORD *)&pcx->M[1][0] = v6;
  return result;
}

// File Line: 1530
// RVA: 0x818C50
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::SetCxform(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::Render::Cxform *cx)
{
  __int64 v3; // rcx
  Scaleform::GFx::DisplayObjectBase *v4; // rbx

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 120) - 22) >= 0xC || (*(_BYTE *)(v3 + 112) & 0x20) != 0 )
    return 0;
  v4 = (Scaleform::GFx::DisplayObjectBase *)pdata[11];
  Scaleform::GFx::DisplayObjectBase::SetCxform(v4, cx);
  v4->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
    v4,
    0);
  return 1;
}

// File Line: 1551
// RVA: 0x7BC660
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::CreateEmptyMovieClip(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::GFx::Value *pmc,
        const char *instanceName,
        int depth)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // rsi
  __int64 v8; // rcx
  __int64 v9; // rbx
  Scaleform::GFx::AS3::Value::V1U v10; // rdi
  const char *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v14; // zf
  __int64 v15; // rcx
  __int64 v16; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v17; // rcx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdx
  char v19; // bl
  Scaleform::GFx::AS3::Value value; // [rsp+48h] [rbp-60h] BYREF
  Scaleform::GFx::AS3::Value v22; // [rsp+68h] [rbp-40h] BYREF
  Scaleform::GFx::ASString v23; // [rsp+B0h] [rbp+8h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v8 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v8 + 120) - 29) >= 5 || (*(_BYTE *)(v8 + 112) & 0x20) != 0 )
    return 0;
  v9 = pdata[11];
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  if ( !Scaleform::GFx::AS3::VM::CreateObject(
          pObject->pAVM.pObject,
          (Scaleform::GFx::AS3::CheckResult *)&v23,
          "flash.display.Sprite",
          pObject->pAVM.pObject->CurrentDomain.pObject,
          &value,
          0,
          0i64)->Result
    || (v10 = value.value.VS._1, v11 = value.value.VS._1.VStr[1].pData,
                                 (unsigned int)(*((_DWORD *)v11 + 30) - 22) >= 0xC)
    || (v11[112] & 0x20) != 0 )
  {
    v19 = 0;
  }
  else
  {
    v22.Flags = 0;
    v22.Bonus.pWeakProxy = 0i64;
    v12 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
            &pObject->BuiltinsMgr,
            &v23,
            instanceName);
    Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(
      (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v10.VStr,
      &v22,
      v12);
    pNode = v23.pNode;
    v14 = v23.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( !v9
      || (v15 = v9 + 4i64 * *(unsigned __int8 *)(v9 + 109),
          v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 40i64))(v15),
          v17 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v16 - 72),
          !v16) )
    {
      v17 = 0i64;
    }
    if ( depth >= 0 )
      LODWORD(pGeomData) = depth;
    else
      pGeomData = v17->pDispObj[1].pGeomData;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
      v17,
      (Scaleform::GFx::DisplayObjContainer *)v10.VStr[2].pManager,
      (unsigned int)pGeomData);
    Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, pmc);
    v19 = 1;
  }
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v14 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v14 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  return v19;
}

// File Line: 1585
// RVA: 0x7B1C80
char __fastcall Scaleform::GFx::AS3ValueObjectInterface::AttachMovie(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _QWORD *pdata,
        Scaleform::GFx::Value *pmc,
        const char *symbolName,
        const char *instanceName,
        int depth,
        Scaleform::GFx::MemberValueSet *initArgs)
{
  const char *v7; // r14
  Scaleform::GFx::Value *v8; // r15
  Scaleform::GFx::AS3::MovieRoot *pObject; // r13
  __int64 v10; // rcx
  __int64 v11; // rbx
  Scaleform::GFx::AS3::VM *v12; // rdi
  __int64 v13; // rcx
  __int64 v14; // rax
  __int64 v15; // r9
  Scaleform::GFx::LogState *v16; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *VStr; // rdi
  const char *v18; // rcx
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *p_BuiltinsMgr; // rsi
  Scaleform::GFx::ASString *String; // rax
  Scaleform::GFx::LogState *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::MemberValueSet *v23; // r12
  unsigned int v24; // r15d
  __int64 v25; // r14
  __int64 v26; // r14
  Scaleform::GFx::AS3::Value::V1U *v27; // rax
  char v28; // di
  Scaleform::GFx::AS3::Value::V1U v29; // rbx
  Scaleform::GFx::AS3::Value::V2U v30; // rdx
  Scaleform::GFx::AS3::GASRefCountBase *v31; // rcx
  int v32; // esi
  const char *v33; // rax
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  Scaleform::GFx::ASStringNode *v37; // rcx
  __int64 v38; // rcx
  __int64 v39; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v40; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdi
  Scaleform::GFx::LogState *v42; // rsi
  char v43; // bl
  Scaleform::GFx::AS3::Value *v45; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::Value v46; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::GFx::AS3::Multiname v49; // [rsp+A0h] [rbp-60h] BYREF
  Scaleform::GFx::DisplayObjContainer **v50; // [rsp+D0h] [rbp-30h]
  Scaleform::GFx::ASString v51; // [rsp+D8h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v52; // [rsp+E0h] [rbp-20h] BYREF
  __int64 v53; // [rsp+E8h] [rbp-18h]
  Scaleform::GFx::AS3::Value::V2U v54; // [rsp+F0h] [rbp-10h]
  __int64 v55; // [rsp+F8h] [rbp-8h]
  Scaleform::GFx::AS3::Value v56; // [rsp+100h] [rbp+0h] BYREF
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [rsp+170h] [rbp+70h] BYREF
  Scaleform::GFx::ASString v58; // [rsp+178h] [rbp+78h] BYREF
  Scaleform::GFx::Value *v59; // [rsp+180h] [rbp+80h]
  const char *v60; // [rsp+188h] [rbp+88h]

  v60 = symbolName;
  v59 = pmc;
  v55 = -2i64;
  v7 = symbolName;
  v8 = pmc;
  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  v10 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v10 + 120) - 29) >= 5 || (*(_BYTE *)(v10 + 112) & 0x20) != 0 )
    return 0;
  v53 = pdata[11];
  v11 = v53;
  value.Flags = 0;
  value.Bonus.pWeakProxy = 0i64;
  v12 = pObject->pAVM.pObject;
  if ( !v53
    || (v13 = v53 + 4i64 * *(unsigned __int8 *)(v53 + 109),
        v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v13 + 40i64))(v13),
        v15 = v14 - 72,
        !v14) )
  {
    v15 = 0i64;
  }
  if ( Scaleform::GFx::AS3::VM::CreateObject(
         v12,
         (Scaleform::GFx::AS3::CheckResult *)&result,
         v7,
         *(Scaleform::GFx::AS3::VMAppDomain **)(v15 + 40),
         &value,
         0,
         0i64)->Result )
  {
    VStr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)value.value.VS._1.VStr;
    v50 = (Scaleform::GFx::DisplayObjContainer **)value.value.VS._1.VStr;
    v18 = value.value.VS._1.VStr[1].pData;
    if ( (unsigned int)(*((_DWORD *)v18 + 30) - 22) < 0xC && (v18[112] & 0x20) == 0 )
    {
      v56.Flags = 0;
      v56.Bonus.pWeakProxy = 0i64;
      p_BuiltinsMgr = &pObject->BuiltinsMgr;
      String = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                 &pObject->BuiltinsMgr,
                 (Scaleform::GFx::ASString *)&result,
                 instanceName);
      Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::nameSet(VStr, &v56, String);
      v21 = result.pObject;
      v22 = LODWORD(result.pObject->vfptr)-- == 1;
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v21);
      v23 = initArgs;
      if ( initArgs )
      {
        v24 = 0;
        if ( initArgs->Data.Size )
        {
          v25 = 0i64;
          do
          {
            v26 = (__int64)&v23->Data.Data[v25];
            v27 = (Scaleform::GFx::AS3::Value::V1U *)Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
                                                       p_BuiltinsMgr,
                                                       &v51,
                                                       (Scaleform::String *)v26);
            v28 = 10;
            v46.Flags = 10;
            v46.Bonus.pWeakProxy = 0i64;
            v29 = *v27;
            v46.value.VS._1 = v29;
            if ( v29.VStr == &v29.VStr->pManager->NullStringNode )
            {
              v29.VStr = 0i64;
              v46.value.VS._1.VStr = 0i64;
              v30.VObj = v54.VObj;
              v46.value.VS._2 = v54;
              v28 = 12;
              v46.Flags = 12;
            }
            else
            {
              ++v29.VStr->RefCount;
              v30.VObj = (Scaleform::GFx::AS3::Object *)v46.value.VS._2;
            }
            v31 = pObject->pAVM.pObject->PublicNamespace.pObject;
            v49.Kind = MN_QName;
            v49.Obj.pObject = v31;
            if ( v31 )
              v31->RefCount = (v31->RefCount + 1) & 0x8FBFFFFF;
            v49.Name.Flags = 0;
            v49.Name.Bonus.pWeakProxy = 0i64;
            v32 = v28 & 0x1F;
            if ( (unsigned int)(v32 - 12) <= 3
              && v29.VStr
              && (v33 = v29.VStr[1].pData, *((_DWORD *)v33 + 30) == 17)
              && (v33[112] & 0x20) == 0 )
            {
              Scaleform::GFx::AS3::Value::Assign(&v49.Name, (Scaleform::GFx::ASString *)&v29.VStr[1].16);
              Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
                (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v49.Obj,
                *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v29.VStr[1].RefCount);
              v49.Kind &= 0xFFFFFFF9;
            }
            else
            {
              _mm_prefetch((const char *)&v46, 2);
              *(_QWORD *)&v49.Name.Flags = *(_QWORD *)&v46.Flags;
              v49.Name.Bonus.pWeakProxy = 0i64;
              v49.Name.value.VS._1 = v29;
              v49.Name.value.VS._2 = v30;
              if ( (v28 & 0x1Fu) > 9 )
              {
                if ( v32 == 10 )
                {
                  ++v29.VStr->RefCount;
                }
                else if ( (v28 & 0x1Fu) <= 0xF )
                {
                  if ( v29.VStr )
                    v29.VStr->Size = (v29.VStr->Size + 1) & 0x8FBFFFFF;
                }
                else if ( (v28 & 0x1Fu) <= 0x11 && v30.VObj )
                {
                  v30.VObj->RefCount = (v30.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
              }
              if ( (v49.Name.Flags & 0x1F) == 10 )
              {
                Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v49.Name, &v58);
                if ( v58.pNode->Size )
                {
                  if ( *v58.pNode->pData == 64 )
                  {
                    v49.Kind |= 8u;
                    v34 = Scaleform::GFx::ASString::Substring(&v58, &v52, 1, v58.pNode->Size);
                    Scaleform::GFx::AS3::Value::Assign(&v49.Name, v34);
                    pNode = v52.pNode;
                    v22 = v52.pNode->RefCount-- == 1;
                    if ( v22 )
                      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
                  }
                }
                v36 = v58.pNode;
                v22 = v58.pNode->RefCount-- == 1;
                if ( v22 )
                  Scaleform::GFx::ASStringNode::ReleaseNode(v36);
              }
            }
            if ( (v28 & 0x1Fu) > 9 )
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v46);
            v37 = v51.pNode;
            v22 = v51.pNode->RefCount-- == 1;
            if ( v22 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v37);
            pdestVal.Flags = 0;
            pdestVal.Bonus.pWeakProxy = 0i64;
            Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, (Scaleform::GFx::Value *)(v26 + 8), &pdestVal);
            ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer **, Scaleform::Ptr<Scaleform::GFx::LogState> *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))(*v50)->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr)(
              v50,
              &result,
              &v49,
              &pdestVal);
            if ( (pdestVal.Flags & 0x1F) > 9 )
            {
              if ( (pdestVal.Flags & 0x200) != 0 )
              {
                v22 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
                if ( v22 )
                  ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
                memset(&pdestVal.Bonus, 0, 24);
                pdestVal.Flags &= 0xFFFFFDE0;
              }
              else
              {
                Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
              }
            }
            Scaleform::GFx::AS3::Multiname::~Multiname(&v49);
            v25 = ++v24;
            p_BuiltinsMgr = &pObject->BuiltinsMgr;
          }
          while ( v24 < v23->Data.Size );
          v11 = v53;
          v7 = v60;
        }
        v8 = v59;
      }
      if ( !v11
        || (v38 = v11 + 4i64 * *(unsigned __int8 *)(v11 + 109),
            v39 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v38 + 40i64))(v38),
            v40 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v39 - 72),
            !v39) )
      {
        v40 = 0i64;
      }
      LODWORD(pGeomData) = depth;
      if ( depth > SLODWORD(v40->pDispObj[1].pGeomData) )
      {
        v42 = Scaleform::GFx::StateBag::GetLogState(&pObject->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
        if ( result.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
        if ( v42 )
        {
          LODWORD(v45) = v40->pDispObj[1].pGeomData;
          Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
            &v42->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
            "DAPI AttachMovie() depth requested (%d) for symbol \"%s\" is too large. Using next highest index (%d) instead.",
            (unsigned int)pGeomData,
            v7,
            v45);
        }
      }
      if ( (int)pGeomData < 0 || (int)pGeomData > SLODWORD(v40->pDispObj[1].pGeomData) )
        pGeomData = v40->pDispObj[1].pGeomData;
      Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(v40, v50[11], (unsigned int)pGeomData);
      Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(pObject, &value, v8);
      v43 = 1;
      goto LABEL_71;
    }
  }
  else
  {
    v16 = Scaleform::GFx::StateBag::GetLogState(&pObject->pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    if ( v16 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptWarning(
        &v16->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "attachMovie() failed - export name \"%s\" is not found.",
        v7);
    v12->HandleException = 0;
  }
  v43 = 0;
LABEL_71:
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v22 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v22 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  return v43;
}

// File Line: 1648
// RVA: 0x826610
void __fastcall Scaleform::GFx::AS3ValueObjectInterface::ToString(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        Scaleform::String *pstr,
        Scaleform::GFx::Value *thisVal)
{
  Scaleform::GFx::AS3::MovieRoot *pObject; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v6; // zf
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value pdestVal; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::AS3::CheckResult v9; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  pObject = (Scaleform::GFx::AS3::MovieRoot *)this->pMovieRoot->pASMovieRoot.pObject;
  pdestVal.Flags = 0;
  pdestVal.Bonus.pWeakProxy = 0i64;
  Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(pObject, thisVal, &pdestVal);
  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
    &pObject->BuiltinsMgr,
    &result);
  Scaleform::GFx::AS3::Value::Convert2String(&pdestVal, &v9, &result);
  Scaleform::String::AssignString(pstr, result.pNode->pData, result.pNode->Size);
  pNode = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Flags = pdestVal.Flags;
  if ( (pdestVal.Flags & 0x1F) > 9 )
  {
    if ( (pdestVal.Flags & 0x200) != 0 )
    {
      v6 = pdestVal.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&pdestVal.Bonus, 0, 24);
      pdestVal.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&pdestVal);
    }
  }
}

// File Line: 1698
// RVA: 0x7BE5A0
char __fastcall Scaleform::GFx::AS3::MovieRoot::CreateObjectValue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pval,
        Scaleform::GFx::Value::ObjectInterface *pobjifc,
        _QWORD *pdata)
{
  __int64 v4; // rcx
  int v7; // edx
  int v9; // edi

  v4 = pdata[5];
  v7 = *(_DWORD *)(v4 + 120);
  v9 = 8;
  if ( (unsigned int)(v7 - 22) >= 0xC || (*(_BYTE *)(v4 + 112) & 0x20) != 0 )
  {
    if ( v7 == 7 )
      v9 = 9;
  }
  else
  {
    v9 = 10;
  }
  if ( (pval->Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval->pObjectInterface->vfptr->gap8[8])(
      pval->pObjectInterface,
      pval,
      pval->mValue);
    pval->pObjectInterface = 0i64;
  }
  pval->mValue.pString = (const char *)pdata;
  pval->pObjectInterface = pobjifc;
  pval->Type = v9 | 0x40;
  (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD *))pobjifc->vfptr->gap8)(
    pobjifc,
    pval,
    pdata);
  return 1;
}

// File Line: 1722
// RVA: 0x7E2F80
void __fastcall Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *gfxVal,
        Scaleform::GFx::AS3::Value *pdestVal)
{
  Scaleform::GFx::Value::ValueType Type; // r8d
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rdi
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::AS3::Instances::Function *pString; // rdx
  Scaleform::GFx::AS3::Traits *pObject; // rax
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rcx
  int DataAux; // eax
  unsigned __int64 v16; // rax
  unsigned int Flags; // ebx
  Scaleform::GFx::ASString v18; // [rsp+20h] [rbp-30h] BYREF
  __int64 v19; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::AS3::Value other; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+18h] BYREF
  Scaleform::GFx::ASString v; // [rsp+78h] [rbp+28h] BYREF

  v19 = -2i64;
  Type = gfxVal->Type;
  switch ( Type & 0x8F )
  {
    case 0:
      Scaleform::GFx::AS3::Value::SetUndefined(pdestVal);
      break;
    case 1:
      Scaleform::GFx::AS3::Value::SetNull(pdestVal);
      break;
    case 2:
      Scaleform::GFx::AS3::Value::SetBool(pdestVal, gfxVal->mValue.BValue);
      break;
    case 3:
      Scaleform::GFx::AS3::Value::SetSInt32(pdestVal, gfxVal->mValue.IValue);
      break;
    case 4:
      Scaleform::GFx::AS3::Value::SetUInt32(pdestVal, gfxVal->mValue.UIValue);
      break;
    case 5:
      Scaleform::GFx::AS3::Value::SetNumber(pdestVal, gfxVal->mValue.NValue);
      break;
    case 6:
      if ( (Type & 0x40) != 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(pdestVal, (Scaleform::GFx::ASStringNode *)gfxVal->mValue.pString);
      }
      else
      {
        v5 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               &this->BuiltinsMgr,
               &result,
               gfxVal->mValue.pString);
        Scaleform::GFx::AS3::Value::Assign(pdestVal, v5);
        pNode = result.pNode;
        v7 = result.pNode->RefCount-- == 1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      }
      break;
    case 7:
      if ( (Type & 0x40) != 0 )
      {
        v8 = (Scaleform::GFx::ASStringNode *)*((_QWORD *)gfxVal->mValue.pString - 1);
        v.pNode = v8;
        ++v8->RefCount;
        Scaleform::GFx::AS3::Value::Assign(pdestVal, &v);
        v7 = v8->RefCount-- == 1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      }
      else
      {
        v9 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
               &this->BuiltinsMgr,
               &v18,
               gfxVal->mValue.pStringW,
               -1i64);
        Scaleform::GFx::AS3::Value::Assign(pdestVal, v9);
        v10 = v18.pNode;
        v7 = v18.pNode->RefCount-- == 1;
        if ( v7 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      }
      break;
    case 8:
    case 9:
    case 0xA:
      pString = (Scaleform::GFx::AS3::Instances::Function *)gfxVal->mValue.pString;
      if ( pString
        && (pObject = pString->pTraits.pObject, pObject->TraitsType == Traits_Function)
        && (pObject->Flags & 0x20) == 0 )
      {
        Scaleform::GFx::AS3::Value::Assign(pdestVal, pString);
      }
      else
      {
        Scaleform::GFx::AS3::Value::Assign(pdestVal, pString);
      }
      break;
    case 0xB:
      v13 = (unsigned __int64)gfxVal->mValue.pString >> 1;
      v14 = (unsigned __int64)gfxVal->mValue.pString & 0xFFFFFFFFFFFFFFFDui64;
      other.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v14;
      other.Bonus.pWeakProxy = 0i64;
      if ( (v13 & 1) != 0 )
      {
        DataAux = gfxVal->DataAux;
        other.Flags = 17;
        other.value.VS._1.VInt = DataAux;
        if ( v14 )
          *(_DWORD *)(v14 + 32) = (*(_DWORD *)(v14 + 32) + 1) & 0x8FBFFFFF;
        other.Flags = 17;
        Scaleform::GFx::AS3::Value::Assign(pdestVal, &other);
      }
      else
      {
        v16 = gfxVal->DataAux;
        other.Flags = 16;
        other.value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)v16;
        if ( v14 )
          *(_DWORD *)(v14 + 32) = (*(_DWORD *)(v14 + 32) + 1) & 0x8FBFFFFF;
        Scaleform::GFx::AS3::Value::Assign(pdestVal, &other);
      }
      Flags = other.Flags;
      if ( (other.Flags & 0x1F) > 9 )
      {
        if ( (other.Flags & 0x200) != 0 )
        {
          v7 = other.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v7 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          other.Flags = Flags & 0xFFFFFDE0;
          memset(&other.Bonus, 0, 24);
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
        }
      }
      break;
    default:
      return;
  }
}

// File Line: 1807
// RVA: 0x7A9350
Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue

// File Line: 1976
// RVA: 0x7BE530
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateObjectInterface(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieImpl *movie)
{
  Scaleform::GFx::Value::ObjectInterface *v3; // rax

  v3 = (Scaleform::GFx::Value::ObjectInterface *)((__int64 (__fastcall *)(Scaleform::GFx::AS3::MovieRoot *, __int64))this->pMovieImpl->pHeap->vfptr->Alloc)(
                                                   this,
                                                   32i64);
  if ( v3 )
  {
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::Value::ObjectInterface::`vftable;
    v3->pMovieRoot = movie;
    v3->ExternalObjRefs.Root.pPrev = (Scaleform::GFx::Value *)&v3->ExternalObjRefs;
    v3->ExternalObjRefs.Root.pNext = (Scaleform::GFx::Value *)&v3->ExternalObjRefs;
    v3->vfptr = (Scaleform::GFx::Value::ObjectInterfaceVtbl *)&Scaleform::GFx::AS3ValueObjectInterface::`vftable;
    movie->pObjectInterface = v3;
  }
  else
  {
    movie->pObjectInterface = 0i64;
  }
}

// File Line: 1983
// RVA: 0x7BF6C0
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateString(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const char *pstring)
{
  unsigned int Flags; // ebx
  bool v6; // zf
  __int64 v7; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString retaddr; // [rsp+58h] [rbp+0h] BYREF
  Scaleform::GFx::ASStringNode *result; // [rsp+60h] [rbp+8h]

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    &this->BuiltinsMgr,
    &retaddr,
    pstring);
  LODWORD(v7) = 10;
  *(_QWORD *)&value.Flags = 0i64;
  value.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)retaddr.pNode;
  if ( retaddr.pNode == &retaddr.pNode->pManager->NullStringNode )
  {
    value.Bonus.pWeakProxy = 0i64;
    value.value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)&value.Flags;
    LODWORD(v7) = 12;
  }
  else
  {
    ++retaddr.pNode->RefCount;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, (Scaleform::GFx::AS3::Value *)&v7, pvalue);
  Flags = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v6 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  v6 = result->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(result);
}

// File Line: 1989
// RVA: 0x7BF830
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateStringW(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const wchar_t *pstring)
{
  unsigned int Flags; // ebx
  bool v6; // zf
  __int64 v7; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::AS3::Value value; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString retaddr; // [rsp+58h] [rbp+0h] BYREF
  Scaleform::GFx::ASStringNode *result; // [rsp+60h] [rbp+8h]

  Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateString(
    &this->BuiltinsMgr,
    &retaddr,
    pstring,
    -1i64);
  LODWORD(v7) = 10;
  *(_QWORD *)&value.Flags = 0i64;
  value.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)retaddr.pNode;
  if ( retaddr.pNode == &retaddr.pNode->pManager->NullStringNode )
  {
    value.Bonus.pWeakProxy = 0i64;
    value.value.VS._1.VStr = *(Scaleform::GFx::ASStringNode **)&value.Flags;
    LODWORD(v7) = 12;
  }
  else
  {
    ++retaddr.pNode->RefCount;
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, (Scaleform::GFx::AS3::Value *)&v7, pvalue);
  Flags = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      v6 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v6 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  v6 = result->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(result);
}

// File Line: 1996
// RVA: 0x7BE130
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateObject(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        const char *className,
        Scaleform::GFx::Value *pargs,
        unsigned int nargs)
{
  Scaleform::GFx::Value *v7; // rsi
  Scaleform::GFx::AS3::Value *v9; // r12
  Scaleform::GFx::AS3::Value *v10; // rbx
  __int64 v11; // rsi
  Scaleform::GFx::AS3::Value *v12; // r8
  Scaleform::GFx::AS3::ASVM *pObject; // r10
  Scaleform::GFx::AS3::VMAppDomain *v14; // r8
  const char *v15; // rdx
  bool v16; // al
  Scaleform::GFx::AS3::ASVM *v17; // rcx
  Scaleform::GFx::AS3::ASVM *v18; // rcx
  Scaleform::GFx::AS3::Value *p_ExceptionObj; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  bool v21; // zf
  Scaleform::GFx::AS3::Value *v22; // rbx
  __int64 v23; // rdi
  Scaleform::GFx::AS3::WeakProxy *v24; // rdx
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v26; // rcx
  unsigned int RefCount; // eax
  _BYTE v28[6]; // [rsp+3Eh] [rbp-C2h] BYREF
  _TBYTE result_6; // [rsp+46h] [rbp-BAh]
  _BYTE result_16[22]; // [rsp+50h] [rbp-B0h]
  __int16 v31; // [rsp+6Eh] [rbp-92h] BYREF
  _TBYTE v32; // [rsp+2E6h] [rbp+1E6h]

  *(_QWORD *)&v32 = pvalue;
  *(_QWORD *)&result_16[14] = -2i64;
  v7 = pvalue;
  if ( nargs <= 0xA )
    v9 = (Scaleform::GFx::AS3::Value *)&v31;
  else
    v9 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         32i64 * nargs,
                                         0i64);
  if ( nargs )
  {
    v10 = v9;
    v11 = nargs;
    do
    {
      if ( v10 )
      {
        v10->Flags = 0;
        v10->Bonus.pWeakProxy = 0i64;
        v12 = v10;
      }
      else
      {
        v12 = 0i64;
      }
      Scaleform::GFx::AS3::MovieRoot::GFxValue2ASValue(this, pargs++, v12);
      ++v10;
      --v11;
    }
    while ( v11 );
    v7 = *(Scaleform::GFx::Value **)((char *)&v32 + 2);
  }
  *(_DWORD *)v28 = 0;
  *(_QWORD *)&result_6 = 0i64;
  pObject = this->pAVM.pObject;
  if ( pObject->CallStack.Size && Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v14 = pObject->CallStack.Pages[(pObject->CallStack.Size - 1) >> 6][(LODWORD(pObject->CallStack.Size) - 1) & 0x3F].pFile->AppDomain.pObject;
  else
    v14 = pObject->CurrentDomain.pObject;
  v15 = "Object";
  if ( className )
    v15 = className;
  v16 = Scaleform::GFx::AS3::VM::Construct(pObject, v15, v14, (Scaleform::GFx::AS3::Value *)v28, nargs, v9, 0);
  v17 = this->pAVM.pObject;
  if ( v17->HandleException )
  {
    printf("Exception in CreateObject(\"%s\"):\n\t", className);
    v18 = this->pAVM.pObject;
    v18->HandleException = 0;
    p_ExceptionObj = &v18->ExceptionObj;
    Scaleform::GFx::AS3::VM::OutputError(v18, &v18->ExceptionObj);
    if ( (p_ExceptionObj->Flags & 0x1F) > 9 )
    {
      if ( (p_ExceptionObj->Flags & 0x200) != 0 )
      {
        pWeakProxy = p_ExceptionObj->Bonus.pWeakProxy;
        v21 = pWeakProxy->RefCount-- == 1;
        if ( v21 )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        p_ExceptionObj->Bonus.pWeakProxy = 0i64;
        p_ExceptionObj->value.VS._1.VStr = 0i64;
        p_ExceptionObj->value.VS._2.VObj = 0i64;
        p_ExceptionObj->Flags &= 0xFFFFFDE0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(p_ExceptionObj);
      }
    }
    p_ExceptionObj->Flags &= 0xFFFFFFE0;
  }
  else if ( v16 )
  {
    Scaleform::GFx::AS3::VM::ExecuteCode(v17, 1u);
  }
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, (Scaleform::GFx::AS3::Value *)v28, v7);
  if ( nargs )
  {
    v22 = v9;
    v23 = nargs;
    do
    {
      if ( (v22->Flags & 0x1F) > 9 )
      {
        if ( (v22->Flags & 0x200) != 0 )
        {
          v24 = v22->Bonus.pWeakProxy;
          v21 = v24->RefCount-- == 1;
          if ( v21 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          v22->Bonus.pWeakProxy = 0i64;
          v22->value.VS._1.VStr = 0i64;
          v22->value.VS._2.VObj = 0i64;
          v22->Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v22);
        }
      }
      ++v22;
      --v23;
    }
    while ( v23 );
  }
  if ( nargs > 0xA )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
  if ( (v28[2] & 0x1Fu) > 9 )
  {
    if ( (*(_WORD *)&v28[2] & 0x200) != 0 )
    {
      v21 = (**(_DWORD **)((char *)&result_6 + 2))-- == 1;
      if ( v21 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      *(_QWORD *)((char *)&result_6 + 2) = 0i64;
      *(_OWORD *)result_16 = 0ui64;
      *(_DWORD *)&v28[2] &= 0xFFFFFDE0;
    }
    else
    {
      switch ( v28[2] & 0x1F )
      {
        case 0xA:
          v25 = *(Scaleform::GFx::ASStringNode **)result_16;
          v21 = (*(_DWORD *)(*(_QWORD *)result_16 + 24i64))-- == 1;
          if ( v21 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v25);
          break;
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
          v26 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)result_16;
          if ( (result_16[0] & 1) == 0 )
            goto LABEL_50;
          --*(_QWORD *)result_16;
          break;
        case 0x10:
        case 0x11:
          v26 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)&result_16[8];
          if ( (result_16[8] & 1) != 0 )
          {
            --*(_QWORD *)&result_16[8];
          }
          else
          {
LABEL_50:
            if ( v26 )
            {
              RefCount = v26->RefCount;
              if ( (RefCount & 0x3FFFFF) != 0 )
              {
                v26->RefCount = RefCount - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v26);
              }
            }
          }
          break;
        default:
          return;
      }
    }
  }
}

// File Line: 2034
// RVA: 0x7BB910
// local variable allocation has failed, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateArray(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue)
{
  int v4; // ebx
  _BYTE v6[6]; // [rsp+26h] [rbp-32h] BYREF
  _QWORD value_6[5]; // [rsp+2Eh] [rbp-2Ah] BYREF
  void *retaddr; // [rsp+58h] [rbp+0h] OVERLAPPED BYREF

  Scaleform::GFx::AS3::InstanceTraits::fl::Array::MakeInstance(
    (Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *)((char *)&retaddr + 6),
    (Scaleform::GFx::AS3::InstanceTraits::fl::Array *)this->pAVM.pObject->TraitsArray.pObject->ITraits.pObject);
  value_6[0] = 0i64;
  *(_DWORD *)v6 = 12;
  *(_OWORD *)&value_6[1] = *(unsigned __int64 *)((char *)&retaddr + 6);
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, (Scaleform::GFx::AS3::Value *)v6, pvalue);
  v4 = *(_DWORD *)&v6[2];
  if ( (v6[2] & 0x1Fu) > 9 )
  {
    if ( (*(_WORD *)&v6[2] & 0x200) != 0 )
    {
      if ( (**(_DWORD **)((char *)value_6 + 2))-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset((char *)value_6 + 2, 0, 24);
      *(_DWORD *)&v6[2] = v4 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&v6[2]);
    }
  }
}

// File Line: 2042
// RVA: 0x7BCD90
void __fastcall Scaleform::GFx::AS3::MovieRoot::CreateFunction(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        Scaleform::GFx::Resource *pfc,
        void *puserData)
{
  Scaleform::GFx::AS3::UserDefinedFunction *v8; // rax
  unsigned __int64 v9; // rax
  unsigned int Flags; // ebx
  Scaleform::GFx::AS3::Value value; // [rsp+28h] [rbp-40h] BYREF

  v8 = (Scaleform::GFx::AS3::UserDefinedFunction *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *const, __int64))this->pAVM.pObject->MHeap->vfptr->Alloc)(
                                                     this->pAVM.pObject->MHeap,
                                                     80i64);
  *(_QWORD *)&value.Flags = v8;
  if ( v8 )
    Scaleform::GFx::AS3::UserDefinedFunction::UserDefinedFunction(
      v8,
      this->pAVM.pObject->TraitsFunction.pObject->ITraits.pObject,
      pfc,
      puserData);
  else
    v9 = 0i64;
  value.Bonus.pWeakProxy = 0i64;
  value.Flags = 14;
  value.value = (Scaleform::GFx::AS3::Value::VU)v9;
  Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(this, &value, pvalue);
  Flags = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags & 0x200) != 0 )
    {
      if ( value.Bonus.pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      memset(&value.Bonus, 0, 24);
      value.Flags = Flags & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
}

