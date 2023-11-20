// File Line: 38
// RVA: 0x77B070
void __fastcall Scaleform::GFx::AS3::AvmSprite::AvmSprite(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::AS3::AvmSprite *v2; // rsi
  Scaleform::GFx::AvmDisplayObjContainerBase *v3; // rdx
  Scaleform::GFx::AvmSpriteBase *v4; // rax
  int v5; // eax
  signed __int64 v6; // rdi
  unsigned int v7; // ebx
  void *v8; // rax
  Scaleform::GFx::AvmSpriteBase *v9; // [rsp+60h] [rbp+18h]
  __int64 v10; // [rsp+68h] [rbp+20h]

  v2 = this;
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&psprite->vfptr);
  v3 = (Scaleform::GFx::AvmDisplayObjContainerBase *)&v2->vfptr;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable;
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable;
  v4 = (Scaleform::GFx::AvmSpriteBase *)&v2->vfptr;
  v9 = v4;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjContainerBase::`vftable;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmSpriteBase::`vftable;
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObjContainer};
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AvmSpriteBase};
  v5 = (*(__int64 (__cdecl **)(Scaleform::GFx::DisplayObject::ScrollRectInfo *))(*(_QWORD *)&v2->pDispObj[1].pScrollRect->Rectangle.x1
                                                                               + 80i64))(v2->pDispObj[1].pScrollRect);
  v6 = (signed __int64)&v2->InitActionsExecuted;
  v10 = v6;
  *(_DWORD *)(v6 + 8) = v5;
  v7 = (unsigned int)(v5 + 7) >> 3;
  LODWORD(v9) = 323;
  v8 = (void *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::FixedBitSetLH<323> *, _QWORD, Scaleform::GFx::AvmSpriteBase **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                 Scaleform::Memory::pGlobalHeap,
                 &v2->InitActionsExecuted,
                 v7,
                 &v9,
                 -2i64);
  *(_QWORD *)v6 = v8;
  memset(v8, 0, v7);
  v2->Flags = 0;
  LOBYTE(v2->pDispObj[2].vfptr) &= 0xDFu;
}

// File Line: 44
// RVA: 0x789A00
void __fastcall Scaleform::GFx::AS3::AvmSprite::~AvmSprite(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::AvmSprite *v1; // rdi
  Scaleform::GFx::AvmSpriteBase *v2; // rbx

  v1 = this;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObjContainer};
  v2 = (Scaleform::GFx::AvmSpriteBase *)&this->vfptr;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmSprite::`vftable{for `Scaleform::GFx::AvmSpriteBase};
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->InitActionsExecuted.pData);
  v2->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  Scaleform::GFx::AS3::AvmDisplayObjContainer::~AvmDisplayObjContainer((Scaleform::GFx::AS3::AvmDisplayObjContainer *)&v1->vfptr);
}

// File Line: 49
// RVA: 0x7F87A0
_BOOL8 __fastcall Scaleform::GFx::AS3::AvmSprite::IsLevelMovie(Scaleform::GFx::AS3::AvmSprite *this)
{
  return this->pDispObj->pParent == 0i64;
}

// File Line: 54
// RVA: 0x7D7680
void __fastcall Scaleform::GFx::AS3::AvmSprite::ForceShutdown(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::AvmSprite *v1; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *v5; // rcx
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = this;
  v2 = this->pAS3CollectiblePtr.pObject;
  if ( v2 )
  {
    if ( (unsigned __int8)v2 & 1 )
    {
      v1->pAS3CollectiblePtr.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v2 - 1);
    }
    else
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v2->vfptr);
      }
    }
    v1->pAS3CollectiblePtr.pObject = 0i64;
  }
  v1->pAS3RawPtr = 0i64;
  v4 = v1->pAS3CollectiblePtr.pObject;
  if ( v4 )
  {
    if ( (unsigned __int8)v4 & 1 )
      v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
    if ( v4 )
      v4->RefCount = (v4->RefCount + 1) & 0x8FBFFFFF;
    v5 = v4->pLoaderInfo.pObject;
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v4->pLoaderInfo.pObject = (Scaleform::GFx::AS3::Instances::fl_display::LoaderInfo *)((char *)v5 - 1);
      }
      else
      {
        v6 = v5->RefCount;
        if ( v6 & 0x3FFFFF )
        {
          v5->RefCount = v6 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
      v4->pLoaderInfo.pObject = 0i64;
    }
    if ( !((unsigned __int8)v4 & 1) )
    {
      v7 = v4->RefCount;
      if ( v7 & 0x3FFFFF )
      {
        v4->RefCount = v7 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v4->vfptr);
      }
    }
  }
}

// File Line: 68
// RVA: 0x801F80
char __fastcall Scaleform::GFx::AS3::AvmSprite::MustBeInPlaylist(Scaleform::GFx::AS3::AvmSprite *this)
{
  const char *v1; // rax
  char result; // al
  __int64 v3; // [rsp+20h] [rbp-28h]
  int v4; // [rsp+28h] [rbp-20h]
  char v5; // [rsp+2Ch] [rbp-1Ch]
  int v6; // [rsp+30h] [rbp-18h]

  if ( (_QWORD)this->pDispObj & 2
    || (v1 = this[-1].pClassName,
        v3 = 2i64,
        v4 = 0,
        v5 = 0,
        v6 = 65280,
        (result = (*((__int64 (__fastcall **)(const char **, __int64 *))v1 + 7))(&this[-1].pClassName, &v3)) != 0) )
  {
    result = 1;
  }
  return result;
}

// File Line: 73
// RVA: 0x7BC570
void __fastcall Scaleform::GFx::AS3::AvmSprite::CreateChildren(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::AvmSprite *v1; // rdi
  Scaleform::GFx::Sprite *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::GFx::AS3::AvmInteractiveObj *v4; // rax
  __int64 v5; // rdx
  unsigned __int8 v6; // al
  __int64 v7; // rax

  v1 = this;
  if ( !(this->Flags & 4) )
  {
    v2 = (Scaleform::GFx::Sprite *)this->pDispObj;
    if ( !Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)this->pDispObj) )
    {
      v3 = v2->pParent;
      if ( v3 )
      {
        if ( Scaleform::GFx::InteractiveObject::IsInPlayList(v3) )
        {
          if ( v2->pParent )
          {
            v4 = Scaleform::GFx::AS3::AvmDisplayObj::GetAvmParent((Scaleform::GFx::AS3::AvmDisplayObj *)&v1->vfptr);
            Scaleform::GFx::AS3::AvmInteractiveObj::InsertChildToPlayList(
              v4,
              (Scaleform::GFx::InteractiveObject *)&v2->vfptr);
          }
          else
          {
            Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
          }
          Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(
            (Scaleform::GFx::InteractiveObject *)&v2->vfptr,
            v5);
        }
      }
    }
    if ( !(v2->Flags & 8) )
      Scaleform::GFx::Sprite::DefaultOnEventLoad(v2);
    v6 = v2->AvmObjOffset;
    if ( v6 )
    {
      v7 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr + 4 * v6))[2].__vecDelDtor)((signed __int64)v2 + 4 * v6);
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 224i64))(v7, 0i64);
    }
    v1->Flags |= 4u;
  }
}

