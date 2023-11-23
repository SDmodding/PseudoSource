// File Line: 45
// RVA: 0x1598020
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440228 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems>>::Method = (void (__fastcall *const)(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *))Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsGet;
  return result;
}

// File Line: 46
// RVA: 0x1599C40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_1_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440238 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,1,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems *>::Method = Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsSet;
  return result;
}

// File Line: 47
// RVA: 0x1597F90
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_2_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl::Array___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440248 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,2,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array>>::Method = Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsGet;
  return result;
}

// File Line: 48
// RVA: 0x1599C70
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_3_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl::Array_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440258 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,3,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl::Array *>::Method = Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsSet;
  return result;
}

// File Line: 49
// RVA: 0x1597FC0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_4_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_display::NativeMenu___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440268 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,4,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::NativeMenu>>::Method = Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::clone;
  return result;
}

// File Line: 50
// RVA: 0x1597FF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_5_Scaleform::GFx::AS3::Value_const__::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440278 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,5,Scaleform::GFx::AS3::Value const>::Method = Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::hideBuiltInItems;
  return result;
}

// File Line: 64
// RVA: 0x91E050
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsGet(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h] BYREF

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method instance::ContextMenu::builtInItemsGet() is not implemented\n");
  Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
    this->pTraits.pObject->pVM,
    &resulta,
    result,
    "flash.ui.ContextMenuBuiltInItems",
    0,
    0i64);
}

// File Line: 73
// RVA: 0x91E0C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsSet(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method instance::ContextMenu::builtInItemsSet() is not implemented\n");
}

// File Line: 80
// RVA: 0x91E680
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsGet(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *Array; // rax
  Scaleform::GFx::AS3::Instances::fl::Array *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // rbx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::FlashUI *UI; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+30h] [rbp+8h] BYREF

  Array = Scaleform::GFx::AS3::VM::MakeArray(this->pTraits.pObject->pVM, &resulta);
  pObject = result->pObject;
  pV = Array->pV;
  if ( Array->pV != result->pObject )
  {
    if ( pObject )
    {
      if ( ((unsigned __int8)pObject & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)pObject - 1);
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
    result->pObject = pV;
  }
  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method instance::ContextMenu::customItemsGet() is not implemented\n");
}

// File Line: 88
// RVA: 0x91E710
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsSet(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Instances::fl::Array *value)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method instance::ContextMenu::customItemsSet() is not implemented\n");
}

// File Line: 95
// RVA: 0x91E250
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::clone(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::NativeMenu> *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method instance::ContextMenu::clone() is not implemented\n");
}

// File Line: 102
// RVA: 0x920E60
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::hideBuiltInItems(
        Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *UI; // rcx

  UI = this->pTraits.pObject->pVM->UI;
  UI->vfptr->Output(UI, Output_Warning, "The method instance::ContextMenu::hideBuiltInItems() is not implemented\n");
}

// File Line: 155
// RVA: 0x8EAD00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::MakeObject(
        Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu *this,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu *t)
{
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu> *Instance; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu> resulta; // [rsp+48h] [rbp+20h] BYREF

  Instance = Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::MakeInstance(&resulta, t);
  Scaleform::GFx::AS3::Value::Pick(result, Instance->pV);
}

// File Line: 177
// RVA: 0x879560
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenu::MakeClassTraits(
        Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result,
        Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::MemoryHeap *MHeap; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  MHeap = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *)MHeap->vfptr->Alloc(MHeap, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(
      v5,
      vm,
      &Scaleform::GFx::AS3::fl_ui::ContextMenuCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenu::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  result->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)MHeap->vfptr->Alloc(MHeap, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
      v7,
      vm,
      &Scaleform::GFx::AS3::fl_ui::ContextMenuCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::`vftable;
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

