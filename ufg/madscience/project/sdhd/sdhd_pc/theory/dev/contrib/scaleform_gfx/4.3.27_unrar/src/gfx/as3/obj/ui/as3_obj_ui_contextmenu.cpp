// File Line: 45
// RVA: 0x1598020
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu_0_Scaleform::GFx::AS3::SPtr_Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems___::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_142440228 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu,0,Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems>>::Method = Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsGet;
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
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsGet(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *result)
{
  Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *v2; // rbx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems> *v3; // rdi
  Scaleform::GFx::AS3::FlashUI *v4; // rcx
  Scaleform::GFx::AS3::CheckResult resulta; // [rsp+40h] [rbp+8h]

  v2 = this;
  v3 = result;
  v4 = this->pTraits.pObject->pVM->UI;
  v4->vfptr->Output(v4, Output_Warning, "The method instance::ContextMenu::builtInItemsGet() is not implemented\n");
  Scaleform::GFx::AS3::VM::ConstructBuiltinObject<Scaleform::GFx::AS3::Instances::fl_geom::Rectangle>(
    v2->pTraits.pObject->pVM,
    &resulta,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_uint> *)v3,
    "flash.ui.ContextMenuBuiltInItems",
    0,
    0i64);
}

// File Line: 73
// RVA: 0x91E0C0
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::builtInItemsSet(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_ui::ContextMenuBuiltInItems *value)
{
  Scaleform::GFx::AS3::FlashUI *v3; // rcx

  v3 = this->pTraits.pObject->pVM->UI;
  v3->vfptr->Output(v3, Output_Warning, "The method instance::ContextMenu::builtInItemsSet() is not implemented\n");
}

// File Line: 80
// RVA: 0x91E680
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsGet(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result)
{
  Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *v2; // rsi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *v3; // rdi
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> *v4; // rax
  Scaleform::GFx::AS3::Instances::fl::Array *v5; // rcx
  Scaleform::GFx::AS3::Instances::fl::Array *v6; // rbx
  unsigned int v7; // eax
  Scaleform::GFx::AS3::FlashUI *v8; // rcx
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> resulta; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = result;
  v4 = Scaleform::GFx::AS3::VM::MakeArray(this->pTraits.pObject->pVM, &resulta);
  v5 = v3->pObject;
  v6 = v4->pV;
  if ( v4->pV != v3->pObject )
  {
    if ( v5 )
    {
      if ( (unsigned __int8)v5 & 1 )
      {
        v3->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v5 - 1);
      }
      else
      {
        v7 = v5->RefCount;
        if ( v7 & 0x3FFFFF )
        {
          v5->RefCount = v7 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v5->vfptr);
        }
      }
    }
    v3->pObject = v6;
  }
  v8 = v2->pTraits.pObject->pVM->UI;
  v8->vfptr->Output(v8, Output_Warning, "The method instance::ContextMenu::customItemsGet() is not implemented\n");
}

// File Line: 88
// RVA: 0x91E710
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::customItemsSet(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl::Array *value)
{
  Scaleform::GFx::AS3::FlashUI *v3; // rcx

  v3 = this->pTraits.pObject->pVM->UI;
  v3->vfptr->Output(v3, Output_Warning, "The method instance::ContextMenu::customItemsSet() is not implemented\n");
}

// File Line: 95
// RVA: 0x91E250
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::clone(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::NativeMenu> *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method instance::ContextMenu::clone() is not implemented\n");
}

// File Line: 102
// RVA: 0x920E60
void __fastcall Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu::hideBuiltInItems(Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::FlashUI *v2; // rcx

  v2 = this->pTraits.pObject->pVM->UI;
  v2->vfptr->Output(v2, Output_Warning, "The method instance::ContextMenu::hideBuiltInItems() is not implemented\n");
}

// File Line: 155
// RVA: 0x8EAD00
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_ui::ContextMenu> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 177
// RVA: 0x879560
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenu::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::fl_events::EventDispatcher::EventDispatcher(
      v5,
      v2,
      &Scaleform::GFx::AS3::fl_ui::ContextMenuCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_ui::ContextMenu::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = (Scaleform::GFx::AS3::ClassTraits::Traits *)&v6->vfptr;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::fl_events::EventDispatcher::EventDispatcher(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_ui::ContextMenuCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_ui::ContextMenu::`vftable;
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