// File Line: 135
// RVA: 0x7ABB00
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS3::AvmSprite::AddDisplayObject(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::ASString *name, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *__formal)
{
  Scaleform::GFx::CharPosInfo *v4; // r15
  Scaleform::GFx::AS3::AvmSprite *v5; // r13
  Scaleform::GFx::MovieDefImpl *v6; // rsi
  signed __int64 v7; // rdi
  Scaleform::GFx::AvmDisplayObjBaseVtbl **v8; // rax
  unsigned __int64 v9; // rdx
  Scaleform::GFx::AS3::Value::V2U v10; // rcx
  bool v11; // r14
  int v12; // eax
  Scaleform::GFx::DisplayObjContainer *v14; // r14
  Scaleform::GFx::DisplayObjectBase *v15; // rsi
  int v16; // er12
  __int64 v17; // rdx
  Scaleform::GFx::ASStringNode *v18; // rbx
  Scaleform::GFx::ASStringNode *v19; // r14
  bool v20; // zf
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::Render::Cxform *v22; // rax
  Scaleform::GFx::AS3::AvmDisplayObj *v23; // r15
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v24; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v25; // r12
  unsigned int v26; // esi
  Scaleform::GFx::ASStringNode *v27; // r14
  Scaleform::GFx::AS3::Value::V2U v28; // rdx
  long double v29; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v30; // rcx
  int v31; // er15
  const char *v32; // rax
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASStringNode *v36; // rcx
  char v37; // si
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v38; // rdx
  __int64 v39; // rcx
  __int64 v40; // rax
  __int64 v41; // r14
  __int16 v42; // dx
  Scaleform::GFx::Sprite *v43; // r12
  Scaleform::GFx::DisplayObjectBase *i; // rbx
  Scaleform::Render::Rect<float> *v45; // rax
  unsigned int v46; // ebx
  unsigned int v47; // ST20_4
  Scaleform::GFx::Sprite *v48; // rbx
  Scaleform::GFx::AS3::AvmDisplayObj *v49; // rax
  Scaleform::GFx::AS3::AvmDisplayObj *v50; // rbx
  unsigned int v51; // esi
  Scaleform::GFx::ASStringNode *v52; // r15
  Scaleform::GFx::AS3::Value::V2U v53; // rdx
  Scaleform::GFx::AS3::VMAppDomain *v54; // rbx
  long double v55; // rax
  Scaleform::GFx::AS3::GASRefCountBase *v56; // rcx
  int v57; // er13
  const char *v58; // rax
  Scaleform::GFx::ASString *v59; // rax
  Scaleform::GFx::ASStringNode *v60; // rcx
  Scaleform::GFx::ASStringNode *v61; // rcx
  Scaleform::GFx::AvmTextFieldBase *(__fastcall *v62)(Scaleform::GFx::AvmDisplayObjBase *); // rcx
  char v63; // al
  __int64 v64; // rax
  __int64 v65; // rdx
  bool pisMarkedForRemove; // [rsp+31h] [rbp-97h]
  char v67; // [rsp+32h] [rbp-96h]
  Scaleform::GFx::AS3::AvmDisplayObj *v68; // [rsp+38h] [rbp-90h]
  Scaleform::GFx::DisplayObjContainer *v69; // [rsp+40h] [rbp-88h]
  __int64 v70; // [rsp+48h] [rbp-80h]
  Scaleform::GFx::ASString v71; // [rsp+50h] [rbp-78h]
  Scaleform::GFx::ResourceId rid[2]; // [rsp+58h] [rbp-70h]
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+60h] [rbp-68h]
  Scaleform::GFx::ASString v74; // [rsp+70h] [rbp-58h]
  Scaleform::GFx::AS3::Value v75; // [rsp+78h] [rbp-50h]
  Scaleform::GFx::AS3::Value v76; // [rsp+98h] [rbp-30h]
  Scaleform::GFx::AS3::Value v77; // [rsp+B8h] [rbp-10h]
  Scaleform::GFx::AS3::Multiname v78; // [rsp+D8h] [rbp+10h]
  Scaleform::GFx::AS3::Multiname v79; // [rsp+108h] [rbp+40h]
  Scaleform::String symbol; // [rsp+138h] [rbp+70h]
  Scaleform::GFx::ASString v81; // [rsp+140h] [rbp+78h]
  Scaleform::GFx::ASStringNode *v82; // [rsp+148h] [rbp+80h]
  Scaleform::GFx::ASString v83; // [rsp+150h] [rbp+88h]
  Scaleform::GFx::ASString v84; // [rsp+158h] [rbp+90h]
  Scaleform::GFx::ASString v85; // [rsp+160h] [rbp+98h]
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v86; // [rsp+168h] [rbp+A0h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v87; // [rsp+170h] [rbp+A8h]
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v88; // [rsp+178h] [rbp+B0h]
  __int64 v89; // [rsp+180h] [rbp+B8h]
  __int64 v90; // [rsp+188h] [rbp+C0h]
  Scaleform::GFx::CharPosInfo posa; // [rsp+198h] [rbp+D0h]
  Scaleform::GFx::AS3::Value::V2U v92; // [rsp+210h] [rbp+148h]
  Scaleform::Render::Rect<float> v93; // [rsp+218h] [rbp+150h]
  Scaleform::GFx::AS3::Value::V2U v94; // [rsp+230h] [rbp+168h]
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+238h] [rbp+170h]
  Scaleform::GFx::AS3::AvmSprite *v96; // [rsp+298h] [rbp+1D0h]
  Scaleform::GFx::ASString *namea; // [rsp+2A8h] [rbp+1E0h]
  int vars0; // [rsp+2C0h] [rbp+1F8h]
  void *retaddr; // [rsp+2C8h] [rbp+200h]
  Scaleform::GFx::AS3::AvmSprite *v100; // [rsp+2D0h] [rbp+208h]
  __int64 v101; // [rsp+2D8h] [rbp+210h]
  Scaleform::GFx::ASString *v102; // [rsp+2E0h] [rbp+218h]

  v102 = name;
  v100 = this;
  v89 = -2i64;
  v4 = pos;
  v5 = this;
  v69 = (Scaleform::GFx::DisplayObjContainer *)this[-1].vfptr;
  v6 = v69->pDefImpl.pObject;
  v7 = 0i64;
  LODWORD(v70) = 0;
  if ( this )
  {
    v86 = this->vfptr;
    v87 = this->pAS3CollectiblePtr.pObject;
    v88 = this->pAS3RawPtr;
    v8 = &v86;
  }
  else
  {
    rid[0] = pos->CharacterId;
    v8 = (Scaleform::GFx::AvmDisplayObjBaseVtbl **)Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
                                                     v6,
                                                     &result,
                                                     (Scaleform::GFx::ResourceId)rid);
  }
  v9 = (unsigned __int64)*v8;
  v75.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)v9;
  *(_QWORD *)&v75.value.VNumber = v8[1];
  v10.VObj = (Scaleform::GFx::AS3::Object *)v8[2];
  v75.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)v8[2];
  if ( v9 )
    goto LABEL_23;
  if ( v4->Flags.Flags & 0x100 )
  {
    presBindData.pResource.pObject = 0i64;
    presBindData.pBinding = 0i64;
    Scaleform::String::String(&symbol, v4->ClassName);
    v11 = Scaleform::GFx::MovieImpl::FindExportedResource(
            *((Scaleform::GFx::MovieImpl **)v5[-1].vfptr->ToAvmTextFieldBase + 2),
            v6,
            &presBindData,
            &symbol);
    v9 = symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((symbol.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    if ( v11 )
    {
      v12 = ((__int64 (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)();
      if ( _bittest(&v12, 0xFu) )
        v75.Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)presBindData.pResource.pObject;
      else
        v75.value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)presBindData.pResource.pObject;
      *(_QWORD *)&v75.value.VNumber = presBindData.pBinding->pOwnerDefRes;
    }
    if ( presBindData.pResource.pObject )
      Scaleform::GFx::Resource::Release(presBindData.pResource.pObject);
    if ( v75.Bonus.pWeakProxy )
      goto LABEL_23;
    v10.VObj = (Scaleform::GFx::AS3::Object *)v75.value.VS._2;
  }
  if ( !v10.VObj
    || (((__int64 (__fastcall *)(Scaleform::GFx::AS3::Value::V2U, unsigned __int64, Scaleform::GFx::ASString *, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *))v10.VObj->vfptr->Finalize_GC)(
          v10,
          v9,
          name,
          __formal) & 0xFF00) != 256 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogError(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v5[-1].vfptr->ToAvmButttonBase,
      "Sprite::AddDisplayObject(): unknown cid = %d\n",
      LOWORD(v4->CharacterId.Id),
      __formal);
    return 0i64;
  }
  LODWORD(v70) = 8;
  if ( !*(_QWORD *)&v75.value.VNumber )
    *(_QWORD *)&v75.value.VNumber = v6;
LABEL_23:
  pisMarkedForRemove = 0;
  v14 = v69;
  v15 = Scaleform::GFx::DisplayList::GetDisplayObjectAtDepth(&v69->mDisplayList, v4->Depth, &pisMarkedForRemove);
  v16 = vars0;
  if ( vars0 == -1 )
  {
    v16 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v14->vfptr[107].__vecDelDtor)(v14);
    vars0 = v16;
  }
  if ( !(((unsigned int)retaddr >> 2) & 1) )
  {
    v37 = 1;
    goto LABEL_117;
  }
  if ( v15
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v15->vfptr[51].__vecDelDtor)(v15)
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v15->vfptr[52].__vecDelDtor)(v15) )
  {
    LOBYTE(v17) = 1;
    v15->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v15->vfptr, v17);
  }
  if ( !pisMarkedForRemove )
  {
    if ( !v15 )
    {
LABEL_116:
      v37 = (unsigned __int8)retaddr & 1;
      goto LABEL_117;
    }
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v15->vfptr[51].__vecDelDtor)(v15) )
      return 0i64;
  }
  if ( !v15 || v15->Depth < -1 || v15->Id.Id != v4->CharacterId.Id )
    goto LABEL_116;
  v18 = (Scaleform::GFx::ASStringNode *)*((_QWORD *)v5[-1].vfptr->ToAvmTextFieldBase + 45);
  v82 = v18;
  ++v18->RefCount;
  if ( SLOBYTE(v15->Flags) < 0 )
  {
    v19 = Scaleform::GFx::DisplayObject::GetOriginalName((Scaleform::GFx::DisplayObject *)v15, &v84)->pNode;
    ++v19->RefCount;
    v20 = v18->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    v18 = v19;
    v82 = v19;
    v21 = v84.pNode;
    v20 = v84.pNode->RefCount == 1;
    --v21->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    v14 = v69;
  }
  if ( SLOBYTE(v15->Flags) >= 0 )
    goto LABEL_48;
  if ( !namea->pNode->Size )
  {
    if ( v18->Size && !((LOBYTE(v15[1].vfptr) >> 1) & 1) )
      goto LABEL_112;
    goto LABEL_48;
  }
  if ( v18 == namea->pNode )
  {
LABEL_48:
    if ( v15->CreateFrame != v16 )
    {
      v37 = 1;
      goto LABEL_113;
    }
    Scaleform::GFx::CharPosInfo::CharPosInfo(&posa, v4);
    if ( SLOBYTE(v4->Flags.Flags) >= 0
      && ((unsigned int (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v15->vfptr[15].__vecDelDtor)(v15) )
    {
      posa.Flags.Flags |= 0x80u;
      posa.BlendMode = 0;
    }
    if ( !((LOBYTE(v4->Flags.Flags) >> 3) & 1) )
    {
      v22 = Scaleform::GFx::DisplayObjectBase::GetCxform(v15);
      if ( !Scaleform::Render::Cxform::IsIdentity(v22) )
      {
        posa.Flags.Flags |= 8u;
        Scaleform::Render::Cxform::SetIdentity(&posa.ColorTransform);
      }
    }
    Scaleform::GFx::DisplayObjContainer::MoveDisplayObject(v14, &posa);
    if ( v15->Flags & 0x100 )
    {
      v23 = (Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v15 + 4 * (unsigned __int8)v15->AvmObjOffset);
      v24 = Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(v23);
      v25 = v24;
      if ( !((LOBYTE(v15[1].vfptr) >> 1) & 1) )
      {
        if ( v24 )
        {
          Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)v15, &v81);
          v26 = 10;
          v75.Flags = 10;
          v70 = 0i64;
          v27 = v81.pNode;
          v71.pNode = v81.pNode;
          if ( v81.pNode == &v81.pNode->pManager->NullStringNode )
          {
            v27 = 0i64;
            v71.pNode = 0i64;
            v28.VObj = v92.VObj;
            *(Scaleform::GFx::AS3::Value::V2U *)&rid[0].Id = v92;
            v26 = 12;
            v75.Flags = 12;
          }
          else
          {
            ++v81.pNode->RefCount;
            v28.VObj = *(Scaleform::GFx::AS3::Object **)&rid[0].Id;
          }
          v29 = *(double *)&v23->pAS3RawPtr;
          if ( v29 == 0.0 )
            v29 = *(double *)&v23->pAS3CollectiblePtr.pObject;
          if ( LOBYTE(v29) & 1 )
            --*(_QWORD *)&v29;
          v77.Flags = 12;
          v77.Bonus.pWeakProxy = 0i64;
          v77.value.VNumber = v29;
          if ( v29 != 0.0 )
            *(_DWORD *)(*(_QWORD *)&v29 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v29 + 32i64) + 1) & 0x8FBFFFFF;
          v30 = *(Scaleform::GFx::AS3::GASRefCountBase **)(*((_QWORD *)v5[-1].vfptr->ToAvmTextFieldBase + 10) + 424i64);
          v79.Kind = 0;
          v79.Obj.pObject = v30;
          if ( v30 )
            v30->RefCount = (v30->RefCount + 1) & 0x8FBFFFFF;
          v79.Name.Flags = 0;
          v79.Name.Bonus.pWeakProxy = 0i64;
          v31 = v26 & 0x1F;
          if ( (unsigned int)(v31 - 12) <= 3
            && v27
            && (v32 = v27[1].pData, *((_DWORD *)v32 + 30) == 17)
            && ~((const unsigned __int8)v32[112] >> 5) & 1 )
          {
            Scaleform::GFx::AS3::Value::Assign(&v79.Name, (Scaleform::GFx::ASString *)&v27[1].16);
            Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
              (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v79.Obj,
              *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v27[1].RefCount);
            v79.Kind &= 0xFFFFFFF9;
          }
          else
          {
            __asm { prefetcht1 byte ptr [rsp+2C0h+var_248.Flags]; Prefetch to all cache levels }
            *(_QWORD *)&v79.Name.Flags = *(_QWORD *)&v75.Flags;
            v79.Name.Bonus.pWeakProxy = 0i64;
            *(_QWORD *)&v79.Name.value.VNumber = v27;
            v79.Name.value.VS._2 = v28;
            if ( v31 > 9 )
            {
              if ( (v26 >> 9) & 1 )
              {
                LODWORD(MEMORY[0]) = MEMORY[0] + 1;
              }
              else if ( v31 == 10 )
              {
                ++v27->RefCount;
              }
              else if ( v31 > 10 )
              {
                if ( v31 <= 15 )
                {
                  if ( v27 )
                    v27->Size = (v27->Size + 1) & 0x8FBFFFFF;
                }
                else if ( v31 <= 17 && v28.VObj )
                {
                  v28.VObj->RefCount = (v28.VObj->RefCount + 1) & 0x8FBFFFFF;
                }
              }
            }
            if ( (v79.Name.Flags & 0x1F) == 10 )
            {
              Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v79.Name, &v74);
              if ( v74.pNode->Size )
              {
                if ( *v74.pNode->pData == 64 )
                {
                  v79.Kind |= 8u;
                  v33 = Scaleform::GFx::ASString::Substring(&v74, &v85, 1, v74.pNode->Size);
                  Scaleform::GFx::AS3::Value::Assign(&v79.Name, v33);
                  v34 = v85.pNode;
                  v20 = v85.pNode->RefCount == 1;
                  --v34->RefCount;
                  if ( v20 )
                    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
                }
              }
              v35 = v74.pNode;
              v20 = v74.pNode->RefCount == 1;
              --v35->RefCount;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v35);
            }
          }
          ((void (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, Scaleform::GFx::AS3::AvmSprite **, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v25->vfptr[1].ForEachChild_GC)(
            v25,
            &v100,
            &v79,
            &v77);
          Scaleform::GFx::AS3::Multiname::~Multiname(&v79);
          if ( (v77.Flags & 0x1F) > 9 )
          {
            if ( (v77.Flags >> 9) & 1 )
            {
              v20 = v77.Bonus.pWeakProxy->RefCount-- == 1;
              if ( v20 )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
              v77.Bonus.pWeakProxy = 0i64;
              v77.value = 0ui64;
              v77.Flags &= 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v77);
            }
          }
          if ( v31 > 9 )
          {
            if ( (v26 >> 9) & 1 )
            {
              LODWORD(MEMORY[0]) = MEMORY[0] - 1;
              if ( !(_DWORD)MEMORY[0] )
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
              v70 = 0i64;
              v71.pNode = 0i64;
              *(_QWORD *)&rid[0].Id = 0i64;
              v75.Flags = v26 & 0xFFFFFDE0;
            }
            else
            {
              Scaleform::GFx::AS3::Value::ReleaseInternal(&v75);
            }
          }
          v36 = v81.pNode;
          v20 = v81.pNode->RefCount == 1;
          --v36->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        }
      }
    }
    if ( posa.pFilters.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)posa.pFilters.pObject);
    v20 = v18->RefCount-- == 1;
    if ( v20 )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
      return 0i64;
    }
    return 0i64;
  }
