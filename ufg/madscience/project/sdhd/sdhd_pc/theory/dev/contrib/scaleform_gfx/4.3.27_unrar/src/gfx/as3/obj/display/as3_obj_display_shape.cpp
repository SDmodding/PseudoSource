// File Line: 36
// RVA: 0x158C890
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_display::Shape_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::Graphics___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243C440 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_display::Shape,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics>>::Method = Scaleform::GFx::AS3::Instances::fl_display::Shape::graphicsGet;
  return result;
}

// File Line: 50
// RVA: 0x84DB10
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Shape::graphicsGet(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *p_pGraphics; // rbx
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *pObject; // r14
  __int64 v6; // rax
  __int64 v7; // rbp
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v9; // rcx
  unsigned int RefCount; // eax

  if ( !this->pDispObj.pObject )
    this->vfptr[6].Finalize_GC(this);
  p_pGraphics = &this->pGraphics;
  if ( !this->pGraphics.pObject
    && (unsigned __int8)Scaleform::GFx::AS3::ASVM::_constructInstance(
                          (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM,
                          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&this->pGraphics,
                          *(Scaleform::GFx::AS3::Object **)&this->pTraits.pObject->pVM[1].Initialized,
                          0,
                          0i64) )
  {
    pObject = p_pGraphics->pObject;
    v6 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->pDispObj.pObject->Scaleform::GFx::AS3::Instances::fl_display::DisplayObject::vfptr[83].__vecDelDtor)(this->pDispObj.pObject);
    v7 = v6;
    if ( v6 )
      ++*(_DWORD *)(v6 + 8);
    v8 = pObject->pDrawing.pObject;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    pObject->pDrawing.pObject = (Scaleform::GFx::DrawingContext *)v7;
    p_pGraphics->pObject->pDispObj = this->pDispObj.pObject;
  }
  if ( p_pGraphics != result )
  {
    if ( p_pGraphics->pObject )
      p_pGraphics->pObject->RefCount = (p_pGraphics->pObject->RefCount + 1) & 0x8FBFFFFF;
    v9 = result->pObject;
    if ( result->pObject )
    {
      if ( ((unsigned __int8)v9 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)((char *)v9 - 1);
        result->pObject = p_pGraphics->pObject;
        return;
      }
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
    result->pObject = p_pGraphics->pObject;
  }
}

// File Line: 86
// RVA: 0x7F2E50
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Shape::InitInstance(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this,
        bool extCall)
{
  if ( !extCall )
    Scaleform::GFx::AS3::Instances::fl_display::Shape::CreateStageObject(this);
}

// File Line: 97
// RVA: 0x7BEEE0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::Instances::fl_display::Shape::CreateStageObject(
        Scaleform::GFx::AS3::Instances::fl_display::Shape *this)
{
  Scaleform::GFx::AS3::Traits *pObject; // rax
  Scaleform::GFx::AS3::VMVtbl *vfptr; // rbx
  void *(__fastcall *vecDelDtor)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  __int64 v5; // rax
  Scaleform::GFx::DisplayObject *v6; // rcx
  __int64 v7; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::Traits *v10; // rsi
  __int64 v11; // rax
  Scaleform::GFx::AS3::VMAppDomain *v12; // rax
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+30h] [rbp-28h] BYREF
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h] BYREF

  if ( this->pDispObj.pObject )
    return this->pDispObj.pObject;
  pObject = this->pTraits.pObject;
  rid.Id = 65540;
  vfptr = pObject->pVM[1].vfptr;
  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
    *((Scaleform::GFx::MovieDefImpl **)vfptr[2].__vecDelDtor + 9),
    &result,
    (Scaleform::GFx::ResourceId)&rid);
  vecDelDtor = vfptr[3].__vecDelDtor;
  rid.Id = 65537;
  v5 = (*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), Scaleform::GFx::CharacterCreateInfo *, _QWORD, Scaleform::GFx::ResourceId *, int))(*(_QWORD *)vecDelDtor + 32i64))(
         vecDelDtor,
         vfptr[2].__vecDelDtor,
         &result,
         0i64,
         &rid,
         1);
  v6 = this->pDispObj.pObject;
  v7 = v5;
  if ( v6 )
    Scaleform::RefCountNTSImpl::Release(v6);
  this->pDispObj.pObject = (Scaleform::GFx::DisplayObject *)v7;
  if ( v7 )
    v7 += 4i64 * *(unsigned __int8 *)(v7 + 109);
  *(_QWORD *)(v7 + 16) = this;
  v8 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v7 + 8);
  if ( v8 )
  {
    if ( ((unsigned __int8)v8 & 1) != 0 )
    {
      *(_QWORD *)(v7 + 8) = (char *)v8 - 1;
    }
    else
    {
      RefCount = v8->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v8->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
      }
    }
    *(_QWORD *)(v7 + 8) = 0i64;
  }
  v10 = this->pTraits.pObject;
  v11 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v10->vfptr[2].~RefCountBaseGC<328>)(v10);
  if ( v11 )
    v12 = *(Scaleform::GFx::AS3::VMAppDomain **)(v11 + 48);
  else
    v12 = v10->pVM->SystemDomain.pObject;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    *(_QWORD *)(v7 + 40) = v12;
  return this->pDispObj.pObject;
}

// File Line: 139
// RVA: 0x7FFF70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Shape> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Shape> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 161
// RVA: 0x74C790
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::Shape::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, vm, &Scaleform::GFx::AS3::fl_display::ShapeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject::`vftable;
    v6->TraitsType = Traits_DisplayObject_Begin;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::Shape::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8.pV = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, vm, &Scaleform::GFx::AS3::fl_display::ShapeCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject::`vftable;
    v8.pV->TraitsType = Traits_DisplayObject_Begin;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape::`vftable;
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(result->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))MHeap->vfptr->Alloc)(
                                       MHeap,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, result->pV);
  return result;
}

