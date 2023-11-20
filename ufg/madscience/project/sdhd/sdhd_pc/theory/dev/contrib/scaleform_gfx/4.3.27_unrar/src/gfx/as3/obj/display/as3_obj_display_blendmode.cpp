// File Line: 49
// RVA: 0x77B4E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_display::BlendMode::BlendMode(Scaleform::GFx::AS3::Classes::fl_display::BlendMode *this, Scaleform::GFx::AS3::ClassTraits::Traits *t)
{
  Scaleform::GFx::AS3::Classes::fl_display::BlendMode *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Class::Class((Scaleform::GFx::AS3::Class *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_display::BlendMode::`vftable;
  v2->ADD = "add";
  v2->ALPHA = "alpha";
  v2->DARKEN = "darken";
  v2->DIFFERENCE = "difference";
  v2->ERASE = "erase";
  v2->HARDLIGHT = "hardlight";
  v2->INVERT = "invert";
  v2->LAYER = "layer";
  v2->LIGHTEN = "lighten";
  v2->MULTIPLY = "multiply";
  v2->NORMAL = "normal";
  v2->OVERLAY = "overlay";
  v2->SCREEN = "screen";
  v2->SUBTRACT = "subtract";
}

// File Line: 55
// RVA: 0x7E6210
signed __int64 __fastcall Scaleform::GFx::AS3::Classes::fl_display::BlendMode::GetBlendMode(Scaleform::GFx::ASString *value)
{
  unsigned int v1; // esi
  const char *v2; // rdi
  __int64 v3; // rcx
  char v4; // al
  __int64 v6; // rcx
  char v7; // al
  __int64 v8; // rcx
  char v9; // al
  __int64 v10; // rcx
  char v11; // al
  __int64 v12; // rcx
  char v13; // al
  __int64 v14; // rcx
  char v15; // al
  __int64 v16; // rcx
  char v17; // al
  __int64 v18; // rcx
  char v19; // al
  __int64 v20; // rcx
  char v21; // al
  __int64 v22; // rcx
  char v23; // al

  v1 = 0;
  v2 = value->pNode->pData;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = v2[v3++];
    if ( v4 != aNormal_0[v3 - 1] )
      break;
    if ( v3 == 7 )
      return 1i64;
  }
  v6 = 0i64;
  while ( 1 )
  {
    v7 = v2[v6++];
    if ( v7 != aAdd_4[v6 - 1] )
      break;
    if ( v6 == 4 )
      return 8i64;
  }
  v8 = 0i64;
  while ( 1 )
  {
    v9 = v2[v8++];
    if ( v9 != aAlpha_0[v8 - 1] )
      break;
    if ( v8 == 6 )
      return 11i64;
  }
  if ( !strcmp(v2, "multiply") )
    return 3i64;
  if ( !strcmp(v2, "subtract") )
    return 9i64;
  v10 = 0i64;
  while ( 1 )
  {
    v11 = v2[v10++];
    if ( v11 != aLayer[v10 - 1] )
      break;
    if ( v10 == 6 )
      return 2i64;
  }
  v12 = 0i64;
  while ( 1 )
  {
    v13 = v2[v12++];
    if ( v13 != aScreen_0[v12 - 1] )
      break;
    if ( v12 == 7 )
      return 4i64;
  }
  v14 = 0i64;
  while ( 1 )
  {
    v15 = v2[v14++];
    if ( v15 != aLighten[v14 - 1] )
      break;
    if ( v14 == 8 )
      return 5i64;
  }
  v16 = 0i64;
  while ( 1 )
  {
    v17 = v2[v16++];
    if ( v17 != aDarken[v16 - 1] )
      break;
    if ( v16 == 7 )
      return 6i64;
  }
  if ( !strcmp(v2, "difference") )
    return 7i64;
  v18 = 0i64;
  while ( 1 )
  {
    v19 = v2[v18++];
    if ( v19 != aInvert[v18 - 1] )
      break;
    if ( v18 == 7 )
      return 10i64;
  }
  v20 = 0i64;
  while ( 1 )
  {
    v21 = v2[v20++];
    if ( v21 != aErase[v20 - 1] )
      break;
    if ( v20 == 6 )
      return 12i64;
  }
  v22 = 0i64;
  while ( 1 )
  {
    v23 = v2[v22++];
    if ( v23 != aOverlay[v22 - 1] )
      break;
    if ( v22 == 8 )
      return 13i64;
  }
  if ( !strcmp(v2, "hardlight") )
    v1 = 14;
  return v1;
}

// File Line: 122
// RVA: 0x74CB00
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_display::BlendMode::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Classes::fl_display::BlendMode *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_display::BlendModeCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_display::BlendMode::`vftable;
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
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_display::BlendModeCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Classes::fl_display::BlendMode *)v4->vfptr->Alloc(v4, 184ui64, 0i64);
  if ( v9 )
    Scaleform::GFx::AS3::Classes::fl_display::BlendMode::BlendMode(v9, v3->pV);
  return v3;
}