LABEL_112:
  v37 = (unsigned __int8)retaddr & 1;
LABEL_113:
  v20 = v18->RefCount-- == 1;
  if ( v20 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
LABEL_117:
  _((AMD_HD3D *)v14);
  v38 = v5[-1].vfptr;
  v39 = *((_QWORD *)v38->ToAvmTextFieldBase + 3);
  LODWORD(v68) = v4->CharacterId.Id;
  v40 = (*(__int64 (__fastcall **)(__int64, _QWORD, Scaleform::GFx::AS3::Value::Extra *, Scaleform::GFx::DisplayObjContainer *, Scaleform::GFx::AS3::AvmDisplayObj **, _DWORD))(*(_QWORD *)v39 + 32i64))(
          v39,
          *((_QWORD *)v38->ToAvmTextFieldBase + 2),
          &v75.Bonus,
          v14,
          &v68,
          v70);
  v41 = v40;
  v90 = v40;
  v42 = *(_WORD *)(v40 + 106);
  v43 = 0i64;
  if ( (v42 & 0x80u) != 0 )
    v43 = (Scaleform::GFx::Sprite *)v40;
  LOBYTE(v100) = 0;
  *(_WORD *)(v40 + 106) = v42 & 0xFFFE;
  for ( i = *(Scaleform::GFx::DisplayObjectBase **)(v40 + 56); i; i = i->pParentChar )
  {
    v45 = Scaleform::GFx::DisplayObjectBase::GetScale9Grid(i, &v93);
    if ( v45->x2 > v45->x1 && v45->y2 > v45->y1 )
    {
      *(_WORD *)(v41 + 106) |= 1u;
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v41 + 160i64))(v41);
      break;
    }
  }
  if ( v43 )
  {
    if ( namea->pNode->Size )
    {
      Scaleform::GFx::DisplayObject::SetOriginalName((Scaleform::GFx::DisplayObject *)&v43->vfptr, namea);
      LOBYTE(v100) = 1;
    }
    if ( v101 )
      ((void (__fastcall *)(Scaleform::GFx::Sprite *))v43->vfptr[94].__vecDelDtor)(v43);
  }
  if ( (unsigned __int8)retaddr & 4 )
    *(_WORD *)(v41 + 136) |= 1u;
  else
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v41 + 424i64))(v41, 0i64);
  *(_DWORD *)(v41 + 48) = vars0;
  v46 = (unsigned int)retaddr & 0xFFFFFFFE;
  if ( v37 )
    v46 |= 1u;
  if ( v4->Flags.Flags & 0x100 )
    Scaleform::GFx::AS3::AvmDisplayObj::InitClassName(
      (Scaleform::GFx::AS3::AvmDisplayObj *)(v41 + 4i64 * *(unsigned __int8 *)(v41 + 109)),
      v4->ClassName);
  v47 = v46;
  v48 = (Scaleform::GFx::Sprite *)v69;
  Scaleform::GFx::DisplayList::AddDisplayObject(
    &v69->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)v5[-1].vfptr,
    v4,
    (Scaleform::GFx::DisplayObjectBase *)v41,
    v47);
  v49 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v41 + 4i64 * *(unsigned __int8 *)(v41 + 109));
  v68 = (Scaleform::GFx::AS3::AvmDisplayObj *)(v41 + 4i64 * *(unsigned __int8 *)(v41 + 109));
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    v49->AppDomain = (Scaleform::GFx::AS3::VMAppDomain *)v5[-1].vfptr;
  if ( Scaleform::GFx::AS3::AvmDisplayObj::CreateASInstanceNoCtor(v49) )
  {
    v50 = v68;
    if ( !((*(_BYTE *)(v41 + 136) >> 1) & 1) && Scaleform::GFx::AS3::AvmDisplayObj::GetAS3Parent(v68) )
    {
      v51 = 10;
      LODWORD(presBindData.pResource.pObject) = 10;
      presBindData.pBinding = 0i64;
      v52 = namea->pNode;
      v74.pNode = v52;
      if ( v52 == &v52->pManager->NullStringNode )
      {
        v52 = 0i64;
        v74.pNode = 0i64;
        v53.VObj = v94.VObj;
        *(Scaleform::GFx::AS3::Value::V2U *)&v75.Flags = v94;
        v51 = 12;
        LODWORD(presBindData.pResource.pObject) = 12;
      }
      else
      {
        ++v52->RefCount;
        v53.VObj = *(Scaleform::GFx::AS3::Object **)&v75.Flags;
      }
      v54 = *(Scaleform::GFx::AS3::VMAppDomain **)&v5[-1].Flags;
      if ( !v54 )
        v54 = v5[-1].AppDomain;
      if ( (unsigned __int8)v54 & 1 )
        v54 = (Scaleform::GFx::AS3::VMAppDomain *)((char *)v54 - 1);
      v55 = *(double *)&v68->pAS3RawPtr;
      if ( v55 == 0.0 )
        v55 = *(double *)&v68->pAS3CollectiblePtr.pObject;
      if ( LOBYTE(v55) & 1 )
        --*(_QWORD *)&v55;
      v76.Flags = 12;
      v76.Bonus.pWeakProxy = 0i64;
      v76.value.VNumber = v55;
      if ( v55 != 0.0 )
        *(_DWORD *)(*(_QWORD *)&v55 + 32i64) = (*(_DWORD *)(*(_QWORD *)&v55 + 32i64) + 1) & 0x8FBFFFFF;
      v56 = *(Scaleform::GFx::AS3::GASRefCountBase **)(*((_QWORD *)v5[-1].vfptr->ToAvmTextFieldBase + 10) + 424i64);
      v78.Kind = 0;
      v78.Obj.pObject = v56;
      if ( v56 )
        v56->RefCount = (v56->RefCount + 1) & 0x8FBFFFFF;
      v78.Name.Flags = 0;
      v78.Name.Bonus.pWeakProxy = 0i64;
      v57 = v51 & 0x1F;
      if ( (unsigned int)(v57 - 12) <= 3
        && v52
        && (v58 = v52[1].pData, *((_DWORD *)v58 + 30) == 17)
        && ~((const unsigned __int8)v58[112] >> 5) & 1 )
      {
        Scaleform::GFx::AS3::Value::Assign(&v78.Name, (Scaleform::GFx::ASString *)&v52[1].16);
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v78.Obj,
          *(Scaleform::GFx::AS3::Instances::fl::XMLList **)&v52[1].RefCount);
        v78.Kind &= 0xFFFFFFF9;
      }
      else
      {
        __asm { prefetcht1 byte ptr [rbp+1F8h+presBindData.pResource.pObject]; Prefetch to all cache levels }
        *(_QWORD *)&v78.Name.Flags = presBindData.pResource.pObject;
        v78.Name.Bonus.pWeakProxy = 0i64;
        *(_QWORD *)&v78.Name.value.VNumber = v52;
        v78.Name.value.VS._2 = v53;
        if ( v57 > 9 )
        {
          if ( (v51 >> 9) & 1 )
          {
            LODWORD(MEMORY[0]) = MEMORY[0] + 1;
          }
          else if ( v57 == 10 )
          {
            ++v52->RefCount;
          }
          else if ( v57 > 10 )
          {
            if ( v57 <= 15 )
            {
              if ( v52 )
                v52->Size = (v52->Size + 1) & 0x8FBFFFFF;
            }
            else if ( v57 <= 17 && v53.VObj )
            {
              v53.VObj->RefCount = (v53.VObj->RefCount + 1) & 0x8FBFFFFF;
            }
          }
        }
        if ( (v78.Name.Flags & 0x1F) == 10 )
        {
          Scaleform::GFx::AS3::Value::operator Scaleform::GFx::ASString(&v78.Name, &v71);
          if ( v71.pNode->Size )
          {
            if ( *v71.pNode->pData == 64 )
            {
              v78.Kind |= 8u;
              v59 = Scaleform::GFx::ASString::Substring(&v71, &v83, 1, v71.pNode->Size);
              Scaleform::GFx::AS3::Value::Assign(&v78.Name, v59);
              v60 = v83.pNode;
              v20 = v83.pNode->RefCount == 1;
              --v60->RefCount;
              if ( v20 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v60);
            }
          }
          v61 = v71.pNode;
          v20 = v71.pNode->RefCount == 1;
          --v61->RefCount;
          if ( v20 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v61);
        }
      }
      ((void (__fastcall *)(Scaleform::GFx::AS3::VMAppDomain *, char *, Scaleform::GFx::AS3::Multiname *, Scaleform::GFx::AS3::Value *))v54->vfptr[1].ForEachChild_GC)(
        v54,
        &v67,
        &v78,
        &v76);
      Scaleform::GFx::AS3::Multiname::~Multiname(&v78);
      if ( (v76.Flags & 0x1F) > 9 )
      {
        if ( (v76.Flags >> 9) & 1 )
        {
          v20 = v76.Bonus.pWeakProxy->RefCount-- == 1;
          if ( v20 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v76.Bonus.pWeakProxy = 0i64;
          v76.value = 0ui64;
          v76.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v76);
        }
      }
      if ( v57 > 9 )
      {
        if ( (v51 >> 9) & 1 )
        {
          LODWORD(MEMORY[0]) = MEMORY[0] - 1;
          if ( !(_DWORD)MEMORY[0] )
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
          presBindData.pBinding = 0i64;
          v74.pNode = 0i64;
          *(_QWORD *)&v75.Flags = 0i64;
          LODWORD(presBindData.pResource.pObject) = v51 & 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal((Scaleform::GFx::AS3::Value *)&presBindData);
        }
      }
      v5 = v96;
      v62 = v96[-1].vfptr->ToAvmTextFieldBase;
      if ( *(_BYTE *)(*((_QWORD *)v62 + 10) + 168i64) )
      {
        Scaleform::GFx::AS3::VM::OutputAndIgnoreException(*((Scaleform::GFx::AS3::VM **)v62 + 10));
        LOWORD(v5[-1].vfptr[1].ToAvmDispContainerBase) |= 0x20u;
      }
      v50 = v68;
    }
    Scaleform::GFx::AS3::AvmDisplayObj::CallCtor(v50, 1);
    if ( (*(_WORD *)(v41 + 106) >> 10) & 1 )
      Scaleform::GFx::AS3::AvmSprite::CreateChildren((Scaleform::GFx::AS3::AvmSprite *)(v41
                                                                                      + 4i64
                                                                                      * *(unsigned __int8 *)(v41 + 109)));
    v48 = (Scaleform::GFx::Sprite *)v69;
  }
  v63 = (char)v100;
  if ( (_BYTE)v100 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::AvmTextFieldBase *(__fastcall *)(Scaleform::GFx::AvmDisplayObjBase *), Scaleform::GFx::Sprite *))(*(_QWORD *)v5[-1].vfptr->ToAvmTextFieldBase + 312i64))(
      v5[-1].vfptr->ToAvmTextFieldBase,
      v43);
    v63 = (char)v100;
  }
  if ( v43 )
  {
    if ( v63 && namea->pNode == (Scaleform::GFx::ASStringNode *)*((_QWORD *)v5[-1].vfptr->ToAvmTextFieldBase + 58) )
      Scaleform::GFx::Sprite::SetHitArea(v48, v43);
    v64 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v43->vfptr
                                                                      + 4 * (unsigned __int8)v43->AvmObjOffset))[1].__vecDelDtor)();
    if ( v64 )
      v7 = v64 - 56;
    LOBYTE(v65) = 1;
    (*(void (__fastcall **)(signed __int64, __int64))(*(_QWORD *)v7 + 152i64))(v7, v65);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v41);
  return (Scaleform::GFx::DisplayObjectBase *)v41;
}

