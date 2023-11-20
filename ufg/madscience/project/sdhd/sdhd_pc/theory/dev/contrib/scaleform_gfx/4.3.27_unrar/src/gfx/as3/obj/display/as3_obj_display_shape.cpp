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
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Shape::graphicsGet(Scaleform::GFx::AS3::Instances::fl_display::Shape *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *result)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *v2; // rsi
  Scaleform::GFx::AS3::Instances::fl_display::Shape *v3; // rdi
  signed __int64 v4; // rbx
  __int64 v5; // r14
  __int64 v6; // rax
  __int64 v7; // rbp
  Scaleform::RefCountNTSImpl *v8; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::Graphics *v9; // rcx
  unsigned int v10; // eax

  v2 = result;
  v3 = this;
  if ( !this->pDispObj.pObject )
    ((void (*)(void))this->vfptr[6].Finalize_GC)();
  v4 = (signed __int64)&v3->pGraphics;
  if ( !v3->pGraphics.pObject
    && (unsigned __int8)Scaleform::GFx::AS3::ASVM::_constructInstance(
                          (Scaleform::GFx::AS3::ASVM *)v3->pTraits.pObject->pVM,
                          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v3->pGraphics,
                          *(Scaleform::GFx::AS3::Object **)&v3->pTraits.pObject->pVM[1].Initialized,
                          0,
                          0i64) )
  {
    v5 = *(_QWORD *)v4;
    v6 = ((__int64 (*)(void))v3->pDispObj.pObject->vfptr[83].__vecDelDtor)();
    v7 = v6;
    if ( v6 )
      ++*(_DWORD *)(v6 + 8);
    v8 = *(Scaleform::RefCountNTSImpl **)(v5 + 56);
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    *(_QWORD *)(v5 + 56) = v7;
    *(_QWORD *)(*(_QWORD *)v4 + 64i64) = v3->pDispObj.pObject;
  }
  if ( (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::Graphics> *)v4 != v2 )
  {
    if ( *(_QWORD *)v4 )
      *(_DWORD *)(*(_QWORD *)v4 + 32i64) = (*(_DWORD *)(*(_QWORD *)v4 + 32i64) + 1) & 0x8FBFFFFF;
    v9 = v2->pObject;
    if ( v2->pObject )
    {
      if ( (unsigned __int8)v9 & 1 )
      {
        v2->pObject = (Scaleform::GFx::AS3::Instances::fl_display::Graphics *)((char *)v9 - 1);
        v2->pObject = *(Scaleform::GFx::AS3::Instances::fl_display::Graphics **)v4;
        return;
      }
      v10 = v9->RefCount;
      if ( v10 & 0x3FFFFF )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v9->vfptr);
      }
    }
    v2->pObject = *(Scaleform::GFx::AS3::Instances::fl_display::Graphics **)v4;
  }
}

// File Line: 86
// RVA: 0x7F2E50
void __fastcall Scaleform::GFx::AS3::Instances::fl_display::Shape::InitInstance(Scaleform::GFx::AS3::Instances::fl_display::Shape *this, bool extCall)
{
  JUMPOUT(extCall, 0, Scaleform::GFx::AS3::Instances::fl_display::Shape::CreateStageObject);
}

// File Line: 97
// RVA: 0x7BEEE0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::Instances::fl_display::Shape::CreateStageObject(Scaleform::GFx::AS3::Instances::fl_display::Shape *this)
{
  Scaleform::GFx::AS3::Instances::fl_display::Shape *v1; // rdi
  Scaleform::GFx::AS3::Traits *v2; // rax
  Scaleform::GFx::AS3::VMVtbl *v3; // rbx
  void *(__fastcall *v4)(Scaleform::GFx::AS3::VM *, unsigned int); // rcx
  signed int v5; // ST28_4
  __int64 v6; // rax
  Scaleform::RefCountNTSImpl *v7; // rcx
  __int64 v8; // rbx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v9; // rcx
  unsigned int v10; // eax
  Scaleform::GFx::AS3::Traits *v11; // rsi
  __int64 v12; // rax
  Scaleform::GFx::AS3::VMAppDomain *v13; // rax
  Scaleform::GFx::CharacterCreateInfo result; // [rsp+30h] [rbp-28h]
  Scaleform::GFx::ResourceId rid; // [rsp+60h] [rbp+8h]

  v1 = this;
  if ( this->pDispObj.pObject )
    return this->pDispObj.pObject;
  v2 = this->pTraits.pObject;
  rid.Id = 65540;
  v3 = v2->pVM[1].vfptr;
  Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
    *((Scaleform::GFx::MovieDefImpl **)v3[2].__vecDelDtor + 9),
    &result,
    (Scaleform::GFx::ResourceId)&rid);
  v4 = v3[3].__vecDelDtor;
  rid.Id = 65537;
  v5 = 1;
  v6 = (*(__int64 (__fastcall **)(void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), void *(__fastcall *)(Scaleform::GFx::AS3::VM *, unsigned int), Scaleform::GFx::CharacterCreateInfo *, _QWORD, Scaleform::GFx::ResourceId *, signed int))(*(_QWORD *)v4 + 32i64))(
         v4,
         v3[2].__vecDelDtor,
         &result,
         0i64,
         &rid,
         v5);
  v7 = (Scaleform::RefCountNTSImpl *)&v1->pDispObj.pObject->vfptr;
  v8 = v6;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v1->pDispObj.pObject = (Scaleform::GFx::DisplayObject *)v8;
  if ( v8 )
    v8 += 4i64 * *(unsigned __int8 *)(v8 + 109);
  *(_QWORD *)(v8 + 16) = v1;
  v9 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v8 + 8);
  if ( v9 )
  {
    if ( (unsigned __int8)v9 & 1 )
    {
      *(_QWORD *)(v8 + 8) = (char *)v9 - 1;
    }
    else
    {
      v10 = v9->RefCount;
      if ( v10 & 0x3FFFFF )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v9);
      }
    }
    *(_QWORD *)(v8 + 8) = 0i64;
  }
  v11 = v1->pTraits.pObject;
  v12 = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::Traits *))v11->vfptr[2].~RefCountBaseGC<328>)(v11);
  if ( v12 )
    v13 = *(Scaleform::GFx::AS3::VMAppDomain **)(v12 + 48);
  else
    v13 = v11->pVM->SystemDomain.pObject;
  if ( Scaleform::GFx::AS3::VMAppDomain::Enabled )
    *(_QWORD *)(v8 + 40) = v13;
  return v1->pDispObj.pObject;
}

// File Line: 139
// RVA: 0x7FFF70
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_display::Shape> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 161
// RVA: 0x74C790
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::Shape::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits> v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::ShapeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::`vftable';
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::DisplayObject::`vftable';
    v6->TraitsType = 22;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::Shape::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8.pV = (Scaleform::GFx::AS3::InstanceTraits::Traits *)&v7->vfptr;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::ShapeCI);
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::`vftable';
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::DisplayObject::`vftable';
    v8.pV->TraitsType = 22;
    v8.pV->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_display::Shape::`vftable';
  }
  else
  {
    v8.pV = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(v3->pV, v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