// File Line: 412
// RVA: 0x80BA80
void __fastcall Scaleform::GFx::AS3::AvmSprite::QueueFrameScript(Scaleform::GFx::AS3::AvmSprite *this, __int64 frame)
{
  Scaleform::GFx::AS3::AvmSprite *v2; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v3; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v4; // rax
  Scaleform::GFx::DisplayObject *v5; // rdi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v6; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v7; // rbx
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // rcx
  unsigned int v10; // eax
  Scaleform::Render::RenderBuffer *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS3::Value other; // [rsp+28h] [rbp-30h]

  v2 = this;
  other.Flags = 0;
  other.Bonus.pWeakProxy = 0i64;
  v3 = this->pAS3RawPtr;
  v4 = v3;
  if ( !v3 )
    v4 = v2->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v4 & 1 )
    v4 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v4 - 1);
  if ( v4 )
  {
    if ( !v3 )
      v3 = v2->pAS3CollectiblePtr.pObject;
    if ( (unsigned __int8)v3 & 1 )
      v3 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v3 - 1);
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *, __int64, Scaleform::GFx::AS3::Value *))v3->vfptr[7].~RefCountBaseGC<328>)(
           v3,
           frame,
           &other) )
    {
      v5 = v2->pDispObj;
      v6 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction((Scaleform::GFx::AS3::MovieRoot *)v5->pASRoot, AL_Frame);
      v7 = v6;
      v6->Type = 2;
      if ( v5 )
        ++v5->RefCount;
      v8 = (Scaleform::RefCountNTSImpl *)&v6->pCharacter.pObject->vfptr;
      if ( v8 )
        Scaleform::RefCountNTSImpl::Release(v8);
      v7->pCharacter.pObject = v5;
      Scaleform::GFx::AS3::Value::Assign(&v7->Function, &other);
      v7->CFunction = 0i64;
      v9 = v7->pAS3Obj.pObject;
      if ( v9 )
      {
        if ( (unsigned __int8)v9 & 1 )
        {
          v7->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v9 - 1);
        }
        else
        {
          v10 = v9->RefCount;
          if ( v10 & 0x3FFFFF )
          {
            v9->RefCount = v10 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
          }
        }
        v7->pAS3Obj.pObject = 0i64;
      }
      v11 = (Scaleform::Render::RenderBuffer *)v7->pNLoadInitCL.pObject;
      if ( v11 )
        Scaleform::RefCountImpl::Release(v11);
      v7->pNLoadInitCL.pObject = 0i64;
    }
  }
  if ( (other.Flags & 0x1F) > 9 )
  {
    if ( (other.Flags >> 9) & 1 )
    {
      v12 = other.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v12 )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      other.Bonus.pWeakProxy = 0i64;
      other.value = 0ui64;
      other.Flags &= 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&other);
    }
  }
}

// File Line: 438
// RVA: 0x7CEDD0
void __fastcall Scaleform::GFx::AS3::AvmSprite::ExecuteFrameTags(Scaleform::GFx::AS3::AvmSprite *this, unsigned int frame)
{
  Scaleform::GFx::AS3::AvmSprite *v2; // rbx

  this->Flags |= 2u;
  v2 = this;
  if ( Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)this->pDispObj) )
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)v2->pDispObj);
  v2->pDispObj->Flags &= 0xFFDFu;
}

// File Line: 447
// RVA: 0x7B0080
void __fastcall Scaleform::GFx::AS3::AvmSprite::AdvanceFrame(Scaleform::GFx::AS3::AvmSprite *this, bool nextFrame, float framePos)
{
  Scaleform::GFx::AS3::AvmSprite *v3; // rbp
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v4; // rdi
  unsigned int v5; // esi
  unsigned int v6; // ebx

  v3 = this;
  v4 = this[-1].vfptr;
  if ( v4 )
    ++*((_DWORD *)&v4->__vecDelDtor + 2);
  if ( !((_QWORD)v4[1].OnUnloading & 0xC)
    && !(*((_WORD *)&v4[1].__vecDelDtor + 5) & 0x1000)
    && SHIDWORD(v4->ToAvmDispContainerBase) >= -1
    && nextFrame
    && !((_QWORD)this->pDispObj & 2) )
  {
    v5 = (*((__int64 (__fastcall **)(Scaleform::GFx::AvmDisplayObjBaseVtbl *))v4->__vecDelDtor + 107))(v4);
    if ( !(*((unsigned int (__fastcall **)(Scaleform::GFx::AvmDisplayObjBaseVtbl *))v4->__vecDelDtor + 115))(v4) )
    {
      v6 = v5;
      Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop((Scaleform::GFx::Sprite *)v4);
      v5 = (*((__int64 (__fastcall **)(Scaleform::GFx::AvmDisplayObjBaseVtbl *))v4->__vecDelDtor + 107))(v4);
      if ( v5 != v6 )
      {
        (*((void (__fastcall **)(const char **, _QWORD))v3[-1].pClassName + 27))(&v3[-1].pClassName, v5);
        Scaleform::GFx::Sprite::ExecuteFrameTags((Scaleform::GFx::Sprite *)v4, v5);
        LOBYTE(v3->pDispObj) |= 2u;
        if ( Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)v3[-1].vfptr) )
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)v3[-1].vfptr);
      }
    }
    if ( !v5 )
      Scaleform::GFx::DisplayList::UnloadMarkedObjects(
        (Scaleform::GFx::DisplayList *)&v3[-1].vfptr[2].ToAvmButttonBase,
        (Scaleform::GFx::DisplayObjectBase *)v3[-1].vfptr);
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v4);
}

// File Line: 515
// RVA: 0x803600
char __fastcall Scaleform::GFx::AS3::AvmSprite::OnEvent(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rdi
  Scaleform::GFx::AS3::AvmSprite *v3; // rbx
  Scaleform::GFx::Sprite *v4; // r9
  signed __int64 v5; // rdx
  Scaleform::GFx::TimelineDef *v6; // rax
  char v7; // cl
  unsigned int v8; // eax
  const char *v9; // rdx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v10; // rcx
  unsigned int v11; // eax
  __int64 v13; // rax
  Scaleform::GFx::EventId evtId; // [rsp+20h] [rbp-28h]

  v2 = id;
  v3 = this;
  if ( !(this->Flags & 1) )
    return Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent((Scaleform::GFx::AS3::AvmInteractiveObj *)&v3->vfptr, v2);
  v4 = (Scaleform::GFx::Sprite *)this->pDispObj;
  v5 = 0i64;
  if ( v4->Flags & 0x40 )
    v6 = v4->pDef.pObject;
  else
    v6 = 0i64;
  if ( !v6 )
    goto LABEL_16;
  v7 = v6[2].Id.Id;
  if ( !(v7 & 7) )
    goto LABEL_16;
  v8 = v2->Id;
  if ( v2->Id > 0x2000 )
  {
    if ( v8 != 0x4000 )
    {
      if ( v8 == 0x8000 )
      {
LABEL_39:
        if ( v7 & 2 )
        {
          v9 = "_down";
          goto LABEL_15;
        }
        goto LABEL_16;
      }
      if ( v8 != 0x10000 )
        goto LABEL_16;
      if ( !((v4->Flags >> 14) & 1) )
        goto LABEL_37;
    }
LABEL_13:
    if ( !(v7 & 1) )
      goto LABEL_16;
    v9 = "_up";
    goto LABEL_15;
  }
  if ( v8 == 0x2000 )
  {
    if ( !(v7 & 4) )
      goto LABEL_16;
    v13 = (unsigned int)v2->ControllerIndex;
    if ( (unsigned int)v13 < 6 )
      v5 = (signed __int64)&v4->pASRoot->pMovieImpl->mMouseState[v13];
    if ( (v4->Flags >> 14) & 1 && *(_BYTE *)(v5 + 52) & 1 )
    {
      v9 = "_down";
    }
    else
    {
      if ( *(_BYTE *)(v5 + 48) & 1 )
        goto LABEL_16;
      v9 = "_over";
    }
LABEL_15:
    Scaleform::GFx::Sprite::GotoLabeledFrame(v4, v9, 0);
    goto LABEL_16;
  }
  if ( v8 == 16 )
    goto LABEL_39;
  if ( v8 != 32 && v8 != 2048 )
  {
    if ( v8 != 4096 )
      goto LABEL_16;
    goto LABEL_13;
  }
LABEL_37:
  if ( v7 & 4 )
  {
    v9 = "_over";
    goto LABEL_15;
  }
LABEL_16:
  if ( v2->Id != 1024 )
    return Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent((Scaleform::GFx::AS3::AvmInteractiveObj *)&v3->vfptr, v2);
  v10 = v3->pAS3RawPtr;
  if ( v10 || v3->pAS3CollectiblePtr.pObject )
  {
    evtId.Id = v2->Id;
    v11 = v2->WcharCode;
    evtId.Id = 16777228;
    evtId.WcharCode = v11;
    evtId.KeyCode = v2->KeyCode;
    evtId.TouchID = v2->TouchID;
    *(_DWORD *)&evtId.RollOverCnt = *(_DWORD *)&v2->RollOverCnt;
    if ( !v10 )
      v10 = v3->pAS3CollectiblePtr.pObject;
    if ( (unsigned __int8)v10 & 1 )
      v10 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v10 - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v10->vfptr,
      &evtId,
      v3->pDispObj);
  }
  return 1;
}

// File Line: 588
// RVA: 0x7AA3A0
char __fastcall Scaleform::GFx::AS3::AvmSprite::ActsAsButton(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v1; // rax
  bool (__fastcall *v3)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // rcx

  if ( this->Flags & 1 )
    return 1;
  v1 = this[-1].vfptr;
  if ( !v1 )
  {
    if ( !*(_QWORD *)&this[-1].MouseOverCnt )
      return 0;
    if ( !*(_QWORD *)&this[-1].MouseOverCnt )
      return 1;
    v1 = *(Scaleform::GFx::AvmDisplayObjBaseVtbl **)&this[-1].MouseOverCnt;
  }
  if ( (unsigned __int8)v1 & 1 )
    v1 = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)((char *)v1 - 1);
  v3 = v1->OnEvent;
  if ( v3 && (*((_BYTE *)v3 + 18) || *((_BYTE *)v3 + 19)) )
    return 1;
  return 0;
}

// File Line: 597
// RVA: 0x7F85B0
char __fastcall Scaleform::GFx::AS3::AvmSprite::IsFocusEnabled(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::GFx::FocusMovedType fmt)
{
  __int32 v2; // edx

  v2 = fmt - 1;
  if ( !v2 )
    return this->Flags & 1 || ((unsigned __int8 (*)(void))this->vfptr[1].OnEventLoad)();
  if ( v2 == 2 )
    return 1;
  return ((__int64 (*)(void))this->vfptr[1].__vecDelDtor)();
}

// File Line: 608
// RVA: 0x7E74D0
__int64 __fastcall Scaleform::GFx::AS3::AvmSprite::GetCursorType(Scaleform::GFx::AS3::AvmSprite *this)
{
  return this->Flags & 1;
}

// File Line: 621
// RVA: 0x7CF150
void __fastcall Scaleform::GFx::AS3::AvmSprite::ExecuteInitActionFrameTags(Scaleform::GFx::AS3::AvmSprite *this, unsigned int frame)
{
  Scaleform::GFx::AS3::AvmSprite *v2; // rsi
  unsigned __int64 v3; // r14
  char v4; // r15
  Scaleform::GFx::DisplayObject *v5; // rdi
  unsigned int v6; // ebx
  __int64 v7; // [rsp+28h] [rbp-30h]
  unsigned int v8; // [rsp+30h] [rbp-28h]

  v2 = this;
  v3 = (unsigned __int64)frame >> 3;
  v4 = frame & 7;
  if ( !(this->InitActionsExecuted.pData[v3] & (unsigned __int8)(1 << (frame & 7))) )
  {
    v5 = this->pDispObj;
    if ( v5 )
      ++v5->RefCount;
    v6 = 0;
    v7 = 0i64;
    v8 = 0;
    if ( (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::DisplayObject::ScrollRectInfo *, __int64 *, _QWORD))(*(_QWORD *)&this->pDispObj[1].pScrollRect->Rectangle.x1 + 96i64))(
           this->pDispObj[1].pScrollRect,
           &v7,
           frame)
      && v8 )
    {
      do
      {
        (*(void (__fastcall **)(_QWORD, Scaleform::GFx::DisplayObject *))(**(_QWORD **)(v7 + 8i64 * v6) + 8i64))(
          *(_QWORD *)(v7 + 8i64 * v6),
          v2->pDispObj);
        ++v6;
      }
      while ( v6 < v8 );
      v2->InitActionsExecuted.pData[v3] |= 1 << v4;
    }
    if ( v5 )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
  }
}

// File Line: 658
// RVA: 0x7F93F0
char __fastcall Scaleform::GFx::AS3::AvmSprite::IsTabable(Scaleform::GFx::AS3::AvmSprite *this)
{
  Scaleform::GFx::AS3::AvmSprite *v1; // rbx
  Scaleform::GFx::AvmDisplayObjBaseVtbl *v3; // rax
  bool (__fastcall *v4)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *); // rax

  v1 = this;
  if ( !(*((unsigned __int8 (**)(void))this[-1].vfptr->__vecDelDtor + 59))() )
    return 0;
  v3 = v1[-1].vfptr;
  if ( (_QWORD)v3[1].OnUnloading & 0x60 )
  {
    if ( ((_QWORD)v3[1].OnUnloading & 0x60) != 96 )
      return 0;
    v4 = v3->HasEventHandler;
    if ( v4 )
    {
      while ( !((*((_DWORD *)v4 + 46) >> 15) & 1) )
      {
        v4 = (bool (__fastcall *)(Scaleform::GFx::AvmDisplayObjBase *, Scaleform::GFx::EventId *))*((_QWORD *)v4 + 7);
        if ( !v4 )
          return 1;
      }
      return 0;
    }
    return 1;
  }
  if ( SWORD2(v3[1].OnUnloading) > 0 )
    return 1;
  return v1->Flags & 1;
}

// File Line: 686
// RVA: 0x7ED6B0
bool __fastcall Scaleform::GFx::AS3::AvmSprite::GetObjectsUnderPoint(Scaleform::GFx::AS3::AvmSprite *this, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray, Scaleform::Render::Point<float> *pt)
{
  Scaleform::Render::Point<float> *v3; // rdi
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *v4; // rsi
  Scaleform::GFx::AS3::AvmSprite *v5; // rbx
  bool result; // al
  Scaleform::GFx::DisplayObject *v7; // rcx
  Scaleform::GFx::DrawingContext *v8; // rax
  bool v9; // di
  Scaleform::GFx::DisplayObjectBase *v10; // rbx
  Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase> val; // [rsp+58h] [rbp+20h]

  v3 = pt;
  v4 = destArray;
  v5 = this;
  result = Scaleform::GFx::AS3::AvmDisplayObjContainer::GetObjectsUnderPoint(
             (Scaleform::GFx::AS3::AvmDisplayObjContainer *)&this->vfptr,
             destArray,
             pt);
  if ( !result )
  {
    v7 = v5->pDispObj;
    if ( v7[2].vfptr )
    {
      v8 = (Scaleform::GFx::DrawingContext *)((__int64 (__cdecl *)(Scaleform::GFx::DisplayObject *))v7->vfptr[83].__vecDelDtor)(v7);
      v9 = Scaleform::GFx::DrawingContext::DefPointTestLocal(
             v8,
             v3,
             1,
             (Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr);
      if ( v9 )
      {
        v10 = (Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr;
        if ( v10 )
          ++v10->RefCount;
        val.pObject = v10;
        Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2>,Scaleform::ArrayDefaultPolicy>>::InsertAt(
          (Scaleform::ArrayBase<Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2>,Scaleform::ArrayDefaultPolicy> > *)&v4->Data,
          0i64,
          &val);
        if ( v10 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
      }
      result = v9;
    }
  }
  return result;
}

